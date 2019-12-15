#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include <string>

#include <ytc/configmap.hpp>
#include <ytc/metadata.hpp>

TEST(ConfigMapTest, EncodeClass) {
  Metadata metadata{"2019-12-31T23:59:59Z", "ho-ho-ho", "old-year"};
  ConfigMap configmap(
      "v1", "ConfigMap", metadata,
      {
          {"example.property.1", "hello"},
          {"example.property.2", "world"},
      },
      "property.1=value-1\nproperty.2=value-2\nproperty.3=value-3");

  ConfigMapPtr cptr = std::make_shared<ConfigMap>(configmap);
  YAML::Node yaml = YAML::convert<ConfigMapPtr>::encode(cptr);

  EXPECT_TRUE(yaml.IsMap());

  EXPECT_EQ("v1", yaml["apiVersion"].as<std::string>());
  EXPECT_EQ("ConfigMap", yaml["kind"].as<std::string>());

  EXPECT_TRUE(yaml["metadata"].IsMap());
  auto md = yaml["metadata"];

  EXPECT_EQ("2019-12-31T23:59:59Z", md["creationTimestamp"].as<std::string>());
  EXPECT_EQ("ho-ho-ho", md["name"].as<std::string>());
  EXPECT_EQ("old-year", md["namespace"].as<std::string>());

  EXPECT_TRUE(yaml["data"].IsMap());
  auto data = yaml["data"];

  EXPECT_EQ("hello", data["example.property.1"].as<std::string>());
  EXPECT_EQ("world", data["example.property.2"].as<std::string>());

  EXPECT_EQ("property.1=value-1\nproperty.2=value-2\nproperty.3=value-3",
            yaml["example.property.file"].as<std::string>());
}
