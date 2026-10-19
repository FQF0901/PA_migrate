# PA_migrate — Infineon AURIX TC397 ADAS ECU

Embedded ADAS (parking/APA) software for Infineon AURIX TC397 (TriCore `tc39xb`, TC39xXP_B-Step, package lfbga516). Two Eclipse CDT projects built with **AURIX Development Studio (ADS)** + TASKING compiler. No CLI build, no package manager, no tests, no CI in this repo.

## Build (ADS GUI — import both projects into one workspace)

- Project names must stay `em_lsad_tc397` and `lib_adas`; the app project references `${workspace_loc:/lib_adas/...}` across projects.
- Build order: **`lib_adas` (config `Library Release`)** → archives to `em_lsad_tc397/lib/lib_swc/lib_adas.a` → then **`em_lsad_tc397` (config `Debug`)** links it into `Debug/em_lsad_tc397.elf` (also emits `.s19`/`.map`). Always rebuild `lib_adas` and relink the app after changing lib sources.
- Prebuilt `.a` libs in `em_lsad_tc397/lib/` (bsw, rte, emos, emdc, vehmsg, uss, sync) are git-ignored and required to link; they are produced by separate repos outside this one and copied in. A fresh clone cannot link until they are present.
- Flash/debug via `em_lsad_tc397.launch` (UDAS over JTAG, TC39xB, loads `${build_config}\em_lsad_tc397.elf`).
- `Debug/`, `DebugLib/`, `Library Release/` are IDE-generated (git-ignored). Do not edit or trust them — they contain stale absolute paths from an older workspace (`D:\Workspace_AURIX\...`, Jenkins).

## What lives where

- `lib_swc/lib_adas/` — the only real source tree; this is what you edit. `adas/` = algorithms (APA/parking, cruising, PEB, DR, lateral/longitudinal controller; MATLAB-codegen style kernels), `lib_adas_adapter/` = integration layer (apa_shell_adapter, vehicle_service incl. calibration).
- `em_lsad_tc397/` — app project. Tracked code is only `source/` (boot stub `Ifx_Cfg_SswBmhd.c` with an empty, unreferenced `core0_main`, fully commented-out `startup.c`, `version.c/.h`) and `common/` (AUTOSAR-style types, `proj_config.h`). Boot/OS/task logic lives inside the prebuilt `.a` libraries — do not try to trace app flow from `source/`.
- `em_lsad_tc397/lib_inc/` — header snapshot (~1770 files, headers only) for compilation: AUTOSAR EB/Tresos + MCAL bsw headers, plus a partial copy of lib_adas public headers. The app compiles against `lib_inc`, not against `lib_swc/lib_adas` — sync the `lib_inc` copy when a public lib header changes.
- `LinkerFiles/Lcf_Tasking_Tricore_Tc.lsl` — linker script the Debug config builds with (`--lsl-file`); includes the per-core memory partitions `select_core<N>_{data,bss,init}_{int,ext}.lsl`. Marked "GENERATED FILE: DO NOT EDIT" (EB Tresos genld) but tracked here — change only for targeted memory-layout work.

## App integration contract (`lib_swc/lib_adas/doc/readme_proj.txt`, `adas/adas_interface.h`)

- Init: `Ctrl_TaskInit()`, `Dr_Init_20ms_Task()`
- 20 ms cycle: `Ctrl_Task_20ms()`, `Dr_Process_20ms_Task()`, `EM_ADAS_to_AdInterface()`, `VehsrvTask_20ms()`

## Config knobs

- `em_lsad_tc397/common/proj_config.h` — `EM_PROJECT_ID` (`EM_61000017_APA`), `EM_VEHI_TYPE` (`VEHI_TYPE_HAN`, selects DBC parser and `rte.h` branches), `EM_SW_PLATFORM` (`PLT_AUTOSAR_EB`), `EM_JENKINS_BUILD_NUM` (CI-managed, reported to SOC in `version.c`). An unhandled project ID hits `#error`.
- `lib_swc/lib_adas/lib_adas_adapter/vehicle_service/calib/calib.cfg` — per-vehicle calibration (MarvelR vs BYDHan values annotated in comments); update when switching `EM_VEHI_TYPE`.

## Migration-in-progress pitfalls (verify before "fixing")

- `proj_config.h` selects AUTOSAR EB, but the Debug build still defines `USING_OS_FREERTOS`; `EM_RTE_ENTER/EXIT_CRITICAL` map to `EM_SuspendOSInterrupts`/`EM_ResumeOSInterrupts`, marked "TO ADAPT TO AUTOSAR CP".
- `lib_swc/lib_adas/adas/CMakeLists.txt` + `tasking.cmake` are stale leftovers (tc27xd, `em_lsad_tc277` paths) and are not a build path for this repo.
- `lib_adas/.cproject` has duplicate stale `DebugLib` configurations (tc27xd, `/bsw/Lib` builder); the maintained one is `Library Release` (tc39xb).
- Some legacy Chinese comments are already mojibake (`version.c` etc.); don't try to repair encodings.

## Verification

No tests/CI here. Verification is an ADS build plus HIL/CANape log review; for log-based root cause the user-level `gp-sdf-dll-rootcause` skill covers the MF4→SDF→DLL replay workflow.
