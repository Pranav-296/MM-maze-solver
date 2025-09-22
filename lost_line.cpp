#include <Arduino.h>
#include "lost_line.h"
#include "motor_control.h"

extern const int SEARCH_SPEED;
extern int lastKnownDirection;

void handleLostLine() {
    static unsigned long lostTime = 0;
    if (lostTime == 0) lostTime = millis();

    unsigned long timeLost = millis() - lostTime;

    if (timeLost < 300) {
        int searchDirection = ((timeLost / 100) % 2 == 0) ? 1 : -1;
        searchDirection *= (lastKnownDirection > 0) ? 1 : -1;
        if (searchDirection > 0) setMotorSpeeds(SEARCH_SPEED, SEARCH_SPEED / 3);
        else setMotorSpeeds(SEARCH_SPEED / 3, SEARCH_SPEED);
    } else {
        stopMotors();
        lostTime = 0;
    }
}
