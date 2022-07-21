#include "version.h"

// using config::version::Version;

config::version::Version::Version() {

}

config::version::Version::~Version() {

}

void config::version::Version::read_config_file() {
    std::string config_file_path;
}

std::string config::version::Version::get_version() {
    return "Cassel DB version 1.00";
}