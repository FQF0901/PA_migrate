/**
 * \file
 *
 * \brief AUTOSAR Dem
 *
 * This file contains the implementation of the AUTOSAR
 * module Dem.
 *
 * \version 6.4.4
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef DEM_INT_ERR_ID_H
#define DEM_INT_ERR_ID_H

/* This file contains the configuration declarations of the
 * BSW Event ID symbols for AUTOSAR module Dem. */



/*==================[inclusions]============================================*/

/*==================[macros]================================================*/

/*------------------[Events configuration]----------------------------------*/

/* !LINKSTO Dem115,2 */
/* Symbolic names of configured BSW event IDs */

#if (defined DemConf_DemEventParameter_ECUM_E_RAM_CHECK_FAILED)
#error DemConf_DemEventParameter_ECUM_E_RAM_CHECK_FAILED already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ECUM_E_RAM_CHECK_FAILED         1U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ECUM_E_RAM_CHECK_FAILED)
#error Dem_ECUM_E_RAM_CHECK_FAILED already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ECUM_E_RAM_CHECK_FAILED         1U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE)
#error DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_CLOCK_FAILURE             2U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_CLOCK_FAILURE)
#error Dem_MCU_E_CLOCK_FAILURE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_CLOCK_FAILURE             2U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_OSC_FAILURE)
#error DemConf_DemEventParameter_MCU_E_OSC_FAILURE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_OSC_FAILURE               3U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_OSC_FAILURE)
#error Dem_MCU_E_OSC_FAILURE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_OSC_FAILURE               3U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_TIMEOUT_ERR)
#error DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_TIMEOUT_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_TIMEOUT_ERR    4U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_SYSTEM_PLL_TIMEOUT_ERR)
#error Dem_MCU_E_SYSTEM_PLL_TIMEOUT_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_SYSTEM_PLL_TIMEOUT_ERR    4U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR)
#error DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR 5U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR)
#error Dem_MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_PERIPHERAL_PLL_TIMEOUT_ERR 5U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_LOCK_LOSS)
#error DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_LOCK_LOSS already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_SYSTEM_PLL_LOCK_LOSS      6U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_SYSTEM_PLL_LOCK_LOSS)
#error Dem_MCU_E_SYSTEM_PLL_LOCK_LOSS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_SYSTEM_PLL_LOCK_LOSS      6U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_LOCK_LOSS)
#error DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_LOCK_LOSS already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_PERIPHERAL_PLL_LOCK_LOSS  7U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_PERIPHERAL_PLL_LOCK_LOSS)
#error Dem_MCU_E_PERIPHERAL_PLL_LOCK_LOSS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_PERIPHERAL_PLL_LOCK_LOSS  7U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_GTM_CLC_ENABLE_ERR)
#error DemConf_DemEventParameter_MCU_E_GTM_CLC_ENABLE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_GTM_CLC_ENABLE_ERR        8U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_GTM_CLC_ENABLE_ERR)
#error Dem_MCU_E_GTM_CLC_ENABLE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_GTM_CLC_ENABLE_ERR        8U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_GTM_CLC_DISABLE_ERR)
#error DemConf_DemEventParameter_MCU_E_GTM_CLC_DISABLE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_GTM_CLC_DISABLE_ERR       9U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_GTM_CLC_DISABLE_ERR)
#error Dem_MCU_E_GTM_CLC_DISABLE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_GTM_CLC_DISABLE_ERR       9U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_ENABLE_ERR)
#error DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_ENABLE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_ENABLE_ERR   10U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_CONVCTRL_CLC_ENABLE_ERR)
#error Dem_MCU_E_CONVCTRL_CLC_ENABLE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_CONVCTRL_CLC_ENABLE_ERR   10U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_DISABLE_ERR)
#error DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_DISABLE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_CONVCTRL_CLC_DISABLE_ERR  11U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_CONVCTRL_CLC_DISABLE_ERR)
#error Dem_MCU_E_CONVCTRL_CLC_DISABLE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_CONVCTRL_CLC_DISABLE_ERR  11U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_CCUCON_UPDATE_ERR)
#error DemConf_DemEventParameter_MCU_E_CCUCON_UPDATE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_CCUCON_UPDATE_ERR         12U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_CCUCON_UPDATE_ERR)
#error Dem_MCU_E_CCUCON_UPDATE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_CCUCON_UPDATE_ERR         12U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_CCU6_CLC_ENABLE_ERR)
#error DemConf_DemEventParameter_MCU_E_CCU6_CLC_ENABLE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_CCU6_CLC_ENABLE_ERR       13U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_CCU6_CLC_ENABLE_ERR)
#error Dem_MCU_E_CCU6_CLC_ENABLE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_CCU6_CLC_ENABLE_ERR       13U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_CCU6_CLC_DISABLE_ERR)
#error DemConf_DemEventParameter_MCU_E_CCU6_CLC_DISABLE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_CCU6_CLC_DISABLE_ERR      14U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_CCU6_CLC_DISABLE_ERR)
#error Dem_MCU_E_CCU6_CLC_DISABLE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_CCU6_CLC_DISABLE_ERR      14U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_GPT12_CLC_ENABLE_ERR)
#error DemConf_DemEventParameter_MCU_E_GPT12_CLC_ENABLE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_GPT12_CLC_ENABLE_ERR      15U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_GPT12_CLC_ENABLE_ERR)
#error Dem_MCU_E_GPT12_CLC_ENABLE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_GPT12_CLC_ENABLE_ERR      15U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_GPT12_CLC_DISABLE_ERR)
#error DemConf_DemEventParameter_MCU_E_GPT12_CLC_DISABLE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_GPT12_CLC_DISABLE_ERR     16U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_GPT12_CLC_DISABLE_ERR)
#error Dem_MCU_E_GPT12_CLC_DISABLE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_GPT12_CLC_DISABLE_ERR     16U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_MCU_E_PMSWCR_UPDATE_ERR)
#error DemConf_DemEventParameter_MCU_E_PMSWCR_UPDATE_ERR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_MCU_E_PMSWCR_UPDATE_ERR         17U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_MCU_E_PMSWCR_UPDATE_ERR)
#error Dem_MCU_E_PMSWCR_UPDATE_ERR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_MCU_E_PMSWCR_UPDATE_ERR         17U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_ACCESS)
#error DemConf_DemEventParameter_ETH_E_ACCESS already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_ACCESS                    18U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_ACCESS)
#error Dem_ETH_E_ACCESS already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_ACCESS                    18U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_ALIGNMENT)
#error DemConf_DemEventParameter_ETH_E_ALIGNMENT already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_ALIGNMENT                 19U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_ALIGNMENT)
#error Dem_ETH_E_ALIGNMENT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_ALIGNMENT                 19U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_CRC)
#error DemConf_DemEventParameter_ETH_E_CRC already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_CRC                       20U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_CRC)
#error Dem_ETH_E_CRC already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_CRC                       20U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_LATECOLLISION)
#error DemConf_DemEventParameter_ETH_E_LATECOLLISION already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_LATECOLLISION             21U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_LATECOLLISION)
#error Dem_ETH_E_LATECOLLISION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_LATECOLLISION             21U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_MULTIPLECOLLISION)
#error DemConf_DemEventParameter_ETH_E_MULTIPLECOLLISION already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_MULTIPLECOLLISION         22U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_MULTIPLECOLLISION)
#error Dem_ETH_E_MULTIPLECOLLISION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_MULTIPLECOLLISION         22U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_OVERSIZEFRAME)
#error DemConf_DemEventParameter_ETH_E_OVERSIZEFRAME already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_OVERSIZEFRAME             23U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_OVERSIZEFRAME)
#error Dem_ETH_E_OVERSIZEFRAME already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_OVERSIZEFRAME             23U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_RX_FRAMES_LOST)
#error DemConf_DemEventParameter_ETH_E_RX_FRAMES_LOST already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_RX_FRAMES_LOST            24U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_RX_FRAMES_LOST)
#error Dem_ETH_E_RX_FRAMES_LOST already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_RX_FRAMES_LOST            24U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_SINGLECOLLISION)
#error DemConf_DemEventParameter_ETH_E_SINGLECOLLISION already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_SINGLECOLLISION           25U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_SINGLECOLLISION)
#error Dem_ETH_E_SINGLECOLLISION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_SINGLECOLLISION           25U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_ETH_E_UNDERSIZEFRAME)
#error DemConf_DemEventParameter_ETH_E_UNDERSIZEFRAME already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_ETH_E_UNDERSIZEFRAME            26U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_ETH_E_UNDERSIZEFRAME)
#error Dem_ETH_E_UNDERSIZEFRAME already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_ETH_E_UNDERSIZEFRAME            26U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_DEM_SPI)
#error DemConf_DemEventParameter_DEM_SPI already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_DEM_SPI                         27U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_DEM_SPI)
#error Dem_DEM_SPI already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_DEM_SPI                         27U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR)
#error DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_SPI_E_HARDWARE_ERROR            28U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_SPI_E_HARDWARE_ERROR)
#error Dem_SPI_E_HARDWARE_ERROR already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_SPI_E_HARDWARE_ERROR            28U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_CANSM_E_BUS_OFF_1)
#error DemConf_DemEventParameter_CANSM_E_BUS_OFF_1 already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_CANSM_E_BUS_OFF_1               29U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_CANSM_E_BUS_OFF_1)
#error Dem_CANSM_E_BUS_OFF_1 already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_CANSM_E_BUS_OFF_1               29U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FLS_E_COMPARE_FAILED)
#error DemConf_DemEventParameter_FLS_E_COMPARE_FAILED already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FLS_E_COMPARE_FAILED            30U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FLS_E_COMPARE_FAILED)
#error Dem_FLS_E_COMPARE_FAILED already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FLS_E_COMPARE_FAILED            30U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FLS_E_ERASE_FAILED)
#error DemConf_DemEventParameter_FLS_E_ERASE_FAILED already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FLS_E_ERASE_FAILED              31U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FLS_E_ERASE_FAILED)
#error Dem_FLS_E_ERASE_FAILED already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FLS_E_ERASE_FAILED              31U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FLS_E_READ_FAILED)
#error DemConf_DemEventParameter_FLS_E_READ_FAILED already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FLS_E_READ_FAILED               32U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FLS_E_READ_FAILED)
#error Dem_FLS_E_READ_FAILED already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FLS_E_READ_FAILED               32U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FLS_E_UNEXPECTED_FLASH_ID)
#error DemConf_DemEventParameter_FLS_E_UNEXPECTED_FLASH_ID already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FLS_E_UNEXPECTED_FLASH_ID       33U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FLS_E_UNEXPECTED_FLASH_ID)
#error Dem_FLS_E_UNEXPECTED_FLASH_ID already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FLS_E_UNEXPECTED_FLASH_ID       33U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FLS_E_WRITE_FAILED)
#error DemConf_DemEventParameter_FLS_E_WRITE_FAILED already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FLS_E_WRITE_FAILED              34U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FLS_E_WRITE_FAILED)
#error Dem_FLS_E_WRITE_FAILED already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FLS_E_WRITE_FAILED              34U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_GC_INIT)
#error DemConf_DemEventParameter_FEE_E_GC_INIT already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_GC_INIT                   35U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_GC_INIT)
#error Dem_FEE_E_GC_INIT already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_GC_INIT                   35U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_WRITE)
#error DemConf_DemEventParameter_FEE_E_WRITE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_WRITE                     36U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_WRITE)
#error Dem_FEE_E_WRITE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_WRITE                     36U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_READ)
#error DemConf_DemEventParameter_FEE_E_READ already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_READ                      37U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_READ)
#error Dem_FEE_E_READ already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_READ                      37U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_GC_READ)
#error DemConf_DemEventParameter_FEE_E_GC_READ already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_GC_READ                   38U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_GC_READ)
#error Dem_FEE_E_GC_READ already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_GC_READ                   38U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_GC_WRITE)
#error DemConf_DemEventParameter_FEE_E_GC_WRITE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_GC_WRITE                  39U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_GC_WRITE)
#error Dem_FEE_E_GC_WRITE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_GC_WRITE                  39U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_GC_ERASE)
#error DemConf_DemEventParameter_FEE_E_GC_ERASE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_GC_ERASE                  40U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_GC_ERASE)
#error Dem_FEE_E_GC_ERASE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_GC_ERASE                  40U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_INVALIDATE)
#error DemConf_DemEventParameter_FEE_E_INVALIDATE already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_INVALIDATE                41U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_INVALIDATE)
#error Dem_FEE_E_INVALIDATE already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_INVALIDATE                41U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_WRITE_CYCLES_EXHAUSTED)
#error DemConf_DemEventParameter_FEE_E_WRITE_CYCLES_EXHAUSTED already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_WRITE_CYCLES_EXHAUSTED    42U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_WRITE_CYCLES_EXHAUSTED)
#error Dem_FEE_E_WRITE_CYCLES_EXHAUSTED already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_WRITE_CYCLES_EXHAUSTED    42U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_GC_TRIG)
#error DemConf_DemEventParameter_FEE_E_GC_TRIG already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_GC_TRIG                   43U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_GC_TRIG)
#error Dem_FEE_E_GC_TRIG already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_GC_TRIG                   43U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DemConf_DemEventParameter_FEE_E_UNCONFIG_BLK_EXCEEDED)
#error DemConf_DemEventParameter_FEE_E_UNCONFIG_BLK_EXCEEDED already defined
#endif
/** \brief Export symbolic name value */
#define DemConf_DemEventParameter_FEE_E_UNCONFIG_BLK_EXCEEDED     44U
#if (defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dem_FEE_E_UNCONFIG_BLK_EXCEEDED)
#error Dem_FEE_E_UNCONFIG_BLK_EXCEEDED already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only (3.1 rev4 < AUTOSAR version <= AUTOSAR 4.0 rev2) **/
#define Dem_FEE_E_UNCONFIG_BLK_EXCEEDED     44U
#endif /* defined DEM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef DEM_INT_ERR_ID_H */
/*==================[end of file]===========================================*/
