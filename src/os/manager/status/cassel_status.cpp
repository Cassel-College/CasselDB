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

void CasselStatus::SetDatabaseName(const std::string &database) {
    database_ = database;
}

std::string CasselStatus::GetDatabaseName() {
    return database_;
}

void CasselStatus::SetTableName(const std::string &table) {
    table_ = table;
}

std::string CasselStatus::GetTableName() {
    return table_;
}

void CasselStatus::SetStatus(CasselManagerStatus status) {
    status_ = status;
}

CasselManagerStatus CasselStatus::GetStatus() {
    return status_;
}

const std::string CasselStatus::GetStatusStr() const {
    std::stringstream ss;
    switch (this->status_) {
        case CasselManagerStatus::DEFAULT:  return "DEFAULT";
        case CasselManagerStatus::DATABASE: ss << "DATABASE: " << this->database_.c_str(); return ss.str();
        case CasselManagerStatus::TABLE:    ss << "TABLE: " << this->table_.c_str(); return ss.str();
        case CasselManagerStatus::CONFIG:   return "CONFIG";
    }
    return "Unknown Status";
}

}; // namespace status
}; // namespace manager;
}; // namespace os;
}; // namespace cassel;