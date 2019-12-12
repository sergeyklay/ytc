#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>

#include "env/base.hpp"
#include "ytc/configmap.hpp"
#include "ytc/metadata.hpp"

TEST(ConfigMapTest, EncodeClass) {
  auto tests_root = TestEnvironment::tests_root();
  if (tests_root.empty()) {
    GTEST_SKIP();
  }

  Metadata metadata{"2016-02-18T19:14:38Z", "example-config", "default"};
  ConfigMap configmap(
      "v1", "ConfigMap", metadata,
      {
          {"example.property.1", "hello"},
          {"example.property.2", "world"},
      },
      "property.1=value-1\nproperty.2=value-2\nproperty.3=value-3");

  ConfigMapPtr cptr = std::make_shared<ConfigMap>(configmap);

  YAML::Node expected;
  expected["metadata"] = YAML::convert<ConfigMapPtr>::encode(cptr);

  YAML::Node actual = YAML::LoadFile(tests_root + "/fixtures/configmap.yml");

  EXPECT_EQ(*actual, expected);
}
