#include <Arduino.h>
#include "core/bus_HAL.h"
#include "core/powerSave.h"

// Настоящие функции ядра ESP32, которые мы вызовем, если пин нормальный
extern void real_pinMode(uint8_t pin, uint8_t mode) __attribute__((alias("pinMode")));
extern void real_digitalWrite(uint8_t pin, uint8_t val) __attribute__((alias("digitalWrite")));

// Наша жесткая защита от пина 255 прямо в коде борды
extern "C" void pinMode(uint8_t pin, uint8_t mode) {
    if (pin == 255 || pin == 0xFF) return; // Игнорируем говнопин
    real_pinMode(pin, mode);
}

extern "C" void digitalWrite(uint8_t pin, uint8_t val) {
    if (pin == 255 || pin == 0xFF) return; // Игнорируем говнопин
    real_digitalWrite(pin, val);
}

/***************************************************************************************
** Function name: _setup_gpio()
** Description:   начальная настройка периферии устройства
***************************************************************************************/
void _setup_gpio() {
    // Безопасная настройка пина NRF24
    if (NRF24_SS_PIN != -1 && NRF24_SS_PIN != 255) {
        pinMode(NRF24_SS_PIN, OUTPUT);
        digitalWrite(NRF24_SS_PIN, HIGH);
    }

    // Безопасная настройка пина CC1101
    #ifdef CC1101_SS_PIN
    if (CC1101_SS_PIN != -1 && CC1101_SS_PIN != 255) {
        pinMode(CC1101_SS_PIN, OUTPUT);
        digitalWrite(CC1101_SS_PIN, HIGH);
    }
    #endif

    bruceConfigPins.rfModule = NRF24_SPI_MODULE; 
    bruceConfigPins.irRx = RXLED;
}

int getBattery() {
    return 100; // Стабильные 100% заряда
}

void initVariant() {
    // Пусто, чтобы убрать ранний краш кнопок
}
