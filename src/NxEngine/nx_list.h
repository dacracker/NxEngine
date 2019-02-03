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

#ifndef __NX_LIST_H__
#define __NX_LIST_H__

#pragma once

#include "nx_common.h"

struct nx_list {
    int size,
        alloc;
    void *data[1];
};

NX_API void nx_list_init(struct nx_list *self);

NX_API void nx_list_destroy(struct nx_list *self);

NX_API void nx_list_append(struct nx_list *self, void *data);

NX_API void* nx_list_at(struct nx_list *self, int index);

#endif
