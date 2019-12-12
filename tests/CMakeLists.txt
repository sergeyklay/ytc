# Conan bootstrap
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_check(REQUIRED)

conan_cmake_run(
  CONANFILE conanfile.txt
  BASIC_SETUP CMAKE_TARGETS
  BUILD missing)

include(GoogleTest)
set(YTC_TESTS metadata_test configmap_test)

file(GLOB metadataFiles ${CMAKE_CURRENT_SOURCE_DIR}/metadata/*.test.cpp)
add_executable(metadata_test
  main.cpp
  env/base.cpp
  ${metadataFiles})

target_include_directories(metadata_test
  PUBLIC  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
          $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/metadata_>)

target_link_libraries(metadata_test
  PUBLIC  metadata
  PRIVATE CONAN_PKG::GTest)

gtest_discover_tests(metadata_test
  TEST_PREFIX gtest:
  PROPERTIES LABELS MetadataTest)

file(GLOB configmapFiles ${CMAKE_CURRENT_SOURCE_DIR}/configmap/*.test.cpp)
add_executable(configmap_test
  main.cpp
  env/base.cpp
  ${configmapFiles})

target_include_directories(configmap_test
  PUBLIC  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
          $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/configmap>)

target_link_libraries(configmap_test
  PUBLIC  metadata configmap
  PRIVATE CONAN_PKG::GTest)

gtest_discover_tests(configmap_test
  TEST_PREFIX gtest:
  PROPERTIES LABELS ConfigMapTest)

add_custom_target(check
  COMMAND ctest --output-on-failure
  DEPENDS ${YTC_TESTS}
  COMMENT "Run all tests..."
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
