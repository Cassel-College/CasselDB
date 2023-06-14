#ifndef CONFIG_CASSEL_CONFIG_H
#define CONFIG_CASSEL_CONFIG_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <tuple>
#include <memory>
#include <stdio.h>
#include <unistd.h>
#include <algorithm>

#include <core/read/readFile/read_file.h>
#include <log4cpp/log_module/log_module.h>
#include <log4cpp/level/level.h>
#include <log4cpp/log_cache/log_cache.h>
#include <log4cpp/style4log/style4log.h>
#include <log4cpp/io4log/io4log.h>
#include <log4cpp/filter4log/filter4log.h>
#include <log4cpp/config4log/config4log.h>
#include <log4cpp/date_time/date_time.h>
#include <log4cpp/log/log.h>

namespace config {
namespace cassel_config {

using namespace core::read;
using log4cpp::log_module::LogModule;
using log4cpp::level::Level;
using log4cpp::log_cache::LogCache;
using log4cpp::style4log::Style4Log;
using log4cpp::io4log::IO4Log;
using log4cpp::filter4log::Filter4Log;
using log4cpp::config4log::Config4Log;
using log4cpp::date_time::DateTime;
using log4cpp::log::Log;

class CasselConfig {

public:

    CasselConfig(CasselConfig &other) = delete;

    static std::shared_ptr<CasselConfig> GetCasselConfigPtr();

    std::string GetCasselDBExecPath();

    std::string GetConfigPath();

    std::vector<std::string> ReadConfig(const std::string &config_path);

    std::string GetConfigInfo(const std::string &key);

    bool ReloadConfig();

    void LaodConfig(const std::string &config_path);

    bool AddConfig(std::pair<std::string, std::string> &config_item);

    std::string InterceptSpecialCharacters(const std::string &info);

    std::vector<std::string> FilterComments(const std::vector<std::string>& input);

    std::string RemoveSpaces(const std::string& str);

    bool SplitConfig(const std::string& str, std::pair<std::string, std::string> &config_item);

private:

    std::string config_file_path;

    std::map<std::string, std::string> config_maps;

protected:

    CasselConfig();

    static std::shared_ptr<CasselConfig> cassel_config_ptr;

};
};
};

#endif