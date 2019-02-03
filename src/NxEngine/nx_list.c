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

#include "nx_list.h"

#include <stdlib.h>
#include <string.h>

/******************************************************************************************/
static int _nx_calc_next_alloc(int size)
{
    if(size <= 20)
        return size + 4;
    
    return size * 2;
}

/******************************************************************************************/
static void _nx_list_grow(int newsize, struct nx_list *self)
{
    if(self->alloc > newsize)
        return;
    
    const int next_alloc = _nx_calc_next_alloc(self->size);
    void *data = realloc(self->data, next_alloc * sizeof(void*));
    
    if(data != 0)
        *self->data = data;
}

NX_EXPORT_SYMBOLS_BEGIN

/******************************************************************************************/
void nx_list_init(struct nx_list *self)
{
    memset(self, 0, sizeof(struct nx_list));
}

/******************************************************************************************/
void nx_list_destroy(struct nx_list *self)
{
    free(self->data);
    self->alloc = 0;
    self->size = 0;
}

/******************************************************************************************/
void nx_list_append(struct nx_list *self, void *data)
{
    _nx_list_grow(self->size + 1, self);
    self->data[++self->size] = data;
}

/******************************************************************************************/
void* nx_list_at(struct nx_list *self, int index)
{
    return self->data[index];
}

NX_EXPORT_SYMBOLS_END
