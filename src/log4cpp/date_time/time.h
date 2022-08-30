#ifndef LOG4CPP_DATE_TIME_TIME_H
#define LOG4CPP_DATE_TIME_TIME_H

#include <stdio.h>
#include <time.h>
#include <stdint.h>
 

namespace log4cpp {
namespace date_time {

class Time {

    public:
        Time();

        ~Time();

    private:

        int hour;

        int mon;

        int sec;

}; // class date
}; // namespace date_time
}; // namespace log4cpp
#endif