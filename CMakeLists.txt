cmake_minimum_required(VERSION 2.6)
include("common.cmake")

# ----------------------------------------
# Pathfinder
# ----------------------------------------
project(pathfinder C)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
#set(CMAKE_BUILD_TYPE Debug)

add_definitions(-std=gnu99)
#add_definitions(-mavx)
add_definitions(-msse4.1)
add_definitions(-pedantic)
add_definitions(-O3)
add_definitions(-Wall)
add_definitions(-Wextra)
add_definitions(-Wcast-align)
add_definitions(-w)

file(GLOB_RECURSE PATHFINDER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pathfinder/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pathfinder/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pathfinder/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pathfinder/*.cpp)

list(SORT PATHFINDER_SOURCES)
create_source_group("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/src" ${PATHFINDER_SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/lib/libuv/include)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(pathfinder STATIC ${PATHFINDER_SOURCES})

target_link_libraries (pathfinder
    ${CMAKE_SOURCE_DIR}/lib/libart/src/art.o)

GET_PROPERTY(pathfinder_location TARGET pathfinder PROPERTY LOCATION)

# ----------------------------------------
# Tests
# ----------------------------------------
file(GLOB_RECURSE TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/test/*.cpp)

list(SORT TEST_SOURCES)
create_source_group("Source Files" "${CMAKE_CURRENT_SOURCE_DIR}/src" ${TEST_SOURCES})
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/check-0.10.0)
include_directories(${CMAKE_SOURCE_DIR}/lib/check-0.10.0/src)

find_package(Threads REQUIRED)

add_executable (test
    ${TEST_SOURCES})

add_dependencies(test pathfinder)

# Libraries to link in reverse order because that's what ld requires.
target_link_libraries (test
    ${pathfinder_location}
    ${CMAKE_SOURCE_DIR}/lib/libart/src/art.o
    ${CMAKE_SOURCE_DIR}/lib/check-0.10.0/src/.libs/libcheck.a
    ${CMAKE_THREAD_LIBS_INIT})

if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries (test rt)
endif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
