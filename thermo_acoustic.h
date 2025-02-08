#ifndef THERMO_ACOUSTIC_H
#define THERMO_ACOUSTIC_H

#include <stdio.h>
#include <stdlib.h>

#define THERMO_ACOUSTIC_ACCURACY 2.0
#define THERMO_ACOUSTIC_DRIFT 0.006

typedef struct {
    int id;
    char type[20];
    double last_reading;
} ThermoAcousticSensor;

void init_thermo_acoustic(ThermoAcousticSensor *sensor, int id);
double get_thermo_acoustic_reading(ThermoAcousticSensor *sensor);

#endif
