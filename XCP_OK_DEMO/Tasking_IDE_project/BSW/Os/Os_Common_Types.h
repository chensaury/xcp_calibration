/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup   Os_Common
 * \{
 *
 * \file
 * \brief       Common types.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_COMMON_TYPES_H
# define OS_COMMON_TYPES_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
# include "Std_Types.h"

/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! \brief    Abstraction of 'static' keyword usage.
 *  \details  --no details--
 */
#ifndef OS_LOCAL                                                                                                        /* COV_OS_COMPILERKEYWORD */
# define OS_LOCAL                   static
#endif

/*! \brief    Abstraction of 'static inline' keyword order.
 *  \details  --no details--
 */
#ifndef OS_LOCAL_INLINE                                                                                                 /* COV_OS_COMPILERKEYWORD */
# define OS_LOCAL_INLINE            LOCAL_INLINE
#endif


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*! \brief    This function performs a NOP on a given variable.
 *  \details  It is used to satisfy compilers in configurations, where not all function parameters are used.
 *  \param    PARAM   The variable to which shall be NOPed */
#define OS_IGNORE_UNREF_PARAM(PARAM)                               ((void)(PARAM))                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/
/*! Standard return type for efficient return of boolean values. */
typedef unsigned int Os_StdReturnType;

/*! Standard data types for processor word. */
typedef unsigned int Os_WordType;

/*! Index type to iterate over OS objects during initialization. */
typedef uint16_least Os_ObjIdxType;


typedef union Os_ParamType_Tag Os_ParamType;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



#endif /* OS_COMMON_TYPES_H */


/* module specific MISRA deviations:

  MD_Os_C90BooleanCompatibility:
      Reason:     Implicit or explicit conversion between 'essentially Boolean' type and an integral type. This is
                  accepted as the Os has been developed for C90 compatibility and shall stay compatible to that.
      Risk:       Readability of the code may be not optimal. This is low risk as the developers are still familiar
                  with C90.
      Prevention: Code inspection by C90 experts.

  MD_Os_Dir1.1_0289_LinkerSymbol:
      Reason:     The identifier is a compiler specific linker symbol which can not correctly be detected by the
                  MISRA tool.
      Risk:       None.
      Prevention: None.

  MD_Os_Dir1.1_0299_Pragma
      Reason:     A compiler specific character can not correctly be detected by the MISRA tool.
      Risk:       Wrong interpretation of this character.
      Prevention: The code is tested with all compilers it shall be compiled with.

  MD_Os_Dir1.1_0314:
      Reason:     The object pointer is safely converted to a void pointer.
      Risk:       None, because there are no violations of alignment requirements.
      Prevention: None.

  MD_Os_Dir1.1_0315:
      Reason:     The implicit conversion of an pointer to object to an pointer to void is safe.
                  There are no restrictions according to the alignment.
      Risk:       None.
      Prevention: None.

  MD_Os_Dir1.1_0715
      Reason:     Splitting this function into two or more parts, would decrease performance, as the data has to be
                  fetched multiple times. E.g. for checking and for execution.
      Risk:       None.
      Prevention: None.

  MD_Os_Dir1.1_2895:
      Reason:     Tick type is treated as absolute point in time. For representing relative types, negative values
                  are required in some cases.
      Risk:       Value representation of negative values depends on the compiler and platform.
      Prevention: Checked with runtime tests that value representation is as expected.

  MD_Os_Dir4.1_2812
      Reason:     The precondition of the function ensures that the parameter is not NULL.
      Risk:       None.
      Prevention: None.

  MD_Os_Dir4.1_2871:
      Reason:     The infinite loop is needed, to provide a core idle state.
      Risk:       None, it is leaved by interrupt, see details of function.
      Prevention: None.

  MD_Os_Dir4.10_0883_MemMap:
      Reason:     The Autosar memory mapping concept requires inclusion of MemMap header files multiple times in a file
                  in order to select appropriate memory sections.
      Risk:       Wrong implementation could lead to wrong memory mapping.
      Prevention: Runtime Test and Implementation Review.

  MD_Os_Rule1.2_1002:
      Reason:     The identifier is a compiler specific linker symbol which can not correctly be detected by the
                  MISRA tool.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule2.1_2880:
      Reason:     Reaching this path depends on the underlying configuration.
      Risk:       None, because in other configurations this path is reached.
      Prevention: None.

  MD_Os_Rule2.1_3219:
      Reason:     This function is inlined and therefore it has to be implemented here. The function is not used
                  by all implementation files which include this header file.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule2.2_2982:
      Reason:     Some compilers issue warnings about a potentially uninitilized variable. This happens because the
                  compiler sees an execution path that is actually not reachable. The compiler warning can only be
                  avoided by adding an unconditional initialization.
      Risk:       The value chosen for initialization could be chosen incorrectly. The path without initialization would
                  then lead to unintended behavior if executed. This cannot be tested, because the path is considered
                  unreachable.
      Prevention: The initialization value has been chosen so that the system has defined and intended behaviour.

  MD_Os_Rule2.2_2983:
      Reason:     The assignment of the structure element of the local variable with the parameter value is necessary
                  for the next function call where this local variable is a parameter of this function call.
      Risk:       None, because the assignment isn't redundant and an part of the next called function.
      Prevention: None.

  MD_Os_Rule2.2_2995:
      Reason:     The result of the logical operation depends on a configuration parameter.
      Risk:       None, because in other configuration it may be false.
      Prevention: None.

  MD_Os_Rule2.2_2996:
      Reason:     The result of the logical operation depends on a configuration parameter.
      Risk:       None, because in other configuration it may be true.
      Prevention: None.

  MD_Os_Rule2.2_3112:
      Reason:     This statement is used to avoid warnings caused by unused parameters. Parameters are defined by
                  standardized API requirements, and not needed in case a feature is disabled by configuration.
                  It is either impossible due to API standardization or necessary code duplication (severe maintenance
                  increase) to provide feature dependent APIs with different signatures.
      Risk:       Unavoidable compiler warning or error because of either unused statements or unused parameter.
      Prevention: None.

  MD_Os_Rule2.2_3112_Hook:
      Reason:     This statement is a user hook which may not be used and therefore left empty.
      Risk:       Unavoidable compiler warning or error because of either unused statements or unused parameter.
      Prevention: None.

  MD_Os_Rule5.5_0784:
      Reason:     The identifier is used as a macro name for object-like usage and still exist in the program source
                  after preprocessing.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule5.9_1527:
      Reason:     The keyword static is used to enable function inlining across different translation units.
      Risk:       A locally defined function could override a globally defined function.
      Prevention: Each function has a module specific prefix, which ensures that no static function may be defined
                  both, locally and globally.

  MD_Os_Rule8.2_1336:
      Reason:     Parameter names not needed here, as this is only a typedef for hook callback functions.
                  Readability of the code is not affected.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule8.5_3449:
      Reason:     Information hiding: The declaration is placed in function scope, because the declared function may
                  not be called from outside the module. So a public declaration within a header file is not possible.
      Risk:       None. Consistency of the multiple declarations is checked by the compiler.
      Prevention: None.

  MD_Os_Rule8.9_1533:
      Reason:     The object is generated from configuration and have to be declared in the generated header file that
                  it can to be used in the static core code.
      Risk:       A greater visibilty of the object may lead to silently compiling and linking with unintentional
                  behaviour.
      Prevention: It is checked by design review.

  MD_Os_Rule8.11_3684_LinkerSymbol:
      Reason:     Declaration of array of unknown size is used for linker tables.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule9.1_2962
      Reason:     The variables are initialized during evaluation of a switch case statement. The default case
                  leads to a call of Os_KernelPanic which never returns.
      Risk:       Usage of uninitialized variables.
      Prevention: Implementation Review.

  MD_Os_Rule10.1_4521:
      Reason:     The enum type operand of the arithmetic operation is generated from OEM defined configuration.
      Risk:       A wrong enum value might result in a wrong array size.
      Prevention: Functional tests of the component data structure.

  MD_Os_Rule10.1_4527:
      Reason:     Enum type is used as operand for increment or decrement operation.
      Risk:       The result of the operation does not match the enum type.
      Prevention: The used enum types are explicitly defined and the range is checked by implementation.
                  This is verified by review and silent analysis.

  MD_Os_Rule10.1_4548
      Reason:     An operator with a fixed boolean like value zero or non zero is used in this logical operation.
                  The code is develpoed according to C90 standard. So boolean values are represented by integral
                  types.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule10.1_4558:
      Reason:     An operator with a fixed boolean like value zero or non zero is used in this logical operation.
                  The code is develpoed according to C90 standard. So boolean values are represented by integral
                  types.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule10.3_2890
      Reason:     Tick type is treated as absolute point in time. For representing relative types, negative values
                  are required in some cases.
      Risk:       Value representation of negative values depends on the compiler and platform.
      Prevention: Checked with runtime tests that value representation is as expected.

  MD_Os_Rule10.4_1881:
      Reason:     The equality operator is used with an enum and an integral operand. This is intended by design.
                  All used enum values are initialized and in range of the integral type.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule10.5_4322:
      Reason:     The cast between different enum types is intended by design to separate the internal from the external 
                  representation. The external values are used to initialize the internal representation.
      Risk:       Values may be incompatible or become incompatible.
      Prevention: Implementation Review.

  MD_Os_Rule10.5_4332:
      Reason:     An expression of 'essentially signed' type is being cast to enum type, to initialze a local variable
                  with a value the enum  data type.
      Risk:       The essentially signed type value may have no representation in the enum type.
      Prevention: These enum types are designed to be used to address array elements and therefore, to have all values 
                  from 0 to OS_...ID_COUNT.

  MD_Os_Rule10.5_4342:
      Reason:     An expression of essential type has been cast to an enum type.
      Risk:       The essential type is not in range of enum type.
      Prevention: The essential type is checked by SW before it will be used.

  MD_Os_Rule11.3_0310:
      Reason:     Conversion of abstract type to a concrete one.
      Risk:       As the originally object is an instance of the concrete type, the alignment is correct.
                  Therefore there is no risk.
      Prevention: None.

  MD_Os_Rule11.3_3305
      Reason:     Conversion of abstract type to a concrete one.
      Risk:       As the originally object is an instance of the concrete type, the alignment is correct.
                  Therefore there is no risk.
      Prevention: None.

  MD_Os_Rule11.4_0306_AccessCheckTest:
      Reason:     In order, to perform numerical operations the pointer is casted into an integral type.
      Risk:       Data width of the pointer may differ from the data width of the integral type.
      Prevention: Ensured by design, that the integral type has the correct data width.

  MD_Os_Rule11.4_0306:
      Reason:     This statement converts an integral address to a pointer or vice versa. This is unavoidable for
                  memory access of that address or put a pointer to a core register.
      Risk:       The risk for incompatibility is low here as the code is used on a specific hardware platform only with
                  known sizes of pointer types and integral types.
      Prevention: The code is tested with all compilers it shall be compiled with.

  MD_Os_Rule11.4_0306_ListEnd:
      Reason:     A value (not NULL_PTR) is required, which signals the end of a list. This value is defined as ~0.
      Risk:       Data width of the pointer may differ from the data width of the integral type.
      Prevention: Ensured by design, that the integral type has the correct data width.

  MD_Os_Rule11.4_0306_PeripheralConfigType:
      Reason:     In order to have numerical constants as peripheral region start and end addresses the pointer
                  is casted into an integral type.
      Risk:       Data width of the pointer may differ from the data width of the integral type.
      Prevention: Ensured by design, that the integral type has the correct data width.

  MD_Os_Rule11.5_0316:
      Reason:     Casting a void pointer to an integral type is done in the context of an address range check.
                  This is neccessary here to calculate with byte granularity.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule11.5_0316_Param:
      Reason:     The underlying function uses void pointers as parameters as specified by AUTOSAR.
                  Depending on the configuration the parameters are casted to the configured values.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule11.6_0326:
      Reason:     To handle platform specific types the void pointers are the prefered pointer type and the compilers
                  ensures the correct memory layout.
      Risk:       The convertion between integer type and a pointer to void may lead to alignment errors.
      Prevention: Checked during review or ReviewHelper.

  MD_Os_Rule11.8_0312_Volatile:
      Reason:     The volatile key word is removed by using a cast. The volatile data is used for cross core
                  communication.
      Risk:       None, as the implementation ensures the correct order of write accesses to the cross core data.
      Prevention: None.

  MD_Os_Rule11.8_0312_Volatile_Api:
      Reason:     The volatile key word is removed by using a cast. The volatile data is used for local variable to
                  avoid compiler optimizations.
      Risk:       None, as the implementation ensures the correctness of the usage of the local variables.
      Prevention: None.

  MD_Os_Rule14.2_2469:
      Reason:     Control variable modified in case of loop abort.
      Risk:       None, as control variable is only modified in case that the loop is aborted.
      Prevention: None.

  MD_Os_Rule14.3_2990:
      Reason:     The controlling expression needs to be always true to provide a core idle state.
      Risk:       None, it is leaved by interrupt, see details of function.
      Prevention: None.

  MD_Os_Rule14.3_2991:
      Reason:     The controlling expression depends on a configuration parameter.
      Risk:       None, because in other configuration it may be false.
      Prevention: None.

  MD_Os_Rule14.3_2992:
      Reason:     The controlling expression depends on a configuration parameter.
      Risk:       None, because in other configuration it may be true.
      Prevention: None.

  MD_Os_Rule17.8_1339:
      Reason:     The usage of the address of a function parameter is intended by design to avoid duplicated code.
                  The parameter is passed by value and acts as an local variable. The modification of the parameter
                  is intended.
      Risk:       None.
      Prevention: None.

  MD_Os_Rule17.8_1340:
      Reason:     The passed const pointer refers to an argument and the called function not modified only assign
                  the const pointer to a structure element of a local variable and as const parameter of a further
                  function.
      Risk:       None, there is no modification of the parameter in the functions.
      Prevention: None.

  MD_Os_Rule18.1_2842
      Reason:     An enum value is used as index for an array. The implementation ensures, that the size of the array
                  equals the number of elements in the enum. The enum values are continuous increasing starting from
                  zero.
      Risk:       None, as the array has the correct size and using enum values out of bounds is detected by compile
                  tests.
      Prevention: None.

  MD_Os_Rule18.1_2842_Precondition
      Reason:     Range is ensured by precondition.
      Risk:       Precondition is missed.
      Prevention: Checked during review or ReviewHelper.

  MD_Os_Rule18.1_2842_Check
      Reason:     Range is checked at runtime.
      Risk:       None, as the array has the correct size and using enum values out of bounds is detected by compile
                  tests.
      Prevention: None.

  MD_Os_Rule18.4_0488_PeripheralAddress:
      Reason:     In order to compare addresses, modeled as pointers, a minimal pointer arithmetic is needed.
      Risk:       None, as pointers value are not modified.
      Prevention: None.

  MD_Os_Rule18.6_3225:
      Reason:     Pointer to a local variable is assigned to output argument of function.
      Risk:       Output argument is invalid when function returns and may not be used.
      Prevention: Output pointer is set to invalid value before function returns in order to ensure that invalid write
                  access is detected during test.

  MD_Os_Rule20.7_3410
      Reason:     Macro used in structures, which do not allow brackets e.g. declaration of functions and variables.
      Risk:       None, type errors will be detected by the compiler.
      Prevention: Used parameter is always atomic.

  MD_Os_Rule20.7_3410_Decl
      Reason:     Macro is used for declaration, which does not allow enclosing parameters in brackets.
      Risk:       None, type errors will be detected by the compiler.
      Prevention: None.

  MD_Os_Rule20.10_0342:
      Reason:     The C standard does not provided any other way to realize the TASK and ISR macros defined by OSEK
                  without using the glue operator. This requires the compiler to support the glue operator. As
                  consequence the glue operator may be used in general.
      Risk:       K&R compiler usage is limited.
      Prevention: Add hint to the user documentation that the glue operator has to be supported.

  MD_Os_STMIF:
      Reason:     Splitting this function into two or more parts, would decrease performance, as the data has to be
                  fetched multiple times. E.g. for checking and for execution.
      Risk:       None.
      Prevention: None.

  MD_Os_STPAR:
      Reason:     A reduction of the number of parameters is not possible in an efficient way.
      Risk:       A caller could mix some of the calling parameters.
      Prevention: None. As all parameters have different types, the compiler checks, whether the given call parameters
                  are in the correct order.

  MD_Os_STCAL:
      Reason:     In order to simplify the code multiple inline getter functions are used. Accessing data directly
                  would increase external coupling. Using macros instead of functions leads to loss of type safety.
      Risk:       None.
      Prevention: None.

  MD_Os_STCYC_Os_TrapHandler:
      Reason:     High cyclomatic complexity due to switch case. Splitting the switch case, would decrease performance.
      Risk:       None, as the switch case has a regular structure the code is still understandable.
      Prevention: None.

  MD_Os_STPTH_Os_TrapHandler:
      Reason:     High path count due to switch case. Splitting the switch case, would decrease performance.
      Risk:       None, as the switch case has a regular structure the code is still understandable.
      Prevention: None.

  MD_Os_STPTH_Os_CoreInit:
      Reason:     High path count due to many iterations. Splitting the function, would decrease performance.
      Risk:       None, as the function has a regular structure the code is still understandable.
      Prevention: None.
 */


/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_Common_Types.h
 **********************************************************************************************************************/
