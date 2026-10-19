/**
 * @file	rte_ultrasonic.h
 * @brief	This is a brief description of file rte_ultrasonic.h.
 * @details	This is the detail description.
 * 
 * @version	0.0.2
 * @par Copyright (C):
 *			
 * @par Encoding:
 *			UTF-8
 * @par Description:
 *	1. Hardware Descriptions:
 *		None.
 *	2. Program Architecture:
 *		None.
 *	3. File Usage:
 *		None.
 *	4. Limitations:
 *		None.
 *	5. Else:
 *		None.
 * @par Modification:
 *	-# Date     : 2020.--.--;
 *	   Revision : 0.0.1;
 *	   
 *	   Contents : Co.
 */

#ifndef ULTRASONIC_RTE_ULTRASONIC_H_
#define ULTRASONIC_RTE_ULTRASONIC_H_

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */

/*	===========================================================================
 *								header files
 *	=========================================================================*/
#include "proj_global.h"
#include "rte.h"
#if US_ON_SOC
#include "utrasonic_interface.h"
#endif

/*	===========================================================================
 *							macros & constants
 *	=========================================================================*/

/*	===========================================================================
 *						data structure declarations
 *	=========================================================================*/

/*	===========================================================================
 *						global variable declarations
 *	=========================================================================*/

/*	===========================================================================
 *						global function declarations
 *	=========================================================================*/
/** ***************************************************************************
 * @brief
 * @details		This is a detail description of foo.
 * @return		Timestamp (unit: usec).
 *****************************************************************************/
extern TimestampType UsSysTm_GetPowOnTimestamp(void);

/** ***************************************************************************
 * @brief
 * @details		1970-01-01T00:00:00Z.
 * @return		Unix Timestamp (unit: usec).
 *****************************************************************************/
extern TimestampType UsSysTm_GetUnixTimestamp(void);

/*	===========================================================================
 *									RTE
 *	=========================================================================*/
/** ***************************************************************************
 * @brief		Switch status.
 * @details		This is a detail description of foo.
 * @param[out]	usSysSwt: output argument description.
 *				@arg APA_US_SWT_OFF:
 *				@arg APA_US_SWT_STANDBY:
 *				@arg APA_US_SWT_ON:
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Read_USH_UltrasonicSysSwt					(		tAPA_UltrasonicSwtCtrl	*usSysSwt				);

/** ***************************************************************************
 * @brief		PDC
 * @details		PDC
 * @param[out]	usPdcAssociSysAbnor: output argument description.
 *				@arg NORMAL:
 *				@arg ABNORMAL:
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Read_USH_PdcAssociatedSysAbnormal			(		tNormalSts				*usPdcAssociSysAbnor	);

/** ***************************************************************************
 * @brief		Power fault status
 * @details		This is a detail description of foo.
 * @param[out]	usPwrFaultSts: output argument description.
 *				@arg NO_FAULT:
 *				@arg FAULT:
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Read_USH_UsPwrFaultSts					(		tFaultSts				*usPwrFaultSts			);

/** ***************************************************************************
 * @brief		Power status
 * @details		This is a detail description of foo.
 * @param[out]	usPwrSwtSts: output argument description.
 *				@arg OFF:
 *				@arg ON:
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Read_USH_UsPwrSwtSts						(		tSwitchSts				*usPwrSwtSts			);

/** ***************************************************************************
 * @brief		DR.
 * @details		This is a detail description of foo.
 * @param[out]	msgMnger_Localisition: output argument description.
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Read_MsgManager_Localisition				(		tMsgMnger_Localisition	*msgMnger_Localisition	);

/*	===========================================================================
 *								submodule
 *	=========================================================================*/
/** ***************************************************************************
 * @brief		DTC * 87.
 * @details		This is a detail description of foo.
 * @param[in]	usSysDtcSts: output argument description.
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Write_USH_UltrasonicSysDtc				(const tUSH_UsSysDtcSts			*usSysDtcSts			);

/** ***************************************************************************
 * @brief		DTC Snapshot(25Byte) * 87.
 * @details		This is a detail description of foo.
 * @param[in]	usSysDtcSnapshot: output argument description.
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Write_USH_DtcSnapshot						(const tUSH_UsSysDtcSnapshot	*usSysDtcSnapshot		);

/** ***************************************************************************
 * @brief		system info
 * @details		This is a detail description of foo.
 * @param[in]	usSysInfo: input argument description.
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Write_USH_UsSysInfo						(const tUSH_UsSysInfo			*usSysInfo				);

/** ***************************************************************************
 * @brief		version info.
 * @details		This is a detail description of foo.
 * @param[in]	usSysVersion: Software version string.
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Write_USH_UsSysVersion					(const tUSH_UsSysVersion		*usSysVersion			);
extern Std_ReturnType Rte_Read_USH_UsSysVersion						(	   tUSH_UsSysVersion		*usSysVersion			);

/** ***************************************************************************
 * @brief		profile request.
 * @details		This is a detail description of foo.
 * @param[in]	usMeasModReq: input argument description.
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Read_USH_UsMeasModReq						(	   tPecpUsMeasModReq		*usMeasModReq			);
extern Std_ReturnType Rte_Write_USH_UsMeasModReq					(const tPecpUsMeasModReq		*usMeasModReq			);

/** ***************************************************************************
 * @brief		bit unlocker.
 * @details		This is a detail description of foo.
 * @param[out]	blindZoneUnlockTriggerBitMask: bit0~5(Front/Rear/FRS/RRS/FLS/RLS)
 *
 * @retval		E_OK: 		success.
 * @retval		E_NOT_OK: 	failed.
 *****************************************************************************/
extern Std_ReturnType Rte_Read_USH_UsBlindZoneUnlockTrigger			(		uint16		            *blindZoneUnlockTriggerBitMask);

/*	===========================================================================
 *								MCU -> SOC
 *	=========================================================================*/
extern Std_ReturnType Rte_Write_MsgManager_UsObstacle		(const tMsgMnger_UsObstacle		*msgMnger_UsObstacle	);
extern Std_ReturnType Rte_Write_MsgManager_ObjDetection		(const tMsgMnger_ObjDetection	*msgMnger_ObjDetection	);
//extern Std_ReturnType Rte_Read_MsgManager_SocFreespace		(const tMsgMnger_Freespace		*msgMnger_Freespace		);
extern Std_ReturnType Rte_Write_MsgManager_PDC				(const tMsgMnger_PDC			*msgMnger_PDC			);

extern Std_ReturnType Rte_Read_MsgManager_VehicleInfo		(      tMsgMnger_VehicleInfo	*msgMnger_VehicleInfo	);
extern Std_ReturnType Rte_Read_MsgManager_ApaState			(      tMsgMnger_ApaState		*msgMnger_ApaState		);

#if US_ON_SOC
extern Std_ReturnType Rte_Write_MsgManager_VehicleInfo		(const tMsgMnger_VehicleInfo	*msgMnger_VehicleInfo	);
extern Std_ReturnType Rte_Read_MsgManager_UsObstacle		(      tMsgMnger_UsObstacle		*msgMnger_UsObstacle	);
extern Std_ReturnType Rte_Read_MsgManager_ObjDetection		(      tMsgMnger_ObjDetection	*msgMnger_ObjDetection	);
//extern Std_ReturnType Rte_Write_MsgManager_McuFreespace     (      tMsgMnger_Freespace		*msgMnger_Freespace		);
extern Std_ReturnType Rte_Read_MsgManager_PDC				(      tMsgMnger_PDC			*msgMnger_PDC			);
#endif

/*	===========================================================================
 *								SOC -> MCU
 *	=========================================================================*/
#if US_ON_SOC
extern Std_ReturnType Rte_Write_MsgManager_ObjDetection		(const tMsgMnger_ObjDetection	*msgMnger_ObjDetection	);
//extern Std_ReturnType Rte_Read_MsgManager_SocFreespace		(const tMsgMnger_Freespace		*msgMnger_Freespace		);
extern Std_ReturnType Rte_Write_MsgManager_UltrasonicPLD	(const tMsgMnger_UltrasonicPLD	*msgMnger_UltrasonicPLD	);
extern Std_ReturnType Rte_Write_MsgManager_PDC				(const tMsgMnger_PDC			*msgMnger_PDC			);

extern Std_ReturnType Rte_Read_MsgManager_ObjDetection		(      tMsgMnger_ObjDetection	*msgMnger_ObjDetection	);
#endif

//extern Std_ReturnType Rte_Write_MsgManager_McuFreespace		(      tMsgMnger_Freespace		*msgMnger_Freespace		);

#if US_ON_SOC
extern Std_ReturnType Rte_Read_MsgManager_UltrasonicPLD		(      tMsgMnger_UltrasonicPLD	*msgMnger_UltrasonicPLD	);
extern Std_ReturnType Rte_Read_MsgManager_PDC				(      tMsgMnger_PDC			*msgMnger_PDC			);
#endif

#if US_ON_SOC
/*	===========================================================================
 *								SOC Ultrasonic
 *	=========================================================================*/
extern Std_ReturnType Rte_Read_SocUs_ObjDetection					(		tSocUs_ObjDetection	    *socUs_ObjDetection		);
extern Std_ReturnType Rte_Read_SocUs_Freespace						(		tSocUs_Freespace		*socUs_Freespace		);
extern Std_ReturnType Rte_Read_SocUs_PDC							(		tSocUs_PDC				*socUs_PDC				);
extern Std_ReturnType Rte_Read_SocUs_UltrasonicPLD					(		tSocUs_UltrasonicPLD	*socUs_UltrasonicPLD	);

extern Std_ReturnType Rte_Write_SocUs_ObjDetection					(const	tSocUs_ObjDetection	    *socUs_ObjDetection		);
extern Std_ReturnType Rte_Write_SocUs_Freespace						(const	tSocUs_Freespace		*socUs_Freespace		);
extern Std_ReturnType Rte_Write_SocUs_PDC							(const	tSocUs_PDC				*socUs_PDC				);
extern Std_ReturnType Rte_Write_SocUs_UltrasonicPLD					(const	tSocUs_UltrasonicPLD	*socUs_UltrasonicPLD	);
#endif

/*	===========================================================================
 *							CAN Signal & Validity
 *	=========================================================================*/
/* vehicle gear & validity */
extern tVehiGear Rte_Read_CanSig_eVehiGear(void);
extern tValidity Rte_Read_CanSig_eVehiGearValidity(void);

/* vehicle speed kph & validity */
extern float32 Rte_Read_CanSig_fVehiSpeed_kph(void);
extern tValidity Rte_Read_CanSig_fVehiSpeedValidity(void);

/* brake active status & validity */
extern tActiveSts Rte_Read_CanSig_eBrakeActiveSts(void);
extern tValidity Rte_Read_CanSig_eBrakeActiveStsValidity(void);

/* outside air temperature & validity */
extern float32 Rte_Read_CanSig_fOutsdAirTemp_degC(void);
extern tValidity Rte_Read_CanSig_fOutsdAirTempValidity(void);


/*	===========================================================================
 *								Runnable
 *	=========================================================================*/
/** \brief Runnable entity: RCtApUltrasonicHandler_Init,
 * Executed once after the RTE is started
 * \param void
 * \return void
 **/
extern void RCtApUltrasonicHandler_Init(void); /* PRQA S 0850, 3449, 3451 */ /* MD_MSR_19.8 */

/** ***************************************************************************
 * @brief		Task_Usr_US.
 * @details		This is a detail description of foo.
 *****************************************************************************/
extern void RCtApUS_5ms(void);

/** \brief Runnable entity: RCtApUltrasonicHandler_20ms,
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 20ms
 * \param void
 * \return void
 **/
extern void RCtApUltrasonicHandler_20ms(void); /* PRQA S 0850, 3449, 3451 */ /* MD_MSR_19.8 */

/** \brief Runnable entity: RCtApUltrasonicHandler_50ms,
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 * \param void
 * \return void
 **/
extern void RCtApUltrasonicHandler_50ms(void); /* PRQA S 0850, 3449, 3451 */ /* MD_MSR_19.8 */

#if US_ON_SOC
extern Std_ReturnType Rte_Write_AllTime_DR_Data						(const	tObjProperty3D			*msgMnger_DR_DATA		);
extern Std_ReturnType Rte_Read_USH_UsSysInfo						(		tUSH_UsSysInfo			*msgMnger_UsSysInfo     );
#if 0
extern Std_ReturnType Rte_Write_Ultrasonic_algo_U                   (const  ExtU_ultrasonic_algo_T  *ultrasonic_algo_U      );
extern Std_ReturnType Rte_Read_Ultrasonic_algo_U                    (       ExtU_ultrasonic_algo_T  *ultrasonic_algo_U      );
#endif
#endif


/* *INDENT-OFF* */
#ifdef __cplusplus
    }
#endif
/* *INDENT-ON* */

#endif /* ULTRASONIC_RTE_ULTRASONIC_H_ */
/******************************************************************************
 *									EOF
 *****************************************************************************/
