#include "ytc/yaml/configmap.hpp"
#include "ytc/configmap.hpp"

YAML::Node YAML::convert<ConfigMapPtr>::encode(const ConfigMapPtr &cptr) {
  Node node;

  node["apiVersion"] = cptr->version_;
  node["kind"] = cptr->kind_;
  node["metadata"] = std::make_shared<Metadata>(cptr->metadata_);
  node["data"] = cptr->data_;
  node["example.property.file"] = cptr->file_;

  return node;
}

bool YAML::convert<ConfigMapPtr>::decode(const YAML::Node &node,
                                         ConfigMapPtr &cptr) {
  if (!node.IsMap()) {
    return false;
  }

  if (node["apiVersion"] && node["apiVersion"].IsScalar()) {
    cptr->version_ = node["apiVersion"].as<std::string>();
  }

  if (node["kind"] && node["kind"].IsScalar()) {
    cptr->kind_ = node["kind"].as<std::string>();
  }

  if (node["metadata"] && node["metadata"].IsMap()) {
    auto m = std::make_shared<Metadata>();
    YAML::convert<MetadataPtr>::decode(node["metadata"], m);
    cptr->metadata_ = *m;
  }

  if (node["data"] && node["data"].IsMap()) {
    cptr->data_ = node["data"].as<std::map<std::string, std::string>>();
  }

  if (node["example.property.file"] &&
      node["example.property.file"].IsScalar()) {
    cptr->file_ = node["example.property.file"].as<std::string>();
  }

  return true;
}
