#include <deque>
#include "outing.h"

#ifndef DATA_CHANNEL_H
#define DATA_CHANNEL_H

/**
 * Name of data channel in relation to logged data.
 */
enum class channel_name  {
    brake_temperature,
    brake_pressure
};

/**
 * Location from car the data is taken from.
 */
enum class location {
    front,
    rear,
    front_left,
    front_right,
    rear_left,
    rear_right
};

/**
 * The type of unit the data represents.
 */
enum class data_type {
    pressure,
    temperature
};

/**
 * The unit that the data is in.
 */
enum class unit {
    // Pressures,
    bar,
    pascal,
    // Temperatures
    celsius,
    fahrenheit,
    kelvin
};

/**
 * Represents time series data.
 */
struct channel {
public:
    outing *session;
    // Metadata
    const channel_name name;
    const location locations;
    const data_type type;
    unit units;

    // Data
    std::deque<double> data; // Raw data
    std::deque<double> time; // Time stamps of each data point
    
};

#endif //DATA_CHANNEL_H
