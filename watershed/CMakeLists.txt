cmake_minimum_required(VERSION 3.12)
project(watershed)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(watershed main.cpp)

target_link_libraries(watershed ${OpenCV_LIBS})