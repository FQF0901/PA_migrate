# actuator_handshake — SCU/EPS/ESC handshake supervisor (20 ms)

Supervises the APA controller ↔ chassis handshake (SCU gearbox, EPS steering, ESC braking) and drives `ActuaSrvTx`. Runs once per 20 ms from the vehicle-service task; part of `lib_adas` (see root `AGENTS.md` for build order).

## Files

- `actuator_handshake_maintask.c:34` — entry `actuator_handshake_Task_20ms()` (declared in `adas/adas_interface.h:10`). First call runs `actuator_handshake_initialize()` (zeroes the module globals); guarded by file-static `VEH_HANDSHAKE_POWERON_INITFLAG`.
- `src/actuator_handshake_task_func.c:26` — `actuator_handshake_step()` pipeline, fixed order (matters): RTE reads → `handshake_common()` → `handshake_fail_reason()` → `handshake_state()` → `actuator_handshake_output()` → `Rte_Write_ActuaSrvTx`.
- `src/handshake_state/handshake_state.c:36` — core state machine (**success / abort / release conditions**). `_transition()` (:36) computes booleans, `_flow()` (:111) applies them.
- `src/handshake_fail_reason/handshake_fail_reason.c` — response-overtime counters → `eHandshakeFailReason`.
- `src/actuator_handshake_output/actuator_handshake_output.c` — builds `g_sActuaSrvTx` (RestTx/VCU/ESC/EPS).
- `src/handshake_common/handshake_common.c:17` — latches `eHandshakeType` from `eHandshakeReq`: only updates in UNCONTROLLED (→NONE) and SUCCESS (→LOW/HIGH); stays latched in all other states.

## State machine (`handshake_state.c`)

States `tHandshakeSts` (`adas/adas_struct.h:304`): UNCONTROLLED=0 → START → SUCCESS → CONTROLLED → RELEASING, plus FAIL/ABORT.

- Start (`:63`): system `LSAD_STS_HANDSHAKE` (or `LSAD_STS_ACTIVE` + `LSAD_CRUISE`) && `eHandshakeReq != HANDSHAKE_RQ_TYPE_NONE` && SCU==1 && EPS==1 && ESC==1.
- Success (`:70`): from START, SCU==2 && EPS==2 && (cruise + high-speed request: CDD/VLC available and no-fail; otherwise ESC==2).
- Success→CONTROLLED (`:79`): system `LSAD_STS_ACTIVE`. CONTROLLED→RELEASING (`:85`): system `LSAD_STS_COMPLETE`, or handshake-type mismatch while brake active.
- ABORT: from START/SUCCESS/CONTROLLED when `LSAD_STS_TERMINATED`. FAIL: from START/SUCCESS/CONTROLLED when `eHandshakeFailReason != NO_FAILCODE`.
- RELEASING → UNCONTROLLED on **either** branch (`:167-175`): fail code set, or >160 ticks && SCU/EPS/ESC all != 2 (comment: BYD Han release takes ~3 s).
- FAIL/ABORT → UNCONTROLLED after >160 ticks (~3.2 s) or `LSAD_STS_STANDBY`.
- Unused struct fields (never set/read): `bHandCtrl2Success`, `bHandAbort2Fail` in `tHandshakeTrans`.

## Fail reasons (`handshake_fail_reason.c`)

- Counter thresholds (20 ms ticks, `:61-89`): ESC >250 (≈5 s), VCU >120 (≈2.4 s), VCU gear-sync >150 (≈3 s), EPS >120 (≈2.4 s).
- Priority ESC > VCU > EPS (`:93`); reset to `NO_FAILCODE` in UNCONTROLLED.
- This module only produces those three `*_RESPONSE_OVERTIME` codes; the rest of `tHandshakeFailReason` (`adas_struct.h:270`) is set by other modules.
- `bGearResponse` (`:123`): requested gear P/R/N/D must equal actual gear (1/2/3/4 ↔ P/R/N/D).

## Outputs (`actuator_handshake_output.c`)

- `APA_MainStas` (`:65`): 0x2 during START/SUCCESS/CONTROLLED; 0x7 during RELEASING/ABORT/FAIL; in UNCONTROLLED 0x7 if system prepare/handshake/active else 0x1.
- Gear request (`:153`): `VCU_gear_map` P=1,R=2,N=3,D=4 (`:362`); forced to 1 during RELEASING/ABORT/FAIL when speed<1.
- ESC (`:200`): ABORT/FAIL → `MPC_32E_axvCvAim=-1` (brake); CONTROLLED copies Ctrl2Chassis speed/stop-distance/accel; `APA_StopDistance` clamped 2000.
- EPS (`:285`): BYD-Han-only 5-cycle enable delay in START (`EPSEnblCnt==5`); target steering angle rate-limited by `Calib_f32SteerAngleIncreRatioMax`, clamped to ±`Calib_f32SteerAngleMax` (calib.cfg B-5/B-6).

## Types and state locations

- `tHandshakeType`, `tHandshakeFailReason`, `tHandshakeSts`, `tHandshakeManager` — `adas/adas_struct.h:263-321`.
- `tHandshakeTrans`, `tHandshakeFailTrans`, `tHandshakeManagerTrans`, `tVehiclServiceCommon`, `tActuaSrvTx` — `../vehicle_service_type.h`.
- `tHandshakeTypeRq` (`HANDSHAKE_RQ_*`) — `em_lsad_tc397/lib_inc/.../emos_rte.h:648`; `tLSAD_SystemSts` / `tLSAD_FuncType` (`LSAD_STS_*`, `LSAD_CRUISE`) — same file `:324`/`:350`.
- Globals `g_sHandshakeManager`, `g_sHandshakeManagerTrans`, `g_sActuaSrvTx`, `g_sVehiclServiceCommon` — `../vehicle_service_global_variables.c`; read outside this module too (e.g. `apa_shell.c`).
- RTE declarations — `em_lsad_tc397/lib_inc/lib_rte/rte/rte.h` (read `CTRL2CHASSIS` :73, `HandShakeInfo` :128, write `ActuaSrvTx` :132).
- Includes use root `vehicle_service/...` paths → the compile include root is `lib_adas_adapter/`.

## Conventions

- MATLAB-codegen style: `memset` zero-init, static helpers, `RTW_HEADER_*` guards; keep the `_transition()` (compute booleans) + `_flow()/_state()` (apply) split when editing.
- All timers are 20 ms ticks (fmin-saturated); comments quoting seconds assume 20 ms cadence.
- Don't reorder the steps in `actuator_handshake_step()`: state reads the fail code computed by `handshake_fail_reason()` earlier in the same cycle.
- Changes land in `lib_adas.a`; rebuild `lib_adas` then relink `em_lsad_tc397`. Build dirs (`DebugLib/`, `Library Release/`) contain generated copies/objects — never edit them.
