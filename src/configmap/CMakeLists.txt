# Add definition for configmap library
add_library(configmap STATIC
  yaml/configmap.cpp
  configmap.cpp)

target_include_directories(configmap
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Setting this to the library only avoids errors in 3rd party dependencies
target_compile_options(configmap PUBLIC -Wall -Werror -pedantic)

target_link_libraries(configmap
  PUBLIC coverage_config
         metadata
         CONAN_PKG::yaml-cpp)
