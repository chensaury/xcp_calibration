# xcp_calibration
xcp标定

1、主分支包含xcp_ok_demo和标定文件夹，其中xcp_ok_demo控制器为TC397，工具使用canape。文件夹的tree在后，

2、标定文件夹，包含各种工程，不同的可移植协议

3、其他文档
XCP_ReferenceBook_V3.0_EN.pdf

XCP_Use_Cases.pdf

UserManual_AUTOSAR_Calibration.pdf  标定

看懂XCP协议.md





├─XCP_OK_DEMO
│  ├─Bsw_Project
│  │  ├─Appl
│  │  │  ├─GenData
│  │  │  │  ├─Components
│  │  │  │  ├─ContractPhase
│  │  │  │  │  ├─BswM
│  │  │  │  │  ├─Can
│  │  │  │  │  ├─CanIf
│  │  │  │  │  ├─CanSM
│  │  │  │  │  ├─Com
│  │  │  │  │  ├─ComM
│  │  │  │  │  ├─Det
│  │  │  │  │  ├─Dio
│  │  │  │  │  ├─EcuM
│  │  │  │  │  ├─McalLib
│  │  │  │  │  ├─Mcu
│  │  │  │  │  ├─PduR
│  │  │  │  │  └─Port
│  │  │  │  ├─inc
│  │  │  │  ├─mak
│  │  │  │  ├─RteAnalyzer
│  │  │  │  │  └─Source
│  │  │  │  ├─RteCache
│  │  │  │  │  └─504704712
│  │  │  │  └─src
│  │  │  └─Source
│  │  │      ├─Core0Swc
│  │  │      ├─Core1Swc
│  │  │      ├─Core2Swc
│  │  │      ├─Core3Swc
│  │  │      ├─Core4Swc
│  │  │      └─Core5Swc
│  │  ├─Config
│  │  │  ├─AUTOSAR
│  │  │  ├─Developer
│  │  │  │  ├─ComponentTypes
│  │  │  │  └─ECUProjects
│  │  │  ├─ECUC
│  │  │  ├─InternalBehavior
│  │  │  ├─McData
│  │  │  ├─ServiceComponents
│  │  │  └─System
│  │  └─Log
│  │      ├─GenerationReport_202303212054
│  │      ├─GenerationReport_202303212107
│  │      ├─GenerationReport_202303212113
│  │      ├─GenerationReport_202304072129
│  │      ├─GenerationReport_202304072137
│  │      ├─GenerationReport_202304072143
│  │      ├─GenerationReport_202304072147
│  │      ├─GenerationReport_202304072150
│  │      ├─GenerationReport_202304072152
│  │      ├─GenerationReport_202304112023
│  │      ├─GenerationReport_202304112024
│  │      ├─GenerationReport_202304112103
│  │      ├─GenerationReport_202304112104
│  │      ├─GenerationReport_202304112119
│  │      ├─GenerationReport_202304132130
│  │      ├─GenerationReport_202304132132
│  │      ├─GenerationReport_202304132133
│  │      ├─GenerationReport_202304132137
│  │      ├─GenerationReport_202304132150
│  │      ├─GenerationReport_202304132153
│  │      ├─GenerationReport_202304132154
│  │      ├─GenerationReport_202304132202
│  │      ├─GenerationReport_202304132203
│  │      ├─GenerationReport_202304132206
│  │      ├─GenerationReport_202304132213
│  │      ├─GenerationReport_202304221946
│  │      ├─GenerationReport_202305242020
│  │      ├─UpdateReport_202303212003
│  │      └─UpdateReport_202305242004
│  ├─MCAL_Project
│  │  ├─.prefs
│  │  ├─config
│  │  └─output
│  │      └─generated
│  │          ├─inc
│  │          └─src
│  └─Tasking_IDE_project
│      ├─Appl
│      │  ├─GenData
│      │  │  ├─Components
│      │  │  ├─ContractPhase
│      │  │  │  ├─BswM
│      │  │  │  ├─Can
│      │  │  │  ├─CanIf
│      │  │  │  ├─CanSM
│      │  │  │  ├─Com
│      │  │  │  ├─ComM
│      │  │  │  ├─Det
│      │  │  │  ├─Dio
│      │  │  │  ├─EcuM
│      │  │  │  ├─McalLib
│      │  │  │  ├─Mcu
│      │  │  │  ├─PduR
│      │  │  │  └─Port
│      │  │  ├─inc
│      │  │  ├─mak
│      │  │  ├─RteAnalyzer
│      │  │  │  └─Source
│      │  │  ├─RteCache
│      │  │  │  └─504704712
│      │  │  └─src
│      │  └─Source
│      │      ├─Core0Swc
│      │      ├─Core1Swc
│      │      ├─Core2Swc
│      │      ├─Core3Swc
│      │      ├─Core4Swc
│      │      └─Core5Swc
│      ├─BSW
│      │  ├─BswM
│      │  │  └─mak
│      │  ├─Can
│      │  │  └─mak
│      │  ├─CanIf
│      │  │  └─mak
│      │  ├─CanSM
│      │  │  └─mak
│      │  ├─CanXcp
│      │  │  └─mak
│      │  ├─Com
│      │  │  └─mak
│      │  ├─ComM
│      │  │  └─mak
│      │  ├─Det
│      │  │  └─mak
│      │  ├─EcuM
│      │  │  └─mak
│      │  ├─Mcal_Tc3xx
│      │  │  └─mak
│      │  ├─Os
│      │  │  └─mak
│      │  ├─PduR
│      │  │  └─mak
│      │  ├─VStdLib
│      │  │  └─mak
│      │  ├─Xcp
│      │  │  └─mak
│      │  └─_Common
│      ├─Debug
│      ├─Include
│      ├─Main_C
│      └─MCAL
│          ├─Infra_Prod
│          │  ├─Platform
│          │  └─Sfr
│          │      └─TC39xB
│          │          └─_Reg
│          └─Mcal
│              └─Tricore
│                  ├─Dio
│                  │  └─ssc
│                  │      ├─inc
│                  │      └─src
│                  ├─McalLib
│                  │  └─ssc
│                  │      ├─inc
│                  │      │  ├─dcc
│                  │      │  └─gnu
│                  │      └─src
│                  ├─Mcu
│                  │  └─ssc
│                  │      ├─inc
│                  │      └─src
│                  └─Port
│                      └─ssc
│                          ├─inc
│                          └─src
└─标定
    ├─CCP
    │  └─CCP_协议栈
    │      ├─CANDRV
    │      ├─CCPLOG
    │      │  └─SOURCE
    │      ├─CCPMON
    │      ├─CCPSIM
    │      │  └─SOURCE
    │      ├─DOC
    │      └─SAMPLES
    │          ├─C16X
    │          │  └─CCP_TEST
    │          │      ├─CANAPE
    │          │      ├─INCLUDE
    │          │      └─SOURCE
    │          └─HC12
    │              └─CCP_TEST
    │                  ├─.vscode
    │                  ├─CANAPE
    │                  ├─INCLUDE
    │                  └─SOURCE
    └─XCP
        ├─Vector_XCP_Basic
        │  ├─Doc
        │  │  ├─Specification
        │  │  │  ├─Version 1.0
        │  │  │  └─Version 1.1
        │  │  └─XCP_Dokumentation
        │  ├─EULA
        │  ├─Samples
        │  │  ├─CAN
        │  │  │  ├─CAN MPC55xx
        │  │  │  │  └─XCPDemo
        │  │  │  │      ├─CANape
        │  │  │  │      └─CANape VX
        │  │  │  └─CAN Tricore
        │  │  │      └─XCPDemo
        │  │  │          ├─CANape
        │  │  │          └─CANape VX
        │  │  ├─RS232
        │  │  │  └─CANape
        │  │  ├─SPI
        │  │  │  └─CANape
        │  │  └─XCPsim
        │  │      └─CANape
        │  └─XCP Basic Driver
        └─XCP_TO_TC277