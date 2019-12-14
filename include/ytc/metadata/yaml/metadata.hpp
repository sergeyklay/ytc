#ifndef YTC_METADATA_YAML_CONFIGMAP_HPP_
#define YTC_METADATA_YAML_CONFIGMAP_HPP_

#include <yaml-cpp/yaml.h>
#include <ytc/metadata/ptr/metadata.hpp>

namespace YAML {
template <> struct convert<MetadataPtr> {
  static Node encode(const MetadataPtr &mptr);
  static bool decode(const Node &node, MetadataPtr &mptr);
};
} // namespace YAML

#endif // YTC_METADATA_YAML_CONFIGMAP_HPP_
