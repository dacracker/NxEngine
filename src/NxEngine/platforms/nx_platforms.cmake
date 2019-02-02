cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set_property(CACHE platform PROPERTY STRINGS "sdl2")

if(${platform} MATCHES "sdl2")
	add_subdirectory(platforms/sdl2)
endif()
