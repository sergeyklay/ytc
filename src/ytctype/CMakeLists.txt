# Add definition for config library.
add_library(ytctype STATIC ytctype.cpp)

target_include_directories(ytctype
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
