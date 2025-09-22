#include "pid_control.h"

extern float Kp, Ki, Kd;
float integral = 0.0f;
float lastError = 0.0f;

float computePID(float error, float dt, float confidence) {
    integral += error * dt * confidence;
    integral = constrain(integral, -50.0f, 50.0f);
    float derivative = (error - lastError) / dt;
    lastError = error;
    return (Kp * error + Ki * integral + Kd * derivative) * confidence;
}
