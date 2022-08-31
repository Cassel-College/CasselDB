#include <iostream>
#include "time.h"

log4cpp::date_time::Time::Time()
{
    std::cout << "Create time." << std::endl;
}

log4cpp::date_time::Time::~Time()
{
    
}

log4cpp::date_time::Time::Time(int hours, int minutes, int seconds)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

std::string log4cpp::date_time::Time::getTime() const
{
    std::string time = "";
    if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59) {
        std::string str_hours = std::to_string(hours);
        if (str_hours.length() <= 1) {
            str_hours = "0" + str_hours;
        }
        std::string str_minutes = std::to_string(minutes);
        if (str_minutes.length() <= 1) {
            str_minutes = "0" + str_minutes;
        }
        std::string str_seconds = std::to_string(seconds);
        if (str_seconds.length() <= 1) {
            str_seconds = "0" + str_seconds;
        }
        time = str_hours + ":" + str_minutes + ":" + str_seconds;
    }
    return time;
}