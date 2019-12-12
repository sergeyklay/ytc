# YTC libraries
add_subdirectory(metadata)
add_subdirectory(configmap)

# Main
add_executable(ytc main.cpp)

# Setting this to the library only avoids errors in 3rd party dependencies
target_compile_options(ytc PUBLIC -Wall -Werror -pedantic)

target_include_directories(ytc
  PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_link_libraries(ytc
  PUBLIC metadata configmap)
