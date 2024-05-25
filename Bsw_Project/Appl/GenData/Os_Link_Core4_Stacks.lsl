/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Link_Core4_Stacks.lsl
 *   Generation Time: 2023-03-21 20:44:22
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 *  STACK SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_KERNEL_STACKS )
group OS_CORE4_STACKS_GROUP(ordered, contiguous, fill)
{

/* Stack: OsCore4_Error (1024 Byte) */
group OS_STACK_OSCORE4_ERROR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE4_ERROR_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE4_ERROR_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE4_ERROR_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE4_ERROR_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE4_ERROR_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE4_ERROR_VAR_NOINIT";

/* Stack: OsCore4_Init (1024 Byte) */
group OS_STACK_OSCORE4_INIT_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE4_INIT_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE4_INIT_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE4_INIT_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE4_INIT_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE4_INIT_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE4_INIT_VAR_NOINIT";

/* Stack: OsCore4_Isr_Core (1024 Byte) */
group OS_STACK_OSCORE4_ISR_CORE_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE4_ISR_CORE_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE4_ISR_CORE_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE4_ISR_CORE_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE4_ISR_CORE_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE4_ISR_CORE_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE4_ISR_CORE_VAR_NOINIT";

/* Stack: OsCore4_Kernel (1024 Byte) */
group OS_STACK_OSCORE4_KERNEL_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE4_KERNEL_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE4_KERNEL_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE4_KERNEL_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE4_KERNEL_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE4_KERNEL_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE4_KERNEL_VAR_NOINIT";

/* Stack: OsCore4_Task_Prio100 (1024 Byte) */
group OS_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT";

/* Stack: OsCore4_Task_Prio20 (1024 Byte) */
group OS_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT";

/* Stack: OsCore4_Task_Prio4294967295 (1024 Byte) */
group OS_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT";

/* Stack: OsCore4_Task_Prio50 (1024 Byte) */
group OS_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
{
  select ".bss.OS_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT";
  reserved ".pad.OS_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT" (size=16);
}
"_OS_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT_START" = "_lc_gb_OS_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT_GROUP";
"_OS_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT_END" = "_lc_ub__pad_OS_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT";



} /* OS_CORE4_STACKS_GROUP */
"_OS_CORE4_STACKS_START" = "_lc_gb_OS_CORE4_STACKS_GROUP";
"_OS_CORE4_STACKS_END" = "_lc_ge_OS_CORE4_STACKS_GROUP";
"_OS_CORE4_STACKS_END_ALIAS" = (("_lc_ge_OS_CORE4_STACKS_GROUP")&~0xF0000000)|0xD0000000;

#endif

#ifdef OS_LINK_KERNEL_STACKS
# undef OS_LINK_KERNEL_STACKS
#endif


