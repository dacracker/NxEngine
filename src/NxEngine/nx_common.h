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
 along with NxEngine. If not, see <http://www.gnu.org/licenses/>.
 \***************************************************************************/

#ifndef __NX_COMMON_H__
#define __NX_COMMON_H__

#pragma once

#include "nx_platform.h"
#include "nx_types.h"

#ifdef NX_BUILD
#   define NX_API NX_EXTERN_C NX_EXPORT
#else
#   define NX_API NX_EXTERN_C NX_IMPORT
#endif

#define NX_UNUSED(x) (void)x;

#define NX_MAX(a,b) ({ __typeof__ (a) _a = (a); \
                      __typeof__ (b) _b = (b); \
                      _a > _b ? _a : _b; })

#define NX_MIN(a,b) ({ __typeof__ (a) _a = (a); \
                      __typeof__ (b) _b = (b); \
                      _a < _b ? _a : _b; })

#endif
