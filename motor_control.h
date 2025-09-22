#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

void stopMotors();
void setMotorSpeeds(int leftSpeed, int rightSpeed);
void executeManeuverStart(int direction);

#endif
