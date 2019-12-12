#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include <string>

#include "ytc/metadata.hpp"

TEST(MetadataTest, ParseFile) {
  YAML::Node node =
      YAML::Load("metadata: {creationTimestamp: 2016-02-18T19:14:38Z, "
                 "name: example-config, namespace: default}");

  Metadata actual("2016-02-18T19:14:38Z", "example-config", "default");
  MetadataPtr m = std::make_shared<Metadata>();

  EXPECT_TRUE(YAML::convert<MetadataPtr>::decode(node["metadata"], m));
  EXPECT_EQ(*m, actual);
}
