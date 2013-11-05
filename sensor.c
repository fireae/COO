#include "sensor.h"

void sensor_init(Sensor *const me)
{}

void sensor_cleanup(Sensor *const me)
{}

int sensor_get_filter_frequency(const Sensor *const me)
{
	return me->filter_frequency;
}
int sensor_set_filter_frequency(Sensor *const me, int p_filter_frequency)
{
	me->filter_frequency = p_filter_frequency;
}
int sensor_get_update_frequency(const Sensor *const me)
{
	return me->update_frequency;
}
int sensor_set_update_frequency(Sensor const *me, int p_filter_frequency)
{
	me->update_frequency = p_filter_frequency;
}

int sensor_get_value(const Sensor *cons tme)
{
	return me->value;
}

Sensor *sensor_create(void)
{
	Sensor *me = (Sensor *)malloc(sizeof(Sensor));
	if (NULL != me)
	{
		sensor_init(me);
	}
	return me;
}

void sensor_destroy(Sensor *const me)
{
	if (NULL != me)
	{
		sensor_cleanup(me);
	}
	free(me);
}

