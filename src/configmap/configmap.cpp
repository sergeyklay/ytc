#include "ytc/configmap.hpp"

#include <tuple>
#include <utility>

ConfigMap::ConfigMap()
    : version{"alpha"}, kind{"Sample"}, metadata{}, data{}, file{""} {}

ConfigMap::ConfigMap(std::string version_, std::string kind_,
                     const Metadata &metadata_, ConfigData data_,
                     std::string file_)
    : version(std::move(version_)), kind(std::move(kind_)), metadata(metadata_),
      data(std::move(data_)), file(std::move(file_)) {}

bool ConfigMap::operator==(const ConfigMap &rhs) const {
  auto lhs_key = std::tie(version, kind, metadata, data, file);
  auto rhs_key =
      std::tie(rhs.version, rhs.kind, rhs.metadata, rhs.data, rhs.file);

  return lhs_key == rhs_key;
}
