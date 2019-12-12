# Add definition for config library.
add_library(metadata STATIC
  yaml/metadata.cpp
  metadata.cpp)

target_include_directories(metadata
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(metadata PUBLIC CONAN_PKG::yaml-cpp)
