#include <iostream>
#include <memory>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#include "date_time.h"
#include "date.h"
#include "time.h"

using log4cpp::date_time::Date;
using log4cpp::date_time::Time;

log4cpp::date_time::DateTime::DateTime()
{
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    const time_t *tm = &ts.tv_sec;
    struct tm *time = localtime(&ts.tv_sec);
    this->date = std::make_shared<Date>(time->tm_year + 1900, time->tm_mon + 1, time->tm_mday);
    this->time = std::make_shared<Time>(time->tm_hour, time->tm_min, time->tm_sec);
}

log4cpp::date_time::DateTime::~DateTime()
{
    
}


std::shared_ptr<Date> log4cpp::date_time::DateTime::getDate() const
{
    return this->date;
}

std::shared_ptr<Time> log4cpp::date_time::DateTime::getTime() const
{
    return this->time;
}

std::string log4cpp::date_time::DateTime::getDateTime() const
{
    std::string datetime = this->date->GetDate() + " " + this->time->getTime();
    return datetime;
}

void log4cpp::date_time::DateTime::show_now() const
{
    std::cout << this->getDateTime() << std::endl;
}