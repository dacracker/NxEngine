cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

project(NxEngine C)

# We want to mark all debug binaries with a d suffix
set(CMAKE_DEBUG_POSTFIX "d")

# We want to put all binaries in the same output dir	   
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# And we want all out libs to be in the same folderas the executables
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories("${PROJECT_BINARY_DIR}")

# Game engine library 
add_subdirectory(src/NxEngine)
add_subdirectory(src/NxTest)

add_subdirectory(tests)
