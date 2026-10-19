# vehicle_interface — chassis signal acquisition (20 ms)

Reads the chassis side from RTE once per 20 ms, converts it into `g_sVehDataRx` (`tVehDataRx`), publishes it as `MsgManager_APPVehData`, and services SOC online calibration. Compiled into `lib_adas`.

## Files

- `vehicle_interface_maintask.c:33` — entry `vehicle_interface_Task_20ms()` (declared `adas/adas_interface.h:8`). First call runs `vehicle_interface_initialize()`; guarded by file-static `VEH_INTERFACE_POWERON_INITFLAG`. Returns `ADAS_ADAPTOR_SUCCESS`/`ADAS_ADAPTOR_ERR` (`../vehicle_service_global_variables.h:7-8`). Its caller is outside tracked sources (prebuilt libs).
- `src/vehicle_interface_task_func.c:18` — `vehicle_interface_initialize()`: memsets `g_sVehDataRx`, sets the impulse-speed LPF coefficients (den2 -0.7, num1/num2 0.15).
- `src/vehicle_interface_task_func.c:30` — `vehicle_interface_step(tVehDataRx*)`: per-cycle body; returns `Ctrl_DiagInputChassis()`'s error code.
- `src/vehicle_interface_task_func.c:92` — `VehInter_CalVehicleSpeedImpulse()`: 16-slot impulse average (static ring buffer).
- `src/vehicle_interface_task_func.c:135` — static `Ctrl_CalDistanceDiff()`: impulse delta × `Calib_f32ImpuseGap` [sic], wraps at `Calib_f32ImpulseMax`.

## Cycle order (`vehicle_interface_step`)

1. `Rte_Read_MsgManager_VehicleInfo` (:35) → `Ctrl_DiagInputChassis()` (:36) consumes the raw message first.
2. Copy fields: EPS steering-wheel angle; VCU brake flag + gear (`VEHI_GEAR_P/R/N/D` → `P/R/N/D_GEAR`, no default branch); ESC speed, impulses FL/FR/RL/RR, wheel speeds, wheel directions.
3. Standstill debounce (:71-74): static counter, resets unless `u8VehStantStill && speed<0.1`; `bVehStandStill` after >25 ticks (~0.5 s; comment: gear-change hold).
4. `eSysPwrMd = SYS_PWR_MD_RUN` hardcoded (:75).
5. Impulse speed → LPF → `f32VehSpdImp` (:78-80).
6. `Rte_Write_MsgManager_APPVehData` (:85), then `CalibOnlineProcess()` (:87; internally gated to every 5th call).

## Gotchas

- Impulse-speed path is suspect — verify before trusting `f32VehSpdImp`:
  - RL call passes `u16WhlPulRL` as both new and recorded value → diff is always 0 (:113).
  - RR call passes `f32WhlSpdRRKph` (float km/h, truncated) into the `uint16` impulse parameter (:114).
  - LPF input `stVehSpdImpLPF.f32LPF_yk` is never assigned anywhere in this tree → :80 overwrites the computed value with 0.
- `5000` in `Ctrl_CalDistanceDiff` (:153) is an invalid-impulse sentinel.
- Module state is wrapped in `#define CtrlPara_START_SEC_VAR` + `#include "proj_MemMap.h"` blocks — keep this pattern for new statics/globals.
- `g_sVehDataRx` is republished via RTE and consumed by the ctrl/DR/apa_shell layers — field changes affect them.
