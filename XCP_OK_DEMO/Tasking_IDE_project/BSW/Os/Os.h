/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                             All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  ------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \ingroup     Os_Kernel
 * \defgroup    Os_UserInterface OS User Interface
 * \brief       User API of MICROSAR OS
 * \details
 * This is a virtual module which contains the user interface (API). The user API is declared in Os.h and the files
 * included from there in order to provide the interface in the header files defined by the AUTOSAR OS standard.
 * However, the subcomponent \ref Os_Trap is responsible for the definition/implementation of the interface.
 *
 * # API functions which may be used before StartOS() {#ApiUsageBeforeStartOsAnchor}
 *
 * The Autosar OS Standard defines which API function is allowed to be called dependent on calling contexts. However,
 * before the OS is started, the allowed calling contexts are not yet cleanly defined. This is done in the picture
 * below.
 *
 * ![API Usage before call of StartOS()](ApiUsageBeforeStartOs.png)
 * \{
 *
 *
 * \file
 * \brief       This file contains all functions and data types which are exposed to the user.
 * \details     It provides the AUTOSAR OS API and proprietary extensions.
 * \trace       SPEC-63736, SPEC-63916
 *
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Alexander Egorenkov           visaev        Vector Informatik GmbH
 *  Andreas Jehl                  virjas        Vector Informatik GmbH
 *  Anton Schmukel                visasl        Vector Informatik GmbH
 *  Benjamin Seifert              virbse        Vector Informatik GmbH
 *  Bilal Parvez                  visbpz        Vector Informatik GmbH
 *  Da He                         visdhe        Vector Informatik GmbH
 *  David Feuerstein              visdfe        Vector Informatik GmbH
 *  Fabian Wild                   viszfa        Vector Informatik GmbH
 *  Hendrik Stoffers              visshk        Vector Informatik GmbH
 *  Ivan Begert                   virbiv        Vector Informatik GmbH
 *  Johannes Thull                visjth        Vector Informatik GmbH
 *  Martin Froschhammer           virmfr        Vector Informatik GmbH
 *  Martin Schultheiss            virsmn        Vector Informatik GmbH
 *  Michael Kock                  vismkk        Vector Informatik GmbH
 *  Rainer Kuennemeyer            visrk         Vector Informatik GmbH
 *  Senol Cendere                 visces        Vector Informatik GmbH
 *  Stefano Simoncelli            virsso        Vector Informatik GmbH
 *  Timo Kerstan                  vistkn        Vector Informatik GmbH
 *  Torsten Schmidt               visto         Vector Informatik GmbH
 *  Susann Rothweiler             visror        Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2016-03-16  visasl  -             Developer version (RC2)
 *                        viszfa
 *                        visrk
 *                        vistkn
 *  01.01.00  2016-04-29
 *  01.01.01  2016-04-29
 *  01.01.02  2016-05-03  visasl  -             Developer version (RC3)
 *                        viszfa
 *                        visrk
 *  01.01.03  2016-05-31  visasl  ESCAN00088874 Bypass interrupt state to/from service functions.
 *                        viszfa  ESCAN00089118 Separation of global data.
 *                        viszfa  ESCAN00089824 Provide possibility to restrict cross core API usage.
 *  01.01.04  2016-06-10  viszfa  -             Internal improvements.
 *  01.01.05  2016-06-27  virbse  ESCAN00090199 Trusted function parameters not ordered by their parameter id.
 *                        virbse  ESCAN00090179 Trusted functions stubs with user specific data types lead to
 *                                              compilation errors.
 *                        visto   ESCAN00089598 Os_Get*StackUsage functions should trigger protection errors instead
 *                                              of application errors.
 *                        viszfa  ESCAN00090425 Startup synchronization is not performed.
 *                        viszfa  ESCAN00090318 Thread/application/OS specific data is mapped into general data
 *                                              sections.
 *                        visasl  ESCAN00089491 Improve support for platforms where the core ID is not readable in user
 *                                              space.
 *                        visrk   ESCAN00090400 Interrupt API does not work before StartOS().
 *                        visrk   ESCAN00089815 Provide OSError_TryToGetSpinlock_Success.
 *                        visrk   ESCAN00089760 Provide NextScheduleTable API.
 *                        visdhe  ESCAN00089652 Detect invalid OS Object IDs compiler independently.
 *                        visdhe  ESCAN00089698 Interrupt resources may lead to interrupt level modification of tasks.
 *                        visdhe  ESCAN00089800 Interrupt Handling Functions do not work when called from non-trusted
 *                                              SW parts.
 *                        visshk  ESCAN00089761 Provide OS start from non autosar master core.
 *                        visrk   ESCAN00089700 Add APIs for disabling interrupt sources, enabling interrupt sources
 *                                              and clear the pending flag of an interrupt source.
 *                        virbse  ESCAN00090396 Generator generates derivative define with explicit derivative instead
 *                                              of group name.
 *                        virbse  ESCAN00097765 Wrong NOCACHE_ZERO_INIT sections in Os_MemMap.h
 *  01.01.06  2016-07-05  visdhe  ESCAN00089612 Support IOC callbacks on local core.
 *                        visdhe  ESCAN00088881 Provide more detailed error code in case of IOC overlay errors.
 *                        visdhe  ESCAN00090320 IOC channel is closed unexpectedly.
 *                        visdhe  ESCAN00090545 Application specific hooks for non-trusted applications are not
 *                                              supported on PowerPC/RH850 architectures.
 *                        visdhe  ESCAN00090546 OSError_* API is not supported on PowerPC architectures in SC3 or SC4.
 *                        viszfa  ESCAN00090602 PanicHook called if interrupt API functions called before StartOS().
 *                        visshk  ESCAN00090624 Core local data is mapped into global OS Section.
 *                        visdfe  ESCAN00090450 Wrong alignment for linker script symbols.
 *  01.01.07  2016-07-22  visasl  ESCAN00090895 The OS API StartCore() does not work on non-AUTOSAR cores.
 *                        vismkk  ESCAN00090890 IOC callback nesting is not supported when sending from callback to a
 *                                              receiver on the local core.
 *                        vismkk  ESCAN00089114 IOC Callbacks for multi receiver configurations are not configurable.
 *                        visrk   ESCAN00089648 Resources are not released during forcible termination of owner thread.
 *                        viszfa  ESCAN00089703 Schedule Table synchronization sporadically fails.
 *                        visrk   ESCAN00090026 Extend ISR epilogue and forcible termination to allow forcible releasing
 *                                              of resources intermixed with spinlocks.
 *                        viszfa  ESCAN00090663 Panic hook called on stack overflow.
 *                        virbiv  ESCAN00090743 Inter-Arrival Time violation for ISR may not be reported.
 *                        virbse  ESCAN00090824 Compiler error: 'RTE_E_NOK' : undeclared identifier.
 *                        visshk  ESCAN00090897 OS API GetCoreID() does not work on non-AUTOSAR cores if Memory
 *                                              Protection is enabled.
 *                        visdfe  ESCAN00090916 Compilation error occurs when using Os.h within a header which is used
 *                                              as include file for Trusted Function stubs.
 *                        virsmn  ESCAN00090935 FPU does not work on PPC derivatives.
 *                        visshk  ESCAN00091390 Interrupt resources are not working (GetResource() and
 *                                              ReleaseResource()).
 *  01.01.08  2016-08-08  virsmn  ESCAN00091137 IOC receive for N:1 function causes memory exception.
 *  01.01.09  2016-08-22  virbiv  WORKITEM6671  Support the Cortex-R on Xilinx Ultrascale ZU9EG (as single core) as
 *                                              development quality.
 *                        virsmn  ESCAN00089169 Stay in waiting state in case of time frame violations.
 *                        vismkk  ESCAN00091224 VTT Synchronizer does not work properly.
 *                        visdhe  WORKITEM8032  Performance improvements on VTT.
 *  01.01.10  2016-09-05  virsmn  ESCAN00089920 Inter-arrival time protection for self-chaining tasks is not provided
 *                        visces  ESCAN00090971 Syscall instruction leads to unpredictable state
 *                        visces  ESCAN00091503 CPU does not run into startup code because reset vector is missing at
 *                                              designated address.
 *                        visces  ESCAN00091490 Parts of OS code are linked to default section ".text" instead of
 *                                              section ".OS_CODE"
 *                        virbse  WORKITEM7244  Improve auto solving actions in OS generator.
 *                        virbse  WORKITEM5608
 *                        visjth  ESCAN00091580 OsSystemIntCtrlPrioOrder is incorrectly synchronized.
 *                        visdhe  WORKITEM5496  Support the Aurix TC3xx devices as development quality.
 *                        visdfe  ESCAN00091362 Generated link scripts for HighTec compiler do not work correctly.
 *  01.02.00  2016-09-19  visasl  WORKITEM6031  Support the Cortex-R (Traveo, single core) devices as QM quality.
 *                        visasl  ESCAN00091238 Incompatibility of Idle Task configuration to RTE Background Task.
 *                        visto   ESCAN00091588 Extend Technical Reference: Os_MemMap.h should be included in MemMap.h
 *                                              manually.
 *                        virsmn  WORKITEM7266  Support the Diab Compiler on PPC.
 *                        virsmn  ESCAN00091721 Unexpected call of ProtectionHook (non-trusted function call).
 *                        virsmn  ESCAN00091722 Unpredictable behaviour on trusted function call.
 *                        visdhe  WORKITEM8043  Provide interrupt source API as ASIL-D quality.
 *                        visrk   WORKITEM8586  Provide Vector Timing Hooks as QM quality.
 *                        virsmn  ESCAN00091825 Category 2 interrupt handling could lead to unpredictable program
 *                                              behaviour.
 *                        visrk   ESCAN00091634 Support ORTI file generation.
 *  01.03.00  2016-09-30  visces  ESCAN00091073 Cat.2 interrupts are still enabled when GetResource is called for an
 *                                              interrupt resource.
 *                        visasl  WORKITEM8970  Support CallTrustedFunction and Peripheral Access API in Pre-Start Task.
 *                        virbse  WORKITEM8430  Provide start and end linker labels for all MemMap sections, which can
 *                                              be used in MPU region configuration.
 *                                              Provide solving actions for MPU configuration in SC3/SC4.
 *                        virsso  ESCAN00091776 A schedule table still triggers its actions after its application is
 *                                              forcibly terminated.
 *                        visdhe  ESCAN00091751 Non-nestable ISRs not working.
 *                        visjth  ESCAN00091538 Race condition of interrupts may lead to an unstable system state in
 *                                              VTTOS.
 *                        visdfe  ESCAN00091598 Linker alignment for interrupt and exception vectors is generated with
 *                                              same amount as for standard code sections.
 *                        vismkk  WORKITEM8709  Consider SIP license in provided solving actions.
 *                        vismkk  ESCAN00091734 Automatically created counter interrupts may have no OS access.
 *  01.04.00  2016-10-20  virsmn  ESCAN00092087 OS counter interrupts are not initialized by OS on PowerPC
 *                        visdhe  ESCAN00091880 Multicore startup fails if core 0 is configured as slave
 *                        visdfe  ESCAN00091778 Multicore not supported on derivatives without consecutive physical
 *                                              core IDs.
 *                        visdfe  ESCAN00092003 GetCoreID returns physical core ID instead of logical core ID
 *                        virsmn  ESCAN00092238 Core MPU on e200z225 core can not be used by OS
 *                        visdhe  WORKITEM7288  Provide virtual master core concept.
 *                        virbiv  ESCAN00091986 TimingProtection not working for ISRs with disabled nesting
 *                        visces  ESCAN00092100 Tasks are not started when using registermode=22 on RH850
 *                        virbiv  WORKITEM9021  Support for ARM Cortex ARMv7M architecture as development quality
 *                                              using GHS compiler (Reference Derivative: ATMEL SAM v71)
 *  01.04.01  2016-10-28  visdhe  ESCAN00092302 Timing protection ISR terminates with the error OS_STATUS_DISABLEDINT
 *                        visdhe  ESCAN00092399 The OS stays in an endless loop during StartOS, when PCXI is not
 *                                              initialized with 0.
 *                        visdhe  ESCAN00092117 Output parameter of getter APIs is not modified in case of aggressive
 *                                              compiler optimization.
 *                        virsmn  ESCAN00092369 Interrupt handling does not work on derivatives with non consecutive
 *                                              core ids.
 *                        visdhe  ESCAN00092193 Idle task will terminate with "Missing TerminateTask" error by using
 *                                              Tasking compiler without optimization.
 *                        virsmn  ESCAN00092370 Handling of interrupt could lead to unpredictable behaviour.
 *                        virsmn  WORKITEM9033  Improvements in ARM Cortex ARMv7M support.
 *                        virsso  WORKITEM10100 Improvements in ARM CortexR Zynq support.
 *  01.05.00  2016-11-14  visdfe  ESCAN00091978 Usage of OS API ORTI Tracing leads to protection violation in SC3 and
 *                                              SC4 systems.
 *  01.06.00  2016-11-28  visdhe  -             Internal improvements
 *  01.07.00  2016-12-05  virbiv  ESCAN00092530 System freezes during PreStartTask
 *                        visdfe  ESCAN00092195 Unpredictable behavior caused by racing condition when starting the OS
 *                        visjth  ESCAN00092119 Missing external Symbol in Os_Hal_Context_Lcfg.c when configuring
 *                                              Trusted Functions in non privileged Applications
 *                        visjth  ESCAN00092653 Cycle time of OS timers changes after reset
 *                        visjth  ESCAN00091379 Synchronization of Alarms in VTT Dual Target configuration not working
 *                                              when Alarms are deleted by RTE in VttOs
 *                        visjth  ESCAN00092991 OsDerivativeInformation Container duplicated in dual target use case
 *                        visrk   ESCAN00092917 Interrupts are enabled in PreStartTask.
 *                        vismkk  ESCAN00091924 BETA version - the BSW module has a feature with BETA state (Vector
 *                                              Timing Hooks)
 *                        visrk   ESCAN00092380 Interrupt Service Routine is executed although interrupts are disabled.
 *  01.08.00  2016-12-22  virjas  WORKITEM10112 Support PPC QUASAR3.
 *                        virsmn  WORKITEM11027 Support PPC semaphore unit.
 *                        virsmn  ESCAN00093279 Spinlock API does not work properly.
 *                        visces  ESCAN00092010 ReleaseResource restores wrong interrupt level when called in
 *                                              non-nestable ISRs.
 *                        virbiv  WORKITEM7465  Support IAR Compiler on Cortex-M.
 *                        virbiv  ESCAN00093193 Interrupt handler may be delayed by unknown time.
 *  01.09.00  2017-01-23  virsmn  ESCAN00093436 Compiler error: identifier "OsCfg_Hal_Core_OsCore<x>" is undefined
 *                        vismkk  ESCAN00093468 Generator throws IndexOutOfBounds exception on S32K14x derivatives
 *                        vismkk  ESCAN00093472 Wrong OsMemoryRegionBusMasterIds in pre-config of S32K14x
 *                        visrk   ESCAN00093275 ChainTask() returns to caller with disabled interrupts if the OS detects
 *                                              an error.
 *                        vismkk  ESCAN00092839 Linker include files are not generated for non-AUTOSAR cores.
 *                        visdhe  ESCAN00092854 Usage of Interrupt API in category1 ISR might lead to exception.
 *                        visrk   ESCAN00093586 Null Pointer Exception during generation of Os_Hal_Core_Lcfg.c
 *                        visrk   ESCAN00092557 API function Os_GetUnhandledExc() provides wrong value.
 *                        virbse  WORKITEM13469 Reduce number of MemMap sections (code).
 *                        virbse  WORKITEM13471 Reduce number of MemMap sections (stack).
 *                        virbse  WORKITEM11361 Example code for ErrorHook in Os_CalloutStubs.c.
 *  02.00.00  2017-02-02  virbiv  WORKITEM10355 Provide Os_CallFastTrustedFunction() as BETA feature.
 *                        visdfe  WORKITEM12188 Provide Os_BarrierSynchronize() as BETA feature.
 *                        visdhe  ESCAN00093803 Compiler error: "The selected derivative is not supported!" for PC580003
 *                                              derivatives
 *  02.01.00  2017-02-08  virbiv  ESCAN00093485 Access to uninitialized memory in XSignal receiver ISR if not all
 *                                              AUTOSAR cores have been started.
 *                        virsmn  ESCAN00093706 Interrupt controller does not work properly.
 *                        virbiv  ESCAN00093961 Nested interrupt may cause an exception loop.
 *                        virbiv  ESCAN00093930 Possible MemoryProtection violation
 *  02.02.00  2017-03-02  visdhe  WORKITEM15265 Some memory section mappings are generated more than once.
 *                                ESCAN00093495 Null pointer access during StartOS() in case an AUTOSAR core has no
 *                                              XSignal configuration.
 *                                WORKITEM10619 OS should generate the linker scripts for ARM OS without alignment if no
 *                                              memory protection configured.
 *                                ESCAN00093894 Wrong generated defines in VTT GenData in DualTarget use case.
 *                                ESCAN00093236 Compiler error: OS does not compile if only application specific hooks
 *                                              are configured.
 *                        virbiv  ESCAN00093390 Interrupts are getting nested even with disabled nesting
 *                                ESCAN00094082 UsageFault exception during startup
 *                                ESCAN00094081 Start address of the interrupt vector table not correctly generated
 *                        virbse  ESCAN00091624 Using array types for unqueued IOC communication leads to compile error:
 *                                              array initialization needs curly braces.
 *                                ESCAN00092812 Using trusted function stubs with user defined types may lead to compile
 *                                              error: left operand must be an l-value.
 *                                ESCAN00093633 Compiler error: Mismatch between expected and generated trusted function
 *                                              signature.
 *            2017-03-20  visces  ESCAN00093389 Writing IRQPLM causes an exception after an nondeterministic time
 *                                ESCAN00093962 The OS does not correctly handle the unhandled exceptions
 *                                ESCAN00094148 The cross core communication does work on systems with mixed core IDs
 *                        visdhe  ESCAN00094000 Wrong core assignment of interrupts on systems with mixed core IDs
 *                                ESCAN00094390 Wrong core assignment in OS_ISR1() macro in case of mixed core id
 *                                              configuration
 *                                ESCAN00093987 Wrong names of MPUs in pre-configuration for TC39x derivatives
 *                                ESCAN00094166 Wrong core assignment of interrupts on systems with mixed core IDs
 *                                ESCAN00093917 Timing protection ISR always lowers its interrupt level to the OS system
 *                                              level during interrupt prologue
 *  02.03.00  2017-03-28  visto   WORKITEM14883 Support for CortexR UltraScale
 *                        virsso  WORKITEM13342 Support for Guest OS on POSIX
 *  02.04.00  2017-04-07  virsmn  ESCAN00093278 OS does not start if OsStackUsageMeasurement is enabled.
 *            2017-04-10  visdhe  ESCAN00093669 Compiler error: Identifier OSError_GetScheduleTableStatus_ScheduleStatus
 *                                              not defined.
 *            2017-04-11  vismkk  ESCAN00094170 Possible endless loop during OS startup if a protection violation occurs.
 *            2017-04-12  visdfe  ESCAN00094147 Timing protection budgets are reseted if a hook is called.
 *            2017-04-20  virbiv  ESCAN00093918 TimingProtection: PreTaskHook consumes timing budget of previous task
 *                        visces  ESCAN00093998 Forcible termination in PreTaskHook leads to unpredictable OS behaviour.
 *                                ESCAN00094066 Forcible termination in PostTaskHook leads to unpredictable OS behaviour.
 *                                ESCAN00094167 PostTaskHook is called recursively, if PostTaskHook triggers
 *                                              ProtectionHook and the ProtectionHook returns a forcible termination
 *                                              reaction.
 *                                ESCAN00094398 PostTaskHook is called recursively, if PostTaskHook triggers the
 *                                              ErrorHook.
 *  02.04.01  2017-04-28  visshk  ESCAN00094817 OS cores are not synchronized during startup and shutdown and the app
 *                                              mode is erroneously reported as invalid
 *                                ESCAN00094962 OS enters endless loop during startup
 *  02.05.00  2017-05-04  vismkk                Internal improvements.
 *            2017-05-16  virbse  ESCAN00094773 Spinlocks of high diagnostic coverage may be fetched/released by cores
 *                                              with lower diagnostic coverage without sufficient access rights
 *                                ESCAN00094774 IOCs data of high diagnostic coverage may be modified by cores with
 *                                              lower diagnostic coverage without sufficient access rights
 *                                FEAT-2824     Support of PRO_IGNORE_EXCEPTION in the Protection Hook (limited to
 *                                              platform Ppc).
 *  02.06.00  2017-06-01  visdfe  ESCAN00094046 Wrong validation of the maximum available MPU regions
 *                        visdhe  ESCAN00093999 API GetNumberOfActivatedCores() triggers kernel panic if caller is not
 *                                              trusted.
 *                        visces  STORYC-1084   Internal improvements
 *                        viszfa  ESCAN00095302 Os_Init and Os_InitMemory APIs perform invalid write access
 *                        viszfa  ESCAN00095569 Compiler error: OS object symbols are not defined in user header include
 *  02.07.00  2017-06-27  viszfa  ESCAN00095585 Incompatible change of peripheral API interface leads to a compilation
 *                                              warning or error
 *                        visces  STORY-1038    Added interrupts of CATEGORY_0
 *  02.08.00  2017-07-06  virjas  WORKITEM15088 Internal improvements
 *                        visces  STORRYC-1176  Support RH850 P1M-C and P1H-C with extended support for timer STM
 *                        visdhe  ESCAN00095893 Protection hook is not called after expected timing protection budget
 *                                              of task/ISR has expired.
 *  02.09.00  2017-07-24  virsmn  ESCAN00094867 Compiler warning: warning #1514-D: incorrect GHS #pragma:
 *                                              small data area is not supported in this configuration.
 *                        vismkk  ESCAN00096171 Cross core API is performed multiple times (with synchronous XSignal
 *                                              only)
 *                        vismkk  ESCAN00096288 Cross core API returns late or never (with synchronous XSignal only)
 *  02.10.00  2017-08-25  virsso  ESCAN00094476 If the ProtectionHook() returns PRO_TERMINATETASKISR and no Task or ISR
 *                                              can be associated with the error, ShutdownOS() is called.
 *                        virsmn  ESCAN00095918 TimingProtection ISR is executed during Startup with not initialized
 *                                              thread dynamic configuration
 *                        viszfa  ESCAN00096463 Protection Hook not called at the expected point in time in case of Lock
 *                                              Budget violations
 *  02.10.01  2017-09-22  visshk  ESCAN00096777 Incorrect scheduling when using Spinlocks with OsSpinlockLockMethod
 *                                              LOCK_WITH_RES_SCHEDULER
 *  02.11.00  2017-10-10  visces  ESCAN00095552 Free Running Timers configured as non High Resolution Counters do not
 *                                              work properly.
 *                                ESCAN00096894 Interrupts are still disabled when returning from EnableAllInterrupts,
 *                                              ResumeAllInterrupts, ReleaseSpinlock or Os_EnableGlobal*
 *                                ESCAN00097942 Interrupts are still (partially) disabled when returning from
 *                                              EnableAllInterrupts, ResumeAllInterrupts, ReleaseSpinlock or
 *                                              Os_EnableGlobal* after the corresponding suspension API has been
 *                                              interrupted by a Category 2 ISR
 *  02.12.00  2017-10-11  virbse  STORY-2237    Internal improvements in generator
 *                                ESCAN00096931 Internal improvements in generator
 *                        visces  STORY-1738    Two new Vector Timing Hook calls (unsuccessfull wait and activate)
 *                        viszfa  FEAT-3204     Provide Vector Timing Hooks so that they are useable in safety serial
 *                                              production environments
 *            2017-10-18  virbse  FEAT-2816     Support shared stack for non-preemptive Basic tasks
 *                                FEAT-2815     Support shared stack for tasks with same internal resource
 *  02.13.00  2017-11-03  virsmn  ESCAN00096854 Usage of High Resolution Timer and Master Protection Mechanism of INTC
 *                                              could lead to protection violation.
 *                                ESCAN00097308 Time triggered events based on PFRT do not occur for an unspecific
 *                                              amount of time
 *                        visbpz  STORY-2620    Internal interrupt API performance improvements
 *                        virsmn  ESCAN00096860 ProtectionHook is called directly after the activation of a task or
 *                                              ISR with Timing Protection
 *  02.14.00  2017-11-22  virsso  STORYC-1751   Performance improvements on some platforms by giving the possibility to
 *                                              read privileges directly from hardware
 *                        visbpz  STORY-2769    OS Interrupt API optimization by replacement of a call sequence for
 *                                              modification of the global interrupt flag.
 *                        virsso  ESCAN00097558 A task activated by an API or a time triggered event is not scheduled
 *                                              or scheduled at an incorrect priority.
 *                        visdhe  ESCAN00097655 Timinig violation of a killed ISR is reported a second time.
 *                        visrk   ESCAN00097597 Explicitly synchronized schedule table is not synchronized on the first
 *                                              call of SyncScheduleTable
 *  02.15.00  2018-01-10  visrk   STORYC-3218   Support for user configurable FPU cotext saving
 *                        visshk  ESCAN00097946 Interrupts are still disabled when returning from ResumeOSInterrupts or
 *                                              ReleaseSpinlock after the corresponding suspension API has been
 *                                              interrupted
 *  02.16.00  2018-01-29  virsmn  STORYC-3600   Update according to CDK coding guidelines.
 *                        virjas  STORYC-3599   Improve coverage justifications.
 *                        virsmn  STORYC-3282   Support for user Msr settings.
 *                        viszfa  ESCAN00098289 Calling SyncScheduleTable ... leads to a constant offset...
 *  02.17.00  2018-02-20  visbpz  STORYC-4070   Performance improvement for interrupt APIs.
 *                        virsmn  STORYC-3042   Support for OS internal exception detection.
 *  02.18.00  2018-03-23  visbpz  STORYC-4068   Performance improvment by avoiding traps.
 *                        visdhe  ESCAN00098976 Compiler warning: warning (etoa:1634): cannot fit enum into short
 *                                              integer type.
 *                        visces  STORYC-4469   Support for ARM compiler version >= 6.6.1.
 *  02.19.00  2018-04-23  virsmn  STORYC-4799   ASIL support for platforms without FRT and/or TP support.
 *            2018-05-03  virsmn  STORYC-3965   Support for platforms without interrupt priority level switching.
 *  02.20.00  2018-05-14  virsmn  STORYC-3320   Added support for interrupt mapping feature.
 *  02.21.00  2018-06-16  visrk   STORYC-4842   Optimized task queues.
 *            2018-06-29  virsmn  STORYC-5594   Added support fo aggregated stack configuration view.
 *  02.22.00  2018-07-13  virsmn  STORYC-3152   Optimization for SingleCore Systems.
 *            2018-07-18  virsmn  STORYC-5541   Optimization for task scheduling.
 *            2018-07-18  virsmn  STORYC-4159   Improvement for internal testing.
 *  02.23.00  2018-07-31  visrk                 Internal improvement.
 *            2018-08-01  virsmn  ESCAN00098513 PanicHook is called or system enters endless loop on stack overflow.
 *            2018-08-07  virsmn  STORYC-4094   Achieve 100 percent variant coverage.
 *            2018-08-22  virsmn  ESCAN00100439 Unexpected call of ProtectionHook with parameter value
 *                                              E_OS_PROTECTION_TIME.
 *  2.24.00   2018-08-29  virbse  STORYC-6182   As a customer I want to be informed if I configure an OS internal
 *                                              function as OsIsrSpecialFunctionName of an OsIsr.
 *                        visrk   TASK-88319    Internal improvement.
 *  2.25.00   2018-10-05  visror  STORYC-4537   MISRA-C 2012 Compliance.
 *  2.26.00   2018-11-02  virsmn  ESCAN00101088 Missing ROM data sections for Globalshared ZERO_INIT sections.
 *            2018-11-08  virbse  STORYC-4796   Interrupt API optimization.
 *  2.27.00   2018-11-02  virsmn  STORYC-6395   Optimization for context switch.
 *            2018-11-29  visshk  STORYC-4461   Optimization for OS footprint.
 *            2018-12-07  visaev  STORYC-6935   Interrupt API optimization.
 *            2018-12-10  visrk   STORYC-6741   New API to enable all external Interrupts at once (Beta)
 *  2.28.00   2019-01-09  visror  ESCAN00101533 Missing safety measure for XSignal Hook Call
 *            2019-01-11  visror  STORYC-4470   Reduce OS Footprint.
 *  2.29.00   2019-01-18  virsmn  STORYC-7070   Added validation for MPU region alignment.
 *                        visaev  TASK-104049   Internal improvement.
 *                        virsmn  ESCAN00101809 OS ends up in KernelPanic (CoreFreeze) due to failed assertion.
 *                        visaev  STORYC-7166   Added OS API Os_InitialEnableInterruptSources.
 **********************************************************************************************************************/

#ifndef OS_H
# define OS_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "OsInt.h"
# include "Os_Cfg.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os Hal dependencies */
# include "Os_Hal_Os.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Vendor and module identification */
# define OS_VENDOR_ID                            (30u)
# define OS_MODULE_ID                            (0x01u)

/* AUTOSAR Software specification version information */
# define OS_AR_RELEASE_MAJOR_VERSION             (4u)
# define OS_AR_RELEASE_MINOR_VERSION             (2u)
# define OS_AR_RELEASE_REVISION_VERSION          (1u)

/* ----- Component version information ----- */
# define OS_SW_MAJOR_VERSION                     (2u)
# define OS_SW_MINOR_VERSION                     (29u)
# define OS_SW_PATCH_VERSION                     (0u)


/*! OS service: GetElapsedCounterValue() (AUTOSAR backward compatibility) */
# define GetElapsedCounterValue   GetElapsedValue


/* The following API defines are used by the RTE to check whether the API is available. */
/*! OS service: osDisableLevelAM() (Gen6 backward compatibility ESCAN00079751) */
# define osDisableLevelAM         Os_DisableLevelAM
/*! OS service: osDisableLevelKM() (Gen6 backward compatibility ESCAN00079751) */
# define osDisableLevelKM         Os_DisableLevelKM
/*! OS service: osDisableLevelUM() (Gen6 backward compatibility ESCAN00079751) */
# define osDisableLevelUM         Os_DisableLevelUM
/*! OS service: osEnableLevelAM() (Gen6 backward compatibility ESCAN00079751) */
# define osEnableLevelAM          Os_EnableLevelAM
/*! OS service: osEnableLevelKM() (Gen6 backward compatibility ESCAN00079751) */
# define osEnableLevelKM          Os_EnableLevelKM
/*! OS service: osEnableLevelUM() (Gen6 backward compatibility ESCAN00079751) */
# define osEnableLevelUM          Os_EnableLevelUM
/*! OS service: osDisableGlobalAM() (Gen6 backward compatibility ESCAN00079751) */
# define osDisableGlobalAM        Os_DisableGlobalAM
/*! OS service: osDisableGlobalKM() (Gen6 backward compatibility ESCAN00079751) */
# define osDisableGlobalKM        Os_DisableGlobalKM
/*! OS service: osDisableGlobalUM() (Gen6 backward compatibility ESCAN00079751) */
# define osDisableGlobalUM        Os_DisableGlobalUM
/*! OS service: osEnableGlobalAM() (Gen6 backward compatibility ESCAN00079751) */
# define osEnableGlobalAM         Os_EnableGlobalAM
/*! OS service: osEnableGlobalKM() (Gen6 backward compatibility ESCAN00079751) */
# define osEnableGlobalKM         Os_EnableGlobalKM
/*! OS service: osEnableGlobalUM() (Gen6 backward compatibility ESCAN00079751) */
# define osEnableGlobalUM         Os_EnableGlobalUM


/*! OS service: osDisableInterruptSource() (Gen6 backward compatibility) */
# define osDisableInterruptSource Os_DisableInterruptSource
/*! OS service: osEnableInterruptSource() (Gen6 backward compatibility) */
# define osEnableInterruptSource  Os_EnableInterruptSource
/*! OS service: osDisableInterruptSource() (Gen6 backward compatibility) */
# define osClearPendingInterrupt  Os_ClearPendingInterrupt
/*! OS service: osIsInterruptSourceEnabled() (Gen6 backward compatibility) */
# define osIsInterruptSourceEnabled  Os_IsInterruptSourceEnabled
/*! OS service: osIsInterruptPending() (Gen6 backward compatibility) */
# define osIsInterruptPending  Os_IsInterruptPending


#if OS_CFG_PERIPHERAL_COMPATIBILITY == STD_ON
/*! OS service: osReadPeripheral8() (Gen6 backward compatibility) */
# define osReadPeripheral8        Os_ReadPeripheral8Legacy
/*! OS service: osReadPeripheral16() (Gen6 backward compatibility) */
# define osReadPeripheral16       Os_ReadPeripheral16Legacy
/*! OS service: osReadPeripheral32() (Gen6 backward compatibility) */
# define osReadPeripheral32       Os_ReadPeripheral32Legacy
/*! OS service: osWritePeripheral8() (Gen6 backward compatibility) */
# define osWritePeripheral8       Os_WritePeripheral8Legacy
/*! OS service: osWritePeripheral16() (Gen6 backward compatibility) */
# define osWritePeripheral16      Os_WritePeripheral16Legacy
/*! OS service: osWritePeripheral32() (Gen6 backward compatibility) */
# define osWritePeripheral32      Os_WritePeripheral32Legacy
/*! OS service: osModifyPeripheral8() (Gen6 backward compatibility) */
# define osModifyPeripheral8      Os_ModifyPeripheral8Legacy
/*! OS service: osModifyPeripheral16() (Gen6 backward compatibility) */
# define osModifyPeripheral16     Os_ModifyPeripheral16Legacy
/*! OS service: osModifyPeripheral32() (Gen6 backward compatibility) */
# define osModifyPeripheral32     Os_ModifyPeripheral32Legacy
#endif

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_GetVersionInfo()
 **********************************************************************************************************************/
/*! \brief        AUTOSAR Get Version Information API.
 *  \details      Returns the Published information of MICROSAR OS.
 *
 *  \param[out]   versioninfo   Version information (decimal coded).
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Given object pointer(s) are valid.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_GetVersionInfo
(
  Std_VersionInfoType *versioninfo
);


/***********************************************************************************************************************
 *  Os_GetExceptionContext()
 **********************************************************************************************************************/
/*! \brief        Getter function for the exception context.
 *  \details      Returns the context structure of the thread interrupted by an exception.
 *
 *  \param[out]   Context   current exception context.
 *
 *  \return       E_OK                No Error.
 *                E_OS_PARAM_POINTER (EXTENDED status:) given pointer is a NULL_PTR.
 *                E_OS_CALLEVEL      (EXTENDED status:) Called from invalid context.
 *                E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (EXTENDED status:)
 *                   Context manipulation is not supported on this hardware.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different Context
 *  \synchronous  TRUE
 *
 *  \pre          Given object pointer(s) are valid.
 *
 *  \trace        CREQ-129664
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_GetExceptionContext
(
  Os_ExceptionContextRefType Context
);


/***********************************************************************************************************************
 *  Os_SetExceptionContext()
 **********************************************************************************************************************/
/*! \brief        Setter function for the exception context.
 *  \details      Writes the given context into the exception context structure.
 *
 *  \param[in]    Context   context to set.
 *
 *  \return       E_OK                No Error.
 *                E_OS_PARAM_POINTER (EXTENDED status:) given pointer is a NULL_PTR.
 *                E_OS_CALLEVEL      (EXTENDED status:) Called from invalid context.
 *                E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (EXTENDED status:)
 *                   Context manipulation is not supported on this hardware.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE for different cores
 *  \synchronous  TRUE
 *
 *  \pre          Given object pointer(s) are valid.
 *
 *  \trace        CREQ-129663
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_SetExceptionContext
(
  Os_ExceptionContextRefType Context
);


/***********************************************************************************************************************
 *  Os_InitMemory()
 **********************************************************************************************************************/
/*! \brief        Proprietary initialization function to optimize startup code.
 *  \details      Initializes the dynamic part of the system and all cores.
 *                This is an API function which is provided within all BSWs of Vector.
 *                It initializes variables of the BSW.
 *                Within the OS module this function is currently empty
 *                This service must be called on all available cores
 *                (even for cores which are intended to be a non-AUTOSAR core)
 *
 *  \context      INIT
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_InitMemory
(
  void
);


/***********************************************************************************************************************
 *  Os_Init()
 **********************************************************************************************************************/
/*! \brief        AUTOSAR Initialization Interface.
 *  \details      Emulation of master-slave behavior, if needed.
 *                Allow usage of interrupt API, before StartOS(), if on AUTOSAR core.
 *                Nevertheless, category 2 ISRs must not occur before calling StartOS()!
 *                Attach to Synchronization barrier, if master core and AUTOSAR core.
 *                The function performs all the basic OS initialization which includes
 *                   - Variable initialization
 *                   - Interrupt controller initialization
 *                   - System MPU initialization in SC3 and SC4 systems (if supported by platform)
 *                   - Synchronization barriers in multi core systems
 *                A function call to this service must be available on all available cores (even for cores which are
 *                intended to be a non-AUTOSAR core)
 *                After call of Os_Init() the AUTOSAR interrupt API may be used.
 *                After Call of Os_Init() the API GetCoreID may be used.
 *
 *  \context      INIT
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Concurrent access is prevented by caller.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_Init
(
  void
);


/***********************************************************************************************************************
 *  Os_EnterPreStartTask()
 **********************************************************************************************************************/
/*! \brief        This function performs a minimum initialization to be able to call non-trusted functions before
 *                StartOS().
 *  \details      The use case is to initialize time critical QM drivers before StartOS().
 *                The function schedules and dispatches to the pre-start task. The core is initialized that
 *                non-trusted function calls can be used safely within this task.
 *                Has to be called on a core which is started as an AUTOSAR core.
 *                The core which calls this function must have a configured pre-start task.
 *                Must only be called once.
 *                Must be called prior to StartOS() but after Os_Init()
 *
 *  \context      INIT
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Concurrent access is prevented by caller.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_EnterPreStartTask
(
  void
);

/***********************************************************************************************************************
 *  StartCore()
 **********************************************************************************************************************/
/*! \brief        OS service StartCore().
 *  \details      Starts the core given by CoreID that is controlled by the AUTOSAR OS.
 *                This API is allowed to be used from AUTOSAR and non-AUTOSAR cores.
 *
 *  \param[in]    CoreID  The core to start.
 *  \param[out]   Status  Status code.
 *
 *  \return       E_OK          No Error.
 *                E_OS_ID       (EXTENDED status:)
 *                              - Core ID is invalid.
 *                              - Core is no AUTOSAR core.
 *                E_OS_ACCESS   (EXTENDED status:) The function was called after starting the OS.
 *                E_OS_STATE    (EXTENDED status:) The Core is already activated.
 *
 *  \context      -
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Supervisor mode.
 *  \pre          Pre-Condition: Given object pointer(s) are valid.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) StartCore
(
  CoreIdType CoreID,
  StatusType *Status
);


/***********************************************************************************************************************
 *  StartNonAutosarCore()
 **********************************************************************************************************************/
/*! \brief        OS service StartNonAutosarCore().
 *  \details      Starts the core given by CoreID that is not controlled by the AUTOSAR OS.
 *
 *  \param[in]    CoreID  The core to start.
 *  \param[out]   Status  Status code.
 *
 *  \return       E_OK          No Error.
 *                E_OS_ID       (EXTENDED status:) Core ID is invalid.
 *                E_OS_STATE    (EXTENDED status:) The Core is already activated.
 *
 *  \context      -
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Supervisor mode.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) StartNonAutosarCore
(
  CoreIdType CoreID,
  StatusType *Status
);


/***********************************************************************************************************************
 *  GetCoreID()
 **********************************************************************************************************************/
/*! \brief        OS service GetCoreID().
 *  \details      Returns the unique logical core identifier of the core on which the function is called.
 *                The mapping of physical cores to logical CoreIDs is implementation specific.
 *                This API is allowed to be used from AUTOSAR cores only. If the API is required on a non-AUTOSAR core,
 *                it is possible to configure the core as an AUTOSAR core but start it as a non-AUTOSAR core using the
 *                StartNonAutosarCore() API.
 *
 *  \return       Unique ID of the calling core.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(CoreIdType, OS_CODE) GetCoreID
(
  void
);


/***********************************************************************************************************************
 *  GetNumberOfActivatedCores()
 **********************************************************************************************************************/
/*! \brief        OS service GetNumberOfActivatedCores().
 *  \details      The function returns the number of cores activated by the StartCore() function.
 *                AUTOSAR specifies this function to be usable from task and ISR call level.
 *                But this function does not explicitly perform any call context checks.
 *                There is no need to, because it is a primitive getter function.
 *
 *  \return       Number of cores activated by the StartCore() function.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) GetNumberOfActivatedCores
(
  void
);


/***********************************************************************************************************************
 *  GetActiveApplicationMode()
 **********************************************************************************************************************/
/*! \brief        OS service GetActiveApplicationMode().
 *  \details      This service returns the current application mode.
 *
 *  \return       Current Application Mode
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(AppModeType, OS_CODE) GetActiveApplicationMode
(
  void
);


/***********************************************************************************************************************
 *  StartOS()
 **********************************************************************************************************************/
/*! \brief        OS service StartOS().
 *  \details      Starts the operating system in a given application mode.
 *
 *  \param[in]    Mode    The application mode in which the OS shall start.
 *
 *  \context      -
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Supervisor mode.
 *  \pre          Pre-Condition: Os_Init() has been called before.
 *
 *  \trace        SPEC-63921, SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_CODE) StartOS
(
  AppModeType Mode
);


/***********************************************************************************************************************
 *  ShutdownOS()
 **********************************************************************************************************************/
/*! \brief        OS service ShutdownOS().
 *  \details      This function shall shutdown the core on which it was called. Only allowed in trusted applications.
 *                In case that ShutdownOS() is called from an invalid context, OS_STATUS_CALLEVEL is reported via the
 *                ProtectionHook.
 *
 *  \param[in]    Error   Error code which shall be passed to the ShutdownHook()
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921, SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_CODE) ShutdownOS
(
  StatusType Error
);


/***********************************************************************************************************************
 *  ShutdownAllCores()
 **********************************************************************************************************************/
/*! \brief        OS service ShutdownAllCores().
 *  \details      Propagates a shutdown request to all started AUTOSAR cores and performs a shutdown itself afterwards.
 *                Only allowed in trusted applications.
 *
 *  \param[in]    Error    This is the error code which shall be passed to the ShutdownHook().
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) ShutdownAllCores
(
  StatusType Error
);


/***********************************************************************************************************************
 *  ControlIdle()
 **********************************************************************************************************************/
/*! \brief        OS service ControlIdle().
 *  \details      This API allows the caller to select the idle mode action which is performed during idle
 *                time of the OS (e.g. if no Task/ISR is active).
 *                The real idle modes are hardware dependent and not standardized.
 *                The default idle mode on each core is IDLE_NO_HALT.
 *
 *  \param[in]    CoreID   Selects the core which idle mode is set
 *  \param[in]    IdleMode The mode which shall be performed during idle time
 *
 *  \return       E_OK                No error.
 *                E_OS_ID             (EXTENDED status): Invalid core and/or invalid IdleMode.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) ControlIdle
(
  CoreIdType CoreID,
  IdleModeType IdleMode
);


/***********************************************************************************************************************
 *  Os_GetUnhandledIrq()
 **********************************************************************************************************************/
/*! \brief        Proprietary OS service Os_GetUnhandledIrq().
 *  \details      Returns the source number of the last interrupt, which occurred but haven't been configured.
 *                Encoding of source numbers is platform specific.
 *                The return value of this function may be interpreted differently for different controller families.
 *
 *  \param[out]   InterruptSource   Interrupt source number.
 *
 *  \return       E_OK                 No error.
 *                E_OS_PARAM_POINTER   (EXTENDED status): Null pointer passed as argument.
 *                E_OS_CORE            (EXTENDED status): Called from non autosar core.
 *                E_OS_STATE           No unhandled exception reported since start up.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_GetUnhandledIrq
(
  Os_InterruptSourceIdRefType InterruptSource
);


/***********************************************************************************************************************
 *  Os_GetUnhandledExc()
 **********************************************************************************************************************/
/*! \brief        Proprietary OS service Os_GetUnhandledExc().
 *  \details      Returns the source number of the last exception, which occurred but cannot be handled by the OS.
 *                Encoding of source numbers is platform specific.
 *                The return value of this function may be interpreted differently for different controller families.
 *
 *  \param[out]   ExceptionSource   Exception source number.
 *
 *  \return       E_OK                 No error.
 *                E_OS_PARAM_POINTER   (EXTENDED status): Null pointer passed as argument.
 *                E_OS_CORE            (EXTENDED status): Called from non autosar core.
 *                E_OS_STATE           No unhandled exception reported since start up.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_GetUnhandledExc
(
  Os_ExceptionSourceIdRefType ExceptionSource
);


/***********************************************************************************************************************
 *  Os_GetTaskStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current stack usage of the given task.
 *  \details      (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into
 *                shutdown.
 *
 *  \param[in]    TaskID        The task which shall be queried.
 *
 *  \return       Current stack usage of the given task in bytes.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_GetTaskStackUsage
(
  TaskType TaskID
);


/***********************************************************************************************************************
 *  Os_GetISRStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current stack usage of the given ISR.
 *  \details      (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into
 *                shutdown.
 *
 *  \param[in]    IsrID         The ISR which shall be queried.
 *
 *  \return       Current stack usage of the given ISR in bytes.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_GetISRStackUsage
(
  ISRType IsrID
);


/***********************************************************************************************************************
 *  Os_GetKernelStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current kernel stack usage on the given core.
 *  \details      (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into
 *                shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current kernel stack usage on the given core in bytes.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_GetKernelStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_GetStartupHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current startup hook stack usage on the given core.
 *  \details      (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into
 *                shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current startup hook stack usage on the given core in bytes.
 *                E_OK             No Error.
 *                E_OS_ID          (EXTENDED status:) Passed Core ID is not a valid ID.
 *                E_OS_ID          (EXTENDED status:) CoreID is not a valid AUTOSAR core ID.
 *                E_OS_ID          (EXTENDED status:) The requested hook is not configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_GetStartupHookStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_GetErrorHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current error hook stack usage on the given core.
 *  \details      (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into
 *                shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current error hook stack usage on the given core in bytes.
 *                E_OK            No Error.
 *                E_OS_ID         (EXTENDED status:) Passed is not a valid ID.
 *                E_OS_ID         (EXTENDED status:) CoreID is not a valid AUTOSAR core ID.
 *                E_OS_ID         (EXTENDED status:) The requested hook is not configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_GetErrorHookStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_GetShutdownHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current shutdown hook stack usage on the given core.
 *  \details      (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into
 *                shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current shutdown hook stack usage on the given core in bytes.
 *                E_OK            No Error.
 *                E_OS_ID         (EXTENDED status:) Passed is not a valid ID.
 *                E_OS_ID         (EXTENDED status:) CoreID is not a valid AUTOSAR core ID.
 *                E_OS_ID         (EXTENDED status:) The requested hook is not configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_GetShutdownHookStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  Os_GetProtectionHookStackUsage()
 **********************************************************************************************************************/
/*! \brief        Get the current protection hook stack usage on the given core.
 *  \details      (EXTENDED status:) If the given object ID is invalid, the function reports an error and goes into
 *                shutdown.
 *
 *  \param[in]    CoreID         The core which shall be queried.
 *
 *  \return       Current protection hook stack usage on the given core in bytes.
 *                E_OK            No Error.
 *                E_OS_ID         (EXTENDED status:) Passed is not a valid ID.
 *                E_OS_ID         (EXTENDED status:) CoreID is not a valid AUTOSAR core ID.
 *                E_OS_ID         (EXTENDED status:) The requested hook is not configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_GetProtectionHookStackUsage
(
  CoreIdType CoreID
);


/***********************************************************************************************************************
 *  GetSpinlock()
 **********************************************************************************************************************/
/*! \brief        OS service GetSpinlock().
 *  \details      Allocates the requested spinlock for the caller. If it is already locked, the function performs
 *                active around until the spinlock becomes available again.
 *
 *  \param[in]    SpinlockId        The spinlock which shall be locked.
 *
 *  \return       E_OK              No error.
 *                E_OS_ID           (EXTENDED status:) Invalid SpinlockID.
 *                E_OS_INTERFERENCE_DEADLOCK (EXTENDED status:) Spinlock already occupied by a task/ISR
 *                                                              of the same core.
 *                E_OS_NESTING_DEADLOCK      (EXTENDED status:) Invalid Spinlock allocation order.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetSpinlock(SpinlockIdType SpinlockId);


/***********************************************************************************************************************
 *  ReleaseSpinlock()
 **********************************************************************************************************************/
/*! \brief        OS service ReleaseSpinlock().
 *  \details      ReleaseSpinlock releases a spinlock variable that was occupied before. Before terminating a task/ISR
 *                all spinlock variables that have been occupied with \ref GetSpinlock() shall be released.
 *                The error E_OS_CALLEVEL is already checked by E_OS_STATE. See \ref Os_SpinlockRelease() for details.
 *
 *  \param[in]    SpinlockId        The spinlock which shall be released.
 *
 *  \return       E_OK              No error.
 *                E_OS_ID           (EXTENDED status:) Invalid SpinlockID.
 *                E_OS_STATE        (EXTENDED status:) The caller is not the owner of the given spinlock.
 *                E_OS_NOFUNC       (EXTENDED status:) The caller tries to release a spinlock while another spinlock has
 *                                  to be released before.
 *                E_OS_RESOURCE     (EXTENDED status:) Spinlock and Resource API not used in LIFO order.
 *                E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient. This
 *                                  error may occur in combination with trusted functions.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) ReleaseSpinlock(SpinlockIdType SpinlockId);


/***********************************************************************************************************************
 *  TryToGetSpinlock()
 **********************************************************************************************************************/
/*! \brief        OS service TryToGetSpinlock().
 *  \details      Allocates the requested spinlock for the caller. If it is already locked, the function returns.
 *
 *  \param[in]    SpinlockId        The spinlock which shall be locked.
 *  \param[out]   Success           The result of the allocation attempt.
 *
 *  \return       E_OK              No error.
 *                E_OS_ID           (EXTENDED status:) Invalid SpinlockID.
 *                E_OS_INTERFERENCE_DEADLOCK (EXTENDED status:) Spinlock already occupied by a task/ISR
 *                                                              of the same core.
 *                E_OS_NESTING_DEADLOCK      (EXTENDED status:) Invalid Spinlock allocation order.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) TryToGetSpinlock
(
  SpinlockIdType SpinlockId,
  TryToGetSpinlockType* Success
);


/***********************************************************************************************************************
 *  DisableAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service DisableAllInterrupts()..
 *  \details      Disables category 1 and category 2 ISRs.
 *                If timing protection is configured, the timing protection interrupt is not affected.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Not already in DisableAllInterrupts() sequence.
 *
 *  \trace        SPEC-63921, SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_CODE) DisableAllInterrupts(void);


/***********************************************************************************************************************
 *  EnableAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service EnableAllInterrupts().
 *  \details      Restores the state saved by DisableAllInterrupts().
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: In DisableAllInterrupts() sequence.
 *
 *  \trace        SPEC-63921, SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_CODE) EnableAllInterrupts(void);


/***********************************************************************************************************************
 *  SuspendAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service SuspendAllInterrupts().
 *  \details      Saves the recognition status of all interrupts and disables all interrupts
 *                for which the hardware supports disabling. This API can be called nested.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Not in DisableAllInterrupts() sequence.
 *
 *  \trace        SPEC-63921, SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_CODE) SuspendAllInterrupts(void);


/***********************************************************************************************************************
 *  ResumeAllInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service ResumeAllInterrupts().
 *  \details      Restores the recognition status of all interrupts saved by the SuspendAllInterrupts() service.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: In SuspendAllInterrupts() sequence.
 *  \pre          Pre-Condition: Correct nesting sequence of suspend interrupt API.
 *
 *  \trace        SPEC-63921, SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_CODE) ResumeAllInterrupts(void);


/***********************************************************************************************************************
 *  SuspendOSInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service SuspendOSInterrupts().
 *  \details      Saves the recognition status of interrupts of category 2 and disables the recognition of
 *                these interrupts. This API can be called nested.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Not in DisableAllInterrupts() sequence.
 *
 *  \trace        SPEC-63921, SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_CODE) SuspendOSInterrupts(void);


/***********************************************************************************************************************
 *  ResumeOSInterrupts()
 **********************************************************************************************************************/
/*! \brief        OS service ResumeOSInterrupts().
 *  \details      Restores the recognition status of interrupts saved by the SuspendOSInterrupts() service.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|ALARMHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: In SuspendOSInterrupts() sequence.
 *  \pre          Pre-Condition: Correct nesting sequence of suspend interrupt API.
 *
 *  \trace        SPEC-63921, SPEC-63736
 **********************************************************************************************************************/
FUNC(void, OS_CODE) ResumeOSInterrupts(void);


/***********************************************************************************************************************
 *  Os_DisableLevelAM()
 **********************************************************************************************************************/
/*! \brief        OS service DisableLevelAM().
 *  \details      This function shall be used, if the caller's mode (user or kernel) is unknown at implementation time.
 *                Disables the recognition status of category 2 interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are enabled.
 *
 *  \trace        CREQ-108745
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_DisableLevelAM(void);


/***********************************************************************************************************************
 *  Os_DisableLevelKM()
 **********************************************************************************************************************/
/*! \brief        OS service DisableLevelKM().
 *  \details      This function shall be used, if the caller runs in kernel mode.
 *                Disables the recognition status of category 2 interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are enabled.
 *  \pre          Pre-Condition: Macro is called in kernel (privileged) mode.
 *
 *  \trace        CREQ-108744
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_DisableLevelKM(void);


/***********************************************************************************************************************
 *  Os_DisableLevelUM()
 **********************************************************************************************************************/
/*! \brief        OS service DisableLevelUM().
 *  \details      This function shall be used, if the caller runs in user mode.
 *                Disables the recognition status of category 2 interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are enabled.
 *
 *  \trace        CREQ-108743
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_DisableLevelUM(void);


/***********************************************************************************************************************
 *  Os_EnableLevelAM()
 **********************************************************************************************************************/
/*! \brief        OS service EnableLevelAM().
 *  \details      This function shall be used, if the caller's mode (user or kernel) is unknown at implementation time.
 *                Enables the recognition status of category 2 interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are disabled (by Os_DisableLevelAM/KM/UM).
 *
 *  \trace        CREQ-108746
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_EnableLevelAM(void);


/***********************************************************************************************************************
 *  Os_EnableLevelKM()
 **********************************************************************************************************************/
/*! \brief        OS service EnableLevelKM().
 *  \details      This function shall be used, if the caller runs in kernel mode.
 *                Enables the recognition status of category 2 interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are disabled (by Os_DisableLevelAM/KM/UM).
 *  \pre          Pre-Condition: Macro is called in kernel (privileged) mode.
 *
 *  \trace        CREQ-108747
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_EnableLevelKM(void);


/***********************************************************************************************************************
 *  Os_EnableLevelUM()
 **********************************************************************************************************************/
/*! \brief        OS service EnableLevelUM().
 *  \details      This function shall be used, if the caller runs in user mode.
 *                Enables the recognition status of category 2 interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are disabled (by Os_DisableLevelAM/KM/UM).
 *
 *  \trace        CREQ-108748
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_EnableLevelUM(void);


/***********************************************************************************************************************
 *  Os_DisableGlobalAM()
 **********************************************************************************************************************/
/*! \brief        OS service DisableGlobalAM().
 *  \details      This function shall be used, if the caller's mode (user or kernel) is unknown at implementation time.
 *                Disables the recognition status of all interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are enabled.
 *
 *  \trace        CREQ-108741
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_DisableGlobalAM(void);


/***********************************************************************************************************************
 *  Os_DisableGlobalKM()
 **********************************************************************************************************************/
/*! \brief        OS service DisableGlobalKM().
 *  \details      This function shall be used, if the caller runs in kernel mode.
 *                Disables the recognition status of all interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are enabled.
 *  \pre          Pre-Condition: Macro is called in kernel (privileged) mode.
 *
 *  \trace        CREQ-1257
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_DisableGlobalKM(void);


/***********************************************************************************************************************
 *  Os_DisableGlobalUM()
 **********************************************************************************************************************/
/*! \brief        OS service DisableGlobalUM().
 *  \details      This function shall be used, if the caller runs in user mode.
 *                Disables the recognition status of all interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are enabled.
 *
 *  \trace        CREQ-1256
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_DisableGlobalUM(void);


/***********************************************************************************************************************
 *  Os_EnableGlobalAM()
 **********************************************************************************************************************/
/*! \brief        OS service EnableGlobalAM().
 *  \details      This function shall be used, if the caller's mode (user or kernel) is unknown at implementation time.
 *                Enables the recognition status of all interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are disabled (by Os_DisableGlobalAM/KM/UM).
 *
 *  \trace        CREQ-108742
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_EnableGlobalAM(void);


/***********************************************************************************************************************
 *  Os_EnableGlobalKM()
 **********************************************************************************************************************/
/*! \brief        OS service EnableGlobalKM().
 *  \details      This function shall be used, if the caller runs in kernel mode.
 *                Enables the recognition status of all interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are disabled (by Os_DisableGlobalAM/KM/UM).
 *  \pre          Pre-Condition: Macro is called in kernel (privileged) mode.
 *
 *  \trace        CREQ-1259
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_EnableGlobalKM(void);


/***********************************************************************************************************************
 *  Os_EnableGlobalUM()
 **********************************************************************************************************************/
/*! \brief        OS service EnableGlobalUM().
 *  \details      This function shall be used, if the caller runs in user mode.
 *                Enables the recognition status of all interrupts. This service does not perform nesting
 *                nor service protection checks.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are disabled (by Os_DisableGlobalAM/KM/UM).
 *
 *  \trace        CREQ-1258
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_EnableGlobalUM(void);



/***********************************************************************************************************************
 *  Os_DisableInterruptSource()
 **********************************************************************************************************************/
/*! \brief          Disable the interrupt source of the given category 2 ISR.
 *  \details        API may be called with interrupts disabled or enabled.
 *                  MICROSAR OS disables the interrupt source by modifying the interrupt controller registers.
 *                  May be called for category 2 ISRs only.
 *                  Depending on target platform (e.g. ARM platforms), the ISR may still become active
 *                  although Os_DisableInterruptSource has returned E_OK.
 *                  This may be caused by hardware racing conditions e.g. when the interrupt is requested
 *                  immediately before the effect of Os_DisableInterruptSource becomes active.
 *
 *  \param[in]      ISRID   Category 2 ISR which shall be disabled.
 *
 *  \return       E_OK                No error.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_ID             (EXTENDED status:) ISRID is not a valid category 2 ISR identifier.
 *                E_OS_ACCESS         (Service Protection:)
 *                                      - The calling application is not the owner of the ISR passed in ISRID.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_DisableInterruptSource
(
  ISRType ISRID
);


/***********************************************************************************************************************
 *  Os_InitialEnableInterruptSources()
 **********************************************************************************************************************/
/*! \brief        Enable the interrupt sources of category 2 ISR on the current core.
 *  \details      API may be called with interrupts disabled or enabled.
 *                MICROSAR OS enables the interrupt sources by modifying the interrupt controller registers.
 *                Additionally it may clear the interrupt pending flags.
 *                This function may only be called from trusted task.
 *
 *  \note         Future versions of the OS will support the possibility to configure per ISR whether or not it shall
 *                be enabled by means of this function. Currently all cat2 user ISRs on the calling core are enabled
 *                if this function is called. OS ISRs are always excluded from the enabling as the OS handles the
 *                enabling internally.
 *
 *  \param[in]    ClearPending  Defines whether the pending flag of the ISRs shall be cleared (TRUE) or not (FALSE).
 *
 *  \return       E_OK                                                     No error.
 *                E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (EXTENDED status:)  Hardware does not support to clear
 *                                                                         pending interrupts.
 *                E_OS_CALLEVEL                        (EXTENDED status:)  Called from invalid context.
 *                E_OS_VALUE                           (EXTENDED status:)  ClearPending is neither TRUE nor FALSE.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_InitialEnableInterruptSources
(
  boolean           ClearPending
);


/***********************************************************************************************************************
 *  Os_EnableInterruptSource()
 **********************************************************************************************************************/
/*! \brief          Enable the interrupt source of the given category 2 ISR.
 *  \details        API may be called with interrupts disabled or enabled.
 *                  MICROSAR OS enables the interrupt source by modifying the interrupt controller registers.
 *                  Additionally it may clear the interrupt pending flag
 *                  May be called for category 2 ISRs only
 *
 *  \param[in]      ISRID         Category 2 ISR which shall be enabled.
 *  \param[in]      ClearPending  Defines whether the pending flag shall be cleared (TRUE) or not (FALSE).
 *
 *  \return  E_OK                No error.
 *           E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (EXTENDED status:)  Hardware does not support to clear
 *                                                                    pending interrupts.
 *           E_OS_CALLEVEL                        (EXTENDED status:)  Called from invalid context.
 *           E_OS_ID                              (EXTENDED status:)  ISRID is not a valid category 2 ISR identifier ID.
 *           E_OS_VALUE                           (EXTENDED status:)  ClearPending is neither TRUE nor FALSE.
 *           E_OS_ACCESS     (Service Protection:)  The calling application is not the owner of the ISR passed in ISRID.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_EnableInterruptSource
(
  ISRType ISRID,
  boolean ClearPending
);


/***********************************************************************************************************************
 *  Os_ClearPendingInterrupt()
 **********************************************************************************************************************/
/*! \brief          Clear the pending flag of the given category 2 ISR.
 *  \details        API may be called with interrupts disabled or enabled.
 *                  MICROSAR OS clears the interrupt pending flag by modifying the interrupt controller registers.
 *                  May be called for category 2 ISRs only
 *                  In order to minimize the risk of spurious interrupts, Os_ClearPendingInterrupt shall be
 *                  called only after the ISR (IsrId) has been disabled and before it is enabled again.
 *
 *                  The API service tries to clear the pending flag only. The interrupt cause has to be reset
 *                  by the application software. Otherwise the flag may be set again immediately after it
 *                  has been cleared by the API. This may be the case e.g. with level triggered ISRs.
 *
 *  \param[in]      ISRID   Category 2 ISR that's pending flag shall be cleared.
 *
 *  \return  E_OK                No error.
 *           E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (EXTENDED status:)  Hardware does not support to clear
 *                                                                    pending interrupts.
 *           E_OS_CALLEVEL                        (EXTENDED status:)  Called from invalid context.
 *           E_OS_ID                              (EXTENDED status:)  ISRID is not a valid category 2 ISR identifier ID.
 *           E_OS_ACCESS     (Service Protection:)  The calling application is not the owner of the ISR passed in ISRID.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_ClearPendingInterrupt
(
  ISRType ISRID
);


/***********************************************************************************************************************
 *  Os_IsInterruptSourceEnabled()
 **********************************************************************************************************************/
/*! \brief          Check if the given interrupt source is enabled.
 *  \details        API may be called with interrupts disabled or enabled.
 *                  MICROSAR OS checks if the interrupt source is enabled reading the interrupt controller registers and
 *                  update the boolean addressed by IsEnabled accordingly
 *                  May be called for category 2 ISRs only
 *
 *  \param[in]      ISRID         Category 2 ISR which shall be checked.
 *  \param[out]     IsEnabled     Pointer to the boolean value: TRUE(enabled), FALSE(not enabled)
 *
 *  \return       E_OK                                                      No error.
 *                E_OS_CALLEVEL                       (EXTENDED status:)    Called from invalid context.
 *                E_OS_ID                             (EXTENDED status:)    Invalid ISRID.
 *                E_OS_PARAM_POINTER                  (EXTENDED status:)    Given pointer parameter (IsEnabled) is NULL.
 *                E_OS_ACCESS                         (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_IsInterruptSourceEnabled
(
  ISRType ISRID,
  P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsEnabled
);


/***********************************************************************************************************************
 *  Os_IsInterruptPending()
 **********************************************************************************************************************/
/*! \brief         Check if the given ISR has been requested.
 *  \details       API may be called with interrupts disabled or enabled.
 *                 MICROSAR OS checks if the ISR has been already requested,  reading the interrupt controller registers
 *                 and update the boolean addressed by IsPending accordingly
 *                 May be called for category 2 ISRs only
 *
 *  \param[in]      ISRID         Category 2 ISR which shall be checked.
 *  \param[out]     IsPending     Pointer to the boolean value: TRUE(pending), FALSE(not pending)
 *
 *  \return       E_OK                                                      No error.
 *                E_OS_SYS_UNIMPLEMENTED_FUNCTIONALITY (EXTENDED status:)   Hardware does not support to clear
 *                                                                          pending interrupts.
 *                E_OS_CALLEVEL                       (EXTENDED status:)    Called from invalid context.
 *                E_OS_ID                             (EXTENDED status:)    Invalid ISRID.
 *                E_OS_PARAM_POINTER                  (EXTENDED status:)    Given pointer parameter (IsEnabled) is NULL.
 *                E_OS_ACCESS                         (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_IsInterruptPending
(
  ISRType ISRID,
  P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT) IsPending
);


/***********************************************************************************************************************
 *  Os_BarrierSynchronize()
 **********************************************************************************************************************/
/*! \brief        Synchronize tasks at the given barrier.
 *  \details      The calling Task will be blocked here until the required number of participating tasks have also
 *                called Os_BarrierSynchronize(). The operating system checks that the Task is allowed to
 *                participate in the given barrier.
 *
 *  \param[in]    BarrierID         The barrier to which task shall be synchronized.
 *
 *  \return       E_OK                              No error.
 *                E_OS_ID                           (EXTENDED status:) Invalid BarrierID.
 *                E_OS_CALLEVEL                     (EXTENDED status:) Called from invalid context.
 *                E_OS_SYS_NO_BARRIER_PARTICIPANT   (EXTENDED status:) The given barrier is not configured for
 *                                                                     the local core.
 *                                                  (EXTENDED status:) Task is not configured to participate
 *                                                                     the barrier.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_BarrierSynchronize
(
  Os_BarrierIdType BarrierID
);


/***********************************************************************************************************************
 *  ActivateTask()
 **********************************************************************************************************************/
/*! \brief        OS service ActivateTask().
 *  \details      The task TaskID is transferred from the SUSPENDED state into the READY state.
 *                The operating system ensures that the task code is being executed from the first statement.
 *
 *  \param[in]    TaskID            The task which shall be activated.
 *
 *  \return       E_OK              No error.
 *                E_OS_LIMIT        Too many task activations.
 *                E_OS_ID           (EXTENDED status:) Invalid TaskID.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                                    - Given task's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given TaskID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) ActivateTask
(
  TaskType TaskID
);


/***********************************************************************************************************************
 *  TerminateTask()
 **********************************************************************************************************************/
/*! \brief        OS service TerminateTask().
 *  \details      This service causes the termination of the calling task.
 *                The calling task is transferred from the RUNNING state into the SUSPENDED state.
 *                This service only returns in case it detects an error.
 *
 *  \return       E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_RESOURCE     (EXTENDED status:) Task still occupies resources.
 *                E_OS_SPINLOCK     (EXTENDED status:) Task still holds spinlocks.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) TerminateTask
(
    void
);


/***********************************************************************************************************************
 *  ChainTask()
 **********************************************************************************************************************/
/*! \brief        OS service ChainTask().
 *  \details      After termination of the calling task the given task is activated.
 *                This service only returns in case it detects an error.
 *
 *  \param[in]    TaskID            The task which shall be activated.
 *
 *  \return       E_OS_LIMIT        Too many task activations.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_RESOURCE     (EXTENDED status:) Task still occupies resources.
 *                E_OS_SPINLOCK     (EXTENDED status:) Task still holds spinlocks.
 *                E_OS_ID           (EXTENDED status:) Invalid TaskID.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                                    - Given task's owner application is not accessible.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given TaskID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) ChainTask
(
  TaskType TaskID
);


/***********************************************************************************************************************
 *  Schedule()
 **********************************************************************************************************************/
/*! \brief      OS service Schedule().
 *  \details
 *  If a higher-priority task is ready, the internal resource of the task is released, the current task is put into
 *  the ready state, its context is saved and the higher-priority task is executed. Otherwise the calling task is
 *  continued.
 *
 *  Rescheduling only takes place if an internal resource is assigned to the calling task during system generation.
 *  (non-preemptive tasks are seen as tasks with an internal resource of highest task priority assigned.) For these
 *  tasks, Schedule() enables a processor assignment to other tasks with lower or equal priority than the ceiling
 *  priority of the internal resource and  higher priority than the priority of the calling task in
 *  application-specific locations. When returning from Schedule, the internal resource has been taken again.
 *  This service has no influence on tasks with no internal resource assigned (preemptive tasks).
 *
 *  \return       E_OK              No Error.
 *                E_OS_CALLEVEL     (EXTENDED status:) The service was called from any context which is not allowed.
 *                E_OS_RESOURCE     (EXTENDED status:) The service was called from a task which holds an OS resource.
 *                E_OS_SPINLOCK     (EXTENDED status:) The service was called from a task which holds a spinlock.
 *                E_OS_DISABLEDINT  (Service Protection:) The service was called with disabled interrupts.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Interrupts are enabled.
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Schedule(void);


/***********************************************************************************************************************
 *  GetTaskID()
 **********************************************************************************************************************/
/*! \brief        OS service GetTaskID().
 *  \details      Returns the ID of the task which is currently RUNNING on the local core.
 *
 *  \param[out]   TaskID              The current task ID.
 *
 *  \return       E_OK                No error.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-64000
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetTaskID(TaskRefType TaskID);


/***********************************************************************************************************************
 *  GetTaskState()
 **********************************************************************************************************************/
/*! \brief        OS service GetTaskState().
 *  \details      Returns the current scheduling state of a task (RUNNING, READY, ...).
 *
 *  \param[in]    TaskID          The task to be queried.
 *  \param[out]   State           The task's state.
 *
 *  \return       E_OK                No error.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_ID             (EXTENDED status:) Invalid TaskID.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS         (Service Protection:)
 *                                      - Caller's access rights are not sufficient.
 *                                      - Given task's owner application is not accessible.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: The given task has to be assigned to the current core.
 *
 *  \trace        SPEC-64000
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetTaskState(TaskType TaskID, TaskStateRefType State);


/***********************************************************************************************************************
 *  GetISRID()
 **********************************************************************************************************************/
/*! \brief        OS service GetISRID().
 *  \details      Return the identifier of the currently executing ISR.
 *
 *  \return       Identifier of running ISR
 *                INVALID_ISR    If called from
 *                                - invalid call-context,
 *                                - from a task or
 *                                - a hook which was called inside a task context.
 *
 *  \context      TASK|ISR2|ERRHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(ISRType, OS_CODE) GetISRID(void);


/***********************************************************************************************************************
 *  SetEvent()
 **********************************************************************************************************************/
/*! \brief        OS service SetEvent().
 *  \details      The events of the given task are set according to the given event mask.
 *
 *  \param[in]    TaskID          The task which shall be modified.
 *  \param[in]    Mask            The events which shall be set.
 *
 *  \return       E_OK                No error.
 *                E_OS_ID             (EXTENDED status:) Invalid TaskID.
 *                E_OS_ACCESS         (EXTENDED status:)
 *                                      - Task is no extended task.
 *                                    (Service Protection:)
 *                                      - Task's owner application is not accessible.
 *                                      - Caller's access rights are not sufficient.
 *                E_OS_STATE          (EXTENDED status:) Events can not be set as the referenced task is in the
 *                                    SUSPENDED state.
 *                E_OS_CALLEVEL       (Service Protection:) Called from invalid context.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) SetEvent
(
  TaskType TaskID,
  EventMaskType Mask
);



/***********************************************************************************************************************
 *  ClearEvent()
 **********************************************************************************************************************/
/*! \brief        OS service ClearEvent().
 *  \details      The events of the calling task are cleared according to the given event mask.
 *
 *  \param[in]    Mask                The events which shall be set.
 *
 *  \return       E_OK                No error.
 *                E_OS_ACCESS         (EXTENDED status:) Task is no extended task.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) ClearEvent
(
  EventMaskType Mask
);


/***********************************************************************************************************************
 *  GetEvent()
 **********************************************************************************************************************/
/*! \brief        OS service GetEvent().
 *  \details      This service returns the state of all event bits of the given task, not the events that the task is
 *                waiting for.
 *
 *  The current status of the event mask of task TaskID is copied to Event.
 *
 *  \param[in]    TaskID          The task which shall be queried.
 *  \param[out]   Mask            Events which are set.
 *
 *  \return       E_OK                No error.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *                E_OS_ID             (EXTENDED status:) Invalid TaskID.
 *                E_OS_ACCESS         (EXTENDED status:)
 *                                      - Task is no extended task.
 *                                    (Service Protection:)
 *                                      - Task's owner application is not accessible.
 *                                      - Caller's access rights are not sufficient.
 *                E_OS_STATE          (EXTENDED status:) Referenced task is in SUSPENDED state.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Task is assigned to the current core.
 *
 *  \trace        SPEC-64000
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetEvent
(
  TaskType TaskID,
  EventMaskRefType Mask
);


/***********************************************************************************************************************
 *  WaitEvent()
 **********************************************************************************************************************/
/*! \brief        OS service WaitEvent().
 *  \details      The state of the current task is set to WAITING, unless at least one of the given events is set.
 *
 *  This call enforces rescheduling, if the wait condition occurs. If rescheduling takes place, the internal resource
 *  of the task is released while the task is in the WAITING state.
 *
 *  This service shall only be called from the extended task owning the event.
 *
 *  \param[in]    Mask  Mask of the events waited for.
 *
 *  \return       E_OK              No error.
 *                E_OS_ACCESS       (EXTENDED status:) Task is no extended task.
 *                E_OS_RESOURCE     (EXTENDED status:) Task still occupies resources.
 *                E_OS_SPINLOCK     (EXTENDED status:) Task still holds spinlocks.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) WaitEvent
(
  EventMaskType Mask
);


/***********************************************************************************************************************
 *  IncrementCounter()
 **********************************************************************************************************************/
/*! \brief      OS service IncrementCounter().
 *  \details
 *  This service increments a software counter.
 *
 *  \param[in]    CounterID           The counter to be incremented.
 *
 *  \return       E_OK                No Error.
 *                E_OS_ID             (EXTENDED status:) CounterID is not a valid software counter ID.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_CORE           (EXTENDED status:) The given object belongs to a foreign core.
 *                E_OS_ACCESS         (Service Protection:)
 *                                      - Caller's access rights are not sufficient.
 *                                      - Given counter's owner application is not accessible.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) IncrementCounter
(
  CounterType CounterID
);


/***********************************************************************************************************************
 *  GetCounterValue()
 **********************************************************************************************************************/
/*! \brief      OS service GetCounterValue().
 *  \details
 *  This service reads the current count value of a counter (returning either the hardware timer ticks if counter
 *  is driven by hardware or the software ticks when user drives counter).
 *
 *  Even if this API is a getter function, we may have to perform a system call, because we may need
 *  peripheral (read) access.
 *
 *  \param[in]    CounterID   The counter to be read.
 *  \param[out]   Value       Contains the current tick value of the counter.
 *
 *  \return       E_OK                No Error.
 *                E_OS_ID             (EXTENDED status:) Invalid CounterID.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *                E_OS_ACCESS         (Service Protection:)
 *                                      - Counter's owner application is not accessible.
 *                                      - Caller's access rights are not sufficient.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-64000
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetCounterValue
(
  CounterType CounterID,
  TickRefType Value
);


/***********************************************************************************************************************
 *  GetElapsedValue()
 **********************************************************************************************************************/
/*! \brief      OS service GetElapsedValue().
 *  \details
 *  This service gets the number of ticks between the current tick value and a previously read tick value.
 *
 *  Even if this API is a getter function, we may have to perform a system call,
 *  because we may need peripheral (read) access.
 *
 *  \param[in]      CounterID     The counter to be read.
 *  \param[in,out]  Value         **in:** The previously read tick value of the counter.<BR>
 *                                **out:** The current tick value of the counter.
 *  \param[out]     ElapsedValue  The difference to the previous read value.
 *
 *  \return       E_OK                No Error.
 *                E_OS_ID             (EXTENDED status:) Invalid CounterID.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_VALUE          (EXTENDED status:) The given Value was not valid.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *                E_OS_ACCESS         (Service Protection:)
 *                                      - Counter's owner application is not accessible.
 *                                      - Caller's access rights are not sufficient.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-64000
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetElapsedValue
(
  CounterType CounterID,
  TickRefType Value,
  TickRefType ElapsedValue
);


/***********************************************************************************************************************
 *  GetAlarmBase()
 **********************************************************************************************************************/
/*! \brief        OS service GetAlarmBase().
 *  \details      The system service GetAlarmBase reads the alarm base characteristics. The return value
 *                Info is a structure in which the information of data type AlarmBaseType is stored.
 *
 *  \param[in]    AlarmID             Reference to the alarm element.
 *  \param[out]   Info                Contains information about the counter on successful return.
 *
 *  \return       E_OK                No error.
 *                E_OS_ID             (EXTENDED status:) Invalid AlarmID.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS         (Service Protection:)
 *                                      - Caller's access rights are not sufficient.
 *                                      - Given task's owner application is not accessible.
 *
 *  \context      TASK|ISR2|PRETHOOK|POSTTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given object pointer(s) are valid.
 *
 *  \trace        SPEC-64000
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetAlarmBase
(
  AlarmType AlarmID,
  AlarmBaseRefType Info
);


/***********************************************************************************************************************
 *  GetAlarm()
 **********************************************************************************************************************/
/*! \brief        OS service GetAlarm().
 *  \details      It is up to the application to decide whether for example a CancelAlarm may still be
 *                useful. If AlarmID is not in use, Tick is not defined. Allowed on task level, ISR,
 *                and in several hook routines.
 *
 *  \param[in]    AlarmID             Reference to the alarm element.
 *  \param[out]   Tick                Relative value in ticks before the alarm expires.
 *
 *  \return       E_OK                No error.
 *                E_OS_NOFUNC         Alarm is not in use.
 *                E_OS_ID             (EXTENDED status:) Invalid AlarmID.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS         (Service Protection:)
 *                                      - Caller's access rights are not sufficient.
 *                                      - Given task's owner application is not accessible.
 *
 *  \context      TASK|ISR2|PRETHOOK|POSTTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given alarm is assigned to the local core.
 *
 *  \trace        SPEC-64000
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetAlarm
(
  AlarmType AlarmID,
  TickRefType Tick
);


/***********************************************************************************************************************
 *  SetRelAlarm()
 **********************************************************************************************************************/
/*! \brief        OS service SetRelAlarm().
 * \details       The system service occupies the alarm AlarmID element. After increment ticks have elapsed,
 *                the task assigned to the alarm AlarmID is activated or the assigned event (only for
 *                extended tasks) is set or the alarm-callback routine is called.
 *
 *  \param[in]    AlarmID           Reference to the alarm element.
 *  \param[in]    Increment         Relative value in ticks.
 *  \param[in]    Cycle             Cycle value in case of cyclic alarm. In case of single alarms, cycle shall be zero.
 *
 *  \return       E_OK              No error.
 *                E_OS_STATE        Alarm is already in use.
 *                E_OS_ID           (EXTENDED status:) Invalid AlarmID.
 *                E_OS_VALUE        Returned if:
 *                                    - Value of increment is zero
 *                                    - (EXTENDED status:)  Value of Increment outside of the admissible limits
 *                                      (lower than zero or greater than maxallowedvalue).
 *                                    - (EXTENDED status:) Value of Cycle unequal to 0 and outside of the admissible
 *                                      counter limits (less than mincycle or greater than maxallowedvalue).
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                                    - Given alarm's owner application is not accessible.
 *                other             See Os_XSigSend_SetRelAlarm() and Os_XSigRecv_SetRelAlarm().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given AlarmID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) SetRelAlarm
(
  AlarmType AlarmID,
  TickType Increment,
  TickType Cycle
);


/***********************************************************************************************************************
 *  SetAbsAlarm()
 **********************************************************************************************************************/
/*! \brief        OS service SetAbsAlarm().
 *  \details      The system service occupies the alarm AlarmID element. When start ticks are reached,
 *                the task assigned to the alarm AlarmID is activated or the assigned event (only for extended tasks)
 *                is set or the alarm-callback routine is called.
 *
 *  \param[in]    AlarmID           Reference to the alarm element.
 *  \param[in]    Start             Absolute value in ticks.
 *  \param[in]    Cycle             Cycle value in case of cyclic alarm. In case of single alarms, cycle shall be zero.
 *
 *  \return       E_OK              No error.
 *                E_OS_STATE        Alarm is already in use.
 *                E_OS_ID           (EXTENDED status:) Invalid AlarmID.
 *                E_OS_VALUE        (EXTENDED status:) Returned if:
 *                                    - Value of Start outside of the admissible counter limit (less than zero or
 *                                      greater than maxallowedvalue).
 *                                    - Value of Cycle unequal to 0 and outside of the admissible counter limits
 *                                      (less than mincycle or greater than maxallowedvalue).
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                                    - Given alarm's owner application is not accessible.
 *                other             See Os_XSigSend_SetAbsAlarm() and Os_XSigRecv_SetAbsAlarm().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given AlarmID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) SetAbsAlarm
(
  AlarmType AlarmID,
  TickType Start,
  TickType Cycle
);


/***********************************************************************************************************************
 *  CancelAlarm()
 **********************************************************************************************************************/
/*! \brief        OS service CancelAlarm().
 *  \details      The system service cancels the alarm AlarmID.
 *
 *  \param[in]    AlarmID           Reference to the alarm element.
 *
 *  \return       E_OK              No error.
 *                E_OS_NOFUNC       Alarm is not in use.
 *                E_OS_ID           (EXTENDED status:) Invalid AlarmID.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                                    - Given alarm's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given AlarmID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) CancelAlarm
(
  AlarmType AlarmID
);


/***********************************************************************************************************************
 *  GetResource()
 **********************************************************************************************************************/
/*! \brief        OS service GetResource().
 *  \details      This API serves to enter critical sections in the code.
 *                A critical section shall always be left using ReleaseResource().
 *
 *  \param[in]    ResID            The resource which shall be occupied.
 *
 *  \return       E_OK              No error.
 *                E_OS_ID           (EXTENDED status:) Invalid ResID.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_CORE         (EXTENDED status:) The given object belongs to a foreign core.
 *                E_OS_ACCESS       (EXTENDED status:)
 *                                    - Statically assigned priority of the caller is higher than the
 *                                      calculated ceiling priority.
 *                                    - Attempt to get a resource which is already occupied.
 *                                  (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetResource
(
  ResourceType ResID
);


/***********************************************************************************************************************
 *  ReleaseResource()
 **********************************************************************************************************************/
/*! \brief        OS service ReleaseResource().
 *  \details      This API is the counterpart of GetResource() and serves to leave critical sections in the code.
 *
 *  \param[in]    ResID            The resource which shall be released.
 *
 *  \return       E_OK              No error.
 *                E_OS_ID           (EXTENDED status:) Invalid ResID.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_CORE         (EXTENDED status:) The given object belongs to a foreign core.
 *                E_OS_NOFUNC       (EXTENDED status:)
 *                                    - Attempt to release a resource which has not been occupied by the caller before.
 *                                    - Attempt to release a nested resource in wrong order.
 *                E_OS_SPINLOCK     (EXTENDED status:) Spinlock and Resource API not used in LIFO order.
 *                E_OS_ACCESS       (EXTENDED status:)
 *                                    - Attempt to release a resource which has a lower ceiling priority than the
 *                                      statically assigned priority of the caller.
 *                                  (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) ReleaseResource
(
  ResourceType ResID
);


/***********************************************************************************************************************
 *  StartScheduleTableRel()
 **********************************************************************************************************************/
/*! \brief        OS service StartScheduleTableRel().
 *  \details      The schedule table is started at a relative offset to the current time.
 *
 *  \param[in]    ScheduleTableID   The ID of the schedule table to be started.
 *  \param[in]    Offset            The relative offset when the schedule table shall be started.
 *
 *  \return       E_OK              No error.
 *                E_OS_STATE        Schedule table has already been started.
 *                E_OS_ID           (EXTENDED status:) Invalid ScheduleTableID.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_VALUE        (EXTENDED status:) Offset is bigger than (OsCounterMaxAllowedValue - InitialOffset)
 *                                                     or is equal to zero
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                                    - Given schedule table's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) StartScheduleTableRel
(
  ScheduleTableType ScheduleTableID,
  TickType Offset
);


/***********************************************************************************************************************
 *  StartScheduleTableAbs()
 **********************************************************************************************************************/
/*! \brief        OS service StartScheduleTableAbs().
 *  \details      The schedule table is started at an absolute time.
 *
 *  \param[in]    ScheduleTableID   The ID of the schedule table to be started
 *  \param[in]    Start             The absolute time when the schedule table shall be started
 *
 *  \return       E_OK              No error.
 *                E_OS_STATE        Schedule table has already been started.
 *                E_OS_ID           (EXTENDED status:) Invalid ScheduleTableID.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_VALUE        (EXTENDED status:) Offset is bigger than OsCounterMaxAllowedValue
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                                    - Given schedule table's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) StartScheduleTableAbs
(
  ScheduleTableType ScheduleTableID,
  TickType Start
);


/***********************************************************************************************************************
 *  StopScheduleTable()
 **********************************************************************************************************************/
/*! \brief        OS service StopScheduleTable().
 *  \details      The schedule table is stopped immediately.
 *
 *  \param[in]    ScheduleTableID   The ID of the schedule table to be stopped.
 *
 *  \return       E_OK              No error.
 *                E_OS_NOFUNC       Schedule table has already been stopped.
 *                E_OS_ID           (EXTENDED status:) Invalid ScheduleTableID.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Caller's access rights are not sufficient.
 *                                    - Given schedule table's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) StopScheduleTable
(
  ScheduleTableType ScheduleTableID
);


/***********************************************************************************************************************
 *  NextScheduleTable()
 **********************************************************************************************************************/
/*! \brief        OS service NextScheduleTable().
 *  \details      Requests the switch of schedule table processing from one schedule table to another after the first
 *                one has reached its end.
 *
 *  \param[in]    ScheduleTableID_From The ID of the schedule table which is requested to stop at its end
 *  \param[in]    ScheduleTableID_To   The ID of the schedule table which starts after the other one has stopped
 *
 *  \return       E_OK                 No error.
 *                E_OS_NOFUNC          Schedule table ScheduleTableID_From has not been started.
 *                E_OS_STATE           Schedule table ScheduleTableID_To has already been requested to start at the end
 *                                     of another schedule table.
 *                E_OS_ID              (EXTENDED status:) Invalid ScheduleTableID_From/To.
 *                E_OS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS          (Service Protection:)
 *                                       - Caller's access rights are not sufficient.
 *                                       - Given schedule table's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) NextScheduleTable
(
  ScheduleTableType ScheduleTableID_From,
  ScheduleTableType ScheduleTableID_To
);


/***********************************************************************************************************************
 *  GetScheduleTableStatus()
 **********************************************************************************************************************/
/*! \brief        OS service GetScheduleTableStatus().
 *  \details      This service queries the state of a schedule table (also with respect to synchronization).
 *
 *  \param[in]    ScheduleTableID      The ID of the schedule table for which the status shall be requested.
 *  \param[out]   ScheduleStatus       Reference to ScheduleTableStatusType.
 *
 *  \return       E_OK                  No error.
 *                E_OS_ID               (EXTENDED status:) Invalid ScheduleTableID
 *                E_OS_CALLEVEL         (EXTENDED status:) Called from invalid context.
 *                E_OS_PARAM_POINTER    (EXTENDED status:) ScheduleStatus is a pointer to null.
 *                E_OS_DISABLEDINT      (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS           (Service Protection:)
 *                                        - Caller's access rights are not sufficient.
 *                                        - Given schedule table's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-64000
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetScheduleTableStatus
(
  ScheduleTableType ScheduleTableID,
  ScheduleTableStatusRefType ScheduleStatus
);


/***********************************************************************************************************************
 *  StartScheduleTableSynchron()
 **********************************************************************************************************************/
/*! \brief        OS service StartScheduleTableSynchron().
 *  \details      This service starts an explicitly synchronized schedule table synchronously. As a result the schedule
 *                table enters the state SCHEDULETABLE_WAITING and waits for a synchronization count to be provided.
 *
 *  \param[in]    ScheduleTableID      The ID of the schedule table which shall start synchronously
 *
 *  \return       E_OK                 No error.
 *                E_OS_STATE           Schedule table ScheduleTableID has already been started.
 *                E_OS_ID              (EXTENDED status:) Invalid ScheduleTableID.
 *                E_OS_CORE            (EXTENDED status:) The given object belongs to a foreign core.
 *                E_OS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS          (Service Protection:)
 *                                       - Caller's access rights are not sufficient.
 *                                       - Given schedule table's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) StartScheduleTableSynchron
(
  ScheduleTableType ScheduleTableID
);


/***********************************************************************************************************************
 *  SyncScheduleTable()
 **********************************************************************************************************************/
/*! \brief        OS service SyncScheduleTable().
 *  \details      This service provides the schedule table with a synchronization count and starts the synchronization.
 *
 *  \param[in]    ScheduleTableID      The ID of the schedule table to the synchronized
 *  \param[in]    Value                The current value of the synchronization counter
 *
 *  \return       E_OK                 No error.
 *                E_OS_STATE           The state of the schedule table ScheduleTableId is equal to
 *                                     SCHEDULETABLE_STOPPED or SCHEDULETABLE_NEXT.
 *                E_OS_ID              (EXTENDED status:) Invalid ScheduleTableID.
 *                E_OS_CORE            (EXTENDED status:) The given object belongs to a foreign core.
 *                E_OS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *                E_OS_VALUE           (EXTENDED status:) The Value is out of range
 *                E_OS_ACCESS          (Service Protection:)
 *                                       - Caller's access rights are not sufficient.
 *                                       - Given schedule table's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) SyncScheduleTable
(
  ScheduleTableType ScheduleTableID,
  TickType Value
);


/***********************************************************************************************************************
 *  SetScheduleTableAsync()
 **********************************************************************************************************************/
/*! \brief        OS service SetScheduleTableAsync().
 *  \details      This service stops the synchronization of a schedule table.
 *
 *  \param[in]    ScheduleTableID      The ID of the schedule table which shall no longer be synchronized.
 *
 *  \return       E_OK                 No error.
 *                E_OS_STATE           Current state of ScheduleTableID is SCHEDULETABLE_STOPPED,
 *                                     SCHEDULETABLE_NEXT or SCHEDULETABLE_WAITING.
 *                E_OS_ID              (EXTENDED status:)
 *                                       - Invalid ScheduleTableID.
 *                                       - OsScheduleTblSyncStrategy of ScheduleTableID is not equal to EXPLICIT
 *                E_OS_CORE            (EXTENDED status:) The given object belongs to a foreign core.
 *                E_OS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *                E_OS_ACCESS          (Service Protection:)
 *                                       - Caller's access rights are not sufficient.
 *                                       - Given schedule table's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) SetScheduleTableAsync
(
  ScheduleTableType ScheduleTableID
);


/***********************************************************************************************************************
 *  GetApplicationID()
 **********************************************************************************************************************/
/*! \brief        OS service GetApplicationID().
 *  \details      This service determines the OS-Application where the caller (Task/ISR/Hook) originally belongs to
 *                (was configured to).
 *                All system objects (e.g. system hooks, idle task, ...) belong to kernel applications.
 *                Kernel applications are regular applications and have valid identifiers.
 *                Therefore INVALID_OSAPPLICATION is never returned because there is always a valid application active.
 *
 *  \return       Identifier of the OS-Application.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(ApplicationType, OS_CODE) GetApplicationID
(
  void
);


/***********************************************************************************************************************
 *  GetCurrentApplicationID()
 **********************************************************************************************************************/
/*! \brief        OS service GetCurrentApplicationID().
 *  \details      This service determines the OS-Application where the caller (Task/ISR/Hook) of the service is
 *                currently executing.
 *                Note that, if the caller is not within a CallTrustedFunction() call, the value is equal to the result
 *                of GetApplicationID().
 *
 *  \return       Identifier of the OS-Application.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-60
 *  \trace        SPEC-63543, SPEC-63545, SPEC-63555, SPEC-63557, SPEC-63921
 **********************************************************************************************************************/
FUNC(ApplicationType, OS_CODE) GetCurrentApplicationID
(
  void
);


/***********************************************************************************************************************
 *  GetApplicationState()
 **********************************************************************************************************************/
/*! \brief        OS service GetApplicationState().
 *  \details      This service returns the current state of an OS-Application.
 *
 *  \param[in]    Application   The OS-Application from which the state is requested.
 *  \param[out]   Value         The current state of the application.
 *
 *  \return       E_OK                No error.
 *                E_OS_ID             (EXTENDED status:) Invalid Application.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|STARTHOOK|SHUTHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-64000
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) GetApplicationState
(
  ApplicationType Application,
  ApplicationStateRefType Value
);


/***********************************************************************************************************************
 *  CheckObjectAccess()
 **********************************************************************************************************************/
/*! \brief        OS service CheckObjectAccess().
 *  \details      This service determines if the OS-Application, given by ApplID, is allowed to use the IDs
 *                of a Task, Resource, Counter, Alarm or Schedule Table in API calls.
 *
 *                Design decision: The following checks are not performed because there is no status type returned
 *                and the API does not evaluate dynamic runtime data.
 *                  - E_OS_CALLEVEL
 *                  - E_OS_DISABLEDINT
 *
 *  \param[in]    ApplID      OS-Application identifier.
 *  \param[in]    ObjectType  Type of the following parameter.
 *  \param[in]    ObjectID    The object to be examined.
 *
 *  \return       ACCESS      if the ApplID has access to the object.
 *                NO_ACCESS   If:
 *                              - ApplID doesn't have access to the object.
 *                              - ApplID is invalid.
 *                              - ObjectID is invalid.
 *
 *  \context      TASK|ISR2|ERRHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(ObjectAccessType, OS_CODE) CheckObjectAccess
(
  ApplicationType ApplID,
  ObjectTypeType ObjectType,
  Os_ObjectIdType ObjectID
);


/***********************************************************************************************************************
 *  CheckObjectOwnership()
 **********************************************************************************************************************/
/*! \brief        OS service CheckObjectOwnership().
 *  \details      This service determines to which OS-Application a given Task, ISR, Counter, Alarm or Schedule Table
 *                belongs.
 *
 *                Design decision: The following checks are not performed because there is no status type returned
 *                and the API does not evaluate dynamic runtime data.
 *                  - E_OS_CALLEVEL
 *                  - E_OS_DISABLEDINT
 *
 *  \param[in]    ObjectType  Type of the following parameter.
 *  \param[in]    ObjectID    The object to be examined.
 *
 *  \return       Identifier of the owner OS-Application.
 *                INVALID_OSAPPLICATION if the object does not exist.
 *
 *  \context      TASK|ISR2|ERRHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(ApplicationType, OS_CODE) CheckObjectOwnership
(
  ObjectTypeType ObjectType,
  Os_ObjectIdType ObjectID
);


/***********************************************************************************************************************
  *  AllowAccess()
  *********************************************************************************************************************/
/*! \brief        OS service AllowAccess().
 *  \details      This service sets the state of the current OS-Application from APPLICATION_RESTARTING to
 *                APPLICATION_ACCESSIBLE.
 *
 *  \return       E_OK              No error.
 *                E_OS_STATE        The application is not in the restarting state.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) AllowAccess(void);


/***********************************************************************************************************************
 *  TerminateApplication()
 **********************************************************************************************************************/
/*! \brief        OS service TerminateApplication().
 *  \details      This service terminates the OS-Application to which the calling Task/ISR/application
 *                specific error hook belongs.
 *
 *  \param[in]    Application       The identifier of the OS-Application to be terminated. If the caller belongs to
 *                                  Application the call results in a self termination.
 *  \param[in]    RestartOption     Either RESTART for doing a restart of the OS-Application or NO_RESTART if
 *                                  OS-Application shall not be restarted.
 *
 *  \return       E_OK              No errors
 *                E_OS_STATE        The state of Application does not allow terminating it:
 *                                    - The application is already terminated.
 *                                    - The application is restarting AND the caller does not belong to the application.
 *                                    - The application is restarting AND the caller does belong to the application
 *                                      AND the RestartOption is RESTART.
 *                E_OS_ID           (EXTENDED status:) Application was not valid.
 *                E_OS_VALUE        (EXTENDED status:) RestartOption was neither RESTART nor NO_RESTART.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_ACCESS       (EXTENDED status:) The caller belongs to a non-trusted OS-Application
 *                                                     AND the caller does not belong to given Application
 *                                                     TerminateApplication() shall return E_OS_ACCESS.
 *                E_OS_DISABLEDINT  (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2|ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) TerminateApplication
(
  ApplicationType Application,
  RestartType RestartOption
);


/***********************************************************************************************************************
 *  Os_ReadPeripheral8Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osReadPeripheral8().
 *  \details      Read a uint8 value from the given region. This API is not intended to be called directly.
 *                Os_ReadPeripheral8() shall be used. In case that this is not possible osReadPeripheral8() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]    PeripheralID      The peripheral region to read from.
 *  \param[in]    Address           The address of interest.
 *
 *  \return       The value which was read from address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_ReadPeripheral8Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address
);


/***********************************************************************************************************************
 *  Os_ReadPeripheral16Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osReadPeripheral16().
 *  \details      Read a uint16 value from the given region. This API is not intended to be called directly.
 *                Os_ReadPeripheral16() shall be used. In case that this is not possible osReadPeripheral16() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]    PeripheralID      The peripheral region to read from.
 *  \param[in]    Address           The address of interest.
 *
 *  \return       The value which was read from address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint16, OS_CODE) Os_ReadPeripheral16Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address
);


/***********************************************************************************************************************
 *  Os_ReadPeripheral32Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osReadPeripheral32().
 *  \details      Read a uint32 value from the given region. This API is not intended to be called directly.
 *                Os_ReadPeripheral32() shall be used. In case that this is not possible osReadPeripheral32() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]    PeripheralID      The peripheral region to read from.
 *  \param[in]    Address           The address of interest.
 *
 *  \return       The value which was read from address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_ReadPeripheral32Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address
);


/***********************************************************************************************************************
 *  Os_WritePeripheral8Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osWritePeripheral8().
 *  \details      Write a uint8 value to the given region. This API is not intended to be called directly.
 *                Os_WritePeripheral8() shall be used. In case that this is not possible osWritePeripheral8() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID      The peripheral region to write to.
 *  \param[in,out] Address           The address of interest.
 *  \param[in]     Value             The value to write to the given address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_WritePeripheral8Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address,
  uint8 Value
);


/***********************************************************************************************************************
 *  Os_WritePeripheral16Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osWritePeripheral16().
 *  \details      Write a uint16 value to the given region. This API is not intended to be called directly.
 *                Os_WritePeripheral16() shall be used. In case that this is not possible osWritePeripheral16() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID      The peripheral region to write to.
 *  \param[in,out] Address           The address of interest.
 *  \param[in]     Value             The value to write to the given address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_WritePeripheral16Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address,
  uint16 Value
);


/***********************************************************************************************************************
 *  Os_WritePeripheral32Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osWritePeripheral32().
 *  \details      Write a uint32 value to the given region. This API is not intended to be called directly.
 *                Os_WritePeripheral32() shall be used. In case that this is not possible osWritePeripheral32() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID      The peripheral region to write to.
 *  \param[in,out] Address           The address of interest.
 *  \param[in]     Value             The value to write to the given address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_WritePeripheral32Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address,
  uint32 Value
);


/***********************************************************************************************************************
 *  Os_ModifyPeripheral8Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osModifyPeripheral8().
 *  \details      Set and clear bits at the given address. This API is not intended to be called directly.
 *                Os_ModifyPeripheral8() shall be used. In case that this is not possible osModifyPeripheral8() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID     The peripheral region to write to.
 *  \param[in,out] Address          The address of interest.
 *  \param[in]     ClearMask        Bits which are 0, are cleared in the target value.
 *  \param[in]     SetMask          Bits which are 1, are set in the target value.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ModifyPeripheral8Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address,
  uint8 ClearMask,
  uint8 SetMask
);


/***********************************************************************************************************************
 *  Os_ModifyPeripheral16Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osModifyPeripheral16().
 *  \details      Set and clear bits at the given address. This API is not intended to be called directly.
 *                Os_ModifyPeripheral16() shall be used. In case that this is not possible osModifyPeripheral16() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID     The peripheral region to write to.
 *  \param[in,out] Address          The address of interest.
 *  \param[in]     ClearMask        Bits which are 0, are cleared in the target value.
 *  \param[in]     SetMask          Bits which are 1, are set in the target value.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ModifyPeripheral16Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address,
  uint16 ClearMask,
  uint16 SetMask
);


/***********************************************************************************************************************
 *  Os_ModifyPeripheral32Legacy()
 **********************************************************************************************************************/
/*! \brief        OS service osModifyPeripheral32().
 *  \details      Set and clear bits at the given address. This API is not intended to be called directly.
 *                Os_ModifyPeripheral32() shall be used. In case that this is not possible osModifyPeripheral32() has
 *                to be used.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID     The peripheral region to write to.
 *  \param[in,out] Address          The address of interest.
 *  \param[in]     ClearMask        Bits which are 0, are cleared in the target value.
 *  \param[in]     SetMask          Bits which are 1, are set in the target value.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ModifyPeripheral32Legacy
(
  Os_PeripheralIdType PeripheralID,
  uint32 Address,
  uint32 ClearMask,
  uint32 SetMask
);


/***********************************************************************************************************************
 *  Os_ReadPeripheral8()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ReadPeripheral8().
 *  \details      Read a uint8 value from the given region.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]    PeripheralID      The peripheral region to read from.
 *  \param[in]    Address           The address of interest.
 *
 *  \return       The value which was read from address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint8, OS_CODE) Os_ReadPeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint8, AUTOMATIC, OS_APPL_DATA) Address
);


/***********************************************************************************************************************
 *  Os_ReadPeripheral16()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ReadPeripheral16().
 *  \details      Read a uint16 value from the given region.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]    PeripheralID      The peripheral region to read from.
 *  \param[in]    Address           The address of interest.
 *
 *  \return       The value which was read from address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint16, OS_CODE) Os_ReadPeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint16, AUTOMATIC, OS_APPL_DATA) Address
);


/***********************************************************************************************************************
 *  Os_ReadPeripheral32()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ReadPeripheral32().
 *  \details      Read a uint32 value from the given region.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]    PeripheralID      The peripheral region to read from.
 *  \param[in]    Address           The address of interest.
 *
 *  \return       The value which was read from address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(uint32, OS_CODE) Os_ReadPeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2CONST(uint32, AUTOMATIC, OS_APPL_DATA) Address
);


/***********************************************************************************************************************
 *  Os_WritePeripheral8()
 **********************************************************************************************************************/
/*! \brief        OS service Os_WritePeripheral8().
 *  \details      Write a uint8 value to the given region.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID      The peripheral region to write to.
 *  \param[in,out] Address           The address of interest.
 *  \param[in]     Value             The value to write to the given address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_WritePeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint8, AUTOMATIC, OS_APPL_DATA) Address,
  uint8 Value
);


/***********************************************************************************************************************
 *  Os_WritePeripheral16()
 **********************************************************************************************************************/
/*! \brief        OS service Os_WritePeripheral16().
 *  \details      Write a uint16 value to the given region.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID      The peripheral region to write to.
 *  \param[in,out] Address           The address of interest.
 *  \param[in]     Value             The value to write to the given address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_WritePeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint16, AUTOMATIC, OS_APPL_DATA) Address,
  uint16 Value
);


/***********************************************************************************************************************
 *  Os_WritePeripheral32()
 **********************************************************************************************************************/
/*! \brief        OS service Os_WritePeripheral32().
 *  \details      Write a uint32 value to the given region.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID      The peripheral region to write to.
 *  \param[in,out] Address           The address of interest.
 *  \param[in]     Value             The value to write to the given address.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_WritePeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Address,
  uint32 Value
);


/***********************************************************************************************************************
 *  Os_ModifyPeripheral8()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ModifyPeripheral8().
 *  \details      Set and clear bits at the given address.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID     The peripheral region to write to.
 *  \param[in,out] Address          The address of interest.
 *  \param[in]     ClearMask        Bits which are 0, are cleared in the target value.
 *  \param[in]     SetMask          Bits which are 1, are set in the target value.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ModifyPeripheral8
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint8, AUTOMATIC, OS_APPL_DATA) Address,
  uint8 ClearMask,
  uint8 SetMask
);


/***********************************************************************************************************************
 *  Os_ModifyPeripheral16()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ModifyPeripheral16().
 *  \details      Set and clear bits at the given address.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID     The peripheral region to write to.
 *  \param[in,out] Address          The address of interest.
 *  \param[in]     ClearMask        Bits which are 0, are cleared in the target value.
 *  \param[in]     SetMask          Bits which are 1, are set in the target value.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ModifyPeripheral16
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint16, AUTOMATIC, OS_APPL_DATA) Address,
  uint16 ClearMask,
  uint16 SetMask
);


/***********************************************************************************************************************
 *  Os_ModifyPeripheral32()
 **********************************************************************************************************************/
/*! \brief        OS service Os_ModifyPeripheral32().
 *  \details      Set and clear bits at the given address.
 *  In case that one of the following errors occurs, the protection hook is called:
 *   - E_OS_ID           (EXTENDED status:) Invalid PeripheralID.
 *   - E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *   - E_OS_ACCESS       (Service Protection:) Caller's access rights are not sufficient.
 *
 *  \param[in]     PeripheralID     The peripheral region to write to.
 *  \param[in,out] Address          The address of interest.
 *  \param[in]     ClearMask        Bits which are 0, are cleared in the target value.
 *  \param[in]     SetMask          Bits which are 1, are set in the target value.
 *
 *  \context      TASK|ISR2|ERRHOOK|STARTHOOK|SHUTHOOK
 *
 *  \reentrant    TRUE for different addresses.
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: Given ID is valid or extended status checks are enabled.
 *  \pre          Pre-Condition: Given address is valid or extended status checks are enabled.
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ModifyPeripheral32
(
  Os_PeripheralIdType PeripheralID,
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Address,
  uint32 ClearMask,
  uint32 SetMask
);


/***********************************************************************************************************************
 *  CallTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        OS service CallTrustedFunction().
 *  \details      Each trusted OS-Application may export services which are callable from other OS-Applications.
 *
 *  \param[in]    FunctionIndex   Index of the function to be called.
 *  \param[in]    FunctionParams  Pointer to the parameters for the function. If no parameters are provided,
 *                                a NULL pointer has to be passed.
 *
 *  \return       E_OK              No error.
 *                E_OS_SERVICEID    No function defined for this index.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_ACCESS       (EXTENDED status:) The given object belongs to a foreign core.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) CallTrustedFunction
(
  TrustedFunctionIndexType FunctionIndex,
  TrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  Os_CallNonTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        OS service Os_CallNonTrustedFunction().
 *  \details      Each non-trusted OS-Application may export services which are callable from other OS-Applications.
 *
 *  \param[in]    FunctionIndex   Index of the function to be called.
 *  \param[in]    FunctionParams  Pointer to the parameters for the function. If no parameters are provided,
 *                                a NULL pointer has to be passed.
 *
 *  \return       E_OK              No error.
 *                E_OS_SERVICEID    No function defined for this index.
 *                E_OS_CALLEVEL     (EXTENDED status:) Called from invalid context.
 *                E_OS_ACCESS       (EXTENDED status:) The given object belongs to a foreign core.
 *                E_OS_ACCESS       (Service Protection:)
 *                                    - Owner application is not accessible.
 *                E_OS_SYS_NO_NTFSTACK  (EXTENDED status:) No further NTF-Stacks available.
 *
 *  \context      TASK|ISR2
 *
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_CallNonTrustedFunction
(
  Os_NonTrustedFunctionIndexType FunctionIndex,
  Os_NonTrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  Os_CallFastTrustedFunction()
 **********************************************************************************************************************/
/*! \brief        OS service Os_CallFastTrustedFunction().
 *  \details      Each trusted OS-Application may export services which are callable from other OS-Applications.
 *                The speedup of the runtime is achieved by removing most of the OS error checks, the application switch
 *                and the MPU reprogramming.
 *
 *  \param[in]    FunctionIndex   Index of the function to be called.
 *  \param[in]    FunctionParams  Pointer to the parameters for the function. If no parameters are provided,
 *                                a NULL pointer has to be passed.
 *
 *  \return       E_OK              No error.
 *                E_OS_SERVICEID    No function defined for this index.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE  Depends on called function. If called function is synchronous then service is synchronous.
 *                      May cause rescheduling.
 *
 *  \pre          Pre-Condition: None
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_CallFastTrustedFunction
(
  Os_FastTrustedFunctionIndexType FunctionIndex,
  Os_FastTrustedFunctionParameterRefType FunctionParams
);


/***********************************************************************************************************************
 *  CheckTaskMemoryAccess()
 **********************************************************************************************************************/
/*! \brief        OS service CheckTaskMemoryAccess().
 *  \details      The system service returns the access rights of the given task to the given address range. The return
 *                value contains the information whether or not the task is allowed to read or write data from/to the
 *                memory region, whether the task is allowed to execute code in the memory region and whether the memory
 *                region is stack space.
 *
 *  \param[in]    TaskID              Reference to the task, the access right shall be checked for.
 *  \param[in]    Address             Start address of the memory region, the access rights shall be checked for.
 *  \param[in]    Size                The size of the the memory region, the access rights shall be checked for.
 *
 *  \return       Value which contains the access rights of the given task to the given memory region.
 *                OS_MEM_ACCESS_TYPE_NON      No access or Ivalid TaskID or address range overflow.
 *
 *  \context      TASK|ISR2|ERRHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(AccessType, OS_CODE) CheckTaskMemoryAccess
(
  TaskType TaskID,
  MemoryStartAddressType Address,
  MemorySizeType Size
);


/***********************************************************************************************************************
 *  CheckISRMemoryAccess()
 **********************************************************************************************************************/
/*! \brief        OS service CheckISRMemoryAccess().
 *  \details      The system service returns the access rights of the given ISR to the given address range. The return
 *                value contains the information whether or not the ISR is allowed to read or write data from/to the
 *                memory region, whether the ISR is allowed to execute code in the memory region and whether the memory
 *                region is stack space.
 *
 *  \param[in]    ISRID               Reference to the ISR, the access right shall be checked for.
 *  \param[in]    Address             Start address of the memory region, the access rights shall be checked for.
 *  \param[in]    Size                The size of the the memory region, the access rights shall be checked for.
 *
 *  \return       Value which contains the access rights of the given ISR to the given memory region.
 *                OS_MEM_ACCESS_TYPE_NON      No access or Ivalid ISRID or address range overflow.
 *
 *  \context      TASK|ISR2|ERRHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63921
 **********************************************************************************************************************/
FUNC(AccessType, OS_CODE) CheckISRMemoryAccess
(
  ISRType ISRID,
  MemoryStartAddressType Address,
  MemorySizeType Size
);


/***********************************************************************************************************************
 *  Os_GetDetailedError()
 **********************************************************************************************************************/
/*! \brief        Returns error information of the last error occurred on the local core.
 *  \details      --no details--
 *
 *  \param[out]   ErrorRef    A reference to an \ref Os_ErrorInformationType object.
 *
 *  \return       E_OK                No error.
 *                E_OS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *                E_OS_PARAM_POINTER  (EXTENDED status:) Given pointer is NULL.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-64000
 **********************************************************************************************************************/
FUNC(StatusType, OS_CODE) Os_GetDetailedError(Os_ErrorInformationRefType ErrorRef);


/***********************************************************************************************************************
 *  OSErrorGetServiceId()
 **********************************************************************************************************************/
/*! \brief        OS service OSErrorGetServiceId().
 *  \details      Provides the service identifier where the error has been risen.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(OSServiceIdType, OS_CODE) OSErrorGetServiceId(void);


/***********************************************************************************************************************
*  OSError_Os_DisableInterruptSource_ISRID()
**********************************************************************************************************************/
/*! \brief        Returns parameter ISRID of a faulty Os_DisableInterruptSource call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ISRType, OS_CODE) OSError_Os_DisableInterruptSource_ISRID(void);


/***********************************************************************************************************************
*  OSError_Os_EnableInterruptSource_ISRID()
**********************************************************************************************************************/
/*! \brief        Returns parameter ISRID of a faulty Os_EnableInterruptSource call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ISRType, OS_CODE) OSError_Os_EnableInterruptSource_ISRID(void);


/***********************************************************************************************************************
*  OSError_Os_EnableInterruptSource_ClearPending()
**********************************************************************************************************************/
/*! \brief        Returns parameter ClearPending of a faulty Os_EnableInterruptSource call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(boolean, OS_CODE) OSError_Os_EnableInterruptSource_ClearPending(void);                                             /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */


/***********************************************************************************************************************
*  OSError_Os_ClearPendingInterrupt_ISRID()
**********************************************************************************************************************/
/*! \brief        Returns parameter ISRID of a faulty Os_ClearPendingInterrupt call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ISRType, OS_CODE) OSError_Os_ClearPendingInterrupt_ISRID(void);


/***********************************************************************************************************************
*  OSError_Os_IsInterruptSourceEnabled_ISRID()
**********************************************************************************************************************/
/*! \brief        Returns parameter ISRID of a faulty Os_IsInterruptSourceEnabled call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ISRType, OS_CODE) OSError_Os_IsInterruptSourceEnabled_ISRID(void);


/***********************************************************************************************************************
*  OSError_Os_IsInterruptSourceEnabled_IsEnabled()
**********************************************************************************************************************/
/*! \brief        Returns parameter IsEnabled of a faulty Os_IsInterruptSourceEnabled call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT), OS_CODE) OSError_Os_IsInterruptSourceEnabled_IsEnabled(void);


/***********************************************************************************************************************
*  OSError_Os_IsInterruptPending_ISRID()
***********************************************************************************************************************/
/*! \brief        Returns parameter ISRID of a faulty Os_IsInterruptPending call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ISRType, OS_CODE) OSError_Os_IsInterruptPending_ISRID(void);


/***********************************************************************************************************************
*  OSError_Os_IsInterruptPending_IsPending()
***********************************************************************************************************************/
/*! \brief        Returns parameter IsPending of a faulty Os_IsInterruptPending_IsPending call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(P2VAR(boolean, AUTOMATIC, OS_VAR_NOINIT), OS_CODE) OSError_Os_IsInterruptPending_IsPending(void);


/***********************************************************************************************************************
*  OSError_CallTrustedFunction_FunctionIndex()
***********************************************************************************************************************/
/*! \brief        Returns parameter FunctionIndex of a faulty CallTrustedFunction call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TrustedFunctionIndexType, OS_CODE) OSError_CallTrustedFunction_FunctionIndex(void);


/***********************************************************************************************************************
 *  OSError_CallTrustedFunction_FunctionParams()
 **********************************************************************************************************************/
/*! \brief        Returns parameter FunctionParams of a faulty CallTrustedFunction call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TrustedFunctionParameterRefType, OS_CODE)
OSError_CallTrustedFunction_FunctionParams(void);                                                                       /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */



/***********************************************************************************************************************
*  OSError_CallNonTrustedFunction_FunctionIndex()
***********************************************************************************************************************/
/*! \brief        Returns parameter FunctionIndex of a faulty CallTrustedFunction call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(Os_NonTrustedFunctionIndexType, OS_CODE) OSError_CallNonTrustedFunction_FunctionIndex(void);


/***********************************************************************************************************************
 *  OSError_CallNonTrustedFunction_FunctionParams()
 **********************************************************************************************************************/
/*! \brief        Returns parameter FunctionParams of a faulty CallNonTrustedFunction call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(Os_NonTrustedFunctionParameterRefType, OS_CODE)
OSError_CallNonTrustedFunction_FunctionParams(void);                                                                    /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */


/***********************************************************************************************************************
 *  OSError_StartScheduleTableRel_ScheduleTableID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID of a faulty StartScheduleTableRel call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_StartScheduleTableRel_ScheduleTableID(void);


/***********************************************************************************************************************
 *  OSError_StartScheduleTableRel_Offset()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Offset of a faulty StartScheduleTableRel call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TickType, OS_CODE) OSError_StartScheduleTableRel_Offset(void);


/***********************************************************************************************************************
 *  OSError_StartScheduleTableAbs_ScheduleTableID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID of a faulty StartScheduleTableAbs call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_StartScheduleTableAbs_ScheduleTableID(void);


/***********************************************************************************************************************
 *  OSError_StartScheduleTableAbs_Start()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Start of a faulty StartScheduleTableAbs call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TickType, OS_CODE) OSError_StartScheduleTableAbs_Start(void);                                                      /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */


/***********************************************************************************************************************
 *  OSError_StopScheduleTable_ScheduleTableID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID of a faulty StopScheduleTable call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_StopScheduleTable_ScheduleTableID(void);


/***********************************************************************************************************************
 *  OSError_NextScheduleTable_ScheduleTableID_From()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID_From of a faulty NextScheduleTable call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_NextScheduleTable_ScheduleTableID_From(void);


/***********************************************************************************************************************
 *  OSError_NextScheduleTable_ScheduleTableID_To()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID_To of a faulty NextScheduleTable call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_NextScheduleTable_ScheduleTableID_To(void);


/***********************************************************************************************************************
 *  OSError_StartScheduleTableSynchron_ScheduleTableID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID of a faulty StartScheduleTableSynchron call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_StartScheduleTableSynchron_ScheduleTableID(void);


/***********************************************************************************************************************
 *  OSError_SyncScheduleTable_ScheduleTableID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID of a faulty SyncScheduleTable call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_SyncScheduleTable_ScheduleTableID(void);


/***********************************************************************************************************************
 *  OSError_SyncScheduleTable_Value()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Value of a faulty SyncScheduleTable call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TickType, OS_CODE) OSError_SyncScheduleTable_Value(void);


/***********************************************************************************************************************
 *  OSError_SetScheduleTableAsync_ScheduleTableID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID of a faulty SetScheduleTableAsync call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_SetScheduleTableAsync_ScheduleTableID(void);


/***********************************************************************************************************************
 *  OSError_GetScheduleTableStatus_ScheduleTableID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleTableID of a faulty GetScheduleTableStatus call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableType, OS_CODE) OSError_GetScheduleTableStatus_ScheduleTableID(void);


/***********************************************************************************************************************
 *  OSError_GetScheduleTableStatus_ScheduleStatus()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ScheduleStatus of a faulty GetScheduleTableStatus call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ScheduleTableStatusRefType, OS_CODE) OSError_GetScheduleTableStatus_ScheduleStatus(void);


/***********************************************************************************************************************
 *  OSError_IncrementCounter_CounterID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter CounterID of a faulty IncrementCounter call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(CounterType, OS_CODE) OSError_IncrementCounter_CounterID(void);


/***********************************************************************************************************************
 *  OSError_GetCounterValue_CounterID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter CounterID of a faulty GetCounterValue call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(CounterType, OS_CODE) OSError_GetCounterValue_CounterID(void);


/***********************************************************************************************************************
 *  OSError_GetCounterValue_Value()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Value of a faulty GetCounterValue call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TickRefType, OS_CODE) OSError_GetCounterValue_Value(void);


/***********************************************************************************************************************
 *  OSError_GetElapsedValue_CounterID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter CounterID of a faulty GetElapsedValue call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(CounterType, OS_CODE) OSError_GetElapsedValue_CounterID(void);


/***********************************************************************************************************************
 *  OSError_GetElapsedValue_Value()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Value of a faulty GetElapsedValue call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TickRefType, OS_CODE) OSError_GetElapsedValue_Value(void);


/***********************************************************************************************************************
 *  OSError_GetElapsedValue_ElapsedValue()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ElapsedValue of a faulty GetElapsedValue call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TickRefType, OS_CODE) OSError_GetElapsedValue_ElapsedValue(void);


/***********************************************************************************************************************
 *  OSError_TerminateApplication_Application()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Application of a faulty TerminateApplication call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ApplicationType, OS_CODE) OSError_TerminateApplication_Application(void);


/***********************************************************************************************************************
 *  OSError_TerminateApplication_RestartOption()
 **********************************************************************************************************************/
/*! \brief        Returns parameter RestartOption of a faulty TerminateApplication call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(RestartType, OS_CODE) OSError_TerminateApplication_RestartOption(void);


/***********************************************************************************************************************
 *  OSError_GetApplicationState_Application()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Application of a faulty GetApplicationState call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ApplicationType, OS_CODE) OSError_GetApplicationState_Application(void);


/***********************************************************************************************************************
 *  OSError_GetApplicationState_Value()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Value of a faulty GetApplicationState call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(ApplicationStateRefType, OS_CODE) OSError_GetApplicationState_Value(void);


/***********************************************************************************************************************
 *  OSError_GetSpinlock_SpinlockId()
 **********************************************************************************************************************/
/*! \brief        Returns parameter SpinlockId of a faulty GetSpinlock call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(SpinlockIdType, OS_CODE) OSError_GetSpinlock_SpinlockId(void);


/***********************************************************************************************************************
 *  OSError_ReleaseSpinlock_SpinlockId()
 **********************************************************************************************************************/
/*! \brief        Returns parameter SpinlockId of a faulty ReleaseSpinlock call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(SpinlockIdType, OS_CODE) OSError_ReleaseSpinlock_SpinlockId(void);


/***********************************************************************************************************************
 *  OSError_TryToGetSpinlock_SpinlockId()
 **********************************************************************************************************************/
/*! \brief        Returns parameter SpinlockId of a faulty TryToGetSpinlock call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(SpinlockIdType, OS_CODE) OSError_TryToGetSpinlock_SpinlockId(void);


/***********************************************************************************************************************
 *  OSError_TryToGetSpinlock_Success()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Success of a faulty TryToGetSpinlock call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(TryToGetSpinlockType const *, OS_CODE) OSError_TryToGetSpinlock_Success(void);


/***********************************************************************************************************************
 *  OSError_ControlIdle_CoreID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter CoreID of a faulty ControlIdle call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(CoreIdType, OS_CODE) OSError_ControlIdle_CoreID(void);


/***********************************************************************************************************************
 *  OSError_Os_GetExceptionContext_Context()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Context of a faulty Os_GetExceptionContext call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(Os_ExceptionContextRefType, OS_CODE) OSError_Os_GetExceptionContext_Context(void);


/***********************************************************************************************************************
 *  OSError_Os_SetExceptionContext_Context()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Context of a faulty Os_SetExceptionContext call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(Os_ExceptionContextRefType, OS_CODE) OSError_Os_SetExceptionContext_Context(void);


/***********************************************************************************************************************
 *  OSError_ControlIdle_IdleMode()
 **********************************************************************************************************************/
/*! \brief        Returns parameter IdleMode of a faulty ControlIdle call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(IdleModeType, OS_CODE) OSError_ControlIdle_IdleMode(void);


/***********************************************************************************************************************
 *  OSError_BarrierSynchronize_BarrierID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter BarrierID of a faulty BarrierSynchronize call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(Os_BarrierIdType, OS_CODE) OSError_BarrierSynchronize_BarrierID(void);


/***********************************************************************************************************************
 *  OSError_ActivateTask_TaskID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter TaskID of a faulty ActivateTask call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TaskType, OS_CODE) OSError_ActivateTask_TaskID(void);


/***********************************************************************************************************************
 *  OSError_ChainTask_TaskID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter TaskID of a faulty ChainTask call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TaskType, OS_CODE) OSError_ChainTask_TaskID(void);


/***********************************************************************************************************************
 *  OSError_GetTaskID_TaskID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter TaskID of a faulty GetTaskID call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TaskRefType, OS_CODE) OSError_GetTaskID_TaskID(void);


/***********************************************************************************************************************
 *  OSError_GetTaskState_TaskID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter TaskID of a faulty GetTaskState call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TaskType, OS_CODE) OSError_GetTaskState_TaskID(void);


/***********************************************************************************************************************
 *  OSError_GetTaskState_State()
 **********************************************************************************************************************/
/*! \brief        Returns parameter State of a faulty GetTaskState call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TaskStateRefType, OS_CODE) OSError_GetTaskState_State(void);


/***********************************************************************************************************************
 *  OSError_SetEvent_TaskID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter TaskID of a faulty SetEvent call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TaskType, OS_CODE) OSError_SetEvent_TaskID(void);


/***********************************************************************************************************************
 *  OSError_SetEvent_Mask()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Mask of a faulty SetEvent call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(EventMaskType, OS_CODE) OSError_SetEvent_Mask(void);


/***********************************************************************************************************************
 *  OSError_ClearEvent_Mask()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Mask of a faulty ClearEvent call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(EventMaskType, OS_CODE) OSError_ClearEvent_Mask(void);


/***********************************************************************************************************************
 *  OSError_GetEvent_TaskID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter TaskID of a faulty GetEvent call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TaskType, OS_CODE) OSError_GetEvent_TaskID(void);


/***********************************************************************************************************************
 *  OSError_GetEvent_Mask()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Mask of a faulty GetEvent call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(EventMaskRefType, OS_CODE) OSError_GetEvent_Mask(void);


/***********************************************************************************************************************
 *  OSError_WaitEvent_Mask()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Mask of a faulty WaitEvent call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(EventMaskType, OS_CODE) OSError_WaitEvent_Mask(void);


/***********************************************************************************************************************
 *  OSError_GetAlarmBase_AlarmID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter AlarmID of a faulty GetAlarmBase call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(AlarmType, OS_CODE) OSError_GetAlarmBase_AlarmID(void);


/***********************************************************************************************************************
 *  OSError_GetAlarmBase_Info()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Info of a faulty GetAlarmBase call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(AlarmBaseRefType, OS_CODE) OSError_GetAlarmBase_Info(void);


/***********************************************************************************************************************
 *  OSError_GetAlarm_AlarmID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter AlarmID of a faulty GetAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(AlarmType, OS_CODE) OSError_GetAlarm_AlarmID(void);


/***********************************************************************************************************************
 *  OSError_GetAlarm_Tick()
 **********************************************************************************************************************/
/*! \brief        Returns parameter Tick of a faulty GetAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TickRefType, OS_CODE) OSError_GetAlarm_Tick(void);


/***********************************************************************************************************************
 *  OSError_SetRelAlarm_AlarmID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter AlarmID of a faulty SetRelAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(AlarmType, OS_CODE) OSError_SetRelAlarm_AlarmID(void);


/***********************************************************************************************************************
 *  OSError_SetRelAlarm_increment()
 **********************************************************************************************************************/
/*! \brief        Returns parameter increment of a faulty SetRelAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TickType, OS_CODE) OSError_SetRelAlarm_increment(void);


/***********************************************************************************************************************
 *  OSError_SetRelAlarm_cycle()
 **********************************************************************************************************************/
/*! \brief        Returns parameter cycle of a faulty SetRelAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TickType, OS_CODE) OSError_SetRelAlarm_cycle(void);


/***********************************************************************************************************************
 *  OSError_SetAbsAlarm_AlarmID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter AlarmID of a faulty SetAbsAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(AlarmType, OS_CODE) OSError_SetAbsAlarm_AlarmID(void);


/***********************************************************************************************************************
 *  OSError_SetAbsAlarm_start()
 **********************************************************************************************************************/
/*! \brief        Returns parameter start of a faulty SetAbsAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TickType, OS_CODE) OSError_SetAbsAlarm_start(void);


/***********************************************************************************************************************
 *  OSError_SetAbsAlarm_cycle()
 **********************************************************************************************************************/
/*! \brief        Returns parameter cycle of a faulty SetAbsAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(TickType, OS_CODE) OSError_SetAbsAlarm_cycle(void);


/***********************************************************************************************************************
 *  OSError_CancelAlarm_AlarmID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter AlarmID of a faulty CancelAlarm call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(AlarmType, OS_CODE) OSError_CancelAlarm_AlarmID(void);


/***********************************************************************************************************************
 *  OSError_GetResource_ResID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ResID of a faulty GetResource call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(ResourceType, OS_CODE) OSError_GetResource_ResID(void);


/***********************************************************************************************************************
 *  OSError_ReleaseResource_ResID()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ResID of a faulty ReleaseResource call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 *  \trace        SPEC-63736
 **********************************************************************************************************************/
FUNC(ResourceType, OS_CODE) OSError_ReleaseResource_ResID(void);


/***********************************************************************************************************************
 *  OSError_Os_GetUnhandledIrq_InterruptSource()
 **********************************************************************************************************************/
/*! \brief        Returns parameter InterruptSource of a faulty Os_GetUnhandledIrq call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(Os_InterruptSourceIdRefType, OS_CODE) OSError_Os_GetUnhandledIrq_InterruptSource(void);


/***********************************************************************************************************************
 *  OSError_Os_GetUnhandledExc_ExceptionSource()
 **********************************************************************************************************************/
/*! \brief        Returns parameter ExceptionSource of a faulty Os_GetUnhandledExc call.
 *  \details      --no details--
 *
 *  \return       Requested parameter value.
 *
 *  \context      ERRHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Pre-Condition: None
 *
 *  \trace        CREQ-97
 *  \trace        SPEC-67578, SPEC-63766
 **********************************************************************************************************************/
FUNC(Os_ExceptionSourceIdRefType, OS_CODE) OSError_Os_GetUnhandledExc_ExceptionSource(void);


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */




#endif /* OS_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os.h
 **********************************************************************************************************************/
