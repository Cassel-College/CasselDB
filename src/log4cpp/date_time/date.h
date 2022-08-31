#ifndef LOG4CPP_DATE_TIME_DATE_H
#define LOG4CPP_DATE_TIME_DATE_H

#include <string>

namespace log4cpp {
namespace date_time {
class Date {

    public:
        Date();

        Date(int year, int month, int day);

        ~Date();

        std::string GetDateInfo() const;

    private:

        int year;

        int month;

        int day;

}; // class date
}; // namespace date_time
}; // namespace log4cpp
#endif