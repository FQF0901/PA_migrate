#ifndef __VEHICLE_H_
#define __VEHICLE_H_

// #include "proj_global.h"
#include "Std_Types.h"
#include "emos_rte.h"
#include "Platform_Types.h"
#include "adas_struct.h"
#include "vehicle_service_type.h"

extern tVehi_VehicleDataRx g_stVehilceDataRx;
extern tVehi_VehicleDataTx g_stVehilceDataTx;
extern tActuaSrvTx         g_stVehActuaSrv;
extern ST_VEHICLE_HANDSHAKE_INFO g_stVehHandShakeInfo;

extern void VehicleInit(void);
extern void VehicleCanMsgProcess(void);

#ifndef _SYSTEMCALENDAR_
#define _SYSTEMCALENDAR_
typedef struct
{
    uint16  year;       ///year
    uint16  month;      ///month,1-12
    uint16  day;        ///day,1-31
    uint16  hour;       ///hour,0-24
    uint16  minute;     ///min,0-59
    uint16  second;     ///sec,0-59
    uint16  msec;       ///msec,0-999
    uint16  usec;       ///usec,0-999

    uint64  u64UnixTimes;       ///seconds since UTC_BASE_YEAR
    uint64  u64UnixTimes_us;    ///usec since UTC_BASE_YEAR
    uint64  u64PowOnTimes_us;   ///usec since last power on

}st_SystemCalendar, *pst_SystemCalendar;
#endif
#endif
