#include <ytc/configmap.hpp>

#include <tuple>
#include <utility>

ConfigMap::ConfigMap()
    : version_{"alpha"}, kind_{"Sample"}, metadata_{}, data_{}, file_{""} {}

ConfigMap::ConfigMap(std::string version, std::string kind,
                     const Metadata &metadata, ConfigData data,
                     std::string file)
    : version_(std::move(version)), kind_(std::move(kind)), metadata_(metadata),
      data_(std::move(data)), file_(std::move(file)) {}

bool ConfigMap::operator==(const ConfigMap &rhs) const {
  auto lhs_key = std::tie(version_, kind_, metadata_, data_, file_);
  auto rhs_key =
      std::tie(rhs.version_, rhs.kind_, rhs.metadata_, rhs.data_, rhs.file_);

  return lhs_key == rhs_key;
}
