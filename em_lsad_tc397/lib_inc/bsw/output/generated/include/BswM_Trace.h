
#ifndef BSWM_TRACE_H
#define BSWM_TRACE_H

/**
 * \file
 *
 * \brief AUTOSAR BswM
 *
 * This file contains the implementation of the AUTOSAR
 * module BswM.
 *
 * \version 1.15.8
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

 /* \addtogroup Mode Management Stack
  * @{ */

/*==================[inclusions]============================================*/

/*==================[macros]================================================*/
#ifndef DBG_BSWM_INIT_ENTRY
/** \brief Entry point of function BswM_Init */
#define DBG_BSWM_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_INIT_EXIT
/** \brief Exit point of function BswM_Init */
#define DBG_BSWM_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_ENTRY
/** \brief Entry point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_ENTRY(a)
#endif

#ifndef DBG_BSWM_GETVERSIONINFO_EXIT
/** \brief Exit point of function BswM_GetVersionInfo */
#define DBG_BSWM_GETVERSIONINFO_EXIT(a)
#endif

#ifndef DBG_BSWM_DEINIT_ENTRY
/** \brief Entry point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_ENTRY()
#endif

#ifndef DBG_BSWM_DEINIT_EXIT
/** \brief Exit point of function BswM_Deinit */
#define DBG_BSWM_DEINIT_EXIT()
#endif

#ifndef DBG_BSWM_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_RequestMode */
#define DBG_BSWM_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentMode */
#define DBG_BSWM_COMM_CURRENTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY
/** \brief Entry point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_COMM_CURRENTPNCMODE_EXIT
/** \brief Exit point of function BswM_ComM_CurrentPNCMode */
#define DBG_BSWM_COMM_CURRENTPNCMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestCommunicationMode */
#define DBG_BSWM_DCM_REQUESTCOMMUNICATIONMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Dcm_CommunicationMode_CurrentState */
#define DBG_BSWM_DCM_COMMUNICATIONMODE_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestSessionMode */
#define DBG_BSWM_DCM_REQUESTSESSIONMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY
/** \brief Entry point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_ENTRY(a)
#endif

#ifndef DBG_BSWM_DCM_REQUESTRESETMODE_EXIT
/** \brief Exit point of function BswM_Dcm_RequestResetMode */
#define DBG_BSWM_DCM_REQUESTRESETMODE_EXIT(a)
#endif

#ifndef DBG_BSWM_DCM_APPLICATIONUPDATED_ENTRY
/** \brief Exit point of function BswM_Dcm_ApplicationUpdated */
#define DBG_BSWM_DCM_APPLICATIONUPDATED_ENTRY()
#endif

#ifndef DBG_BSWM_DCM_APPLICATIONUPDATED_EXIT
/** \brief Exit point of function BswM_Dcm_ApplicationUpdated */
#define DBG_BSWM_DCM_APPLICATIONUPDATED_EXIT()
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_CANSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_CanSM_CurrentState */
#define DBG_BSWM_CANSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_ENTRY
/** \brief Entry point of function BswM_EthIf_PortGroupLinkStateChg */
#define DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_EXIT
/** \brief Exit point of function BswM_EthIf_PortGroupLinkStateChg */
#define DBG_BSWM_ETHIF_PORTGROUPLINKSTATECHG_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ETHSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EthSM_CurrentState */
#define DBG_BSWM_ETHSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_FRSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_FrSM_CurrentState */
#define DBG_BSWM_FRSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentState */
#define DBG_BSWM_LINSM_CURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_ENTRY(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTSTATE_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentState */
#define DBG_BSWM_ECUM_CURRENTSTATE_EXIT(a)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY
/** \brief Entry point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT
/** \brief Exit point of function BswM_EcuM_CurrentWakeup */
#define DBG_BSWM_ECUM_CURRENTWAKEUP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NMIF_CARWAKEUPINDICATION_ENTRY
/** \brief Entry point of function BswM_NmIf_CarWakeUpIndication */
#define DBG_BSWM_NMIF_CARWAKEUPINDICATION_ENTRY(a)
#endif

#ifndef DBG_BSWM_NMIF_CARWAKEUPINDICATION_EXIT
/** \brief Exit point of function BswM_NmIf_CarWakeUpIndication */
#define DBG_BSWM_NMIF_CARWAKEUPINDICATION_EXIT(a)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentBlockMode */
#define DBG_BSWM_NVM_CURRENTBLOCKMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY
/** \brief Entry point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_NVM_CURRENTJOBMODE_EXIT
/** \brief Exit point of function BswM_NvM_CurrentJobMode */
#define DBG_BSWM_NVM_CURRENTJOBMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY
/** \brief Entry point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT
/** \brief Exit point of function BswM_LinSM_CurrentSchedule */
#define DBG_BSWM_LINSM_CURRENTSCHEDULE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_ENTRY
/** \brief Entry point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_LINTP_REQUESTMODE_EXIT
/** \brief Exit point of function BswM_LinTp_RequestMode */
#define DBG_BSWM_LINTP_REQUESTMODE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ClientServiceCurrentState */
#define DBG_BSWM_SD_CLIENTSERVICECURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_ConsumedEventGroupCurrentState */
#define DBG_BSWM_SD_CONSUMEDEVENTGROUPCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY
/** \brief Entry point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_ENTRY(a,b)
#endif

#ifndef DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT
/** \brief Exit point of function BswM_Sd_EventHandlerCurrentState */
#define DBG_BSWM_SD_EVENTHANDLERCURRENTSTATE_EXIT(a,b)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY
/** \brief Entry point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_ENTRY(a)
#endif

#ifndef DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT
/** \brief Exit point of function BswM_WdgM_RequestPartitionReset */
#define DBG_BSWM_WDGM_REQUESTPARTITIONRESET_EXIT(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY
/** \brief Entry point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT
/** \brief Exit point of function BswM_TriggerStartUpPhase2 */
#define DBG_BSWM_TRIGGERSTARTUPPHASE2_EXIT(a,b)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY
/** \brief Entry point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_ENTRY(a)
#endif

#ifndef DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT
/** \brief Exit point of function BswM_TriggerSlaveRTEStop */
#define DBG_BSWM_TRIGGERSLAVERTESTOP_EXIT(a,b)
#endif

#ifndef DBG_BSWM_MAINFUNCTION_ENTRY
/** \brief Entry point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_ENTRY()
#endif

#ifndef DBG_BSWM_MAINFUNCTION_EXIT
/** \brief Exit point of function BswM_MainFunction */
#define DBG_BSWM_MAINFUNCTION_EXIT()
#endif

#ifndef DBG_BSWM_CORE_INIT_ENTRY
/** \brief Entry point of function BswM_Core_Init */
#define DBG_BSWM_CORE_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_CORE_INIT_EXIT
/** \brief Exit point of function BswM_Core_Init */
#define DBG_BSWM_CORE_INIT_EXIT()
#endif

#ifndef DBG_BSWM_PARTITION_INIT_ENTRY
/** \brief Entry point of function BswM_Partition_Init */
#define DBG_BSWM_PARTITION_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_PARTITION_INIT_EXIT
/** \brief Exit point of function BswM_Partition_Init */
#define DBG_BSWM_PARTITION_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_PB_INIT_ENTRY
/** \brief Entry point of function BswM_PB_Init */
#define DBG_BSWM_PB_INIT_ENTRY(a,b,c)
#endif

#ifndef DBG_BSWM_PB_INIT_EXIT
/** \brief Exit point of function BswM_PB_Init */
#define DBG_BSWM_PB_INIT_EXIT(a,b,c,d)
#endif

#ifndef DBG_BSWM_RT_INIT_ENTRY
/** \brief Entry point of function BswM_RT_Init */
#define DBG_BSWM_RT_INIT_ENTRY(a)
#endif

#ifndef DBG_BSWM_RT_INIT_EXIT
/** \brief Exit point of function BswM_RT_Init */
#define DBG_BSWM_RT_INIT_EXIT(a)
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C0_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C0_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C0_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C0_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C0_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C0_INIT_EXIT()
#endif
#ifndef DBG_BSWM_LT_OSAPPLICATION_C1_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C1_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C1_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C1_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C1_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C1_INIT_EXIT()
#endif
#ifndef DBG_BSWM_LT_OSAPPLICATION_C2_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C2_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C2_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C2_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C2_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C2_INIT_EXIT()
#endif
#ifndef DBG_BSWM_LT_OSAPPLICATION_C3_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C3_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C3_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C3_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C3_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C3_INIT_EXIT()
#endif
#ifndef DBG_BSWM_LT_OSAPPLICATION_C4_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C4_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C4_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C4_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C4_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C4_INIT_EXIT()
#endif
#ifndef DBG_BSWM_LT_OSAPPLICATION_C5_INIT_ENTRY
/** \brief Entry point of function BswM_LT_OsApplication_C5_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C5_INIT_ENTRY()
#endif

#ifndef DBG_BSWM_LT_OSAPPLICATION_C5_INIT_EXIT
/** \brief Exit point of function BswM_LT_OsApplication_C5_Init */
#define DBG_BSWM_LT_OSAPPLICATION_C5_INIT_EXIT()
#endif

/* Dynamically generated macros */
#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_ETHFULLCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_EthFullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_ETHFULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_ETHFULLCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_EthFullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_ETHFULLCOM_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_CanFullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_CanFullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_CANFULLCOM_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_ETHNOCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_EthNoCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_ETHNOCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_ETHNOCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_EthNoCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_ETHNOCOM_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_GoOffOneA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_GoOffOneA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEA_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_GoOffOneB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_GoOffOneB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_GOOFFONEB_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PRPSHUTDOWN_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_PrpShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PRPSHUTDOWN_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PRPSHUTDOWN_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_PrpShutdown */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_PRPSHUTDOWN_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RequestRunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RequestRunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTRUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTWAKEUPTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RequestWakeupTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTWAKEUPTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTWAKEUPTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RequestWakeupTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_REQUESTWAKEUPTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RESTARTCOMMFULLCOM_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RestartComMFullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RESTARTCOMMFULLCOM_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RESTARTCOMMFULLCOM_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RestartComMFullCom */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RESTARTCOMMFULLCOM_EXIT(a)
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_RunTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_RUNTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_StartupTwoA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_StartupTwoA */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOA_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_StartupTwoB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_StartupTwoB */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_STARTUPTWOB_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_WAKEUPTWO_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C0_BswM_Act_WakeupTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_WAKEUPTWO_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_WAKEUPTWO_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C0_BswM_Act_WakeupTwo */
#define DBG_BSWM_ACTION_OSAPPLICATION_C0_BSWM_ACT_WAKEUPTWO_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUP_C1_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C1_BswM_Act_StartUp_C1 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUP_C1_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUP_C1_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C1_BswM_Act_StartUp_C1 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C1_BSWM_ACT_STARTUP_C1_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUP_C2_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C2_BswM_Act_StartUp_C2 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUP_C2_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUP_C2_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C2_BswM_Act_StartUp_C2 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C2_BSWM_ACT_STARTUP_C2_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUP_C3_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C3_BswM_Act_StartUp_C3 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUP_C3_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUP_C3_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C3_BswM_Act_StartUp_C3 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C3_BSWM_ACT_STARTUP_C3_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C4_BSWM_ACT_STARTUP_C4_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C4_BswM_Act_StartUp_C4 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C4_BSWM_ACT_STARTUP_C4_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C4_BSWM_ACT_STARTUP_C4_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C4_BswM_Act_StartUp_C4 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C4_BSWM_ACT_STARTUP_C4_EXIT()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C5_BSWM_ACT_STARTUP_C5_ENTRY
/** \brief Entry point of function BswM_Action_OsApplication_C5_BswM_Act_StartUp_C5 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C5_BSWM_ACT_STARTUP_C5_ENTRY()
#endif

#ifndef DBG_BSWM_ACTION_OSAPPLICATION_C5_BSWM_ACT_STARTUP_C5_EXIT
/** \brief Exit point of function BswM_Action_OsApplication_C5_BswM_Act_StartUp_C5 */
#define DBG_BSWM_ACTION_OSAPPLICATION_C5_BSWM_ACT_STARTUP_C5_EXIT()
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

/*==================[end of file]===========================================*/
/** @} doxygen end group definition */
#endif /* ifndef BSWM_TRACE_H */
/*==================[end of file]============================================*/

