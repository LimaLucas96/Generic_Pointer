cmake_minimum_required(VERSION 3.5)
project (SmallRangesLibrary)

#=== FINDING PACKAGES ===#

# Locate GTest package (library)
#find_package(GTest REQUIRED)
include_directories( ${GTEST_INCLUDE_DIRS})

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )
set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

#Include dir
include_directories( include )

#=== Library ===

# We want to build a static library.
add_library(Ranges STATIC "src/min.cpp")

#define C++11 as the standard.
target_compile_features(Ranges PUBLIC cxx_std_11)

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "make install" to apply
install(TARGETS Ranges ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib)

#=== Test target ===

# The file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES_TEST "test/*.cpp" )

# Define the sources
add_executable(run_tests ${SOURCES_TEST} )

set ( MY_GTEST_LIB "libgtest.a" "libgtest_main.a" )

# Link with the google test libraries.
target_link_libraries(run_tests PRIVATE ${MY_GTEST_LIB} PRIVATE pthread PRIVATE Ranges )

#define C++11 as the standard.
target_compile_features(run_tests PUBLIC cxx_std_11)
