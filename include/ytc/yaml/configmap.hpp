#ifndef YTC_YAML_CONFIGMAP_HPP_
#define YTC_YAML_CONFIGMAP_HPP_

#include "ytc/ptr/configmap.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<ConfigMapPtr> {
  static Node encode(const ConfigMapPtr &rhs);
  static bool decode(const Node &node, ConfigMapPtr &cptr);
};
} // namespace YAML

#endif // YTC_YAML_CONFIGMAP_HPP_
