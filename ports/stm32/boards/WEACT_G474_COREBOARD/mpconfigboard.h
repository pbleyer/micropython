#define MICROPY_HW_BOARD_NAME       "WEACT_G474_COREBOARD"
#define MICROPY_HW_MCU_NAME         "STM32G474"

#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1) // A4, A5
#define MICROPY_HW_ENABLE_USB       (1) // can be enabled if USB cable connected to PA11/PA12 (D-/D+)
#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1) // Export internal Flash

#define MICROPY_PY_ASYNCIO          (1)
#define MICROPY_PY_DEFLATE          (1)
#define MICROPY_PY_BINASCII         (1)
#define MICROPY_PY_HASHLIB          (0)
#define MICROPY_PY_JSON             (1)
#define MICROPY_PY_RE               (1)
#define MICROPY_PY_FRAMEBUF         (0)
#define MICROPY_PY_SOCKET           (0)
#define MICROPY_PY_NETWORK          (0)

// The board has an 8MHz HSE, the following gives 170MHz CPU speed
#define MICROPY_HW_CLK_PLLM         (2)
#define MICROPY_HW_CLK_PLLN         (85)
#define MICROPY_HW_CLK_PLLP         (2)
#define MICROPY_HW_CLK_PLLQ         (8)
#define MICROPY_HW_CLK_PLLR         (2)

#define MICROPY_HW_CLK_USE_HSI48    (1) // for RNG and USB

// RTC
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_8

// UART config
// #define MICROPY_HW_LPUART1_TX       (pin_A2)  // A2, B11 = QSPI_nCS
// #define MICROPY_HW_LPUART1_RX       (pin_A3)  // A3, B10 = QSPI_CLK
#define MICROPY_HW_UART1_TX         (pin_B6)  // A9, B6, C4
#define MICROPY_HW_UART1_RX         (pin_B7)  // A10, B7
// #define MICROPY_HW_UART2_TX       (pin_A2)  // A14, B3
// #define MICROPY_HW_UART2_RX       (pin_A3)  // A15, B4
// #define MICROPY_HW_UART2_RTS      (pin_A1)  // 
// #define MICROPY_HW_UART2_CTS      (pin_A0)  // 
// #define MICROPY_HW_UART3_TX         (pin_B10) // B9, B10, C10
// #define MICROPY_HW_UART3_RX         (pin_B11) // B8 = boot0, B11, C11
// #define MICROPY_HW_UART3_RTS      (pin_B14) // 
// #define MICROPY_HW_UART3_CTS      (pin_B13) // A13
// #define MICROPY_HW_UART4_TX       (pin_)    // C10
// #define MICROPY_HW_UART4_RX       (pin_)    // C11

#define MICROPY_HW_ENABLE_UART_REPL (0) // REPL only on USB
// #define MICROPY_HW_UART_REPL        (PYB_LPUART_1) // default on Nucleo G474
// #define MICROPY_HW_UART_REPL_BAUD   (115200)

// I2C buses
#define MICROPY_HW_I2C1_SCL         (pin_B8) // A13, A15, B8 (=boot0)
#define MICROPY_HW_I2C1_SDA         (pin_B9) // A14, B7, B9
#define MICROPY_HW_I2C2_SCL       (pin_A9)   // A9, C4
#define MICROPY_HW_I2C2_SDA       (pin_A8)   // A8
// #define MICROPY_HW_I2C3_SCL       (pin_)   // A8
// #define MICROPY_HW_I2C3_SDA       (pin_)   // B5, C9, C11

// SPI
// QSPI FLASH (BK1): nCS=B11 IO0=B1 IO1=B0 IO2=A7 IO3=A6 CLK=B10
#define MICROPY_HW_SPI1_NSS         (pin_A15) // A4, A15 (Nucleo64 specifies B6 as pin CS, must be done as GPIO, not as AF)
#define MICROPY_HW_SPI1_SCK         (pin_B3) // A5, B3 (SWO)
#define MICROPY_HW_SPI1_MISO        (pin_B4) // A6, B4
#define MICROPY_HW_SPI1_MOSI        (pin_B5) // A7, B5
#define MICROPY_HW_SPI2_NSS       (pin_B12)   // B12
#define MICROPY_HW_SPI2_SCK       (pin_B13)   // B13
#define MICROPY_HW_SPI2_MISO      (pin_B14)   // A10, B14
#define MICROPY_HW_SPI2_MOSI      (pin_B15)   // A11, B15
// #define MICROPY_HW_SPI3_NSS       (pin_)   // A4, A15
// #define MICROPY_HW_SPI3_SCK       (pin_)   // B3, C10
// #define MICROPY_HW_SPI3_MISO      (pin_)   // B4, C11
// #define MICROPY_HW_SPI3_MOSI      (pin_)   // B5

// USRSW is pulled low. Pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN        (pin_C13)
#define MICROPY_HW_USRSW_PULL       (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED    (1)

// LEDs
#define MICROPY_HW_LED1             (pin_C6)    // blue
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

// USB
#define MICROPY_HW_USB_FS              (1)
// #define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
// #define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)

// FDCAN bus
// User TODO: fit transceiver chip
// #define MICROPY_HW_CAN1_NAME        "FDCAN1"
// #define MICROPY_HW_CAN1_TX          (pin_A12) // A12, B9, D1
// #define MICROPY_HW_CAN1_RX          (pin_A11) // A11, B8, D0

#if !MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE

#define MICROPY_HW_SPIFLASH_ENABLE_CACHE (1)

// #define MICROPY_BOARD_EARLY_INIT board_early_init
// void board_early_init(void);

extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;

#define MICROPY_HW_BDEV_SPIFLASH_CONFIG (&spiflash_config)
#define MICROPY_HW_BDEV_SPIFLASH (&spi_bdev)
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev) // for extended block protocol
#define MICROPY_HW_BDEV_SPIFLASH_SIZE_BYTES (1 << (MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 - 3))

// QSPI flash configuration
#define MICROPY_HW_QSPI_PRESCALER (2) // 85MHz @ 170MHz HCLK
#define MICROPY_HW_QSPIFLASH_CS (pyb_pin_QSPI1_CS)
#define MICROPY_HW_QSPIFLASH_SCK (pyb_pin_QSPI1_SCK)
#define MICROPY_HW_QSPIFLASH_IO0 (pyb_pin_QSPI1_IO0)
#define MICROPY_HW_QSPIFLASH_IO1 (pyb_pin_QSPI1_IO1)
#define MICROPY_HW_QSPIFLASH_IO2 (pyb_pin_QSPI1_IO2)
#define MICROPY_HW_QSPIFLASH_IO3 (pyb_pin_QSPI1_IO3)

#define STATIC_AF_QUADSPI_BK1_NCS STATIC_AF_QUADSPI1_BK1_NCS
#define STATIC_AF_QUADSPI_CLK STATIC_AF_QUADSPI1_CLK
#define STATIC_AF_QUADSPI_BK1_IO0 STATIC_AF_QUADSPI1_BK1_IO0
#define STATIC_AF_QUADSPI_BK1_IO1 STATIC_AF_QUADSPI1_BK1_IO1
#define STATIC_AF_QUADSPI_BK1_IO2 STATIC_AF_QUADSPI1_BK1_IO2
#define STATIC_AF_QUADSPI_BK1_IO3 STATIC_AF_QUADSPI1_BK1_IO3
#endif
