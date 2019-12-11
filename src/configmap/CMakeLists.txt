# Add definition for config library.
add_library(configmap STATIC metadata.cpp yaml/configmap.cpp configmap.cpp)

target_include_directories(configmap
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(configmap PUBLIC CONAN_PKG::yaml-cpp)
