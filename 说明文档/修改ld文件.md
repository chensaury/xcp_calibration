### 对于 RAM  (`S32K142_32_ram.ld) 的链接器脚本：

1. **调整现有的 RAM 区域**：从 `m_data` 区域中划分出一部分作为 `xcpram`
2. **定义新的 RAM 区域**：在 `MEMORY` 部分添加 `xcpram_**`

```ld
/* 在 MEMORY 部分添加 xcpram 定义 */
MEMORY
{
  /* SRAM_L */
  m_interrupts          (RX)  : ORIGIN = 0x1FFFC000, LENGTH = 0x00000400
  m_text                (RX)  : ORIGIN = 0x1FFFC400, LENGTH = 0x00003C00

  /* SRAM_U */
  m_data                (RW)  : ORIGIN = 0x20000000, LENGTH = 0x00002000
  xcp_mes 				(RW)  : ORIGIN = 0x20002000, LENGTH = 0x00000800  /* 假设的起始地址和长度 */
  xcp_cal 				(RW)  : ORIGIN = 0x20003000, LENGTH = 0x00000800  /* 假设的起始地址和长度 */
}
```

3. **在 SECTIONS 中创建新的 RAM 节**：在 `SECTIONS` 部分添加 `.xcpram_**` 节，并将初始化数据放在 `.text` 节之后。

```ld
/* 在 SECTIONS 部分添加 .xcpram 节 */
.xcp_mes :
{
    . = ALIGN(4);
    __xcp_mes_start__ = .;
    *(.xcp_mes)
    . = ALIGN(4);
    __xcp_mes_end__ = .;
} > xcp_mes

.xcp_cal :
{
    . = ALIGN(4);
    __xcp_cal_start__ = .;
    *(.xcp_cal)
    . = ALIGN(4);
    __xcp_cal_end__ = .;
} > xcp_cal
```

### 对于 Flash  (`S32K142_32_flash.ld）接器脚本：

1. **调整现有的 Flash 区域**：从 `m_text` 区域中划分出一部分作为 `xcpflash`
2. **定义新的 Flash 区域**：在 `MEMORY` 部分添加 `xcpflash`

```ld
/* 在 MEMORY 部分添加 xcpflash 定义 */
/* Specify the memory areas */
MEMORY
{
  /* Flash */
  m_interrupts          (RX)  : ORIGIN = 0x00000000, LENGTH = 0x00000400
  m_flash_config        (RX)  : ORIGIN = 0x00000400, LENGTH = 0x00000010
  m_text                (RX)  : ORIGIN = 0x00000410, LENGTH = 0x00030000
  xcp_cal_rp              	(RX)  : ORIGIN = 0x00030410, LENGTH = 0x00000800  /* 假设的起始地址和长度 */

  /* SRAM_L */
  m_data                (RW)  : ORIGIN = 0x1FFFC000, LENGTH = 0x00003400

  /* SRAM_U */
  m_data_2              (RW)  : ORIGIN = 0x20000000, LENGTH = 0x00003000
  xcp_cal_wp			(RW)  : ORIGIN = 0x20002000, LENGTH = 0x00000800  /* 假设的起始地址和长度 */
  xcp_mes 	 			(RW)  : ORIGIN = 0x20003000, LENGTH = 0x00000800  /* 假设的起始地址和长度 */
}

```

3. **在 SECTIONS 中创建新的 Flash 节**：在 `SECTIONS` 部分添加 `.xcpflash` 节。

```ld
/* 在 SECTIONS 部分添加 .xcpram 节 */
.xcp_mes :
{
    . = ALIGN(4);
    __xcp_mes_start__ = .;
    *(.xcp_mes)
    . = ALIGN(4);
    __xcp_mes_end__ = .;
} > xcp_mes

.xcp_cal_wp :
{
    . = ALIGN(4);
    __xcp_cal_wp_start__ = .;
    *(.xcp_cal)
    . = ALIGN(4);
    __xcp_cal_wp_end__ = .;
} > xcp_cal_wp AT > xcp_cal_rp

/* 在 SECTIONS 部分添加 .xcpflash 节 */
.xcp_cal_rp :
{
    KEEP(*(.xcp_cal))  /* 保留 .xcpflash 节中的所有内容 */
} > xcp_cal_rp 
```

### 启动代码：

```c
void CopyXcpFlashToXcpRam(void) {
    uint32_t *src = (uint32_t *)__xcp_cal_rp_start__;
    uint32_t *dst = (uint32_t *)__xcp_cal_wp_start__;
    uint32_t *end = (uint32_t *)__xcp_cal_rp_end__;
    while (src < end) {
        *dst++ = *src++;
    }
}
```

此函数应在`main`函数之前调用，以确保在程序开始执行之前，数据从Flash复制到RAM







### C 源文件中的变量声明：

在 C 源文件中，使用 `__attribute__` 来指定变量

```c
/* 在 C 源文件中声明变量 */
int __attribute__((section(".xcpram"))) myVariable = 10;  /* 变量及其初始值放在 xcpram */
```



### 使用__declspec

在C源文件中，使用`__declspec`或`#pragma`指令将变量的初始化部分放在Flash中的特定节。

```c
__declspec(section ".xcpram") int myVariable = 10;
```















