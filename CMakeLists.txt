cmake_minimum_required(VERSION 3.21)

project(LearningVulkan LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    mem_01_01
    cpp/MEM_objects_memory/01_objects_storage/mem_01_01_objects.cpp
)

if(MSVC)
    target_compile_options(mem_01_01 PRIVATE /W4 /permissive-)
endif()