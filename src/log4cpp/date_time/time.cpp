#include <iostream>
#include "time.h"

log4cpp::date_time::Time::Time()
{
    std::cout << "Create time." << std::endl;
}

log4cpp::date_time::Time::Time(int hours, int minutes, int seconds)
{
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

void log4cpp::date_time::Time::setMicroseconds(const int microseconds)
{
    this->microseconds = microseconds;
}

int log4cpp::date_time::Time::getMicroseconds() const
{
    return microseconds;
}

void log4cpp::date_time::Time::setNanosecond(const int nanosecond)
{
    this->nanosecond = nanosecond;
}

int log4cpp::date_time::Time::getNanosecond() const
{
    return nanosecond;
}

void log4cpp::date_time::Time::setNanoseconds(const int nanoseconds)
{
    this->nanoseconds = nanoseconds;
}

int log4cpp::date_time::Time::getNanoseconds() const
{
    return nanoseconds;
}

log4cpp::date_time::Time::~Time()
{
    
}

void log4cpp::date_time::Time::setMicSecond(const long nsec)
{
    this->setMicroseconds(static_cast<int>(nsec / 1000000));
    this->setNanosecond(static_cast<int>((nsec / 1000) % 1000));
    this->setNanoseconds(static_cast<int>(nsec % 1000));
}

std::string log4cpp::date_time::Time::getTimeInfo() const
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

std::string log4cpp::date_time::Time::getAllTimeInfo() const
{
    long mic_second = microseconds * 1000000 + nanosecond * 1000 + nanoseconds;
    std::string time = this->getTimeInfo() + "." + std::to_string(mic_second);
    return time;
}