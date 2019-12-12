#include "ytc/metadata/yaml/metadata.hpp"
#include "ytc/metadata.hpp"

YAML::Node YAML::convert<MetadataPtr>::encode(const MetadataPtr &rhs) {
  Node node;
  // TODO(serghei): Not implemented
  return node;
}

bool YAML::convert<MetadataPtr>::decode(const YAML::Node &node,
                                        MetadataPtr &rhs) {

  if (!node.IsMap()) {
    return false;
  }

  if (node["creationTimestamp"] && node["creationTimestamp"].IsScalar()) {
    rhs->created_at = node["creationTimestamp"].as<std::string>();
  }

  if (node["name"] && node["name"].IsScalar()) {
    rhs->name = node["name"].as<std::string>();
  }

  if (node["namespace"] && node["namespace"].IsScalar()) {
    rhs->ns = node["namespace"].as<std::string>();
  }

  return true;
}
