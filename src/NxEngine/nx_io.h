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

#ifndef __NX_IO_H__
#define __NX_IO_H__

#pragma once

#include "nx_common.h"

#include <stdio.h>

void NX_API nx_printf(const char* fmt, ...);

struct nx_file;

struct nx_file* NX_API nx_fopen(const char *file_path, const char *perm, const char* encoding);

/** Close the file */
void NX_API nx_fclose(struct nx_file *file);

/** Writes a UTF-8 encoded string to the file
  * Returns the number of characters written to the file (not bytes)
  */
int NX_API nx_fwrite(struct nx_file *file, const char *fmt, ...);

/** Read UTF-8 encoded characters from a file */
int NX_API nx_fread(struct nx_file *file, char *buffer, int buffer_size);

/** Flushes the the write buffer to disk */
void NX_API nx_fflush(struct nx_file *file);

/** Returns true if the file pointer is a the end of the file */
bool NX_API nx_feof(struct nx_file *file);

/** Set the file pointer to point at the beginning of the file */
void NX_API nx_frewind(struct nx_file *file);

/** Seeks to byte position in the file */
int NX_API nx_fseek(struct nx_file *file, int pos, int whence);

/** Returns the internal FILE pointer */
FILE* NX_API nx_getfile(struct nx_file *file);

#endif
