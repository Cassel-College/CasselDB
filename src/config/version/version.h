/**
 * @file version.h
 * @author liupeng (liupeng.0@outlook.com)
 * @brief 程序版本配置
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CONDIF_VERSION_VERSION_H
#define CONDIF_VERSION_VERSION_H

#include <string>

/**
 * @brief config namespace
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2022-09-16
 * @copyright Copyright (c) 2022
 */
namespace config
{
    /**
     * @brief version namespace
     * 
     * @version 0.1
     * @author liupeng (liupeng.0@outlook.com)
     * @date 2022-09-16
     * @copyright Copyright (c) 2022
     */
    namespace version 
    {
        /**
         * @brief Version Class
         * 
         * @version 0.1
         * @author liupeng (liupeng.0@outlook.com)
         * @date 2022-09-16
         * @copyright Copyright (c) 2022
         */
        class Version 
        {
            public:
                /**
                 * @brief Construct a new Version object
                 * 
                 * @version 0.1
                 * @author liupeng (liupeng.0@outlook.com)
                 * @date 2022-09-16
                 * @copyright Copyright (c) 2022
                 */
                Version();

                /**
                 * @brief Destroy the Version object
                 * 
                 * @version 0.1
                 * @author liupeng (liupeng.0@outlook.com)
                 * @date 2022-09-16
                 * @copyright Copyright (c) 2022
                 */
                ~Version();

                /**
                 * @brief read config file
                 * 
                 * @version 0.1
                 * @author liupeng (liupeng.0@outlook.com)
                 * @date 2022-09-16
                 * @copyright Copyright (c) 2022
                 */
                void read_config_file();

                /**
                 * @brief Get the version object
                 * 
                 * @return std::string 
                 * @version 0.1
                 * @author liupeng (liupeng.0@outlook.com)
                 * @date 2022-09-16
                 * @copyright Copyright (c) 2022
                 * @return std::string 
                 */
                std::string get_version();
                
            private:

                /// @brief 程序名称
                std::string name;

                /// @brief 程序大版本号
                size_t big_version_number;

                /// @brief 程序小版本号
                size_t somll_version_number;
        };
    }; // version
}; // config


#endif