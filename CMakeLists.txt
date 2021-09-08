cmake_minimum_required(VERSION 3.12)

set(PROJ_NAME "02Math")
set(PROJ_TEST "Test${PROJ_NAME}")
set(PROJ_LIB "lib${PROJ_NAME}")

project(${PROJ_NAME})

# include all files
include_directories("${PROJECT_SOURCE_DIR}/include")
set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/include")

# create our library
file(GLOB_RECURSE PROJ_LIB_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library("${PROJ_LIB}" ${PROJ_LIB_SOURCES} ) 

file(GLOB_RECURSE PROJ_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*.cpp")
add_executable(${PROJ_TEST} ${PROJ_TEST_SOURCES})
target_link_libraries(${PROJ_TEST} ${PROJ_LIB})
target_include_directories(${PROJ_TEST} PUBLIC ${PROJ_INCLUDE_DIRS})


# find googleTest
find_package(GTest)
if(GTEST_FOUND)
	target_include_directories(${PROJ_TEST} PRIVATE ${GTEST_INCLUDE_DIRS})
	target_link_libraries(${PROJ_TEST} ${GTEST_BOTH_LIBRARIES})
endif(GTEST_FOUND)

# thread for google test
find_package(Threads)
target_link_libraries(${PROJ_TEST} Threads::Threads)


# add test unit

enable_testing()
include(GoogleTest)
gtest_discover_tests(${PROJ_TEST})