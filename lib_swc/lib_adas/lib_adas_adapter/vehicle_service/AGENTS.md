# vehicle_service — vehicle data, handshake, calibration, ctrl I/O (20 ms)

Adapter layer inside `lib_adas` between the algorithms (`adas/`) and RTE/chassis. Contains the two 20 ms task entries, the single calibration blob, the ctrl module's RTE adapter + diagnostics, and DEM event aggregation. Include root for this whole tree is `lib_adas_adapter/` (files include as `vehicle_service/...`).

## Submodules

- `vehicle_interface/` — chassis signal acquisition → `g_sVehDataRx`; entry `vehicle_interface_Task_20ms()`. See `vehicle_interface/AGENTS.md`.
- `actuator_handshake/` — SCU/EPS/ESC handshake state machine → `ActuaSrvTx`; entry `actuator_handshake_Task_20ms()`. See `actuator_handshake/AGENTS.md`.
- `calib/` — calibration blob + SOC online calibration (below).
- `ctrl_adapter/` — RTE I/O adapter for the ctrl module (code belongs to `adas/ctrl_algo`, lives here). API in `ctrl_adapter.h`; called from `adas/ctrl_algo/src/ctrl_task_func.c:73-77`, `:141-143`, `:507`.
- `ctrl_diag/` — ctrl fault/status codes + debug log (below).
- `diag_info/` — DEM event aggregation → `tDiagInfo`.
- `para/`, `common/` — vestigial test scaffolding: `VehsrvAllGlobalParaInit()` has no callers, `g_stVehsrv*` globals unused. Don't build on it.

## Entries and tracked call sites

- `vehicle_interface_Task_20ms()` (`vehicle_interface/vehicle_interface_maintask.c:33`) and `actuator_handshake_Task_20ms()` (`actuator_handshake/actuator_handshake_maintask.c:34`) are declared in `adas/adas_interface.h:8,10`; their callers are in the prebuilt libs, not tracked sources. `VehsrvTask_20ms` (`doc/readme_proj.txt:19`) is not defined anywhere in tracked sources.
- `VehSrv_CalibInit()` ← `adas/ctrl_algo/src/ctrl_task_func.c:46`; `VehSrv_GetCalib()` is the accessor used across `adas/` and this tree.
- `Ctrl_VehDiag_20ms()` ← `adas/ctrl_algo/ctrl_maintask.c:99`; `Ctrl_DiagInputChassis()` ← `vehicle_interface/src/vehicle_interface_task_func.c:36`; `Ctrl_DiagInputUss()`/`Ctrl_DiagInputPpInfo()` ← `ctrl_adapter.c:77,180`.
- `SendDiagInfo2APP()` ← `apa_shell_adapter/apa_shell_adapter.c:52`; result read via `Get_sDiagInfo()` (`lsad_fsm_adapter.c`, `lsad_fsm_core.c`, `ctrl_diag.c`).
- `CalibOnlineProcess()` ← `vehicle_interface/src/vehicle_interface_task_func.c:87`.

## Shared state (top-level files)

- `vehicle_service_global_variables.c/h` — `g_sVehDataRx`, `g_sHandshakeManager`, `g_sHandshakeManagerTrans`, `g_sActuaSrvTx`, `g_sVehiclServiceCommon`, `g_sDiagInfo`; return macros `ADAS_ADAPTOR_SUCCESS/ERR`, `ADAS_HANDSHAKE_ERR`.
- `wrapper_api.c/h` — `Set_sDiagInfo`/`Get_sDiagInfo` (diag exchange with `apa_shell_adapter`).
- `vehicle_service_math.c/h` — `LpfCalculation()` 2nd-order IIR helper (`f32LPF_yk` in → `f32LPF_filter_yk` out).
- `vehicle_service_type.h` — handshake types (`tActuaSrvTx` etc.).

## calib/

- `g_stCalibData` (`tPFCalibData`, `vehsrv_calib_data.c:11`) is THE calibration blob; `calib.cfg` is textually `#include`d inside `VehSrv_CalibInitData()` (`vehsrv_calib_data.c:19`) — it is C statements, keep it compilable.
- CFM loading is compiled out in this build: `CALIB_DATA_FROM_CFM 0` (`../ctrl_project_config.h:4`).
- cfg caveats: `Calib_f32AccSlopeUpLimit` is never set in calib.cfg (stays 0); per-vehicle values annotated MarvelR vs BYDHan.
- `calib/online/` — SOC↔MCU calibration sync over RTE; `CalibOnlineProcess()` (`online_calib_algo.c:575`) runs every 5th call; hardcoded `PROJECT_VERSION "61000017"` (`online_calib_algo.c:16`).

## ctrl_diag / diag_info

- Error codes: `CTRL_ERRCODE_DEF(module, err) = (module<<12)|err` (`ctrl_diag/ctrl_errcode.h:7`); module ids in `ctrl_diag/ctrl_module_id.h`. `g_stCtrlDiagErrCode` is defined in `adas/ctrl_algo/src/ctrl_global_variables.c:57`, not here.
- `Ctrl_VehDiag_20ms()` (`ctrl_diag.c:75`) fills `g_stCtrlLogInfo.f32AdasDebugVal[0..168]` and writes `Rte_Write_MsgManager_CTRLERRCODE` (:62).
- `SendDiagInfo2APP()` (`diag_info/diag_info.c:6`) polls DEM events 0..243 and maps id ranges to `tDiagInfo` flags. Known bug: loop writes `local_DiagData[243]` against a `[243]` array (one past end); the memset (:13) sizes one element, not the array.
- Dead ends: `Ctrl_DiagOutputChassis` returns 0 (`ctrl_diag.c:432`); `Ctrl_ShakeHandWithChassis` (`ctrl_adapter.c:681`) has no callers; `Ctrl_WaveHandWithChassis` divides by `f32WheelToSteerRatio` with no zero guard (`ctrl_adapter.c:704`).

## Conventions / build

- Return styles differ per file (`E_OK`, `ADAS_ADAPTOR_SUCCESS/ERR`, `ADAS_HANDSHAKE_ERR`) — match the file you edit.
- Module state is wrapped in `CtrlPara_START_SEC_VAR` + `proj_MemMap.h` sections; follow this pattern for new statics/globals.
- MATLAB-codegen style (static helpers, memset init) — keep file-local patterns.
- Changes compile into `lib_adas.a`; rebuild `lib_adas` then relink `em_lsad_tc397` (root `AGENTS.md`). Never edit `DebugLib/`, `Library Release/`.
