/**
 * \file
 *
 * \brief AUTOSAR Xcp
 *
 * This file contains the implementation of the AUTOSAR
 * module Xcp.
 *
 * \version 2.12.3
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* 
 * MISRA-C:2012 Deviation List
 *
 */
#ifndef XCP_USERCALLOUTS_H
#define XCP_USERCALLOUTS_H


/*==================[includes]===============================================*/

#include <Xcp.h>

/*==================[macros]=================================================*/

#if (defined XCP_APPL_OK)
#error XCP_APPL_OK already defined
#endif
/** \brief return value of XCP application callout for successful execution. */
#define XCP_APPL_OK                     0x01U

/* !LINKSTO Xcp.UserCallouts.RAMCallback.Busy,1 */
#if (defined XCP_APPL_BUSY)
#error XCP_APPL_BUSY already defined
#endif
/** \brief return value of XCP application callout for signaling the Xcp slave
 ** that the requested data is not yet available */
#define XCP_APPL_BUSY                     0x02U

#if (defined XCP_APPL_ERR_CMD_UNKNOWN)
#error XCP_APPL_ERR_CMD_UNKNOWN already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_CMD_UNKNOWN error code. */
#define XCP_APPL_ERR_CMD_UNKNOWN        0x20U

#if (defined XCP_APPL_ERR_OUT_OF_RANGE)
#error XCP_APPL_ERR_OUT_OF_RANGE already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_OUT_OF_RANGE error code. */
#define XCP_APPL_ERR_OUT_OF_RANGE       0x22U

#if (defined XCP_APPL_ERR_WRITE_PROTECTED)
#error XCP_APPL_ERR_WRITE_PROTECTED already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_WRITE_PROTECTED error code. */
#define XCP_APPL_ERR_WRITE_PROTECTED    0x23U

#if (defined XCP_APPL_ERR_ACCESS_DENIED)
#error XCP_APPL_ERR_ACCESS_DENIED already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_ACCESS_DENIED error code. */
#define XCP_APPL_ERR_ACCESS_DENIED      0x24U

#if (defined XCP_APPL_ERR_PAGE_NOT_VALID)
#error XCP_APPL_ERR_PAGE_NOT_VALID already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_PAGE_NOT_VALID error code. */
#define XCP_APPL_ERR_PAGE_NOT_VALID     0x26U

#if (defined XCP_APPL_ERR_MODE_NOT_VALID)
#error XCP_APPL_ERR_MODE_NOT_VALID already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_MODE_NOT_VALID error code. */
#define XCP_APPL_ERR_MODE_NOT_VALID     0x27U

#if (defined XCP_APPL_ERR_SEGMENT_NOT_VALID)
#error XCP_APPL_ERR_SEGMENT_NOT_VALID already defined
#endif
/** \brief return value of XCP application callout XCP ERR_SEGMENT_NOT_VALID error code. */
#define XCP_APPL_ERR_SEGMENT_NOT_VALID  0x28U

#if (defined XCP_APPL_ERR_MEMORY_OVERFLOW)
#error XCP_APPL_ERR_MEMORY_OVERFLOW already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_MEMORY_OVERFLOW error code. */
#define XCP_APPL_ERR_MEMORY_OVERFLOW    0x30U

#if (defined XCP_APPL_ERR_GENERIC)
#error XCP_APPL_ERR_GENERIC already defined
#endif
/** \brief return value of XCP application callout with XCP ERR_GENERIC error code. */
#define XCP_APPL_ERR_GENERIC            0x31U

/** \brief Macro for address translation
 **
 ** Translates the given XCP address and address extension into the physical
 ** address to access.
 **
 ** \param[in] AddressExtension 8 bit XCP address extension
 ** \param[in] AddressPtr Pointer to the XCP address
 **
 ** \return Pointer to the physical address to access
 */
#if (defined XCP_APPL_GET_ADDRESS)
#error XCP_APPL_GET_ADDRESS already defined
#endif


#define XCP_APPL_GET_ADDRESS( AddressExtension, AddressPtr ) \
  (AddressPtr)

/*==================[type definitions]=======================================*/

/** \brief XCP application callout return type
 **
 ** This type provides the different return values to be used by the application
 ** callouts.
 */
typedef uint8 Xcp_ApplReturnType;


/*==================[external function declarations]=========================*/


#define XCP_START_SEC_APPL_CODE
#include <Xcp_MemMap.h>








/** \brief Compare Key from the Master.
 **
 ** This function will be called by the XCP Slave when the key from master
 ** needs to be compared.
 ** Implementation of this function shall be provided by the user.
 ** The file Xcp_Callouts.c from the templates folder can be used as a reference.
 ** The function shall implement the algorithm being used by the master to generate the Key.
 **
 ** \param[in]  ResourceIdentifier  A Resource to be unlocked.
 ** \param[in]  KeyBufferPtr        Pointer to the key to be verified.
 ** \param[in]  KeyLength           Length of the key RAM.
 **
 ** \return Function result
 ** \retval E_OK Function successful
 ** \retval E_NOT_OK Function not successful
 **
 ** \Reentrancy{Reentrant for different ResourceIdentifier. Non-reentrant for the same ResourceIdentifier}
 ** \Synchronicity{Synchronous} */
extern FUNC(Std_ReturnType, XCP_APPL_CODE) Xcp_ApplCompareKey
(
  uint8 ResourceIdentifier,
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) KeyBufferPtr,
  uint8 KeyLength
);

/** \brief Generate Seed for a resource.
 **
 ** This function is called by the XCP slave to generate seed for a requested resource.
 ** Implementation of this function shall be provided by the user.
 ** The file Xcp_Callouts.c from the templates folder can be used as a reference.
 ** The function shall implement the algorithm being used by the master to generate the Seed.
 ** When requesting for a resource the user shall make sure that the resource is supported 
 ** and allowed.
 ** Any attempt to unlock a not supporter resource shall return E_NOT_OK.
 **
 ** \param[in]     ResourceIdentifier    A Resource to be unlocked.
 ** \param[in,out]  SeedBufferPtr        Pointer to the RAM area where the seed needs to be stored.
 ** \param[in,out]  SeedBufferLengthPtr  Pointer to the RAM area where the seed length needs to be stored.
 **
 ** \return Function result
 ** \retval E_OK Function successful
 ** \retval E_NOT_OK Function not successful
 **
 ** \Reentrancy{Reentrant for different ResourceIdentifier. Non-reentrant for the same ResourceIdentifier}
 ** \Synchronicity{Synchronous} */
extern FUNC(Std_ReturnType, XCP_APPL_CODE) Xcp_ApplGetSeed
(
  uint8 ResourceIdentifier,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) SeedBufferPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) SeedBufferLengthPtr
);

/** \brief Callout function for the command PROGRAM_START
 **
 ** This function is called by the Xcp whenever the command PROGRAM_START is
 ** executed. Use this callout to setup the programming (memory programming may have implementation
 ** specific preconditions (slave device in a secure physical state, additional code
 ** downloaded, ...).
 **
 ** \param[out] ErrorCodePtr Pointer to write the slave specific error code to. Value is used only
 ** to fill the error message ERR_GENERIC. If XCP_APPL_ERR_GENERIC is not thrown by the callout
 ** function this parameter is ignored.
 **
 ** \return Function result
 ** \retval XCP_APPL_OK Function successful
 ** \retval XCP_APPL_ERR_GENERIC The slave device is not in a state which permits programming
 */
extern FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplProgramStart
(
  P2VAR(uint16, AUTOMATIC, XCP_APPL_DATA) ErrorCodePtr
);

/** \brief Callout function for the command PROGRAM_CLEAR
 **
 ** This function is called by the Xcp whenever the command PROGRAM_CLEAR is
 ** executed. Use this function to clear a part of non-volatile memory prior to reprogramming.
 **
 ** \param[in] AddressPtr Pointer to the address of the flash block to be
 **                       cleared
 ** \param[in] ClearRange Length, in bytes, of the block to be cleared
 **
 ** \return Function result
 ** \retval XCP_APPL_OK Function successful
 ** \retval XCP_APPL_ERR_OUT_OF_RANGE Parameter is invalid
 ** \retval XCP_APPL_ERR_ACCESS_DENIED Memory access not allowed
 */
extern FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplProgramClear
(
  P2VAR(void, AUTOMATIC, XCP_APPL_DATA) AddressPtr,
  uint32 ClearRange
);

/** \brief Callout function for the command PROGRAM
 **
 ** This function is called by the Xcp in the following cases, depending on the communication mode:
 ** - normal mode: with each execution of PROGRAM or PROGRAM_MAX commands
 ** - block mode: at the end of an entire block mode sequence (i.e. the last PROGRAM_NEXT) and each
 **   time a PROGRAM with number of bytes to be programmed = 0 is called.
 **
 ** This function should do the actual programming.
 **
 ** When this callout is called with DataLength = 0, it means the end of the programming for the
 ** current segment.
 **
 ** \param[in] AddressPtr Pointer to the address of the flash block to be
 **                       programmed.
 ** \param[in] DataPtr Pointer to a data buffer to be programmed.
 ** \param[in] DataLength Length of the buffer to be programmed (in bytes).
 **
 ** \return Function result
 ** \retval XCP_APPL_OK Function successful
 ** \retval XCP_APPL_ERR_OUT_OF_RANGE Parameter is invalid
 ** \retval XCP_APPL_ERR_ACCESS_DENIED Memory access not allowed
 ** \retval XCP_APPL_ERR_MEMORY_OVERFLOW Memory overflow during execution
 */
extern FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplProgram
(
  P2VAR(void, AUTOMATIC, XCP_APPL_DATA) AddressPtr,
  P2CONST(uint8, AUTOMATIC, XCP_APPL_DATA) DataPtr,
  uint16 DataLength
);

/** \brief Callout function for the command PROGRAM_RESET
 **
 ** This function is called by the Xcp whenever the command PROGRAM_RESET is executed.
 **
 */
extern FUNC(void, XCP_APPL_CODE) Xcp_ApplProgramReset( void );

/** \brief Callout function for command GET_PGM_PROCESSOR_INFO
 **
 ** This callout function provides the programming processor basic information:
 ** \li total number of available sectors
 ** \li and programming general properties:
 ** - the available mode[s];
 ** - data compression properties;
 ** - data encryption properties;
 ** - and message sequence processing properties.
 **
 ** Note: if the function returns a different value than those listed in the return value
 ** section, the Xcp module will assume that the command was not executed and send the error
 ** ERR_CMD_UNKNOWN as response to the master.
 **
 ** Implementation of this function shall be provided by the user.
 ** The file Xcp_Callouts.c from the templates folder can be used as a template.
 **
 ** \param[out] MaxSectorPtr Total number of available sectors to be returned to the master
 ** \param[out] PgmPropertiesPtr General properties for programming to be returned to
 **             the master. The programming mode bits will be masked to only contain those
 **             modes which are supported by the Xcp (only ABSOLUTE_MODE is supported by the Xcp).
 **
 ** \return Function result.
 ** \retval XCP_APPL_OK Function successful.
 **
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetPgmProcessorInfo
(
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) MaxSectorPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) PgmPropertiesPtr
);

/** \brief Callout function for command GET_SECTOR_INFO
 **
 ** This callout function shall provide the sector information that was requested.
 ** That information shall be written to the address, to which \a CommandResponsePtr points to.
 **
 ** Note: if the function returns a different value than those listed in the return value
 ** section, the Xcp module will assume that the command was not executed and send the error
 ** ERR_CMD_UNKNOWN as response to the master.
 **
 ** Implementation of this function shall be provided by the user.
 ** The file Xcp_Callouts.c from the templates folder can be used as a template.
 **
 ** Implementation hints: The following ASAM requirement has to fulfilled by this callout:
 **   "The clear and programming sequence number of a flash sector shall be unique and continuous."
 **
 ** \param[in] Mode Type of information requested for the given Sector number (start address,
 **            length [BYTE] or name length).
 ** \param[in] Sector The Sector number for which information is requested.
 ** \param[out] MtaPtr Optional parameter used to get the MTA of the SECTOR name.
 **    \a MtaPtr parameter is the address of a 4-byte buffer containing the location address from
 **     which the Master may upload the SECTOR name as ASCII text, using one or more UPLOAD
 **     commands.
 **     Note: This parameter is mandatory in case \a Mode equals 2.
 ** \param[out] CommandResponsePtr Command response buffer address:
 **     - a 7-byte buffer, in case one of the following sector information is requested: the
 **       start address or length [BYTE], or
 **     - a 1-byte buffer, in case the name length sector information is requested;
 **
 **    where, the callout function stores its response data depending on \a Mode input parameters.
 **    - Depending on the Mode input parameter, this callout function shall provide the following
 ** data in the command response buffer:
 ** \li Mode 0:
 **     - Byte 0: Clear Sequence Number;
 **     - Byte 1: Program Sequence Number;
 **     - Byte 2: Programming method.
 **     - Bytes 3-6: Start address for this Sector (DWORD).
 ** \li Mode 1:
 **     - Byte 0: Clear Sequence Number;
 **     - Byte 1: Program Sequence Number;
 **     - Byte 2: Programming method.
 **     - Bytes 3-6: Length of this Sector [Byte] (DWORD).
 ** \li Mode 2:
 **     - Byte 0: SECTOR_NAME_LENGTH in bytes or 0 if not available;
 **
 ** \return Function result.
 ** \retval XCP_APPL_OK Function successful.
 ** \retval XCP_APPL_ERR_MODE_NOT_VALID Parameter \a Mode is invalid.
 ** \retval XCP_APPL_ERR_SEGMENT_NOT_VALID Parameter \a Sector is invalid.
 **
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous}
 */
extern FUNC(Xcp_ApplReturnType, XCP_APPL_CODE) Xcp_ApplGetSectorInfo
(
  uint8 Mode,
  uint8 Sector,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) MtaPtr,
  P2VAR(uint8, AUTOMATIC, XCP_APPL_DATA) CommandResponsePtr
);



#define XCP_STOP_SEC_APPL_CODE
#include <Xcp_MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef XCP_USERCALLOUTS_H */
/*==================[end of file]============================================*/
