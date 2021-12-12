#include "select_info_from_list.h"
#include <iostream>

core::tools::SelectInfoFromList::SelectInfoFromList() {
    
}

core::tools::SelectInfoFromList::~SelectInfoFromList() {
    
}

std::vector<std::string> core::tools::SelectInfoFromList::SelectInfo(std::vector<std::string> list, std::string info, bool same) {
    std::vector<std::string> info_list = {};
    if (same) {
        for (std::string tempInfo : list) {
            if ((tempInfo.find(info) != std::string::npos)){
                info_list.push_back(tempInfo);
            }
        }
    } else {
        for (std::string tempInfo : list) {
            if ((tempInfo.find(info) == std::string::npos)){
                info_list.push_back(tempInfo);
            }
        }
    }
    return info_list;
}
