#ifndef THERMORESISTIVE_H
#define THERMORESISTIVE_H

#include <stdio.h>
#include <stdlib.h>

#define THERMORESISTIVE_ACCURACY 1.0
#define THERMORESISTIVE_DRIFT 0.006

typedef struct {
    int id;
    char type[20];
    double last_reading;
} ThermoresistiveSensor;

void init_thermoresistive(ThermoresistiveSensor *sensor, int id);
double get_thermoresistive_reading(ThermoresistiveSensor *sensor);

#endif
