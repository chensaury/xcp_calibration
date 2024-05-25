/*
 * File: CtMDA_Control_Logic.h
 *
 * Code generated for Simulink model 'CtMDA_Control_Logic'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Nov 10 11:54:47 2023
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CtMDA_Control_Logic_h_
#define RTW_HEADER_CtMDA_Control_Logic_h_
#ifndef CtMDA_Control_Logic_COMMON_INCLUDES_
#define CtMDA_Control_Logic_COMMON_INCLUDES_
//#include "rtwtypes.h"
#include "Rte_CtMDA_Control_Logic.h"
#endif                                /* CtMDA_Control_Logic_COMMON_INCLUDES_ */

#include "CtMDA_Control_Logic_types.h"
#include "Rte_Type.h"

/* Block states (default storage) for system '<Root>' */
typedef struct tag_DW_CtMDA_Control_Logic_T {
  uint8 Output_DSTATE;                 /* '<S3>/Output' */
} DW_CtMDA_Control_Logic_T;

/* Block states (default storage) */
extern DW_CtMDA_Control_Logic_T CtMDA_Control_Logic_DW;

/* External data declarations for dependent source files */
extern const MotTgtOutFL CtMDA_Control_Logic_rtZA_MotTgtOutFL;/* MotTgtOutFL ground */
extern const MotTgtOutFR CtMDA_Control_Logic_rtZA_MotTgtOutFR;/* MotTgtOutFR ground */
extern const MotTgtOutRL CtMDA_Control_Logic_rtZA_MotTgtOutRL;/* MotTgtOutRL ground */
extern const MotTgtOutRR CtMDA_Control_Logic_rtZA_MotTgtOutRR;/* MotTgtOutRR ground */
extern const VlvTgtCurrent CtMDA_Control_Logic_rtZA_VlvTgtCurrent;/* VlvTgtCurrent ground */
extern const VlvTgtFlutter CtMDA_Control_Logic_rtZVlvTgtFlutter;/* VlvTgtFlutter ground */
extern const VlvTgtFrequency CtMDA_Control_Logic_rtZVlvTgtFrequency;/* VlvTgtFrequency ground */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'CtMDA_Control_Logic'
 * '<S1>'   : 'CtMDA_Control_Logic/CtMDA_Control_Logic_Init'
 * '<S2>'   : 'CtMDA_Control_Logic/MDA_Control_Logic_sys'
 * '<S3>'   : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Counter Limited'
 * '<S4>'   : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Ground_24'
 * '<S5>'   : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Ground_25'
 * '<S6>'   : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Ground_26'
 * '<S7>'   : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Ground_27'
 * '<S8>'   : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Ground_29'
 * '<S9>'   : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Ground_30'
 * '<S10>'  : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Ground_31'
 * '<S11>'  : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Counter Limited/Increment Real World'
 * '<S12>'  : 'CtMDA_Control_Logic/MDA_Control_Logic_sys/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_CtMDA_Control_Logic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
