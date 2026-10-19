/*
 * Transplant.h
 *
 *  Created on: 2023.11.23
 *      
 *      Transplant: ganping.zhan
*/

#ifndef APP_ETHERNET_H_
#define APP_ETHERNET_H_

#include "Eth_GeneralTypes.h"

extern void EMSYNC_RxIndication(uint8 CtrlIdx,
            Eth_FrameType FrameType,
            boolean IsBroadcast,
            P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr,
            P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
            uint16 LenByte);

extern void EMSYNC_MainFUnction();

extern void EMSYNC_TxConfirmation(
  uint8 EthIfCtrlIdx,
  uint8 EthBufIdx);
  
#endif /* APP_ETHERNET_H_ */
