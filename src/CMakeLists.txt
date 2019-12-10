# YTC libraries
add_subdirectory(configmap)

# Main
add_executable(ytc main.cpp)

target_include_directories(ytc
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(ytc PUBLIC configmap)
