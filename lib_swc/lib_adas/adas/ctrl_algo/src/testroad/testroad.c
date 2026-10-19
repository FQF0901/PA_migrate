#include "testroad.h"
#include "math.h"

static tMsgMnger_PathPlanner FakePath;

static uint8_t Ctrl_Init_Fake_Road(tCtrlCommonInfo* stCtrlCommonInfo_ptr)
{

    if(1 == stCtrlCommonInfo_ptr->u8FakeRoadPathId)
    {
        FakePath.u64Timestamp_us                   = 0;
        FakePath.eApaPathPlanSts                   = APA_PATH_PLAN_SUCCESS;
        FakePath.stPathPlanData.u16TotallyPathNum  = 2;
        FakePath.stPathPlanData.u16PathId          = 1;                      //now id
        FakePath.stPathPlanData.u8Size             = 28;
        FakePath.stPathPlanData.u8Shift            = 3;                      //now gear
        FakePath.stPathPlanData.u8PldType          = 2;
        FakePath.stPathPlanData.u8PlanResult       = 1;
        FakePath.stPathPlanData.u8PebLevel         = 0;
        FakePath.stPathPlanData.u8VehicleActionRequest       = 0;

        FakePath.stPathPlanData.stPathPosition[0].f32WayPointX         = 0.000000;
        FakePath.stPathPlanData.stPathPosition[0].f32WayPointY         = 0.000000;
        FakePath.stPathPlanData.stPathPosition[0].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[0].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[1].f32WayPointX         = 0.2017;
        FakePath.stPathPlanData.stPathPosition[1].f32WayPointY         = -0.000000;
        FakePath.stPathPlanData.stPathPosition[1].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[1].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[2].f32WayPointX         = 0.4034;
        FakePath.stPathPlanData.stPathPosition[2].f32WayPointY         = -0.000000;
        FakePath.stPathPlanData.stPathPosition[2].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[2].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[3].f32WayPointX         = 0.6051;
        FakePath.stPathPlanData.stPathPosition[3].f32WayPointY         = 0.000000;
        FakePath.stPathPlanData.stPathPosition[3].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[3].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[4].f32WayPointX         = 0.8067;
        FakePath.stPathPlanData.stPathPosition[4].f32WayPointY         = -0.000000;
        FakePath.stPathPlanData.stPathPosition[4].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[4].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[5].f32WayPointX         = 1.0084;
        FakePath.stPathPlanData.stPathPosition[5].f32WayPointY         = -0.000000;
        FakePath.stPathPlanData.stPathPosition[5].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[5].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[6].f32WayPointX         = 1.2101;
        FakePath.stPathPlanData.stPathPosition[6].f32WayPointY         = -0.000000;
        FakePath.stPathPlanData.stPathPosition[6].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[6].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[7].f32WayPointX         = 1.4118;
        FakePath.stPathPlanData.stPathPosition[7].f32WayPointY         = -0.000000;
        FakePath.stPathPlanData.stPathPosition[7].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[7].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[8].f32WayPointX         = 1.6135;
        FakePath.stPathPlanData.stPathPosition[8].f32WayPointY         = 0.000000;
        FakePath.stPathPlanData.stPathPosition[8].f32WayPointTheta     = 0.000000;
        FakePath.stPathPlanData.stPathPosition[8].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[9].f32WayPointX         = 1.7953;
        FakePath.stPathPlanData.stPathPosition[9].f32WayPointY         = 0.0002;
        FakePath.stPathPlanData.stPathPosition[9].f32WayPointTheta     = 0.0033;
        FakePath.stPathPlanData.stPathPosition[9].f32WayPointCurvature = 0.0364;

        FakePath.stPathPlanData.stPathPosition[10].f32WayPointX         = 1.9771;
        FakePath.stPathPlanData.stPathPosition[10].f32WayPointY         = 0.0016;
        FakePath.stPathPlanData.stPathPosition[10].f32WayPointTheta     = 0.0132;
        FakePath.stPathPlanData.stPathPosition[10].f32WayPointCurvature = 0.0727;

        FakePath.stPathPlanData.stPathPosition[11].f32WayPointX         = 2.1589;
        FakePath.stPathPlanData.stPathPosition[11].f32WayPointY         = 0.0054;
        FakePath.stPathPlanData.stPathPosition[11].f32WayPointTheta     = 0.0298;
        FakePath.stPathPlanData.stPathPosition[11].f32WayPointCurvature = 0.1091;

        FakePath.stPathPlanData.stPathPosition[12].f32WayPointX         = 2.3405;
        FakePath.stPathPlanData.stPathPosition[12].f32WayPointY         = 0.0128;
        FakePath.stPathPlanData.stPathPosition[12].f32WayPointTheta     = 0.0529;
        FakePath.stPathPlanData.stPathPosition[12].f32WayPointCurvature = 0.1455;

        FakePath.stPathPlanData.stPathPosition[13].f32WayPointX         = 2.5219;
        FakePath.stPathPlanData.stPathPosition[13].f32WayPointY         = 0.0188;
        FakePath.stPathPlanData.stPathPosition[13].f32WayPointTheta     = 0.0826;
        FakePath.stPathPlanData.stPathPosition[13].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[14].f32WayPointX         = 2.7201;
        FakePath.stPathPlanData.stPathPosition[14].f32WayPointY         = 0.0388;
        FakePath.stPathPlanData.stPathPosition[14].f32WayPointTheta     = 0.1189;
        FakePath.stPathPlanData.stPathPosition[14].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[15].f32WayPointX         = 2.9174;
        FakePath.stPathPlanData.stPathPosition[15].f32WayPointY         = 0.0660;
        FakePath.stPathPlanData.stPathPosition[15].f32WayPointTheta     = 0.1551;
        FakePath.stPathPlanData.stPathPosition[15].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[16].f32WayPointX         = 3.1136;
        FakePath.stPathPlanData.stPathPosition[16].f32WayPointY         = 0.1003;
        FakePath.stPathPlanData.stPathPosition[16].f32WayPointTheta     = 0.1913;
        FakePath.stPathPlanData.stPathPosition[16].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[17].f32WayPointX         = 3.3084;
        FakePath.stPathPlanData.stPathPosition[17].f32WayPointY         = 0.1417;
        FakePath.stPathPlanData.stPathPosition[17].f32WayPointTheta     = 0.2275;
        FakePath.stPathPlanData.stPathPosition[17].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[18].f32WayPointX         = 3.5016;
        FakePath.stPathPlanData.stPathPosition[18].f32WayPointY         = 0.1902;
        FakePath.stPathPlanData.stPathPosition[18].f32WayPointTheta     = 0.2637;
        FakePath.stPathPlanData.stPathPosition[18].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[19].f32WayPointX         = 3.6929;
        FakePath.stPathPlanData.stPathPosition[19].f32WayPointY         = 0.2456;
        FakePath.stPathPlanData.stPathPosition[19].f32WayPointTheta     = 0.2999;
        FakePath.stPathPlanData.stPathPosition[19].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[20].f32WayPointX         = 3.8821;
        FakePath.stPathPlanData.stPathPosition[20].f32WayPointY         = 0.3078;
        FakePath.stPathPlanData.stPathPosition[20].f32WayPointTheta     = 0.3361;
        FakePath.stPathPlanData.stPathPosition[20].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[21].f32WayPointX         = 4.0689;
        FakePath.stPathPlanData.stPathPosition[21].f32WayPointY         = 0.3769;
        FakePath.stPathPlanData.stPathPosition[21].f32WayPointTheta     = 0.3724;
        FakePath.stPathPlanData.stPathPosition[21].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[22].f32WayPointX         = 4.2531;
        FakePath.stPathPlanData.stPathPosition[22].f32WayPointY         = 0.4527;
        FakePath.stPathPlanData.stPathPosition[22].f32WayPointTheta     = 0.4086;
        FakePath.stPathPlanData.stPathPosition[22].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[23].f32WayPointX         = 4.4344;
        FakePath.stPathPlanData.stPathPosition[23].f32WayPointY         = 0.5352;
        FakePath.stPathPlanData.stPathPosition[23].f32WayPointTheta     = 0.4448;
        FakePath.stPathPlanData.stPathPosition[23].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[24].f32WayPointX         = 4.6126;
        FakePath.stPathPlanData.stPathPosition[24].f32WayPointY         = 0.6241;
        FakePath.stPathPlanData.stPathPosition[24].f32WayPointTheta     = 0.4810;
        FakePath.stPathPlanData.stPathPosition[24].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[25].f32WayPointX         = 4.7875;
        FakePath.stPathPlanData.stPathPosition[25].f32WayPointY         = 0.7194;
        FakePath.stPathPlanData.stPathPosition[25].f32WayPointTheta     = 0.5172;
        FakePath.stPathPlanData.stPathPosition[25].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[26].f32WayPointX         = 4.9588;
        FakePath.stPathPlanData.stPathPosition[26].f32WayPointY         = 0.8210;
        FakePath.stPathPlanData.stPathPosition[26].f32WayPointTheta     = 0.5534;
        FakePath.stPathPlanData.stPathPosition[26].f32WayPointCurvature = 0.1818;

        FakePath.stPathPlanData.stPathPosition[27].f32WayPointX         = 5.1263;
        FakePath.stPathPlanData.stPathPosition[27].f32WayPointY         = 0.9288;
        FakePath.stPathPlanData.stPathPosition[27].f32WayPointTheta     = 0.5897;
        FakePath.stPathPlanData.stPathPosition[27].f32WayPointCurvature = 0.1818;
    }

    else if(2 == stCtrlCommonInfo_ptr->u8FakeRoadPathId)
    {
        FakePath.u64Timestamp_us                   = 0;
        FakePath.eApaPathPlanSts                   = APA_PATH_PLAN_SUCCESS;
        FakePath.stPathPlanData.u16TotallyPathNum  = 2;
        FakePath.stPathPlanData.u16PathId          = 2;                      //now id
        FakePath.stPathPlanData.u8Size             = 41;
        FakePath.stPathPlanData.u8Shift            = 1;                      //now gear
        FakePath.stPathPlanData.u8PldType          = 2;
        FakePath.stPathPlanData.u8PlanResult       = 1;
        FakePath.stPathPlanData.u8PebLevel         = 0;
        FakePath.stPathPlanData.u8VehicleActionRequest       = 0;

        FakePath.stPathPlanData.stPathPosition[0].f32WayPointX         = 5.1263;
        FakePath.stPathPlanData.stPathPosition[0].f32WayPointY         = 0.9288;
        FakePath.stPathPlanData.stPathPosition[0].f32WayPointTheta     = 0.5897;
        FakePath.stPathPlanData.stPathPosition[0].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[1].f32WayPointX         = 4.9604;
        FakePath.stPathPlanData.stPathPosition[1].f32WayPointY         = 0.8137;
        FakePath.stPathPlanData.stPathPosition[1].f32WayPointTheta     = 0.6233;
        FakePath.stPathPlanData.stPathPosition[1].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[2].f32WayPointX         = 4.7985;
        FakePath.stPathPlanData.stPathPosition[2].f32WayPointY         = 0.6931;
        FakePath.stPathPlanData.stPathPosition[2].f32WayPointTheta     = 0.6570;
        FakePath.stPathPlanData.stPathPosition[2].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[3].f32WayPointX         = 4.6407;
        FakePath.stPathPlanData.stPathPosition[3].f32WayPointY         = 0.5671;
        FakePath.stPathPlanData.stPathPosition[3].f32WayPointTheta     = 0.6906;
        FakePath.stPathPlanData.stPathPosition[3].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[4].f32WayPointX         = 4.4872;
        FakePath.stPathPlanData.stPathPosition[4].f32WayPointY         = 0.4358;
        FakePath.stPathPlanData.stPathPosition[4].f32WayPointTheta     = 0.7243;
        FakePath.stPathPlanData.stPathPosition[4].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[5].f32WayPointX         = 4.3382;
        FakePath.stPathPlanData.stPathPosition[5].f32WayPointY         = 0.2995;
        FakePath.stPathPlanData.stPathPosition[5].f32WayPointTheta     = 0.7579;
        FakePath.stPathPlanData.stPathPosition[5].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[6].f32WayPointX         = 4.1939;
        FakePath.stPathPlanData.stPathPosition[6].f32WayPointY         = 0.1583;
        FakePath.stPathPlanData.stPathPosition[6].f32WayPointTheta     = 0.7916;
        FakePath.stPathPlanData.stPathPosition[6].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[7].f32WayPointX         = 4.0545;
        FakePath.stPathPlanData.stPathPosition[7].f32WayPointY         = 0.0122;
        FakePath.stPathPlanData.stPathPosition[7].f32WayPointTheta     = 0.8252;
        FakePath.stPathPlanData.stPathPosition[7].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[8].f32WayPointX         = 3.92;
        FakePath.stPathPlanData.stPathPosition[8].f32WayPointY         = -0.1384;
        FakePath.stPathPlanData.stPathPosition[8].f32WayPointTheta     = 0.8589;
        FakePath.stPathPlanData.stPathPosition[8].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[9].f32WayPointX         = 3.7907;
        FakePath.stPathPlanData.stPathPosition[9].f32WayPointY         = -0.2935;
        FakePath.stPathPlanData.stPathPosition[9].f32WayPointTheta     = 0.8926;
        FakePath.stPathPlanData.stPathPosition[9].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[10].f32WayPointX         = 3.6667;
        FakePath.stPathPlanData.stPathPosition[10].f32WayPointY         = -0.4528;
        FakePath.stPathPlanData.stPathPosition[10].f32WayPointTheta     = 0.9262;
        FakePath.stPathPlanData.stPathPosition[10].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[11].f32WayPointX         = 3.5481;
        FakePath.stPathPlanData.stPathPosition[11].f32WayPointY         = -0.6163;
        FakePath.stPathPlanData.stPathPosition[11].f32WayPointTheta     = 0.9599;
        FakePath.stPathPlanData.stPathPosition[11].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[12].f32WayPointX         = 3.435;
        FakePath.stPathPlanData.stPathPosition[12].f32WayPointY         = -0.7836;
        FakePath.stPathPlanData.stPathPosition[12].f32WayPointTheta     = 0.9935;
        FakePath.stPathPlanData.stPathPosition[12].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[13].f32WayPointX         = 3.3277;
        FakePath.stPathPlanData.stPathPosition[13].f32WayPointY         = -0.9546;
        FakePath.stPathPlanData.stPathPosition[13].f32WayPointTheta     = 1.0272;
        FakePath.stPathPlanData.stPathPosition[13].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[14].f32WayPointX         = 3.2262;
        FakePath.stPathPlanData.stPathPosition[14].f32WayPointY         = -1.1292;
        FakePath.stPathPlanData.stPathPosition[14].f32WayPointTheta     = 1.0608;
        FakePath.stPathPlanData.stPathPosition[14].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[15].f32WayPointX         = 3.1306;
        FakePath.stPathPlanData.stPathPosition[15].f32WayPointY         = -1.3070;
        FakePath.stPathPlanData.stPathPosition[15].f32WayPointTheta     = 1.0945;
        FakePath.stPathPlanData.stPathPosition[15].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[16].f32WayPointX         = 3.041;
        FakePath.stPathPlanData.stPathPosition[16].f32WayPointY         = -1.4880;
        FakePath.stPathPlanData.stPathPosition[16].f32WayPointTheta     = 1.1282;
        FakePath.stPathPlanData.stPathPosition[16].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[17].f32WayPointX         = 2.9576;
        FakePath.stPathPlanData.stPathPosition[17].f32WayPointY         = -1.6719;
        FakePath.stPathPlanData.stPathPosition[17].f32WayPointTheta     = 1.1618;
        FakePath.stPathPlanData.stPathPosition[17].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[18].f32WayPointX         = 2.8805;
        FakePath.stPathPlanData.stPathPosition[18].f32WayPointY         = -1.8585;
        FakePath.stPathPlanData.stPathPosition[18].f32WayPointTheta     = 1.1955;
        FakePath.stPathPlanData.stPathPosition[18].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[19].f32WayPointX         = 2.8096;
        FakePath.stPathPlanData.stPathPosition[19].f32WayPointY         = -2.0476;
        FakePath.stPathPlanData.stPathPosition[19].f32WayPointTheta     = 1.2291;
        FakePath.stPathPlanData.stPathPosition[19].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[20].f32WayPointX         = 2.7452;
        FakePath.stPathPlanData.stPathPosition[20].f32WayPointY         = -2.2390;
        FakePath.stPathPlanData.stPathPosition[20].f32WayPointTheta     = 1.2628;
        FakePath.stPathPlanData.stPathPosition[20].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[21].f32WayPointX         = 2.6872;
        FakePath.stPathPlanData.stPathPosition[21].f32WayPointY         = -2.4324;
        FakePath.stPathPlanData.stPathPosition[21].f32WayPointTheta     = 1.2964;
        FakePath.stPathPlanData.stPathPosition[21].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[22].f32WayPointX         = 2.6358;
        FakePath.stPathPlanData.stPathPosition[22].f32WayPointY         = -2.6277;
        FakePath.stPathPlanData.stPathPosition[22].f32WayPointTheta     = 1.3301;
        FakePath.stPathPlanData.stPathPosition[22].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[23].f32WayPointX         = 2.5909;
        FakePath.stPathPlanData.stPathPosition[23].f32WayPointY         = -2.8245;
        FakePath.stPathPlanData.stPathPosition[23].f32WayPointTheta     = 1.3637;
        FakePath.stPathPlanData.stPathPosition[23].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[24].f32WayPointX         = 2.5527;
        FakePath.stPathPlanData.stPathPosition[24].f32WayPointY         = -3.0228;
        FakePath.stPathPlanData.stPathPosition[24].f32WayPointTheta     = 1.3974;
        FakePath.stPathPlanData.stPathPosition[24].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[25].f32WayPointX         = 2.5213;
        FakePath.stPathPlanData.stPathPosition[25].f32WayPointY         = -3.2223;
        FakePath.stPathPlanData.stPathPosition[25].f32WayPointTheta     = 1.4311;
        FakePath.stPathPlanData.stPathPosition[25].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[26].f32WayPointX         = 2.5013;
        FakePath.stPathPlanData.stPathPosition[26].f32WayPointY         = -3.4229;
        FakePath.stPathPlanData.stPathPosition[26].f32WayPointTheta     = 1.4647;
        FakePath.stPathPlanData.stPathPosition[26].f32WayPointCurvature = -0.1667;

        FakePath.stPathPlanData.stPathPosition[27].f32WayPointX         = 2.4826;
        FakePath.stPathPlanData.stPathPosition[27].f32WayPointY         = -3.6303;
        FakePath.stPathPlanData.stPathPosition[27].f32WayPointTheta     = 1.4951;
        FakePath.stPathPlanData.stPathPosition[27].f32WayPointCurvature = -0.1250;

        FakePath.stPathPlanData.stPathPosition[28].f32WayPointX         = 2.4692;
        FakePath.stPathPlanData.stPathPosition[28].f32WayPointY         = -3.8383;
        FakePath.stPathPlanData.stPathPosition[28].f32WayPointTheta     = 1.5168;
        FakePath.stPathPlanData.stPathPosition[28].f32WayPointCurvature = -0.0833;

        FakePath.stPathPlanData.stPathPosition[29].f32WayPointX         = 2.4595;
        FakePath.stPathPlanData.stPathPosition[29].f32WayPointY         = -4.0464;
        FakePath.stPathPlanData.stPathPosition[29].f32WayPointTheta     = 1.5298;
        FakePath.stPathPlanData.stPathPosition[29].f32WayPointCurvature = -0.0417;

        FakePath.stPathPlanData.stPathPosition[30].f32WayPointX         = 2.4515;
        FakePath.stPathPlanData.stPathPosition[30].f32WayPointY         = -4.2545;
        FakePath.stPathPlanData.stPathPosition[30].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[30].f32WayPointCurvature = 0.0000;

        FakePath.stPathPlanData.stPathPosition[31].f32WayPointX         = 2.444;
        FakePath.stPathPlanData.stPathPosition[31].f32WayPointY         = -4.4597;
        FakePath.stPathPlanData.stPathPosition[31].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[31].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[32].f32WayPointX         = 2.4365;
        FakePath.stPathPlanData.stPathPosition[32].f32WayPointY         = -4.6648;
        FakePath.stPathPlanData.stPathPosition[32].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[32].f32WayPointCurvature = 0.0000;

        FakePath.stPathPlanData.stPathPosition[33].f32WayPointX         = 2.429;
        FakePath.stPathPlanData.stPathPosition[33].f32WayPointY         = -4.8700;
        FakePath.stPathPlanData.stPathPosition[33].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[33].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[34].f32WayPointX         = 2.4215;
        FakePath.stPathPlanData.stPathPosition[34].f32WayPointY         = -5.0751;
        FakePath.stPathPlanData.stPathPosition[34].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[34].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[35].f32WayPointX         = 2.4139;
        FakePath.stPathPlanData.stPathPosition[35].f32WayPointY         = -5.2803;
        FakePath.stPathPlanData.stPathPosition[35].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[35].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[36].f32WayPointX         = 2.4064;
        FakePath.stPathPlanData.stPathPosition[36].f32WayPointY         = -5.4854;
        FakePath.stPathPlanData.stPathPosition[36].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[36].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[37].f32WayPointX         = 2.3989;
        FakePath.stPathPlanData.stPathPosition[37].f32WayPointY         = -5.6905;
        FakePath.stPathPlanData.stPathPosition[37].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[37].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[38].f32WayPointX = 2.3914;
        FakePath.stPathPlanData.stPathPosition[38].f32WayPointY         = -5.8957;
        FakePath.stPathPlanData.stPathPosition[38].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[38].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[39].f32WayPointX         = 2.3839;
        FakePath.stPathPlanData.stPathPosition[39].f32WayPointY         = -6.1008;
        FakePath.stPathPlanData.stPathPosition[39].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[39].f32WayPointCurvature = 0.000000;

        FakePath.stPathPlanData.stPathPosition[40].f32WayPointX         = 2.3763;
        FakePath.stPathPlanData.stPathPosition[40].f32WayPointY         = -6.3060;
        FakePath.stPathPlanData.stPathPosition[40].f32WayPointTheta     = 1.5342;
        FakePath.stPathPlanData.stPathPosition[40].f32WayPointCurvature = 0.000000;
    }
    else if(3 == stCtrlCommonInfo_ptr->u8FakeRoadPathId)
    {
        FakePath.u64Timestamp_us                   = 0;
        FakePath.eApaPathPlanSts                   = APA_PATH_PLAN_SUCCESS;
        FakePath.stPathPlanData.u16TotallyPathNum  = 2;
        FakePath.stPathPlanData.u16PathId          = 3;                      //now id
        FakePath.stPathPlanData.u8Size             = 0;
        FakePath.stPathPlanData.u8Shift            = 5;                      //now gear
        FakePath.stPathPlanData.u8PldType          = 2;
        FakePath.stPathPlanData.u8PlanResult       = 1;
        FakePath.stPathPlanData.u8PebLevel         = 0;
        FakePath.stPathPlanData.u8VehicleActionRequest       = 10;
    }
    else{}
   return E_OK;
}


tMsgMnger_PathPlanner Ctrl_Recv_Fake_Road(tCtrlCommonInfo*  stCtrlCommonInfo_ptr)
{
    tMsgMnger_PathPlanner   msgMnger_PathPlanner;

    static tCtrlVehiclePosition pose_ptr;

    if (LSAD_STS_STANDBY == g_stCtrlFuncFsmInfo.eLsadSystemSts)
    {
        pose_ptr.f32X_Coor = pose_ptr.f32Y_Coor = pose_ptr.f32Theta = 0.0f;
 //       Dr_SetPoseNow(&pose_ptr);   Lin: Change to matrix shift in the future
    }

    if(1 == g_stCtrlLongiInfo.u8CurrentPathFinishedFlag && 0 == g_stCtrlLongiInfo.u8CurrentPathFinishedFlagPrev)
    {
        stCtrlCommonInfo_ptr->u8FakeRoadPathId ++;
    }

    g_stCtrlLongiInfo.u8CurrentPathFinishedFlagPrev = g_stCtrlLongiInfo.u8CurrentPathFinishedFlag;

    if(1 == stCtrlCommonInfo_ptr->u8FakeRoadPathId)
    {
        Ctrl_Init_Fake_Road(stCtrlCommonInfo_ptr);
        msgMnger_PathPlanner = FakePath;
        // PRINTF_WJ("road 111\r\n");
    }
    else if (2 == stCtrlCommonInfo_ptr->u8FakeRoadPathId)
    {
        Ctrl_Init_Fake_Road(stCtrlCommonInfo_ptr);
        msgMnger_PathPlanner = FakePath;
        // PRINTF_WJ("road 222\r\n");
    }
    else if (3 == stCtrlCommonInfo_ptr->u8FakeRoadPathId)
    {
        Ctrl_Init_Fake_Road(stCtrlCommonInfo_ptr);
        msgMnger_PathPlanner = FakePath;
        // PRINTF_WJ("road 333\r\n");
    }
    else 
    {
        // PRINTF_WJ("road 111\r\n");
    }

    return msgMnger_PathPlanner;
}
