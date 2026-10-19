/**
 * @file    us_driver_elmos.h
 * @brief   Elmos Ultrasonic Transducer Driver and Signal Processor (E524.09).
 * @details This is the detail description.
 * 
 * @date    2021.04.07 (created)
 * @version V1.1
 * @par Copyright (C):
 *          
 * @par Encoding:
 *          UTF-8
 * @par Description:
 *  1. Hardware Descriptions:
 *      None.
 *  2. Program Architecture:
 *      None.
 *  3. File Usage:
 *      None.
 *  4. Limitations:
 *      None.
 *  5. Else:
 *      None.
 * @par Modification:
 *  -# Date     : 2021.05.14;
 *     Revision : V1.1;
 *     
 *     Contents : add US_Get_READ_TEMP_WithDiagnostic function.
 */

#ifndef US_DRIVER_ELMOS_H_
#define US_DRIVER_ELMOS_H_

/*  ===========================================================================
 *                              header files
 *  =========================================================================*/
#include "proj_global.h"

/*  ===========================================================================
 *                          macros & constants
 *  =========================================================================*/
#define US_DRIVER_DEPRECATED_ON			///< used for "us_driver_elmos.h"
#define USH_ECHO_NUM_MAX            5U  ///< 5 echoes

/** ***********************************
 * @brief   Description of enum typedef.
 *************************************/
typedef enum
{
    US_Diag_Normal         = 0x00000000U,             /** US IO normal. */
    US_Diag_SC             = 0x00000001U,             /** US IO short circuit. */
    US_Diag_OC             = 0x00000002U,             /** US IO open circuit. */
    US_Diag_IO_Check_Err   = 0x00000004U,             /** US IO command send recheck difference */
    US_Diag_Comm_Check_Err = 0x00000008U,             /** US IO command receive data error */
    Us_Diag_Comm_IO_Err    = 0x00000010U,             /** US IO command receive pulse error*/
    Us_Diag_Driver_Err     = 0x00000020U,             /** US driver error*/
    Us_Diag_Input_Err      = 0x00000040U              /** US driver input error*/
} US_Diag_State;

/** ***********************************
 * @brief   echo reporting (measurement).
 *************************************/
typedef struct USH_EchoData
{
    uint16 echoTime[USH_ECHO_NUM_MAX];  /** unit: (us). */
    uint16 pulseWidth[USH_ECHO_NUM_MAX];/** unit: (us). */
    uint32 RisingEdgeTimeStamp;         /** unit: (us). */
    uint32 MeasStartEdgeTimeStamp;      /** unit: (us). */
    uint32 RingingTimeEdgeTimeStamp;    /** unit: (us). */
    uint64 SendingCommandTimeStamp;     /** unit: (us). */
    uint8  RingingDetect;               /** 1: output adjusted echoTime because of ringring time */
    uint8  echoNum;                     /** num of echoes */
}tUSH_EchoData;

/** ***********************************
 * @brief   Table 5.9.2.5-1: Status wrap up bits.
 *************************************/
typedef struct
{
    uint8 NoiseFlg;        /** (1b) Noise detected during last measurement command */
    uint8 VolErr;          /** (1b) Indication that a supply voltage outside spec occurred or
                             default threshold values or default measurement profiles are active. */
    uint8 FreqDev;         /** (2b) ringing frequency deviation, |freq_dev| */
    uint8 EchoHeight;      /** (6b) the echo height of the first detected echo. */
}ST_US_DiagDataBitType;

/** ***********************************
 * @brief   Table 5.9.3-1: Configuration of threshold setup.
 *************************************/
typedef struct
{
    uint8 THVAL2;           /** (5b) 2nd threshold value */
    uint8 THVAL3;           /** (5b) 3rd threshold value */
    uint8 THVAL4;           /** (5b) 4th threshold value */
    uint8 THVAL5;           /** (5b) 5th threshold value */
    uint8 THVAL6;           /** (5b) 6th threshold value */
    uint8 THVAL7;           /** (5b) 7th threshold value */
    uint8 THVAL8;           /** (5b) 8th threshold value */
    uint8 THVAL9;           /** (5b) 9th threshold value */
    uint8 THVAL10;          /** (5b) 10th threshold value */
    uint8 THVAL11;          /** (5b) 11th threshold value */
    uint8 THVAL12;          /** (5b) 12th threshold value */
    uint8 THVAL13;          /** (5b) 13th threshold value */
    uint8 THSFT_CFG;        /** (2b) Threshold position shift configuration: */
    uint8 ATG_CFG;          /** (2b) Automatic threshold configuration: */
    uint8 ATG_TAU;          /** (2b) Time constant of ATG */
    uint8 ATG_ALPHA;        /** (1b) Multiplier of ATG */
    uint8 THRESSCALE_REC;   /** (2b) Down scaling in receive mode: */
}US_THRESHOLD_DATA;

/** ***********************************
 * @brief   Table 5.9.5-1: Configuration of measurement setup.
 *************************************/
typedef struct
{
    uint8 NPULSES_A       ; /** (3b) Number of burst pulses - Profile A */
    uint8 TMEAS_A         ; /** (3b) Measurement time - Profile A */
    uint8 THRESSCALE_A    ; /** (2b) Threshold scaling factor - Profile A */
    uint8 NPULSES_B       ; /** (3b) Number of burst pulses - Profile B */
    uint8 TMEAS_B         ; /** (3b) Measurement time - Profile B */
    uint8 THRESSCALE_B    ; /** (2b) Threshold scaling factor - Profile B */
    uint8 NPULSES_C       ; /** (3b) Number of burst pulses - Profile C */
    uint8 TMEAS_C         ; /** (3b) Measurement time - Profile C */
    uint8 THRESSCALE_C    ; /** (2b) Threshold scaling factor - Profile C */
    uint8 ECHO_DEB        ; /** (1b) Echo debouncing: */
    uint8 RT_CFG          ; /** (1b) Ringing time configuration */
    uint8 NFTG            ; /** (1b) Near field threshold generation: */
    uint8 FTC             ; /** (1b) Fast Time Constant method: */
    uint8 EPD             ; /** (1b) Echo Peak Detection */
    uint8 STC_CFG         ; /** (2b) STC configuration: */
    uint8 STC_START       ; /** (2b) STC start time: */
    uint8 NOISE_CFG       ; /** (2b) Noise threshold for noise measurement: */
    uint8 FILTER_CFG      ; /** (1b) Digital Filter configuration */
}US_MEASSETUP_DATA;

/** ***********************************
 * @brief   Table 5.9.7: Read Status: Bits 0-9.
 *************************************/
typedef struct
{
    uint8 FreqDev;          /** (5b) frequency deviation between the transducer driver and its resonance frequency */
    uint8 FreqValid;        /** (1b) Result of frequency measurement */
    uint8 ThresActive;      /** (1b) (Default / Transmitted threshold) values active */
    uint8 MeasActive;       /** (1b) (Default / Transmitted measurement) profiles active */
    uint8 OverVol;          /** (1b) Overvoltage detected during last measurement cycle */
    uint8 UnderVol;         /** (1b) Undervoltage detected during last measurement cycle */
}ST_US_StatusDataBitType;

/** ***********************************
 * @brief   Figure 5.9.11-1: calibration/EEPROM organization.
 *************************************/
typedef struct
{
    uint8 OSC_TRIM;         /** (4b) oscillator trimming If no trimming is required use '0000' */
    uint8 CUSTOMER_BITS;    /** (7b) free configurable */
    uint8 G_DIG;            /** (7b) Digital amplifier gain configuration */
    uint8 G_ANA;            /** (3b) Analog amplifier gain adjustment */
    uint8 I_DRV;            /** (5b) Transducer driver output current configuration */
    uint8 F_DRV;            /** (8b) Driver frequency */
}US_CAL_DATA;

/*  ===========================================================================
 *                      global variable declarations
 *  =========================================================================*/

/*  ===========================================================================
 *                      global function declarations
 *  =========================================================================*/
/** ***************************************************************************
 * @brief       SEND_A / RECEIVE_A
 * @details     Initiates a burst signal via the internal drivers followed by a measurement
 *              sequence and a status sequence. Measurement parameters of profile A
 *              from MEAS_SETUP register are used.
 *              Initiates a measurement sequence without preceding burst, useful for triangulation
 *              in systems with multiple transducers. The measurement
 *              sequence is followed by a status sequence. Measurement parameters of
 *              profile A from MEAS_SETUP register are used.
 *****************************************************************************/
extern Std_ReturnType US_Trans_SEND_A           (uint8 sensorIdx);
extern Std_ReturnType US_Get_SEND_A             (uint8 sensorIdx, tUSH_EchoData *echoData, ST_US_DiagDataBitType *echoStatus);
extern Std_ReturnType US_Trans_RECEIVE_A        (uint8 sensorIdx);
extern Std_ReturnType US_Get_RECEIVE_A          (uint8 sensorIdx, tUSH_EchoData *echoData, ST_US_DiagDataBitType *echoStatus);

/** ***************************************************************************
 * @brief       SEND_B / RECEIVE_B
 * @details     Initiates a burst signal via the internal drivers followed by a measurement
 *              sequence and a status sequence. Measurement parameters of profile B
 *              from MEAS_SETUP register are used.
 *              Initiates a measurement sequence without preceding burst, useful for triangulation
 *              in systems with multiple transducers. The measurement
 *              sequence is followed by a status sequence. Measurement parameters of
 *              profile B from MEAS_SETUP register are used.
 *****************************************************************************/
extern Std_ReturnType US_Trans_SEND_B           (uint8 sensorIdx);
extern Std_ReturnType US_Get_SEND_B             (uint8 sensorIdx, tUSH_EchoData *echoData, ST_US_DiagDataBitType *echoStatus);
extern Std_ReturnType US_Trans_RECEIVE_B        (uint8 sensorIdx);
extern Std_ReturnType US_Get_RECEIVE_B          (uint8 sensorIdx, tUSH_EchoData *echoData, ST_US_DiagDataBitType *echoStatus);

/** ***************************************************************************
 * @brief       SEND_C / RECEIVE_C
 * @details     Initiates a burst signal via the internal drivers followed by a measurement
 *              sequence and a status sequence. Measurement parameters of profile C
 *              from MEAS_SETUP register are used.
 *              Initiates a measurement sequence without preceding burst, useful for triangulation
 *              in systems with multiple transducers. The measurement
 *              sequence is followed by a status sequence. Measurement parameters of
 *              profile C from MEAS_SETUP register are used.
 *****************************************************************************/
extern Std_ReturnType US_Trans_SEND_C           (uint8 sensorIdx);
extern Std_ReturnType US_Get_SEND_C             (uint8 sensorIdx, tUSH_EchoData *echoData, ST_US_DiagDataBitType *echoStatus);
extern Std_ReturnType US_Trans_RECEIVE_C        (uint8 sensorIdx);
extern Std_ReturnType US_Get_RECEIVE_C          (uint8 sensorIdx, tUSH_EchoData *echoData, ST_US_DiagDataBitType *echoStatus);

/** ***************************************************************************
 * @brief       THRES_SETUP / READ_THRES_SETUP
 * @details     Writes individual values for the static threshold generation and its scaling
 *              in receive mode into the device. Additionally the dynamic threshold generation
 *              can be activated and configured.
 *              Reads values of the threshold configuration (THRES_SETUP) from the
 *              volatile memory of the device.
 *****************************************************************************/
extern Std_ReturnType US_Trans_THRES_SETUP      (uint8 sensorIdx, const US_THRESHOLD_DATA *threshold);
extern Std_ReturnType US_Trans_READ_THRES_SETUP (uint8 sensorIdx);
extern Std_ReturnType US_Get_READ_THRES_SETUP   (uint8 sensorIdx, US_THRESHOLD_DATA *threshold);

/** ***************************************************************************
 * @brief       MEAS_SETUP / READ_MEAS_SETUP
 * @details     Writes individual measurement setup for up to 3 profiles (number of
 *              burst pulses, measurement time and scaling) into the device. Additionally
 *              settings for STC, noise and filter can be configured.
 *              Reads values of the measurement configuration (MEAS_SETUP) from the
 *              volatile memory of the device.
 *****************************************************************************/
extern Std_ReturnType US_Trans_MEAS_SETUP       (uint8 sensorIdx, const US_MEASSETUP_DATA *meassetup);
extern Std_ReturnType US_Trans_READ_MEAS_SETUP  (uint8 sensorIdx);
extern Std_ReturnType US_Get_READ_MEAS_SETUP    (uint8 sensorIdx, US_MEASSETUP_DATA *meassetup);

/** ***************************************************************************
 * @brief       READ_STATUS
 * @details     Verifies previous transmission of THRES_SETUP and MEAS_SETUP, reads
 *              current noise status, reads frequency deviation between driver and resonance
 *              frequency, reads overvoltage, undervoltage and reset state.
 *****************************************************************************/
extern Std_ReturnType US_Trans_READ_STATUS      (uint8 sensorIdx);
extern Std_ReturnType US_Get_READ_STATUS        (uint8 sensorIdx, ST_US_StatusDataBitType *status);

/** ***************************************************************************
 * @brief       CAL_PULSES
 * @details     Returns 2 pulses with a defined interval of TCAL for transducer driver frequency
 *              calibration purposes.
 *****************************************************************************/
extern Std_ReturnType US_Trans_CAL_PULSES       (uint8 sensorIdx);
extern Std_ReturnType US_Get_CAL_PULSES         (uint8 sensorIdx, uint32* calPulseWidth);

/** ***************************************************************************
 * @brief       READ_TEMP
 * @details     Returns the ADC value of the temperature sensor.
 *****************************************************************************/
extern Std_ReturnType US_Trans_READ_TEMP        (uint8 sensorIdx);
extern Std_ReturnType US_Get_READ_TEMP          (uint8 sensorIdx, float32 *temp);

/** ***************************************************************************
 * @brief       ENVELOPE_SEND_A / ENVELOPE_REC_A
 * @details     Initiates a burst signal via the internal drivers followed by a measurement
 *              sequence of profile A. Instead of the echo detection the envelope signal is
 *              shown on the IO line.
 *              Initiates a measurement sequence of profile A without preceding burst.
 *              Instead of the echo detection the envelope signal is shown on the IO line.
 *****************************************************************************/
extern Std_ReturnType US_Trans_ENVELOPE_SEND_A  (uint8 sensorIdx);
extern Std_ReturnType US_Trans_ENVELOPE_REC_A   (uint8 sensorIdx);

/** ***************************************************************************
 * @brief       CALIB_WRITE / CALIB_READ
 * @details     Allows to pre-load settings for the driver frequency, driver current, analog
 *              and digital amplifier gain into the device.
 *              Reads the calibration registers to verify CALIB_WRITE.
 *****************************************************************************/
extern Std_ReturnType US_Trans_CALIB_WRITE      (uint8 sensorIdx, const US_CAL_DATA *eepromData);
extern Std_ReturnType US_Trans_CALIB_READ       (uint8 sensorIdx);
extern Std_ReturnType US_Get_CALIB_READ         (uint8 sensorIdx, US_CAL_DATA *eepromData);

#ifdef US_DRIVER_DEPRECATED_ON
/** ***************************************************************************
 * @brief       EE_COPY / EE_READ
 * @details     Copies the settings from the calibration register into the internal EEPROM.
 *              Reads the EEPROM contents with three read voltage levels to verify successful
 *              programming.
 *****************************************************************************/
extern Std_ReturnType US_Trans_EE_COPY          (uint8 sensorIdx);
extern Std_ReturnType US_Trans_EE_READ          (uint8 sensorIdx);
extern Std_ReturnType US_Get_EE_READ            (uint8 sensorIdx, US_CAL_DATA* eepromData);
#endif

/** ***************************************************************************
 * @brief       READ_ID
 * @details     A 24 bit chip ID is transferred on the IO line.
 *****************************************************************************/
extern Std_ReturnType US_Trans_READ_ID          (uint8 sensorIdx);
extern Std_ReturnType US_Get_READ_ID            (uint8 sensorIdx, uint32* chipId);

/** ***************************************************************************
 * @brief       STANDBY / WAKE_UP
 * @details     Initiates standby mode to decrease current consumption.
 *              Initiates a wake up from standby mode.
 *****************************************************************************/
extern Std_ReturnType US_Trans_STANDBY          (uint8 sensorIdx);
extern Std_ReturnType US_Trans_WAKE_UP          (uint8 sensorIdx);

/** ***************************************************************************
 * @brief       READ_TEMP with diagnostic
 * @details     Returns the ADC value of the temperature sensor & diagnostic status.
 *****************************************************************************/
extern Std_ReturnType US_Get_READ_TEMP_WithDiagnostic (uint8 sensorIdx, float32 *temp, US_Diag_State *diagState);

/** \brief The function executes to get the verison information of us low level driver
 *
 * \param void : Void
 *
 * \return Description of the return
 * \retval uint16 : 16bit version infromation, for example 0x0020
 *
 */
extern uint16 US_version_get(void);

#if 0
/** \brief The function executes to initialize the Blind Zone Boundary
 *
 * \param void : Void
 *
 * \return Description of the return
 * \retval void.
 *
 */
extern void US_Set_ReceiveEchoBlindZone_Boundary(uint8 sensorIdx, uint16 MaxLength, uint16 MinLength);
#endif
/** \brief The function 
 *
 * \param void : Void
 *
 * \return Description of the return
 * \retval void : 
 *
 */
void Us_Reset_RingingTimeCnts(uint8 sensorIdx);

/** \brief The function 
 *
 * \param void : Void
 *
 * \return Description of the return
 * \retval void : 
 *
 */
void US_SetSensorRandomWaitingTime(uint8 sensorIdx, uint8 cmd, uint32 time);

/** \brief The function executes to initialize the hardware resource of US related modules
 *
 * \param void : Void
 *
 * \return Description of the return
 * \retval uint8 : If the initialization sucessfully, it will return 0, else it will return 1.
 *
 */
extern uint8 US_Init(void);

/** \brief 
 *
 * \param void : Void
 *
 * \return Description of the return
 *
 */
uint32 US_Get_Driver_Diagnose_Status(uint8 sensorIdx);

/** \brief 
 *
 * \param void : Void
 *
 * \return Description of the return
 *
 */
uint32 US_Get_Driver_Error_Pulse(uint8 sensorIdx);

#endif /* US_DRIVER_ELMOS_H_ */
/******************************************************************************
 *                                  EOF
 *****************************************************************************/
