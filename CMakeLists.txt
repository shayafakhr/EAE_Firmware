cmake_minimum_required(VERSION 3.10)
project(EAE_Firmware)

set(CMAKE_CXX_STANDARD 17)

add_executable(pid_control pid_control.cpp)
add_executable(canbus_simulation canbus_simulation.cpp)
