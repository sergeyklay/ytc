#ifndef YTC_METADATA_YAML_CONFIGMAP_HPP_
#define YTC_METADATA_YAML_CONFIGMAP_HPP_

#include <yaml-cpp/yaml.h>
#include <ytc/metadata/ptr/metadata.hpp>

namespace YAML {
template <> struct convert<MetadataPtr> {
  /**
   * @brief Encode Metadata object to a Yaml Node.
   *
   * @param mptr The smart pointer to a Metadata instance
   * @return Yaml Node
   */
  static Node encode(const MetadataPtr &mptr);

  /**
   * @brief Decode Yaml Node to a Metadata object.
   *
   * @param node Yaml Node
   * @param mptr The smart pointer to a Metadata instance
   * @return true on success, false otherwise
   */
  static bool decode(const Node &node, MetadataPtr &mptr);
};
} // namespace YAML

#endif // YTC_METADATA_YAML_CONFIGMAP_HPP_
