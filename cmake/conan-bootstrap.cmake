# Conan bootstrap
macro(conan_bootstrap)
  if(NOT EXISTS "${PROJECT_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.14/conan.cmake"
      "${PROJECT_BINARY_DIR}/conan.cmake")
  endif()

  include(${PROJECT_BINARY_DIR}/conan.cmake)
  conan_check(REQUIRED)
endmacro()
