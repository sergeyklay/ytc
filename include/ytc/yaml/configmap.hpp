#ifndef YTC_YAML_CONFIGMAP_HPP_
#define YTC_YAML_CONFIGMAP_HPP_

#include <yaml-cpp/yaml.h>
#include <ytc/ptr/configmap.hpp>

namespace YAML {
template <> struct convert<ConfigMapPtr> {
  /**
   * @brief Encode ConfigMap object to a Yaml Node.
   *
   * @param cptr The smart pointer to a ConfigMap instance
   * @return Yaml Node
   */
  static Node encode(const ConfigMapPtr &cptr);

  /**
   * @brief Decode Yaml Node to a ConfigMap object.
   *
   * @param node Yaml Node
   * @param cptr The smart pointer to a ConfigMap instance
   * @return true on success, false otherwise
   */
  static bool decode(const Node &node, ConfigMapPtr &cptr);
};
} // namespace YAML

#endif // YTC_YAML_CONFIGMAP_HPP_
