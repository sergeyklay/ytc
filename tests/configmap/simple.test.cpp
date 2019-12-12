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

  Metadata metadata{"2016-02-18T19:14:38Z", "example-config", "default"};
  ConfigMap actual(
      "v1", "ConfigMap", metadata,
      {
          {"example.property.1", "hello"},
          {"example.property.2", "world"},
      },
      "property.1=value-1\nproperty.2=value-2\nproperty.3=value-3");

  EXPECT_EQ(*c, actual);
}
