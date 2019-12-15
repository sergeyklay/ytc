#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include <string>

#include <ytc/metadata.hpp>

TEST(MetadataTest, EncodeClass) {
  MetadataPtr metadata = std::make_shared<Metadata>(
      "2019", "example-config", "default");

  auto yaml = YAML::convert<MetadataPtr>::encode(metadata);

  EXPECT_TRUE(yaml.IsMap());

  EXPECT_EQ("2019", yaml["creationTimestamp"].as<std::string>());
  EXPECT_EQ("example-config", yaml["name"].as<std::string>());
  EXPECT_EQ("default", yaml["namespace"].as<std::string>());
}
