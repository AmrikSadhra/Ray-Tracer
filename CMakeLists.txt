cmake_minimum_required(VERSION 3.3)
project(Ray_Tracer)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES main.c Operators.c Operators.h FileHandling.c FileHandling.h)
add_executable(Ray_Tracer ${SOURCE_FILES})