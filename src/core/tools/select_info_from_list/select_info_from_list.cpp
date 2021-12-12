#include "select_info_from_list.h"

core::tools::SelectInfoFromList::SelectInfoFromList() {
    
}

core::tools::SelectInfoFromList::~SelectInfoFromList() {
    
}

std::vector<std::string> core::tools::SelectInfoFromList::SelectInfo(std::vector<std::string> list, std::string info, bool same) {
    std::vector<std::string> info_list = {};
    for (std::string tempInfo : list) {
        if ((tempInfo.find(info) != std::string::npos)){
            if (same) {
                info_list.push_back(tempInfo);
            } else {
                info_list.push_back(tempInfo);
            }
        }
    }
    return info_list;
}
