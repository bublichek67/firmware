#include <Arduino.h>
#include <FS.h>
#include <functional>

// Точные типы функций микрофона для успешной линковки Bruce Firmware
bool InitI2SMicroPhone() { return false; }
void mic_test() { return; }
void mic_record_app() { return; }

bool mic_capture_samples(uint32_t sample_rate, uint32_t channels, float duration, int16_t** buffer, uint32_t* out_samples) {
    if (out_samples) *out_samples = 0;
    return false;
}

bool mic_record_wav_to_path(fs::FS &fs, const String &path, uint32_t duration_ms, float gain, uint32_t* out_samples, std::function<bool()> check_cancel) {
    if (out_samples) *out_samples = 0;
    return false;
}

