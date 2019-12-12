#include "ytc/metadata.hpp"

#include <tuple>

Metadata::Metadata()
    : created_at{"00-00-00T00:00:00Z"}, name{"example"}, ns{"ytc"} {}

bool Metadata::operator==(const Metadata &rhs) const {
  auto lhs_key = std::tie(created_at, name, ns);
  auto rhs_key = std::tie(rhs.created_at, rhs.name, rhs.ns);

  return lhs_key == rhs_key;
}
