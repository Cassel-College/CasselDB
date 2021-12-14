#include "create_database.h"
#include <module/config/path/install_path/install_path.h>
#include <module/config/path/data_path/data_path.h>
#include <core/create/createFolder/create_folder.h>

using module::create::CreateDataBaseStatus;
using module::config::path::InstallPath;
using module::config::path::DataPath;
using core::create::CreateFolder;
using core::create::CreateFolderStatus;

module::create::CreateDatabase::CreateDatabase() {
    this->status = CreateDataBaseStatus::INIT;
    // set databases status
    this->SetCreateDataBaseStatus();
}

module::create::CreateDatabase::~CreateDatabase() {
    this->status = CreateDataBaseStatus::INIT;
}

void module::create::CreateDatabase::SetBashPath(const std::string& bashPath) {
    if (this->status == CreateDataBaseStatus::ENVIRONMENT_OK) {
        this->bashPath = DataPath::GetDataPath();
    }
}

std::string module::create::CreateDatabase::GetBashPath() const {
    return this->bashPath;
}

void module::create::CreateDatabase::SetDatabasesName(const std::string& dataBaseName) {
    this->dataBaseName = dataBaseName;
}

std::string module::create::CreateDatabase::GetDatabaseName() const {
    return this->dataBaseName;
}

void module::create::CreateDatabase::SetCreateDataBaseStatus() {
    bool isInstallCasselBD = InstallPath::SoftSec();
    if (!isInstallCasselBD) {
        std::cout << "NOT_INSRTALL_CASSEL_DB" << std::endl;
        this->status = CreateDataBaseStatus::NOT_INSRTALL_CASSEL_DB;
    } else {
        std::cout << "INSRTALL_CASSEL_DB" << std::endl;
        this->status = CreateDataBaseStatus::CASSEL_DB_INSTALL;
        bool isSetCasselDBDataPath = DataPath::DataSec();
        if (!isSetCasselDBDataPath) {
            std::cout << "NO_CASSEL_DB_PATH" << std::endl;
            this->status = CreateDataBaseStatus::NO_CASSEL_DB_PATH;
        } else {
            std::cout << "has Cassel Db path" << std::endl;
            this->status = CreateDataBaseStatus::ENVIRONMENT_OK;
            this->SetBashPath(DataPath::GetDataPath());
            std::cout << "data_path:" << DataPath::GetDataPath() << std::endl;
        }
    }
}

CreateDataBaseStatus module::create::CreateDatabase::GetCreateDataBaseStatus() const {
    return this->status;
}

bool module::create::CreateDatabase::Create() {
    bool pass = true;
    // check environment
    if (this->status != CreateDataBaseStatus::ENVIRONMENT_OK) {
        pass = false;
    }
    // check databases name
    pass = this->CheckDataBaseName();
    // check databases path
    if (pass) {
        pass = this->CheckDatabasesPath();
    }
    // TODO: check database exist!
    std::cout << "TODO: check database exist!" << std::endl;
    // create database
    if (pass) {
        CreateFolder *createFolder = new CreateFolder();
        createFolder->SetPath(this->bashPath);
        createFolder->SetFolderName(this->dataBaseName);
        createFolder->DoCreateFolder();
        CreateFolderStatus createFolderStatus = createFolder->GetStatus();
        if (createFolderStatus == CreateFolderStatus::CREATE_SUCCESS) {
            this->status = CreateDataBaseStatus::CREATE_SUCCESS;
        } else {
            this->status = CreateDataBaseStatus::CREATE_ERROR;
            pass = false;
        }
    }
    return pass;
}

bool module::create::CreateDatabase::CheckDataBaseName() {
    bool check = true;
    for (auto item : this->dataBaseName) {
        if (item == '/') {
            check = false;
            return check;
        }
    }
    return check;
}

bool module::create::CreateDatabase::CheckDatabasesPath() {
    bool check = true;
    std::string databasePath = this->bashPath + "/" + this->GetDatabaseName();
    if (databasePath.length() >= 1024 || databasePath.length() <= 0) {
        check = false;
    }
    return check;
}
