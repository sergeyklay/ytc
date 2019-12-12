#ifndef YTC_CONFIGMAP_HPP_
#define YTC_CONFIGMAP_HPP_

#include <string>

#include "ytc/metadata.hpp"
#include "ytc/yaml/configmap.hpp"

using ConfigData = std::map<std::string, std::string>;

class ConfigMap {
public:
  ConfigMap();
  explicit ConfigMap(std::string version, std::string kind,
                     const Metadata &metadata, ConfigData data,
                     std::string file);

  friend YAML::Node YAML::convert<ConfigMapPtr>::encode(const ConfigMapPtr &rhs);
  friend bool YAML::convert<ConfigMapPtr>::decode(const YAML::Node &node,
                                                  ConfigMapPtr &cptr);

  bool operator==(const ConfigMap &rhs) const;

private:
  std::string version_;
  std::string kind_;
  Metadata metadata_;
  ConfigData data_;
  std::string file_;
};

#endif // YTC_CONFIGMAP_HPP_
