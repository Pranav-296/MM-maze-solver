#include <Arduino.h>
#include "motor_control.h"

extern const int MAX_SPEED, TURN_SPEED;
extern const uint8_t MOTOR_LEFT_IN1, MOTOR_LEFT_IN2, MOTOR_RIGHT_IN1, MOTOR_RIGHT_IN2;
extern const uint8_t PWM_CH_L, PWM_CH_R;

void stopMotors() {
    ledcWrite(PWM_CH_L, 0);
    ledcWrite(PWM_CH_R, 0);
    digitalWrite(MOTOR_LEFT_IN1, LOW); digitalWrite(MOTOR_LEFT_IN2, LOW);
    digitalWrite(MOTOR_RIGHT_IN1, LOW); digitalWrite(MOTOR_RIGHT_IN2, LOW);
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    leftSpeed = constrain(leftSpeed, -MAX_SPEED, MAX_SPEED);
    rightSpeed = constrain(rightSpeed, -MAX_SPEED, MAX_SPEED);

    if (leftSpeed >= 0) { digitalWrite(MOTOR_LEFT_IN1, HIGH); digitalWrite(MOTOR_LEFT_IN2, LOW); }
    else { digitalWrite(MOTOR_LEFT_IN1, LOW); digitalWrite(MOTOR_LEFT_IN2, HIGH); }

    if (rightSpeed >= 0) { digitalWrite(MOTOR_RIGHT_IN1, HIGH); digitalWrite(MOTOR_RIGHT_IN2, LOW); }
    else { digitalWrite(MOTOR_RIGHT_IN1, LOW); digitalWrite(MOTOR_RIGHT_IN2, HIGH); }

    ledcWrite(PWM_CH_L, abs(leftSpeed));
    ledcWrite(PWM_CH_R, abs(rightSpeed));
}

void executeManeuverStart(int direction) {
    switch (direction) {
        case 0: setMotorSpeeds(-TURN_SPEED, TURN_SPEED); break;  // Left
        case 2: setMotorSpeeds(TURN_SPEED, -TURN_SPEED); break;  // Right
        case 1: setMotorSpeeds(180, 180); break;                 // Straight
        case 3: setMotorSpeeds(-TURN_SPEED, TURN_SPEED); break;  // Back
    }
}
