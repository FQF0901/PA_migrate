/*
 * timing_rbuf.h
 *
 *  Created on: 2022年12月13日
 *      
 */

#ifndef TIMING_RBUF_H__
#define TIMING_RBUF_H__

/*  ===========================================================================
 *                              header files
 *  =========================================================================*/
#include "Std_Types.h"

/*  ===========================================================================
 *                              constants
 *  =========================================================================*/

/*  ===========================================================================
 *                              macros
 *  =========================================================================*/

/*  ===========================================================================
 *                      data structure declarations
 *  =========================================================================*/

/*  ===========================================================================
 *                      global variable declarations
 *  =========================================================================*/

/*  ===========================================================================
 *                      global function declarations
 *  =========================================================================*/
extern void   Timing_RBuf_Init(uint8* ptrRBuf, uint32 size);
extern uint32 Timing_RBuf_Write(void *pBuf, uint32 len);
extern uint32 Timing_RBuf_Read(void *pBuf, uint32 maxLen);
extern uint32 Timing_RBuf_Check(void *pBuf, uint32 maxLen);
extern void*  Timing_RBuf_Malloc(uint32 size);
extern uint32 Timing_RBuf_UsedSize(void);
extern uint32 Timing_RBuf_GetWriteIndex(void);
extern uint32 Timing_RBuf_GetReadIndex(void);
extern uint32 Timing_RBuf_GetCheckIndex(void);

#endif /* TIMING_RBUF_H__ */
