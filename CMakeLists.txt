cmake_minimum_required(VERSION 3.10)
project(Algoritmi_Vaja1)

set(CMAKE_CXX_STANDARD 17)

# Glavni program
add_executable(sorting src/main.cpp src/sorting.cpp)
target_include_directories(sorting PRIVATE src)

# Testi
add_executable(tests tests/test_sort.cpp src/sorting.cpp)
target_include_directories(tests PRIVATE tests src)
