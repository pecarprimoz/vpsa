cmake_minimum_required(VERSION 3.8)
project(vaje2)

set(CMAKE_C_STANDARD 99)
find_package( Threads REQUIRED )


set(SOURCE_FILES serverLinux.cpp)
add_executable(vaje2 ${SOURCE_FILES})