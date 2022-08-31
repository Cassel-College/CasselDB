#ifndef LOG4CPP_DATE_TIME_TIME_H
#define LOG4CPP_DATE_TIME_TIME_H


#include <string>

namespace log4cpp {
namespace date_time {

class Time {

    public:
        Time();

        Time(int hours, int minutes, int seconds);

        ~Time();

        std::string getTime() const;

    private:

        int hours;

        int minutes;

        int seconds;

}; // class date
}; // namespace date_time
}; // namespace log4cpp
#endif