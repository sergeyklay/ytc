#ifndef YTC_METADATA_HPP_
#define YTC_METADATA_HPP_

#include <string>
#include <ytc/metadata/yaml/metadata.hpp>

class Metadata {
public:
  Metadata();
  explicit Metadata(std::string created_at, std::string name, std::string ns);

  /**
   * @brief Encode Metadata object to a Yaml Node.
   *
   * @param mptr The smart pointer to a Metadata instance
   * @return Yaml Node
   */
  friend YAML::Node YAML::convert<MetadataPtr>::encode(const MetadataPtr &mptr);

  /**
   * @brief Decode Yaml Node to a Metadata object.
   *
   * @param node Yaml Node
   * @param mptr The smart pointer to a Metadata instance
   * @return true on success, false otherwise
   */
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
