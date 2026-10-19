/**
 * \file
 *
 * \brief AUTOSAR EthIf
 *
 * This file contains the implementation of the AUTOSAR
 * module EthIf.
 *
 * \version 1.9.20
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef ETHIF_DRVTYPES_H
#define ETHIF_DRVTYPES_H





#include <EthIf_Cfg.h>

#include <Eth.h>              /* AUTOSAR Eth controller driver header file inclusion */



/*==================[macros]=================================================*/

/* --- Eth controller function definitions---------------------------------- */

#if (defined ETHIF_ETH_GETCONTROLLERMODE)
#error ETHIF_ETH_GETCONTROLLERMODE is already defined
#endif
#define ETHIF_ETH_GETCONTROLLERMODE(PhyCtrlPtr, CtrlModePtr) \
Eth_GetControllerMode((PhyCtrlPtr)->EthCtrlIdx, (CtrlModePtr))

#if (defined ETHIF_ETH_GETPHYSADDR)
#error ETHIF_ETH_GETPHYSADDR is already defined
#endif
#define ETHIF_ETH_GETPHYSADDR(PhyCtrlPtr, PhysAddrPtr) \
Eth_GetPhysAddr((PhyCtrlPtr)->EthCtrlIdx, (PhysAddrPtr))

#if (defined ETHIF_ETH_PROVIDETXBUFFER)
#error ETHIF_ETH_PROVIDETXBUFFER is already defined
#endif
#define ETHIF_ETH_PROVIDETXBUFFER(PhyCtrlPtr, Priority, BufIdxPtr, BufPtr, LenBytePtr) \
Eth_ProvideTxBuffer((PhyCtrlPtr)->EthCtrlIdx, (Priority), (BufIdxPtr), (BufPtr), (LenBytePtr))

#if (defined ETHIF_ETH_READMII)
#error ETHIF_ETH_READMII is already defined
#endif
#define ETHIF_ETH_READMII(PhyCtrlPtr, TrcvIdx, RegIdx, RegValPtr) \
Eth_ReadMii((PhyCtrlPtr)->EthCtrlIdx, (TrcvIdx), (RegIdx), (RegValPtr))

#if (defined ETHIF_ETH_WRITEMII)
#error ETHIF_ETH_WRITEMII is already defined
#endif
#define ETHIF_ETH_WRITEMII(PhyCtrlPtr, TrcvIdx, RegIdx, RegVal) \
Eth_WriteMii((PhyCtrlPtr)->EthCtrlIdx, (TrcvIdx), (RegIdx), (RegVal))

#if (defined ETHIF_ETH_RECEIVE)
#error ETHIF_ETH_RECEIVE is already defined
#endif
#define ETHIF_ETH_RECEIVE(PhyCtrlPtr, FifoIdx, RxStatus) \
Eth_Receive((PhyCtrlPtr)->EthCtrlIdx, (FifoIdx), (RxStatus))

#if (defined ETHIF_ETH_SETCONTROLLERMODE)
#error ETHIF_ETH_SETCONTROLLERMODE is already defined
#endif
#define ETHIF_ETH_SETCONTROLLERMODE(PhyCtrlPtr, CtrlMode) \
Eth_SetControllerMode((PhyCtrlPtr)->EthCtrlIdx, (CtrlMode))

#if (defined ETHIF_ETH_TRANSMIT)
#error ETHIF_ETH_TRANSMIT is already defined
#endif
#define ETHIF_ETH_TRANSMIT(PhyCtrlPtr, BufIdx, FrameType, TxConfirmation, LenByte, PhysAddrPtr) \
Eth_Transmit((PhyCtrlPtr)->EthCtrlIdx, (BufIdx), (FrameType), (TxConfirmation), (LenByte), \
PhysAddrPtr)

#if (defined ETHIF_ETH_TXCONFIRMATON)
#error ETHIF_ETH_TXCONFIRMATON is already defined
#endif
#define ETHIF_ETH_TXCONFIRMATON(PhyCtrlPtr) \
Eth_TxConfirmation((PhyCtrlPtr)->EthCtrlIdx)

#if (defined ETHIF_ETH_SETPHYADDR)
#error ETHIF_ETH_SETPHYADDR is already defined
#endif
#define ETHIF_ETH_SETPHYADDR(PhyCtrlPtr, PhysAddrPtr) \
Eth_SetPhysAddr((PhyCtrlPtr)->EthCtrlIdx, (PhysAddrPtr))

#if (defined ETHIF_ETH_UPDATEPHYADDRFILTER)
#error ETHIF_ETH_UPDATEPHYADDRFILTER is already defined
#endif
#define ETHIF_ETH_UPDATEPHYADDRFILTER(PhyCtrlPtr, PhysAddrPtr, Action) \
Eth_UpdatePhysAddrFilter((PhyCtrlPtr)->EthCtrlIdx, (PhysAddrPtr), (Action))

#if (defined ETHIF_ETH_GETCURRENTTIME)
#error ETHIF_ETH_GETCURRENTTIME is already defined
#endif
#define ETHIF_ETH_GETCURRENTTIME(PhyCtrlPtr, TimeQualPtr, TimeStampPtr) \
Eth_GetCurrentTime((PhyCtrlPtr)->EthCtrlIdx, (TimeQualPtr), (TimeStampPtr))

#if (defined ETHIF_ETH_ENABLEEGRESSTIMESTAMP)
#error ETHIF_ETH_ENABLEEGRESSTIMESTAMP is already defined
#endif
#define ETHIF_ETH_ENABLEEGRESSTIMESTAMP(PhyCtrlPtr, BufIdx) \
Eth_EnableEgressTimeStamp((PhyCtrlPtr)->EthCtrlIdx, (BufIdx))

#if (defined ETHIF_ETH_GETEGRESSTIMESTAMP)
#error ETHIF_ETH_GETEGRESSTIMESTAMP is already defined
#endif
#define ETHIF_ETH_GETEGRESSTIMESTAMP(PhyCtrlPtr, BufIdx, TimeQualPtr, TimeStampPtr) \
Eth_GetEgressTimeStamp((PhyCtrlPtr)->EthCtrlIdx, (BufIdx), (TimeQualPtr), (TimeStampPtr))

#if (defined ETHIF_ETH_GETINGRESSTIMESTAMP)
#error ETHIF_ETH_GETINGRESSTIMESTAMP is already defined
#endif
#define ETHIF_ETH_GETINGRESSTIMESTAMP(PhyCtrlPtr, DataPtr, TimeQualPtr, TimeStampPtr) \
Eth_GetIngressTimeStamp((PhyCtrlPtr)->EthCtrlIdx, (DataPtr), (TimeQualPtr), (TimeStampPtr))

#if (defined ETHIF_ETH_SETCORRECTIONTIME)
#error ETHIF_ETH_SETCORRECTIONTIME is already defined
#endif
#define ETHIF_ETH_SETCORRECTIONTIME(PhyCtrlPtr, TimeOffsetPtr, RateRatioPtr) \
Eth_SetCorrectionTime((PhyCtrlPtr)->EthCtrlIdx, (TimeOffsetPtr), (RateRatioPtr))

#if (defined ETHIF_ETH_SETGLOBALTIME)
#error ETHIF_ETH_SETGLOBALTIME is already defined
#endif
#define ETHIF_ETH_SETGLOBALTIME(PhyCtrlPtr, TimeStampPtr) \
Eth_SetGlobalTime((PhyCtrlPtr)->EthCtrlIdx, (TimeStampPtr))

#if (defined ETHIF_ETH_RETRANSMIT)
#error ETHIF_ETH_RETRANSMIT is already defined
#endif
#define ETHIF_ETH_RETRANSMIT(PhyCtrlPtr, OrigCtrlIdx, BufIdxPtr, DataPtr, FrameType, \
LenByte, RetransmitInfoPtr) Eth_Retransmit((PhyCtrlPtr)->EthCtrlIdx,(OrigCtrlIdx), (BufIdxPtr), \
(DataPtr), (FrameType), (LenByte), (RetransmitInfoPtr))

/* --- Eth transceiver function definitions---------------------------------- */

#if (defined ETHIF_ETHTRCV_SETPHYLOOPBACKMODE)
#error ETHIF_ETHTRCV_SETPHYLOOPBACKMODE is already defined
#endif
#define ETHIF_ETHTRCV_SETPHYLOOPBACKMODE(EthIfTrvcPtr, Mode) \
EthTrcv_SetPhyLoopbackMode((EthIfTrvcPtr)->EthTrcvIdx, (Mode))

#if (defined ETHIF_ETHTRCV_SETPHYTXMODE)
#error ETHIF_ETHTRCV_SETPHYTXMODE is already defined
#endif
#define ETHIF_ETHTRCV_SETPHYTXMODE(EthIfTrvcPtr, Mode) \
EthTrcv_SetPhyTxMode((EthIfTrvcPtr)->EthTrcvIdx, (Mode))

#if (defined ETHIF_ETHTRCV_GETPHYSIGQUAL)
#error ETHIF_ETHTRCV_GETPHYSIGQUAL is already defined
#endif
#define ETHIF_ETHTRCV_GETPHYSIGQUAL(EthIfTrvcPtr, SignalQualityPtr) \
EthTrcv_GetPhySignalQuality((EthIfTrvcPtr)->EthTrcvIdx, (SignalQualityPtr))

#if (defined ETHIF_ETHTRCV_GETCABLEDIAGRESULT)
#error ETHIF_ETHTRCV_GETCABLEDIAGRESULT is already defined
#endif
#define ETHIF_ETHTRCV_GETCABLEDIAGRESULT(EthIfTrvcPtr, ResultPtr) \
EthTrcv_GetCableDiagnosticsResult((EthIfTrvcPtr)->EthTrcvIdx, (ResultPtr))

#if (defined ETHIF_ETHTRCV_GETPHYIDENTIFIER)
#error ETHIF_ETHTRCV_GETPHYIDENTIFIER is already defined
#endif
#define ETHIF_ETHTRCV_GETPHYIDENTIFIER(EthIfTrvcPtr, OrgUniqueIdPtr, ModelNrPtr, RevisionNrPtr) \
EthTrcv_GetPhyIdentifier((EthIfTrvcPtr)->EthTrcvIdx, (OrgUniqueIdPtr), (ModelNrPtr), (RevisionNrPtr))

#if (defined ETHIF_ETHTRCV_SETPHYTESTMODE)
#error ETHIF_ETHTRCV_SETPHYTESTMODE is already defined
#endif
#define ETHIF_ETHTRCV_SETPHYTESTMODE(EthIfTrvcPtr, Mode) \
EthTrcv_SetPhyTestMode((EthIfTrvcPtr)->EthTrcvIdx, (Mode))

#if (defined ETHIF_ETHTRCV_SETTRCVWAKEUPMODE)
#error ETHIF_ETHTRCV_SETTRCVWAKEUPMODE is already defined
#endif
#define ETHIF_ETHTRCV_SETTRCVWAKEUPMODE(EthIfTrvcPtr, TrcvWakeupMode) \
EthTrcv_SetTransceiverWakeupMode((EthIfTrvcPtr)->EthTrcvIdx, (TrcvWakeupMode))

#if (defined ETHIF_ETHTRCV_GETTRCVWAKEUPMODE)
#error ETHIF_ETHTRCV_GETTRCVWAKEUPMODE is already defined
#endif
#define ETHIF_ETHTRCV_GETTRCVWAKEUPMODE(EthIfTrvcPtr, TrcvWakeupModePtr) \
EthTrcv_GetTransceiverWakeupMode((EthIfTrvcPtr)->EthTrcvIdx, (TrcvWakeupModePtr))

#if (defined ETHIF_ETHTRCV_CHECKWAKEUP)
#error ETHIF_ETHTRCV_CHECKWAKEUP is already defined
#endif
#define ETHIF_ETHTRCV_CHECKWAKEUP(EthIfTrvcPtr) \
EthTrcv_CheckWakeup((EthIfTrvcPtr)->EthTrcvIdx)

#if (defined ETHIF_ETHTRCV_SETTRCVMODE)
#error ETHIF_ETHTRCV_SETTRCVMODE is already defined
#endif
#define ETHIF_ETHTRCV_SETTRCVMODE(EthIfTrvcPtr, CtrlMode) \
EthTrcv_SetTransceiverMode((EthIfTrvcPtr)->EthTrcvIdx, (CtrlMode))

#if (defined ETHIF_ETHTRCV_GETTRCVMODE)
#error ETHIF_ETHTRCV_GETTRCVMODE is already defined
#endif
#define ETHIF_ETHTRCV_GETTRCVMODE(EthIfTrvcPtr, TrcvModePtr) \
EthTrcv_GetTransceiverMode((EthIfTrvcPtr)->EthTrcvIdx, (TrcvModePtr))

#if (defined ETHIF_ETHTRCV_GETLINKSTATE)
#error ETHIF_ETHTRCV_GETLINKSTATE is already defined
#endif
#define ETHIF_ETHTRCV_GETLINKSTATE(EthIfTrvcPtr, LinkStatePtr) \
EthTrcv_GetLinkState((EthIfTrvcPtr)->EthTrcvIdx, (LinkStatePtr))

#if (defined ETHIF_ETHTRCV_RUNCABLEDIAG)
#error ETHIF_ETHTRCV_RUNCABLEDIAG is already defined
#endif
#define ETHIF_ETHTRCV_RUNCABLEDIAG(EthIfTrvcPtr) \
EthTrcv_RunCableDiagnostic((EthIfTrvcPtr)->EthTrcvIdx)

/* --- Eth switch function definitions---------------------------------- */

#if (defined ETHIF_ETHSWT_TXADAPTFRAMETYPEBFLEN)
#error ETHIF_ETHSWT_TXADAPTFRAMETYPEBFLEN is already defined
#endif
#define ETHIF_ETHSWT_TXADAPTFRAMETYPEBFLEN(CtrlIdx, FrameTypePtr, LenBytePtr) \
EthSwt_EthIfTxAdaptFrameTypeBufferLength((CtrlIdx), (FrameTypePtr), (LenBytePtr))

#if (defined ETHIF_ETHSWT_PREPROCESSRXFRAME)
#error ETHIF_ETHSWT_PREPROCESSRXFRAME is already defined
#endif
#define ETHIF_ETHSWT_PREPROCESSRXFRAME(CtrlIdx, DataPtrPtr, LenPtr, PhysAddrPtr, FrameTypePtr) \
EthSwt_EthIfPreProcessRxFrame((CtrlIdx), (DataPtrPtr), (LenPtr), (PhysAddrPtr), (FrameTypePtr))

#if (defined ETHIF_ETHSWT_PREPROCESSTXFRAME)
#error ETHIF_ETHSWT_PREPROCESSTXFRAME is already defined
#endif
#define ETHIF_ETHSWT_PREPROCESSTXFRAME(CtrlIdx, FrameType, Priority, BufIdx, BufPtrPtr, \
LenBytePtr) EthSwt_EthIfPreProcessTxFrame((CtrlIdx), (FrameType), (Priority), (BufIdx), \
(BufPtrPtr), (LenBytePtr))

#if (defined ETHIF_ETHSWT_GETPORTSIGNALQUALITY)
#error ETHIF_ETHSWT_GETPORTSIGNALQUALITY is already defined
#endif
#define ETHIF_ETHSWT_GETPORTSIGNALQUALITY(SwitchIdx, SwitchPortIdx, SignalQualityPtr) \
EthSwt_GetPortSignalQuality((SwitchIdx), (SwitchPortIdx), (SignalQualityPtr))

#if (defined ETHIF_ETHSWT_GETARLTABLE)
#error ETHIF_ETHSWT_GETARLTABLE is already defined
#endif
#define ETHIF_ETHSWT_GETARLTABLE(SwitchIdx, numberOfElements, ArlTable) \
EthSwt_GetArlTable((SwitchIdx), (numberOfElements), (ArlTable))

#if (defined ETHIF_ETHSWT_GETBUFFLEVEL)
#error ETHIF_ETHSWT_GETBUFFLEVEL is already defined
#endif
#define ETHIF_ETHSWT_GETBUFFLEVEL(SwitchIdx, SwitchBufferLevelPtr) \
EthSwt_GetBufferLevel((SwitchIdx), (SwitchBufferLevelPtr))

#if (defined ETHIF_ETHSWT_GETCOUNTERVALUES)
#error ETHIF_ETHSWT_GETCOUNTERVALUES is already defined
#endif
#define ETHIF_ETHSWT_GETCOUNTERVALUES(SwitchIdx, SwitchPortIdx, CounterPtr) \
EthSwt_GetCounterValues((SwitchIdx), (SwitchPortIdx), (CounterPtr))

#if (defined ETHIF_ETHSWT_STORECONFIG)
#error ETHIF_ETHSWT_STORECONFIG is already defined
#endif
#define ETHIF_ETHSWT_STORECONFIG(SwitchIdx) EthSwt_StoreConfiguration((SwitchIdx))

#if (defined ETHIF_ETHSWT_RESETCONFIG)
#error ETHIF_ETHSWT_RESETCONFIG is already defined
#endif
#define ETHIF_ETHSWT_RESETCONFIG(SwitchIdx) EthSwt_ResetConfiguration((SwitchIdx))

#if (defined ETHIF_ETHSWT_SETSWITCHPORTMODE)
#error ETHIF_ETHSWT_SETSWITCHPORTMODE is already defined
#endif
#define ETHIF_ETHSWT_SETSWITCHPORTMODE(SwitchIdx, SwitchPortIdx, PortMode) \
EthSwt_SetSwitchPortMode((SwitchIdx), (SwitchPortIdx), (PortMode))

#if (defined ETHIF_ETHSWT_GETLINKSTATE)
#error ETHIF_ETHSWT_GETLINKSTATE is already defined
#endif
#define ETHIF_ETHSWT_GETLINKSTATE(SwitchIdx, SwitchPortIdx, LinkStatePtr) \
EthSwt_GetLinkState((SwitchIdx), (SwitchPortIdx), (LinkStatePtr))

#if (defined ETHIF_ETHSWT_PORTRUNCABLEDIAG)
#error ETHIF_ETHSWT_PORTRUNCABLEDIAG is already defined
#endif
#define ETHIF_ETHSWT_PORTRUNCABLEDIAG(SwitchIdx, PortIdx) \
EthSwt_PortRunCableDiagnostic((SwitchIdx), (PortIdx))

/*==================[type definitions]=======================================*/





#endif /* ifndef ETHIF_DRVTYPES_H */
/*==================[end of file]============================================*/
