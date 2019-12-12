#include "ytc/metadata.hpp"

#include <tuple>
#include <utility>

Metadata::Metadata()
    : created_at{"00-00-00T00:00:00Z"}, name{"example"}, ns{"ytc"} {}

Metadata::Metadata(std::string created_at_, std::string name_, std::string ns_)
    : created_at(std::move(created_at_)), name(std::move(name_)),
      ns(std::move(ns_)) {}

bool Metadata::operator==(const Metadata &rhs) const {
  auto lhs_key = std::tie(created_at, name, ns);
  auto rhs_key = std::tie(rhs.created_at, rhs.name, rhs.ns);

  return lhs_key == rhs_key;
}

Metadata &Metadata::operator=(const Metadata &rhs) = default;
