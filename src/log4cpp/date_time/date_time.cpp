#include <iostream>
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
    std::cout << " -- date time --" << std::endl;
    // int main(void)
// {
    // struct timespec ts;
    // timespec_get(&ts, TIME_UTC);
    char buff[100];

    std::cout << ts.tv_nsec << std::endl;

    const time_t *tm = &ts.tv_sec;

    // std::cout << asctime(tm) << std::endl;
    std::cout << tm << std::endl;
    struct tm *time = localtime(tm);
    std::cout << time->tm_hour << std::endl;
    
    std::cout << time->tm_year + 1900 << std::endl;
    
    Date date = Date();
    Time t = Time();
    

//     strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));

//     printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);
//     printf("Raw timespec.time_t: %jd\n", (intmax_t)ts.tv_sec);
//     printf("Raw timespec.tv_nsec: %09ld\n", ts.tv_nsec);
// }
}

log4cpp::date_time::DateTime::~DateTime()
{
    
}