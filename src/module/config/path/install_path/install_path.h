#ifndef MODULE_CONFIG_PATH_INSTALL_PATH_INSTALL_PATH_H
#define MODULE_CONFIG_PATH_INSTALL_PATH_INSTALL_PATH_H

#include <string>

namespace module {
namespace config {
namespace path {

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