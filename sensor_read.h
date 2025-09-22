#ifndef SENSOR_READ_H
#define SENSOR_READ_H

void readIRSensors();
bool isLineDetected();
bool detectIntersection();
bool detectEndZone();
float calculateError();
float getLineConfidence();

#endif
