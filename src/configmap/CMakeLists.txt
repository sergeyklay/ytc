# Add definition for config library.
add_library(configmap STATIC configmap.cpp)

target_include_directories(configmap
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
