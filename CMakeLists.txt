cmake_minimum_required(VERSION 3.11...3.16)

project(ytc
  LANGUAGES CXX
  VERSION 1.0.0
  DESCRIPTION "YAML Template Class example")

# See: https://github.com/conan-io/cmake-conan/issues/159
cmake_policy(SET CMP0025 NEW)

# Determine if ytc is built as a subproject (using add_subdirectory) or if it
# is the master project.
set(MASTER_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(MASTER_PROJECT ON)
  message(STATUS "CMake version: ${CMAKE_VERSION}")
endif()

# Provide path for cmake scripts
list(APPEND CMAKE_MODULE_PATH ${ytc_SOURCE_DIR}/cmake)

include(language-standard)
include(conan-bootstrap)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Set the compiler standard to C++17
cxx_17()

# Conan bootstrap
conan_bootstrap()

conan_cmake_run(
  CONANFILE conanfile.txt
  BASIC_SETUP CMAKE_TARGETS
  BUILD missing)

# Adjusts the standard library flags (libc++`, libstdc++, libstdc++11)
conan_set_libcxx()

# Code Coverage Configuration
add_library(coverage_config INTERFACE)

option(CODE_COVERAGE "Builds targets with code coverage instrumentation." OFF)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  # Add required flags (GCC & LLVM/Clang)
  target_compile_options(coverage_config INTERFACE
    -O0        # no optimization
    -g         # generate debug info
    --coverage # sets all required flags
    )

  if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
    target_link_options(coverage_config INTERFACE --coverage)
  else()
    target_link_libraries(coverage_config INTERFACE --coverage)
  endif()
endif()

add_subdirectory(src)

if(MASTER_PROJECT)
  include(CTest)
endif()

if(MASTER_PROJECT AND BUILD_TESTING)
  message(STATUS "Include test sources")
  add_subdirectory(tests)
endif()
