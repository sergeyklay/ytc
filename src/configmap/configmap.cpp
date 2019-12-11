#include "ytc/configmap.hpp"
#include <tuple>
#include <utility>

YAML::Node YAML::convert<ConfigMapPtr>::encode(const ConfigMapPtr &rhs) {
  Node node;
  // TODO(serghei): Not implemented
  return node;
}

bool YAML::convert<ConfigMapPtr>::decode(const YAML::Node &node,
                                         ConfigMapPtr &rhs) {
  // TODO(serghei): Not implemented
  return true;
}

ConfigMap::ConfigMap()
    : version_{"v1"}, kind_{"ConfigMap"}, meta_{}, data_{}, file_{""} {}

bool ConfigMap::operator==(const ConfigMap &rhs) const {
  auto lhs_key = std::tie(version_, kind_, meta_, data_, file_);
  auto rhs_key =
      std::tie(rhs.version_, rhs.kind_, rhs.meta_, rhs.data_, rhs.file_);

  return lhs_key == rhs_key;
}
