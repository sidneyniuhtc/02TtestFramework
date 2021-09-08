cmake_minimum_required(VERSION 3.5)

set(PRROJ_NAME "02Math")
set(PRROJ_LIB "lib${PRROJ_NAME}")
set(PRROJ_TEST "Test${PRROJ_NAME}")

project (${PRROJ_NAME})

# include all files
include_directories("${CMAKE_SOURCE_DIR}/include")
message("include_directories(${PROJ_INCLUDE_DIRS})")
set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE PROJ_HEADERS "${CMAKE_SOURCE_DIR}/include/*.hpp")

# create our library
file(GLOB_RECURSE PRROJ_LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_library("${PRROJ_LIB}" ${PRROJ_LIB_SOURCES} ) 



# add our test file

#find googleTest
find_package(GTest)
if(GTEST_FOUND)
	target_include_directories(${PRROJ_TEST} PRIVATE ${GTEST_INCLUDE_DIRS})
	target_link_libraries(${PRROJ_TEST} ${GTEST_BOTH_LIBRARIES})
endif()

file(GLOB_RECURSE PRROJ_TEST_SOURCES "${CMAKE_SOURCE_DIR}/test/*.cpp")
add_executable(${PRROJ_TEST} ${PRROJ_TEST_SOURCES} ${PROJ_HEADERS})
target_link_libraries(${PRROJ_TEST} ${PRROJ_LIB})