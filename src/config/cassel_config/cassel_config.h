#ifndef CONFIG_CASSEL_CONFIG_H
#define CONFIG_CASSEL_CONFIG_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>



namespace config {
namespace cassel_config {
class CasselConfig {

public:

    CasselConfig(CasselConfig &other) = delete;

    static std::shared_ptr<CasselConfig> GetCasselConfigPtr();

    void SetInstallPath(const std::string &installPath);

    const std::string GetInstallPath() const;

    void SetDataPath(const std::string &path);

    const std::string GetDataPath() const;

    void SetConfigFilePath(const std::string &path);

    const std::string GetConfigFilePath() const;

private:

    std::string install_path;
    std::string data_path;
    std::string config_file_path;

protected:

    CasselConfig();

    static std::shared_ptr<CasselConfig> cassel_config_ptr;

};
};
};

#endif