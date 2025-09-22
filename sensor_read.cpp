#include <Arduino.h>
#include "sensor_read.h"

extern const uint8_t IR_PINS[8];
extern const uint16_t SENSOR_THRESH, ENDZONE_THRESH, INTERSECTION_THRESH, NOISE_FILTER;

int16_t sensors[8];
int16_t filteredSensors[8];

void readIRSensors() {
    for (uint8_t i = 0; i < 8; i++) {
        int16_t raw = analogRead(IR_PINS[i]);
        sensors[i] = raw;
        filteredSensors[i] = (raw > NOISE_FILTER) ? raw : 0;
    }
}

bool isLineDetected() {
    for (uint8_t i = 0; i < 8; i++) if (filteredSensors[i] > SENSOR_THRESH) return true;
    return false;
}

// (add detectIntersection, detectEndZone, calculateError, getLineConfidence here)
