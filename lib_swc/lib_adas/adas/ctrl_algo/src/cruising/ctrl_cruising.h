/*
 * Ctrl_Cursing.h
 *
 *  Created on: Jul 13, 2021
 *      
 */

#ifndef SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_CURSING_H_
#define SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_CURSING_H_


#include "ctrl_struct.h"

typedef enum
{
    eNoErr = 0,
    eErrLatAlgoType,  
}ERROR_ID;

typedef enum
{
    eLqrDyn = 0,
    ePurePursuit
}LAT_ALGORITHM;

#define STEER_WHELL_RATIO 15

#define STEERING_DELAY_TIME 0.22

uint8_t Ctrl_CruisingTask_20ms(void);
int GetTrajIndexByTime(tCtrlCommonInfo*  stCtrlCommonInfo_ptr,
						tPathPlannerInfo* stPathPlanerData_ptr,
						int  nCycle,
						_Bool delayFlag);
void GetTrajDesired(uint8_t indexffw,
					uint8_t indexfb,
					tPathPlannerInfo* stPathPlanerData_ptr,
					tTrajLongiController* stTrajLongiController_ptr);

#endif /* SRC_APL_APP_CTRL_ALGO_INCLUDE_CTRL_CURSING_H_ */
