cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

include(../../../../cmake/FindSDL2.cmake)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIRS})

set(sdl2_platform_src sdl2_platform.c)

add_library(sdl2_platform STATIC ${sdl2_platform_src})

set_target_properties(sdl2_platform PROPERTIES 
					  C_STANDARD 11
					  POSITION_INDEPENDENT_CODE ON)

if(UNIX)
	target_link_libraries(sdl2_platform pthread)
endif()

target_link_libraries(sdl2_platform ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})

source_group("src" FILES ${sdl2_platform_src})
