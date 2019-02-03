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

#include "nx_io.h"

#include <stdlib.h>
#include <stdarg.h>

#include <unicode/ustdio.h>
#include <unicode/uchar.h>
#include <unicode/ustring.h>

NX_EXPORT_SYMBOLS_BEGIN

/******************************************************************/
void nx_printf(const char *fmt, ...)
{
    UChar buf[1024];
    
    va_list vargs;
    va_start(vargs, fmt);
    
    u_snprintf(buf, sizeof(buf), "%s", fmt);
    u_vfprintf_u(u_get_stdout(), buf, vargs);

    va_end(vargs);
}

/******************************************************************/
struct nx_file* nx_fopen(const char *file_path, const char *perm, const char* encoding)
{
    /* Default to UTF-8 if no specific encoding is specified */
    const char* enc = encoding == 0 ? u8"UTF-8" : encoding;
    return (struct nx_file*)u_fopen(file_path,perm,0,enc);
}

/******************************************************************/
void nx_fclose(struct nx_file *file)
{
    u_fclose((UFILE*)file);
}

/******************************************************************/
int nx_fwrite(struct nx_file *file,  const char *fmt, ...)
{
    UChar buffer[1024];
    int result = 0;
    
    va_list vargs;
    va_start(vargs, fmt);
    
    u_snprintf(buffer, sizeof(buffer), "%s", fmt);
    result = u_vfprintf_u((UFILE*)file, buffer, vargs);
    
    va_end(vargs);
    
    return result;
}

/******************************************************************/
int nx_fread(struct nx_file *file, char *buffer, int buffer_size)
{
    UChar priv_buff[1024];
    const int max_read = NX_MIN(sizeof(priv_buff), buffer_size);
    int char_read = 0;
    UErrorCode error = 0;
    
    while(!u_feof((UFILE*)file) && (char_read < buffer_size)){
        const int new_chars = u_file_read(priv_buff, max_read, (UFILE*)file);
        int chars_written = 0;
        u_strToUTF8(buffer + char_read, buffer_size, &chars_written, priv_buff, new_chars, &error);
        char_read += chars_written;
    }
    
    return char_read;
}

/******************************************************************/
void nx_fflush(struct nx_file *file)
{
    u_fflush((UFILE*)file);
}

/******************************************************************/
bool nx_feof(struct nx_file *file)
{
    return u_feof((UFILE*)file);
}

/******************************************************************/
void nx_frewind(struct nx_file *file)
{
    u_frewind((UFILE*)file);
}

/******************************************************************/
int nx_fseek(struct nx_file *file, int offset, int whence)
{
    return fseek(nx_getfile(file), offset, whence);
}

/******************************************************************/
FILE* NX_API nx_getfile(struct nx_file *file)
{
    return u_fgetfile((UFILE*)file);
}

NX_EXPORT_SYMBOLS_END
