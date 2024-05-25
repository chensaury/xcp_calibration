###############################################################################
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
# Copyright (c) 2018 by Vector Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               A U T H O R   I D E N T I T Y                                 #
#-----------------------------------------------------------------------------#
# Initials     Name                      Company                              #
# --------     ---------------------     -------------------------------------#
# virgaj       Andrej Gazvoda            Vector Informatik GmbH               #
# virgki       Kishore Gunda             Vector Informatik GmbH               #
#-----------------------------------------------------------------------------#
#              R E V I S I O N   H I S T O R Y                                #
#-----------------------------------------------------------------------------#
# Date         Version  Sign    Description                                   #
# ----------   -------  ------  ----------------------------------------------#
# 2018/03/05   1.00.00  Virgaj	Initial revision			                  #
# 2018/03/15   1.00.01  Virgaj	Added Irq        			                  #
# 2018/04/11   1.01.00	Virgaj	Support of TC39x							  #
# 2018/04/23   1.01.01	Virgaj	Added handling of component Irq				  #
# 2018/07/24   1.02.00	Virgki	Update the include path for _Reg			  #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################


###############################################################
# REGISTRY
#

#Defaults for component switches
#Can be overwritten in Makefile.Project.Part.Defines
ifeq ($(MCAL_EXCLUDE_ADC),)
MCAL_EXCLUDE_ADC = 0
endif
ifeq ($(MCAL_EXCLUDE_DIO),)
MCAL_EXCLUDE_DIO = 0
endif
ifeq ($(MCAL_EXCLUDE_DMA),)
MCAL_EXCLUDE_DMA = 0
endif
ifeq ($(MCAL_EXCLUDE_FEE),)
MCAL_EXCLUDE_FEE = 0
endif
ifeq ($(MCAL_EXCLUDE_FLS),)
MCAL_EXCLUDE_FLS = 0
endif
ifeq ($(MCAL_EXCLUDE_GPT),)
MCAL_EXCLUDE_GPT = 0
endif
ifeq ($(MCAL_EXCLUDE_ICU),)
MCAL_EXCLUDE_ICU = 0
endif
ifeq ($(MCAL_EXCLUDE_IRQ),)
MCAL_EXCLUDE_IRQ = 0
endif
ifeq ($(MCAL_EXCLUDE_MCU),)
MCAL_EXCLUDE_MCU = 0
endif
ifeq ($(MCAL_EXCLUDE_PORT),)
MCAL_EXCLUDE_PORT = 0
endif
ifeq ($(MCAL_EXCLUDE_PWM),)
MCAL_EXCLUDE_PWM = 0
endif
ifeq ($(MCAL_EXCLUDE_SPI),)
MCAL_EXCLUDE_SPI = 0
endif
ifeq ($(MCAL_EXCLUDE_WDG),)
MCAL_EXCLUDE_WDG = 0
endif

#e.g.: LIBRARIES_TO_BUILD      +=    $(LIB_OUPUT_PATH)\vendorx_canlib1.$(LIB_FILE_SUFFIX)
LIBRARIES_TO_BUILD      +=

# e.g.: CC_FILES_TO_BUILD       += drv\can_drv.c

#Path to Mcal source and include files
MCAL_PATH_BASE = ..\ThirdParty\Mcal_Tc3xx\Supply\MC-ISAR_AS42x_AURIX2G_TC38xA_TC39xB_BASIC_1.0.0-rc
MCAL_PATH_CD = ..\ThirdParty\Mcal_Tc3xx\Supply\MC-ISAR_AS42x_AURIX2G_TC38xA_TC39xB_CD_1.0.0-rc
SEL_DERIV = TC39B

ifeq ($(SEL_DERIV),TC39B)
CC_INCLUDE_PATH += $(MCAL_PATH_BASE)\McIsar\Src\Infra_Prod\Sfr\TC39xB\_Reg
endif
ifeq ($(SEL_DERIV),TC38A)
CC_INCLUDE_PATH += $(MCAL_PATH_BASE)\McIsar\Src\Infra_Prod\Sfr\TC38xA\_Reg
endif

CC_INCLUDE_PATH += $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc
CC_INCLUDE_PATH += $(MCAL_PATH_BASE)\DemoWorkspace\McalDemo\$(SEL_DERIV)\0_Src\BaseSw\Infra\Autosar_Srv

CC_FILES_TO_BUILD += $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\McalLib\ssc\src\McalLib.c
CC_FILES_TO_BUILD += $(MCAL_PATH_BASE)\DemoWorkspace\McalDemo\$(SEL_DERIV)\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c

#IRQ
ifneq ($(MCAL_EXCLUDE_IRQ),1)

CC_INCLUDE_PATH += $(MCAL_PATH_BASE)\DemoWorkspace\McalDemo\$(SEL_DERIV)\0_Src\BaseSw\Infra\Integration
CC_INCLUDE_PATH += $(IRQ_BASE_PATH)\inc

MOD_IRQ_BASE_PATH = $(MCAL_PATH_BASE)\DemoWorkspace\McalDemo\$(SEL_DERIV)\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq
#Path to Irq source and include files
IRQ_BASE_PATH = $(MCAL_PATH_BASE)\DemoWorkspace\McalDemo\$(SEL_DERIV)\0_Src\BaseSw\Infra\Irq\ssc
CC_FILES_TO_BUILD  += $(IRQ_BASE_PATH)\src\Irq.c

#Path to <MSN>_Irq folders
MOD_CDD_IRQ_BASE_PATH = $(MCAL_PATH_CD)\DemoWorkspace\McalDemo\$(SEL_DERIV)\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq

endif
#End of IRQ

#ADC
ifneq ($(MCAL_EXCLUDE_ADC),1)
ADC_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Adc\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Adc_PBcfg.c
CC_FILES_TO_BUILD  += $(ADC_BASE_PATH)\src\Adc.c
CC_INCLUDE_PATH    += $(ADC_BASE_PATH)\inc

ifneq ($(MCAL_EXCLUDE_IRQ),1)
CC_FILES_TO_BUILD  += $(MOD_IRQ_BASE_PATH)\Adc_Irq\Adc_Irq.c
endif

endif
#End of ADC

#DIO
ifneq ($(MCAL_EXCLUDE_DIO),1)

DIO_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Dio\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Dio_Lcfg.c
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio.c
CC_INCLUDE_PATH    += $(DIO_BASE_PATH)\inc

endif
#End of DIO

#DMA
ifneq ($(MCAL_EXCLUDE_DMA),1)

DMA_BASE_PATH     = $(MCAL_PATH_CD)\McIsar\Src\Mcal\Tricore\Dma\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Dma_PBcfg.c
CC_FILES_TO_BUILD  += $(DMA_BASE_PATH)\src\Dma.c
CC_INCLUDE_PATH    += $(DMA_BASE_PATH)\inc

ifneq ($(MCAL_EXCLUDE_IRQ),1)
CC_FILES_TO_BUILD  += $(MOD_CDD_IRQ_BASE_PATH)\Dma_Irq\Dma_Irq.c
endif

endif
#End of DMA

#GPT
ifneq ($(MCAL_EXCLUDE_GPT),1)

GPT_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Gpt\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Gpt_PBcfg.c
CC_FILES_TO_BUILD  += $(GPT_BASE_PATH)\src\Gpt.c
CC_INCLUDE_PATH    += $(GPT_BASE_PATH)\inc

ifneq ($(MCAL_EXCLUDE_IRQ),1)
CC_FILES_TO_BUILD  += $(MOD_IRQ_BASE_PATH)\Gpt12_Irq\Gpt12_Irq.c
endif

endif
#End of GPT

#ICU
ifneq ($(MCAL_EXCLUDE_ICU),1)

ICU_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Icu_17_TimerIp\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Icu_17_TimerIp_PBcfg.c
CC_FILES_TO_BUILD  += $(ICU_BASE_PATH)\src\Icu_17_TimerIp.c
CC_INCLUDE_PATH    += $(ICU_BASE_PATH)\inc

endif
#End of ICU

#MCU
ifneq ($(MCAL_EXCLUDE_MCU),1)

MCU_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Mcu\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Mcu_17_TimerIp_Cfg.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Mcu_PBcfg.c
CC_FILES_TO_BUILD  += $(MCU_BASE_PATH)\src\Mcu.c
CC_FILES_TO_BUILD  += $(MCU_BASE_PATH)\src\Mcu_17_TimerIp.c
CC_INCLUDE_PATH    += $(MCU_BASE_PATH)\inc

ifneq ($(MCAL_EXCLUDE_IRQ),1)
CC_FILES_TO_BUILD  += $(MOD_IRQ_BASE_PATH)\Ccu6_Irq\Ccu6_Irq.c
CC_FILES_TO_BUILD  += $(MOD_IRQ_BASE_PATH)\Eru_Irq\Eru_Irq.c
CC_FILES_TO_BUILD  += $(MOD_IRQ_BASE_PATH)\Gtm_Irq\Gtm_Irq.c
endif

endif
#End of MCU

#PORT
ifneq ($(MCAL_EXCLUDE_PORT),1)
PORT_BASE_PATH    = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Port\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Port_PBcfg.c
CC_FILES_TO_BUILD  += $(PORT_BASE_PATH)\src\Port.c
CC_INCLUDE_PATH    += $(PORT_BASE_PATH)\inc
endif
#End of PORT

#PWM
ifneq ($(MCAL_EXCLUDE_PWM),1)

PWM_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Pwm_17_GtmCcu6\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Pwm_17_GtmCcu6_PBcfg.c
CC_FILES_TO_BUILD  += $(PWM_BASE_PATH)\src\Pwm_17_GtmCcu6.c
CC_INCLUDE_PATH    += $(PWM_BASE_PATH)\inc

endif
#End of PWM

#SPI
ifneq ($(MCAL_EXCLUDE_SPI),1)

SPI_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Spi\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Spi_PBcfg.c
CC_FILES_TO_BUILD  += $(SPI_BASE_PATH)\src\Spi.c
CC_INCLUDE_PATH    += $(SPI_BASE_PATH)\inc

ifneq ($(MCAL_EXCLUDE_IRQ),1)
CC_FILES_TO_BUILD  += $(MOD_IRQ_BASE_PATH)\Spi_Irq\Spi_Irq.c
endif

endif
#End of SPI

#WDG
ifneq ($(MCAL_EXCLUDE_WDG),1)

WDG_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Wdg_17_Scu\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg_17_Scu_PBcfg.c
CC_FILES_TO_BUILD  += $(WDG_BASE_PATH)\src\Wdg_17_Scu.c
CC_INCLUDE_PATH    += $(WDG_BASE_PATH)\inc

endif
#End of WDG

#FEE
ifneq ($(MCAL_EXCLUDE_FEE),1)

FEE_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Fee\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Fee_PBcfg.c
CC_FILES_TO_BUILD  += $(FEE_BASE_PATH)\src\Fee.c
CC_INCLUDE_PATH    += $(FEE_BASE_PATH)\inc

endif
#End of FEE

#FLS
ifneq ($(MCAL_EXCLUDE_FLS),1)

FLS_BASE_PATH     = $(MCAL_PATH_BASE)\McIsar\Src\Mcal\Tricore\Fls_17_Dmu\ssc
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Fls_17_Dmu_PBcfg.c
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls_17_Dmu.c
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls_17_Dmu_ac.c
CC_INCLUDE_PATH    += $(FLS_BASE_PATH)\inc

ifneq ($(MCAL_EXCLUDE_IRQ),1)
CC_FILES_TO_BUILD  += $(MOD_IRQ_BASE_PATH)\Fls_Irq\Fls_Irq.c
endif

endif
#End of FLS

CPP_FILES_TO_BUILD +=
ASM_FILES_TO_BUILD +=

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

# e.g.:  GENERATED_SOURCE_FILES += $(GENDATA_DIR)\drv_par.c
ADDITIONAL_INCLUDES     += $(GENDATA_DIR)\inc

#e.g.: COMMON_SOURCE_FILES     += $(GENDATA_DIR)\v_par.c
COMMON_SOURCE_FILES     +=

#-------------------------------------------------------------------------------------------------
# <project>.dep & <projekt>.lnk & <project>.bin and.....
# all in err\ & obj\ & lst\ & lib\ & log\ will be deleted by clean-rule automaticly
# so in this clean-rule it is only necessary to define additional files which
# were not delete automaticly.
# e.g.: $(<PATH>)\can_test.c
#-------------------------------------------------------------------------------------------------
MAKE_CLEAN_RULES        +=
#MAKE_GENERATE_RULES     +=
#MAKE_COMPILER_RULES     +=
#MAKE_DEBUG_RULES        +=
#MAKE_CONFIG_RULES       +=
#MAKE_ADD_RULES          +=


###############################################################
# REQUIRED   (defined in BaseMake (global.Makefile.target.make...))
#
# SSC_ROOT		(required)
# PROJECT_ROOT	(required)
#
# LIB_OUTPUT_PATH	(optional)
# OBJ_OUTPUT_PATH	(optional)
#
# OBJ_FILE_SUFFIX
# LIB_FILE_SUFFIX
#
###############################################################


###############################################################
# PROVIDE   this Section can be used to define own additional rules
#
# In vendorx_can_cfg.mak:
# Please configure the project file:
#CAN_CONFIG_FILE = $(PROJECT_ROOT)\source\network\can\my_can_config.cfg

#In vendorx_can_config :
#generate_can_config:
#$(SSC_ROOT)\core\com\can\tools\canconfiggen.exe -o $(CAN_CONFIG_FILE)


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the
# Rules-Makefile. Each author is free to create temporary
# variables or to use other resources of GNU-MAKE
#
###############################################################


