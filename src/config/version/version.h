#ifndef CONDIF_VERSION_VERSION_H
#define CONDIF_VERSION_VERSION_H

#include <string>

namespace config
{
    namespace version 
    {
        class Version 
        {
            public:
                Version();

                ~Version();

                void read_config_file();

                std::string get_version();
            private:

                std::string name;

                size_t big_version_number;

                size_t somll_version_number;
        };
    }; // version
}; // config


#endif