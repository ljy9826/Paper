cmake_minimum_required(VERSION 3.12)
project(calcHist)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(calcHist main.cpp)

target_link_libraries(calcHist ${OpenCV_LIBS})