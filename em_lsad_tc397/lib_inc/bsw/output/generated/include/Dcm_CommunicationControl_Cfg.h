/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.11
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef DCM_COMMUNICATIONCONTROL_CFG_H
#define DCM_COMMUNICATIONCONTROL_CFG_H

/* !LINKSTO Dcm.Dsn.File.CommunicationControl.ConfigH,1 */

/*==================[includes]===================================================================*/

#include <Std_Types.h>

#include <ComM_Dcm.h>                                         /* Definition of NetworkHandleType */

/*==================[macros]=====================================================================*/

/** \brief Support for resetting of channel state on failure of the
 **        DcmDspComControlCommunicationReEnableModeRuleRef mode rule check */
#if (defined DCM_DSP_COMMUNICATIONCONTROL_REENABLE_MODE_RULE_SUPPORT)
  #error "DCM_DSP_COMMUNICATIONCONTROL_REENABLE_MODE_RULE_SUPPORT is already defined"
#endif
#define DCM_DSP_COMMUNICATIONCONTROL_REENABLE_MODE_RULE_SUPPORT            STD_OFF

#if (defined DCM_0X28_0X00_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X28_0X00_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X28_0X00_SSVC_ENABLED ) */

/** \brief Subservice 0x00 for 0x28 enabled or not */
#define DCM_0X28_0X00_SSVC_ENABLED                                         STD_ON

#if (defined DCM_0X28_0X01_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X28_0X01_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X28_0X01_SSVC_ENABLED ) */

/** \brief Subservice 0x01 for 0x28 enabled or not */
#define DCM_0X28_0X01_SSVC_ENABLED                                         STD_ON

#if (defined DCM_0X28_0X02_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X28_0X02_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X28_0X02_SSVC_ENABLED ) */

/** \brief Subservice 0x02 for 0x28 enabled or not */
#define DCM_0X28_0X02_SSVC_ENABLED                                         STD_ON

#if (defined DCM_0X28_0X03_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X28_0X03_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X28_0X03_SSVC_ENABLED ) */

/** \brief Subservice 0x03 for 0x28 enabled or not */
#define DCM_0X28_0X03_SSVC_ENABLED                                         STD_ON

#if (defined DCM_0X28_0X04_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X28_0X04_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X28_0X04_SSVC_ENABLED ) */

/** \brief Subservice 0x04 for 0x28 enabled or not */
#define DCM_0X28_0X04_SSVC_ENABLED                                         STD_OFF

#if (defined DCM_0X28_0X05_SSVC_ENABLED ) /* To prevent double declaration */
#error DCM_0X28_0X05_SSVC_ENABLED  already defined
#endif /* if (defined DCM_0X28_0X05_SSVC_ENABLED ) */

/** \brief Subservice 0x05 for 0x28 enabled or not */
#define DCM_0X28_0X05_SSVC_ENABLED                                         STD_OFF

#if (defined DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE) /* To prevent double declaration */
#error DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE already defined
#endif /* if (defined DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE) */

/** \brief Size of array Dcm_CommunicationControlLookUpTable[] and
 **        Dcm_CommunicationControlLookUpTableComMode[].
 **
 ** If mode declaration is enabled than the DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE will be equal with
 ** the number of channels referenced from RxConnections + number of channels from DcmDspComControl.
 ** If mode declaration is disable then the DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE will be equal with
 ** the number of channels referenced from RxConnections.
 */
#define DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE                               1U

/*==================[type definitions]===========================================================*/


/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

/*==================[external constants]=========================================================*/

#if(DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE > 0U)

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/** \brief Global array holding the ComM channels ID referenced from RxConnections.
 **        This array is used to search the requested channel. Always when the communication
 **        mode is changed(0x28 request or session change) the channel is searched in this array and
 **        the same index on which it is found is changed with the request communication mode in the
 **        Dcm_CommunicationControl_CommunicationMode[] array.
 */
extern CONST(NetworkHandleType, DCM_CONST)
                          Dcm_CommunicationControlLookUpTable[DCM_COMMUNICATIONCONTROL_LOOKUP_SIZE];

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

#endif

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

#endif /* ifndef DCM_COMMUNICATIONCONTROL_CFG_H */
/*==================[end of file]================================================================*/
