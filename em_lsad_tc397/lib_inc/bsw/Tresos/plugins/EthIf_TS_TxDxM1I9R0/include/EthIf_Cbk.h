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

#ifndef ETHIF_CBK_H
#define ETHIF_CBK_H

/*==================[inclusions]============================================*/

#include <EthIf_Version.h>     /* Module Version Info */
#include <ComStack_Types.h>
#include <EthIf_Cfg.h>         /* this module's configuration */
#include <EthIf_Types.h>       /* Module public types */

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

#define ETHIF_START_SEC_CODE
#include <EthIf_MemMap.h>

/**
 * \brief   Calls EthIf_RxIndication()
 *
 * This service directly calls EthIf_RxIndication().
 *
 * \param[in] CtrlIdx             Index of the controller within the context of the EthIf.
 * \param[in] DataPtr             Address of the received payload (including Ethernet header).
 * \param[in] LenByte             Length of the payload contained in the received Rx buffer.
 *
 * \ServiceID{0x10}
 * \Reentrancy{Non reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, ETHIF_CODE) EthIf_Cbk_RxIndication
(
  uint8 CtrlIdx,
  P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
  uint16 LenByte
);

/**
 * \brief   Rx indication function
 *
 * This service is called by the Ethernet driver if a reception is indicated.
 *
 * \param[in] CtrlIdx             Index of the controller within the context of the EthIf.
 * \param[in] FrameType           Ethernet frame type.
 * \param[in] isBroadcast         Indicates whether the Ethernet destination address is a broadcast
 *                                address or not.
 * \param[in] PhysAddrPtr         Ethernet source address.
 * \param[in] DataPtr             Address of the received payload.
 * \param[in] LenByte             Length of the payload contained in the received Rx buffer.
 *
 * \ServiceID{0x10}
 * \Reentrancy{Non reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, ETHIF_CODE) EthIf_RxIndication
(
  uint8 CtrlIdx,
  Eth_FrameType FrameType,
  boolean isBroadcast,
  P2CONST(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr,
  P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
  uint16 LenByte
);

/**
 * \brief   Tx confirmation callback function
 *
 * This service confirms the transmission of an Ethernet frame.
 *
 * \param[in] CtrlIdx   Index of the Ethernet controller within the context of the Ethernet Interface.
 * \param[in] BufIdx    Index of the transmitted buffer.
 *
 * \ServiceID{0x11}
 * \Reentrancy{Non reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, ETHIF_CODE) EthIf_Cbk_TxConfirmation
(
  uint8 CtrlIdx,
  Eth_BufIdxType BufIdx
);

#if (ETHIF_ETH_SUPPORT_API == ETHIF_ETH_SUPPORT_API_ASR430)
/**
 * \brief   Tx confirmation function
 *
 * This service confirms the frame transmission by the indexed controller.
 *
 * \param[in] CtrlIdx   Index of the Ethernet controller within the context of the Ethernet Interface.
 * \param[in] BufIdx    Index of the transmitted buffer.
 * \param[in] Result    E_OK: The transmission was successful.
 *                      E_NOT_OK: The transmission failed.
 *
 * \ServiceID{0x11}
 * \Reentrancy{Non reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, ETHIF_CODE) EthIf_TxConfirmation
(
  uint8 CtrlIdx,
  Eth_BufIdxType BufIdx,
  Std_ReturnType Result
);
#else
/**
 * \brief   Tx confirmation function
 *
 * This service confirms the frame transmission by the indexed controller.
 *
 * \param[in] CtrlIdx    Index of the Ethernet controller within the context of the Ethernet Interface.
 * \param[in] BufIdx     Index of the transmitted buffer.
 *
 * \ServiceID{0x11}
 * \Reentrancy{Non reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, ETHIF_CODE) EthIf_TxConfirmation
(
  uint8 CtrlIdx,
  Eth_BufIdxType BufIdx
);
#endif /* (ETHIF_ETH_SUPPORT_API == ETHIF_ETH_SUPPORT_API_ASR430) */

/**
 * \brief   Callback function to indicate a controller mode change.
 *
 * Called asynchronously when the mode is read out. Triggered by the previous Eth_SetControllerMode()
 * call. Can be called directly within the trigger functions.
 *
 * \param[in] CtrlIdx             Index of the physical Ethernet controller within the context
 *                                of the Ethernet Interface.
 * \param[in] CtrlMode            Notified Ethernet controller mode:
 *                                - ETH_MODE_DOWN
 *                                - ETH_MODE_ACTIVE
 *
 * \ServiceID{0x0E}
 * \Reentrancy{Non reentrant for the same CtrlIdx. Reentrant for different CtrlIdx.}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, ETHIF_CODE) EthIf_CtrlModeIndication
(
  uint8 CtrlIdx,
  Eth_ModeType CtrlMode
);

/**
 * \brief   Callback function to indicate a transceiver mode change.
 *
 * Called asynchronously when the mode is read out. Triggered by the previous Eth_SetTransceiverMode()
 * call. Can be called directly within the trigger functions.
 *
 * \param[in] TrcvIdx             Index of the Ethernet transceiver within the context of
 *                                the Ethernet Interface
 * \param[in] TrcvMode            Notified Ethernet transceiver mode:
 *                                - ETHTRCV_MODE_DOWN
 *                                - ETHTRCV_MODE_ACTIVE
 *
 * \ServiceID{0x0F}
 * \Reentrancy{Non reentrant for the same CtrlIdx. Reentrant for different CtrlIdx.}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, ETHIF_CODE) EthIf_TrcvModeIndication
(
  uint8 TrcvIdx,
  EthTrcv_ModeType TrcvMode
);


#if (ETHIF_SWITCHMANAGEMENTSUPPORT == STD_ON)
/**
 * \brief   Callback function to indicate switch management info.
 *
 * Ingress Switch management info indication redirected call to upper layers that registered
 * for the call.
 *
 * \param[in] CtrlIdx             Index of an Ethernet Interface controller.
 * \param[in] DataPtr             Ethernet data pointer where the management information belongs.
 * \param[out] MgmtInfoPtr        Pointer to management information.
 *
 * \ServiceID{0x3A}
 * \Reentrancy{Non reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, ETHIF_CODE) EthIf_SwitchMgmtInfoIndication
(
  uint8 CtrlIdx,
  P2VAR(Eth_DataType, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
  P2VAR(EthSwt_MgmtInfoType, AUTOMATIC, ETHIF_APPL_DATA) MgmtInfoPtr
);
#endif /* ETHIF_SWITCHMANAGEMENTSUPPORT == STD_ON */


#define ETHIF_STOP_SEC_CODE
#include <EthIf_MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef ETHIF_CBK_H */
/*==================[end of file]===========================================*/
