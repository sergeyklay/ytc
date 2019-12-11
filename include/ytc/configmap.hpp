#ifndef YTC_CONFIGMAP_HPP_
#define YTC_CONFIGMAP_HPP_

#include <string>

#include "ytc/metadata.hpp"
#include "ytc/yaml/configmap.hpp"

class ConfigMap {
public:
  ConfigMap();

  bool operator==(const ConfigMap &rhs) const;

  std::string version;
  std::string kind;
  Metadata meta;
  std::map<std::string, std::string> data;
  std::string file;
};

#endif // YTC_CONFIGMAP_HPP_
