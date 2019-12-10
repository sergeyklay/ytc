#include "ytc/configmap.hpp"

YAML::Node YAML::convert<ConfigMapPtr>::encode(const ConfigMapPtr &rhs) {
  Node node;
  // TODO(serghei): Not implemented
  return node;
}

bool YAML::convert<ConfigMapPtr>::decode(const YAML::Node &node, ConfigMapPtr &rhs) {
  // TODO(serghei): Not implemented
  return true;
}
