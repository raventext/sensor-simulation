#ifndef THERMO_OPTICAL_H
#define THERMO_OPTICAL_H

#include <stdio.h>
#include <stdlib.h>

#define THERMO_OPTICAL_ACCURACY 1.5
#define THERMO_OPTICAL_DRIFT 0.006

typedef struct {
    int id;
    char type[20];
    double last_reading;
} ThermoOpticalSensor;

void init_thermo_optical(ThermoOpticalSensor *sensor, int id);
double get_thermo_optical_reading(ThermoOpticalSensor *sensor);

#endif
