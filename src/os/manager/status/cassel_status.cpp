#include "cassel_status.h"

namespace cassel {
namespace os {
namespace manager {
namespace status {

CasselStatus::CasselStatus() {
    Init();
}

 void CasselStatus::Init() {
    database_ = "";
    table_ = "";
    status_ = CasselManagerStatus::DEFAULT;
 }

void CasselStatus::SetDataBase(const std::string &database) {
    database_ = database;
}

std::string CasselStatus::GetDataBase() {
    return database_;
}

void CasselStatus::SetTable(const std::string &table) {
    table_ = table;
}

std::string CasselStatus::GetTable() {
    return table_;
}

void CasselStatus::SetStatus(CasselManagerStatus status) {
    status_ = status;
}

CasselManagerStatus CasselStatus::GetStatus() {
    return status_;
}

}; // namespace status
}; // namespace manager;
}; // namespace os;
}; // namespace cassel;