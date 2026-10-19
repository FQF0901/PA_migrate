#include "adas_project_input.h"
#include "vehicle_service_math.h"


uint8_t LpfCalculation(tLowPassFilterPara* stLowPassFilterPara_ptr)
{
   stLowPassFilterPara_ptr->f32LPF_filter_yk_1   =  stLowPassFilterPara_ptr->f32LPF_filter_yk;
   stLowPassFilterPara_ptr->f32LPF_filter_yk     =  - stLowPassFilterPara_ptr->f32LPF_den_2 * stLowPassFilterPara_ptr->f32LPF_filter_yk_1
                                                    + stLowPassFilterPara_ptr->f32LPF_num_1 * stLowPassFilterPara_ptr->f32LPF_yk
                                                    + stLowPassFilterPara_ptr->f32LPF_num_2 * stLowPassFilterPara_ptr->f32LPF_filter_yk_1;
   stLowPassFilterPara_ptr->f32LPF_yk_1          =  stLowPassFilterPara_ptr->f32LPF_yk;   // Raw previous value, not used

   return E_OK;
}
