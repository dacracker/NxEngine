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

#include "nx_log.h"

#include <stdarg.h>
#include <stdio.h>

NX_EXPORT_SYMBOLS_BEGIN

/******************************************************************************************/
void nx_log(enum nx_log_category cat, const char* msg, ...)
{
    char format[1024];
    
    va_list args;
    va_start(args, msg);
   
    snprintf(format, sizeof(format), "%s\n", msg);

    vprintf(format, args);
    va_end(args);
}

NX_EXPORT_SYMBOLS_END
