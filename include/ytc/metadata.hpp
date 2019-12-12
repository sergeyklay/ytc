#ifndef YTC_METADATA_HPP_
#define YTC_METADATA_HPP_

#include "ytc/metadata/yaml/metadata.hpp"
#include <string>

class Metadata {
public:
  Metadata();
  explicit Metadata(std::string created_at, std::string name, std::string ns);

  friend YAML::Node YAML::convert<MetadataPtr>::encode(const MetadataPtr &mptr);
  friend bool YAML::convert<MetadataPtr>::decode(const YAML::Node &node,
                                                 MetadataPtr &mptr);

  bool operator==(const Metadata &rhs) const;
  Metadata &operator=(const Metadata &rhs);

private:
  std::string created_at_;
  std::string name_;
  std::string ns_;
};

#endif // YTC_CONFIGMAP_HPP_
