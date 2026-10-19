/* Os_hw.h
 *
 * This file defines the architecture and derivative
 *
 * CHECK: TABS 4 (see editor commands at end of file)
 *
 * Copyright Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 *
 * $Id: Os_hw.h.m4 35545 2021-10-06 14:19:48Z ache271795 $
*/
#ifndef OS_HW_H
#define OS_HW_H

#define OS_ARCH	OS_TRICORE
#define OS_CPU	OS_TC39XX

/*
 * Those are defined in asc_PluginBuildEnv/common/Include/Base_BuildEnvironment/util/common.mak
*/
#ifndef TS_ARCH_FAMILY
#define TS_ARCH_FAMILY		OS_TRICORE
#endif
#ifndef TS_ARCH_DERIVATE
#define TS_ARCH_DERIVATE	OS_TC39XX
#endif

/* Architecture specific defines */
#include <TRICORE/Os_hw_TRICORE.h>

#endif /* OS_HW_H */
/* Editor settings - DO NOT DELETE
 * vi:set ts=4:
*/

