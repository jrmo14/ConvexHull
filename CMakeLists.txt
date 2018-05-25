cmake_minimum_required(VERSION 3.10)
project(ConvexHull C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_BUILD_TYPE Debug)

set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_PATH obj)

add_library(Utils src/utils/Utils.c src/utils/Vector.c src/utils/Point.c)

add_executable(ConvHull src/conv-hull.c)
add_executable(VECTest src/vectorTest.c)

target_link_libraries(ConvHull Utils)
target_link_libraries(VECTest Utils)
