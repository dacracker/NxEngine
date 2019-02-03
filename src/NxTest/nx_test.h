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

#ifndef __NX_TEST_H__
#define __NX_TEST_H__

#pragma once

#include "../NxEngine/nx_platform.h"

#include <string.h>

#ifdef NX_TEST_BUILD
#   define NX_TEST_API NX_EXTERN_C NX_EXPORT
#else
#   define NX_TEST_API NX_EXTERN_C NX_IMPORT
#endif

struct nx_test_status {
    int total;
    int fails;
};

typedef void (*nx_test)(void*);

NX_TEST_API void _nx_test_assert(struct nx_test_status *status, int line, const char *func, const char *file, int result);

#define nx_test_assert(_expr_) _nx_test_assert((struct nx_test_status *)data, __LINE__, __func__, __FILE__, _expr_)

#define nx_test_run(_test_ary_) struct nx_test_status test_status;\
                                memset(&test_status, 0, sizeof(struct nx_test_status)); \
                                for(int i = 0; i < sizeof(_test_ary_)/sizeof(_test_ary_[0]); ++i)\
                                    (*_test_ary_[i])(&test_status);

#endif
