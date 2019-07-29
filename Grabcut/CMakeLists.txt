cmake_minimum_required(VERSION 3.12)
project(Grabcut)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(Grabcut main.cpp grabcut.cpp grabcut.h)

target_link_libraries(Grabcut ${OpenCV_LIBS})