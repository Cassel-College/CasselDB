#ifndef LOG4CPP_DATE_TIME_DATE_TIME_H
#define LOG4CPP_DATE_TIME_DATE_TIME_H

#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <memory>
#include "date.h"
#include "time.h"

namespace log4cpp {
namespace date_time {

using log4cpp::date_time::Date;
using log4cpp::date_time::Time;
class DateTime {

    public:
        DateTime();

        ~DateTime();

        std::shared_ptr<Date> getDate() const;

        std::shared_ptr<Time> getTime() const;

        std::string getDateTime() const;

        void show_now() const;

    private:

        struct timespec now;

        std::shared_ptr<Date> date;

        std::shared_ptr<Time> time;

}; // class datetime
}; // namespace date_time
}; // namespace log4cpp
#endif