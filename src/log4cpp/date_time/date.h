#ifndef LOG4CPP_DATE_TIME_DATE_H
#define LOG4CPP_DATE_TIME_DATE_H

#include <stdio.h>
#include <time.h>
#include <stdint.h>
 

namespace log4cpp {
namespace date_time {

class Date {

    public:
        Date();

        ~Date();

    private:

        int year;

        int month;

        int day;

}; // class date
}; // namespace date_time
}; // namespace log4cpp
#endif