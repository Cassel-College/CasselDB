#include "version.h"

#include <log4cpp/log/log.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_module/log_module.h>

using log4cpp::log::Log;
using log4cpp::level::Level;
using log4cpp::log_module::LogModule;

/**
 * @brief Construct a new config::version::Version::Version object
 * 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-18
 * @copyright Copyright (c) 2022
 */
config::version::Version::Version() {
    Log* logMS = Log::GetLog();
    logMS->add(LogModule("Create version", Level("ERROR"), __FILE__, __LINE__, "log"));
    logMS->send_log();
}

/**
 * @brief Destroy the config::version::Version::Version object
 * 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-18
 * @copyright Copyright (c) 2022
 */
config::version::Version::~Version() {

}

/**
 * @brief Read config_file
 * 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-18
 * @copyright Copyright (c) 2022
 */
void config::version::Version::read_config_file() {
    std::string config_file_path;
}

/**
 * @brief Get Cassel DB version information.
 * 
 * @return std::string 
 * @version 1.0
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-18
 * @copyright Copyright (c) 2022
 */
std::string config::version::Version::get_version() {
    return "Cassel DB version 1.00";
}