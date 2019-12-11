# Conan bootstrap
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_check(REQUIRED)

conan_cmake_run(
  CONANFILE conanfile.txt
  BASIC_SETUP CMAKE_TARGETS
  BUILD missing)

include(GoogleTest)
set(YTC_TESTS configmap_test)

file(GLOB configmapTestFiles ${CMAKE_CURRENT_SOURCE_DIR}/configmap/*.test.cpp)
add_executable(configmap_test main.cpp env/base.cpp ${configmapTestFiles})

target_include_directories(configmap_test
  PUBLIC  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
          $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/configmap>)

target_link_libraries(configmap_test
  PUBLIC  configmap
  PRIVATE CONAN_PKG::GTest)

gtest_discover_tests(configmap_test
  TEST_PREFIX gtest:
  PROPERTIES LABELS YamlTest)

add_custom_target(check
  COMMAND ctest --output-on-failure
  DEPENDS ${YTC_TESTS}
  COMMENT "Run all tests..."
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
