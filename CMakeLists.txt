cmake_minimum_required(VERSION 3.10)
project(c_algorithms)

set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

include_directories(include)
add_subdirectory(src)
add_subdirectory(tests)
