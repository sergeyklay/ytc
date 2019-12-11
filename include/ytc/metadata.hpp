#ifndef YTC_METADATA_HPP_
#define YTC_METADATA_HPP_

#include <string>

class Metadata {
public:
  Metadata();
  bool operator==(const Metadata &rhs) const;

private:
  std::string created_at_;
  std::string name_;
  std::string ns_;
};

#endif // YTC_CONFIGMAP_HPP_
