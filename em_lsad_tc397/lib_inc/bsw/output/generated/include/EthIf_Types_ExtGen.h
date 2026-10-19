


/**
 * \file
 *
 * \brief AUTOSAR EthIf
 *
 * This file contains the implementation of the AUTOSAR
 * module EthIf.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef ETHIF_TYPES_EXTGEN_H
#define ETHIF_TYPES_EXTGEN_H



/*==================[inclusions]=============================================*/

#include <Platform_Types.h>
#include <TSAutosar.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_PTR_CLASS ETHIF_APPL_CONST
#include <TSPBConfig_Types.h>


/*==================[macros]=================================================*/

#if (defined ETHIF_PORTROLE_STANDARD) /* To prevent double definition */
#error ETHIF_PORTROLE_STANDARD already defined
#endif /* (defined ETHIF_PORTROLE_STANDARD) */

#define ETHIF_PORTROLE_STANDARD 0


#if (defined ETHIF_PORTROLE_UPLINK) /* To prevent double definition */
#error ETHIF_PORTROLE_UPLINK already defined
#endif /* (defined ETHIF_PORTROLE_UPLINK) */

#define ETHIF_PORTROLE_UPLINK 1


#if (defined ETHIF_PORTROLE_HOST) /* To prevent double definition */
#error ETHIF_PORTROLE_HOST already defined
#endif /* (defined ETHIF_PORTROLE_HOST) */

#define ETHIF_PORTROLE_HOST 2


#if (defined ETHIF_INVALID_TRCV_IDX) /* To prevent double definition */
#error ETHIF_INVALID_TRCV_IDX already defined
#endif /* (defined ETHIF_INVALID_TRCV_IDX) */

#define ETHIF_INVALID_TRCV_IDX 255


#if (defined ETHIF_INVALID_TRCV_MIIIDX) /* To prevent double definition */
#error ETHIF_INVALID_TRCV_MIIIDX already defined
#endif /* (defined ETHIF_INVALID_TRCV_MIIIDX) */

#define ETHIF_INVALID_TRCV_MIIIDX 255


#if (defined ETHIF_INVALID_PORTGROUP_IDX) /* To prevent double definition */
#error ETHIF_INVALID_PORTGROUP_IDX already defined
#endif /* (defined ETHIF_INVALID_PORTGROUP_IDX) */

#define ETHIF_INVALID_PORTGROUP_IDX 255


#if (defined ETHIF_INVALID_SWT_IDX) /* To prevent double definition */
#error ETHIF_INVALID_SWT_IDX already defined
#endif /* (defined ETHIF_INVALID_SWT_IDX) */

#define ETHIF_INVALID_SWT_IDX 255


#if (defined ETHIF_INVALID_IDSMEVENTID_IDX) /* To prevent double definition */
#error ETHIF_INVALID_IDSMEVENTID_IDX already defined
#endif /* (defined ETHIF_INVALID_IDSMEVENTID_IDX) */

#define ETHIF_INVALID_IDSMEVENTID_IDX 65535


#if (defined ETHIF_INVALID_DEM_EVENT_ID) /* To prevent double definition */
#error ETHIF_INVALID_DEM_EVENT_ID already defined
#endif /* (defined ETHIF_INVALID_DEM_EVENT_ID) */

#define ETHIF_INVALID_DEM_EVENT_ID 0


#if (defined ETHIF_REFTYPE_NO_REF) /* To prevent double definition */
#error ETHIF_REFTYPE_NO_REF already defined
#endif /* (defined ETHIF_REFTYPE_NO_REF) */

#define ETHIF_REFTYPE_NO_REF 0


#if (defined ETHIF_REFTYPE_LINK_INFO) /* To prevent double definition */
#error ETHIF_REFTYPE_LINK_INFO already defined
#endif /* (defined ETHIF_REFTYPE_LINK_INFO) */

#define ETHIF_REFTYPE_LINK_INFO 1


#if (defined ETHIF_REFTYPE_CONTROL) /* To prevent double definition */
#error ETHIF_REFTYPE_CONTROL already defined
#endif /* (defined ETHIF_REFTYPE_CONTROL) */

#define ETHIF_REFTYPE_CONTROL 2


#if (defined ETHIF_REFTYPE_SWITCH) /* To prevent double definition */
#error ETHIF_REFTYPE_SWITCH already defined
#endif /* (defined ETHIF_REFTYPE_SWITCH) */

#define ETHIF_REFTYPE_SWITCH 3



/*==================[type definitions]=======================================*/

/** 
 Type of EthIf controller configuration structure.
 */
typedef struct /* EthIf_CtrlType */ {
    VAR( uint8, TYPEDEF ) PhysCtrlIdx;
    VAR( uint8, TYPEDEF ) EthIfPortGroupIdx;
} EthIf_CtrlType;

/** 
 Type of Phys controller configuration structure.
 */
typedef struct /* EthIf_PhysCtrlType */ {
    VAR( uint8, TYPEDEF ) EthCtrlIdx;
} EthIf_PhysCtrlType;

/** 
 Type of Transceiver configuration structure.
 */
typedef struct /* EthIf_TrcvType */ {
    VAR( uint8, TYPEDEF ) EthTrcvIdx;
} EthIf_TrcvType;

/** 
 Type of Switch port configuration structure.
 */
typedef struct /* EthIf_SwtPortType */ {
    VAR( uint8, TYPEDEF ) EthSwtIdx;
    VAR( uint8, TYPEDEF ) EthSwtPortIdx;
} EthIf_SwtPortType;

/** 
 Type for Ethernet switch port role: [PORTROLE_STANDARD, PORTROLE_UPLINK, PORTROLE_HOST].
 */
typedef VAR( uint8, TYPEDEF ) EthIf_PortRoleType;

/** 
 Type for Port group reference semantics: [REFTYPE_NO_REF, REFTYPE_LINK_INFO, REFTYPE_CONTROL, REFTYPE_SWITCH].
 */
typedef VAR( uint8, TYPEDEF ) EthIf_PortGroupRefSemanticType;

/** 
 Type for mapping array from EthIf to Eth physical controller.
 */
typedef struct /* EthIf_PhysCtrlEthIfCtrlMapDataType */ {
    VAR( uint8, TYPEDEF ) EthIfCtrlIdxOffset;
    VAR( uint8, TYPEDEF ) EthIfCtrlIdNumber;
} EthIf_PhysCtrlEthIfCtrlMapDataType;

/** 
 Type of EthIf Physical controller Ingress Fifo configuration structure.
 */
typedef struct /* EthIf_PhysCtrlIngrFifoType */ {
    VAR( uint16, TYPEDEF ) EthIfCtrlRxIndicationIterations;
    VAR( uint8, TYPEDEF ) PhysCtrlIdx;
    VAR( uint8, TYPEDEF ) EthFifoIdx;
} EthIf_PhysCtrlIngrFifoType;

/** 
 Type definition of the root structure.
 */
typedef struct /* EthIf_ConfigType */ {
    VAR( uint32, TYPEDEF ) PlatformSignature; /* Used to validate the platform. */
    VAR( uint32, TYPEDEF ) LcfgSignature; /* Used to validate the post build configuration against the link time configuration. */
    VAR( uint32, TYPEDEF ) CfgSignature; /* Used to validate the post build configuration against the precompile time configuration. */
    VAR( uint32, TYPEDEF ) PublicInfoSignature; /* Used to validate Public information. */
    TS_REF2CFG( EthIf_CtrlType )  EthIf_EthIfCtrlRef;
    TS_REF2CFG( EthIf_PhysCtrlType )  EthIf_PhysCtrlRef;
    TS_REF2CFG( uint8 )  EthIf_EthIfSwtRef;
    VAR( uint8, TYPEDEF ) PhyCtrlMax;
    VAR( uint8, TYPEDEF ) EthIfCtrlMax;
    VAR( uint8, TYPEDEF ) EthIfSwtMax;
    VAR( uint8, TYPEDEF ) EthIfTrcvMax;
} EthIf_ConfigType;

/** 
 Type of Switch port group configuration structure.
 */
typedef struct /* EthIf_SwtPortGroupType */ {
    VAR( uint16, TYPEDEF ) BeginIdx;
    VAR( uint8, TYPEDEF ) NumPorts;
    VAR( EthIf_PortGroupRefSemanticType, TYPEDEF ) RefType;
} EthIf_SwtPortGroupType;


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/


/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/



#undef TS_RELOCATABLE_CFG_ENABLE

#undef TS_PB_CFG_PTR_CLASS

#endif /* ETHIF_TYPES_EXTGEN_H */

/*==================[end of file]============================================*/

