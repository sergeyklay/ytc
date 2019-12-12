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

  bool operator==(const ConfigMap &rhs) const;

  std::string version;
  std::string kind;
  Metadata metadata;
  ConfigData data;
  std::string file;
};

#endif // YTC_CONFIGMAP_HPP_
