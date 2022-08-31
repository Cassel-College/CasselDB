#ifndef LOG4CPP_DATE_TIME_TIME_H
#define LOG4CPP_DATE_TIME_TIME_H


#include <string>

namespace log4cpp {
namespace date_time {

class Time {

    public:
        Time();

        Time(int hours, int minutes, int seconds);

        void setMicroseconds(const int microseconds);
        
        int getMicroseconds() const;

        void setNanosecond(const int nanosecond);

        int getNanosecond() const;

        void setNanoseconds(const int nanoseconds);

        int getNanoseconds() const;

        ~Time();

        std::string getTimeInfo() const;

        std::string getAllTimeInfo() const;

        void setMicSecond(const long nsec);

    private:

        int hours;

        int minutes;

        int seconds;

        int microseconds = -1;

        int nanosecond = -1;

        int nanoseconds = -1;
}; // class date
}; // namespace date_time
}; // namespace log4cpp
#endif