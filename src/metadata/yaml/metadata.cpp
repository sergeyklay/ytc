#include "ytc/metadata/yaml/metadata.hpp"
#include "ytc/metadata.hpp"

YAML::Node YAML::convert<MetadataPtr>::encode(const MetadataPtr &mptr) {
  Node node;
  // TODO(serghei): Not implemented
  return node;
}

bool YAML::convert<MetadataPtr>::decode(const YAML::Node &node,
                                        MetadataPtr &mptr) {
  if (!node.IsMap()) {
    return false;
  }

  if (node["creationTimestamp"] && node["creationTimestamp"].IsScalar()) {
    mptr->created_at_ = node["creationTimestamp"].as<std::string>();
  }

  if (node["name"] && node["name"].IsScalar()) {
    mptr->name_ = node["name"].as<std::string>();
  }

  if (node["namespace"] && node["namespace"].IsScalar()) {
    mptr->ns_ = node["namespace"].as<std::string>();
  }

  return true;
}
