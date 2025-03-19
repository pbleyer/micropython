# MCU settings
MCU_SERIES = g4
CMSIS_MCU = STM32G474xx
MICROPY_FLOAT_IMPL = single
AF_FILE = boards/stm32g474_af.csv

MICROPY_HW_ENABLE_ISR_UART_FLASH_FUNCS_IN_RAM = 1
MICROPY_VFS_LFS2 ?= 1

ifdef SPI_FLASH_SIZE_MB
BUILD := $(BUILD)_FLASH_$(SPI_FLASH_SIZE_MB)M
endif

SPI_FLASH_SIZE_MB ?= 0

# Use external flash if size is specified
ifeq ($(SPI_FLASH_SIZE_MB),0)
MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE = 1
LD_FILES = boards/stm32g474.ld boards/common_basic.ld
else
MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE = 0

ifeq ($(SPI_FLASH_SIZE_MB),4)
MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 = 25
else ifeq ($(SPI_FLASH_SIZE_MB),8)
MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 = 26
else ifeq ($(SPI_FLASH_SIZE_MB),16)
MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 = 27
else
$(error Unsupported external Flash size)
endif

LD_FILES = boards/WEACT_G474_COREBOARD/g474_qspi.ld boards/common_basic.ld
CFLAGS += -DMICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2=$(MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2)
endif

CFLAGS += -DMICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE=$(MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE)
