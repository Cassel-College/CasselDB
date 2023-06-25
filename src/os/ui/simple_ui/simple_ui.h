#ifndef CASSEL_OS_UI_SIMPLE_UI_H
#define CASSEL_OS_UI_SIMPLE_UI_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

namespace cassel {
namespace os {
namespace ui {

using VecStrPtr = std::shared_ptr<std::vector<std::string>>;

class SimpleUI {

public:

    SimpleUI();

    ~SimpleUI();

    void Show(VecStrPtr ui_infos);

    VecStrPtr PrintTable(const VecStrPtr data);

    VecStrPtr GenDB(VecStrPtr db_infos);

    VecStrPtr GenTable(VecStrPtr table_infos);

    VecStrPtr GenConfig(VecStrPtr config_infos);

    VecStrPtr GenStatus(VecStrPtr status_infos);

}; // class SimpleUI

}; // namespace ui
}; // namespace os
}; // namespace cassel

#endif // CASSEL_OS_UI_SIMPLE_UI_H