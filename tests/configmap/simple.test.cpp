#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include <string>

#include "env/base.hpp"
#include "ytc/configmap.hpp"

TEST(ConfigMapTest, ParseFile) {
  auto tests_root = TestEnvironment::tests_root();
  if (tests_root.empty()) {
    GTEST_SKIP();
  }

  YAML::Node node = YAML::LoadFile(tests_root + "/fixtures/configmap.yml");
  ConfigMapPtr c = std::make_shared<ConfigMap>();

  EXPECT_TRUE(YAML::convert<ConfigMapPtr>::decode(node, c));

  EXPECT_EQ(c->version, "v1");
  EXPECT_EQ(c->kind, "ConfigMap");

  EXPECT_EQ(c->metadata.created_at, "2016-02-18T19:14:38Z");
  EXPECT_EQ(c->metadata.name, "example-config");
  EXPECT_EQ(c->metadata.ns, "default");

  std::map<std::string, std::string> data{
      {"example.property.1", "hello"},
      {"example.property.2", "world"},
  };
  EXPECT_EQ(c->data, data);

  std::string file{
      "property.1=value-1\nproperty.2=value-2\nproperty.3=value-3"};
  EXPECT_EQ(c->file, file);
}
