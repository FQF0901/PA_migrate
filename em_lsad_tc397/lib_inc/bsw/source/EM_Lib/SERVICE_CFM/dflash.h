
#ifndef DFLASH_H__
#define DFLASH_H__

#include "Std_Types.h"

#ifdef  __cplusplus
extern "C" {
#endif

//_________________________________________________________________________________________________
// Macro define
#define EEPROM_SIZE_IN_BYTES    10240U

//_________________________________________________________________________________________________
// Enum define
typedef enum
{
    EEPROM_OK,
    EEPROM_BUSY,
    EEPROM_ERR_NOT_OK,
    EEPROM_ERR_ADDRESS_OUT_OF_RANGE,
    EEPROM_ERR_OPER,                /**< \brief Flash Operation Error - OPER (rh) */
    EEPROM_ERR_SQER,                /**< \brief Command Sequence Error - SQER (rh) */
    EEPROM_ERR_PROER,               /**< \brief Protection Error - PROER (rh) */
    EEPROM_ERR_PVER,                /**< \brief Program Verify Error - PVER (rh) */
    EEPROM_ERR_EVER,                /**< \brief Erase Verify Error - EVER (rh) */
    EEPROM_ERR_ADER,                /**< \brief SRI Bus Address ECC Error - ADER (rh) */
    EEPROM_ERR_ORIER,               /**< \brief Original Error - ORIER (rh) */
}eeStatus_e;
//_________________________________________________________________________________________________
// Function description
extern int eeprom_write(uint32 addr, uint8 *pBuf, uint32 bytes);
extern int eeprom_read (uint32 addr, uint8 *pBuf, uint32 bytes);

#ifdef  __cplusplus
}
#endif

#endif  // DFLASH_H__
