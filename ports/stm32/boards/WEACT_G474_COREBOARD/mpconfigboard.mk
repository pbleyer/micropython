# MCU settings
MCU_SERIES = g4
CMSIS_MCU = STM32G474xx
MICROPY_FLOAT_IMPL = single
AF_FILE = boards/stm32g474_af.csv
LD_FILES = boards/stm32g474.ld boards/common_basic.ld

MICROPY_HW_ENABLE_ISR_UART_FLASH_FUNCS_IN_RAM = 1

MICROPY_VFS_LFS2 = 1

ifdef SPI_FLASH_SIZE_MB
BUILD := $(BUILD)_FLASH_$(SPI_FLASH_SIZE_MB)M
endif

# No flash chip in default build - use internal flash
SPI_FLASH_SIZE_MB ?= 0

CFLAGS += -DMICROPY_HW_SPIFLASH_SIZE_BYTES="($(SPI_FLASH_SIZE_MB) * 1024 * 1024)"
