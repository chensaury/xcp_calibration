###############################################################################
# File Name  : Os_Core.inc                                                    #
# Description: Autosar makefile Template                                      #
#              This makefile is a template to implement the common            #
#              features of each project.                                      #
#              It is included by the Global.Makefile.target.make.$(Version)   #
#              and is supported from version 3.24 .                           #
#                                                                             #
#-----------------------------------------------------------------------------#
#               C O P Y R I G H T                                             #
#-----------------------------------------------------------------------------#
# Copyright (c) 2018 by Vector Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               A U T H O R   I D E N T I T Y                                 #
#-----------------------------------------------------------------------------#
# Initials     Name                      Company                              #
# --------     ---------------------     -------------------------------------#
# Dfe          David Feuerstein          Vector Informatik GmbH               #
# Rk           Rainer Kuennemeyer        Vector Informatik GmbH               #
# Smn          Martin Schultheiﬂ         Vector Informatik GmbH               #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version  Sign Description                                      #
# ----------   -------  ---- -------------------------------------------------#
# 2016-03-24   1.00     Dfe  Initial Version                                  #
# 2018-02-23   1.03     Smn  Added Os_Error_Lcfg.c.                           #
# 2018-07-05   1.04     Rk   Removed FifoPtr.c (no longer part of the OS)     #
# 2019/02/06   1.05     Cbl  Added support of component-based SIP structure
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################

CC_FILES_TO_BUILD       +=  Os$(BSW_SRC_DIR)\Os_AccessCheck.c      \
                            Os$(BSW_SRC_DIR)\Os_Alarm.c            \
                            Os$(BSW_SRC_DIR)\Os_Application.c      \
                            Os$(BSW_SRC_DIR)\Os_Barrier.c          \
                            Os$(BSW_SRC_DIR)\Os_Bit.c              \
                            Os$(BSW_SRC_DIR)\Os_BitArray.c         \
                            Os$(BSW_SRC_DIR)\Os_Core.c             \
                            Os$(BSW_SRC_DIR)\Os_Counter.c          \
                            Os$(BSW_SRC_DIR)\Os_Deque.c            \
                            Os$(BSW_SRC_DIR)\Os_Error.c            \
                            Os$(BSW_SRC_DIR)\Os_Event.c            \
                            Os$(BSW_SRC_DIR)\Os_Fifo.c             \
                            Os$(BSW_SRC_DIR)\Os_Fifo08.c           \
                            Os$(BSW_SRC_DIR)\Os_Fifo16.c           \
                            Os$(BSW_SRC_DIR)\Os_Fifo32.c           \
                            Os$(BSW_SRC_DIR)\Os_FifoRef.c          \
                            Os$(BSW_SRC_DIR)\Os_Hook.c             \
                            Os$(BSW_SRC_DIR)\Os_Interrupt.c        \
                            Os$(BSW_SRC_DIR)\Os_Ioc.c              \
                            Os$(BSW_SRC_DIR)\Os_Isr.c              \
                            Os$(BSW_SRC_DIR)\Os_Job.c              \
                            Os$(BSW_SRC_DIR)\Os_Lock.c             \
                            Os$(BSW_SRC_DIR)\Os_MemoryProtection.c \
                            Os$(BSW_SRC_DIR)\Os_Peripheral.c       \
                            Os$(BSW_SRC_DIR)\Os_PriorityQueue.c    \
                            Os$(BSW_SRC_DIR)\Os_Resource.c         \
                            Os$(BSW_SRC_DIR)\Os_Scheduler.c        \
                            Os$(BSW_SRC_DIR)\Os_ScheduleTable.c    \
                            Os$(BSW_SRC_DIR)\Os_ServiceFunction.c  \
                            Os$(BSW_SRC_DIR)\Os_Spinlock.c         \
                            Os$(BSW_SRC_DIR)\Os_Stack.c            \
                            Os$(BSW_SRC_DIR)\Os_Task.c             \
                            Os$(BSW_SRC_DIR)\Os_Thread.c           \
                            Os$(BSW_SRC_DIR)\Os_Timer.c            \
                            Os$(BSW_SRC_DIR)\Os_TimingProtection.c \
                            Os$(BSW_SRC_DIR)\Os_Trace.c            \
                            Os$(BSW_SRC_DIR)\Os_Trap.c             \
                            Os$(BSW_SRC_DIR)\Os_XSignal.c

GENERATED_SOURCE_FILES  +=  $(GENDATA_DIR)\Os_AccessCheck_Lcfg.c          \
                            $(GENDATA_DIR)\Os_Alarm_Lcfg.c                \
                            $(GENDATA_DIR)\Os_Application_Lcfg.c          \
                            $(GENDATA_DIR)\Os_Barrier_Lcfg.c              \
                            $(GENDATA_DIR)\Os_Core_Lcfg.c                 \
                            $(GENDATA_DIR)\Os_Counter_Lcfg.c              \
                            $(GENDATA_DIR)\Os_Error_Lcfg.c                \
                            $(GENDATA_DIR)\Os_Hook_Lcfg.c                 \
                            $(GENDATA_DIR)\Os_Ioc_Lcfg.c                  \
                            $(GENDATA_DIR)\Os_Isr_Lcfg.c                  \
                            $(GENDATA_DIR)\Os_MemoryProtection_Lcfg.c     \
                            $(GENDATA_DIR)\Os_Peripheral_Lcfg.c           \
                            $(GENDATA_DIR)\Os_Resource_Lcfg.c             \
                            $(GENDATA_DIR)\Os_Scheduler_Lcfg.c            \
                            $(GENDATA_DIR)\Os_ScheduleTable_Lcfg.c        \
                            $(GENDATA_DIR)\Os_ServiceFunction_Lcfg.c      \
                            $(GENDATA_DIR)\Os_Spinlock_Lcfg.c             \
                            $(GENDATA_DIR)\Os_Stack_Lcfg.c                \
                            $(GENDATA_DIR)\Os_Task_Lcfg.c                 \
                            $(GENDATA_DIR)\Os_TimingProtection_Lcfg.c     \
                            $(GENDATA_DIR)\Os_Trace_Lcfg.c                \
                            $(GENDATA_DIR)\Os_XSignal_Lcfg.c
