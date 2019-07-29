cmake_minimum_required(VERSION 3.12)
project(Cut)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(Cut main.cpp)

target_link_libraries(Cut ${OpenCV_LIBS})