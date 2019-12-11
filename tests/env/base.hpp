#ifndef YTC_TESTS_ENV_BASE_HPP_
#define YTC_TESTS_ENV_BASE_HPP_

#include <gtest/gtest.h>

#include <string>

class TestEnvironment : public ::testing::Environment {
public:
  void SetUp() override;
  static std::string cwd();
  static std::string tests_root();
};

#endif // YTC_TESTS_ENV_BASE_HPP_
