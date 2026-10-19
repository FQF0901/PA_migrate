/**
 * \file
 *
 * \brief AUTOSAR IdsM
 *
 * This file contains the implementation of the AUTOSAR
 * module IdsM.
 *
 * \version 1.0.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef IDSM_PROTOCOLACCESS_H
#define IDSM_PROTOCOLACCESS_H

/*==================[inclusions]============================================*/

#include <IdsM_Cfg.h>               /* IdsM pre-compile-time configuration */
#include <Std_Types.h>              /* AUTOSAR standard types */
#include <ComStack_Helpers.h>       /* EB specific endian macros */

/*==================[macros]================================================*/

/* --- IDS General Macros ------------------------------------------------- */

/** \brief IDS protocol version */
#if (defined IDSM_PROTOCOL_VERSION)
#error IDSM_PROTOCOL_VERSION already defined!
#endif
#define IDSM_PROTOCOL_VERSION               0x01U

/** \brief IDS protocol version shifted 4 bits same as its location in IDS buffer */
#if (defined IDSM_PROTOCOL_VERSION_SHIFTED)
#error IDSM_PROTOCOL_VERSION_SHIFTED already defined!
#endif
#define IDSM_PROTOCOL_VERSION_SHIFTED       (IDSM_PROTOCOL_VERSION << 4)


/* --- IDS Protocol Helper and Serializer Macros -------------------------- */

/** \brief Set a bit in a byte */
#if (defined IDSM_SET_BIT)
#error IDSM_SET_BIT is already defined
#endif
#define IDSM_SET_BIT(var, num) \
    ((var) |= (uint8)(1U << (num)))

/** \brief Check a bit in a byte */
#if (defined IDSM_CHECK_BIT)
#error IDSM_CHECK_BIT is already defined
#endif
#define IDSM_CHECK_BIT(var, num) \
    (((var) >> (num)) & 1U)

/** \brief Byte mirror macro to convert uint64 values between little and big endian format */
#if (defined IDSM_MIRROR64)
#error IDSM_MIRROR64 is already defined
#endif
#define IDSM_MIRROR64(value) (uint64)\
    (   (uint64)((uint64)(((uint64)(value) & (uint64)0x00000000000000FFUL) << 56U))    | \
        (uint64)((uint64)(((uint64)(value) & (uint64)0x000000000000FF00UL) << 40U))    | \
        (uint64)((uint64)(((uint64)(value) & (uint64)0x0000000000FF0000UL) << 24U))    | \
        (uint64)((uint64)(((uint64)(value) & (uint64)0x00000000FF000000UL) << 8U ))    | \
        (uint64)((uint64)(((uint64)(value)) >> 8U  ) & ((uint64)0x00000000FF000000UL)) | \
        (uint64)((uint64)(((uint64)(value)) >> 24U ) & ((uint64)0x0000000000FF0000UL)) | \
        (uint64)((uint64)(((uint64)(value)) >> 40U ) & ((uint64)0x000000000000FF00UL)) | \
        (uint64)((uint64)(((uint64)(value)) >> 56U ) & ((uint64)0x00000000000000FFUL))    )

/** \brief Host to network for uint64, it converts uint64 to big endian if the machine is little endian */
#if (defined IDSM_HTON_UINT64)
#error IDSM_HTON_UINT64 is already defined
#endif
#define IDSM_HTON_UINT64(value) TS_IF_BE_LE((value), IDSM_MIRROR64(value))

/** \brief Set types greater than one byte in IDS protocol by casting bufferPtr to refType */
#if (defined IDSM_BUFFER_SET_VALUE)
#error IDSM_BUFFER_SET_VALUE is already defined
#endif
#define IDSM_BUFFER_SET_VALUE(bufferPtr, refType, value, offset) \
    ( *((P2VAR(refType, AUTOMATIC, IDSM_APPL_DATA)) \
        (P2VAR(void, AUTOMATIC, IDSM_APPL_DATA)) \
        ((bufferPtr)+(offset)) ) = (refType)(value) )

/** \brief Set uint8 value in IDS buffer offset */
#if (defined IDSM_BUFFER_SET_UINT8)
#error IDSM_BUFFER_SET_UINT8 is already defined
#endif
#define IDSM_BUFFER_SET_UINT8(bufferPtr, value, offset) \
    ((bufferPtr)[offset] = (uint8)(value))

/** \brief Set uint16 value in IDS buffer offset */
#if (defined IDSM_BUFFER_SET_UINT16)
#error IDSM_BUFFER_SET_UINT16 is already defined
#endif
#define IDSM_BUFFER_SET_UINT16(bufferPtr, value, offset) \
    do \
    { \
        (bufferPtr)[(offset)] = (uint8)((value) >> 8); \
        (bufferPtr)[(offset)+1] = (uint8)((value) & 0x00FF); \
    } while(FALSE)

/** \brief Set uint32 value in IDS buffer offset */
#if (defined IDSM_BUFFER_SET_UINT32)
#error IDSM_BUFFER_SET_UINT32 is already defined
#endif
#define IDSM_BUFFER_SET_UINT32(bufferPtr, value, offset) \
    (IDSM_BUFFER_SET_VALUE(bufferPtr, uint32, value, offset))

/** \brief Set uint64 value in IDS buffer offset */
#if (defined IDSM_BUFFER_SET_UINT64)
#error IDSM_BUFFER_SET_UINT64 is already defined
#endif
#define IDSM_BUFFER_SET_UINT64(bufferPtr, value, offset) \
    (IDSM_BUFFER_SET_VALUE(bufferPtr, uint64, value, offset))

/** \brief Serialize uint16 value to big endian and put it in IDS buffer offset */
#if (defined IDSM_BUFFER_SERIALIZE_UINT16)
#error IDSM_BUFFER_SERIALIZE_UINT16 is already defined
#endif
#define IDSM_BUFFER_SERIALIZE_UINT16(bufferPtr, value, offset) \
    (IDSM_BUFFER_SET_VALUE(bufferPtr, uint16, COMSTACK_HTON_UINT16(value), offset))

/** \brief Serialize uint32 value to big endian and put it in IDS buffer offset */
#if (defined IDSM_BUFFER_SERIALIZE_UINT32)
#error IDSM_BUFFER_SERIALIZE_UINT32 is already defined
#endif
#define IDSM_BUFFER_SERIALIZE_UINT32(bufferPtr, value, offset) \
    (IDSM_BUFFER_SET_VALUE(bufferPtr, uint32, COMSTACK_HTON_UINT32(value), offset))

/** \brief Serialize uint64 value to big endian and put it in IDS buffer offset */
#if (defined IDSM_BUFFER_SERIALIZE_UINT64)
#error IDSM_BUFFER_SERIALIZE_UINT64 is already defined
#endif
#define IDSM_BUFFER_SERIALIZE_UINT64(bufferPtr, value, offset) \
    (IDSM_BUFFER_SET_VALUE(bufferPtr, uint64, IDSM_HTON_UINT64(value), offset))

/** \brief Set uint16 value in buffer offset serialized if host is ECU and as it is if host is external device */
#if (defined IDSM_HOST_BUFFER_SET_UINT16)
#error IDSM_HOST_BUFFER_SET_UINT16 is already defined
#endif
#if (defined IDSM_HOST_ECU)
#define IDSM_HOST_BUFFER_SET_UINT16(bufferPtr, value, offset) \
    (IDSM_BUFFER_SERIALIZE_UINT16(bufferPtr, value, offset))
#elif (defined IDSM_HOST_EXTERNAL_DEVICE)
#define IDSM_HOST_BUFFER_SET_UINT16(bufferPtr, value, offset) \
    (IDSM_BUFFER_SET_UINT16(bufferPtr, value, offset))
#endif

/** \brief Set uint32 value in buffer offset serialized if host is ECU and as it is if host is external device */
#if (defined IDSM_HOST_BUFFER_SET_UINT32)
#error IDSM_HOST_BUFFER_SET_UINT32 is already defined
#endif
#if (defined IDSM_HOST_ECU)
#define IDSM_HOST_BUFFER_SET_UINT32(bufferPtr, value, offset) \
    (IDSM_BUFFER_SERIALIZE_UINT32(bufferPtr, value, offset))
#elif (defined IDSM_HOST_EXTERNAL_DEVICE)
#define IDSM_HOST_BUFFER_SET_UINT32(bufferPtr, value, offset) \
    (IDSM_BUFFER_SET_UINT32(bufferPtr, value, offset))
#endif

/** \brief Set uint64 value in buffer offset serialized if host is ECU and as it is if host is external device */
#if (defined IDSM_HOST_BUFFER_SET_UINT64)
#error IDSM_HOST_BUFFER_SET_UINT64 is already defined
#endif
#if (defined IDSM_HOST_ECU)
#define IDSM_HOST_BUFFER_SET_UINT64(bufferPtr, value, offset) \
    (IDSM_BUFFER_SERIALIZE_UINT64(bufferPtr, value, offset))
#elif (defined IDSM_HOST_EXTERNAL_DEVICE)
#define IDSM_HOST_BUFFER_SET_UINT64(bufferPtr, value, offset) \
    (IDSM_BUFFER_SET_UINT64(bufferPtr, value, offset))
#endif

/** \brief Get types greater than one byte from IDS protocol by casting bufferPtr to refType */
#if (defined IDSM_BUFFER_GET_VALUE)
#error IDSM_BUFFER_GET_VALUE is already defined
#endif
#define IDSM_BUFFER_GET_VALUE(bufferPtr, refType, offset) \
    ( *((P2VAR(refType, AUTOMATIC, IDSM_APPL_DATA)) \
        (P2VAR(void, AUTOMATIC, IDSM_APPL_DATA)) \
        ((bufferPtr)+(offset)) ) )

/** \brief Get uint8 value from IDS buffer offset */
#if (defined IDSM_BUFFER_GET_UINT8)
#error IDSM_BUFFER_GET_UINT8 is already defined
#endif
#define IDSM_BUFFER_GET_UINT8(bufferPtr, offset) \
    ((uint8)(bufferPtr)[offset])

/** \brief Get uint16 value from IDS buffer offset */
#if (defined IDSM_BUFFER_GET_UINT16)
#error IDSM_BUFFER_GET_UINT16 is already defined
#endif
#define IDSM_BUFFER_GET_UINT16(bufferPtr, offset) \
    ((uint16)(((uint16)((bufferPtr)[(offset)]) << 8) | ((uint16)(bufferPtr)[(offset)+1])))

/** \brief Get uint32 value from IDS buffer offset */
#if (defined IDSM_BUFFER_GET_UINT32)
#error IDSM_BUFFER_GET_UINT32 is already defined
#endif
#define IDSM_BUFFER_GET_UINT32(bufferPtr, offset) \
    (IDSM_BUFFER_GET_VALUE(bufferPtr, uint32, offset))

/** \brief Get uint64 value from IDS buffer offset */
#if (defined IDSM_BUFFER_GET_UINT64)
#error IDSM_BUFFER_GET_UINT64 is already defined
#endif
#define IDSM_BUFFER_GET_UINT64(bufferPtr, offset) \
    (IDSM_BUFFER_GET_VALUE(bufferPtr, uint64, offset))

/** \brief De-Serialize uint16 value to machine from big endian in IDS buffer offset */
#if (defined IDSM_BUFFER_DESERIALIZE_UINT16)
#error IDSM_BUFFER_DESERIALIZE_UINT16 is already defined
#endif
#define IDSM_BUFFER_DESERIALIZE_UINT16(bufferPtr, offset) \
    (COMSTACK_HTON_UINT16(IDSM_BUFFER_GET_UINT16(bufferPtr, offset)))

/** \brief De-Serialize uint32 value to machine from big endian in IDS buffer offset */
#if (defined IDSM_BUFFER_DESERIALIZE_UINT32)
#error IDSM_BUFFER_DESERIALIZE_UINT32 is already defined
#endif
#define IDSM_BUFFER_DESERIALIZE_UINT32(bufferPtr, offset) \
    (COMSTACK_HTON_UINT32(IDSM_BUFFER_GET_UINT32(bufferPtr, offset)))

/** \brief De-Serialize uint64 value to machine from big endian in IDS buffer offset */
#if (defined IDSM_BUFFER_DESERIALIZE_UINT64)
#error IDSM_BUFFER_DESERIALIZE_UINT64 is already defined
#endif
#define IDSM_BUFFER_DESERIALIZE_UINT64(bufferPtr, offset) \
    (IDSM_HTON_UINT64(IDSM_BUFFER_GET_UINT64(bufferPtr, offset)))

/** \brief Get uint16 value from buffer offset deserialized if host is ECU and as it is if host is external device */
#if (defined IDSM_HOST_BUFFER_GET_UINT16)
#error IDSM_HOST_BUFFER_GET_UINT16 is already defined
#endif
#if (defined IDSM_HOST_ECU)
#define IDSM_HOST_BUFFER_GET_UINT16(bufferPtr, offset) \
    (IDSM_BUFFER_DESERIALIZE_UINT16(bufferPtr, offset))
#elif (defined IDSM_HOST_EXTERNAL_DEVICE)
#define IDSM_HOST_BUFFER_GET_UINT16(bufferPtr, offset) \
    (IDSM_BUFFER_GET_UINT16(bufferPtr, offset))
#endif

/** \brief Get uint32 value from buffer offset deserialized if host is ECU and as it is if host is external device */
#if (defined IDSM_HOST_BUFFER_GET_UINT32)
#error IDSM_HOST_BUFFER_GET_UINT32 is already defined
#endif
#if (defined IDSM_HOST_ECU)
#define IDSM_HOST_BUFFER_GET_UINT32(bufferPtr, offset) \
    (IDSM_BUFFER_DESERIALIZE_UINT32(bufferPtr, offset))
#elif (defined IDSM_HOST_EXTERNAL_DEVICE)
#define IDSM_HOST_BUFFER_GET_UINT32(bufferPtr, offset) \
    (IDSM_BUFFER_GET_UINT32(bufferPtr, offset))
#endif

/** \brief Get uint64 value from buffer offset deserialized if host is ECU and as it is if host is external device */
#if (defined IDSM_HOST_BUFFER_GET_UINT64)
#error IDSM_HOST_BUFFER_GET_UINT64 is already defined
#endif
#if (defined IDSM_HOST_ECU)
#define IDSM_HOST_BUFFER_GET_UINT64(bufferPtr, offset) \
    (IDSM_BUFFER_DESERIALIZE_UINT64(bufferPtr, offset))
#elif (defined IDSM_HOST_EXTERNAL_DEVICE)
#define IDSM_HOST_BUFFER_GET_UINT64(bufferPtr, offset) \
    (IDSM_BUFFER_GET_UINT64(bufferPtr, offset))
#endif



/* --- IDS Protocol Header Bits Access ------------------------------------ */

/** \brief Context data bit number in IdsM protocol header in big endian format */
#if (defined IDSM_HEADER_CONTEXT_DATA_BIT)
#error IDSM_HEADER_CONTEXT_DATA_BIT already defined!
#endif
#define IDSM_HEADER_CONTEXT_DATA_BIT        0x00U

/** \brief Timestamp bit number in IdsM protocol header in big endian format */
#if (defined IDSM_HEADER_TIMESTAMP_BIT)
#error IDSM_HEADER_TIMESTAMP_BIT already defined!
#endif
#define IDSM_HEADER_TIMESTAMP_BIT           0x01U

/** \brief Signutare bit number in IdsM protocol header in big endian format */
#if (defined IDSM_HEADER_SIGNUTARE_BIT)
#error IDSM_HEADER_SIGNUTARE_BIT already defined!
#endif
#define IDSM_HEADER_SIGNUTARE_BIT           0x02U



/* --- IDS Protocol Context Data Length Encoding -------------------------- */

/** \brief Context data length is encoded with short encoding in one byte */
#if (defined IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT)
#error IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT already defined!
#endif
#define IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT     0x01U

/** \brief Context data length is encoded with long encoding in four bytes */
#if (defined IDSM_CONTEXT_DATA_LENGTH_ENCODING_LONG)
#error IDSM_CONTEXT_DATA_LENGTH_ENCODING_LONG already defined!
#endif
#define IDSM_CONTEXT_DATA_LENGTH_ENCODING_LONG      0x04U

/** \brief Get context data length encoding from IDS buffer, either short or long */
#if (defined IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING)
#error IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING is already defined
#endif
#define IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING(bufferPtr) \
    ( (((bufferPtr)[IDSM_CONTEXT_DATA_LENGTH_OFFSET] & 0x80) == 0) ? \
        (IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT) : \
        (IDSM_CONTEXT_DATA_LENGTH_ENCODING_LONG) )



/* --- IDS Protocol variable offsets  ------------------------------------- */

/** \brief Offset of protocol version and protocol header in IDS protocol */
#if (defined IDSM_PROTOCOL_HEADER_OFFSET)
#error IDSM_PROTOCOL_HEADER_OFFSET already defined!
#endif
#define IDSM_PROTOCOL_HEADER_OFFSET         0x00U

/** \brief Offset of IdsM Instance Id in IDS protocol */
#if (defined IDSM_INSTANCE_ID_OFFSET)
#error IDSM_INSTANCE_ID_OFFSET already defined!
#endif
#define IDSM_INSTANCE_ID_OFFSET             0x01U

/** \brief Offset of IdsM sensor Instance Id in IDS protocol */
#if (defined IDSM_SENSOR_INSTANCE_ID_OFFSET)
#error IDSM_SENSOR_INSTANCE_ID_OFFSET already defined!
#endif
#define IDSM_SENSOR_INSTANCE_ID_OFFSET      0x02U

/** \brief Offset of event definition in IDS protocol */
#if (defined IDSM_EVENT_DEFINITION_ID_OFFSET)
#error IDSM_EVENT_DEFINITION_ID_OFFSET already defined!
#endif
#define IDSM_EVENT_DEFINITION_ID_OFFSET     0x03U

/** \brief Offset of count in IDS protocol */
#if (defined IDSM_COUNT_OFFSET)
#error IDSM_COUNT_OFFSET already defined!
#endif
#define IDSM_COUNT_OFFSET                   0x05U

/** \brief Offset of reserved in IDS protocol */
#if (defined IDSM_RESERVED_OFFSET)
#error IDSM_RESERVED_OFFSET already defined!
#endif
#define IDSM_RESERVED_OFFSET                0x07U

/** \brief Event Frame Length */
#if (defined IDSM_EVENT_FRAME_LENGTH)
#error IDSM_EVENT_FRAME_LENGTH already defined!
#endif
#define IDSM_EVENT_FRAME_LENGTH             0x08U

/** \brief Offset of timestamp in IDS protocol */
#if (defined IDSM_TIMESTAMP_OFFSET)
#error IDSM_TIMESTAMP_OFFSET already defined!
#endif
#define IDSM_TIMESTAMP_OFFSET               0x08U

/** \brief Timestamp length in IDS protocol, because it is optional and may be used or not */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_01100,1 */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_01103,1 */
#if (defined IDSM_TIMESTAMP_LENGTH)
#error IDSM_TIMESTAMP_LENGTH already defined!
#endif
#if (IDSM_TIMESTAMP_SUPPORT == STD_ON)
#define IDSM_TIMESTAMP_LENGTH               0x08U
#else
#define IDSM_TIMESTAMP_LENGTH               0x00U
#endif /* IDSM_TIMESTAMP_SUPPORT == STD_ON */

/** \brief Minimum IDS message legnth depends on timestamp configured or not */
#if (defined IDSM_MIN_MESSAGE_LENGTH)
#error IDSM_MIN_MESSAGE_LENGTH already defined!
#endif
#define IDSM_MIN_MESSAGE_LENGTH             (IDSM_EVENT_FRAME_LENGTH + IDSM_TIMESTAMP_LENGTH)

/** \brief Offset of context data length in IDS protocol */
#if (defined IDSM_CONTEXT_DATA_LENGTH_OFFSET)
#error IDSM_CONTEXT_DATA_LENGTH_OFFSET already defined!
#endif
#define IDSM_CONTEXT_DATA_LENGTH_OFFSET     (IDSM_MIN_MESSAGE_LENGTH)

/** \brief Offset of context data when short length is used in IDS protocol */
#if (defined IDSM_CONTEXT_DATA_OFFSET_SHORT)
#error IDSM_CONTEXT_DATA_OFFSET_SHORT already defined!
#endif
#define IDSM_CONTEXT_DATA_OFFSET_SHORT      (IDSM_MIN_MESSAGE_LENGTH + 1U)

/** \brief Offset of context data when long length is used in IDS protocol */
#if (defined IDSM_CONTEXT_DATA_OFFSET_LONG)
#error IDSM_CONTEXT_DATA_OFFSET_LONG already defined!
#endif
#define IDSM_CONTEXT_DATA_OFFSET_LONG       (IDSM_MIN_MESSAGE_LENGTH + 5U)

/** \brief Maximum length for context data with short format in IDS protocol */
#if (defined IDSM_CONTEXT_DATA_SHORT_MAX_LEN)
#error IDSM_CONTEXT_DATA_SHORT_MAX_LEN already defined!
#endif
#define IDSM_CONTEXT_DATA_SHORT_MAX_LEN     0x7FU



/* --- IDS Protocol set fields  ------------------------------------------- */

/** \brief Set IDS protocol version and clear protocol header flags in buffer */
#if (defined IDSM_SET_PROTOCOL_VERSION_AND_CLEAR_HEADER)
#error IDSM_SET_PROTOCOL_VERSION_AND_CLEAR_HEADER is already defined
#endif
#define IDSM_SET_PROTOCOL_VERSION_AND_CLEAR_HEADER(bufferPtr) \
    (IDSM_BUFFER_SET_UINT8(bufferPtr, IDSM_PROTOCOL_VERSION_SHIFTED, IDSM_PROTOCOL_HEADER_OFFSET))

/** \brief Set context data flag in protocol header */
#if (defined IDSM_SET_CONTEXT_DATA_FLAG)
#error IDSM_SET_CONTEXT_DATA_FLAG is already defined
#endif
#define IDSM_SET_CONTEXT_DATA_FLAG(bufferPtr) \
    (IDSM_SET_BIT(bufferPtr[IDSM_PROTOCOL_HEADER_OFFSET], IDSM_HEADER_CONTEXT_DATA_BIT))

/** \brief Set timestamp flag in protocol header */
#if (defined IDSM_SET_TIMESTAMP_FLAG)
#error IDSM_SET_CONTEXT_DATA_FLAG is already defined
#endif
#define IDSM_SET_TIMESTAMP_FLAG(bufferPtr) \
    (IDSM_SET_BIT((bufferPtr)[IDSM_PROTOCOL_HEADER_OFFSET], IDSM_HEADER_TIMESTAMP_BIT))

/** \brief Set IDS sensor instance id value in buffer, should be used before IDSM_SET_IDSM_INSTANCE_ID. It acts as a reset for IdsM instance bits */
#if (defined IDSM_SET_SENSOR_INSTANCE_ID)
#error IDSM_SET_SENSOR_INSTANCE_ID is already defined
#endif
#define IDSM_SET_SENSOR_INSTANCE_ID(bufferPtr, value) \
    (IDSM_BUFFER_SET_UINT8(bufferPtr, ((value) & 0x3FU), IDSM_SENSOR_INSTANCE_ID_OFFSET))

/** \brief Set IDS IdsM instance id value in buffer, should be used after IDSM_SET_SENSOR_INSTANCE_ID */
#if (defined IDSM_SET_IDSM_INSTANCE_ID)
#error IDSM_SET_IDSM_INSTANCE_ID is already defined
#endif
#define IDSM_SET_IDSM_INSTANCE_ID(bufferPtr, value) \
    do \
    { \
        IDSM_BUFFER_SET_UINT8(bufferPtr, ((value) >> 2U), IDSM_INSTANCE_ID_OFFSET); \
        (bufferPtr)[IDSM_SENSOR_INSTANCE_ID_OFFSET] |= (uint8)(((value) & 0x03U) << 6); \
    } while(FALSE)

/** \brief Set IDS event definition id value in buffer serialized for ECU and same as host for external device */
#if (defined IDSM_SET_EVENT_DEFINITION_ID)
#error IDSM_SET_EVENT_DEFINITION_ID is already defined
#endif
#define IDSM_SET_EVENT_DEFINITION_ID(bufferPtr, value) \
    IDSM_BUFFER_SET_UINT16(bufferPtr, value, IDSM_EVENT_DEFINITION_ID_OFFSET)

/** \brief Set IDS count value in buffer serialized for ECU and same as host for external device */
#if (defined IDSM_SET_COUNT)
#error IDSM_SET_COUNT is already defined
#endif
#define IDSM_SET_COUNT(bufferPtr, value) \
    IDSM_BUFFER_SET_UINT16(bufferPtr, value, IDSM_COUNT_OFFSET)

/** \brief Set IDS reserved value in buffer */
#if (defined IDSM_SET_RESERVED)
#error IDSM_SET_RESERVED is already defined
#endif
#define IDSM_SET_RESERVED(bufferPtr) \
    (IDSM_BUFFER_SET_UINT8(bufferPtr, 0U, IDSM_RESERVED_OFFSET))

/** \brief Set IDS timestamp value in buffer serialized for ECU and same as host for external device */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_01110,1 */
#if (defined IDSM_SET_TIMESTAMP)
#error IDSM_SET_TIMESTAMP is already defined
#endif
#define IDSM_SET_TIMESTAMP(bufferPtr, value) \
    (IDSM_HOST_BUFFER_SET_UINT64(bufferPtr, ((uint64)(value) & 0x3FFFFFFFFFFFFFFF), IDSM_TIMESTAMP_OFFSET))

/** \brief Set IDS timestamp value in buffer from local timestamp array */
#if (defined IDSM_SET_LOCAL_TIMESTAMP_IN_BUFFER)
#error IDSM_SET_LOCAL_TIMESTAMP_IN_BUFFER is already defined
#endif
#define IDSM_SET_LOCAL_TIMESTAMP_IN_BUFFER(bufferPtr, localTimestampPtr) \
    (TS_MemCpy((bufferPtr)+(IDSM_TIMESTAMP_OFFSET), localTimestampPtr, IDSM_TIMESTAMP_LENGTH))

/** \brief Set stbm timestamp to variable in LocalTimestamp format serialized for ECU and same as host for external device */
/* !LINKSTO IdsM.ASR20-11.SWS_IdsM_01110,1 */
#if (defined IDSM_SET_LOCAL_STBM_TIMESTAMP)
#error IDSM_SET_LOCAL_STBM_TIMESTAMP is already defined
#endif
#define IDSM_SET_LOCAL_STBM_TIMESTAMP(localTimestampPtr, nanoseconds, seconds) \
    do \
    { \
        IDSM_HOST_BUFFER_SET_UINT32(localTimestampPtr, nanoseconds, 0); \
        IDSM_HOST_BUFFER_SET_UINT32(localTimestampPtr, seconds, 4); \
    } while(FALSE);

/** \brief Set IDS context data length in buffer
 *
 * When context data length is less than 128, the short approach is used which is one byte only for length, and MSB is set to 0.
 * When context data length is bigger than 128, the long approach is used which is four bytes for length, and MSB is set to 1.
 *
 */
#if (defined IDSM_SET_CONTEXT_DATA_LENGTH)
#error IDSM_SET_CONTEXT_DATA_LENGTH is already defined
#endif
#define IDSM_SET_CONTEXT_DATA_LENGTH(bufferPtr, len) \
    ( ((len) < IDSM_CONTEXT_DATA_SHORT_MAX_LEN) ? \
        (IDSM_BUFFER_SET_UINT8(bufferPtr, ((len) & 0x7FU), IDSM_CONTEXT_DATA_LENGTH_OFFSET)) : \
        (IDSM_HOST_BUFFER_SET_UINT32(bufferPtr, ((uint32)(len) | 0x80000000), IDSM_CONTEXT_DATA_LENGTH_OFFSET)) )

/** \brief Copy context data to IDS buffer offset */
#if (defined IDSM_SET_CONTEXT_DATA_OFFSET)
#error IDSM_SET_CONTEXT_DATA_OFFSET is already defined
#endif
#define IDSM_SET_CONTEXT_DATA_OFFSET(bufferPtr, offset, contextDataPtr, contextDataSize) \
    (TS_MemCpy((bufferPtr)+(offset), contextDataPtr, contextDataSize))

/** \brief Copy context data to IDS buffer
 *
 * When context data length is encoding in short length, use context data short offset
 * When context data length is encoding in long length, use context data long offset
 */
#if (defined IDSM_SET_CONTEXT_DATA)
#error IDSM_SET_CONTEXT_DATA is already defined
#endif
#define IDSM_SET_CONTEXT_DATA(bufferPtr, contextDataPtr, contextDataSize) \
    ( (IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING(bufferPtr) == IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT) ? \
        (IDSM_SET_CONTEXT_DATA_OFFSET(bufferPtr, IDSM_CONTEXT_DATA_OFFSET_SHORT, contextDataPtr, contextDataSize)) : \
        (IDSM_SET_CONTEXT_DATA_OFFSET(bufferPtr, IDSM_CONTEXT_DATA_OFFSET_LONG, contextDataPtr, contextDataSize)) )



/* --- IDS Protocol get fields  ------------------------------------------- */

/** \brief Check if context data flag is raised in protocol header in buffer */
#if (defined IDSM_CHECK_CONTEXT_DATA_FLAG)
#error IDSM_CHECK_CONTEXT_DATA_FLAG is already defined
#endif
#define IDSM_CHECK_CONTEXT_DATA_FLAG(bufferPtr) \
    (IDSM_CHECK_BIT((bufferPtr)[IDSM_PROTOCOL_HEADER_OFFSET], IDSM_HEADER_CONTEXT_DATA_BIT))

/** \brief Check if timestamp flag is raised in protocol header in buffer */
#if (defined IDSM_CHECK_TIMESTAMP_FLAG)
#error IDSM_CHECK_TIMESTAMP_FLAG is already defined
#endif
#define IDSM_CHECK_TIMESTAMP_FLAG(bufferPtr) \
    (IDSM_CHECK_BIT((bufferPtr)[IDSM_PROTOCOL_HEADER_OFFSET], IDSM_HEADER_TIMESTAMP_BIT))

/** \brief Check if signature flag is raised in protocol header in buffer */
#if (defined IDSM_CHECK_SIGNATURE_FLAG)
#error IDSM_CHECK_SIGNATURE_FLAG is already defined
#endif
#define IDSM_CHECK_SIGNATURE_FLAG(bufferPtr) \
    (IDSM_CHECK_BIT((bufferPtr)[IDSM_PROTOCOL_HEADER_OFFSET], IDSM_HEADER_SIGNUTARE_BIT))

/** \brief Get count value deserialized for ECU and as it is for External Device from IDS buffer */
#if (defined IDSM_GET_COUNT)
#error IDSM_GET_COUNT is already defined
#endif
#define IDSM_GET_COUNT(bufferPtr) \
    (IDSM_BUFFER_GET_UINT16(bufferPtr, IDSM_COUNT_OFFSET))

/** \brief Get timestamp value deserialized for ECU and as it is for External Device from IDS buffer */
#if (defined IDSM_GET_TIMESTAMP)
#error IDSM_GET_TIMESTAMP is already defined
#endif
#define IDSM_GET_TIMESTAMP(bufferPtr) \
    (IDSM_HOST_BUFFER_GET_UINT64(bufferPtr, IDSM_TIMESTAMP_OFFSET))

/** \brief Get context data value deserialized for ECU and as it is for External Device from IDS buffer */
#if (defined IDSM_GET_CONTEXT_DATA_LENGTH)
#error IDSM_GET_CONTEXT_DATA_LENGTH is already defined
#endif
#define IDSM_GET_CONTEXT_DATA_LENGTH(bufferPtr) \
    ( (IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING(bufferPtr) == IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT) ? \
        (IDSM_BUFFER_GET_UINT8(bufferPtr, IDSM_CONTEXT_DATA_LENGTH_OFFSET)) : \
        ((IDSM_HOST_BUFFER_GET_UINT32(bufferPtr, IDSM_CONTEXT_DATA_LENGTH_OFFSET)) & 0x7FFFFFFF) )

/** \brief Get number of bytes used for context data length encoding either 1 or 4 */
#if (defined IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING_LENGTH)
#error IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING_LENGTH is already defined
#endif
#define IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING_LENGTH(bufferPtr) \
    ( (IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING(bufferPtr) == IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT) ? \
    (IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT) : \
    (IDSM_CONTEXT_DATA_LENGTH_ENCODING_LONG) )

/** \brief Get context data pointer offset from IDS buffer */
#if (defined IDSM_GET_CONTEXT_DATA_OFFSET)
#error IDSM_GET_CONTEXT_DATA_OFFSET is already defined
#endif
#define IDSM_GET_CONTEXT_DATA_OFFSET(bufferPtr) \
    ( (IDSM_GET_CONTEXT_DATA_LENGTH_ENCODING(bufferPtr) == IDSM_CONTEXT_DATA_LENGTH_ENCODING_SHORT) ? \
        (IDSM_CONTEXT_DATA_OFFSET_SHORT) : (IDSM_CONTEXT_DATA_OFFSET_LONG) )



/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef IDSM_PROTOCOLACCESS_H */
/*==================[end of file]===========================================*/
