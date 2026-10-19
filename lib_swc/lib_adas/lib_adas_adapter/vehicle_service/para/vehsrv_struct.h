#ifndef VS_STRUCT_H_
#define VS_STRUCT_H_

#include "vehsrv_enum.h"
#include "adas_project_input.h"  //contains adas_struct.h


/*	=====================================================================
*						        Input
*	===================================================================*/

typedef struct _VS_INPUT //vs input test
{
	float   f32VehsrvInput1;
	float   f32VehsrvInput2;
	float   f32VehsrvInput3;
}tVehsrvInputInfo;

/*	=====================================================================
*						        Common
*	===================================================================*/

typedef struct _VS_PROSESS //vs prosess test
{
    E_VEHSRV_STS   eVehsrvSts;
	float          f32VehsrvProsess2;
	float          f32VehsrvProsess3;
}tVehsrvProsessInfo;

/*	=====================================================================
*						        Output
*	===================================================================*/

typedef struct _VS_OUTPUT //vs output test
{
	float   f32VehsrvOutput1;
	float   f32VehsrvOutput2;
	float   f32VehsrvOutput3;
}tVehsrvOutputInfo;

/*	=====================================================================
*				                Others.
*	===================================================================*/

#endif /*VS_STRUCT_H_*/
