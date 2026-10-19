#ifndef CTRL_CALIBRATION_DATA_H_
#define CTRL_CALIBRATION_DATA_H_

#include "adas_types.h"


//---------------------------------------------------------------------------

//------------------------DO NOT CHANGE !!!!!!!!!-----------------------------

#define CTRL_DR_STEER_AND_VS 0
//---------------------------------------------------------------------------


    /*	=====================================================================
    *						        Vehicle
    *	===================================================================*/

    /*	=====================================================================
    *						        Longitudinal
    *	===================================================================*/

#define MAX_POINT_NUM      (128u) 

    /*	=====================================================================
    *						        Lateral
    *	===================================================================*/


    /*	=====================================================================
    *						        Utility
    *	===================================================================*/

#define CTRL_PI       (3.141592653f)
#define CTRL_180DEG   (180.0f)
#define CTRL_360DEG   (360.0f)
#define CTRL_MM2METER (0.001f)
#define CTRL_METER2CM (100.0f)


    /*  =====================================================================
    *                               PEB
    *   ===================================================================*/

#define CTRL_USS_UPA_PDC_VALUE_MAX    (250.0f)   //front and rear uss (cm)
#define CTRL_USS_APA_PDC_VALUE_MAX    (500.0f)   //side uss (cm)
#define CTRL_USS_PDC_DANGER_DISTANCE  (40.0f)    //USS dangerous distance (cm)


    /*  =====================================================================
    *                               TEST ROAD
    *   ===================================================================*/

#define ADAS_TEST_ROAD_SWITCH 0

    /*  =====================================================================
    *                               CRUISING
    *   ===================================================================*/

#define TESTBYD   1
#if (TESTBYD == 1)
    #define CF_WHLBASE    (2.920f)
    #define CF_VEH_WIDTH  (1.890f)
    #define CF_WHL_WIDTH_L (0.285f)
    #define CF_WHL_WIDTH_R (0.205f)
    #define CF_DR_WIDTH_L (CF_VEH_WIDTH-CF_WHL_WIDTH_L)
    #define CF_DR_WIDTH_R (CF_VEH_WIDTH-CF_WHL_WIDTH_R)
    #define CTRL_IMPULSE_MAX (1023u)
    #define CF_WHL_DIAM           (0.7176f)
    #define CTRL_IMPULSE_RC_STEP  (0.0225f) 
    #define CF_MIN_TUTN_Radius_R  6.20f
    #define CF_REAR_LEN           0.926f
    #define CF_FRONT_LEN          0.952f
    #define CTRL_STEER_MIN  (-455.0f)
    #define CTRL_STEER_MAX  (455.0f)
    #define MAX_DESIRED_SPEED (20)
#endif

#endif  // CTRL_CALIBRATION_DATA_H_
