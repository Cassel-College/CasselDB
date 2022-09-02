#include "version.h"

#include <log4cpp/log/log.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_module/log_module.h>

using log4cpp::log::Log;
using log4cpp::log_module::LogModule;


config::version::Version::Version() {
    Log* logMS = Log::GetLog();
    logMS->add(LogModule("Create version", Level("ERROR"), __FILE__, __LINE__, "log"));
    logMS->send_log();
}

config::version::Version::~Version() {

}

void config::version::Version::read_config_file() {
    std::string config_file_path;
}

std::string config::version::Version::get_version() {
    return "Cassel DB version 1.00";
}