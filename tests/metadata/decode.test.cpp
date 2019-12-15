#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include <ytc/metadata.hpp>

TEST(MetadataTest, DecodeString) {
  YAML::Node yaml = YAML::Load(R"(
{
  name: example-config,
  namespace: default,
  creationTimestamp: 2016-02-18T19:14:38Z
}
)");

  Metadata expected("2016-02-18T19:14:38Z", "example-config", "default");
  MetadataPtr actual = std::make_shared<Metadata>();

  EXPECT_TRUE(YAML::convert<MetadataPtr>::decode(yaml, actual));
  EXPECT_EQ(*actual, expected);
}

TEST(MetadataTest, DecodeInvalid) {
  YAML::Node yaml = YAML::Load("foo: bar");
  MetadataPtr actual = std::make_shared<Metadata>();
  EXPECT_FALSE(YAML::convert<MetadataPtr>::decode(yaml["foo"], actual));
}
