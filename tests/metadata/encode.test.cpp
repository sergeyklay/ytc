#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include <string>

#include "ytc/metadata.hpp"

TEST(MetadataTest, EncodeClass) {
  MetadataPtr metadata = std::make_shared<Metadata>(
      "2016-02-18T19:14:38Z", "example-config", "default");

  YAML::Node node;
  node["metadata"] = YAML::convert<MetadataPtr>::encode(metadata);

  EXPECT_TRUE(node.IsMap());

  EXPECT_EQ("2016-02-18T19:14:38Z",
            node["metadata"]["creationTimestamp"].as<std::string>());
  EXPECT_EQ("example-config", node["metadata"]["name"].as<std::string>());
  EXPECT_EQ("default", node["metadata"]["namespace"].as<std::string>());
}
