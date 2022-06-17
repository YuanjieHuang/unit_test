cmake_minimum_required(VERSION 3.15)
project(GtestLearn C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CAMKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(SOURCE_FILES
    main.c
    include/func.h
    func.c
    A.cpp
    include/ex_func.h
    include/ex_func.c)

add_executable(GtestLearn ${SOURCE_FILES})
target_link_libraries(GtestLearn ${LIBRARIES})