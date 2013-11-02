#ifndef _SENSOR_H
#define _SENSOR_H

typdef struct Sensor Sensor;
struct Sensor{
	int filter_frequency;
	int update_frequency;
	int value;
};

int sensor_get_filter_frequency(const Sensor *const me);
int sensor_set_filter_frequency(Sensor *const me, int p_filter_frequency);

int sensor_get_update_frequency(const Sensor *const me);
int sensor_set_update_frequency(Sensor const *me, int p_filter_frequency);

int sensor_get_value(const Sensor *cons tme);

Sensor *sensor_create(void);

void sensor_destroy(Sensor *const me);

#endif /* _SENSOR_H */