#include "cassel_config.h"

namespace config {
namespace cassel_config {

CasselConfig::CasselConfig() {
    
}

std::shared_ptr<CasselConfig> CasselConfig::GetCasselConfigPtr() {
    if (cassel_config_ptr == nullptr) {
        std::shared_ptr<CasselConfig> temp_cassel_config_ptr(new CasselConfig());
        cassel_config_ptr.swap(temp_cassel_config_ptr);
    }
    return cassel_config_ptr;
}

}; // namespace cassel_config
}; // namespace config