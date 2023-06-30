#include "simple_ui.h"

using VecStrPtr = std::shared_ptr<std::vector<std::string>>;

/**
 * @brief Construct a new cassel::os::ui::Simple UI::Simple UI object
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 */
cassel::os::ui::SimpleUI::SimpleUI() {
    // TODO Auto-generated constructor stub
};

/**
 * @brief Destructor for the SimpleUI class from the cassel::os::ui namespace. 
 * 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 */
cassel::os::ui::SimpleUI::~SimpleUI() {
    
};

/**
 * @brief Genaration DB show infos.
 * 
 * @param db_infos 
 * @return VecStrPtr 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 * @return VecStrPtr 
 */
VecStrPtr cassel::os::ui::SimpleUI::GenDB(VecStrPtr db_infos) {

    VecStrPtr new_db_infos = std::make_shared<std::vector<std::string>>();
    if (db_infos->size() != 0) {
        new_db_infos = PrintTable(db_infos);
    }
    return new_db_infos;
};

/**
 * @brief Destructor for the SimpleUI class from the cassel::os::ui namespace. 
 * 
 * @param table_infos 
 * @return VecStrPtr 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 * @return VecStrPtr 
 */
VecStrPtr cassel::os::ui::SimpleUI::GenTable(VecStrPtr table_infos) {
    VecStrPtr new_table_infos = std::make_shared<std::vector<std::string>>();;
    return new_table_infos;
};

/**
 * @brief Genaration config show infos.
 * 
 * @param config_infos 
 * @return VecStrPtr 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 * @return VecStrPtr 
 */
VecStrPtr cassel::os::ui::SimpleUI::GenConfig(VecStrPtr config_infos) {
    VecStrPtr new_config_infos = std::make_shared<std::vector<std::string>>();;
    return new_config_infos;
};

/**
 * @brief Show the UI
 * 
 * @param ui_infos 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-24
 * @copyright Copyright (c) 2023
 */
void cassel::os::ui::SimpleUI::Show(VecStrPtr ui_infos) {
    for (const auto& row : *ui_infos) {
        std::cout << row << std::endl;
    }
};

/**
 * @brief Genaration status show infos.
 * 
 * @param status_infos 
 * @return VecStrPtr 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-29
 * @copyright Copyright (c) 2023
 * @return VecStrPtr 
 */
VecStrPtr cassel::os::ui::SimpleUI::GenStatus(VecStrPtr status_infos) {
    VecStrPtr new_status_infos = std::make_shared<std::vector<std::string>>();

    if (status_infos->size() != 0) {
        new_status_infos = PrintTable(status_infos);
    }
    return new_status_infos;
};

/**
 * @brief Print the table
 * 
 * @param data 
 * @return VecStrPtr 
 * @version 0.1
 * @author liupeng (liupeng.0@outlook.com)
 * @date 2023-06-29
 * @copyright Copyright (c) 2023
 * @return VecStrPtr 
 */
VecStrPtr cassel::os::ui::SimpleUI::PrintTable(const VecStrPtr data) {
    auto table = std::make_shared<std::vector<std::string>>();

    // Get the longest string
    size_t maxLength = 0;
    for (const auto& str : *data) {
        maxLength = std::max(maxLength, str.length());
    }

    // build the separator
    std::string separator = "+-";
    for (size_t i = 0; i < maxLength; ++i) {
        separator += "-";
    }
    separator += "-+";

    table->push_back(separator);
    for (const auto& str : *data) {
        std::string row = "| " + str;
        row.resize(separator.length() - 2, ' ');
        row += " |";
        table->push_back(row);
    }
    table->push_back(separator);
    return table;
};
