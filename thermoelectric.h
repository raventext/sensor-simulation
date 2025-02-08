#ifndef THERMOELECTRIC_H
#define THERMOELECTRIC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define THERMOELECTRIC_ACCURACY 2.5
#define THERMOELECTRIC_DRIFT 0.006
#define TEMP_MIN 0.0
#define TEMP_MAX 60.0

typedef struct {
    int id;
    char type[20];
    double last_reading;
} ThermoelectricSensor;

void init_thermoelectric(ThermoelectricSensor *sensor, int id);
double get_thermoelectric_reading(ThermoelectricSensor *sensor);

#endif
