#include "channel.h"
#include <iostream>
#include <stdexcept>

#ifndef DATA_HELPER_H
#define DATA_HELPER_H


double celsius_to_fahrenheit(double temp);

double celsius_to_kelvin(double temp);

double kelvin_to_fahrenheit(double temp);

double kelvin_to_celsius(double temp);

double fahrenheit_to_celsius(double temp);

double fahrenheit_to_kelvin(double temp);

double pascal_to_bar(double pressure);

double bar_to_pascal(double pressure);

double linear_approximation(double time1, double data1, double time2, double data2, double expected_time);


void conversion(struct channel *channel, unit convert_to);


void conversion(struct channel *channel, unit convert_to, struct channel *return_channel) ;


void add_constant(struct channel *channel, double constant);

void multiply_by_constant(struct channel *channel, double constant);

void add_channels(struct channel *input_channel1, struct channel *input_channel2, struct channel *return_channel,
                  bool uniform);


#endif //DATA_HELPER_H
