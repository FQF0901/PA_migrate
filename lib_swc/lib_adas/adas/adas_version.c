/*
 * version_swc.c
 *
 *  Created on: 2022-3-4
 *      Author: 
 */


#include "version.h"

#define ADAS_PF_VERSION_MAJOR  4
#define ADAS_PF_VERSION_MEDIUM 0
#define ADAS_PF_VERSION_MINOR  0


/** @page history Changes history

*/

/******************************************************************************/
/*                                                                            */
/*                              VERSION TOOL                                  */
/*                                                                            */
/******************************************************************************/


#ifndef ADAS_PF_TOOL_VERSION
#define ADAS_PF_TOOL_STRINGIFY(s) ADAS_PF_TOOL_TOSTRING(s)
#define ADAS_PF_TOOL_TOSTRING(s)  #s

#define ADAS_PF_TOOL_VERSION_INT(a, b, c) (a<<16 | b<<8 | c)
#define ADAS_PF_TOOL_VERSION_DOT(a, b, c) a##.##b##.##c
#define ADAS_PF_TOOL_VERSION(a, b, c) ADAS_PF_TOOL_VERSION_DOT(a, b, c)
#endif

#define ADAS_PF_VERSION_INTER ADAS_PF_TOOL_VERSION(ADAS_PF_VERSION_MAJOR, \
                                                    ADAS_PF_VERSION_MEDIUM, \
                                                    ADAS_PF_VERSION_MINOR)

#define ADAS_PF_VERSION_INT   ADAS_PF_TOOL_VERSION_INT(ADAS_PF_VERSION_MAJOR, \
                                                        ADAS_PF_VERSION_MEDIUM, \
                                                        ADAS_PF_VERSION_MINOR)

#define ADAS_PF_VERSION_STRING  "ADAS_PF_" ADAS_PF_TOOL_STRINGIFY(ADAS_PF_VERSION_INTER)

const stVersionInfo cVerLib_swc_adas =
{
    .index   = VER_LIB_swc_adas,
    .name    = "lib adas",
    .version = ADAS_PF_VERSION_STRING,
    .rebuild = ""__DATE__", "__TIME__,
};
