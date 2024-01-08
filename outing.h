#include <string>

#ifndef DATA_OUTING_H
#define DATA_OUTING_H

struct outing {
public:
    // Date
    short int day;
    short int month;
    short int year;

    // Metadata
    std::string driver;
    std::string event;
    std::string venue;
};

#endif //DATA_OUTING_H
