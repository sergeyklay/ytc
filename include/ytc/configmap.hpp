#ifndef YTC_CONFIGMAP_HPP_
#define YTC_CONFIGMAP_HPP_

#include <memory>
#include <string>
#include <yaml-cpp/yaml.h>

#include "ytc/metadata.hpp"

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

using ConfigMapPtr = std::shared_ptr<ConfigMap>;

namespace YAML {
template <> struct convert<ConfigMapPtr> {
  static Node encode(const ConfigMapPtr &rhs);
  static bool decode(const Node &node, ConfigMapPtr &c);
};
} // namespace YAML

#endif // YTC_CONFIGMAP_HPP_
