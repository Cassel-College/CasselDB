#ifndef LOG4CPP_CONFIG4LOG_CONFIG4LOG_H
#define LOG4CPP_CONFIG4LOG_CONFIG4LOG_H

#include <string>
namespace log4cpp {
namespace config4log {
class Config4Log {

    public:

        Config4Log();

        ~Config4Log();

        void setDefaultSetting();

        void read_config(const std::string &condif_path);

        std::string getLogWebServerIp() const;

        void setLogWebServerIp(const std::string &logWebServerIp_);

        int getLogWebServerPort() const;

        void setLogWebServerPort(int logWebServerPort_);

        std::string getLogPath() const;

        void setLogPath(const std::string &logPath_);

        int getMaxCache() const;

        void setMaxCache(int maxCache_);

        int getMaxSaveTime() const;

        void setMaxSaveTime(int maxSaveTime_);

        int getMaxLogFileSize() const;

        void setMaxLogFileSize(int maxLogFileSize_);

        std::string getLogStyle() const;

        void setLogStyle(const std::string &logStyle_);

        std::string getFilterLevel() const;

        void setFilterLevel(const std::string &filterLevel_);

        std::string getFilterModule() const;

        void setFilterModule(const std::string &filterModule_);

        std::string getLogCopyFileStyle() const;

        void setLogCopyFileStyle(const std::string &logCopyFileStyle_);

    private:

        std::string logWebServerIp;
        int logWebServerPort;
        std::string logPath;
        std::string configPolyPath;
        int maxCache = 1024;
        int maxSaveTime = 300;
        int maxLogFileSize = 10240;
        std::string logStyle = "def";
        std::string filterLevel = "debug";
        std::string filterModule = "";
        std::string logCopyFileStyle = "log_yyyy_mm_dd_hh_mm_ss_count.log";

}; // class Config
}; // namespace config;
}; //namespace log4cpp;

#endif