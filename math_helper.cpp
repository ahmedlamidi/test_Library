#include "math_helper.h"
double celsius_to_fahrenheit(double temp) {
    return (temp * (9.0 / 5.0)) + 32;
}

double celsius_to_kelvin(double temp) {
    return temp + 273.15;
}

double kelvin_to_fahrenheit(double temp) {
    return celsius_to_fahrenheit(temp - 273.15);
}

double kelvin_to_celsius(double temp) {
    return temp - 273.15;
}

double fahrenheit_to_celsius(double temp) {
    return (temp - 32) * (5.0 / 9.0);
}

double fahrenheit_to_kelvin(double temp) {
    return celsius_to_kelvin(fahrenheit_to_celsius(temp));
}

double pascal_to_bar(double pressure) {
    return pressure / 100000;
}

double bar_to_pascal(double pressure) {
    return pressure * 100000;
}

double linear_approximation(double time1, double data1, double time2, double data2, double expected_time) {
    double slope = (data2 - data1) / (time2 - time1);
    return ((expected_time - time1) * slope) + data1;
}

/**
 *
 * @param channel pointer to channel to be modified in place
 * @param convert_to unit to be converted to
 **/
void conversion(struct channel *channel, unit convert_to) {
    switch (channel->units) {

        case unit::bar:
            if (convert_to == unit::pascal) {
                for (double &i: channel->data) {
                    i = bar_to_pascal(i);
                }
                channel->units = unit::pascal;
            } else if (convert_to != unit::bar) {
                std::cerr << "Invalid Unit Conversion";
            }
            break;

        case unit::pascal:
            if (convert_to == unit::bar) {
                for (double &i: channel->data) {
                    i = pascal_to_bar(i);
                }
                channel->units = unit::bar;
            } else if (convert_to != unit::pascal) {
                std::cerr << "Invalid unit conversion";
            }
            break;

        case unit::celsius:
            if (convert_to == unit::kelvin) {
                for (double &i: channel->data) {
                    i = celsius_to_kelvin(i);
                }
                channel->units = unit::kelvin;
            } else if (convert_to == unit::fahrenheit) {
                for (double &i: channel->data) {
                    i = celsius_to_fahrenheit(i);
                }
                channel->units = unit::fahrenheit;
            } else if (convert_to != unit::celsius) {
                std::cerr << "Invalid unit conversion";
            }
            break;

        case unit::fahrenheit:
            if (convert_to == unit::celsius) {
                for (double &i: channel->data) {
                    i = fahrenheit_to_celsius(i);
                }
                channel->units = unit::celsius;
            } else if (convert_to == unit::kelvin) {
                for (double &i: channel->data) {
                    i = fahrenheit_to_kelvin(i);
                }
                channel->units = unit::kelvin;
            } else if (convert_to != unit::fahrenheit) {
                std::cerr << "Invalid unit conversion";
            }
            break;

        case unit::kelvin:
            if (convert_to == unit::celsius) {
                for (double &i: channel->data) {
                    i = kelvin_to_celsius(i);
                }
                channel->units = unit::celsius;
            } else if (convert_to == unit::fahrenheit) {
                for (double &i: channel->data) {
                    i = kelvin_to_fahrenheit(i);
                }
                channel->units = unit::fahrenheit;
            } else if (convert_to != unit::kelvin) {
                std::cerr << "Invalid unit conversion";
            }
            break;
    }

}

/**
 *
 * @param channel pointer to channel to be converted
 * @param convert_to unit to be converted to
 * @param return_channel  pointer to channel for output
 */
void conversion(struct channel *channel, unit convert_to, struct channel *return_channel) {
    switch (channel->units) {

        case unit::bar:
            if (convert_to == unit::pascal) {
                for (int i = 0; i < channel->data.size(); i++) {
                    return_channel->data[i] = bar_to_pascal(channel->data[i]);
                }
                return_channel->units = unit::pascal;
            } else if (convert_to != unit::bar) {
                std::cerr << "Invalid Unit Conversion";
            }
            break;

        case unit::pascal:
            if (convert_to == unit::bar) {
                for (int i = 0; i < channel->data.size(); i++) {
                    return_channel->data[i] = pascal_to_bar(channel->data[i]);
                }
                return_channel->units = unit::bar;
            } else if (convert_to != unit::pascal) {
                std::cerr << "Invalid unit conversion";
            }
            break;

        case unit::celsius:
            if (convert_to == unit::kelvin) {
                for (int i = 0; i < channel->data.size(); i++) {
                    return_channel->data[i] = celsius_to_kelvin(channel->data[i]);
                }
                return_channel->units = unit::kelvin;
            } else if (convert_to == unit::fahrenheit) {
                for (int i = 0; i < channel->data.size(); i++) {
                    return_channel->data[i] = celsius_to_fahrenheit(channel->data[i]);
                }
                return_channel->units = unit::fahrenheit;
            } else if (convert_to != unit::celsius) {
                std::cerr << "Invalid unit conversion";
            }
            break;

        case unit::fahrenheit:
            if (convert_to == unit::celsius) {
                for (int i = 0; i < channel->data.size(); i++) {
                    return_channel->data[i] = fahrenheit_to_celsius(channel->data[i]);
                }
                return_channel->units = unit::celsius;
            } else if (convert_to == unit::kelvin) {
                for (int i = 0; i < channel->data.size(); i++) {
                    return_channel->data[i] = fahrenheit_to_kelvin(channel->data[i]);
                }
                return_channel->units = unit::kelvin;
            } else if (convert_to != unit::fahrenheit) {
                std::cerr << "Invalid unit conversion";
            }
            break;

        case unit::kelvin:
            if (convert_to == unit::celsius) {
                for (int i = 0; i < channel->data.size(); i++) {
                    return_channel->data[i] = kelvin_to_celsius(channel->data[i]);
                }
                return_channel->units = unit::celsius;
            } else if (convert_to == unit::fahrenheit) {
                for (int i = 0; i < channel->data.size(); i++) {
                    return_channel->data[i] = kelvin_to_fahrenheit(channel->data[i]);
                }
                return_channel->units = unit::fahrenheit;
            } else if (convert_to != unit::kelvin) {
                std::cerr << "Invalid unit conversion";
            }
            break;
    }
}

/**
 *
 * @param channel input channel
 * @param constant double constant to be added to every element
 */
void add_constant(struct channel *channel, double constant) {
    for (double &i: channel->data) {
        i += constant;
    }
}

/**
 *
 * @param channel input channel
 * @param constant double constant to multiply every element
 */
void multiply_by_constant(struct channel *channel, double constant) {
    for (double &i: channel->data) {
        i *= constant;
    }

}

void add_channels(struct channel *input_channel1, struct channel *input_channel2, struct channel *return_channel,
                  bool uniform) {
    if (input_channel1->type != input_channel2->type) {
        std::cerr << "Invalid Types for addition";
        return;
    }
    if (uniform) {
        // when we want to make the time data uniform
        return_channel->data = std::deque<double>();
        return_channel->time = std::deque<double>();
        int index_channel1 = 0, index_channel2 = 0;
        while (index_channel1 < input_channel1->data.size() && index_channel2 < input_channel2->data.size()) {
            if (input_channel1->time[index_channel1] == input_channel2->time[index_channel2]) {
                return_channel->data.push_back(
                        input_channel1->data[index_channel1] + input_channel2->data[index_channel2]);
                return_channel->data.push_back(input_channel1->time[index_channel1]);
                index_channel1++;
                index_channel2++;
                continue;
            } else if (input_channel1->time[index_channel1] > input_channel2->time[index_channel2]) {
                if (index_channel1 >= 1) {
                    double expected_value = linear_approximation(
                            input_channel1->time[index_channel1 - 1], input_channel1->data[index_channel1 - 1],
                            input_channel1->time[index_channel1], input_channel1->data[index_channel1],
                            input_channel2->time[index_channel2]
                    );
                    return_channel->data.push_back(expected_value + input_channel2->data[index_channel2]);
                    return_channel->time.push_back(input_channel2->time[index_channel2]);
                    index_channel2++;
                }
                // What to do when the data is longer for one of them ??
                // What to do when missing data points at the start , cannot linearly approximate

            }
        }
    }


}