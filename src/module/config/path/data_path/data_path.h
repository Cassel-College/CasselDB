#ifndef MODULE_CONFIG_PATH_DATA_PATH_DATA_PATH_H
#define MODULE_CONFIG_PATH_DATA_PATH_DATA_PATH_H

#include <string>

namespace module {
namespace config {
namespace path {

class DataPath
{
public:
    DataPath();

    ~DataPath();

    static std::string GetDataPath();

    static bool DataSec();
};

}; // namespace path
}; // namespace config
}; // namespace module

#endif