#ifndef CORE_TOOLS_SELECT_INFO_FROM_LIST_SELECT_INFO_FROM_LIST_H
#define CORE_TOOLS_SELECT_INFO_FROM_LIST_SELECT_INFO_FROM_LIST_H

#include <string>
#include <vector>

namespace core {
namespace tools {
class SelectInfoFromList {

public:

    SelectInfoFromList();

    ~SelectInfoFromList();

    static std::vector<std::string> SelectInfo(std::vector<std::string> list, std::string info, bool same);

}; 

}; // namespace tools
}; // namespace core
#endif