cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

include_directories("../src/NxEngine" "../src/NxTest")

set(init_test_src init_test.c)
set(tests_src ${init_test_src}) 

# Tests initialization  
add_executable(init_test ${init_test_src})

set_target_properties(init_test PROPERTIES 
					  C_STANDARD 11)

target_link_libraries(init_test NxEngine NxTest)

source_group("src" FILES ${tests_src})
