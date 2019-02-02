cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

set(nx_inc nx_test.h)

set(nx_src nx_test.c) 
 
add_library(NxTest SHARED ${nx_inc} ${nx_src})

set_target_properties(NxTest PROPERTIES 
					  DEFINE_SYMBOL NX_TEST_BUILD
					  C_STANDARD 11
					  C_VISIBILITY_PRESET hidden)

source_group("src" FILES ${nx_inc} ${nx_src})
