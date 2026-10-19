
#ifndef _EM_ETH_INTF_H_
#define _EM_ETH_INTF_H_

#include "Eth_GeneralTypes.h"

extern void EthIf_Emdc_RxIndication(uint8 CtrlIdx,
  Eth_FrameType FrameType,
  boolean IsBroadcast,
  P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) PhysAddrPtr,
  P2VAR(uint8, AUTOMATIC, ETHIF_APPL_DATA) DataPtr,
  uint16 LenByte);
#endif