cmake_minimum_required(VERSION 3.12)
project(otsu)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(otsu main.cpp)

target_link_libraries(otsu ${OpenCV_LIBS})
