#ifndef LOG4CPP_IO4LOG_IO4LOG_H
#define LOG4CPP_IO4LOG_IO4LOG_H

#include <iostream>
#include <string>

namespace log4cpp {

namespace io4log {

class IO4Log {

    public:

        IO4Log();

        IO4Log(const std::string &log_path);

        ~IO4Log();

        void wirte(const std::string &log_info);

    private:

        std::string log_path;

};
};
};

#endif