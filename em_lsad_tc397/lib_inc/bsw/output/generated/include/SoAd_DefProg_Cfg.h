/**
 * \file
 *
 * \brief AUTOSAR SoAd
 *
 * This file contains the implementation of the AUTOSAR
 * module SoAd.
 *
 * \version 1.8.19
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2022 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef SOAD_DEFPROG_CFG_H
#define SOAD_DEFPROG_CFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/




/*------------------[Defensive programming]---------------------------------*/

#if (defined SOAD_DEFENSIVE_PROGRAMMING_ENABLED)
#error SOAD_DEFENSIVE_PROGRAMMING_ENABLED is already defined
#endif
/** \brief Defensive programming usage
 **
 ** En- or disables the usage of the defensive programming */
#define SOAD_DEFENSIVE_PROGRAMMING_ENABLED   STD_OFF

#if (defined SOAD_PRECONDITION_ASSERT_ENABLED)
#error SOAD_PRECONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Precondition assertion usage
 **
 ** En- or disables the usage of precondition assertion checks */
#define SOAD_PRECONDITION_ASSERT_ENABLED     STD_OFF

#if (defined SOAD_POSTCONDITION_ASSERT_ENABLED)
#error SOAD_POSTCONDITION_ASSERT_ENABLED is already defined
#endif
/** \brief Postcondition assertion usage
 **
 ** En- or disables the usage of postcondition assertion checks */
#define SOAD_POSTCONDITION_ASSERT_ENABLED    STD_OFF

#if (defined SOAD_UNREACHABLE_CODE_ASSERT_ENABLED)
#error SOAD_UNREACHABLE_CODE_ASSERT_ENABLED is already defined
#endif
/** \brief Unreachable code assertion usage
 **
 ** En- or disables the usage of unreachable code assertion checks */
#define SOAD_UNREACHABLE_CODE_ASSERT_ENABLED STD_OFF

#if (defined SOAD_INVARIANT_ASSERT_ENABLED)
#error SOAD_INVARIANT_ASSERT_ENABLED is already defined
#endif
/** \brief Invariant assertion usage
 **
 ** En- or disables the usage of invariant assertion checks */
#define SOAD_INVARIANT_ASSERT_ENABLED        STD_OFF

#if (defined SOAD_STATIC_ASSERT_ENABLED)
#error SOAD_STATIC_ASSERT_ENABLED is already defined
#endif
/** \brief Static assertion usage
 **
 ** En- or disables the usage of static assertion checks */
#define SOAD_STATIC_ASSERT_ENABLED           STD_OFF



/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[external data]=========================================*/

#endif /* ifndef SOAD_DEFPROG_CFG_H */
/*==================[end of file]===========================================*/
