/*
 * Diag_ErrManager_Interface.h
 *
 *  Created on: 2022年2月18日
 *      
 */

#ifndef EM_SERVICESLAYER_SERVICE_DIAG_MANAGER_DIAG_ERRMANAGER_INTERFACE_H_
#define EM_SERVICESLAYER_SERVICE_DIAG_MANAGER_DIAG_ERRMANAGER_INTERFACE_H_

#include "Diag_ErrType_Enum.h"
//#include "proj_global.h"
extern uint8 Diag_ErrInformationReport(Diag_Errortype ErrorId);
extern uint8 Diag_ErrInformationClear(Diag_Errortype ErrorId);
extern uint32* Diag_GetErrorRTlist(uint16* count);
extern uint32* Diag_GetErrorHistorylist(uint16* count);

#endif /* EM_SERVICESLAYER_SERVICE_DIAG_MANAGER_DIAG_ERRMANAGER_INTERFACE_H_ */
