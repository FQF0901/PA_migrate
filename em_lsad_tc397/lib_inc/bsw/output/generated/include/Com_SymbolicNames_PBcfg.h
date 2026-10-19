#ifndef COM_SYMBOLIC_NAMES_PB_CFG_H
#define COM_SYMBOLIC_NAMES_PB_CFG_H

/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \version 6.3.52
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[includes]==============================================*/

/*==================[macros]================================================*/

/* IPDU group ID defines */
#if (defined ComConf_ComIPduGroup_RXPDUS_GLOBAL) /* To prevent double declaration */
#error ComConf_ComIPduGroup_RXPDUS_GLOBAL already defined
#endif /* #if (defined ComConf_ComIPduGroup_RXPDUS_GLOBAL) */

#define ComConf_ComIPduGroup_RXPDUS_GLOBAL 0U


#if (defined ComConf_ComIPduGroup_TXPDUS_GLOBAL) /* To prevent double declaration */
#error ComConf_ComIPduGroup_TXPDUS_GLOBAL already defined
#endif /* #if (defined ComConf_ComIPduGroup_TXPDUS_GLOBAL) */

#define ComConf_ComIPduGroup_TXPDUS_GLOBAL 1U


#if (defined ComConf_ComIPduGroup_RGEthChannel) /* To prevent double declaration */
#error ComConf_ComIPduGroup_RGEthChannel already defined
#endif /* #if (defined ComConf_ComIPduGroup_RGEthChannel) */

#define ComConf_ComIPduGroup_RGEthChannel 2U


#if (defined ComConf_ComIPduGroup_TGEthChannel) /* To prevent double declaration */
#error ComConf_ComIPduGroup_TGEthChannel already defined
#endif /* #if (defined ComConf_ComIPduGroup_TGEthChannel) */

#define ComConf_ComIPduGroup_TGEthChannel 3U


#if (defined ComConf_ComIPduGroup_RGCanNetwork) /* To prevent double declaration */
#error ComConf_ComIPduGroup_RGCanNetwork already defined
#endif /* #if (defined ComConf_ComIPduGroup_RGCanNetwork) */

#define ComConf_ComIPduGroup_RGCanNetwork 4U


#if (defined ComConf_ComIPduGroup_TGCanNetwork) /* To prevent double declaration */
#error ComConf_ComIPduGroup_TGCanNetwork already defined
#endif /* #if (defined ComConf_ComIPduGroup_TGCanNetwork) */

#define ComConf_ComIPduGroup_TGCanNetwork 5U


/* External Rx IPdus defines */
#if (defined ComConf_ComIPdu_PDPdu_DummyOut_R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_DummyOut_R already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_DummyOut_R) */

#define ComConf_ComIPdu_PDPdu_DummyOut_R 0U


#if (defined ComConf_ComIPdu_PDPdu_CounterIn_R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_CounterIn_R already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_CounterIn_R) */

#define ComConf_ComIPdu_PDPdu_CounterIn_R 1U


#if (defined ComConf_ComIPdu_PDPdu_UssToolIn_R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_UssToolIn_R already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_UssToolIn_R) */

#define ComConf_ComIPdu_PDPdu_UssToolIn_R 2U


#if (defined ComConf_ComIPdu_PDPdu_CfmIn_R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_CfmIn_R already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_CfmIn_R) */

#define ComConf_ComIPdu_PDPdu_CfmIn_R 3U


#if (defined ComConf_ComIPdu_PDPdu_TestUdpOut_R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_TestUdpOut_R already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_TestUdpOut_R) */

#define ComConf_ComIPdu_PDPdu_TestUdpOut_R 4U


#if (defined ComConf_ComIPdu_PDGW_HSC2_SCU_FrP00_157R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDGW_HSC2_SCU_FrP00_157R already defined
#endif /* #if (defined ComConf_ComIPdu_PDGW_HSC2_SCU_FrP00_157R) */

#define ComConf_ComIPdu_PDGW_HSC2_SCU_FrP00_157R 5U


#if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP00_193R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSCS_HSC2_FrP00_193R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP00_193R) */

#define ComConf_ComIPdu_PDSCS_HSC2_FrP00_193R 6U


#if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP01_197R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSCS_HSC2_FrP01_197R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP01_197R) */

#define ComConf_ComIPdu_PDSCS_HSC2_FrP01_197R 7U


#if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP02_389R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSCS_HSC2_FrP02_389R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP02_389R) */

#define ComConf_ComIPdu_PDSCS_HSC2_FrP02_389R 8U


#if (defined ComConf_ComIPdu_PDEPS_HSC2_FrP02_433R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDEPS_HSC2_FrP02_433R already defined
#endif /* #if (defined ComConf_ComIPdu_PDEPS_HSC2_FrP02_433R) */

#define ComConf_ComIPdu_PDEPS_HSC2_FrP02_433R 9U


#if (defined ComConf_ComIPdu_PDEHBS_HSC2_FrP00_438R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDEHBS_HSC2_FrP00_438R already defined
#endif /* #if (defined ComConf_ComIPdu_PDEHBS_HSC2_FrP00_438R) */

#define ComConf_ComIPdu_PDEHBS_HSC2_FrP00_438R 10U


#if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP03_455R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSCS_HSC2_FrP03_455R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP03_455R) */

#define ComConf_ComIPdu_PDSCS_HSC2_FrP03_455R 11U


#if (defined ComConf_ComIPdu_PDSAS_HSC2_FrP00_485R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSAS_HSC2_FrP00_485R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSAS_HSC2_FrP00_485R) */

#define ComConf_ComIPdu_PDSAS_HSC2_FrP00_485R 12U


#if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP05_489R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSCS_HSC2_FrP05_489R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP05_489R) */

#define ComConf_ComIPdu_PDSCS_HSC2_FrP05_489R 13U


#if (defined ComConf_ComIPdu_PDEPB_HSC2_FrP01_554R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDEPB_HSC2_FrP01_554R already defined
#endif /* #if (defined ComConf_ComIPdu_PDEPB_HSC2_FrP01_554R) */

#define ComConf_ComIPdu_PDEPB_HSC2_FrP01_554R 14U


#if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP11_840R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSCS_HSC2_FrP11_840R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP11_840R) */

#define ComConf_ComIPdu_PDSCS_HSC2_FrP11_840R 15U


#if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP12_842R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSCS_HSC2_FrP12_842R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP12_842R) */

#define ComConf_ComIPdu_PDSCS_HSC2_FrP12_842R 16U


#if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP15_851R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDSCS_HSC2_FrP15_851R already defined
#endif /* #if (defined ComConf_ComIPdu_PDSCS_HSC2_FrP15_851R) */

#define ComConf_ComIPdu_PDSCS_HSC2_FrP15_851R 17U


#if (defined ComConf_ComIPdu_PDGW_HSC2_FrP10_1009R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDGW_HSC2_FrP10_1009R already defined
#endif /* #if (defined ComConf_ComIPdu_PDGW_HSC2_FrP10_1009R) */

#define ComConf_ComIPdu_PDGW_HSC2_FrP10_1009R 18U


#if (defined ComConf_ComIPdu_PDGW_HSC2_IPK_FrP06_1345R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDGW_HSC2_IPK_FrP06_1345R already defined
#endif /* #if (defined ComConf_ComIPdu_PDGW_HSC2_IPK_FrP06_1345R) */

#define ComConf_ComIPdu_PDGW_HSC2_IPK_FrP06_1345R 19U


#if (defined ComConf_ComIPdu_PDEM_BerthIdInfo_0x529_1321R) /* To prevent double declaration */
#error ComConf_ComIPdu_PDEM_BerthIdInfo_0x529_1321R already defined
#endif /* #if (defined ComConf_ComIPdu_PDEM_BerthIdInfo_0x529_1321R) */

#define ComConf_ComIPdu_PDEM_BerthIdInfo_0x529_1321R 20U


/* External Tx IPdu defines */
#if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP00_424T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_HSC2_FrP00_424T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP00_424T) */

#define ComConf_ComIPdu_PDP2P_HSC2_FrP00_424T 0U


#if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP01_437T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_HSC2_FrP01_437T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP01_437T) */

#define ComConf_ComIPdu_PDP2P_HSC2_FrP01_437T 1U


#if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP04_567T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_HSC2_FrP04_567T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP04_567T) */

#define ComConf_ComIPdu_PDP2P_HSC2_FrP04_567T 2U


#if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP03_573T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_HSC2_FrP03_573T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP03_573T) */

#define ComConf_ComIPdu_PDP2P_HSC2_FrP03_573T 3U


#if (defined ComConf_ComIPdu_PDAPA_SecCH_FrP03_651T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDAPA_SecCH_FrP03_651T already defined
#endif /* #if (defined ComConf_ComIPdu_PDAPA_SecCH_FrP03_651T) */

#define ComConf_ComIPdu_PDAPA_SecCH_FrP03_651T 4U


#if (defined ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP01_764T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP01_764T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP01_764T) */

#define ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP01_764T 5U


#if (defined ComConf_ComIPdu_PDP2P_HSC4_FrP03_781T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_HSC4_FrP03_781T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_HSC4_FrP03_781T) */

#define ComConf_ComIPdu_PDP2P_HSC4_FrP03_781T 6U


#if (defined ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP02_912T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP02_912T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP02_912T) */

#define ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP02_912T 7U


#if (defined ComConf_ComIPdu_PDP2P_HSC2_FrI02_914T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_HSC2_FrI02_914T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_HSC2_FrI02_914T) */

#define ComConf_ComIPdu_PDP2P_HSC2_FrI02_914T 8U


#if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP02_966T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDP2P_HSC2_FrP02_966T already defined
#endif /* #if (defined ComConf_ComIPdu_PDP2P_HSC2_FrP02_966T) */

#define ComConf_ComIPdu_PDP2P_HSC2_FrP02_966T 9U


#if (defined ComConf_ComIPdu_PDEM_APAPLDINF_0x531_1329T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDEM_APAPLDINF_0x531_1329T already defined
#endif /* #if (defined ComConf_ComIPdu_PDEM_APAPLDINF_0x531_1329T) */

#define ComConf_ComIPdu_PDEM_APAPLDINF_0x531_1329T 10U


#if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_0_INF_1330T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDLADS_HSC4_OBJ_0_INF_1330T already defined
#endif /* #if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_0_INF_1330T) */

#define ComConf_ComIPdu_PDLADS_HSC4_OBJ_0_INF_1330T 11U


#if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_1_INF_1337T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDLADS_HSC4_OBJ_1_INF_1337T already defined
#endif /* #if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_1_INF_1337T) */

#define ComConf_ComIPdu_PDLADS_HSC4_OBJ_1_INF_1337T 12U


#if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_2_INF_1339T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDLADS_HSC4_OBJ_2_INF_1339T already defined
#endif /* #if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_2_INF_1339T) */

#define ComConf_ComIPdu_PDLADS_HSC4_OBJ_2_INF_1339T 13U


#if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_3_INF_1340T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDLADS_HSC4_OBJ_3_INF_1340T already defined
#endif /* #if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_3_INF_1340T) */

#define ComConf_ComIPdu_PDLADS_HSC4_OBJ_3_INF_1340T 14U


#if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_4_INF_1341T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDLADS_HSC4_OBJ_4_INF_1341T already defined
#endif /* #if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_4_INF_1341T) */

#define ComConf_ComIPdu_PDLADS_HSC4_OBJ_4_INF_1341T 15U


#if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_5_INF_1342T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDLADS_HSC4_OBJ_5_INF_1342T already defined
#endif /* #if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_5_INF_1342T) */

#define ComConf_ComIPdu_PDLADS_HSC4_OBJ_5_INF_1342T 16U


#if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_6_INF_1343T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDLADS_HSC4_OBJ_6_INF_1343T already defined
#endif /* #if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_6_INF_1343T) */

#define ComConf_ComIPdu_PDLADS_HSC4_OBJ_6_INF_1343T 17U


#if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_7_INF_1346T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDLADS_HSC4_OBJ_7_INF_1346T already defined
#endif /* #if (defined ComConf_ComIPdu_PDLADS_HSC4_OBJ_7_INF_1346T) */

#define ComConf_ComIPdu_PDLADS_HSC4_OBJ_7_INF_1346T 18U


#if (defined ComConf_ComIPdu_PDEM_APAPLDINF_0x545_1349T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDEM_APAPLDINF_0x545_1349T already defined
#endif /* #if (defined ComConf_ComIPdu_PDEM_APAPLDINF_0x545_1349T) */

#define ComConf_ComIPdu_PDEM_APAPLDINF_0x545_1349T 19U


#if (defined ComConf_ComIPdu_PDPdu_CounterOut_T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_CounterOut_T already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_CounterOut_T) */

#define ComConf_ComIPdu_PDPdu_CounterOut_T 20U


#if (defined ComConf_ComIPdu_PDPdu_DummyIn_T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_DummyIn_T already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_DummyIn_T) */

#define ComConf_ComIPdu_PDPdu_DummyIn_T 21U


#if (defined ComConf_ComIPdu_PDPdu_UssToolOut_T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_UssToolOut_T already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_UssToolOut_T) */

#define ComConf_ComIPdu_PDPdu_UssToolOut_T 22U


#if (defined ComConf_ComIPdu_PDPdu_CfmOut_T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_CfmOut_T already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_CfmOut_T) */

#define ComConf_ComIPdu_PDPdu_CfmOut_T 23U


#if (defined ComConf_ComIPdu_PDPdu_TestUdpOut_T) /* To prevent double declaration */
#error ComConf_ComIPdu_PDPdu_TestUdpOut_T already defined
#endif /* #if (defined ComConf_ComIPdu_PDPdu_TestUdpOut_T) */

#define ComConf_ComIPdu_PDPdu_TestUdpOut_T 24U


/* External Rx Signal IDs (no group signals) defines */
#if (defined ComConf_ComSignal_SGDummyOut_R) /* To prevent double declaration */
#error ComConf_ComSignal_SGDummyOut_R already defined
#endif /* #if (defined ComConf_ComSignal_SGDummyOut_R) */

#define ComConf_ComSignal_SGDummyOut_R 0U


#if (defined ComConf_ComSignal_SGCounterIn_R) /* To prevent double declaration */
#error ComConf_ComSignal_SGCounterIn_R already defined
#endif /* #if (defined ComConf_ComSignal_SGCounterIn_R) */

#define ComConf_ComSignal_SGCounterIn_R 1U


#if (defined ComConf_ComSignal_SGUssToolIn_R) /* To prevent double declaration */
#error ComConf_ComSignal_SGUssToolIn_R already defined
#endif /* #if (defined ComConf_ComSignal_SGUssToolIn_R) */

#define ComConf_ComSignal_SGUssToolIn_R 2U


#if (defined ComConf_ComSignal_SGCfmIn_R) /* To prevent double declaration */
#error ComConf_ComSignal_SGCfmIn_R already defined
#endif /* #if (defined ComConf_ComSignal_SGCfmIn_R) */

#define ComConf_ComSignal_SGCfmIn_R 3U


#if (defined ComConf_ComSignal_SGTestUdpIn_R) /* To prevent double declaration */
#error ComConf_ComSignal_SGTestUdpIn_R already defined
#endif /* #if (defined ComConf_ComSignal_SGTestUdpIn_R) */

#define ComConf_ComSignal_SGTestUdpIn_R 4U


#if (defined ComConf_ComSignal_SGSCUDrvrIntrvnAHSC2_157R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCUDrvrIntrvnAHSC2_157R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCUDrvrIntrvnAHSC2_157R) */

#define ComConf_ComSignal_SGSCUDrvrIntrvnAHSC2_157R 5U


#if (defined ComConf_ComSignal_SGSCUNRCDAvlblHSC2_157R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCUNRCDAvlblHSC2_157R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCUNRCDAvlblHSC2_157R) */

#define ComConf_ComSignal_SGSCUNRCDAvlblHSC2_157R 6U


#if (defined ComConf_ComSignal_SGSCUShifterLvrPosHSC2_157R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCUShifterLvrPosHSC2_157R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCUShifterLvrPosHSC2_157R) */

#define ComConf_ComSignal_SGSCUShifterLvrPosHSC2_157R 7U


#if (defined ComConf_ComSignal_SGSCUShifterPosInvsnHSC2_157R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCUShifterPosInvsnHSC2_157R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCUShifterPosInvsnHSC2_157R) */

#define ComConf_ComSignal_SGSCUShifterPosInvsnHSC2_157R 8U


#if (defined ComConf_ComSignal_SGSCUShifterPosRCHSC2_157R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCUShifterPosRCHSC2_157R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCUShifterPosRCHSC2_157R) */

#define ComConf_ComSignal_SGSCUShifterPosRCHSC2_157R 9U


#if (defined ComConf_ComSignal_SGLDrvnWhlRotlDistPlsCtrHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLDrvnWhlRotlDistPlsCtrHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGLDrvnWhlRotlDistPlsCtrHSC2_193R) */

#define ComConf_ComSignal_SGLDrvnWhlRotlDistPlsCtrHSC2_193R 10U


#if (defined ComConf_ComSignal_SGLDrvnWhlRotlDistTRCHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLDrvnWhlRotlDistTRCHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGLDrvnWhlRotlDistTRCHSC2_193R) */

#define ComConf_ComSignal_SGLDrvnWhlRotlDistTRCHSC2_193R 11U


#if (defined ComConf_ComSignal_SGLDrvnWhlRotlDistTmspHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLDrvnWhlRotlDistTmspHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGLDrvnWhlRotlDistTmspHSC2_193R) */

#define ComConf_ComSignal_SGLDrvnWhlRotlDistTmspHSC2_193R 12U


#if (defined ComConf_ComSignal_SGLDrvnWhlRotlDistVHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLDrvnWhlRotlDistVHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGLDrvnWhlRotlDistVHSC2_193R) */

#define ComConf_ComSignal_SGLDrvnWhlRotlDistVHSC2_193R 13U


#if (defined ComConf_ComSignal_SGLDrvnWhlRotlRstOcdHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLDrvnWhlRotlRstOcdHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGLDrvnWhlRotlRstOcdHSC2_193R) */

#define ComConf_ComSignal_SGLDrvnWhlRotlRstOcdHSC2_193R 14U


#if (defined ComConf_ComSignal_SGLDrvnWhlRotlSeqNumHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLDrvnWhlRotlSeqNumHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGLDrvnWhlRotlSeqNumHSC2_193R) */

#define ComConf_ComSignal_SGLDrvnWhlRotlSeqNumHSC2_193R 15U


#if (defined ComConf_ComSignal_SGRDrvnWhlRotlDistPlsCtrHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRDrvnWhlRotlDistPlsCtrHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGRDrvnWhlRotlDistPlsCtrHSC2_193R) */

#define ComConf_ComSignal_SGRDrvnWhlRotlDistPlsCtrHSC2_193R 16U


#if (defined ComConf_ComSignal_SGRDrvnWhlRotlDistTRCHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRDrvnWhlRotlDistTRCHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGRDrvnWhlRotlDistTRCHSC2_193R) */

#define ComConf_ComSignal_SGRDrvnWhlRotlDistTRCHSC2_193R 17U


#if (defined ComConf_ComSignal_SGRDrvnWhlRotlDistTmspHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRDrvnWhlRotlDistTmspHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGRDrvnWhlRotlDistTmspHSC2_193R) */

#define ComConf_ComSignal_SGRDrvnWhlRotlDistTmspHSC2_193R 18U


#if (defined ComConf_ComSignal_SGRDrvnWhlRotlDistVHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRDrvnWhlRotlDistVHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGRDrvnWhlRotlDistVHSC2_193R) */

#define ComConf_ComSignal_SGRDrvnWhlRotlDistVHSC2_193R 19U


#if (defined ComConf_ComSignal_SGRDrvnWhlRotlRstOcdHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRDrvnWhlRotlRstOcdHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGRDrvnWhlRotlRstOcdHSC2_193R) */

#define ComConf_ComSignal_SGRDrvnWhlRotlRstOcdHSC2_193R 20U


#if (defined ComConf_ComSignal_SGRDrvnWhlRotlSeqNumHSC2_193R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRDrvnWhlRotlSeqNumHSC2_193R already defined
#endif /* #if (defined ComConf_ComSignal_SGRDrvnWhlRotlSeqNumHSC2_193R) */

#define ComConf_ComSignal_SGRDrvnWhlRotlSeqNumHSC2_193R 21U


#if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDistPCHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLNonDrvnWhlRotlDistPCHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDistPCHSC2_197R) */

#define ComConf_ComSignal_SGLNonDrvnWhlRotlDistPCHSC2_197R 22U


#if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDistTHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLNonDrvnWhlRotlDistTHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDistTHSC2_197R) */

#define ComConf_ComSignal_SGLNonDrvnWhlRotlDistTHSC2_197R 23U


#if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDistTRCHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLNonDrvnWhlRotlDistTRCHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDistTRCHSC2_197R) */

#define ComConf_ComSignal_SGLNonDrvnWhlRotlDistTRCHSC2_197R 24U


#if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDistVHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLNonDrvnWhlRotlDistVHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDistVHSC2_197R) */

#define ComConf_ComSignal_SGLNonDrvnWhlRotlDistVHSC2_197R 25U


#if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlRstOcdHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLNonDrvnWhlRotlRstOcdHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlRstOcdHSC2_197R) */

#define ComConf_ComSignal_SGLNonDrvnWhlRotlRstOcdHSC2_197R 26U


#if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlSeqNumHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLNonDrvnWhlRotlSeqNumHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlSeqNumHSC2_197R) */

#define ComConf_ComSignal_SGLNonDrvnWhlRotlSeqNumHSC2_197R 27U


#if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDistPCHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRNonDrvnWhlRotlDistPCHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDistPCHSC2_197R) */

#define ComConf_ComSignal_SGRNonDrvnWhlRotlDistPCHSC2_197R 28U


#if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDistTHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRNonDrvnWhlRotlDistTHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDistTHSC2_197R) */

#define ComConf_ComSignal_SGRNonDrvnWhlRotlDistTHSC2_197R 29U


#if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDistTRCHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRNonDrvnWhlRotlDistTRCHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDistTRCHSC2_197R) */

#define ComConf_ComSignal_SGRNonDrvnWhlRotlDistTRCHSC2_197R 30U


#if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDistVHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRNonDrvnWhlRotlDistVHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDistVHSC2_197R) */

#define ComConf_ComSignal_SGRNonDrvnWhlRotlDistVHSC2_197R 31U


#if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlRstOcdHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRNonDrvnWhlRotlRstOcdHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlRstOcdHSC2_197R) */

#define ComConf_ComSignal_SGRNonDrvnWhlRotlRstOcdHSC2_197R 32U


#if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlSeqNumHSC2_197R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRNonDrvnWhlRotlSeqNumHSC2_197R already defined
#endif /* #if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlSeqNumHSC2_197R) */

#define ComConf_ComSignal_SGRNonDrvnWhlRotlSeqNumHSC2_197R 33U


#if (defined ComConf_ComSignal_SGVSELatAccHSC2_389R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVSELatAccHSC2_389R already defined
#endif /* #if (defined ComConf_ComSignal_SGVSELatAccHSC2_389R) */

#define ComConf_ComSignal_SGVSELatAccHSC2_389R 34U


#if (defined ComConf_ComSignal_SGVSELatAccVHSC2_389R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVSELatAccVHSC2_389R already defined
#endif /* #if (defined ComConf_ComSignal_SGVSELatAccVHSC2_389R) */

#define ComConf_ComSignal_SGVSELatAccVHSC2_389R 35U


#if (defined ComConf_ComSignal_SGVSELongtAccHSC2_389R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVSELongtAccHSC2_389R already defined
#endif /* #if (defined ComConf_ComSignal_SGVSELongtAccHSC2_389R) */

#define ComConf_ComSignal_SGVSELongtAccHSC2_389R 36U


#if (defined ComConf_ComSignal_SGVSELongtAccVHSC2_389R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVSELongtAccVHSC2_389R already defined
#endif /* #if (defined ComConf_ComSignal_SGVSELongtAccVHSC2_389R) */

#define ComConf_ComSignal_SGVSELongtAccVHSC2_389R 37U


#if (defined ComConf_ComSignal_SGEPSAPAAlvRCHSC2_433R) /* To prevent double declaration */
#error ComConf_ComSignal_SGEPSAPAAlvRCHSC2_433R already defined
#endif /* #if (defined ComConf_ComSignal_SGEPSAPAAlvRCHSC2_433R) */

#define ComConf_ComSignal_SGEPSAPAAlvRCHSC2_433R 38U


#if (defined ComConf_ComSignal_SGEPSAPAChksmHSC2_433R) /* To prevent double declaration */
#error ComConf_ComSignal_SGEPSAPAChksmHSC2_433R already defined
#endif /* #if (defined ComConf_ComSignal_SGEPSAPAChksmHSC2_433R) */

#define ComConf_ComSignal_SGEPSAPAChksmHSC2_433R 39U


#if (defined ComConf_ComSignal_SGEPSAPAInhHSC2_433R) /* To prevent double declaration */
#error ComConf_ComSignal_SGEPSAPAInhHSC2_433R already defined
#endif /* #if (defined ComConf_ComSignal_SGEPSAPAInhHSC2_433R) */

#define ComConf_ComSignal_SGEPSAPAInhHSC2_433R 40U


#if (defined ComConf_ComSignal_SGEPSAPAStsHSC2_433R) /* To prevent double declaration */
#error ComConf_ComSignal_SGEPSAPAStsHSC2_433R already defined
#endif /* #if (defined ComConf_ComSignal_SGEPSAPAStsHSC2_433R) */

#define ComConf_ComSignal_SGEPSAPAStsHSC2_433R 41U


#if (defined ComConf_ComSignal_SGBrkPdlAppdHSC2_438R) /* To prevent double declaration */
#error ComConf_ComSignal_SGBrkPdlAppdHSC2_438R already defined
#endif /* #if (defined ComConf_ComSignal_SGBrkPdlAppdHSC2_438R) */

#define ComConf_ComSignal_SGBrkPdlAppdHSC2_438R 42U


#if (defined ComConf_ComSignal_SGHydBstrCmpstnReqHSC2_438R) /* To prevent double declaration */
#error ComConf_ComSignal_SGHydBstrCmpstnReqHSC2_438R already defined
#endif /* #if (defined ComConf_ComSignal_SGHydBstrCmpstnReqHSC2_438R) */

#define ComConf_ComSignal_SGHydBstrCmpstnReqHSC2_438R 43U


#if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDircnHSC2_455R) /* To prevent double declaration */
#error ComConf_ComSignal_SGLNonDrvnWhlRotlDircnHSC2_455R already defined
#endif /* #if (defined ComConf_ComSignal_SGLNonDrvnWhlRotlDircnHSC2_455R) */

#define ComConf_ComSignal_SGLNonDrvnWhlRotlDircnHSC2_455R 44U


#if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDircnHSC2_455R) /* To prevent double declaration */
#error ComConf_ComSignal_SGRNonDrvnWhlRotlDircnHSC2_455R already defined
#endif /* #if (defined ComConf_ComSignal_SGRNonDrvnWhlRotlDircnHSC2_455R) */

#define ComConf_ComSignal_SGRNonDrvnWhlRotlDircnHSC2_455R 45U


#if (defined ComConf_ComSignal_SGSCSAPAAcclAHSC2_455R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCSAPAAcclAHSC2_455R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCSAPAAcclAHSC2_455R) */

#define ComConf_ComSignal_SGSCSAPAAcclAHSC2_455R 46U


#if (defined ComConf_ComSignal_SGSCSAPAAlvRCHSC2_455R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCSAPAAlvRCHSC2_455R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCSAPAAlvRCHSC2_455R) */

#define ComConf_ComSignal_SGSCSAPAAlvRCHSC2_455R 47U


#if (defined ComConf_ComSignal_SGSCSAPAAvlblHSC2_455R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCSAPAAvlblHSC2_455R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCSAPAAvlblHSC2_455R) */

#define ComConf_ComSignal_SGSCSAPAAvlblHSC2_455R 48U


#if (defined ComConf_ComSignal_SGSCSNRCDAvlblHSC2_455R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSCSNRCDAvlblHSC2_455R already defined
#endif /* #if (defined ComConf_ComSignal_SGSCSNRCDAvlblHSC2_455R) */

#define ComConf_ComSignal_SGSCSNRCDAvlblHSC2_455R 49U


#if (defined ComConf_ComSignal_SGStrgWhlAngHSC2_485R) /* To prevent double declaration */
#error ComConf_ComSignal_SGStrgWhlAngHSC2_485R already defined
#endif /* #if (defined ComConf_ComSignal_SGStrgWhlAngHSC2_485R) */

#define ComConf_ComSignal_SGStrgWhlAngHSC2_485R 50U


#if (defined ComConf_ComSignal_SGStrgWhlAngVHSC2_485R) /* To prevent double declaration */
#error ComConf_ComSignal_SGStrgWhlAngVHSC2_485R already defined
#endif /* #if (defined ComConf_ComSignal_SGStrgWhlAngVHSC2_485R) */

#define ComConf_ComSignal_SGStrgWhlAngVHSC2_485R 51U


#if (defined ComConf_ComSignal_SGABSAHSC2_489R) /* To prevent double declaration */
#error ComConf_ComSignal_SGABSAHSC2_489R already defined
#endif /* #if (defined ComConf_ComSignal_SGABSAHSC2_489R) */

#define ComConf_ComSignal_SGABSAHSC2_489R 52U


#if (defined ComConf_ComSignal_SGTCSAHSC2_489R) /* To prevent double declaration */
#error ComConf_ComSignal_SGTCSAHSC2_489R already defined
#endif /* #if (defined ComConf_ComSignal_SGTCSAHSC2_489R) */

#define ComConf_ComSignal_SGTCSAHSC2_489R 53U


#if (defined ComConf_ComSignal_SGVSESysAHSC2_489R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVSESysAHSC2_489R already defined
#endif /* #if (defined ComConf_ComSignal_SGVSESysAHSC2_489R) */

#define ComConf_ComSignal_SGVSESysAHSC2_489R 54U


#if (defined ComConf_ComSignal_SGVehDynYawRateHSC2_489R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVehDynYawRateHSC2_489R already defined
#endif /* #if (defined ComConf_ComSignal_SGVehDynYawRateHSC2_489R) */

#define ComConf_ComSignal_SGVehDynYawRateHSC2_489R 55U


#if (defined ComConf_ComSignal_SGVehDynYawRateVHSC2_489R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVehDynYawRateVHSC2_489R already defined
#endif /* #if (defined ComConf_ComSignal_SGVehDynYawRateVHSC2_489R) */

#define ComConf_ComSignal_SGVehDynYawRateVHSC2_489R 56U


#if (defined ComConf_ComSignal_SGEPBAppcnStsHSC2_554R) /* To prevent double declaration */
#error ComConf_ComSignal_SGEPBAppcnStsHSC2_554R already defined
#endif /* #if (defined ComConf_ComSignal_SGEPBAppcnStsHSC2_554R) */

#define ComConf_ComSignal_SGEPBAppcnStsHSC2_554R 57U


#if (defined ComConf_ComSignal_SGEPBAppcnStsPVHSC2_554R) /* To prevent double declaration */
#error ComConf_ComSignal_SGEPBAppcnStsPVHSC2_554R already defined
#endif /* #if (defined ComConf_ComSignal_SGEPBAppcnStsPVHSC2_554R) */

#define ComConf_ComSignal_SGEPBAppcnStsPVHSC2_554R 58U


#if (defined ComConf_ComSignal_SGEPBAvlblyStsHSC2_554R) /* To prevent double declaration */
#error ComConf_ComSignal_SGEPBAvlblyStsHSC2_554R already defined
#endif /* #if (defined ComConf_ComSignal_SGEPBAvlblyStsHSC2_554R) */

#define ComConf_ComSignal_SGEPBAvlblyStsHSC2_554R 59U


#if (defined ComConf_ComSignal_SGEPBAvlblyStsPVHSC2_554R) /* To prevent double declaration */
#error ComConf_ComSignal_SGEPBAvlblyStsPVHSC2_554R already defined
#endif /* #if (defined ComConf_ComSignal_SGEPBAvlblyStsPVHSC2_554R) */

#define ComConf_ComSignal_SGEPBAvlblyStsPVHSC2_554R 60U


#if (defined ComConf_ComSignal_SGWhlGndVelLDrvnHSC2_840R) /* To prevent double declaration */
#error ComConf_ComSignal_SGWhlGndVelLDrvnHSC2_840R already defined
#endif /* #if (defined ComConf_ComSignal_SGWhlGndVelLDrvnHSC2_840R) */

#define ComConf_ComSignal_SGWhlGndVelLDrvnHSC2_840R 61U


#if (defined ComConf_ComSignal_SGWhlGndVelLDrvnVHSC2_840R) /* To prevent double declaration */
#error ComConf_ComSignal_SGWhlGndVelLDrvnVHSC2_840R already defined
#endif /* #if (defined ComConf_ComSignal_SGWhlGndVelLDrvnVHSC2_840R) */

#define ComConf_ComSignal_SGWhlGndVelLDrvnVHSC2_840R 62U


#if (defined ComConf_ComSignal_SGWhlGndVelRDrvnHSC2_840R) /* To prevent double declaration */
#error ComConf_ComSignal_SGWhlGndVelRDrvnHSC2_840R already defined
#endif /* #if (defined ComConf_ComSignal_SGWhlGndVelRDrvnHSC2_840R) */

#define ComConf_ComSignal_SGWhlGndVelRDrvnHSC2_840R 63U


#if (defined ComConf_ComSignal_SGWhlGndVelRDrvnVHSC2_840R) /* To prevent double declaration */
#error ComConf_ComSignal_SGWhlGndVelRDrvnVHSC2_840R already defined
#endif /* #if (defined ComConf_ComSignal_SGWhlGndVelRDrvnVHSC2_840R) */

#define ComConf_ComSignal_SGWhlGndVelRDrvnVHSC2_840R 64U


#if (defined ComConf_ComSignal_SGWhlGndVelLNonDrvnHSC2_842R) /* To prevent double declaration */
#error ComConf_ComSignal_SGWhlGndVelLNonDrvnHSC2_842R already defined
#endif /* #if (defined ComConf_ComSignal_SGWhlGndVelLNonDrvnHSC2_842R) */

#define ComConf_ComSignal_SGWhlGndVelLNonDrvnHSC2_842R 65U


#if (defined ComConf_ComSignal_SGWhlGndVelLNonDrvnVHSC2_842R) /* To prevent double declaration */
#error ComConf_ComSignal_SGWhlGndVelLNonDrvnVHSC2_842R already defined
#endif /* #if (defined ComConf_ComSignal_SGWhlGndVelLNonDrvnVHSC2_842R) */

#define ComConf_ComSignal_SGWhlGndVelLNonDrvnVHSC2_842R 66U


#if (defined ComConf_ComSignal_SGWhlGndVelRNonDrvnHSC2_842R) /* To prevent double declaration */
#error ComConf_ComSignal_SGWhlGndVelRNonDrvnHSC2_842R already defined
#endif /* #if (defined ComConf_ComSignal_SGWhlGndVelRNonDrvnHSC2_842R) */

#define ComConf_ComSignal_SGWhlGndVelRNonDrvnHSC2_842R 67U


#if (defined ComConf_ComSignal_SGWhlGndVelRNonDrvnVHSC2_842R) /* To prevent double declaration */
#error ComConf_ComSignal_SGWhlGndVelRNonDrvnVHSC2_842R already defined
#endif /* #if (defined ComConf_ComSignal_SGWhlGndVelRNonDrvnVHSC2_842R) */

#define ComConf_ComSignal_SGWhlGndVelRNonDrvnVHSC2_842R 68U


#if (defined ComConf_ComSignal_SGDistRCAvgDrvnHSC2_851R) /* To prevent double declaration */
#error ComConf_ComSignal_SGDistRCAvgDrvnHSC2_851R already defined
#endif /* #if (defined ComConf_ComSignal_SGDistRCAvgDrvnHSC2_851R) */

#define ComConf_ComSignal_SGDistRCAvgDrvnHSC2_851R 69U


#if (defined ComConf_ComSignal_SGDistRCAvgDrvnRstOcdHSC2_851R) /* To prevent double declaration */
#error ComConf_ComSignal_SGDistRCAvgDrvnRstOcdHSC2_851R already defined
#endif /* #if (defined ComConf_ComSignal_SGDistRCAvgDrvnRstOcdHSC2_851R) */

#define ComConf_ComSignal_SGDistRCAvgDrvnRstOcdHSC2_851R 70U


#if (defined ComConf_ComSignal_SGDistRCAvgDrvnSrcHSC2_851R) /* To prevent double declaration */
#error ComConf_ComSignal_SGDistRCAvgDrvnSrcHSC2_851R already defined
#endif /* #if (defined ComConf_ComSignal_SGDistRCAvgDrvnSrcHSC2_851R) */

#define ComConf_ComSignal_SGDistRCAvgDrvnSrcHSC2_851R 71U


#if (defined ComConf_ComSignal_SGDistRCAvgDrvnVHSC2_851R) /* To prevent double declaration */
#error ComConf_ComSignal_SGDistRCAvgDrvnVHSC2_851R already defined
#endif /* #if (defined ComConf_ComSignal_SGDistRCAvgDrvnVHSC2_851R) */

#define ComConf_ComSignal_SGDistRCAvgDrvnVHSC2_851R 72U


#if (defined ComConf_ComSignal_SGVehSpdAvgDrvnHSC2_851R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVehSpdAvgDrvnHSC2_851R already defined
#endif /* #if (defined ComConf_ComSignal_SGVehSpdAvgDrvnHSC2_851R) */

#define ComConf_ComSignal_SGVehSpdAvgDrvnHSC2_851R 73U


#if (defined ComConf_ComSignal_SGVehSpdAvgDrvnVHSC2_851R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVehSpdAvgDrvnVHSC2_851R already defined
#endif /* #if (defined ComConf_ComSignal_SGVehSpdAvgDrvnVHSC2_851R) */

#define ComConf_ComSignal_SGVehSpdAvgDrvnVHSC2_851R 74U


#if (defined ComConf_ComSignal_SGVehSpdAvgNonDrvnHSC2_851R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVehSpdAvgNonDrvnHSC2_851R already defined
#endif /* #if (defined ComConf_ComSignal_SGVehSpdAvgNonDrvnHSC2_851R) */

#define ComConf_ComSignal_SGVehSpdAvgNonDrvnHSC2_851R 75U


#if (defined ComConf_ComSignal_SGVehSpdAvgNonDrvnVHSC2_851R) /* To prevent double declaration */
#error ComConf_ComSignal_SGVehSpdAvgNonDrvnVHSC2_851R already defined
#endif /* #if (defined ComConf_ComSignal_SGVehSpdAvgNonDrvnVHSC2_851R) */

#define ComConf_ComSignal_SGVehSpdAvgNonDrvnVHSC2_851R 76U


#if (defined ComConf_ComSignal_SGOtsdAirTemCrValMsk_h2HSC2_1009R) /* To prevent double declaration */
#error ComConf_ComSignal_SGOtsdAirTemCrValMsk_h2HSC2_1009R already defined
#endif /* #if (defined ComConf_ComSignal_SGOtsdAirTemCrValMsk_h2HSC2_1009R) */

#define ComConf_ComSignal_SGOtsdAirTemCrValMsk_h2HSC2_1009R 77U


#if (defined ComConf_ComSignal_SGOtsdAirTemCrValV_h2HSC2_1009R) /* To prevent double declaration */
#error ComConf_ComSignal_SGOtsdAirTemCrValV_h2HSC2_1009R already defined
#endif /* #if (defined ComConf_ComSignal_SGOtsdAirTemCrValV_h2HSC2_1009R) */

#define ComConf_ComSignal_SGOtsdAirTemCrValV_h2HSC2_1009R 78U


#if (defined ComConf_ComSignal_SGOtsdAirTemCrVal_h2HSC2_1009R) /* To prevent double declaration */
#error ComConf_ComSignal_SGOtsdAirTemCrVal_h2HSC2_1009R already defined
#endif /* #if (defined ComConf_ComSignal_SGOtsdAirTemCrVal_h2HSC2_1009R) */

#define ComConf_ComSignal_SGOtsdAirTemCrVal_h2HSC2_1009R 79U


#if (defined ComConf_ComSignal_SGCalendarDayHSC2_1345R) /* To prevent double declaration */
#error ComConf_ComSignal_SGCalendarDayHSC2_1345R already defined
#endif /* #if (defined ComConf_ComSignal_SGCalendarDayHSC2_1345R) */

#define ComConf_ComSignal_SGCalendarDayHSC2_1345R 80U


#if (defined ComConf_ComSignal_SGCalendarMonthHSC2_1345R) /* To prevent double declaration */
#error ComConf_ComSignal_SGCalendarMonthHSC2_1345R already defined
#endif /* #if (defined ComConf_ComSignal_SGCalendarMonthHSC2_1345R) */

#define ComConf_ComSignal_SGCalendarMonthHSC2_1345R 81U


#if (defined ComConf_ComSignal_SGCalendarYearHSC2_1345R) /* To prevent double declaration */
#error ComConf_ComSignal_SGCalendarYearHSC2_1345R already defined
#endif /* #if (defined ComConf_ComSignal_SGCalendarYearHSC2_1345R) */

#define ComConf_ComSignal_SGCalendarYearHSC2_1345R 82U


#if (defined ComConf_ComSignal_SGHourOfDayHSC2_1345R) /* To prevent double declaration */
#error ComConf_ComSignal_SGHourOfDayHSC2_1345R already defined
#endif /* #if (defined ComConf_ComSignal_SGHourOfDayHSC2_1345R) */

#define ComConf_ComSignal_SGHourOfDayHSC2_1345R 83U


#if (defined ComConf_ComSignal_SGMinuteOfHourHSC2_1345R) /* To prevent double declaration */
#error ComConf_ComSignal_SGMinuteOfHourHSC2_1345R already defined
#endif /* #if (defined ComConf_ComSignal_SGMinuteOfHourHSC2_1345R) */

#define ComConf_ComSignal_SGMinuteOfHourHSC2_1345R 84U


#if (defined ComConf_ComSignal_SGSecsOfMinuteHSC2_1345R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSecsOfMinuteHSC2_1345R already defined
#endif /* #if (defined ComConf_ComSignal_SGSecsOfMinuteHSC2_1345R) */

#define ComConf_ComSignal_SGSecsOfMinuteHSC2_1345R 85U


#if (defined ComConf_ComSignal_SGTimeDspFmtHSC2_1345R) /* To prevent double declaration */
#error ComConf_ComSignal_SGTimeDspFmtHSC2_1345R already defined
#endif /* #if (defined ComConf_ComSignal_SGTimeDspFmtHSC2_1345R) */

#define ComConf_ComSignal_SGTimeDspFmtHSC2_1345R 86U


#if (defined ComConf_ComSignal_SGSelectedBerthIdTmp_1321R) /* To prevent double declaration */
#error ComConf_ComSignal_SGSelectedBerthIdTmp_1321R already defined
#endif /* #if (defined ComConf_ComSignal_SGSelectedBerthIdTmp_1321R) */

#define ComConf_ComSignal_SGSelectedBerthIdTmp_1321R 87U


/* External Tx Signal IDs (no group signals) defines */
#if (defined ComConf_ComSignal_SGCounterOut_T) /* To prevent double declaration */
#error ComConf_ComSignal_SGCounterOut_T already defined
#endif /* #if (defined ComConf_ComSignal_SGCounterOut_T) */

#define ComConf_ComSignal_SGCounterOut_T 0U


#if (defined ComConf_ComSignal_SGDummyIn_T) /* To prevent double declaration */
#error ComConf_ComSignal_SGDummyIn_T already defined
#endif /* #if (defined ComConf_ComSignal_SGDummyIn_T) */

#define ComConf_ComSignal_SGDummyIn_T 1U


#if (defined ComConf_ComSignal_SGUssToolOut_T) /* To prevent double declaration */
#error ComConf_ComSignal_SGUssToolOut_T already defined
#endif /* #if (defined ComConf_ComSignal_SGUssToolOut_T) */

#define ComConf_ComSignal_SGUssToolOut_T 2U


#if (defined ComConf_ComSignal_SGCfmOut_T) /* To prevent double declaration */
#error ComConf_ComSignal_SGCfmOut_T already defined
#endif /* #if (defined ComConf_ComSignal_SGCfmOut_T) */

#define ComConf_ComSignal_SGCfmOut_T 3U


#if (defined ComConf_ComSignal_SGTestUdpOut_T) /* To prevent double declaration */
#error ComConf_ComSignal_SGTestUdpOut_T already defined
#endif /* #if (defined ComConf_ComSignal_SGTestUdpOut_T) */

#define ComConf_ComSignal_SGTestUdpOut_T 4U


#if (defined ComConf_ComSignal_SGAPAAlvRCHSC2_424T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAAlvRCHSC2_424T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAAlvRCHSC2_424T) */

#define ComConf_ComSignal_SGAPAAlvRCHSC2_424T 5U


#if (defined ComConf_ComSignal_SGAPAChksmHSC2_424T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAChksmHSC2_424T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAChksmHSC2_424T) */

#define ComConf_ComSignal_SGAPAChksmHSC2_424T 6U


#if (defined ComConf_ComSignal_SGAPACmdEPSStsHSC2_424T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPACmdEPSStsHSC2_424T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPACmdEPSStsHSC2_424T) */

#define ComConf_ComSignal_SGAPACmdEPSStsHSC2_424T 7U


#if (defined ComConf_ComSignal_SGAPAFHSC2_424T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAFHSC2_424T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAFHSC2_424T) */

#define ComConf_ComSignal_SGAPAFHSC2_424T 8U


#if (defined ComConf_ComSignal_SGAPAToqReqStsHSC2_424T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAToqReqStsHSC2_424T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAToqReqStsHSC2_424T) */

#define ComConf_ComSignal_SGAPAToqReqStsHSC2_424T 9U


#if (defined ComConf_ComSignal_SGAPAToqReqValHSC2_424T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAToqReqValHSC2_424T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAToqReqValHSC2_424T) */

#define ComConf_ComSignal_SGAPAToqReqValHSC2_424T 10U


#if (defined ComConf_ComSignal_SGAPATrgtEPSStrgWhlAngHSC2_424T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPATrgtEPSStrgWhlAngHSC2_424T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPATrgtEPSStrgWhlAngHSC2_424T) */

#define ComConf_ComSignal_SGAPATrgtEPSStrgWhlAngHSC2_424T 11U


#if (defined ComConf_ComSignal_SGAPACrpSpdReqStsHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPACrpSpdReqStsHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPACrpSpdReqStsHSC2_437T) */

#define ComConf_ComSignal_SGAPACrpSpdReqStsHSC2_437T 12U


#if (defined ComConf_ComSignal_SGAPACrpSpdReqValHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPACrpSpdReqValHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPACrpSpdReqValHSC2_437T) */

#define ComConf_ComSignal_SGAPACrpSpdReqValHSC2_437T 13U


#if (defined ComConf_ComSignal_SGAPAEPBOPReqHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAEPBOPReqHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAEPBOPReqHSC2_437T) */

#define ComConf_ComSignal_SGAPAEPBOPReqHSC2_437T 14U


#if (defined ComConf_ComSignal_SGAPAEPBOpReqValPVHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAEPBOpReqValPVHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAEPBOpReqValPVHSC2_437T) */

#define ComConf_ComSignal_SGAPAEPBOpReqValPVHSC2_437T 15U


#if (defined ComConf_ComSignal_SGAPAEPBReqAlvRCHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAEPBReqAlvRCHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAEPBReqAlvRCHSC2_437T) */

#define ComConf_ComSignal_SGAPAEPBReqAlvRCHSC2_437T 16U


#if (defined ComConf_ComSignal_SGAPAInfoDispReqHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAInfoDispReqHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAInfoDispReqHSC2_437T) */

#define ComConf_ComSignal_SGAPAInfoDispReqHSC2_437T 17U


#if (defined ComConf_ComSignal_SGAPAMdHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAMdHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAMdHSC2_437T) */

#define ComConf_ComSignal_SGAPAMdHSC2_437T 18U


#if (defined ComConf_ComSignal_SGAPANRCDAvlblHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPANRCDAvlblHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPANRCDAvlblHSC2_437T) */

#define ComConf_ComSignal_SGAPANRCDAvlblHSC2_437T 19U


#if (defined ComConf_ComSignal_SGAPAReqHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAReqHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAReqHSC2_437T) */

#define ComConf_ComSignal_SGAPAReqHSC2_437T 20U


#if (defined ComConf_ComSignal_SGAPASCSAcclReqStsHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPASCSAcclReqStsHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPASCSAcclReqStsHSC2_437T) */

#define ComConf_ComSignal_SGAPASCSAcclReqStsHSC2_437T 21U


#if (defined ComConf_ComSignal_SGAPASCSAcclReqValHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPASCSAcclReqValHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPASCSAcclReqValHSC2_437T) */

#define ComConf_ComSignal_SGAPASCSAcclReqValHSC2_437T 22U


#if (defined ComConf_ComSignal_SGAPASCSAcclReqValPVHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPASCSAcclReqValPVHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPASCSAcclReqValPVHSC2_437T) */

#define ComConf_ComSignal_SGAPASCSAcclReqValPVHSC2_437T 23U


#if (defined ComConf_ComSignal_SGAPASCSAlvRCHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPASCSAlvRCHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPASCSAlvRCHSC2_437T) */

#define ComConf_ComSignal_SGAPASCSAlvRCHSC2_437T 24U


#if (defined ComConf_ComSignal_SGAPAShifterPosReqdHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAShifterPosReqdHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAShifterPosReqdHSC2_437T) */

#define ComConf_ComSignal_SGAPAShifterPosReqdHSC2_437T 25U


#if (defined ComConf_ComSignal_SGAPAStsHSC2_437T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAStsHSC2_437T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAStsHSC2_437T) */

#define ComConf_ComSignal_SGAPAStsHSC2_437T 26U


#if (defined ComConf_ComSignal_SGFLSideObsDistHSC2_567T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFLSideObsDistHSC2_567T already defined
#endif /* #if (defined ComConf_ComSignal_SGFLSideObsDistHSC2_567T) */

#define ComConf_ComSignal_SGFLSideObsDistHSC2_567T 27U


#if (defined ComConf_ComSignal_SGFRSideObsDistHSC2_567T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFRSideObsDistHSC2_567T already defined
#endif /* #if (defined ComConf_ComSignal_SGFRSideObsDistHSC2_567T) */

#define ComConf_ComSignal_SGFRSideObsDistHSC2_567T 28U


#if (defined ComConf_ComSignal_SGRLSideObsDistHSC2_567T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRLSideObsDistHSC2_567T already defined
#endif /* #if (defined ComConf_ComSignal_SGRLSideObsDistHSC2_567T) */

#define ComConf_ComSignal_SGRLSideObsDistHSC2_567T 29U


#if (defined ComConf_ComSignal_SGRRSideObsDistHSC2_567T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRRSideObsDistHSC2_567T already defined
#endif /* #if (defined ComConf_ComSignal_SGRRSideObsDistHSC2_567T) */

#define ComConf_ComSignal_SGRRSideObsDistHSC2_567T 30U


#if (defined ComConf_ComSignal_SGFLObsRngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFLObsRngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGFLObsRngHSC2_573T) */

#define ComConf_ComSignal_SGFLObsRngHSC2_573T 31U


#if (defined ComConf_ComSignal_SGFRObsRngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFRObsRngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGFRObsRngHSC2_573T) */

#define ComConf_ComSignal_SGFRObsRngHSC2_573T 32U


#if (defined ComConf_ComSignal_SGFrtMidLObsRngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFrtMidLObsRngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGFrtMidLObsRngHSC2_573T) */

#define ComConf_ComSignal_SGFrtMidLObsRngHSC2_573T 33U


#if (defined ComConf_ComSignal_SGFrtMidRObsRngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFrtMidRObsRngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGFrtMidRObsRngHSC2_573T) */

#define ComConf_ComSignal_SGFrtMidRObsRngHSC2_573T 34U


#if (defined ComConf_ComSignal_SGFrtObsDistHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFrtObsDistHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGFrtObsDistHSC2_573T) */

#define ComConf_ComSignal_SGFrtObsDistHSC2_573T 35U


#if (defined ComConf_ComSignal_SGFrtPDCAudWrnngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFrtPDCAudWrnngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGFrtPDCAudWrnngHSC2_573T) */

#define ComConf_ComSignal_SGFrtPDCAudWrnngHSC2_573T 36U


#if (defined ComConf_ComSignal_SGPDCCofignStsHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGPDCCofignStsHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGPDCCofignStsHSC2_573T) */

#define ComConf_ComSignal_SGPDCCofignStsHSC2_573T 37U


#if (defined ComConf_ComSignal_SGPDCSysStsHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGPDCSysStsHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGPDCSysStsHSC2_573T) */

#define ComConf_ComSignal_SGPDCSysStsHSC2_573T 38U


#if (defined ComConf_ComSignal_SGRLObsRngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRLObsRngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGRLObsRngHSC2_573T) */

#define ComConf_ComSignal_SGRLObsRngHSC2_573T 39U


#if (defined ComConf_ComSignal_SGRRObsRngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRRObsRngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGRRObsRngHSC2_573T) */

#define ComConf_ComSignal_SGRRObsRngHSC2_573T 40U


#if (defined ComConf_ComSignal_SGRrMidLObsRngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRrMidLObsRngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGRrMidLObsRngHSC2_573T) */

#define ComConf_ComSignal_SGRrMidLObsRngHSC2_573T 41U


#if (defined ComConf_ComSignal_SGRrMidRObsRngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRrMidRObsRngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGRrMidRObsRngHSC2_573T) */

#define ComConf_ComSignal_SGRrMidRObsRngHSC2_573T 42U


#if (defined ComConf_ComSignal_SGRrObsDistHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRrObsDistHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGRrObsDistHSC2_573T) */

#define ComConf_ComSignal_SGRrObsDistHSC2_573T 43U


#if (defined ComConf_ComSignal_SGRrPDCAudWrnngHSC2_573T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRrPDCAudWrnngHSC2_573T already defined
#endif /* #if (defined ComConf_ComSignal_SGRrPDCAudWrnngHSC2_573T) */

#define ComConf_ComSignal_SGRrPDCAudWrnngHSC2_573T 44U


#if (defined ComConf_ComSignal_SGFLObsDist_sech2_SecCAN2_651T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFLObsDist_sech2_SecCAN2_651T already defined
#endif /* #if (defined ComConf_ComSignal_SGFLObsDist_sech2_SecCAN2_651T) */

#define ComConf_ComSignal_SGFLObsDist_sech2_SecCAN2_651T 45U


#if (defined ComConf_ComSignal_SGFRObsDist_sech2_SecCAN2_651T) /* To prevent double declaration */
#error ComConf_ComSignal_SGFRObsDist_sech2_SecCAN2_651T already defined
#endif /* #if (defined ComConf_ComSignal_SGFRObsDist_sech2_SecCAN2_651T) */

#define ComConf_ComSignal_SGFRObsDist_sech2_SecCAN2_651T 46U


#if (defined ComConf_ComSignal_SGRLObsDist_sech2_SecCAN2_651T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRLObsDist_sech2_SecCAN2_651T already defined
#endif /* #if (defined ComConf_ComSignal_SGRLObsDist_sech2_SecCAN2_651T) */

#define ComConf_ComSignal_SGRLObsDist_sech2_SecCAN2_651T 47U


#if (defined ComConf_ComSignal_SGRRObsDist_sech2_SecCAN2_651T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRRObsDist_sech2_SecCAN2_651T already defined
#endif /* #if (defined ComConf_ComSignal_SGRRObsDist_sech2_SecCAN2_651T) */

#define ComConf_ComSignal_SGRRObsDist_sech2_SecCAN2_651T 48U


#if (defined ComConf_ComSignal_SGIECUToBCMCtrlPotclHSC2_914T) /* To prevent double declaration */
#error ComConf_ComSignal_SGIECUToBCMCtrlPotclHSC2_914T already defined
#endif /* #if (defined ComConf_ComSignal_SGIECUToBCMCtrlPotclHSC2_914T) */

#define ComConf_ComSignal_SGIECUToBCMCtrlPotclHSC2_914T 49U


#if (defined ComConf_ComSignal_SGHD_AVMCurViewHSC4_764T) /* To prevent double declaration */
#error ComConf_ComSignal_SGHD_AVMCurViewHSC4_764T already defined
#endif /* #if (defined ComConf_ComSignal_SGHD_AVMCurViewHSC4_764T) */

#define ComConf_ComSignal_SGHD_AVMCurViewHSC4_764T 50U


#if (defined ComConf_ComSignal_SGHD_AVMErrorDisplay_h4HSC4_764T) /* To prevent double declaration */
#error ComConf_ComSignal_SGHD_AVMErrorDisplay_h4HSC4_764T already defined
#endif /* #if (defined ComConf_ComSignal_SGHD_AVMErrorDisplay_h4HSC4_764T) */

#define ComConf_ComSignal_SGHD_AVMErrorDisplay_h4HSC4_764T 51U


#if (defined ComConf_ComSignal_SGHD_AVMInfoDisplayHSC4_764T) /* To prevent double declaration */
#error ComConf_ComSignal_SGHD_AVMInfoDisplayHSC4_764T already defined
#endif /* #if (defined ComConf_ComSignal_SGHD_AVMInfoDisplayHSC4_764T) */

#define ComConf_ComSignal_SGHD_AVMInfoDisplayHSC4_764T 52U


#if (defined ComConf_ComSignal_SGHD_AVMVideoFmtStaHSC4_764T) /* To prevent double declaration */
#error ComConf_ComSignal_SGHD_AVMVideoFmtStaHSC4_764T already defined
#endif /* #if (defined ComConf_ComSignal_SGHD_AVMVideoFmtStaHSC4_764T) */

#define ComConf_ComSignal_SGHD_AVMVideoFmtStaHSC4_764T 53U


#if (defined ComConf_ComSignal_SGHD_AVMsysrdyHSC4_764T) /* To prevent double declaration */
#error ComConf_ComSignal_SGHD_AVMsysrdyHSC4_764T already defined
#endif /* #if (defined ComConf_ComSignal_SGHD_AVMsysrdyHSC4_764T) */

#define ComConf_ComSignal_SGHD_AVMsysrdyHSC4_764T 54U


#if (defined ComConf_ComSignal_SGRoute2StateHSC4_781T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRoute2StateHSC4_781T already defined
#endif /* #if (defined ComConf_ComSignal_SGRoute2StateHSC4_781T) */

#define ComConf_ComSignal_SGRoute2StateHSC4_781T 55U


#if (defined ComConf_ComSignal_SGAutoDrvngSysStsHSC4_912T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAutoDrvngSysStsHSC4_912T already defined
#endif /* #if (defined ComConf_ComSignal_SGAutoDrvngSysStsHSC4_912T) */

#define ComConf_ComSignal_SGAutoDrvngSysStsHSC4_912T 56U


#if (defined ComConf_ComSignal_SGAPAParkngSchedHSC2_966T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAParkngSchedHSC2_966T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAParkngSchedHSC2_966T) */

#define ComConf_ComSignal_SGAPAParkngSchedHSC2_966T 57U


#if (defined ComConf_ComSignal_SGAPAParkngSchedVHSC2_966T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAParkngSchedVHSC2_966T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAParkngSchedVHSC2_966T) */

#define ComConf_ComSignal_SGAPAParkngSchedVHSC2_966T 58U


#if (defined ComConf_ComSignal_SGAPASlotBearngHSC2_966T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPASlotBearngHSC2_966T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPASlotBearngHSC2_966T) */

#define ComConf_ComSignal_SGAPASlotBearngHSC2_966T 59U


#if (defined ComConf_ComSignal_SGAPASlotLngthHSC2_966T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPASlotLngthHSC2_966T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPASlotLngthHSC2_966T) */

#define ComConf_ComSignal_SGAPASlotLngthHSC2_966T 60U


#if (defined ComConf_ComSignal_SGAPAVehCrdnatAzmthHSC2_966T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAVehCrdnatAzmthHSC2_966T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAVehCrdnatAzmthHSC2_966T) */

#define ComConf_ComSignal_SGAPAVehCrdnatAzmthHSC2_966T 61U


#if (defined ComConf_ComSignal_SGAPAVehCrdnatPosXHSC2_966T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAVehCrdnatPosXHSC2_966T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAVehCrdnatPosXHSC2_966T) */

#define ComConf_ComSignal_SGAPAVehCrdnatPosXHSC2_966T 62U


#if (defined ComConf_ComSignal_SGAPAVehCrdnatPosYHSC2_966T) /* To prevent double declaration */
#error ComConf_ComSignal_SGAPAVehCrdnatPosYHSC2_966T already defined
#endif /* #if (defined ComConf_ComSignal_SGAPAVehCrdnatPosYHSC2_966T) */

#define ComConf_ComSignal_SGAPAVehCrdnatPosYHSC2_966T 63U


#if (defined ComConf_ComSignal_SGDspObjInfo_531_Counter_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGDspObjInfo_531_Counter_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGDspObjInfo_531_Counter_1329T) */

#define ComConf_ComSignal_SGDspObjInfo_531_Counter_1329T 64U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_0_DspMode_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_531_0_DspMode_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_0_DspMode_1329T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_531_0_DspMode_1329T 65U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_0_ID_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_531_0_ID_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_0_ID_1329T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_531_0_ID_1329T 66U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_1_DspMode_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_531_1_DspMode_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_1_DspMode_1329T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_531_1_DspMode_1329T 67U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_1_ID_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_531_1_ID_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_1_ID_1329T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_531_1_ID_1329T 68U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_2_DspMode_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_531_2_DspMode_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_2_DspMode_1329T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_531_2_DspMode_1329T 69U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_2_ID_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_531_2_ID_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_2_ID_1329T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_531_2_ID_1329T 70U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_3_DspMode_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_531_3_DspMode_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_3_DspMode_1329T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_531_3_DspMode_1329T 71U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_3_ID_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_531_3_ID_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_531_3_ID_1329T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_531_3_ID_1329T 72U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_531_0_DspMode_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_531_0_DspMode_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_531_0_DspMode_1329T) */

#define ComConf_ComSignal_SGRightDspObjInfo_531_0_DspMode_1329T 73U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_531_0_ID_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_531_0_ID_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_531_0_ID_1329T) */

#define ComConf_ComSignal_SGRightDspObjInfo_531_0_ID_1329T 74U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_531_1_DspMode_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_531_1_DspMode_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_531_1_DspMode_1329T) */

#define ComConf_ComSignal_SGRightDspObjInfo_531_1_DspMode_1329T 75U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_531_1_ID_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_531_1_ID_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_531_1_ID_1329T) */

#define ComConf_ComSignal_SGRightDspObjInfo_531_1_ID_1329T 76U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_531_2_DspMode_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_531_2_DspMode_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_531_2_DspMode_1329T) */

#define ComConf_ComSignal_SGRightDspObjInfo_531_2_DspMode_1329T 77U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_531_2_ID_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_531_2_ID_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_531_2_ID_1329T) */

#define ComConf_ComSignal_SGRightDspObjInfo_531_2_ID_1329T 78U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_531_3_DspMode_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_531_3_DspMode_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_531_3_DspMode_1329T) */

#define ComConf_ComSignal_SGRightDspObjInfo_531_3_DspMode_1329T 79U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_531_3_ID_1329T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_531_3_ID_1329T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_531_3_ID_1329T) */

#define ComConf_ComSignal_SGRightDspObjInfo_531_3_ID_1329T 80U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_CounterHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_0_CounterHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_CounterHSC4_1330T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_0_CounterHSC4_1330T 81U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_ThetaHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_0_ThetaHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_ThetaHSC4_1330T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_0_ThetaHSC4_1330T 82U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_TypeHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_0_TypeHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_TypeHSC4_1330T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_0_TypeHSC4_1330T 83U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_XHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_0_XHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_XHSC4_1330T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_0_XHSC4_1330T 84U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_YHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_0_YHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_0_YHSC4_1330T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_0_YHSC4_1330T 85U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_0_CounterHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_0_CounterHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_0_CounterHSC4_1330T) */

#define ComConf_ComSignal_SGRightDspObjInfo_0_CounterHSC4_1330T 86U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_0_ThetaHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_0_ThetaHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_0_ThetaHSC4_1330T) */

#define ComConf_ComSignal_SGRightDspObjInfo_0_ThetaHSC4_1330T 87U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_0_TypeHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_0_TypeHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_0_TypeHSC4_1330T) */

#define ComConf_ComSignal_SGRightDspObjInfo_0_TypeHSC4_1330T 88U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_0_XHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_0_XHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_0_XHSC4_1330T) */

#define ComConf_ComSignal_SGRightDspObjInfo_0_XHSC4_1330T 89U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_0_YHSC4_1330T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_0_YHSC4_1330T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_0_YHSC4_1330T) */

#define ComConf_ComSignal_SGRightDspObjInfo_0_YHSC4_1330T 90U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_CounterHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_1_CounterHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_CounterHSC4_1337T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_1_CounterHSC4_1337T 91U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_ThetaHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_1_ThetaHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_ThetaHSC4_1337T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_1_ThetaHSC4_1337T 92U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_TypeHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_1_TypeHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_TypeHSC4_1337T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_1_TypeHSC4_1337T 93U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_XHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_1_XHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_XHSC4_1337T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_1_XHSC4_1337T 94U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_YHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_1_YHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_1_YHSC4_1337T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_1_YHSC4_1337T 95U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_1_CounterHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_1_CounterHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_1_CounterHSC4_1337T) */

#define ComConf_ComSignal_SGRightDspObjInfo_1_CounterHSC4_1337T 96U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_1_ThetaHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_1_ThetaHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_1_ThetaHSC4_1337T) */

#define ComConf_ComSignal_SGRightDspObjInfo_1_ThetaHSC4_1337T 97U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_1_TypeHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_1_TypeHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_1_TypeHSC4_1337T) */

#define ComConf_ComSignal_SGRightDspObjInfo_1_TypeHSC4_1337T 98U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_1_XHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_1_XHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_1_XHSC4_1337T) */

#define ComConf_ComSignal_SGRightDspObjInfo_1_XHSC4_1337T 99U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_1_YHSC4_1337T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_1_YHSC4_1337T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_1_YHSC4_1337T) */

#define ComConf_ComSignal_SGRightDspObjInfo_1_YHSC4_1337T 100U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_CounterHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_2_CounterHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_CounterHSC4_1339T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_2_CounterHSC4_1339T 101U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_ThetaHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_2_ThetaHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_ThetaHSC4_1339T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_2_ThetaHSC4_1339T 102U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_TypeHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_2_TypeHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_TypeHSC4_1339T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_2_TypeHSC4_1339T 103U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_XHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_2_XHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_XHSC4_1339T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_2_XHSC4_1339T 104U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_YHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_2_YHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_2_YHSC4_1339T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_2_YHSC4_1339T 105U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_2_CounterHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_2_CounterHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_2_CounterHSC4_1339T) */

#define ComConf_ComSignal_SGRightDspObjInfo_2_CounterHSC4_1339T 106U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_2_ThetaHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_2_ThetaHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_2_ThetaHSC4_1339T) */

#define ComConf_ComSignal_SGRightDspObjInfo_2_ThetaHSC4_1339T 107U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_2_TypeHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_2_TypeHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_2_TypeHSC4_1339T) */

#define ComConf_ComSignal_SGRightDspObjInfo_2_TypeHSC4_1339T 108U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_2_XHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_2_XHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_2_XHSC4_1339T) */

#define ComConf_ComSignal_SGRightDspObjInfo_2_XHSC4_1339T 109U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_2_YHSC4_1339T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_2_YHSC4_1339T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_2_YHSC4_1339T) */

#define ComConf_ComSignal_SGRightDspObjInfo_2_YHSC4_1339T 110U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_CounterHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_3_CounterHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_CounterHSC4_1340T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_3_CounterHSC4_1340T 111U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_ThetaHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_3_ThetaHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_ThetaHSC4_1340T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_3_ThetaHSC4_1340T 112U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_TypeHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_3_TypeHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_TypeHSC4_1340T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_3_TypeHSC4_1340T 113U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_XHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_3_XHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_XHSC4_1340T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_3_XHSC4_1340T 114U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_YHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_3_YHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_3_YHSC4_1340T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_3_YHSC4_1340T 115U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_3_CounterHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_3_CounterHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_3_CounterHSC4_1340T) */

#define ComConf_ComSignal_SGRightDspObjInfo_3_CounterHSC4_1340T 116U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_3_ThetaHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_3_ThetaHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_3_ThetaHSC4_1340T) */

#define ComConf_ComSignal_SGRightDspObjInfo_3_ThetaHSC4_1340T 117U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_3_TypeHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_3_TypeHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_3_TypeHSC4_1340T) */

#define ComConf_ComSignal_SGRightDspObjInfo_3_TypeHSC4_1340T 118U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_3_XHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_3_XHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_3_XHSC4_1340T) */

#define ComConf_ComSignal_SGRightDspObjInfo_3_XHSC4_1340T 119U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_3_YHSC4_1340T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_3_YHSC4_1340T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_3_YHSC4_1340T) */

#define ComConf_ComSignal_SGRightDspObjInfo_3_YHSC4_1340T 120U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_CounterHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_4_CounterHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_CounterHSC4_1341T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_4_CounterHSC4_1341T 121U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_ThetaHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_4_ThetaHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_ThetaHSC4_1341T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_4_ThetaHSC4_1341T 122U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_TypeHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_4_TypeHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_TypeHSC4_1341T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_4_TypeHSC4_1341T 123U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_XHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_4_XHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_XHSC4_1341T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_4_XHSC4_1341T 124U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_YHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_4_YHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_4_YHSC4_1341T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_4_YHSC4_1341T 125U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_4_CounterHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_4_CounterHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_4_CounterHSC4_1341T) */

#define ComConf_ComSignal_SGRightDspObjInfo_4_CounterHSC4_1341T 126U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_4_ThetaHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_4_ThetaHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_4_ThetaHSC4_1341T) */

#define ComConf_ComSignal_SGRightDspObjInfo_4_ThetaHSC4_1341T 127U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_4_TypeHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_4_TypeHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_4_TypeHSC4_1341T) */

#define ComConf_ComSignal_SGRightDspObjInfo_4_TypeHSC4_1341T 128U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_4_XHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_4_XHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_4_XHSC4_1341T) */

#define ComConf_ComSignal_SGRightDspObjInfo_4_XHSC4_1341T 129U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_4_YHSC4_1341T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_4_YHSC4_1341T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_4_YHSC4_1341T) */

#define ComConf_ComSignal_SGRightDspObjInfo_4_YHSC4_1341T 130U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_CounterHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_5_CounterHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_CounterHSC4_1342T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_5_CounterHSC4_1342T 131U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_ThetaHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_5_ThetaHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_ThetaHSC4_1342T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_5_ThetaHSC4_1342T 132U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_TypeHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_5_TypeHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_TypeHSC4_1342T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_5_TypeHSC4_1342T 133U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_XHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_5_XHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_XHSC4_1342T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_5_XHSC4_1342T 134U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_YHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_5_YHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_5_YHSC4_1342T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_5_YHSC4_1342T 135U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_5_CounterHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_5_CounterHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_5_CounterHSC4_1342T) */

#define ComConf_ComSignal_SGRightDspObjInfo_5_CounterHSC4_1342T 136U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_5_ThetaHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_5_ThetaHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_5_ThetaHSC4_1342T) */

#define ComConf_ComSignal_SGRightDspObjInfo_5_ThetaHSC4_1342T 137U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_5_TypeHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_5_TypeHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_5_TypeHSC4_1342T) */

#define ComConf_ComSignal_SGRightDspObjInfo_5_TypeHSC4_1342T 138U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_5_XHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_5_XHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_5_XHSC4_1342T) */

#define ComConf_ComSignal_SGRightDspObjInfo_5_XHSC4_1342T 139U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_5_YHSC4_1342T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_5_YHSC4_1342T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_5_YHSC4_1342T) */

#define ComConf_ComSignal_SGRightDspObjInfo_5_YHSC4_1342T 140U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_CounterHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_6_CounterHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_CounterHSC4_1343T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_6_CounterHSC4_1343T 141U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_ThetaHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_6_ThetaHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_ThetaHSC4_1343T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_6_ThetaHSC4_1343T 142U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_TypeHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_6_TypeHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_TypeHSC4_1343T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_6_TypeHSC4_1343T 143U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_XHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_6_XHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_XHSC4_1343T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_6_XHSC4_1343T 144U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_YHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_6_YHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_6_YHSC4_1343T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_6_YHSC4_1343T 145U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_6_CounterHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_6_CounterHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_6_CounterHSC4_1343T) */

#define ComConf_ComSignal_SGRightDspObjInfo_6_CounterHSC4_1343T 146U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_6_ThetaHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_6_ThetaHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_6_ThetaHSC4_1343T) */

#define ComConf_ComSignal_SGRightDspObjInfo_6_ThetaHSC4_1343T 147U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_6_TypeHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_6_TypeHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_6_TypeHSC4_1343T) */

#define ComConf_ComSignal_SGRightDspObjInfo_6_TypeHSC4_1343T 148U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_6_XHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_6_XHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_6_XHSC4_1343T) */

#define ComConf_ComSignal_SGRightDspObjInfo_6_XHSC4_1343T 149U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_6_YHSC4_1343T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_6_YHSC4_1343T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_6_YHSC4_1343T) */

#define ComConf_ComSignal_SGRightDspObjInfo_6_YHSC4_1343T 150U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_CounterHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_7_CounterHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_CounterHSC4_1346T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_7_CounterHSC4_1346T 151U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_ThetaHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_7_ThetaHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_ThetaHSC4_1346T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_7_ThetaHSC4_1346T 152U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_TypeHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_7_TypeHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_TypeHSC4_1346T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_7_TypeHSC4_1346T 153U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_XHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_7_XHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_XHSC4_1346T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_7_XHSC4_1346T 154U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_YHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_7_YHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_7_YHSC4_1346T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_7_YHSC4_1346T 155U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_7_CounterHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_7_CounterHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_7_CounterHSC4_1346T) */

#define ComConf_ComSignal_SGRightDspObjInfo_7_CounterHSC4_1346T 156U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_7_ThetaHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_7_ThetaHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_7_ThetaHSC4_1346T) */

#define ComConf_ComSignal_SGRightDspObjInfo_7_ThetaHSC4_1346T 157U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_7_TypeHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_7_TypeHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_7_TypeHSC4_1346T) */

#define ComConf_ComSignal_SGRightDspObjInfo_7_TypeHSC4_1346T 158U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_7_XHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_7_XHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_7_XHSC4_1346T) */

#define ComConf_ComSignal_SGRightDspObjInfo_7_XHSC4_1346T 159U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_7_YHSC4_1346T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_7_YHSC4_1346T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_7_YHSC4_1346T) */

#define ComConf_ComSignal_SGRightDspObjInfo_7_YHSC4_1346T 160U


#if (defined ComConf_ComSignal_SGDspObjInfo_545_Counter_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGDspObjInfo_545_Counter_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGDspObjInfo_545_Counter_1349T) */

#define ComConf_ComSignal_SGDspObjInfo_545_Counter_1349T 161U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_4_DspMode_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_545_4_DspMode_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_4_DspMode_1349T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_545_4_DspMode_1349T 162U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_4_ID_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_545_4_ID_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_4_ID_1349T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_545_4_ID_1349T 163U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_5_DspMode_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_545_5_DspMode_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_5_DspMode_1349T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_545_5_DspMode_1349T 164U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_5_ID_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_545_5_ID_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_5_ID_1349T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_545_5_ID_1349T 165U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_6_DspMode_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_545_6_DspMode_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_6_DspMode_1349T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_545_6_DspMode_1349T 166U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_6_ID_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_545_6_ID_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_6_ID_1349T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_545_6_ID_1349T 167U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_7_DspMode_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_545_7_DspMode_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_7_DspMode_1349T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_545_7_DspMode_1349T 168U


#if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_7_ID_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGLeftDspObjInfo_545_7_ID_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGLeftDspObjInfo_545_7_ID_1349T) */

#define ComConf_ComSignal_SGLeftDspObjInfo_545_7_ID_1349T 169U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_545_4_DspMode_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_545_4_DspMode_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_545_4_DspMode_1349T) */

#define ComConf_ComSignal_SGRightDspObjInfo_545_4_DspMode_1349T 170U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_545_4_ID_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_545_4_ID_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_545_4_ID_1349T) */

#define ComConf_ComSignal_SGRightDspObjInfo_545_4_ID_1349T 171U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_545_5_DspMode_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_545_5_DspMode_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_545_5_DspMode_1349T) */

#define ComConf_ComSignal_SGRightDspObjInfo_545_5_DspMode_1349T 172U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_545_5_ID_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_545_5_ID_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_545_5_ID_1349T) */

#define ComConf_ComSignal_SGRightDspObjInfo_545_5_ID_1349T 173U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_545_6_DspMode_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_545_6_DspMode_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_545_6_DspMode_1349T) */

#define ComConf_ComSignal_SGRightDspObjInfo_545_6_DspMode_1349T 174U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_545_6_ID_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_545_6_ID_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_545_6_ID_1349T) */

#define ComConf_ComSignal_SGRightDspObjInfo_545_6_ID_1349T 175U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_545_7_DspMode_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_545_7_DspMode_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_545_7_DspMode_1349T) */

#define ComConf_ComSignal_SGRightDspObjInfo_545_7_DspMode_1349T 176U


#if (defined ComConf_ComSignal_SGRightDspObjInfo_545_7_ID_1349T) /* To prevent double declaration */
#error ComConf_ComSignal_SGRightDspObjInfo_545_7_ID_1349T already defined
#endif /* #if (defined ComConf_ComSignal_SGRightDspObjInfo_545_7_ID_1349T) */

#define ComConf_ComSignal_SGRightDspObjInfo_545_7_ID_1349T 177U


/* External Rx Group Signal IDs defines */
/* External Tx Group Signal IDs defines */
/* External Rx Signal Group IDs defines */
/* External Tx Signal Group IDs defines */

/*------------------[symbols without prefix for backward compatibility]-----*/
#if (defined COM_PROVIDE_LEGACY_SYMBOLIC_NAMES)

/* IPDU group ID defines */

#if (defined Com_RXPDUS_GLOBAL) /* To prevent double declaration */
#error Com_RXPDUS_GLOBAL already defined
#endif /* #if (defined Com_RXPDUS_GLOBAL) */

#define Com_RXPDUS_GLOBAL ComConf_ComIPduGroup_RXPDUS_GLOBAL



#if (defined Com_TXPDUS_GLOBAL) /* To prevent double declaration */
#error Com_TXPDUS_GLOBAL already defined
#endif /* #if (defined Com_TXPDUS_GLOBAL) */

#define Com_TXPDUS_GLOBAL ComConf_ComIPduGroup_TXPDUS_GLOBAL



#if (defined Com_RGEthChannel) /* To prevent double declaration */
#error Com_RGEthChannel already defined
#endif /* #if (defined Com_RGEthChannel) */

#define Com_RGEthChannel ComConf_ComIPduGroup_RGEthChannel



#if (defined Com_TGEthChannel) /* To prevent double declaration */
#error Com_TGEthChannel already defined
#endif /* #if (defined Com_TGEthChannel) */

#define Com_TGEthChannel ComConf_ComIPduGroup_TGEthChannel



#if (defined Com_RGCanNetwork) /* To prevent double declaration */
#error Com_RGCanNetwork already defined
#endif /* #if (defined Com_RGCanNetwork) */

#define Com_RGCanNetwork ComConf_ComIPduGroup_RGCanNetwork



#if (defined Com_TGCanNetwork) /* To prevent double declaration */
#error Com_TGCanNetwork already defined
#endif /* #if (defined Com_TGCanNetwork) */

#define Com_TGCanNetwork ComConf_ComIPduGroup_TGCanNetwork


/* External Rx IPdus defines */
#if (defined Com_PDPdu_DummyOut_R) /* To prevent double declaration */
#error Com_PDPdu_DummyOut_R already defined
#endif /* #if (defined Com_PDPdu_DummyOut_R) */

#define Com_PDPdu_DummyOut_R ComConf_ComIPdu_PDPdu_DummyOut_R


#if (defined Com_PDPdu_CounterIn_R) /* To prevent double declaration */
#error Com_PDPdu_CounterIn_R already defined
#endif /* #if (defined Com_PDPdu_CounterIn_R) */

#define Com_PDPdu_CounterIn_R ComConf_ComIPdu_PDPdu_CounterIn_R


#if (defined Com_PDPdu_UssToolIn_R) /* To prevent double declaration */
#error Com_PDPdu_UssToolIn_R already defined
#endif /* #if (defined Com_PDPdu_UssToolIn_R) */

#define Com_PDPdu_UssToolIn_R ComConf_ComIPdu_PDPdu_UssToolIn_R


#if (defined Com_PDPdu_CfmIn_R) /* To prevent double declaration */
#error Com_PDPdu_CfmIn_R already defined
#endif /* #if (defined Com_PDPdu_CfmIn_R) */

#define Com_PDPdu_CfmIn_R ComConf_ComIPdu_PDPdu_CfmIn_R


#if (defined Com_PDPdu_TestUdpOut_R) /* To prevent double declaration */
#error Com_PDPdu_TestUdpOut_R already defined
#endif /* #if (defined Com_PDPdu_TestUdpOut_R) */

#define Com_PDPdu_TestUdpOut_R ComConf_ComIPdu_PDPdu_TestUdpOut_R


#if (defined Com_PDGW_HSC2_SCU_FrP00_157R) /* To prevent double declaration */
#error Com_PDGW_HSC2_SCU_FrP00_157R already defined
#endif /* #if (defined Com_PDGW_HSC2_SCU_FrP00_157R) */

#define Com_PDGW_HSC2_SCU_FrP00_157R ComConf_ComIPdu_PDGW_HSC2_SCU_FrP00_157R


#if (defined Com_PDSCS_HSC2_FrP00_193R) /* To prevent double declaration */
#error Com_PDSCS_HSC2_FrP00_193R already defined
#endif /* #if (defined Com_PDSCS_HSC2_FrP00_193R) */

#define Com_PDSCS_HSC2_FrP00_193R ComConf_ComIPdu_PDSCS_HSC2_FrP00_193R


#if (defined Com_PDSCS_HSC2_FrP01_197R) /* To prevent double declaration */
#error Com_PDSCS_HSC2_FrP01_197R already defined
#endif /* #if (defined Com_PDSCS_HSC2_FrP01_197R) */

#define Com_PDSCS_HSC2_FrP01_197R ComConf_ComIPdu_PDSCS_HSC2_FrP01_197R


#if (defined Com_PDSCS_HSC2_FrP02_389R) /* To prevent double declaration */
#error Com_PDSCS_HSC2_FrP02_389R already defined
#endif /* #if (defined Com_PDSCS_HSC2_FrP02_389R) */

#define Com_PDSCS_HSC2_FrP02_389R ComConf_ComIPdu_PDSCS_HSC2_FrP02_389R


#if (defined Com_PDEPS_HSC2_FrP02_433R) /* To prevent double declaration */
#error Com_PDEPS_HSC2_FrP02_433R already defined
#endif /* #if (defined Com_PDEPS_HSC2_FrP02_433R) */

#define Com_PDEPS_HSC2_FrP02_433R ComConf_ComIPdu_PDEPS_HSC2_FrP02_433R


#if (defined Com_PDEHBS_HSC2_FrP00_438R) /* To prevent double declaration */
#error Com_PDEHBS_HSC2_FrP00_438R already defined
#endif /* #if (defined Com_PDEHBS_HSC2_FrP00_438R) */

#define Com_PDEHBS_HSC2_FrP00_438R ComConf_ComIPdu_PDEHBS_HSC2_FrP00_438R


#if (defined Com_PDSCS_HSC2_FrP03_455R) /* To prevent double declaration */
#error Com_PDSCS_HSC2_FrP03_455R already defined
#endif /* #if (defined Com_PDSCS_HSC2_FrP03_455R) */

#define Com_PDSCS_HSC2_FrP03_455R ComConf_ComIPdu_PDSCS_HSC2_FrP03_455R


#if (defined Com_PDSAS_HSC2_FrP00_485R) /* To prevent double declaration */
#error Com_PDSAS_HSC2_FrP00_485R already defined
#endif /* #if (defined Com_PDSAS_HSC2_FrP00_485R) */

#define Com_PDSAS_HSC2_FrP00_485R ComConf_ComIPdu_PDSAS_HSC2_FrP00_485R


#if (defined Com_PDSCS_HSC2_FrP05_489R) /* To prevent double declaration */
#error Com_PDSCS_HSC2_FrP05_489R already defined
#endif /* #if (defined Com_PDSCS_HSC2_FrP05_489R) */

#define Com_PDSCS_HSC2_FrP05_489R ComConf_ComIPdu_PDSCS_HSC2_FrP05_489R


#if (defined Com_PDEPB_HSC2_FrP01_554R) /* To prevent double declaration */
#error Com_PDEPB_HSC2_FrP01_554R already defined
#endif /* #if (defined Com_PDEPB_HSC2_FrP01_554R) */

#define Com_PDEPB_HSC2_FrP01_554R ComConf_ComIPdu_PDEPB_HSC2_FrP01_554R


#if (defined Com_PDSCS_HSC2_FrP11_840R) /* To prevent double declaration */
#error Com_PDSCS_HSC2_FrP11_840R already defined
#endif /* #if (defined Com_PDSCS_HSC2_FrP11_840R) */

#define Com_PDSCS_HSC2_FrP11_840R ComConf_ComIPdu_PDSCS_HSC2_FrP11_840R


#if (defined Com_PDSCS_HSC2_FrP12_842R) /* To prevent double declaration */
#error Com_PDSCS_HSC2_FrP12_842R already defined
#endif /* #if (defined Com_PDSCS_HSC2_FrP12_842R) */

#define Com_PDSCS_HSC2_FrP12_842R ComConf_ComIPdu_PDSCS_HSC2_FrP12_842R


#if (defined Com_PDSCS_HSC2_FrP15_851R) /* To prevent double declaration */
#error Com_PDSCS_HSC2_FrP15_851R already defined
#endif /* #if (defined Com_PDSCS_HSC2_FrP15_851R) */

#define Com_PDSCS_HSC2_FrP15_851R ComConf_ComIPdu_PDSCS_HSC2_FrP15_851R


#if (defined Com_PDGW_HSC2_FrP10_1009R) /* To prevent double declaration */
#error Com_PDGW_HSC2_FrP10_1009R already defined
#endif /* #if (defined Com_PDGW_HSC2_FrP10_1009R) */

#define Com_PDGW_HSC2_FrP10_1009R ComConf_ComIPdu_PDGW_HSC2_FrP10_1009R


#if (defined Com_PDGW_HSC2_IPK_FrP06_1345R) /* To prevent double declaration */
#error Com_PDGW_HSC2_IPK_FrP06_1345R already defined
#endif /* #if (defined Com_PDGW_HSC2_IPK_FrP06_1345R) */

#define Com_PDGW_HSC2_IPK_FrP06_1345R ComConf_ComIPdu_PDGW_HSC2_IPK_FrP06_1345R


#if (defined Com_PDEM_BerthIdInfo_0x529_1321R) /* To prevent double declaration */
#error Com_PDEM_BerthIdInfo_0x529_1321R already defined
#endif /* #if (defined Com_PDEM_BerthIdInfo_0x529_1321R) */

#define Com_PDEM_BerthIdInfo_0x529_1321R ComConf_ComIPdu_PDEM_BerthIdInfo_0x529_1321R


/* External Tx IPdu defines */
#if (defined Com_PDP2P_HSC2_FrP00_424T) /* To prevent double declaration */
#error Com_PDP2P_HSC2_FrP00_424T already defined
#endif /* #if (defined Com_PDP2P_HSC2_FrP00_424T) */

#define Com_PDP2P_HSC2_FrP00_424T ComConf_ComIPdu_PDP2P_HSC2_FrP00_424T


#if (defined Com_PDP2P_HSC2_FrP01_437T) /* To prevent double declaration */
#error Com_PDP2P_HSC2_FrP01_437T already defined
#endif /* #if (defined Com_PDP2P_HSC2_FrP01_437T) */

#define Com_PDP2P_HSC2_FrP01_437T ComConf_ComIPdu_PDP2P_HSC2_FrP01_437T


#if (defined Com_PDP2P_HSC2_FrP04_567T) /* To prevent double declaration */
#error Com_PDP2P_HSC2_FrP04_567T already defined
#endif /* #if (defined Com_PDP2P_HSC2_FrP04_567T) */

#define Com_PDP2P_HSC2_FrP04_567T ComConf_ComIPdu_PDP2P_HSC2_FrP04_567T


#if (defined Com_PDP2P_HSC2_FrP03_573T) /* To prevent double declaration */
#error Com_PDP2P_HSC2_FrP03_573T already defined
#endif /* #if (defined Com_PDP2P_HSC2_FrP03_573T) */

#define Com_PDP2P_HSC2_FrP03_573T ComConf_ComIPdu_PDP2P_HSC2_FrP03_573T


#if (defined Com_PDAPA_SecCH_FrP03_651T) /* To prevent double declaration */
#error Com_PDAPA_SecCH_FrP03_651T already defined
#endif /* #if (defined Com_PDAPA_SecCH_FrP03_651T) */

#define Com_PDAPA_SecCH_FrP03_651T ComConf_ComIPdu_PDAPA_SecCH_FrP03_651T


#if (defined Com_PDP2P_IECU_HSC4_FrP01_764T) /* To prevent double declaration */
#error Com_PDP2P_IECU_HSC4_FrP01_764T already defined
#endif /* #if (defined Com_PDP2P_IECU_HSC4_FrP01_764T) */

#define Com_PDP2P_IECU_HSC4_FrP01_764T ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP01_764T


#if (defined Com_PDP2P_HSC4_FrP03_781T) /* To prevent double declaration */
#error Com_PDP2P_HSC4_FrP03_781T already defined
#endif /* #if (defined Com_PDP2P_HSC4_FrP03_781T) */

#define Com_PDP2P_HSC4_FrP03_781T ComConf_ComIPdu_PDP2P_HSC4_FrP03_781T


#if (defined Com_PDP2P_IECU_HSC4_FrP02_912T) /* To prevent double declaration */
#error Com_PDP2P_IECU_HSC4_FrP02_912T already defined
#endif /* #if (defined Com_PDP2P_IECU_HSC4_FrP02_912T) */

#define Com_PDP2P_IECU_HSC4_FrP02_912T ComConf_ComIPdu_PDP2P_IECU_HSC4_FrP02_912T


#if (defined Com_PDP2P_HSC2_FrI02_914T) /* To prevent double declaration */
#error Com_PDP2P_HSC2_FrI02_914T already defined
#endif /* #if (defined Com_PDP2P_HSC2_FrI02_914T) */

#define Com_PDP2P_HSC2_FrI02_914T ComConf_ComIPdu_PDP2P_HSC2_FrI02_914T


#if (defined Com_PDP2P_HSC2_FrP02_966T) /* To prevent double declaration */
#error Com_PDP2P_HSC2_FrP02_966T already defined
#endif /* #if (defined Com_PDP2P_HSC2_FrP02_966T) */

#define Com_PDP2P_HSC2_FrP02_966T ComConf_ComIPdu_PDP2P_HSC2_FrP02_966T


#if (defined Com_PDEM_APAPLDINF_0x531_1329T) /* To prevent double declaration */
#error Com_PDEM_APAPLDINF_0x531_1329T already defined
#endif /* #if (defined Com_PDEM_APAPLDINF_0x531_1329T) */

#define Com_PDEM_APAPLDINF_0x531_1329T ComConf_ComIPdu_PDEM_APAPLDINF_0x531_1329T


#if (defined Com_PDLADS_HSC4_OBJ_0_INF_1330T) /* To prevent double declaration */
#error Com_PDLADS_HSC4_OBJ_0_INF_1330T already defined
#endif /* #if (defined Com_PDLADS_HSC4_OBJ_0_INF_1330T) */

#define Com_PDLADS_HSC4_OBJ_0_INF_1330T ComConf_ComIPdu_PDLADS_HSC4_OBJ_0_INF_1330T


#if (defined Com_PDLADS_HSC4_OBJ_1_INF_1337T) /* To prevent double declaration */
#error Com_PDLADS_HSC4_OBJ_1_INF_1337T already defined
#endif /* #if (defined Com_PDLADS_HSC4_OBJ_1_INF_1337T) */

#define Com_PDLADS_HSC4_OBJ_1_INF_1337T ComConf_ComIPdu_PDLADS_HSC4_OBJ_1_INF_1337T


#if (defined Com_PDLADS_HSC4_OBJ_2_INF_1339T) /* To prevent double declaration */
#error Com_PDLADS_HSC4_OBJ_2_INF_1339T already defined
#endif /* #if (defined Com_PDLADS_HSC4_OBJ_2_INF_1339T) */

#define Com_PDLADS_HSC4_OBJ_2_INF_1339T ComConf_ComIPdu_PDLADS_HSC4_OBJ_2_INF_1339T


#if (defined Com_PDLADS_HSC4_OBJ_3_INF_1340T) /* To prevent double declaration */
#error Com_PDLADS_HSC4_OBJ_3_INF_1340T already defined
#endif /* #if (defined Com_PDLADS_HSC4_OBJ_3_INF_1340T) */

#define Com_PDLADS_HSC4_OBJ_3_INF_1340T ComConf_ComIPdu_PDLADS_HSC4_OBJ_3_INF_1340T


#if (defined Com_PDLADS_HSC4_OBJ_4_INF_1341T) /* To prevent double declaration */
#error Com_PDLADS_HSC4_OBJ_4_INF_1341T already defined
#endif /* #if (defined Com_PDLADS_HSC4_OBJ_4_INF_1341T) */

#define Com_PDLADS_HSC4_OBJ_4_INF_1341T ComConf_ComIPdu_PDLADS_HSC4_OBJ_4_INF_1341T


#if (defined Com_PDLADS_HSC4_OBJ_5_INF_1342T) /* To prevent double declaration */
#error Com_PDLADS_HSC4_OBJ_5_INF_1342T already defined
#endif /* #if (defined Com_PDLADS_HSC4_OBJ_5_INF_1342T) */

#define Com_PDLADS_HSC4_OBJ_5_INF_1342T ComConf_ComIPdu_PDLADS_HSC4_OBJ_5_INF_1342T


#if (defined Com_PDLADS_HSC4_OBJ_6_INF_1343T) /* To prevent double declaration */
#error Com_PDLADS_HSC4_OBJ_6_INF_1343T already defined
#endif /* #if (defined Com_PDLADS_HSC4_OBJ_6_INF_1343T) */

#define Com_PDLADS_HSC4_OBJ_6_INF_1343T ComConf_ComIPdu_PDLADS_HSC4_OBJ_6_INF_1343T


#if (defined Com_PDLADS_HSC4_OBJ_7_INF_1346T) /* To prevent double declaration */
#error Com_PDLADS_HSC4_OBJ_7_INF_1346T already defined
#endif /* #if (defined Com_PDLADS_HSC4_OBJ_7_INF_1346T) */

#define Com_PDLADS_HSC4_OBJ_7_INF_1346T ComConf_ComIPdu_PDLADS_HSC4_OBJ_7_INF_1346T


#if (defined Com_PDEM_APAPLDINF_0x545_1349T) /* To prevent double declaration */
#error Com_PDEM_APAPLDINF_0x545_1349T already defined
#endif /* #if (defined Com_PDEM_APAPLDINF_0x545_1349T) */

#define Com_PDEM_APAPLDINF_0x545_1349T ComConf_ComIPdu_PDEM_APAPLDINF_0x545_1349T


#if (defined Com_PDPdu_CounterOut_T) /* To prevent double declaration */
#error Com_PDPdu_CounterOut_T already defined
#endif /* #if (defined Com_PDPdu_CounterOut_T) */

#define Com_PDPdu_CounterOut_T ComConf_ComIPdu_PDPdu_CounterOut_T


#if (defined Com_PDPdu_DummyIn_T) /* To prevent double declaration */
#error Com_PDPdu_DummyIn_T already defined
#endif /* #if (defined Com_PDPdu_DummyIn_T) */

#define Com_PDPdu_DummyIn_T ComConf_ComIPdu_PDPdu_DummyIn_T


#if (defined Com_PDPdu_UssToolOut_T) /* To prevent double declaration */
#error Com_PDPdu_UssToolOut_T already defined
#endif /* #if (defined Com_PDPdu_UssToolOut_T) */

#define Com_PDPdu_UssToolOut_T ComConf_ComIPdu_PDPdu_UssToolOut_T


#if (defined Com_PDPdu_CfmOut_T) /* To prevent double declaration */
#error Com_PDPdu_CfmOut_T already defined
#endif /* #if (defined Com_PDPdu_CfmOut_T) */

#define Com_PDPdu_CfmOut_T ComConf_ComIPdu_PDPdu_CfmOut_T


#if (defined Com_PDPdu_TestUdpOut_T) /* To prevent double declaration */
#error Com_PDPdu_TestUdpOut_T already defined
#endif /* #if (defined Com_PDPdu_TestUdpOut_T) */

#define Com_PDPdu_TestUdpOut_T ComConf_ComIPdu_PDPdu_TestUdpOut_T


/* External Rx Signal IDs (no group signals) defines */
#if (defined Com_SGDummyOut_R) /* To prevent double declaration */
#error Com_SGDummyOut_R already defined
#endif /* #if (defined Com_SGDummyOut_R) */

#define Com_SGDummyOut_R ComConf_ComSignal_SGDummyOut_R


#if (defined Com_SGCounterIn_R) /* To prevent double declaration */
#error Com_SGCounterIn_R already defined
#endif /* #if (defined Com_SGCounterIn_R) */

#define Com_SGCounterIn_R ComConf_ComSignal_SGCounterIn_R


#if (defined Com_SGUssToolIn_R) /* To prevent double declaration */
#error Com_SGUssToolIn_R already defined
#endif /* #if (defined Com_SGUssToolIn_R) */

#define Com_SGUssToolIn_R ComConf_ComSignal_SGUssToolIn_R


#if (defined Com_SGCfmIn_R) /* To prevent double declaration */
#error Com_SGCfmIn_R already defined
#endif /* #if (defined Com_SGCfmIn_R) */

#define Com_SGCfmIn_R ComConf_ComSignal_SGCfmIn_R


#if (defined Com_SGTestUdpIn_R) /* To prevent double declaration */
#error Com_SGTestUdpIn_R already defined
#endif /* #if (defined Com_SGTestUdpIn_R) */

#define Com_SGTestUdpIn_R ComConf_ComSignal_SGTestUdpIn_R


#if (defined Com_SGSCUDrvrIntrvnAHSC2_157R) /* To prevent double declaration */
#error Com_SGSCUDrvrIntrvnAHSC2_157R already defined
#endif /* #if (defined Com_SGSCUDrvrIntrvnAHSC2_157R) */

#define Com_SGSCUDrvrIntrvnAHSC2_157R ComConf_ComSignal_SGSCUDrvrIntrvnAHSC2_157R


#if (defined Com_SGSCUNRCDAvlblHSC2_157R) /* To prevent double declaration */
#error Com_SGSCUNRCDAvlblHSC2_157R already defined
#endif /* #if (defined Com_SGSCUNRCDAvlblHSC2_157R) */

#define Com_SGSCUNRCDAvlblHSC2_157R ComConf_ComSignal_SGSCUNRCDAvlblHSC2_157R


#if (defined Com_SGSCUShifterLvrPosHSC2_157R) /* To prevent double declaration */
#error Com_SGSCUShifterLvrPosHSC2_157R already defined
#endif /* #if (defined Com_SGSCUShifterLvrPosHSC2_157R) */

#define Com_SGSCUShifterLvrPosHSC2_157R ComConf_ComSignal_SGSCUShifterLvrPosHSC2_157R


#if (defined Com_SGSCUShifterPosInvsnHSC2_157R) /* To prevent double declaration */
#error Com_SGSCUShifterPosInvsnHSC2_157R already defined
#endif /* #if (defined Com_SGSCUShifterPosInvsnHSC2_157R) */

#define Com_SGSCUShifterPosInvsnHSC2_157R ComConf_ComSignal_SGSCUShifterPosInvsnHSC2_157R


#if (defined Com_SGSCUShifterPosRCHSC2_157R) /* To prevent double declaration */
#error Com_SGSCUShifterPosRCHSC2_157R already defined
#endif /* #if (defined Com_SGSCUShifterPosRCHSC2_157R) */

#define Com_SGSCUShifterPosRCHSC2_157R ComConf_ComSignal_SGSCUShifterPosRCHSC2_157R


#if (defined Com_SGLDrvnWhlRotlDistPlsCtrHSC2_193R) /* To prevent double declaration */
#error Com_SGLDrvnWhlRotlDistPlsCtrHSC2_193R already defined
#endif /* #if (defined Com_SGLDrvnWhlRotlDistPlsCtrHSC2_193R) */

#define Com_SGLDrvnWhlRotlDistPlsCtrHSC2_193R ComConf_ComSignal_SGLDrvnWhlRotlDistPlsCtrHSC2_193R


#if (defined Com_SGLDrvnWhlRotlDistTRCHSC2_193R) /* To prevent double declaration */
#error Com_SGLDrvnWhlRotlDistTRCHSC2_193R already defined
#endif /* #if (defined Com_SGLDrvnWhlRotlDistTRCHSC2_193R) */

#define Com_SGLDrvnWhlRotlDistTRCHSC2_193R ComConf_ComSignal_SGLDrvnWhlRotlDistTRCHSC2_193R


#if (defined Com_SGLDrvnWhlRotlDistTmspHSC2_193R) /* To prevent double declaration */
#error Com_SGLDrvnWhlRotlDistTmspHSC2_193R already defined
#endif /* #if (defined Com_SGLDrvnWhlRotlDistTmspHSC2_193R) */

#define Com_SGLDrvnWhlRotlDistTmspHSC2_193R ComConf_ComSignal_SGLDrvnWhlRotlDistTmspHSC2_193R


#if (defined Com_SGLDrvnWhlRotlDistVHSC2_193R) /* To prevent double declaration */
#error Com_SGLDrvnWhlRotlDistVHSC2_193R already defined
#endif /* #if (defined Com_SGLDrvnWhlRotlDistVHSC2_193R) */

#define Com_SGLDrvnWhlRotlDistVHSC2_193R ComConf_ComSignal_SGLDrvnWhlRotlDistVHSC2_193R


#if (defined Com_SGLDrvnWhlRotlRstOcdHSC2_193R) /* To prevent double declaration */
#error Com_SGLDrvnWhlRotlRstOcdHSC2_193R already defined
#endif /* #if (defined Com_SGLDrvnWhlRotlRstOcdHSC2_193R) */

#define Com_SGLDrvnWhlRotlRstOcdHSC2_193R ComConf_ComSignal_SGLDrvnWhlRotlRstOcdHSC2_193R


#if (defined Com_SGLDrvnWhlRotlSeqNumHSC2_193R) /* To prevent double declaration */
#error Com_SGLDrvnWhlRotlSeqNumHSC2_193R already defined
#endif /* #if (defined Com_SGLDrvnWhlRotlSeqNumHSC2_193R) */

#define Com_SGLDrvnWhlRotlSeqNumHSC2_193R ComConf_ComSignal_SGLDrvnWhlRotlSeqNumHSC2_193R


#if (defined Com_SGRDrvnWhlRotlDistPlsCtrHSC2_193R) /* To prevent double declaration */
#error Com_SGRDrvnWhlRotlDistPlsCtrHSC2_193R already defined
#endif /* #if (defined Com_SGRDrvnWhlRotlDistPlsCtrHSC2_193R) */

#define Com_SGRDrvnWhlRotlDistPlsCtrHSC2_193R ComConf_ComSignal_SGRDrvnWhlRotlDistPlsCtrHSC2_193R


#if (defined Com_SGRDrvnWhlRotlDistTRCHSC2_193R) /* To prevent double declaration */
#error Com_SGRDrvnWhlRotlDistTRCHSC2_193R already defined
#endif /* #if (defined Com_SGRDrvnWhlRotlDistTRCHSC2_193R) */

#define Com_SGRDrvnWhlRotlDistTRCHSC2_193R ComConf_ComSignal_SGRDrvnWhlRotlDistTRCHSC2_193R


#if (defined Com_SGRDrvnWhlRotlDistTmspHSC2_193R) /* To prevent double declaration */
#error Com_SGRDrvnWhlRotlDistTmspHSC2_193R already defined
#endif /* #if (defined Com_SGRDrvnWhlRotlDistTmspHSC2_193R) */

#define Com_SGRDrvnWhlRotlDistTmspHSC2_193R ComConf_ComSignal_SGRDrvnWhlRotlDistTmspHSC2_193R


#if (defined Com_SGRDrvnWhlRotlDistVHSC2_193R) /* To prevent double declaration */
#error Com_SGRDrvnWhlRotlDistVHSC2_193R already defined
#endif /* #if (defined Com_SGRDrvnWhlRotlDistVHSC2_193R) */

#define Com_SGRDrvnWhlRotlDistVHSC2_193R ComConf_ComSignal_SGRDrvnWhlRotlDistVHSC2_193R


#if (defined Com_SGRDrvnWhlRotlRstOcdHSC2_193R) /* To prevent double declaration */
#error Com_SGRDrvnWhlRotlRstOcdHSC2_193R already defined
#endif /* #if (defined Com_SGRDrvnWhlRotlRstOcdHSC2_193R) */

#define Com_SGRDrvnWhlRotlRstOcdHSC2_193R ComConf_ComSignal_SGRDrvnWhlRotlRstOcdHSC2_193R


#if (defined Com_SGRDrvnWhlRotlSeqNumHSC2_193R) /* To prevent double declaration */
#error Com_SGRDrvnWhlRotlSeqNumHSC2_193R already defined
#endif /* #if (defined Com_SGRDrvnWhlRotlSeqNumHSC2_193R) */

#define Com_SGRDrvnWhlRotlSeqNumHSC2_193R ComConf_ComSignal_SGRDrvnWhlRotlSeqNumHSC2_193R


#if (defined Com_SGLNonDrvnWhlRotlDistPCHSC2_197R) /* To prevent double declaration */
#error Com_SGLNonDrvnWhlRotlDistPCHSC2_197R already defined
#endif /* #if (defined Com_SGLNonDrvnWhlRotlDistPCHSC2_197R) */

#define Com_SGLNonDrvnWhlRotlDistPCHSC2_197R ComConf_ComSignal_SGLNonDrvnWhlRotlDistPCHSC2_197R


#if (defined Com_SGLNonDrvnWhlRotlDistTHSC2_197R) /* To prevent double declaration */
#error Com_SGLNonDrvnWhlRotlDistTHSC2_197R already defined
#endif /* #if (defined Com_SGLNonDrvnWhlRotlDistTHSC2_197R) */

#define Com_SGLNonDrvnWhlRotlDistTHSC2_197R ComConf_ComSignal_SGLNonDrvnWhlRotlDistTHSC2_197R


#if (defined Com_SGLNonDrvnWhlRotlDistTRCHSC2_197R) /* To prevent double declaration */
#error Com_SGLNonDrvnWhlRotlDistTRCHSC2_197R already defined
#endif /* #if (defined Com_SGLNonDrvnWhlRotlDistTRCHSC2_197R) */

#define Com_SGLNonDrvnWhlRotlDistTRCHSC2_197R ComConf_ComSignal_SGLNonDrvnWhlRotlDistTRCHSC2_197R


#if (defined Com_SGLNonDrvnWhlRotlDistVHSC2_197R) /* To prevent double declaration */
#error Com_SGLNonDrvnWhlRotlDistVHSC2_197R already defined
#endif /* #if (defined Com_SGLNonDrvnWhlRotlDistVHSC2_197R) */

#define Com_SGLNonDrvnWhlRotlDistVHSC2_197R ComConf_ComSignal_SGLNonDrvnWhlRotlDistVHSC2_197R


#if (defined Com_SGLNonDrvnWhlRotlRstOcdHSC2_197R) /* To prevent double declaration */
#error Com_SGLNonDrvnWhlRotlRstOcdHSC2_197R already defined
#endif /* #if (defined Com_SGLNonDrvnWhlRotlRstOcdHSC2_197R) */

#define Com_SGLNonDrvnWhlRotlRstOcdHSC2_197R ComConf_ComSignal_SGLNonDrvnWhlRotlRstOcdHSC2_197R


#if (defined Com_SGLNonDrvnWhlRotlSeqNumHSC2_197R) /* To prevent double declaration */
#error Com_SGLNonDrvnWhlRotlSeqNumHSC2_197R already defined
#endif /* #if (defined Com_SGLNonDrvnWhlRotlSeqNumHSC2_197R) */

#define Com_SGLNonDrvnWhlRotlSeqNumHSC2_197R ComConf_ComSignal_SGLNonDrvnWhlRotlSeqNumHSC2_197R


#if (defined Com_SGRNonDrvnWhlRotlDistPCHSC2_197R) /* To prevent double declaration */
#error Com_SGRNonDrvnWhlRotlDistPCHSC2_197R already defined
#endif /* #if (defined Com_SGRNonDrvnWhlRotlDistPCHSC2_197R) */

#define Com_SGRNonDrvnWhlRotlDistPCHSC2_197R ComConf_ComSignal_SGRNonDrvnWhlRotlDistPCHSC2_197R


#if (defined Com_SGRNonDrvnWhlRotlDistTHSC2_197R) /* To prevent double declaration */
#error Com_SGRNonDrvnWhlRotlDistTHSC2_197R already defined
#endif /* #if (defined Com_SGRNonDrvnWhlRotlDistTHSC2_197R) */

#define Com_SGRNonDrvnWhlRotlDistTHSC2_197R ComConf_ComSignal_SGRNonDrvnWhlRotlDistTHSC2_197R


#if (defined Com_SGRNonDrvnWhlRotlDistTRCHSC2_197R) /* To prevent double declaration */
#error Com_SGRNonDrvnWhlRotlDistTRCHSC2_197R already defined
#endif /* #if (defined Com_SGRNonDrvnWhlRotlDistTRCHSC2_197R) */

#define Com_SGRNonDrvnWhlRotlDistTRCHSC2_197R ComConf_ComSignal_SGRNonDrvnWhlRotlDistTRCHSC2_197R


#if (defined Com_SGRNonDrvnWhlRotlDistVHSC2_197R) /* To prevent double declaration */
#error Com_SGRNonDrvnWhlRotlDistVHSC2_197R already defined
#endif /* #if (defined Com_SGRNonDrvnWhlRotlDistVHSC2_197R) */

#define Com_SGRNonDrvnWhlRotlDistVHSC2_197R ComConf_ComSignal_SGRNonDrvnWhlRotlDistVHSC2_197R


#if (defined Com_SGRNonDrvnWhlRotlRstOcdHSC2_197R) /* To prevent double declaration */
#error Com_SGRNonDrvnWhlRotlRstOcdHSC2_197R already defined
#endif /* #if (defined Com_SGRNonDrvnWhlRotlRstOcdHSC2_197R) */

#define Com_SGRNonDrvnWhlRotlRstOcdHSC2_197R ComConf_ComSignal_SGRNonDrvnWhlRotlRstOcdHSC2_197R


#if (defined Com_SGRNonDrvnWhlRotlSeqNumHSC2_197R) /* To prevent double declaration */
#error Com_SGRNonDrvnWhlRotlSeqNumHSC2_197R already defined
#endif /* #if (defined Com_SGRNonDrvnWhlRotlSeqNumHSC2_197R) */

#define Com_SGRNonDrvnWhlRotlSeqNumHSC2_197R ComConf_ComSignal_SGRNonDrvnWhlRotlSeqNumHSC2_197R


#if (defined Com_SGVSELatAccHSC2_389R) /* To prevent double declaration */
#error Com_SGVSELatAccHSC2_389R already defined
#endif /* #if (defined Com_SGVSELatAccHSC2_389R) */

#define Com_SGVSELatAccHSC2_389R ComConf_ComSignal_SGVSELatAccHSC2_389R


#if (defined Com_SGVSELatAccVHSC2_389R) /* To prevent double declaration */
#error Com_SGVSELatAccVHSC2_389R already defined
#endif /* #if (defined Com_SGVSELatAccVHSC2_389R) */

#define Com_SGVSELatAccVHSC2_389R ComConf_ComSignal_SGVSELatAccVHSC2_389R


#if (defined Com_SGVSELongtAccHSC2_389R) /* To prevent double declaration */
#error Com_SGVSELongtAccHSC2_389R already defined
#endif /* #if (defined Com_SGVSELongtAccHSC2_389R) */

#define Com_SGVSELongtAccHSC2_389R ComConf_ComSignal_SGVSELongtAccHSC2_389R


#if (defined Com_SGVSELongtAccVHSC2_389R) /* To prevent double declaration */
#error Com_SGVSELongtAccVHSC2_389R already defined
#endif /* #if (defined Com_SGVSELongtAccVHSC2_389R) */

#define Com_SGVSELongtAccVHSC2_389R ComConf_ComSignal_SGVSELongtAccVHSC2_389R


#if (defined Com_SGEPSAPAAlvRCHSC2_433R) /* To prevent double declaration */
#error Com_SGEPSAPAAlvRCHSC2_433R already defined
#endif /* #if (defined Com_SGEPSAPAAlvRCHSC2_433R) */

#define Com_SGEPSAPAAlvRCHSC2_433R ComConf_ComSignal_SGEPSAPAAlvRCHSC2_433R


#if (defined Com_SGEPSAPAChksmHSC2_433R) /* To prevent double declaration */
#error Com_SGEPSAPAChksmHSC2_433R already defined
#endif /* #if (defined Com_SGEPSAPAChksmHSC2_433R) */

#define Com_SGEPSAPAChksmHSC2_433R ComConf_ComSignal_SGEPSAPAChksmHSC2_433R


#if (defined Com_SGEPSAPAInhHSC2_433R) /* To prevent double declaration */
#error Com_SGEPSAPAInhHSC2_433R already defined
#endif /* #if (defined Com_SGEPSAPAInhHSC2_433R) */

#define Com_SGEPSAPAInhHSC2_433R ComConf_ComSignal_SGEPSAPAInhHSC2_433R


#if (defined Com_SGEPSAPAStsHSC2_433R) /* To prevent double declaration */
#error Com_SGEPSAPAStsHSC2_433R already defined
#endif /* #if (defined Com_SGEPSAPAStsHSC2_433R) */

#define Com_SGEPSAPAStsHSC2_433R ComConf_ComSignal_SGEPSAPAStsHSC2_433R


#if (defined Com_SGBrkPdlAppdHSC2_438R) /* To prevent double declaration */
#error Com_SGBrkPdlAppdHSC2_438R already defined
#endif /* #if (defined Com_SGBrkPdlAppdHSC2_438R) */

#define Com_SGBrkPdlAppdHSC2_438R ComConf_ComSignal_SGBrkPdlAppdHSC2_438R


#if (defined Com_SGHydBstrCmpstnReqHSC2_438R) /* To prevent double declaration */
#error Com_SGHydBstrCmpstnReqHSC2_438R already defined
#endif /* #if (defined Com_SGHydBstrCmpstnReqHSC2_438R) */

#define Com_SGHydBstrCmpstnReqHSC2_438R ComConf_ComSignal_SGHydBstrCmpstnReqHSC2_438R


#if (defined Com_SGLNonDrvnWhlRotlDircnHSC2_455R) /* To prevent double declaration */
#error Com_SGLNonDrvnWhlRotlDircnHSC2_455R already defined
#endif /* #if (defined Com_SGLNonDrvnWhlRotlDircnHSC2_455R) */

#define Com_SGLNonDrvnWhlRotlDircnHSC2_455R ComConf_ComSignal_SGLNonDrvnWhlRotlDircnHSC2_455R


#if (defined Com_SGRNonDrvnWhlRotlDircnHSC2_455R) /* To prevent double declaration */
#error Com_SGRNonDrvnWhlRotlDircnHSC2_455R already defined
#endif /* #if (defined Com_SGRNonDrvnWhlRotlDircnHSC2_455R) */

#define Com_SGRNonDrvnWhlRotlDircnHSC2_455R ComConf_ComSignal_SGRNonDrvnWhlRotlDircnHSC2_455R


#if (defined Com_SGSCSAPAAcclAHSC2_455R) /* To prevent double declaration */
#error Com_SGSCSAPAAcclAHSC2_455R already defined
#endif /* #if (defined Com_SGSCSAPAAcclAHSC2_455R) */

#define Com_SGSCSAPAAcclAHSC2_455R ComConf_ComSignal_SGSCSAPAAcclAHSC2_455R


#if (defined Com_SGSCSAPAAlvRCHSC2_455R) /* To prevent double declaration */
#error Com_SGSCSAPAAlvRCHSC2_455R already defined
#endif /* #if (defined Com_SGSCSAPAAlvRCHSC2_455R) */

#define Com_SGSCSAPAAlvRCHSC2_455R ComConf_ComSignal_SGSCSAPAAlvRCHSC2_455R


#if (defined Com_SGSCSAPAAvlblHSC2_455R) /* To prevent double declaration */
#error Com_SGSCSAPAAvlblHSC2_455R already defined
#endif /* #if (defined Com_SGSCSAPAAvlblHSC2_455R) */

#define Com_SGSCSAPAAvlblHSC2_455R ComConf_ComSignal_SGSCSAPAAvlblHSC2_455R


#if (defined Com_SGSCSNRCDAvlblHSC2_455R) /* To prevent double declaration */
#error Com_SGSCSNRCDAvlblHSC2_455R already defined
#endif /* #if (defined Com_SGSCSNRCDAvlblHSC2_455R) */

#define Com_SGSCSNRCDAvlblHSC2_455R ComConf_ComSignal_SGSCSNRCDAvlblHSC2_455R


#if (defined Com_SGStrgWhlAngHSC2_485R) /* To prevent double declaration */
#error Com_SGStrgWhlAngHSC2_485R already defined
#endif /* #if (defined Com_SGStrgWhlAngHSC2_485R) */

#define Com_SGStrgWhlAngHSC2_485R ComConf_ComSignal_SGStrgWhlAngHSC2_485R


#if (defined Com_SGStrgWhlAngVHSC2_485R) /* To prevent double declaration */
#error Com_SGStrgWhlAngVHSC2_485R already defined
#endif /* #if (defined Com_SGStrgWhlAngVHSC2_485R) */

#define Com_SGStrgWhlAngVHSC2_485R ComConf_ComSignal_SGStrgWhlAngVHSC2_485R


#if (defined Com_SGABSAHSC2_489R) /* To prevent double declaration */
#error Com_SGABSAHSC2_489R already defined
#endif /* #if (defined Com_SGABSAHSC2_489R) */

#define Com_SGABSAHSC2_489R ComConf_ComSignal_SGABSAHSC2_489R


#if (defined Com_SGTCSAHSC2_489R) /* To prevent double declaration */
#error Com_SGTCSAHSC2_489R already defined
#endif /* #if (defined Com_SGTCSAHSC2_489R) */

#define Com_SGTCSAHSC2_489R ComConf_ComSignal_SGTCSAHSC2_489R


#if (defined Com_SGVSESysAHSC2_489R) /* To prevent double declaration */
#error Com_SGVSESysAHSC2_489R already defined
#endif /* #if (defined Com_SGVSESysAHSC2_489R) */

#define Com_SGVSESysAHSC2_489R ComConf_ComSignal_SGVSESysAHSC2_489R


#if (defined Com_SGVehDynYawRateHSC2_489R) /* To prevent double declaration */
#error Com_SGVehDynYawRateHSC2_489R already defined
#endif /* #if (defined Com_SGVehDynYawRateHSC2_489R) */

#define Com_SGVehDynYawRateHSC2_489R ComConf_ComSignal_SGVehDynYawRateHSC2_489R


#if (defined Com_SGVehDynYawRateVHSC2_489R) /* To prevent double declaration */
#error Com_SGVehDynYawRateVHSC2_489R already defined
#endif /* #if (defined Com_SGVehDynYawRateVHSC2_489R) */

#define Com_SGVehDynYawRateVHSC2_489R ComConf_ComSignal_SGVehDynYawRateVHSC2_489R


#if (defined Com_SGEPBAppcnStsHSC2_554R) /* To prevent double declaration */
#error Com_SGEPBAppcnStsHSC2_554R already defined
#endif /* #if (defined Com_SGEPBAppcnStsHSC2_554R) */

#define Com_SGEPBAppcnStsHSC2_554R ComConf_ComSignal_SGEPBAppcnStsHSC2_554R


#if (defined Com_SGEPBAppcnStsPVHSC2_554R) /* To prevent double declaration */
#error Com_SGEPBAppcnStsPVHSC2_554R already defined
#endif /* #if (defined Com_SGEPBAppcnStsPVHSC2_554R) */

#define Com_SGEPBAppcnStsPVHSC2_554R ComConf_ComSignal_SGEPBAppcnStsPVHSC2_554R


#if (defined Com_SGEPBAvlblyStsHSC2_554R) /* To prevent double declaration */
#error Com_SGEPBAvlblyStsHSC2_554R already defined
#endif /* #if (defined Com_SGEPBAvlblyStsHSC2_554R) */

#define Com_SGEPBAvlblyStsHSC2_554R ComConf_ComSignal_SGEPBAvlblyStsHSC2_554R


#if (defined Com_SGEPBAvlblyStsPVHSC2_554R) /* To prevent double declaration */
#error Com_SGEPBAvlblyStsPVHSC2_554R already defined
#endif /* #if (defined Com_SGEPBAvlblyStsPVHSC2_554R) */

#define Com_SGEPBAvlblyStsPVHSC2_554R ComConf_ComSignal_SGEPBAvlblyStsPVHSC2_554R


#if (defined Com_SGWhlGndVelLDrvnHSC2_840R) /* To prevent double declaration */
#error Com_SGWhlGndVelLDrvnHSC2_840R already defined
#endif /* #if (defined Com_SGWhlGndVelLDrvnHSC2_840R) */

#define Com_SGWhlGndVelLDrvnHSC2_840R ComConf_ComSignal_SGWhlGndVelLDrvnHSC2_840R


#if (defined Com_SGWhlGndVelLDrvnVHSC2_840R) /* To prevent double declaration */
#error Com_SGWhlGndVelLDrvnVHSC2_840R already defined
#endif /* #if (defined Com_SGWhlGndVelLDrvnVHSC2_840R) */

#define Com_SGWhlGndVelLDrvnVHSC2_840R ComConf_ComSignal_SGWhlGndVelLDrvnVHSC2_840R


#if (defined Com_SGWhlGndVelRDrvnHSC2_840R) /* To prevent double declaration */
#error Com_SGWhlGndVelRDrvnHSC2_840R already defined
#endif /* #if (defined Com_SGWhlGndVelRDrvnHSC2_840R) */

#define Com_SGWhlGndVelRDrvnHSC2_840R ComConf_ComSignal_SGWhlGndVelRDrvnHSC2_840R


#if (defined Com_SGWhlGndVelRDrvnVHSC2_840R) /* To prevent double declaration */
#error Com_SGWhlGndVelRDrvnVHSC2_840R already defined
#endif /* #if (defined Com_SGWhlGndVelRDrvnVHSC2_840R) */

#define Com_SGWhlGndVelRDrvnVHSC2_840R ComConf_ComSignal_SGWhlGndVelRDrvnVHSC2_840R


#if (defined Com_SGWhlGndVelLNonDrvnHSC2_842R) /* To prevent double declaration */
#error Com_SGWhlGndVelLNonDrvnHSC2_842R already defined
#endif /* #if (defined Com_SGWhlGndVelLNonDrvnHSC2_842R) */

#define Com_SGWhlGndVelLNonDrvnHSC2_842R ComConf_ComSignal_SGWhlGndVelLNonDrvnHSC2_842R


#if (defined Com_SGWhlGndVelLNonDrvnVHSC2_842R) /* To prevent double declaration */
#error Com_SGWhlGndVelLNonDrvnVHSC2_842R already defined
#endif /* #if (defined Com_SGWhlGndVelLNonDrvnVHSC2_842R) */

#define Com_SGWhlGndVelLNonDrvnVHSC2_842R ComConf_ComSignal_SGWhlGndVelLNonDrvnVHSC2_842R


#if (defined Com_SGWhlGndVelRNonDrvnHSC2_842R) /* To prevent double declaration */
#error Com_SGWhlGndVelRNonDrvnHSC2_842R already defined
#endif /* #if (defined Com_SGWhlGndVelRNonDrvnHSC2_842R) */

#define Com_SGWhlGndVelRNonDrvnHSC2_842R ComConf_ComSignal_SGWhlGndVelRNonDrvnHSC2_842R


#if (defined Com_SGWhlGndVelRNonDrvnVHSC2_842R) /* To prevent double declaration */
#error Com_SGWhlGndVelRNonDrvnVHSC2_842R already defined
#endif /* #if (defined Com_SGWhlGndVelRNonDrvnVHSC2_842R) */

#define Com_SGWhlGndVelRNonDrvnVHSC2_842R ComConf_ComSignal_SGWhlGndVelRNonDrvnVHSC2_842R


#if (defined Com_SGDistRCAvgDrvnHSC2_851R) /* To prevent double declaration */
#error Com_SGDistRCAvgDrvnHSC2_851R already defined
#endif /* #if (defined Com_SGDistRCAvgDrvnHSC2_851R) */

#define Com_SGDistRCAvgDrvnHSC2_851R ComConf_ComSignal_SGDistRCAvgDrvnHSC2_851R


#if (defined Com_SGDistRCAvgDrvnRstOcdHSC2_851R) /* To prevent double declaration */
#error Com_SGDistRCAvgDrvnRstOcdHSC2_851R already defined
#endif /* #if (defined Com_SGDistRCAvgDrvnRstOcdHSC2_851R) */

#define Com_SGDistRCAvgDrvnRstOcdHSC2_851R ComConf_ComSignal_SGDistRCAvgDrvnRstOcdHSC2_851R


#if (defined Com_SGDistRCAvgDrvnSrcHSC2_851R) /* To prevent double declaration */
#error Com_SGDistRCAvgDrvnSrcHSC2_851R already defined
#endif /* #if (defined Com_SGDistRCAvgDrvnSrcHSC2_851R) */

#define Com_SGDistRCAvgDrvnSrcHSC2_851R ComConf_ComSignal_SGDistRCAvgDrvnSrcHSC2_851R


#if (defined Com_SGDistRCAvgDrvnVHSC2_851R) /* To prevent double declaration */
#error Com_SGDistRCAvgDrvnVHSC2_851R already defined
#endif /* #if (defined Com_SGDistRCAvgDrvnVHSC2_851R) */

#define Com_SGDistRCAvgDrvnVHSC2_851R ComConf_ComSignal_SGDistRCAvgDrvnVHSC2_851R


#if (defined Com_SGVehSpdAvgDrvnHSC2_851R) /* To prevent double declaration */
#error Com_SGVehSpdAvgDrvnHSC2_851R already defined
#endif /* #if (defined Com_SGVehSpdAvgDrvnHSC2_851R) */

#define Com_SGVehSpdAvgDrvnHSC2_851R ComConf_ComSignal_SGVehSpdAvgDrvnHSC2_851R


#if (defined Com_SGVehSpdAvgDrvnVHSC2_851R) /* To prevent double declaration */
#error Com_SGVehSpdAvgDrvnVHSC2_851R already defined
#endif /* #if (defined Com_SGVehSpdAvgDrvnVHSC2_851R) */

#define Com_SGVehSpdAvgDrvnVHSC2_851R ComConf_ComSignal_SGVehSpdAvgDrvnVHSC2_851R


#if (defined Com_SGVehSpdAvgNonDrvnHSC2_851R) /* To prevent double declaration */
#error Com_SGVehSpdAvgNonDrvnHSC2_851R already defined
#endif /* #if (defined Com_SGVehSpdAvgNonDrvnHSC2_851R) */

#define Com_SGVehSpdAvgNonDrvnHSC2_851R ComConf_ComSignal_SGVehSpdAvgNonDrvnHSC2_851R


#if (defined Com_SGVehSpdAvgNonDrvnVHSC2_851R) /* To prevent double declaration */
#error Com_SGVehSpdAvgNonDrvnVHSC2_851R already defined
#endif /* #if (defined Com_SGVehSpdAvgNonDrvnVHSC2_851R) */

#define Com_SGVehSpdAvgNonDrvnVHSC2_851R ComConf_ComSignal_SGVehSpdAvgNonDrvnVHSC2_851R


#if (defined Com_SGOtsdAirTemCrValMsk_h2HSC2_1009R) /* To prevent double declaration */
#error Com_SGOtsdAirTemCrValMsk_h2HSC2_1009R already defined
#endif /* #if (defined Com_SGOtsdAirTemCrValMsk_h2HSC2_1009R) */

#define Com_SGOtsdAirTemCrValMsk_h2HSC2_1009R ComConf_ComSignal_SGOtsdAirTemCrValMsk_h2HSC2_1009R


#if (defined Com_SGOtsdAirTemCrValV_h2HSC2_1009R) /* To prevent double declaration */
#error Com_SGOtsdAirTemCrValV_h2HSC2_1009R already defined
#endif /* #if (defined Com_SGOtsdAirTemCrValV_h2HSC2_1009R) */

#define Com_SGOtsdAirTemCrValV_h2HSC2_1009R ComConf_ComSignal_SGOtsdAirTemCrValV_h2HSC2_1009R


#if (defined Com_SGOtsdAirTemCrVal_h2HSC2_1009R) /* To prevent double declaration */
#error Com_SGOtsdAirTemCrVal_h2HSC2_1009R already defined
#endif /* #if (defined Com_SGOtsdAirTemCrVal_h2HSC2_1009R) */

#define Com_SGOtsdAirTemCrVal_h2HSC2_1009R ComConf_ComSignal_SGOtsdAirTemCrVal_h2HSC2_1009R


#if (defined Com_SGCalendarDayHSC2_1345R) /* To prevent double declaration */
#error Com_SGCalendarDayHSC2_1345R already defined
#endif /* #if (defined Com_SGCalendarDayHSC2_1345R) */

#define Com_SGCalendarDayHSC2_1345R ComConf_ComSignal_SGCalendarDayHSC2_1345R


#if (defined Com_SGCalendarMonthHSC2_1345R) /* To prevent double declaration */
#error Com_SGCalendarMonthHSC2_1345R already defined
#endif /* #if (defined Com_SGCalendarMonthHSC2_1345R) */

#define Com_SGCalendarMonthHSC2_1345R ComConf_ComSignal_SGCalendarMonthHSC2_1345R


#if (defined Com_SGCalendarYearHSC2_1345R) /* To prevent double declaration */
#error Com_SGCalendarYearHSC2_1345R already defined
#endif /* #if (defined Com_SGCalendarYearHSC2_1345R) */

#define Com_SGCalendarYearHSC2_1345R ComConf_ComSignal_SGCalendarYearHSC2_1345R


#if (defined Com_SGHourOfDayHSC2_1345R) /* To prevent double declaration */
#error Com_SGHourOfDayHSC2_1345R already defined
#endif /* #if (defined Com_SGHourOfDayHSC2_1345R) */

#define Com_SGHourOfDayHSC2_1345R ComConf_ComSignal_SGHourOfDayHSC2_1345R


#if (defined Com_SGMinuteOfHourHSC2_1345R) /* To prevent double declaration */
#error Com_SGMinuteOfHourHSC2_1345R already defined
#endif /* #if (defined Com_SGMinuteOfHourHSC2_1345R) */

#define Com_SGMinuteOfHourHSC2_1345R ComConf_ComSignal_SGMinuteOfHourHSC2_1345R


#if (defined Com_SGSecsOfMinuteHSC2_1345R) /* To prevent double declaration */
#error Com_SGSecsOfMinuteHSC2_1345R already defined
#endif /* #if (defined Com_SGSecsOfMinuteHSC2_1345R) */

#define Com_SGSecsOfMinuteHSC2_1345R ComConf_ComSignal_SGSecsOfMinuteHSC2_1345R


#if (defined Com_SGTimeDspFmtHSC2_1345R) /* To prevent double declaration */
#error Com_SGTimeDspFmtHSC2_1345R already defined
#endif /* #if (defined Com_SGTimeDspFmtHSC2_1345R) */

#define Com_SGTimeDspFmtHSC2_1345R ComConf_ComSignal_SGTimeDspFmtHSC2_1345R


#if (defined Com_SGSelectedBerthIdTmp_1321R) /* To prevent double declaration */
#error Com_SGSelectedBerthIdTmp_1321R already defined
#endif /* #if (defined Com_SGSelectedBerthIdTmp_1321R) */

#define Com_SGSelectedBerthIdTmp_1321R ComConf_ComSignal_SGSelectedBerthIdTmp_1321R


/* External Tx Signal IDs (no group signals) defines */
#if (defined Com_SGCounterOut_T) /* To prevent double declaration */
#error Com_SGCounterOut_T already defined
#endif /* #if (defined Com_SGCounterOut_T) */

#define Com_SGCounterOut_T ComConf_ComSignal_SGCounterOut_T


#if (defined Com_SGDummyIn_T) /* To prevent double declaration */
#error Com_SGDummyIn_T already defined
#endif /* #if (defined Com_SGDummyIn_T) */

#define Com_SGDummyIn_T ComConf_ComSignal_SGDummyIn_T


#if (defined Com_SGUssToolOut_T) /* To prevent double declaration */
#error Com_SGUssToolOut_T already defined
#endif /* #if (defined Com_SGUssToolOut_T) */

#define Com_SGUssToolOut_T ComConf_ComSignal_SGUssToolOut_T


#if (defined Com_SGCfmOut_T) /* To prevent double declaration */
#error Com_SGCfmOut_T already defined
#endif /* #if (defined Com_SGCfmOut_T) */

#define Com_SGCfmOut_T ComConf_ComSignal_SGCfmOut_T


#if (defined Com_SGTestUdpOut_T) /* To prevent double declaration */
#error Com_SGTestUdpOut_T already defined
#endif /* #if (defined Com_SGTestUdpOut_T) */

#define Com_SGTestUdpOut_T ComConf_ComSignal_SGTestUdpOut_T


#if (defined Com_SGAPAAlvRCHSC2_424T) /* To prevent double declaration */
#error Com_SGAPAAlvRCHSC2_424T already defined
#endif /* #if (defined Com_SGAPAAlvRCHSC2_424T) */

#define Com_SGAPAAlvRCHSC2_424T ComConf_ComSignal_SGAPAAlvRCHSC2_424T


#if (defined Com_SGAPAChksmHSC2_424T) /* To prevent double declaration */
#error Com_SGAPAChksmHSC2_424T already defined
#endif /* #if (defined Com_SGAPAChksmHSC2_424T) */

#define Com_SGAPAChksmHSC2_424T ComConf_ComSignal_SGAPAChksmHSC2_424T


#if (defined Com_SGAPACmdEPSStsHSC2_424T) /* To prevent double declaration */
#error Com_SGAPACmdEPSStsHSC2_424T already defined
#endif /* #if (defined Com_SGAPACmdEPSStsHSC2_424T) */

#define Com_SGAPACmdEPSStsHSC2_424T ComConf_ComSignal_SGAPACmdEPSStsHSC2_424T


#if (defined Com_SGAPAFHSC2_424T) /* To prevent double declaration */
#error Com_SGAPAFHSC2_424T already defined
#endif /* #if (defined Com_SGAPAFHSC2_424T) */

#define Com_SGAPAFHSC2_424T ComConf_ComSignal_SGAPAFHSC2_424T


#if (defined Com_SGAPAToqReqStsHSC2_424T) /* To prevent double declaration */
#error Com_SGAPAToqReqStsHSC2_424T already defined
#endif /* #if (defined Com_SGAPAToqReqStsHSC2_424T) */

#define Com_SGAPAToqReqStsHSC2_424T ComConf_ComSignal_SGAPAToqReqStsHSC2_424T


#if (defined Com_SGAPAToqReqValHSC2_424T) /* To prevent double declaration */
#error Com_SGAPAToqReqValHSC2_424T already defined
#endif /* #if (defined Com_SGAPAToqReqValHSC2_424T) */

#define Com_SGAPAToqReqValHSC2_424T ComConf_ComSignal_SGAPAToqReqValHSC2_424T


#if (defined Com_SGAPATrgtEPSStrgWhlAngHSC2_424T) /* To prevent double declaration */
#error Com_SGAPATrgtEPSStrgWhlAngHSC2_424T already defined
#endif /* #if (defined Com_SGAPATrgtEPSStrgWhlAngHSC2_424T) */

#define Com_SGAPATrgtEPSStrgWhlAngHSC2_424T ComConf_ComSignal_SGAPATrgtEPSStrgWhlAngHSC2_424T


#if (defined Com_SGAPACrpSpdReqStsHSC2_437T) /* To prevent double declaration */
#error Com_SGAPACrpSpdReqStsHSC2_437T already defined
#endif /* #if (defined Com_SGAPACrpSpdReqStsHSC2_437T) */

#define Com_SGAPACrpSpdReqStsHSC2_437T ComConf_ComSignal_SGAPACrpSpdReqStsHSC2_437T


#if (defined Com_SGAPACrpSpdReqValHSC2_437T) /* To prevent double declaration */
#error Com_SGAPACrpSpdReqValHSC2_437T already defined
#endif /* #if (defined Com_SGAPACrpSpdReqValHSC2_437T) */

#define Com_SGAPACrpSpdReqValHSC2_437T ComConf_ComSignal_SGAPACrpSpdReqValHSC2_437T


#if (defined Com_SGAPAEPBOPReqHSC2_437T) /* To prevent double declaration */
#error Com_SGAPAEPBOPReqHSC2_437T already defined
#endif /* #if (defined Com_SGAPAEPBOPReqHSC2_437T) */

#define Com_SGAPAEPBOPReqHSC2_437T ComConf_ComSignal_SGAPAEPBOPReqHSC2_437T


#if (defined Com_SGAPAEPBOpReqValPVHSC2_437T) /* To prevent double declaration */
#error Com_SGAPAEPBOpReqValPVHSC2_437T already defined
#endif /* #if (defined Com_SGAPAEPBOpReqValPVHSC2_437T) */

#define Com_SGAPAEPBOpReqValPVHSC2_437T ComConf_ComSignal_SGAPAEPBOpReqValPVHSC2_437T


#if (defined Com_SGAPAEPBReqAlvRCHSC2_437T) /* To prevent double declaration */
#error Com_SGAPAEPBReqAlvRCHSC2_437T already defined
#endif /* #if (defined Com_SGAPAEPBReqAlvRCHSC2_437T) */

#define Com_SGAPAEPBReqAlvRCHSC2_437T ComConf_ComSignal_SGAPAEPBReqAlvRCHSC2_437T


#if (defined Com_SGAPAInfoDispReqHSC2_437T) /* To prevent double declaration */
#error Com_SGAPAInfoDispReqHSC2_437T already defined
#endif /* #if (defined Com_SGAPAInfoDispReqHSC2_437T) */

#define Com_SGAPAInfoDispReqHSC2_437T ComConf_ComSignal_SGAPAInfoDispReqHSC2_437T


#if (defined Com_SGAPAMdHSC2_437T) /* To prevent double declaration */
#error Com_SGAPAMdHSC2_437T already defined
#endif /* #if (defined Com_SGAPAMdHSC2_437T) */

#define Com_SGAPAMdHSC2_437T ComConf_ComSignal_SGAPAMdHSC2_437T


#if (defined Com_SGAPANRCDAvlblHSC2_437T) /* To prevent double declaration */
#error Com_SGAPANRCDAvlblHSC2_437T already defined
#endif /* #if (defined Com_SGAPANRCDAvlblHSC2_437T) */

#define Com_SGAPANRCDAvlblHSC2_437T ComConf_ComSignal_SGAPANRCDAvlblHSC2_437T


#if (defined Com_SGAPAReqHSC2_437T) /* To prevent double declaration */
#error Com_SGAPAReqHSC2_437T already defined
#endif /* #if (defined Com_SGAPAReqHSC2_437T) */

#define Com_SGAPAReqHSC2_437T ComConf_ComSignal_SGAPAReqHSC2_437T


#if (defined Com_SGAPASCSAcclReqStsHSC2_437T) /* To prevent double declaration */
#error Com_SGAPASCSAcclReqStsHSC2_437T already defined
#endif /* #if (defined Com_SGAPASCSAcclReqStsHSC2_437T) */

#define Com_SGAPASCSAcclReqStsHSC2_437T ComConf_ComSignal_SGAPASCSAcclReqStsHSC2_437T


#if (defined Com_SGAPASCSAcclReqValHSC2_437T) /* To prevent double declaration */
#error Com_SGAPASCSAcclReqValHSC2_437T already defined
#endif /* #if (defined Com_SGAPASCSAcclReqValHSC2_437T) */

#define Com_SGAPASCSAcclReqValHSC2_437T ComConf_ComSignal_SGAPASCSAcclReqValHSC2_437T


#if (defined Com_SGAPASCSAcclReqValPVHSC2_437T) /* To prevent double declaration */
#error Com_SGAPASCSAcclReqValPVHSC2_437T already defined
#endif /* #if (defined Com_SGAPASCSAcclReqValPVHSC2_437T) */

#define Com_SGAPASCSAcclReqValPVHSC2_437T ComConf_ComSignal_SGAPASCSAcclReqValPVHSC2_437T


#if (defined Com_SGAPASCSAlvRCHSC2_437T) /* To prevent double declaration */
#error Com_SGAPASCSAlvRCHSC2_437T already defined
#endif /* #if (defined Com_SGAPASCSAlvRCHSC2_437T) */

#define Com_SGAPASCSAlvRCHSC2_437T ComConf_ComSignal_SGAPASCSAlvRCHSC2_437T


#if (defined Com_SGAPAShifterPosReqdHSC2_437T) /* To prevent double declaration */
#error Com_SGAPAShifterPosReqdHSC2_437T already defined
#endif /* #if (defined Com_SGAPAShifterPosReqdHSC2_437T) */

#define Com_SGAPAShifterPosReqdHSC2_437T ComConf_ComSignal_SGAPAShifterPosReqdHSC2_437T


#if (defined Com_SGAPAStsHSC2_437T) /* To prevent double declaration */
#error Com_SGAPAStsHSC2_437T already defined
#endif /* #if (defined Com_SGAPAStsHSC2_437T) */

#define Com_SGAPAStsHSC2_437T ComConf_ComSignal_SGAPAStsHSC2_437T


#if (defined Com_SGFLSideObsDistHSC2_567T) /* To prevent double declaration */
#error Com_SGFLSideObsDistHSC2_567T already defined
#endif /* #if (defined Com_SGFLSideObsDistHSC2_567T) */

#define Com_SGFLSideObsDistHSC2_567T ComConf_ComSignal_SGFLSideObsDistHSC2_567T


#if (defined Com_SGFRSideObsDistHSC2_567T) /* To prevent double declaration */
#error Com_SGFRSideObsDistHSC2_567T already defined
#endif /* #if (defined Com_SGFRSideObsDistHSC2_567T) */

#define Com_SGFRSideObsDistHSC2_567T ComConf_ComSignal_SGFRSideObsDistHSC2_567T


#if (defined Com_SGRLSideObsDistHSC2_567T) /* To prevent double declaration */
#error Com_SGRLSideObsDistHSC2_567T already defined
#endif /* #if (defined Com_SGRLSideObsDistHSC2_567T) */

#define Com_SGRLSideObsDistHSC2_567T ComConf_ComSignal_SGRLSideObsDistHSC2_567T


#if (defined Com_SGRRSideObsDistHSC2_567T) /* To prevent double declaration */
#error Com_SGRRSideObsDistHSC2_567T already defined
#endif /* #if (defined Com_SGRRSideObsDistHSC2_567T) */

#define Com_SGRRSideObsDistHSC2_567T ComConf_ComSignal_SGRRSideObsDistHSC2_567T


#if (defined Com_SGFLObsRngHSC2_573T) /* To prevent double declaration */
#error Com_SGFLObsRngHSC2_573T already defined
#endif /* #if (defined Com_SGFLObsRngHSC2_573T) */

#define Com_SGFLObsRngHSC2_573T ComConf_ComSignal_SGFLObsRngHSC2_573T


#if (defined Com_SGFRObsRngHSC2_573T) /* To prevent double declaration */
#error Com_SGFRObsRngHSC2_573T already defined
#endif /* #if (defined Com_SGFRObsRngHSC2_573T) */

#define Com_SGFRObsRngHSC2_573T ComConf_ComSignal_SGFRObsRngHSC2_573T


#if (defined Com_SGFrtMidLObsRngHSC2_573T) /* To prevent double declaration */
#error Com_SGFrtMidLObsRngHSC2_573T already defined
#endif /* #if (defined Com_SGFrtMidLObsRngHSC2_573T) */

#define Com_SGFrtMidLObsRngHSC2_573T ComConf_ComSignal_SGFrtMidLObsRngHSC2_573T


#if (defined Com_SGFrtMidRObsRngHSC2_573T) /* To prevent double declaration */
#error Com_SGFrtMidRObsRngHSC2_573T already defined
#endif /* #if (defined Com_SGFrtMidRObsRngHSC2_573T) */

#define Com_SGFrtMidRObsRngHSC2_573T ComConf_ComSignal_SGFrtMidRObsRngHSC2_573T


#if (defined Com_SGFrtObsDistHSC2_573T) /* To prevent double declaration */
#error Com_SGFrtObsDistHSC2_573T already defined
#endif /* #if (defined Com_SGFrtObsDistHSC2_573T) */

#define Com_SGFrtObsDistHSC2_573T ComConf_ComSignal_SGFrtObsDistHSC2_573T


#if (defined Com_SGFrtPDCAudWrnngHSC2_573T) /* To prevent double declaration */
#error Com_SGFrtPDCAudWrnngHSC2_573T already defined
#endif /* #if (defined Com_SGFrtPDCAudWrnngHSC2_573T) */

#define Com_SGFrtPDCAudWrnngHSC2_573T ComConf_ComSignal_SGFrtPDCAudWrnngHSC2_573T


#if (defined Com_SGPDCCofignStsHSC2_573T) /* To prevent double declaration */
#error Com_SGPDCCofignStsHSC2_573T already defined
#endif /* #if (defined Com_SGPDCCofignStsHSC2_573T) */

#define Com_SGPDCCofignStsHSC2_573T ComConf_ComSignal_SGPDCCofignStsHSC2_573T


#if (defined Com_SGPDCSysStsHSC2_573T) /* To prevent double declaration */
#error Com_SGPDCSysStsHSC2_573T already defined
#endif /* #if (defined Com_SGPDCSysStsHSC2_573T) */

#define Com_SGPDCSysStsHSC2_573T ComConf_ComSignal_SGPDCSysStsHSC2_573T


#if (defined Com_SGRLObsRngHSC2_573T) /* To prevent double declaration */
#error Com_SGRLObsRngHSC2_573T already defined
#endif /* #if (defined Com_SGRLObsRngHSC2_573T) */

#define Com_SGRLObsRngHSC2_573T ComConf_ComSignal_SGRLObsRngHSC2_573T


#if (defined Com_SGRRObsRngHSC2_573T) /* To prevent double declaration */
#error Com_SGRRObsRngHSC2_573T already defined
#endif /* #if (defined Com_SGRRObsRngHSC2_573T) */

#define Com_SGRRObsRngHSC2_573T ComConf_ComSignal_SGRRObsRngHSC2_573T


#if (defined Com_SGRrMidLObsRngHSC2_573T) /* To prevent double declaration */
#error Com_SGRrMidLObsRngHSC2_573T already defined
#endif /* #if (defined Com_SGRrMidLObsRngHSC2_573T) */

#define Com_SGRrMidLObsRngHSC2_573T ComConf_ComSignal_SGRrMidLObsRngHSC2_573T


#if (defined Com_SGRrMidRObsRngHSC2_573T) /* To prevent double declaration */
#error Com_SGRrMidRObsRngHSC2_573T already defined
#endif /* #if (defined Com_SGRrMidRObsRngHSC2_573T) */

#define Com_SGRrMidRObsRngHSC2_573T ComConf_ComSignal_SGRrMidRObsRngHSC2_573T


#if (defined Com_SGRrObsDistHSC2_573T) /* To prevent double declaration */
#error Com_SGRrObsDistHSC2_573T already defined
#endif /* #if (defined Com_SGRrObsDistHSC2_573T) */

#define Com_SGRrObsDistHSC2_573T ComConf_ComSignal_SGRrObsDistHSC2_573T


#if (defined Com_SGRrPDCAudWrnngHSC2_573T) /* To prevent double declaration */
#error Com_SGRrPDCAudWrnngHSC2_573T already defined
#endif /* #if (defined Com_SGRrPDCAudWrnngHSC2_573T) */

#define Com_SGRrPDCAudWrnngHSC2_573T ComConf_ComSignal_SGRrPDCAudWrnngHSC2_573T


#if (defined Com_SGFLObsDist_sech2_SecCAN2_651T) /* To prevent double declaration */
#error Com_SGFLObsDist_sech2_SecCAN2_651T already defined
#endif /* #if (defined Com_SGFLObsDist_sech2_SecCAN2_651T) */

#define Com_SGFLObsDist_sech2_SecCAN2_651T ComConf_ComSignal_SGFLObsDist_sech2_SecCAN2_651T


#if (defined Com_SGFRObsDist_sech2_SecCAN2_651T) /* To prevent double declaration */
#error Com_SGFRObsDist_sech2_SecCAN2_651T already defined
#endif /* #if (defined Com_SGFRObsDist_sech2_SecCAN2_651T) */

#define Com_SGFRObsDist_sech2_SecCAN2_651T ComConf_ComSignal_SGFRObsDist_sech2_SecCAN2_651T


#if (defined Com_SGRLObsDist_sech2_SecCAN2_651T) /* To prevent double declaration */
#error Com_SGRLObsDist_sech2_SecCAN2_651T already defined
#endif /* #if (defined Com_SGRLObsDist_sech2_SecCAN2_651T) */

#define Com_SGRLObsDist_sech2_SecCAN2_651T ComConf_ComSignal_SGRLObsDist_sech2_SecCAN2_651T


#if (defined Com_SGRRObsDist_sech2_SecCAN2_651T) /* To prevent double declaration */
#error Com_SGRRObsDist_sech2_SecCAN2_651T already defined
#endif /* #if (defined Com_SGRRObsDist_sech2_SecCAN2_651T) */

#define Com_SGRRObsDist_sech2_SecCAN2_651T ComConf_ComSignal_SGRRObsDist_sech2_SecCAN2_651T


#if (defined Com_SGIECUToBCMCtrlPotclHSC2_914T) /* To prevent double declaration */
#error Com_SGIECUToBCMCtrlPotclHSC2_914T already defined
#endif /* #if (defined Com_SGIECUToBCMCtrlPotclHSC2_914T) */

#define Com_SGIECUToBCMCtrlPotclHSC2_914T ComConf_ComSignal_SGIECUToBCMCtrlPotclHSC2_914T


#if (defined Com_SGHD_AVMCurViewHSC4_764T) /* To prevent double declaration */
#error Com_SGHD_AVMCurViewHSC4_764T already defined
#endif /* #if (defined Com_SGHD_AVMCurViewHSC4_764T) */

#define Com_SGHD_AVMCurViewHSC4_764T ComConf_ComSignal_SGHD_AVMCurViewHSC4_764T


#if (defined Com_SGHD_AVMErrorDisplay_h4HSC4_764T) /* To prevent double declaration */
#error Com_SGHD_AVMErrorDisplay_h4HSC4_764T already defined
#endif /* #if (defined Com_SGHD_AVMErrorDisplay_h4HSC4_764T) */

#define Com_SGHD_AVMErrorDisplay_h4HSC4_764T ComConf_ComSignal_SGHD_AVMErrorDisplay_h4HSC4_764T


#if (defined Com_SGHD_AVMInfoDisplayHSC4_764T) /* To prevent double declaration */
#error Com_SGHD_AVMInfoDisplayHSC4_764T already defined
#endif /* #if (defined Com_SGHD_AVMInfoDisplayHSC4_764T) */

#define Com_SGHD_AVMInfoDisplayHSC4_764T ComConf_ComSignal_SGHD_AVMInfoDisplayHSC4_764T


#if (defined Com_SGHD_AVMVideoFmtStaHSC4_764T) /* To prevent double declaration */
#error Com_SGHD_AVMVideoFmtStaHSC4_764T already defined
#endif /* #if (defined Com_SGHD_AVMVideoFmtStaHSC4_764T) */

#define Com_SGHD_AVMVideoFmtStaHSC4_764T ComConf_ComSignal_SGHD_AVMVideoFmtStaHSC4_764T


#if (defined Com_SGHD_AVMsysrdyHSC4_764T) /* To prevent double declaration */
#error Com_SGHD_AVMsysrdyHSC4_764T already defined
#endif /* #if (defined Com_SGHD_AVMsysrdyHSC4_764T) */

#define Com_SGHD_AVMsysrdyHSC4_764T ComConf_ComSignal_SGHD_AVMsysrdyHSC4_764T


#if (defined Com_SGRoute2StateHSC4_781T) /* To prevent double declaration */
#error Com_SGRoute2StateHSC4_781T already defined
#endif /* #if (defined Com_SGRoute2StateHSC4_781T) */

#define Com_SGRoute2StateHSC4_781T ComConf_ComSignal_SGRoute2StateHSC4_781T


#if (defined Com_SGAutoDrvngSysStsHSC4_912T) /* To prevent double declaration */
#error Com_SGAutoDrvngSysStsHSC4_912T already defined
#endif /* #if (defined Com_SGAutoDrvngSysStsHSC4_912T) */

#define Com_SGAutoDrvngSysStsHSC4_912T ComConf_ComSignal_SGAutoDrvngSysStsHSC4_912T


#if (defined Com_SGAPAParkngSchedHSC2_966T) /* To prevent double declaration */
#error Com_SGAPAParkngSchedHSC2_966T already defined
#endif /* #if (defined Com_SGAPAParkngSchedHSC2_966T) */

#define Com_SGAPAParkngSchedHSC2_966T ComConf_ComSignal_SGAPAParkngSchedHSC2_966T


#if (defined Com_SGAPAParkngSchedVHSC2_966T) /* To prevent double declaration */
#error Com_SGAPAParkngSchedVHSC2_966T already defined
#endif /* #if (defined Com_SGAPAParkngSchedVHSC2_966T) */

#define Com_SGAPAParkngSchedVHSC2_966T ComConf_ComSignal_SGAPAParkngSchedVHSC2_966T


#if (defined Com_SGAPASlotBearngHSC2_966T) /* To prevent double declaration */
#error Com_SGAPASlotBearngHSC2_966T already defined
#endif /* #if (defined Com_SGAPASlotBearngHSC2_966T) */

#define Com_SGAPASlotBearngHSC2_966T ComConf_ComSignal_SGAPASlotBearngHSC2_966T


#if (defined Com_SGAPASlotLngthHSC2_966T) /* To prevent double declaration */
#error Com_SGAPASlotLngthHSC2_966T already defined
#endif /* #if (defined Com_SGAPASlotLngthHSC2_966T) */

#define Com_SGAPASlotLngthHSC2_966T ComConf_ComSignal_SGAPASlotLngthHSC2_966T


#if (defined Com_SGAPAVehCrdnatAzmthHSC2_966T) /* To prevent double declaration */
#error Com_SGAPAVehCrdnatAzmthHSC2_966T already defined
#endif /* #if (defined Com_SGAPAVehCrdnatAzmthHSC2_966T) */

#define Com_SGAPAVehCrdnatAzmthHSC2_966T ComConf_ComSignal_SGAPAVehCrdnatAzmthHSC2_966T


#if (defined Com_SGAPAVehCrdnatPosXHSC2_966T) /* To prevent double declaration */
#error Com_SGAPAVehCrdnatPosXHSC2_966T already defined
#endif /* #if (defined Com_SGAPAVehCrdnatPosXHSC2_966T) */

#define Com_SGAPAVehCrdnatPosXHSC2_966T ComConf_ComSignal_SGAPAVehCrdnatPosXHSC2_966T


#if (defined Com_SGAPAVehCrdnatPosYHSC2_966T) /* To prevent double declaration */
#error Com_SGAPAVehCrdnatPosYHSC2_966T already defined
#endif /* #if (defined Com_SGAPAVehCrdnatPosYHSC2_966T) */

#define Com_SGAPAVehCrdnatPosYHSC2_966T ComConf_ComSignal_SGAPAVehCrdnatPosYHSC2_966T


#if (defined Com_SGDspObjInfo_531_Counter_1329T) /* To prevent double declaration */
#error Com_SGDspObjInfo_531_Counter_1329T already defined
#endif /* #if (defined Com_SGDspObjInfo_531_Counter_1329T) */

#define Com_SGDspObjInfo_531_Counter_1329T ComConf_ComSignal_SGDspObjInfo_531_Counter_1329T


#if (defined Com_SGLeftDspObjInfo_531_0_DspMode_1329T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_531_0_DspMode_1329T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_531_0_DspMode_1329T) */

#define Com_SGLeftDspObjInfo_531_0_DspMode_1329T ComConf_ComSignal_SGLeftDspObjInfo_531_0_DspMode_1329T


#if (defined Com_SGLeftDspObjInfo_531_0_ID_1329T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_531_0_ID_1329T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_531_0_ID_1329T) */

#define Com_SGLeftDspObjInfo_531_0_ID_1329T ComConf_ComSignal_SGLeftDspObjInfo_531_0_ID_1329T


#if (defined Com_SGLeftDspObjInfo_531_1_DspMode_1329T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_531_1_DspMode_1329T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_531_1_DspMode_1329T) */

#define Com_SGLeftDspObjInfo_531_1_DspMode_1329T ComConf_ComSignal_SGLeftDspObjInfo_531_1_DspMode_1329T


#if (defined Com_SGLeftDspObjInfo_531_1_ID_1329T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_531_1_ID_1329T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_531_1_ID_1329T) */

#define Com_SGLeftDspObjInfo_531_1_ID_1329T ComConf_ComSignal_SGLeftDspObjInfo_531_1_ID_1329T


#if (defined Com_SGLeftDspObjInfo_531_2_DspMode_1329T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_531_2_DspMode_1329T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_531_2_DspMode_1329T) */

#define Com_SGLeftDspObjInfo_531_2_DspMode_1329T ComConf_ComSignal_SGLeftDspObjInfo_531_2_DspMode_1329T


#if (defined Com_SGLeftDspObjInfo_531_2_ID_1329T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_531_2_ID_1329T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_531_2_ID_1329T) */

#define Com_SGLeftDspObjInfo_531_2_ID_1329T ComConf_ComSignal_SGLeftDspObjInfo_531_2_ID_1329T


#if (defined Com_SGLeftDspObjInfo_531_3_DspMode_1329T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_531_3_DspMode_1329T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_531_3_DspMode_1329T) */

#define Com_SGLeftDspObjInfo_531_3_DspMode_1329T ComConf_ComSignal_SGLeftDspObjInfo_531_3_DspMode_1329T


#if (defined Com_SGLeftDspObjInfo_531_3_ID_1329T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_531_3_ID_1329T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_531_3_ID_1329T) */

#define Com_SGLeftDspObjInfo_531_3_ID_1329T ComConf_ComSignal_SGLeftDspObjInfo_531_3_ID_1329T


#if (defined Com_SGRightDspObjInfo_531_0_DspMode_1329T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_531_0_DspMode_1329T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_531_0_DspMode_1329T) */

#define Com_SGRightDspObjInfo_531_0_DspMode_1329T ComConf_ComSignal_SGRightDspObjInfo_531_0_DspMode_1329T


#if (defined Com_SGRightDspObjInfo_531_0_ID_1329T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_531_0_ID_1329T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_531_0_ID_1329T) */

#define Com_SGRightDspObjInfo_531_0_ID_1329T ComConf_ComSignal_SGRightDspObjInfo_531_0_ID_1329T


#if (defined Com_SGRightDspObjInfo_531_1_DspMode_1329T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_531_1_DspMode_1329T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_531_1_DspMode_1329T) */

#define Com_SGRightDspObjInfo_531_1_DspMode_1329T ComConf_ComSignal_SGRightDspObjInfo_531_1_DspMode_1329T


#if (defined Com_SGRightDspObjInfo_531_1_ID_1329T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_531_1_ID_1329T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_531_1_ID_1329T) */

#define Com_SGRightDspObjInfo_531_1_ID_1329T ComConf_ComSignal_SGRightDspObjInfo_531_1_ID_1329T


#if (defined Com_SGRightDspObjInfo_531_2_DspMode_1329T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_531_2_DspMode_1329T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_531_2_DspMode_1329T) */

#define Com_SGRightDspObjInfo_531_2_DspMode_1329T ComConf_ComSignal_SGRightDspObjInfo_531_2_DspMode_1329T


#if (defined Com_SGRightDspObjInfo_531_2_ID_1329T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_531_2_ID_1329T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_531_2_ID_1329T) */

#define Com_SGRightDspObjInfo_531_2_ID_1329T ComConf_ComSignal_SGRightDspObjInfo_531_2_ID_1329T


#if (defined Com_SGRightDspObjInfo_531_3_DspMode_1329T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_531_3_DspMode_1329T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_531_3_DspMode_1329T) */

#define Com_SGRightDspObjInfo_531_3_DspMode_1329T ComConf_ComSignal_SGRightDspObjInfo_531_3_DspMode_1329T


#if (defined Com_SGRightDspObjInfo_531_3_ID_1329T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_531_3_ID_1329T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_531_3_ID_1329T) */

#define Com_SGRightDspObjInfo_531_3_ID_1329T ComConf_ComSignal_SGRightDspObjInfo_531_3_ID_1329T


#if (defined Com_SGLeftDspObjInfo_0_CounterHSC4_1330T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_0_CounterHSC4_1330T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_0_CounterHSC4_1330T) */

#define Com_SGLeftDspObjInfo_0_CounterHSC4_1330T ComConf_ComSignal_SGLeftDspObjInfo_0_CounterHSC4_1330T


#if (defined Com_SGLeftDspObjInfo_0_ThetaHSC4_1330T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_0_ThetaHSC4_1330T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_0_ThetaHSC4_1330T) */

#define Com_SGLeftDspObjInfo_0_ThetaHSC4_1330T ComConf_ComSignal_SGLeftDspObjInfo_0_ThetaHSC4_1330T


#if (defined Com_SGLeftDspObjInfo_0_TypeHSC4_1330T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_0_TypeHSC4_1330T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_0_TypeHSC4_1330T) */

#define Com_SGLeftDspObjInfo_0_TypeHSC4_1330T ComConf_ComSignal_SGLeftDspObjInfo_0_TypeHSC4_1330T


#if (defined Com_SGLeftDspObjInfo_0_XHSC4_1330T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_0_XHSC4_1330T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_0_XHSC4_1330T) */

#define Com_SGLeftDspObjInfo_0_XHSC4_1330T ComConf_ComSignal_SGLeftDspObjInfo_0_XHSC4_1330T


#if (defined Com_SGLeftDspObjInfo_0_YHSC4_1330T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_0_YHSC4_1330T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_0_YHSC4_1330T) */

#define Com_SGLeftDspObjInfo_0_YHSC4_1330T ComConf_ComSignal_SGLeftDspObjInfo_0_YHSC4_1330T


#if (defined Com_SGRightDspObjInfo_0_CounterHSC4_1330T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_0_CounterHSC4_1330T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_0_CounterHSC4_1330T) */

#define Com_SGRightDspObjInfo_0_CounterHSC4_1330T ComConf_ComSignal_SGRightDspObjInfo_0_CounterHSC4_1330T


#if (defined Com_SGRightDspObjInfo_0_ThetaHSC4_1330T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_0_ThetaHSC4_1330T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_0_ThetaHSC4_1330T) */

#define Com_SGRightDspObjInfo_0_ThetaHSC4_1330T ComConf_ComSignal_SGRightDspObjInfo_0_ThetaHSC4_1330T


#if (defined Com_SGRightDspObjInfo_0_TypeHSC4_1330T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_0_TypeHSC4_1330T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_0_TypeHSC4_1330T) */

#define Com_SGRightDspObjInfo_0_TypeHSC4_1330T ComConf_ComSignal_SGRightDspObjInfo_0_TypeHSC4_1330T


#if (defined Com_SGRightDspObjInfo_0_XHSC4_1330T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_0_XHSC4_1330T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_0_XHSC4_1330T) */

#define Com_SGRightDspObjInfo_0_XHSC4_1330T ComConf_ComSignal_SGRightDspObjInfo_0_XHSC4_1330T


#if (defined Com_SGRightDspObjInfo_0_YHSC4_1330T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_0_YHSC4_1330T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_0_YHSC4_1330T) */

#define Com_SGRightDspObjInfo_0_YHSC4_1330T ComConf_ComSignal_SGRightDspObjInfo_0_YHSC4_1330T


#if (defined Com_SGLeftDspObjInfo_1_CounterHSC4_1337T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_1_CounterHSC4_1337T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_1_CounterHSC4_1337T) */

#define Com_SGLeftDspObjInfo_1_CounterHSC4_1337T ComConf_ComSignal_SGLeftDspObjInfo_1_CounterHSC4_1337T


#if (defined Com_SGLeftDspObjInfo_1_ThetaHSC4_1337T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_1_ThetaHSC4_1337T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_1_ThetaHSC4_1337T) */

#define Com_SGLeftDspObjInfo_1_ThetaHSC4_1337T ComConf_ComSignal_SGLeftDspObjInfo_1_ThetaHSC4_1337T


#if (defined Com_SGLeftDspObjInfo_1_TypeHSC4_1337T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_1_TypeHSC4_1337T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_1_TypeHSC4_1337T) */

#define Com_SGLeftDspObjInfo_1_TypeHSC4_1337T ComConf_ComSignal_SGLeftDspObjInfo_1_TypeHSC4_1337T


#if (defined Com_SGLeftDspObjInfo_1_XHSC4_1337T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_1_XHSC4_1337T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_1_XHSC4_1337T) */

#define Com_SGLeftDspObjInfo_1_XHSC4_1337T ComConf_ComSignal_SGLeftDspObjInfo_1_XHSC4_1337T


#if (defined Com_SGLeftDspObjInfo_1_YHSC4_1337T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_1_YHSC4_1337T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_1_YHSC4_1337T) */

#define Com_SGLeftDspObjInfo_1_YHSC4_1337T ComConf_ComSignal_SGLeftDspObjInfo_1_YHSC4_1337T


#if (defined Com_SGRightDspObjInfo_1_CounterHSC4_1337T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_1_CounterHSC4_1337T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_1_CounterHSC4_1337T) */

#define Com_SGRightDspObjInfo_1_CounterHSC4_1337T ComConf_ComSignal_SGRightDspObjInfo_1_CounterHSC4_1337T


#if (defined Com_SGRightDspObjInfo_1_ThetaHSC4_1337T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_1_ThetaHSC4_1337T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_1_ThetaHSC4_1337T) */

#define Com_SGRightDspObjInfo_1_ThetaHSC4_1337T ComConf_ComSignal_SGRightDspObjInfo_1_ThetaHSC4_1337T


#if (defined Com_SGRightDspObjInfo_1_TypeHSC4_1337T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_1_TypeHSC4_1337T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_1_TypeHSC4_1337T) */

#define Com_SGRightDspObjInfo_1_TypeHSC4_1337T ComConf_ComSignal_SGRightDspObjInfo_1_TypeHSC4_1337T


#if (defined Com_SGRightDspObjInfo_1_XHSC4_1337T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_1_XHSC4_1337T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_1_XHSC4_1337T) */

#define Com_SGRightDspObjInfo_1_XHSC4_1337T ComConf_ComSignal_SGRightDspObjInfo_1_XHSC4_1337T


#if (defined Com_SGRightDspObjInfo_1_YHSC4_1337T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_1_YHSC4_1337T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_1_YHSC4_1337T) */

#define Com_SGRightDspObjInfo_1_YHSC4_1337T ComConf_ComSignal_SGRightDspObjInfo_1_YHSC4_1337T


#if (defined Com_SGLeftDspObjInfo_2_CounterHSC4_1339T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_2_CounterHSC4_1339T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_2_CounterHSC4_1339T) */

#define Com_SGLeftDspObjInfo_2_CounterHSC4_1339T ComConf_ComSignal_SGLeftDspObjInfo_2_CounterHSC4_1339T


#if (defined Com_SGLeftDspObjInfo_2_ThetaHSC4_1339T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_2_ThetaHSC4_1339T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_2_ThetaHSC4_1339T) */

#define Com_SGLeftDspObjInfo_2_ThetaHSC4_1339T ComConf_ComSignal_SGLeftDspObjInfo_2_ThetaHSC4_1339T


#if (defined Com_SGLeftDspObjInfo_2_TypeHSC4_1339T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_2_TypeHSC4_1339T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_2_TypeHSC4_1339T) */

#define Com_SGLeftDspObjInfo_2_TypeHSC4_1339T ComConf_ComSignal_SGLeftDspObjInfo_2_TypeHSC4_1339T


#if (defined Com_SGLeftDspObjInfo_2_XHSC4_1339T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_2_XHSC4_1339T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_2_XHSC4_1339T) */

#define Com_SGLeftDspObjInfo_2_XHSC4_1339T ComConf_ComSignal_SGLeftDspObjInfo_2_XHSC4_1339T


#if (defined Com_SGLeftDspObjInfo_2_YHSC4_1339T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_2_YHSC4_1339T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_2_YHSC4_1339T) */

#define Com_SGLeftDspObjInfo_2_YHSC4_1339T ComConf_ComSignal_SGLeftDspObjInfo_2_YHSC4_1339T


#if (defined Com_SGRightDspObjInfo_2_CounterHSC4_1339T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_2_CounterHSC4_1339T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_2_CounterHSC4_1339T) */

#define Com_SGRightDspObjInfo_2_CounterHSC4_1339T ComConf_ComSignal_SGRightDspObjInfo_2_CounterHSC4_1339T


#if (defined Com_SGRightDspObjInfo_2_ThetaHSC4_1339T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_2_ThetaHSC4_1339T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_2_ThetaHSC4_1339T) */

#define Com_SGRightDspObjInfo_2_ThetaHSC4_1339T ComConf_ComSignal_SGRightDspObjInfo_2_ThetaHSC4_1339T


#if (defined Com_SGRightDspObjInfo_2_TypeHSC4_1339T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_2_TypeHSC4_1339T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_2_TypeHSC4_1339T) */

#define Com_SGRightDspObjInfo_2_TypeHSC4_1339T ComConf_ComSignal_SGRightDspObjInfo_2_TypeHSC4_1339T


#if (defined Com_SGRightDspObjInfo_2_XHSC4_1339T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_2_XHSC4_1339T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_2_XHSC4_1339T) */

#define Com_SGRightDspObjInfo_2_XHSC4_1339T ComConf_ComSignal_SGRightDspObjInfo_2_XHSC4_1339T


#if (defined Com_SGRightDspObjInfo_2_YHSC4_1339T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_2_YHSC4_1339T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_2_YHSC4_1339T) */

#define Com_SGRightDspObjInfo_2_YHSC4_1339T ComConf_ComSignal_SGRightDspObjInfo_2_YHSC4_1339T


#if (defined Com_SGLeftDspObjInfo_3_CounterHSC4_1340T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_3_CounterHSC4_1340T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_3_CounterHSC4_1340T) */

#define Com_SGLeftDspObjInfo_3_CounterHSC4_1340T ComConf_ComSignal_SGLeftDspObjInfo_3_CounterHSC4_1340T


#if (defined Com_SGLeftDspObjInfo_3_ThetaHSC4_1340T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_3_ThetaHSC4_1340T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_3_ThetaHSC4_1340T) */

#define Com_SGLeftDspObjInfo_3_ThetaHSC4_1340T ComConf_ComSignal_SGLeftDspObjInfo_3_ThetaHSC4_1340T


#if (defined Com_SGLeftDspObjInfo_3_TypeHSC4_1340T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_3_TypeHSC4_1340T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_3_TypeHSC4_1340T) */

#define Com_SGLeftDspObjInfo_3_TypeHSC4_1340T ComConf_ComSignal_SGLeftDspObjInfo_3_TypeHSC4_1340T


#if (defined Com_SGLeftDspObjInfo_3_XHSC4_1340T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_3_XHSC4_1340T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_3_XHSC4_1340T) */

#define Com_SGLeftDspObjInfo_3_XHSC4_1340T ComConf_ComSignal_SGLeftDspObjInfo_3_XHSC4_1340T


#if (defined Com_SGLeftDspObjInfo_3_YHSC4_1340T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_3_YHSC4_1340T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_3_YHSC4_1340T) */

#define Com_SGLeftDspObjInfo_3_YHSC4_1340T ComConf_ComSignal_SGLeftDspObjInfo_3_YHSC4_1340T


#if (defined Com_SGRightDspObjInfo_3_CounterHSC4_1340T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_3_CounterHSC4_1340T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_3_CounterHSC4_1340T) */

#define Com_SGRightDspObjInfo_3_CounterHSC4_1340T ComConf_ComSignal_SGRightDspObjInfo_3_CounterHSC4_1340T


#if (defined Com_SGRightDspObjInfo_3_ThetaHSC4_1340T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_3_ThetaHSC4_1340T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_3_ThetaHSC4_1340T) */

#define Com_SGRightDspObjInfo_3_ThetaHSC4_1340T ComConf_ComSignal_SGRightDspObjInfo_3_ThetaHSC4_1340T


#if (defined Com_SGRightDspObjInfo_3_TypeHSC4_1340T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_3_TypeHSC4_1340T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_3_TypeHSC4_1340T) */

#define Com_SGRightDspObjInfo_3_TypeHSC4_1340T ComConf_ComSignal_SGRightDspObjInfo_3_TypeHSC4_1340T


#if (defined Com_SGRightDspObjInfo_3_XHSC4_1340T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_3_XHSC4_1340T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_3_XHSC4_1340T) */

#define Com_SGRightDspObjInfo_3_XHSC4_1340T ComConf_ComSignal_SGRightDspObjInfo_3_XHSC4_1340T


#if (defined Com_SGRightDspObjInfo_3_YHSC4_1340T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_3_YHSC4_1340T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_3_YHSC4_1340T) */

#define Com_SGRightDspObjInfo_3_YHSC4_1340T ComConf_ComSignal_SGRightDspObjInfo_3_YHSC4_1340T


#if (defined Com_SGLeftDspObjInfo_4_CounterHSC4_1341T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_4_CounterHSC4_1341T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_4_CounterHSC4_1341T) */

#define Com_SGLeftDspObjInfo_4_CounterHSC4_1341T ComConf_ComSignal_SGLeftDspObjInfo_4_CounterHSC4_1341T


#if (defined Com_SGLeftDspObjInfo_4_ThetaHSC4_1341T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_4_ThetaHSC4_1341T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_4_ThetaHSC4_1341T) */

#define Com_SGLeftDspObjInfo_4_ThetaHSC4_1341T ComConf_ComSignal_SGLeftDspObjInfo_4_ThetaHSC4_1341T


#if (defined Com_SGLeftDspObjInfo_4_TypeHSC4_1341T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_4_TypeHSC4_1341T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_4_TypeHSC4_1341T) */

#define Com_SGLeftDspObjInfo_4_TypeHSC4_1341T ComConf_ComSignal_SGLeftDspObjInfo_4_TypeHSC4_1341T


#if (defined Com_SGLeftDspObjInfo_4_XHSC4_1341T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_4_XHSC4_1341T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_4_XHSC4_1341T) */

#define Com_SGLeftDspObjInfo_4_XHSC4_1341T ComConf_ComSignal_SGLeftDspObjInfo_4_XHSC4_1341T


#if (defined Com_SGLeftDspObjInfo_4_YHSC4_1341T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_4_YHSC4_1341T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_4_YHSC4_1341T) */

#define Com_SGLeftDspObjInfo_4_YHSC4_1341T ComConf_ComSignal_SGLeftDspObjInfo_4_YHSC4_1341T


#if (defined Com_SGRightDspObjInfo_4_CounterHSC4_1341T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_4_CounterHSC4_1341T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_4_CounterHSC4_1341T) */

#define Com_SGRightDspObjInfo_4_CounterHSC4_1341T ComConf_ComSignal_SGRightDspObjInfo_4_CounterHSC4_1341T


#if (defined Com_SGRightDspObjInfo_4_ThetaHSC4_1341T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_4_ThetaHSC4_1341T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_4_ThetaHSC4_1341T) */

#define Com_SGRightDspObjInfo_4_ThetaHSC4_1341T ComConf_ComSignal_SGRightDspObjInfo_4_ThetaHSC4_1341T


#if (defined Com_SGRightDspObjInfo_4_TypeHSC4_1341T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_4_TypeHSC4_1341T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_4_TypeHSC4_1341T) */

#define Com_SGRightDspObjInfo_4_TypeHSC4_1341T ComConf_ComSignal_SGRightDspObjInfo_4_TypeHSC4_1341T


#if (defined Com_SGRightDspObjInfo_4_XHSC4_1341T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_4_XHSC4_1341T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_4_XHSC4_1341T) */

#define Com_SGRightDspObjInfo_4_XHSC4_1341T ComConf_ComSignal_SGRightDspObjInfo_4_XHSC4_1341T


#if (defined Com_SGRightDspObjInfo_4_YHSC4_1341T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_4_YHSC4_1341T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_4_YHSC4_1341T) */

#define Com_SGRightDspObjInfo_4_YHSC4_1341T ComConf_ComSignal_SGRightDspObjInfo_4_YHSC4_1341T


#if (defined Com_SGLeftDspObjInfo_5_CounterHSC4_1342T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_5_CounterHSC4_1342T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_5_CounterHSC4_1342T) */

#define Com_SGLeftDspObjInfo_5_CounterHSC4_1342T ComConf_ComSignal_SGLeftDspObjInfo_5_CounterHSC4_1342T


#if (defined Com_SGLeftDspObjInfo_5_ThetaHSC4_1342T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_5_ThetaHSC4_1342T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_5_ThetaHSC4_1342T) */

#define Com_SGLeftDspObjInfo_5_ThetaHSC4_1342T ComConf_ComSignal_SGLeftDspObjInfo_5_ThetaHSC4_1342T


#if (defined Com_SGLeftDspObjInfo_5_TypeHSC4_1342T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_5_TypeHSC4_1342T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_5_TypeHSC4_1342T) */

#define Com_SGLeftDspObjInfo_5_TypeHSC4_1342T ComConf_ComSignal_SGLeftDspObjInfo_5_TypeHSC4_1342T


#if (defined Com_SGLeftDspObjInfo_5_XHSC4_1342T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_5_XHSC4_1342T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_5_XHSC4_1342T) */

#define Com_SGLeftDspObjInfo_5_XHSC4_1342T ComConf_ComSignal_SGLeftDspObjInfo_5_XHSC4_1342T


#if (defined Com_SGLeftDspObjInfo_5_YHSC4_1342T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_5_YHSC4_1342T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_5_YHSC4_1342T) */

#define Com_SGLeftDspObjInfo_5_YHSC4_1342T ComConf_ComSignal_SGLeftDspObjInfo_5_YHSC4_1342T


#if (defined Com_SGRightDspObjInfo_5_CounterHSC4_1342T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_5_CounterHSC4_1342T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_5_CounterHSC4_1342T) */

#define Com_SGRightDspObjInfo_5_CounterHSC4_1342T ComConf_ComSignal_SGRightDspObjInfo_5_CounterHSC4_1342T


#if (defined Com_SGRightDspObjInfo_5_ThetaHSC4_1342T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_5_ThetaHSC4_1342T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_5_ThetaHSC4_1342T) */

#define Com_SGRightDspObjInfo_5_ThetaHSC4_1342T ComConf_ComSignal_SGRightDspObjInfo_5_ThetaHSC4_1342T


#if (defined Com_SGRightDspObjInfo_5_TypeHSC4_1342T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_5_TypeHSC4_1342T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_5_TypeHSC4_1342T) */

#define Com_SGRightDspObjInfo_5_TypeHSC4_1342T ComConf_ComSignal_SGRightDspObjInfo_5_TypeHSC4_1342T


#if (defined Com_SGRightDspObjInfo_5_XHSC4_1342T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_5_XHSC4_1342T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_5_XHSC4_1342T) */

#define Com_SGRightDspObjInfo_5_XHSC4_1342T ComConf_ComSignal_SGRightDspObjInfo_5_XHSC4_1342T


#if (defined Com_SGRightDspObjInfo_5_YHSC4_1342T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_5_YHSC4_1342T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_5_YHSC4_1342T) */

#define Com_SGRightDspObjInfo_5_YHSC4_1342T ComConf_ComSignal_SGRightDspObjInfo_5_YHSC4_1342T


#if (defined Com_SGLeftDspObjInfo_6_CounterHSC4_1343T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_6_CounterHSC4_1343T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_6_CounterHSC4_1343T) */

#define Com_SGLeftDspObjInfo_6_CounterHSC4_1343T ComConf_ComSignal_SGLeftDspObjInfo_6_CounterHSC4_1343T


#if (defined Com_SGLeftDspObjInfo_6_ThetaHSC4_1343T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_6_ThetaHSC4_1343T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_6_ThetaHSC4_1343T) */

#define Com_SGLeftDspObjInfo_6_ThetaHSC4_1343T ComConf_ComSignal_SGLeftDspObjInfo_6_ThetaHSC4_1343T


#if (defined Com_SGLeftDspObjInfo_6_TypeHSC4_1343T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_6_TypeHSC4_1343T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_6_TypeHSC4_1343T) */

#define Com_SGLeftDspObjInfo_6_TypeHSC4_1343T ComConf_ComSignal_SGLeftDspObjInfo_6_TypeHSC4_1343T


#if (defined Com_SGLeftDspObjInfo_6_XHSC4_1343T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_6_XHSC4_1343T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_6_XHSC4_1343T) */

#define Com_SGLeftDspObjInfo_6_XHSC4_1343T ComConf_ComSignal_SGLeftDspObjInfo_6_XHSC4_1343T


#if (defined Com_SGLeftDspObjInfo_6_YHSC4_1343T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_6_YHSC4_1343T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_6_YHSC4_1343T) */

#define Com_SGLeftDspObjInfo_6_YHSC4_1343T ComConf_ComSignal_SGLeftDspObjInfo_6_YHSC4_1343T


#if (defined Com_SGRightDspObjInfo_6_CounterHSC4_1343T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_6_CounterHSC4_1343T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_6_CounterHSC4_1343T) */

#define Com_SGRightDspObjInfo_6_CounterHSC4_1343T ComConf_ComSignal_SGRightDspObjInfo_6_CounterHSC4_1343T


#if (defined Com_SGRightDspObjInfo_6_ThetaHSC4_1343T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_6_ThetaHSC4_1343T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_6_ThetaHSC4_1343T) */

#define Com_SGRightDspObjInfo_6_ThetaHSC4_1343T ComConf_ComSignal_SGRightDspObjInfo_6_ThetaHSC4_1343T


#if (defined Com_SGRightDspObjInfo_6_TypeHSC4_1343T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_6_TypeHSC4_1343T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_6_TypeHSC4_1343T) */

#define Com_SGRightDspObjInfo_6_TypeHSC4_1343T ComConf_ComSignal_SGRightDspObjInfo_6_TypeHSC4_1343T


#if (defined Com_SGRightDspObjInfo_6_XHSC4_1343T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_6_XHSC4_1343T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_6_XHSC4_1343T) */

#define Com_SGRightDspObjInfo_6_XHSC4_1343T ComConf_ComSignal_SGRightDspObjInfo_6_XHSC4_1343T


#if (defined Com_SGRightDspObjInfo_6_YHSC4_1343T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_6_YHSC4_1343T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_6_YHSC4_1343T) */

#define Com_SGRightDspObjInfo_6_YHSC4_1343T ComConf_ComSignal_SGRightDspObjInfo_6_YHSC4_1343T


#if (defined Com_SGLeftDspObjInfo_7_CounterHSC4_1346T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_7_CounterHSC4_1346T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_7_CounterHSC4_1346T) */

#define Com_SGLeftDspObjInfo_7_CounterHSC4_1346T ComConf_ComSignal_SGLeftDspObjInfo_7_CounterHSC4_1346T


#if (defined Com_SGLeftDspObjInfo_7_ThetaHSC4_1346T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_7_ThetaHSC4_1346T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_7_ThetaHSC4_1346T) */

#define Com_SGLeftDspObjInfo_7_ThetaHSC4_1346T ComConf_ComSignal_SGLeftDspObjInfo_7_ThetaHSC4_1346T


#if (defined Com_SGLeftDspObjInfo_7_TypeHSC4_1346T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_7_TypeHSC4_1346T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_7_TypeHSC4_1346T) */

#define Com_SGLeftDspObjInfo_7_TypeHSC4_1346T ComConf_ComSignal_SGLeftDspObjInfo_7_TypeHSC4_1346T


#if (defined Com_SGLeftDspObjInfo_7_XHSC4_1346T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_7_XHSC4_1346T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_7_XHSC4_1346T) */

#define Com_SGLeftDspObjInfo_7_XHSC4_1346T ComConf_ComSignal_SGLeftDspObjInfo_7_XHSC4_1346T


#if (defined Com_SGLeftDspObjInfo_7_YHSC4_1346T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_7_YHSC4_1346T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_7_YHSC4_1346T) */

#define Com_SGLeftDspObjInfo_7_YHSC4_1346T ComConf_ComSignal_SGLeftDspObjInfo_7_YHSC4_1346T


#if (defined Com_SGRightDspObjInfo_7_CounterHSC4_1346T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_7_CounterHSC4_1346T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_7_CounterHSC4_1346T) */

#define Com_SGRightDspObjInfo_7_CounterHSC4_1346T ComConf_ComSignal_SGRightDspObjInfo_7_CounterHSC4_1346T


#if (defined Com_SGRightDspObjInfo_7_ThetaHSC4_1346T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_7_ThetaHSC4_1346T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_7_ThetaHSC4_1346T) */

#define Com_SGRightDspObjInfo_7_ThetaHSC4_1346T ComConf_ComSignal_SGRightDspObjInfo_7_ThetaHSC4_1346T


#if (defined Com_SGRightDspObjInfo_7_TypeHSC4_1346T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_7_TypeHSC4_1346T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_7_TypeHSC4_1346T) */

#define Com_SGRightDspObjInfo_7_TypeHSC4_1346T ComConf_ComSignal_SGRightDspObjInfo_7_TypeHSC4_1346T


#if (defined Com_SGRightDspObjInfo_7_XHSC4_1346T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_7_XHSC4_1346T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_7_XHSC4_1346T) */

#define Com_SGRightDspObjInfo_7_XHSC4_1346T ComConf_ComSignal_SGRightDspObjInfo_7_XHSC4_1346T


#if (defined Com_SGRightDspObjInfo_7_YHSC4_1346T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_7_YHSC4_1346T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_7_YHSC4_1346T) */

#define Com_SGRightDspObjInfo_7_YHSC4_1346T ComConf_ComSignal_SGRightDspObjInfo_7_YHSC4_1346T


#if (defined Com_SGDspObjInfo_545_Counter_1349T) /* To prevent double declaration */
#error Com_SGDspObjInfo_545_Counter_1349T already defined
#endif /* #if (defined Com_SGDspObjInfo_545_Counter_1349T) */

#define Com_SGDspObjInfo_545_Counter_1349T ComConf_ComSignal_SGDspObjInfo_545_Counter_1349T


#if (defined Com_SGLeftDspObjInfo_545_4_DspMode_1349T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_545_4_DspMode_1349T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_545_4_DspMode_1349T) */

#define Com_SGLeftDspObjInfo_545_4_DspMode_1349T ComConf_ComSignal_SGLeftDspObjInfo_545_4_DspMode_1349T


#if (defined Com_SGLeftDspObjInfo_545_4_ID_1349T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_545_4_ID_1349T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_545_4_ID_1349T) */

#define Com_SGLeftDspObjInfo_545_4_ID_1349T ComConf_ComSignal_SGLeftDspObjInfo_545_4_ID_1349T


#if (defined Com_SGLeftDspObjInfo_545_5_DspMode_1349T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_545_5_DspMode_1349T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_545_5_DspMode_1349T) */

#define Com_SGLeftDspObjInfo_545_5_DspMode_1349T ComConf_ComSignal_SGLeftDspObjInfo_545_5_DspMode_1349T


#if (defined Com_SGLeftDspObjInfo_545_5_ID_1349T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_545_5_ID_1349T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_545_5_ID_1349T) */

#define Com_SGLeftDspObjInfo_545_5_ID_1349T ComConf_ComSignal_SGLeftDspObjInfo_545_5_ID_1349T


#if (defined Com_SGLeftDspObjInfo_545_6_DspMode_1349T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_545_6_DspMode_1349T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_545_6_DspMode_1349T) */

#define Com_SGLeftDspObjInfo_545_6_DspMode_1349T ComConf_ComSignal_SGLeftDspObjInfo_545_6_DspMode_1349T


#if (defined Com_SGLeftDspObjInfo_545_6_ID_1349T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_545_6_ID_1349T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_545_6_ID_1349T) */

#define Com_SGLeftDspObjInfo_545_6_ID_1349T ComConf_ComSignal_SGLeftDspObjInfo_545_6_ID_1349T


#if (defined Com_SGLeftDspObjInfo_545_7_DspMode_1349T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_545_7_DspMode_1349T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_545_7_DspMode_1349T) */

#define Com_SGLeftDspObjInfo_545_7_DspMode_1349T ComConf_ComSignal_SGLeftDspObjInfo_545_7_DspMode_1349T


#if (defined Com_SGLeftDspObjInfo_545_7_ID_1349T) /* To prevent double declaration */
#error Com_SGLeftDspObjInfo_545_7_ID_1349T already defined
#endif /* #if (defined Com_SGLeftDspObjInfo_545_7_ID_1349T) */

#define Com_SGLeftDspObjInfo_545_7_ID_1349T ComConf_ComSignal_SGLeftDspObjInfo_545_7_ID_1349T


#if (defined Com_SGRightDspObjInfo_545_4_DspMode_1349T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_545_4_DspMode_1349T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_545_4_DspMode_1349T) */

#define Com_SGRightDspObjInfo_545_4_DspMode_1349T ComConf_ComSignal_SGRightDspObjInfo_545_4_DspMode_1349T


#if (defined Com_SGRightDspObjInfo_545_4_ID_1349T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_545_4_ID_1349T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_545_4_ID_1349T) */

#define Com_SGRightDspObjInfo_545_4_ID_1349T ComConf_ComSignal_SGRightDspObjInfo_545_4_ID_1349T


#if (defined Com_SGRightDspObjInfo_545_5_DspMode_1349T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_545_5_DspMode_1349T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_545_5_DspMode_1349T) */

#define Com_SGRightDspObjInfo_545_5_DspMode_1349T ComConf_ComSignal_SGRightDspObjInfo_545_5_DspMode_1349T


#if (defined Com_SGRightDspObjInfo_545_5_ID_1349T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_545_5_ID_1349T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_545_5_ID_1349T) */

#define Com_SGRightDspObjInfo_545_5_ID_1349T ComConf_ComSignal_SGRightDspObjInfo_545_5_ID_1349T


#if (defined Com_SGRightDspObjInfo_545_6_DspMode_1349T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_545_6_DspMode_1349T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_545_6_DspMode_1349T) */

#define Com_SGRightDspObjInfo_545_6_DspMode_1349T ComConf_ComSignal_SGRightDspObjInfo_545_6_DspMode_1349T


#if (defined Com_SGRightDspObjInfo_545_6_ID_1349T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_545_6_ID_1349T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_545_6_ID_1349T) */

#define Com_SGRightDspObjInfo_545_6_ID_1349T ComConf_ComSignal_SGRightDspObjInfo_545_6_ID_1349T


#if (defined Com_SGRightDspObjInfo_545_7_DspMode_1349T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_545_7_DspMode_1349T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_545_7_DspMode_1349T) */

#define Com_SGRightDspObjInfo_545_7_DspMode_1349T ComConf_ComSignal_SGRightDspObjInfo_545_7_DspMode_1349T


#if (defined Com_SGRightDspObjInfo_545_7_ID_1349T) /* To prevent double declaration */
#error Com_SGRightDspObjInfo_545_7_ID_1349T already defined
#endif /* #if (defined Com_SGRightDspObjInfo_545_7_ID_1349T) */

#define Com_SGRightDspObjInfo_545_7_ID_1349T ComConf_ComSignal_SGRightDspObjInfo_545_7_ID_1349T


/* External Rx Group Signal IDs defines */
/* External Tx Group Signal IDs defines */
/* External Rx Signal Group IDs defines */
/* External Tx Signal Group IDs defines */
#endif /* (defined COM_PROVIDE_LEGACY_SYMBOLIC_NAMES) */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/** @} doxygen end group definition */
#endif /* ifndef COM_SYMBOLIC_NAMES_PB_CFG_H  */
/*==================[end of file]===========================================*/
