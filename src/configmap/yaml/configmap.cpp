#include "ytc/yaml/configmap.hpp"
#include "ytc/configmap.hpp"

YAML::Node YAML::convert<ConfigMapPtr>::encode(const ConfigMapPtr &rhs) {
  Node node;
  // TODO(serghei): Not implemented
  return node;
}

bool YAML::convert<ConfigMapPtr>::decode(const YAML::Node &node,
                                         ConfigMapPtr &rhs) {
  if (!node.IsMap()) {
    return false;
  }

  if (node["apiVersion"] && node["apiVersion"].IsScalar()) {
    rhs->version = node["apiVersion"].as<std::string>();
  }

  if (node["kind"] && node["kind"].IsScalar()) {
    rhs->kind = node["kind"].as<std::string>();
  }

  if (node["metadata"] && node["metadata"].IsMap()) {
    // TODO(serghei): Not implemented
    // rhs->meta= node["metadata"].as<Metadata>();
  }

  if (node["data"] && node["data"].IsMap()) {
    rhs->data = node["data"].as<std::map<std::string, std::string>>();
  }

  if (node["example.property.file"] &&
      node["example.property.file"].IsScalar()) {
    rhs->file = node["example.property.file"].as<std::string>();
  }

  return true;
}