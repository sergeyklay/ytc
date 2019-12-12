#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "ytc/metadata.hpp"

TEST(MetadataTest, DecodeString) {
  YAML::Node node =
      YAML::Load("metadata: {creationTimestamp: 2016-02-18T19:14:38Z, "
                 "name: example-config, namespace: default}");

  Metadata expected("2016-02-18T19:14:38Z", "example-config", "default");
  MetadataPtr actual = std::make_shared<Metadata>();

  EXPECT_TRUE(YAML::convert<MetadataPtr>::decode(node["metadata"], actual));
  EXPECT_EQ(*actual, expected);
}
