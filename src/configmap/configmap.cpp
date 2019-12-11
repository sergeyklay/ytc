#include "ytc/configmap.hpp"
#include <iostream>
#include <tuple>

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
    std::cout << "Setting apiVersion" << std::endl;
    rhs->SetVersion(node["apiVersion"].as<std::string>());
  }

  if (node["kind"] && node["kind"].IsScalar()) {
    std::cout << "Setting kind" << std::endl;
    rhs->SetKind(node["kind"].as<std::string>());
  }

  if (node["metadata"] && node["metadata"].IsMap()) {
    std::cout << "Setting metadata" << std::endl;
    // TODO(serghei): Not implemented
    // rhs->SetMeta(node["metadata"].as<Metadata>());
  }

  if (node["data"] && node["data"].IsMap()) {
    std::cout << "Setting data" << std::endl;
    rhs->SetData(node["data"].as<std::map<std::string, std::string>>());
  }

  if (node["example.property.file"] &&
      node["example.property.file"].IsScalar()) {
    std::cout << "Setting example.property.file" << std::endl;
    rhs->SetFile(node["example.property.file"].as<std::string>());
  }

  return true;
}

ConfigMap::ConfigMap()
    : version_{"v1"}, kind_{"ConfigMap"}, meta_{}, data_{}, file_{""} {}

void ConfigMap::SetVersion(std::string version) {
  version_ = std::move(version);
}
void ConfigMap::SetKind(std::string kind) { kind_ = std::move(kind); }
void ConfigMap::SetMeta(Metadata meta) { meta_ = std::move(meta); }

void ConfigMap::SetData(std::map<std::string, std::string> data) {
  data_ = std::move(data);
}
void ConfigMap::SetFile(std::string file) { file_ = std::move(file); }

bool ConfigMap::operator==(const ConfigMap &rhs) const {
  auto lhs_key = std::tie(version_, kind_, meta_, data_, file_);
  auto rhs_key =
      std::tie(rhs.version_, rhs.kind_, rhs.meta_, rhs.data_, rhs.file_);

  return lhs_key == rhs_key;
}
