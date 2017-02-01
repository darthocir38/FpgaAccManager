cmake_minimum_required(VERSION 2.6)


project(boost-program-options-sample CXX)
set(PROJECT_EXEC "AccManager")


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector -s")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Werror -pedantic")

set(LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# Find Boost libs.
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_NO_SYSTEM_PATHS ON)
set(BOOST_INCLUDEDIR "${LIBS_DIR}/boost")
set(BOOST_LIBRARYDIR "${LIBS_DIR}/boost/libs")
find_package(Boost 1.60.0 REQUIRED program_options)
include_directories("${Boost_INCLUDE_DIRS}")
message(STATUS "Boost include dir: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")


set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cc")

add_executable("${PROJECT_EXEC}" "${SRC_FILES}")
target_link_libraries("${PROJECT_EXEC}" ${Boost_LIBRARIES})

