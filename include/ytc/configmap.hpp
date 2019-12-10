#ifndef YTC_CONFIGMAP_HPP_
#define YTC_CONFIGMAP_HPP_

#include <yaml-cpp/yaml.h>
#include <memory>

class ConfigMap;
using ConfigMapPtr = std::shared_ptr<ConfigMap>;

namespace YAML {
template<> struct convert<ConfigMapPtr> {
  static Node encode(const ConfigMapPtr &rhs);
  static bool decode(const Node &node, ConfigMapPtr &c);
};
}

#endif  // YTC_CONFIGMAP_HPP_
