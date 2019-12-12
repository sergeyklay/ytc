# Set the compiler standard to C++17
macro(cxx_17)
  # Use C++17
  set(CMAKE_CXX_STANDARD 17)
  # Require (at least) it
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  # Don't use e.g. GNU extension (like -std=gnu++17) for portability
  set(CMAKE_CXX_EXTENSIONS OFF)
endmacro()
