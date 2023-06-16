#ifndef MODULE_CONFIG_PATH_INSTALL_PATH_INSTALL_PATH_H
#define MODULE_CONFIG_PATH_INSTALL_PATH_INSTALL_PATH_H

#include <string>
#include <iostream>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <memory>

#include <core/read/readFile/read_file.h>
#include <core/tools/select_info_from_list/select_info_from_list.h>
#include <config/cassel_config/cassel_config.h>



namespace module {
namespace config {
namespace path {

using core::read::ReadFile;
using core::tools::SelectInfoFromList;
using db_config::cassel_config::CasselConfig;

class InstallPath
{
public:
    InstallPath();

    ~InstallPath();

    static std::string GetInstallPath();

    static bool SoftSec();
};

}; // namespace path
}; // namespace config
}; // namespace module

#endif