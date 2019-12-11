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

  EXPECT_EQ(c->GetVersion(), "v1");
  EXPECT_EQ(c->GetKind(), "ConfigMap");

  // EXPECT_EQ(c->GetFile(), "ConfigMap");
}
