#ifndef YTC_METADATA_YAML_CONFIGMAP_HPP_
#define YTC_METADATA_YAML_CONFIGMAP_HPP_

#include "ytc/metadata/ptr/metadata.hpp"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<MetadataPtr> {
  static Node encode(const MetadataPtr &mptr);
  static bool decode(const Node &node, MetadataPtr &mptr);
};
} // namespace YAML

#endif // YTC_METADATA_YAML_CONFIGMAP_HPP_
