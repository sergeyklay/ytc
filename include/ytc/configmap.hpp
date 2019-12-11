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

private:
  std::string version_;
  std::string kind_;
  Metadata meta_;
  std::map<std::string, std::string> data_;
  std::string file_;
};

using ConfigMapPtr = std::shared_ptr<ConfigMap>;

namespace YAML {
template <> struct convert<ConfigMapPtr> {
  static Node encode(const ConfigMapPtr &rhs);
  static bool decode(const Node &node, ConfigMapPtr &c);
};
} // namespace YAML

#endif // YTC_CONFIGMAP_HPP_
