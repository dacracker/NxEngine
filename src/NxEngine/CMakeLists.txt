cmake_minimum_required(VERSION 3.9.0 FATAL_ERROR)

set(platform "sdl2" CACHE STRING "Game engine backend")
include(platforms/nx_platforms.cmake)

set(nx_inc nx_common.h
		   nx_compiler.h
		   nx_platform.h
		   nx_types.h
		   nx_application.h
		   nx_list.h
		   nx_log.h
		   nx_events.h)

set(nx_platform_inc platforms/nx_platform_impl.h)

set(nx_src nx_application.c
		   nx_list.c
		   nx_log.c)

add_library(NxEngine SHARED ${nx_inc} ${nx_platform_inc} ${nx_src})

set_target_properties(NxEngine PROPERTIES 
					  DEFINE_SYMBOL NX_BUILD
					  C_STANDARD 11
					  C_VISIBILITY_PRESET hidden
					  POSITION_INDEPENDENT_CODE ON)

target_link_libraries(NxEngine ${platform}_platform)

source_group("src" FILES ${nx_inc} ${nx_src})
source_group("src\\platforms" FILES ${nx_platform_inc})
