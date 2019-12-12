#include "ytc/metadata.hpp"

#include <tuple>
#include <utility>

Metadata::Metadata()
    : created_at_{"00-00-00T00:00:00Z"}, name_{"example"}, ns_{"ytc"} {}

Metadata::Metadata(std::string created_at, std::string name, std::string ns)
    : created_at_(std::move(created_at)), name_(std::move(name)),
      ns_(std::move(ns)) {}

bool Metadata::operator==(const Metadata &rhs) const {
  auto lhs_key = std::tie(created_at_, name_, ns_);
  auto rhs_key = std::tie(rhs.created_at_, rhs.name_, rhs.ns_);

  return lhs_key == rhs_key;
}

Metadata &Metadata::operator=(const Metadata &rhs) = default;
