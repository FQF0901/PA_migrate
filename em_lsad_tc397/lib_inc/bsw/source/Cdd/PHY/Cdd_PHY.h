#ifndef CDD_PHY_H
#define CDD_PHY_H
#include "IfxGeth_reg.h"
#include "Platform_Types.h"

typedef struct _Phy_Link_State_Bits
{
    uint32 reserved_0:16;   /**< \brief [15: 0] Reserved */
    uint32 LNKMOD:1;        /**< \brief [16:16] Link Mode - LNKMOD (r) */
    uint32 LNKSPEED:2;      /**< \brief [18:17] Link Speed - LNKSPEED (r) */
    uint32 LNKSTS:1;        /**< \brief [19:19] Link Status - LNKSTS (r) */
    uint32 reserved_20:12;  /**< \brief [31:20] Reserved */

} Phy_Link_State_Bits;

typedef union _Phy_Link_State
{
    uint32 U;                 /**< \brief Unsigned access */
    Phy_Link_State_Bits B;    /**< \brief Bitfield access */
}Phy_Link_State;

#define CDD_PHY_WAIT_MDIO_READY(void) while (GETH_MAC_MDIO_ADDRESS.B.GB) {}


#define PHY_DEVICE_ADDRESS   0x00
/******************************************************************************************************************/
/**********************************************PHY register********************************************************/
/*Common Register*/
#define MII_BMCR                    (0x00U)     /* Basic Control register */
#define MII_BMSR                    (0x01U)     /* Basic Status register */
#define MII_PHYID1                  (0x02U)     /* PHY identification register 1 */
#define MII_PHYID2                  (0x03U)     /* PHY identification register 2 */
#define MII_ESTATUS                 (0x0FU)     /* Extended Status register */
// NXP specific registers
#define MII_PHYID3                  (0x10U)     /* PHY identification register 3 */
#define MII_ECTRL                   (0x11U)     /* extended_control register (TJA1100 and TJA1102) */
#define MII_CFG1                    (0x12U)     /* configuration_1 register (TJA1100 and TJA1102) */
#define MII_CFG2                    (0x13U)     /* configuration_2 register (TJA1100 and TJA1102) */
#define MII_SYMERRCNT               (0x14U)     /* symbol_error_counter register (TJA1100 and TJA1102) */
#define MII_INTSRC                  (0x15U)     /* interrupt_source_flag register (TJA1100 and TJA1102) */
#define MII_INTMASK                 (0x16U)     /* interrupt_mask register (TJA1100 and TJA1102) */
#define MII_COMMSTAT                (0x17U)     /* communication_status register (TJA1100 and TJA1102) */
#define MII_GENSTAT                 (0x18U)     /* general_status register (TJA1100 and TJA1102) */
#define MII_EXTSTATUS               (0x19U)     /* external_status register (TJA1100 and TJA1102) */
#define MII_LINKFAILCNT             (0x1AU)     /* link_fail_counter register (TJA1100 and TJA1102) */
#define MII_COMMCFG                 (0x1BU)     /* common_configuration register (only TJA1102) */
#define MII_CFG3                    (0x1CU)     /* configuration_3 register (only TJA1102) */
/******************************************************************************************************************/

/*BMCR detial*/
#define BMCR_RESET                  ((uint16)(0x01) << (15))
#define BMCR_SPEED_SEL_LSB          ((uint16)(0x01) << (13))
#define BMCR_SPEED_SEL_MSB          ((uint16)(0x01) << (6))
#define BMCR_POWERDOWN              ((uint16)(0x01) << (11))
#define BMCR_DUPLEX_MODE            ((uint16)(0x01) << (8))
#define BMCR_SPEED_SEL_10M          (0x00)
#define BMCR_SPEED_SEL_100M         (BMCR_SPEED_SEL_LSB)
#define BMCR_SPEED_SEL_1000M        (BMCR_SPEED_SEL_MSB)

/*ECTRL detial*/
#define ECTRL_LINK_CONTROL_MASK             ((uint16)(0x01) << (15))
#define ECTRL_LINK_CONTROL                  ((uint16)(0x01) << (15))
#define ECTRL_POWER_MODE_MASK               ((uint16)(0x0F) << (11))
#define ECTRL_POWER_MODE_NORMAL             ((uint16)(0x03) << (11))
#define ECTRL_CONFIG_EN_MASK                ((uint16)(0x01) << (2))
#define ECTRL_CONFIG_EN                     ((uint16)(0x01) << (2))

/* CFG1 detial*/
#define CFG1_MASTER_SLAVE_MASK              ((uint16)(0x01) << (15))
#define CFG1_FWDPHYLOC_MASK                 ((uint16)(0x01) << (14))
#define CFG1_SLEEP_CONFIRM_MASK             ((uint16)(0x01) << (6))

/* CFG3 detial*/
#define CFG3_MDI_POL_MASK                   ((uint16)(0x01) << (2))
#define CFG3_FORCE_SLEEP_MASK               ((uint16)(0x01) << (1))

/* CFG2 detial*/
#define CFG2_SLEEP_REQUEST_TO_MASK          ((uint16)(0x03) << (0))
#define CFG2_SLEEP_REQUEST_TO               ((uint16)(0x03) << (0))

/*COMMSTAT detial*/
#define COMMSTAT_LINK_UP                    ((uint16)(0x01) << (15))  


void Cdd_PHY_SoftRest(void);
void Cdd_PHY_SetRegisterBits(const uint8 CtrlIdx,const uint8 TrcvIdx,const uint8 RegIdx, uint16 Reg_mask, uint16 Reg_Data);
uint16 Cdd_PHY_GetRegisterValue(const uint8 CtrlIdx,const uint8 TrcvIdx,const uint8 RegIdx);
void Cdd_PHY_SetRegisterBit(const uint8 CtrlIdx,const uint8 TrcvIdx,const uint8 RegIdx, uint16 Reg_mask,boolean BitFlag);
void Cdd_PHY_CleanRegisterBit(const uint8 CtrlIdx,const uint8 TrcvIdx,const uint8 RegIdx, uint16 Reg_mask);
void Cdd_PHY_IOInit(void);
void Cdd_PHY_Init(void);
#endif