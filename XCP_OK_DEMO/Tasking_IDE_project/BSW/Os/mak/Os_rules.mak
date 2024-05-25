###############################################################################
# File Name  : Os_rules.mak
# Description: Rules makefile 
#
#-----------------------------------------------------------------------------
#               C O P Y R I G H T
#-----------------------------------------------------------------------------
# Copyright (c) 2019 by Vector Informatik GmbH.  All rights reserved.
#
#-----------------------------------------------------------------------------
#               A U T H O R   I D E N T I T Y
#-----------------------------------------------------------------------------
# Initials     Name                      Company
# --------     ---------------------     -------------------------------------
# Dfe          David Feuerstein          Vector Informatik GmbH
# Cbl          Claudia Buhl              Vector Informatik GmbH
# Rk           Rainer Kuennemeyer        Vector Informatik GmbH
#-----------------------------------------------------------------------------
#               R E V I S I O N   H I S T O R Y
#-----------------------------------------------------------------------------
# Date         Version     Sign Description
# ----------   -------     ---- ----------------------------------------------
# 2016-03-24   1.01.00     Dfe  Initial Version
# 2019-02-06   1.02.00     Cbl  Added support of component-based SIP structure
# 2019-02-11               Rk   Rework to match the template
#-----------------------------------------------------------------------------
# TemplateVersion = 1.01
###############################################################################

# Include of OS Core makefile

include $(ROOT)\$(GLOBAL_COMP_DIR)\Os\$(if $(BSW_MAKE_DIR),$(BSW_MAKE_DIR),mak)\Os_Core.mak


# Component Files

CC_FILES_TO_BUILD       +=  Os$(BSW_SRC_DIR)\Os_Hal_Context.c      \
                            Os$(BSW_SRC_DIR)\Os_Hal_Core.c         \
                            Os$(BSW_SRC_DIR)\Os_Hal_Entry.c        \
                            Os$(BSW_SRC_DIR)\Os_Hal_Trap.c         \
                            Os$(BSW_SRC_DIR)\Os_Hal_Compiler_HighTec.c

ASM_FILES_TO_BUILD      +=

GENERATED_SOURCE_FILES  +=  $(GENDATA_DIR)\Os_Hal_Context_Lcfg.c          \
                            $(GENDATA_DIR)\Os_Hal_Core_Lcfg.c             \
                            $(GENDATA_DIR)\Os_Hal_Entry_Lcfg.c            \
                            $(GENDATA_DIR)\Os_Hal_Interrupt_Lcfg.c        \
                            $(GENDATA_DIR)\Os_Hal_Kernel_Lcfg.c           \
                            $(GENDATA_DIR)\Os_Hal_MemoryProtection_Lcfg.c \
                            $(GENDATA_DIR)\Os_Hal_Timer_Lcfg.c


# Library Settings
# Library not supported
