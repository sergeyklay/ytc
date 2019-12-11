#include "ytc/configmap.hpp"
#include <tuple>

ConfigMap::ConfigMap()
    : version{"alpha"}, kind{"Sample"}, meta{}, data{}, file{""} {}

bool ConfigMap::operator==(const ConfigMap &rhs) const {
  auto lhs_key = std::tie(version, kind, meta, data, file);
  auto rhs_key = std::tie(rhs.version, rhs.kind, rhs.meta, rhs.data, rhs.file);

  return lhs_key == rhs_key;
}
