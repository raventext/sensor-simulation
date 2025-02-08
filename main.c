#include "thermoelectric.h"
#include "thermoresistive.h"
#include "thermo_optical.h"
#include "thermo_acoustic.h"

#define NUM_READINGS 12
#define FAN_ON_THRESHOLD 35.0
#define HEATER_ON_THRESHOLD 6.0

// Generate random temperature within accuracy limits
double generate_temperature(double accuracy) {
    return (rand() % (int)(TEMP_MAX - TEMP_MIN)) + TEMP_MIN + ((rand() / (double)RAND_MAX) * (2 * accuracy) - accuracy);
}

// Sensor Initialization Functions
void init_thermoelectric(ThermoelectricSensor *sensor, int id) {
    sensor->id = id;
    strcpy(sensor->type, "Thermoelectric");
    sensor->last_reading = 0;
}

void init_thermoresistive(ThermoresistiveSensor *sensor, int id) {
    sensor->id = id;
    strcpy(sensor->type, "Thermoresistive");
    sensor->last_reading = 0;
}

void init_thermo_optical(ThermoOpticalSensor *sensor, int id) {
    sensor->id = id;
    strcpy(sensor->type, "Thermo-Optical");
    sensor->last_reading = 0;
}

void init_thermo_acoustic(ThermoAcousticSensor *sensor, int id) {
    sensor->id = id;
    strcpy(sensor->type, "Thermo-Acoustic");
    sensor->last_reading = 0;
}

// Sensor Data Retrieval Functions
double get_thermoelectric_reading(ThermoelectricSensor *sensor) {
    sensor->last_reading = generate_temperature(THERMOELECTRIC_ACCURACY);
    return sensor->last_reading;
}

double get_thermoresistive_reading(ThermoresistiveSensor *sensor) {
    sensor->last_reading = generate_temperature(THERMORESISTIVE_ACCURACY);
    return sensor->last_reading;
}

double get_thermo_optical_reading(ThermoOpticalSensor *sensor) {
    sensor->last_reading = generate_temperature(THERMO_OPTICAL_ACCURACY);
    return sensor->last_reading;
}

double get_thermo_acoustic_reading(ThermoAcousticSensor *sensor) {
    sensor->last_reading = generate_temperature(THERMO_ACOUSTIC_ACCURACY);
    return sensor->last_reading;
}

int main() {
    srand(time(0));

    ThermoelectricSensor thermo;
    ThermoresistiveSensor resistive;
    ThermoOpticalSensor optical;
    ThermoAcousticSensor acoustic;

    init_thermoelectric(&thermo, 1);
    init_thermoresistive(&resistive, 2);
    init_thermo_optical(&optical, 3);
    init_thermo_acoustic(&acoustic, 4);

    FILE *file = fopen("sensor_data.csv", "w");
    fprintf(file, "Reading,Thermoelectric,Thermoresistive,Thermo-Optical,Thermo-Acoustic,Average,Action\n");

    for (int i = 0; i < NUM_READINGS; i++) {
        double t1 = get_thermoelectric_reading(&thermo);
        double t2 = get_thermoresistive_reading(&resistive);
        double t3 = get_thermo_optical_reading(&optical);
        double t4 = get_thermo_acoustic_reading(&acoustic);

        double avg_temp = (t1 + t2 + t3 + t4) / 4;
        char *action = "No Action";
        if (avg_temp > FAN_ON_THRESHOLD) action = "Fan ON";
        else if (avg_temp < HEATER_ON_THRESHOLD) action = "Heater ON";

        fprintf(file, "%d,%.2f,%.2f,%.2f,%.2f,%.2f,%s\n", i+1, t1, t2, t3, t4, avg_temp, action);
    }

    fclose(file);
    printf("Simulation completed. Check sensor_data.csv.\n");
    return 0;
}
