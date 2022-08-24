#include "level.h"

using log4cpp::level::level_index;
using log4cpp::level::level_map;
using log4cpp::level::is_level_member;
using log4cpp::level::is_level_index_member;

log4cpp::level::Level::Level()
{
    this->level = "DEBUG";
    this->index = 1;
}

log4cpp::level::Level::Level(std::string level)
{
    this->level = "DEBUG";
    this->index = 1;
    if (is_level_member(level)) {
        this->level = level;
        std::map<level_index, std::string> ::iterator it = level_map.begin();
        while (it != level_map.end()) {
            if (strcmp(level.c_str(), it->second.c_str()) ==  0) {
                this->index = it->first;
            }
            it ++;
        }
    }
}

log4cpp::level::Level::Level(level_index index)
{
    this->level = "DEBUG";
    this->index = 1;
    if (is_level_index_member(index)) {
        this->index = index;
        this->level = level_map[index];
    }
}

log4cpp::level::Level::~Level()
{
    
}

std::string log4cpp::level::Level::get_level() const
{
    return this->level;
}

int log4cpp::level::Level::get_index() const
{
    return this->index;
}

bool log4cpp::level::Level::compare(const log4cpp::level::Level &stanard, const log4cpp::level::Level &target)
{
    return target.get_index() <= stanard.get_index();
}

bool log4cpp::level::Level::compare(const level_index stanard, const level_index target)
{
    return target <= stanard;
}