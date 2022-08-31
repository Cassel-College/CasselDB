#ifndef LOG4CPP_LEVEL_LEVEL_H
#define LOG4CPP_LEVEL_LEVEL_H

#include <cstring>
#include <string>
#include <map>

namespace log4cpp {
namespace level {

typedef int level_index;

std::map<level_index, std::string> level_map = {{0, "ERROR"}, {1, "DEBUG"}, {2, "INFO"}};

bool is_level_member(const std::string &target) 
{
    bool level_is_number = false;
    std::map<level_index, std::string> ::iterator it = level_map.begin();
    while (it != level_map.end()) {
        if (strcmp(target.c_str(), it->second.c_str()) ==  0) {
            level_is_number = true;
        }
        it ++;
    }
    return level_is_number;
}

bool is_level_index_member(const level_index target)
{
    bool level_is_number = false;
    std::map<level_index, std::string> ::iterator it = level_map.find(target);
    if (it != level_map.end()) {
        level_is_number = true;
    }
    return level_is_number;
}

class Level {

    private:

        std::string level;
        level_index index;
        int max_level_str_length = 5;

    public:

        Level();

        Level(std::string level);

        Level(level_index index);

        ~Level();

        std::string get_level() const;

        int get_index() const;

        static bool compare(const Level &stanard, const Level &target);

        static bool compare(const level_index stanard, const level_index target);

}; // class Level
}; // namespace level
}; // namespace log4cpp

#endif