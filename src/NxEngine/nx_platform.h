/***************************************************************************\
 This file is part of the NxEngine project.
 Copyright 2019 Patrik Jeppsson
 
 NxEngine is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 NxEngine is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with NyxEngine. If not, see <http://www.gnu.org/licenses/>.
 \***************************************************************************/

#ifndef __NX_PLATFORM_H__
#define __NX_PLATFORM_H__

#pragma once 

#include "nx_compiler.h"

/*
	Platform macros
	
	Windows: NX_OS_WIN32
	Windows 64-bit: NX_OS_WIN64
	
	Linux: NX_OS_LINUX
	Linux 64-bit: NX_OS_LINUX64
 
	Mac OS X: NX_OS_MACOS
	Mac OS X 64-bit: NX_OS_MACOS64
 
	FreeBSD: NX_OS_FREEBSD
	FreeBSD 64-bit: NX_OS_FREEBSD64
 */

/* Dection of Microsoft Windows */
#if(defined(_WIN32) || defined(_WINDOWS))
#	define NX_OS_WIN32
#	if (defined(_WIN64) || defined(_M_X64))
#		define NX_OS_WIN64
#	endif
#endif

/* Detection of GNU/Linux */
#if(defined(__linux) || defined(__linux__))
#	define NX_OS_LINUX
#	ifdef __x86_64__
#		define NX_OS_LINUX64
#	endif
#endif

/* Detection of Apple OS X */
#if defined(__APPLE__)
#	define NX_OS_MACOS
#	ifdef __LP64__
#		define NX_OS_MACOS64
#	endif
#endif

/* Detection of FreeBSD */
#if defined(__FreeBSD__)
#	define NX_OS_FREEBSD
#	ifdef __x86_64__
#		define NX_OS_FREEBSD64
#	endif
#endif

#if defined(NX_OS_WIN64) || defined(NX_OS_LINUX64) || defined(NX_OS_MACOS64) || defined(NX_OS_FREEBSD64)
#	define NX_OS_ARCH64
#else
#	define NX_OS_ARCH32
#endif

#if defined(NX_OS_ARCH64)
#   define NX_POINTER_SIZE 8
#else
#   define NX_POINTER_SIZE 4
#endif

/* Library defines for exporting symbols (needed for Windows) */
#ifdef NX_OS_WIN32
#	define NX_EXPORT __declspec(dllexport)
#	define NX_IMPORT __declspec(dllimport)
#   define NX_EXPORT_SYMBOLS_BEGIN
#   define NX_EXPORT_SYMBOLS_END
#else
#	define NX_EXPORT __attribute__((visibility("default")))
#	define NX_IMPORT
#if(defined(NX_CC_CLANG) || defined(NX_CC_GCC))
#   define NX_EXPORT_SYMBOLS_BEGIN _Pragma("GCC visibility push(default)")
#   define NX_EXPORT_SYMBOLS_END _Pragma("GCC visibility pop")
#else
#   define NX_EXPORT_SYMBOLS_BEGIN
#   define NX_EXPORT_SYMBOLS_END
#endif
#endif

#ifdef NX_STD_CPP
#   define NX_EXTERN_C extern "C"
#else
#   define NX_EXTERN_C
#endif

#endif
