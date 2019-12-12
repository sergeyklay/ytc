#ifndef YTC_METADATA_HPP_
#define YTC_METADATA_HPP_

#include "ytc/metadata/yaml/metadata.hpp"
#include <string>

class Metadata {
public:
  Metadata();

  bool operator==(const Metadata &rhs) const;

  std::string created_at;
  std::string name;
  std::string ns;
};

#endif // YTC_CONFIGMAP_HPP_
