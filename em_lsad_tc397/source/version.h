/*
* version.h
*
*  Created on: 2022年3月4日
*      
*/

#ifndef VERSION_H_
#define VERSION_H_

typedef enum _eVerIndex
{
   VER_ELF = 0,
   VER_LIB_bsw,
//    VER_LIB_bsw_base,
//    VER_LIB_bsw_emsync,
//    VER_LIB_bsw_service,
//    VER_LIB_bsw_task,
//    VER_LIB_bsw_usdriver,
   VER_LIB_rte,
   VER_LIB_vehmsg,
   VER_LIB_swc_adas,
   VER_LIB_swc_ultrasonic,
   VER_LIB_timing,

   VER_INFO_NUMBER,
}eVerIndex;

typedef struct _stVersionInfo
{
   eVerIndex index;
   char     *name;     /* like "lib_bsw_base", align 15 char */
   char     *version;  /* like "1.0.0" */
   char     *rebuild;  /* macro ""__DATE__", "__TIME__ */
}stVersionInfo;

// extern const stVersionInfo *sAllVersion[];
// extern const stVersionInfo cVerElf;
// extern void show_version_info(char *prefix, char *suffix);

#endif /* VERSION_H_ */
