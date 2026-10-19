#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "soc/soc_caps.h"
#include <stdint.h>

// Явно объявляем стандартные пины I2C для библиотеки Wire
#define SDA 47
#define SCL 48

// Базовая шина SPI (Общая для экрана, тача, SD и NRF24)
static const uint8_t SS = 7;
static const uint8_t MOSI = 17;
static const uint8_t MISO = 8;
static const uint8_t SCK = 18;

#define SPI_SCK_PIN 18
#define SPI_MOSI_PIN 17
#define SPI_MISO_PIN 8
#define SPI_SS_PIN 7

// Безопасный UART (пины 1 и 2 освобождены от конфликтов)
#define SERIAL_RX 44  
#define SERIAL_TX 43
#define BAD_RX SERIAL_RX
#define BAD_TX SERIAL_TX
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX
#define USB_as_HID 1

// Навигация будет через ТАЧСКРИН, физические кнопки отключены
#define BTN_ALIAS "\"OK\""
#define BTN_ACT LOW

#define RXLED 4
#define TXLED 5
#define LED_ON HIGH
#define LED_OFF LOW

// Конфигурация NRF24L01 (Пин 14 теперь полностью свободен для радио!)
#define USE_NRF24_VIA_SPI
#define NRF24_CE_PIN 21
#define NRF24_SS_PIN 14
#define NRF24_MOSI_PIN SPI_MOSI_PIN
#define NRF24_SCK_PIN SPI_SCK_PIN
#define NRF24_MISO_PIN SPI_MISO_PIN

// Параметры твоего экрана ILI9341 (240x320)
#define HAS_SCREEN 1
#define ROTATION 1
#define MINBRIGHT (uint8_t)1

#define USER_SETUP_LOADED 1
#define ILI9341_DRIVER 1
#define TFT_RGB_ORDER 0
#define TFT_WIDTH 240
#define TFT_HEIGHT 320
#define TFT_BACKLIGHT_ON 1
#define TFT_BL 6
#define TFT_RST 16
#define TFT_DC 15
#define TFT_MISO 8
#define TFT_MOSI 17
#define TFT_SCLK 18
#define TFT_CS 7
#define TOUCH_CS 32  // Тач работает отдельно на GPIO 32
#define SMOOTH_FONT 1
#define SPI_FREQUENCY 20000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000

// SD-карта (Если будет использоваться)
#define SDCARD_CS 3
#define SDCARD_SCK 18
#define SDCARD_MISO 8
#define SDCARD_MOSI 17

// Шина I2C
#define GROVE_SDA 47
#define GROVE_SCL 48
#define SYS_I2C_SDA 47
#define SYS_I2C_SCL 48

// Встроенный NeoPixel светодиод (если есть на плате)
#define HAS_RGB_LED 1
#define RGB_LED 45
#define LED_TYPE WS2812B
#define LED_ORDER GRB
#define LED_TYPE_IS_RGBW 0
#define LED_COUNT 16
#define LED_COLOR_STEP 15

// Отключаем неиспользуемый трансивер CC1101
#define CC1101_SS_PIN   -1
#define CC1101_GDO0_PIN -1
#define CC1101_GDO2_PIN -1

// Отключаем физические кнопки (управление строго через тач)
#define BUTTON_UP_PIN    -1
#define BUTTON_DOWN_PIN  -1
#define BUTTON_LEFT_PIN  -1
#define BUTTON_RIGHT_PIN -1
#define BUTTON_ACT_PIN   -1

// Отключаем пин прерывания отсутствующей микросхемы питания BQ25896
#define PMIC_INT_PIN     -1

#endif /* Pins_Arduino_h */
