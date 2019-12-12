#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "ytc/metadata.hpp"

TEST(MetadataTest, EncodeClass) {
  MetadataPtr metadata = std::make_shared<Metadata>(
      "2016-02-18T19:14:38Z", "example-config", "default");

  YAML::Node expected;
  expected["metadata"] = YAML::convert<MetadataPtr>::encode(metadata);

  YAML::Node actual =
      YAML::Load("metadata: {creationTimestamp: 2016-02-18T19:14:38Z, "
                 "name: example-config, namespace: default}");

  EXPECT_EQ(*actual, expected);
}
