cmake_minimum_required(VERSION 3.21)
project(LearningVulkan LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


function(add_exercise target source)
    add_executable(${target} "${source}")

    if(MSVC)
        target_compile_options(${target} PRIVATE
            /W4
            /permissive-
            $<$<CONFIG:Debug>:/JMC>
        )
    endif()
endfunction()


add_exercise(mem_01_01 cpp/MEM_objects_memory/01_objects_storage/mem_01_01_objects.cpp)
add_exercise(mem_01_02 cpp/MEM_objects_memory/01_objects_storage/mem_01_02_objects.cpp)
add_exercise(mem_01_03 cpp/MEM_objects_memory/01_objects_storage/mem_01_03_optimization.cpp)
add_exercise(mem_01_04 cpp/MEM_objects_memory/01_objects_storage/mem_01_04_storage_durations.cpp)
add_exercise(mem_01_05 cpp/MEM_objects_memory/01_objects_storage/mem_01_05_scope_storage_lifetime.cpp)

add_exercise(mem_02_01 cpp/MEM_objects_memory/02_object_lifetime/mem_02_01_lifetime.cpp)
add_exercise(mem_02_02 cpp/MEM_objects_memory/02_object_lifetime/mem_02_02_construction_order.cpp)
add_exercise(mem_02_03 cpp/MEM_objects_memory/02_object_lifetime/mem_02_03_return_local_address.cpp)
add_exercise(mem_02_04 cpp/MEM_objects_memory/02_object_lifetime/mem_02_04_dangling_vs_nullptr.cpp)
add_exercise(mem_02_05 cpp/MEM_objects_memory/02_object_lifetime/mem_02_05_temporary_lifetime.cpp)
add_exercise(mem_02_06 cpp/MEM_objects_memory/02_object_lifetime/mem_02_06_exception_unwinding.cpp)
add_exercise(mem_02_07 cpp/MEM_objects_memory/02_object_lifetime/mem_02_07_placement_new.cpp)

add_exercise(mem_03_01 cpp/MEM_objects_memory/03_object_relationships/mem_03_01_aliasing.cpp)
add_exercise(mem_03_02 cpp/MEM_objects_memory/03_object_relationships/mem_03_02_subobjects.cpp)
add_exercise(mem_03_03 cpp/MEM_objects_memory/03_object_relationships/mem_03_03_triviality.cpp)
add_exercise(mem_03_04 cpp/MEM_objects_memory/03_object_relationships/mem_03_04_undefined_behavior.cpp)

add_exercise(int_02 integration/MEM_objects_memory/int_02_object_routes.cpp)
