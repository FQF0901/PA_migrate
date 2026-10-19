/**
 * \file
 *
 * \brief AUTOSAR SoAd
 *
 * This file contains the implementation of the AUTOSAR
 * module SoAd.
 *
 * \version 1.8.19
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef SOAD_TYPES_H
#define SOAD_TYPES_H

/*
 * Misra-C:2012 Deviations:
 *
 * MISRA-1) Deviated Rule: 20.5 (required)
 * "#undef shall not be used"
 *
 * Reason:
 * The macros TS_RELOCATABLE_CFG_ENABLE and TS_PB_CFG_PTR_CLASS
 * might be used by more modules than the SoAd module.
 * To avoid that these macros are used by other modules accidentally,
 * an undef is used here.
 */

/*==================[includes]==============================================*/

#include <SoAd_CfgTypes.h>     /* Generated types by XGEN */
#include <TSAutosar.h>         /* EB AUTOSAR standard types */
#include <ComStack_Types.h>    /* Com-stack types */
#include <TcpIp.h>             /* TODO declare SoAd_TcpIp types instead */
#include <SoAd_Cfg.h>          /* module pre-compile config */

#define TS_RELOCATABLE_CFG_ENABLE SOAD_RELOCATABLE_CFG_ENABLE
#define TS_PB_CFG_PTR_CLASS SOAD_APPL_DATA
#include <TSPBConfig_Types.h>

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/
/**
 * SoAd_RingBufferAccessType
 */
typedef struct {
    uint8 *BufPtr; /* BufPtr */
    SoAd_RefToRAM In; /* In */
    SoAd_RefToRAM Out; /* Out */
    SoAd_RefToRAM Size; /* Size */
    SoAd_RefToRAM Used; /* Used */
} SoAd_RingBufferAccessType;

/**
 * SoAd_SoConTxDataType
 */
typedef struct {
    uint8 *ULIfDataPtr; /* ULIfDataPtr */
    SoAd_PduLengthType PduPayloadRemainingLen; /* PduPayloadRemainingLen */
    SoAd_PduLengthType TcpIpTxRemainingLen; /* TcpIpTxRemainingLen */
    SoAd_PduRouteDestVirtualIdType ActivePduRouteDestVirtualId; /* ActivePduRouteDestVirtualId */
    uint8 PduHeaderWrittenLen; /* PduHeaderWrittenLen */
} SoAd_SoConTxDataType;

/**
 * SoAd_PBRAMLayoutType
 */
typedef struct {
    uint32 routingGroupTriggeredBitMap[1]; /* routingGroupTriggeredBitMap */
    SoAd_SoConRxDataType soConRxData[1]; /* soConRxData */
    SoAd_SoConStateType soConState[1]; /* soConState */
    SoAd_SoConTxDataType soConTxData[1]; /* soConTxData */
    uint32 bufferPoolInUseBitMap[1]; /* bufferPoolInUseBitMap */
    uint32 soConTransCondChangeBitMap[1]; /* soConTransCondChangeBitMap */
    uint32 notIdleBitMap[1]; /* notIdleBitMap */
    uint32 rxNotIdleBitMap[1]; /* rxNotIdleBitMap */
    uint32 txTPNotIdleBitMap[1]; /* txTPNotIdleBitMap */
    uint32 txIFNotIdleBitMap[1]; /* txIFNotIdleBitMap */
    uint32 pduRouteDestVirtualTxEnabledBitMap[1]; /* pduRouteDestVirtualTxEnabledBitMap */
    uint32 socketRouteVirtRxDestEnabledBitMap[1]; /* socketRouteVirtRxDestEnabledBitMap */
    SoAd_SoConGroupStateType soConGroupState[1]; /* soConGroupState */
    SoAd_SoConTxTcpDataType soConTxTcpData[1]; /* soConTxTcpData */
    SoAd_SoConTxUdpDataType soConTxUdpData[1]; /* soConTxUdpData */
    SoAd_PduRouteDestVirtualDataType pduTxData[1]; /* pduTxData */
    SoAd_PduTxTcpDataType pduTxTcpData[1]; /* pduTxTcpData */
    SoAd_ListenSocketSoConMapType listenSocketSoConMap[1]; /* listenSocketSoConMap */
    SoAd_SocketSoConMapType socketSoConMap[1]; /* socketSoConMap */
    SoAd_SocketRouteDestIdType soConToSocketRouteDestMap[1]; /* soConToSocketRouteDestMap */
    SoAd_SoConTxBufferStateType soConTxBufferState[1]; /* soConTxBufferState */
    uint8 routingGroupStateBitMap[1]; /* routingGroupStateBitMap */
    uint8 localIpAddrStateBitMap[1]; /* localIpAddrStateBitMap */
    uint8 buffers[1]; /* buffers */
    uint8 triggerTransmitBuffer[1]; /* triggerTransmitBuffer */
} SoAd_PBRAMLayoutType;



/*------------------[function pointer types]--------------------------------*/

/** \brief Function pointer type used for indication functions of interface
 ** modules **/
typedef P2FUNC(void,SOAD_APPL_CODE,SoAd_IfRxIndFpType)
(
    PduIdType RxPduId,
    P2VAR(PduInfoType,AUTOMATIC,SOAD_APPL_DATA) PduInfoPtr
);

/** \brief Function pointer type used for confirmation functions of interface
 ** modules **/
typedef P2FUNC(void,SOAD_APPL_CODE,SoAd_IfTxConfFpType)
(
    PduIdType TxPduId
);

/** \brief Function pointer type used for trigger functions of interface
 ** modules **/
typedef P2FUNC(Std_ReturnType,SOAD_APPL_CODE,SoAd_IfTrigTxFpType)
(
    PduIdType TxPduId,
    P2VAR(PduInfoType,AUTOMATIC,SOAD_APPL_DATA) PduInfoPtr
);

/** \brief Function pointer type used for indication functions
 ** of TP modules **/
typedef P2FUNC(void,SOAD_APPL_CODE,SoAd_TpRxIndFpType)
(
    PduIdType id,
    NotifResultType result
);

/** \brief Function pointer type used for CopyRxData functions of TP
 ** modules **/
typedef P2FUNC(BufReq_ReturnType,SOAD_APPL_CODE,SoAd_TpCopyRxDataFpType)
(
    PduIdType id,
    P2CONST(PduInfoType,AUTOMATIC,SOAD_APPL_CONST) info,
    P2VAR(PduLengthType,AUTOMATIC,SOAD_APPL_DATA) bufferSizePtr
);

/** \brief Function pointer type used for StartOfReception functions of TP
 ** modules **/
typedef P2FUNC(BufReq_ReturnType,SOAD_APPL_CODE,SoAd_TpStartOfReceptionFpType)
(
    PduIdType id,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType,AUTOMATIC,SOAD_APPL_DATA) bufferSizePtr
);

/** \brief Function pointer type used for CopyTxData functions of TP
 ** modules **/
typedef P2FUNC(BufReq_ReturnType,SOAD_APPL_CODE,SoAd_TpCopyTxDataFpType)
(
    PduIdType id,
    P2VAR(PduInfoType,AUTOMATIC,SOAD_APPL_DATA) info,
    P2VAR(RetryInfoType,AUTOMATIC,SOAD_APPL_DATA) retry,
    P2VAR(PduLengthType,AUTOMATIC,SOAD_APPL_DATA) availableDataPtr
);

/** \brief Function pointer type used for confirmation functions
 ** of TP modules **/
typedef P2FUNC(void,SOAD_APPL_CODE,SoAd_TpTxConfFpType)
(
    PduIdType id,
    NotifResultType result
);

/** \brief Function pointer type used for SoConModeChg functions **/
typedef P2FUNC(void,SOAD_APPL_CODE,SoAd_SoConModeChgFpType)
(
    SoAd_SoConIdType SoConId,
    SoAd_SoConModeType Mode
);

/** \brief Function pointer type used for LocalIpAddrAssignmentChg functions **/
typedef P2FUNC(void,SOAD_APPL_CODE,SoAd_LocalIpAddrAssignmentChgFpType)
(
    SoAd_SoConIdType SoConId,
    TcpIp_IpAddrStateType State
);



/*------------------[Module API table type]---------------------------------*/

/**
 * type for If module API
 */
typedef struct
{
    SoAd_IfTxConfFpType IfTxConfirmation; /**< pointer to x_TxConfirmation() */
    SoAd_IfRxIndFpType IfRxIndication; /**< pointer to x_RxIndication() */
    SoAd_IfTrigTxFpType IfTriggerTransmit; /**< pointer to x_TriggerTransmit() */
} SoAd_IfModuleAPIType;

/**
 * type for Tp module API
 */
typedef struct
{
    SoAd_TpTxConfFpType TpTxConfirmation; /**< pointer to x_TxConfirmation() */
    SoAd_TpRxIndFpType TpRxIndication; /**< pointer to x_RxIndication() */
    SoAd_TpCopyRxDataFpType TpCopyRxData; /**< pointer to x_CopyRxData() */
    SoAd_TpStartOfReceptionFpType TpStartOfReception; /**< pointer to x_StartOfReception() */
    SoAd_TpCopyTxDataFpType TpCopyTxData; /**< pointer to x_CopyTxData() */
} SoAd_TpModuleAPIType;

/**
 * type for notification API
 */
typedef struct
{
    SoAd_SoConModeChgFpType SoConModeChg; /**< pointer to x_SoConModeChg() */
    SoAd_LocalIpAddrAssignmentChgFpType LocalIpAddrAssignmentChg; /**< pointer to x_LocalIpAddrAssignmentChg() */
} SoAd_NotificationAPIType;


/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

/* Deviation MISRA-1 */
#undef TS_RELOCATABLE_CFG_ENABLE
/* Deviation MISRA-1 */
#undef TS_PB_CFG_PTR_CLASS

/** @} doxygen end group definition */
#endif /* ifndef SOAD_TYPES_H  */
/*==================[end of file]===========================================*/
