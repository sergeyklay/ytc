# Add definition for metadata library
add_library(metadata STATIC
  yaml/metadata.cpp
  metadata.cpp)

target_include_directories(metadata
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# Setting this to the library only avoids errors in 3rd party dependencies
target_compile_options(metadata PUBLIC -Wall -Werror -pedantic)

target_link_libraries(metadata
  PUBLIC coverage_config
         CONAN_PKG::yaml-cpp)
