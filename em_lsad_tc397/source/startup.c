///*
// * startup.c
// * 	Just for elf links
// *  Created on: 2022-11-11
// *  
// */
//
//#include "log_print.h"
//
//#define BSW_START_SEC_VAR
//#include "proj_MemMap.h"
//
//extern void _START (void);
//extern void _START1(void);
//extern void _START2(void);
//extern void _START3(void);
//extern void _START4(void);
//extern void _START5(void);
//
//const unsigned int __attribute__((used)) START_TBL[6]=
//{
//    (unsigned int)_START,
//    (unsigned int)_START1,
//    (unsigned int)_START2,
//    (unsigned int)_START3,
//    (unsigned int)_START4,
//    (unsigned int)_START5
//};
//
//extern void IfxCpu_Trap_vectorTable0(void);
//extern void IfxCpu_Trap_vectorTable1(void);
//extern void IfxCpu_Trap_vectorTable2(void);
//extern void IfxCpu_Trap_vectorTable3(void);
//extern void IfxCpu_Trap_vectorTable4(void);
//extern void IfxCpu_Trap_vectorTable5(void);
//
//const unsigned int __attribute__((used)) Trap_vectorTables[6]=
//{
//    (unsigned int)IfxCpu_Trap_vectorTable0,
//    (unsigned int)IfxCpu_Trap_vectorTable1,
//    (unsigned int)IfxCpu_Trap_vectorTable2,
//    (unsigned int)IfxCpu_Trap_vectorTable3,
//    (unsigned int)IfxCpu_Trap_vectorTable4,
//    (unsigned int)IfxCpu_Trap_vectorTable5,
//};
//
//#include "Ifx_Ssw.h"
//
//extern const Ifx_Ssw_Bmhd bmhd_0_orig;
//extern const Ifx_Ssw_Bmhd bmhd_0_copy;
//extern const Ifx_Ssw_Bmhd bmhd_1_orig;
//extern const Ifx_Ssw_Bmhd bmhd_1_copy;
//extern const Ifx_Ssw_Bmhd bmhd_2_orig;
//extern const Ifx_Ssw_Bmhd bmhd_2_copy;
//extern const Ifx_Ssw_Bmhd bmhd_3_orig;
//extern const Ifx_Ssw_Bmhd bmhd_3_copy;
//
//
//#define  BSW_STOP_SEC_VAR
//#include "proj_MemMap.h"
