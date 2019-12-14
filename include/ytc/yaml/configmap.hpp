#ifndef YTC_YAML_CONFIGMAP_HPP_
#define YTC_YAML_CONFIGMAP_HPP_

#include <yaml-cpp/yaml.h>
#include <ytc/ptr/configmap.hpp>

namespace YAML {
template <> struct convert<ConfigMapPtr> {
  static Node encode(const ConfigMapPtr &cptr);
  static bool decode(const Node &node, ConfigMapPtr &cptr);
};
} // namespace YAML

#endif // YTC_YAML_CONFIGMAP_HPP_
