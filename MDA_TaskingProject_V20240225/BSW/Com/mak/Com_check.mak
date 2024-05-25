###############################################################################
# File Name  : Com_check.mak                                                  #
# Description: Autosar makefile Template                                      #
#              This makefile is a template to implement the common            #
#              features of each project.                                      #
#              It is included by the Global.Makefile.target.make.$(Version)   #
#              and is supported from version 3.24 .                           #
#                                                                             #
# This Template is based on AUTOSAR_BSW_MakefileInterface.doc version 0.4     #
#                                                                             #
#-----------------------------------------------------------------------------#
#               C O P Y R I G H T                                             #
#-----------------------------------------------------------------------------#
# Copyright (c) 2014 by Vector Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               A U T H O R   I D E N T I T Y                                 #
#-----------------------------------------------------------------------------#
# Initials     Name                      Company                              #
# --------     ---------------------     -------------------------------------#
# ms           Gunnar Meiss              Vector Informatik GmbH               #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version  Sign Description                                      #
# ----------   -------  ---- -------------------------------------------------#
# 2011/11/30   1.00     ms   initial CFG5 version derived from                #
#                            Il_AsrIpduM Version 1.00.00                      #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 1.0                                                       #
###############################################################################

###############################################################
# REGISTRY
#

#e.g.: PREPARE_CONFIGURATION_INTERFACE     += CAN_MODULES 
PREPARE_CONFIGURATION_INTERFACE     +=

CHECK_VARS_WHICH_ARE_REQUIRED       += 

CHECK_VARS_WHICH_ARE_OPTIONAL       +=

CHECK_VARS_WHICH_ARE_OBSOLETE       +=

CHECK_VARS_WITH_ONE_CC_FILE         +=
CHECK_VARS_WITH_MORE_CC_FILES       +=

CHECK_VARS_WITH_ONE_CPP_FILE        +=
CHECK_VARS_WITH_MORE_CPP_FILES      +=

CHECK_VARS_WITH_ONE_ASM_FILE        +=
CHECK_VARS_WITH_MORE_ASM_FILES      +=

CHECK_VARS_WITH_ONE_LIB_FILE        +=
CHECK_VARS_WITH_MORE_LIB_FILES      +=

CHECK_VARS_WITH_ONE_OBJ_FILE        +=
CHECK_VARS_WITH_MORE_OBJ_FILES      +=

#e.g: CHECK_VARS_WITH_ONE_DIRECTORY       +=     $(DIRECTORIES_TO_CREATE)
#       $(DIRECTORIES_TO_CREATE) = C:\demo\drv          (this var is defined in _rules.mak)
CHECK_VARS_WITH_ONE_DIRECTORY       +=
CHECK_VARS_WITH_MORE_DIRECTORIES    +=

CHECK_VARS_WITH_ONE_FILE            +=
CHECK_VARS_WITH_MORE_FILES          +=

CHECK_VARS_WITH_MAX_LENGTH_ONE      +=

###############################################################
# SPECIFIC
#
#ifneq ($(CAN_DRIVER_MODE),singlechannel)
#ifneq ($(CAN_DRIVER_MODE),multichannel)
#$(error The value of the variable CAN_DRIVER_MODE is not valid. \
#	Please use singlechannel or multichannel)
#endif
#endif


###############################################################
# REQUIRED
#
# No other resources are required for a Configuration Check 
# Makefile
#
###############################################################


###############################################################
# PROVIDE
#
# A configuration Makefile does not provide resources for other
# basic software bundles or the base-make package.
#
###############################################################

