#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include <string>

#include "ytc/configmap.hpp"
#include "ytc/metadata.hpp"

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
  YAML::Node node = YAML::convert<ConfigMapPtr>::encode(cptr);

  EXPECT_TRUE(node.IsMap());

  EXPECT_EQ("v1", node["apiVersion"].as<std::string>());
  EXPECT_EQ("ConfigMap", node["kind"].as<std::string>());
  EXPECT_EQ("2019-12-31T23:59:59Z",
            node["metadata"]["creationTimestamp"].as<std::string>());
  EXPECT_EQ("ho-ho-ho", node["metadata"]["name"].as<std::string>());
  EXPECT_EQ("old-year", node["metadata"]["namespace"].as<std::string>());
  EXPECT_EQ("hello", node["data"]["example.property.1"].as<std::string>());
  EXPECT_EQ("world", node["data"]["example.property.2"].as<std::string>());
  EXPECT_EQ("property.1=value-1\nproperty.2=value-2\nproperty.3=value-3",
            node["example.property.file"].as<std::string>());
}
