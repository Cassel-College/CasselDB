#include <iostream>
#include <string>
#include "date.h"

log4cpp::date_time::Date::Date()
{
    std::cout << "Create date " << std::endl;
}

log4cpp::date_time::Date::Date(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

log4cpp::date_time::Date::~Date()
{
    this->year = 0;
    this->month = 0;
    this->day = 0;
}

std::string log4cpp::date_time::Date::GetDate() const
{
    std::string date = "";
    if (year >= 0 && month >= 0 && month <= 12 && day >= 0 && day <= 31) {
        std::string str_year = std::to_string(year);
        std::string str_month = std::to_string(month);
        if (str_month.length() <= 1) {
            str_month = "0" + str_month;
        }
        std::string str_day = std::to_string(day);
        if (str_day.length() <= 1) {
            str_day = "0" + str_day;
        }
        date = str_year + "-" + str_month + "-" + str_day;
    }
    return date;
}

