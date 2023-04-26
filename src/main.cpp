#include <Arduino.h>

//#define SENSOR_PIN A0 // Arduino Uno
#define SENSOR_PIN 27// ESP32

const int ADC_MAX = 352 * 10; // 空気中の実測値
const int ADC_MIN = 159 * 10; // 水に浸した実測値


void setup() {
    Serial.begin(115200);
    pinMode(SENSOR_PIN, INPUT);
    delay(3000);
}

void loop() {
    int val = analogRead(SENSOR_PIN);
    Serial.println("ESP32 val");
    Serial.println(val);

    if (ADC_MAX < val) {
        val = ADC_MAX;
    }
    else if (ADC_MIN > val) {
        val = ADC_MIN;
    }

    int moisture = 100 - map(val, ADC_MIN, ADC_MAX, 0, 100);

    // 水に使っていない時が 0
    Serial.println("ESP32 moisture");
    Serial.println(moisture);
    delay(1000);
}
