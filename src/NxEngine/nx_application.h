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

#ifndef __NX_APPLICATION_H__
#define __NX_APPLICATION_H__

#pragma once

#include "nx_common.h"

enum nx_subsystem {
  NX_INIT_CORE = 1,
  NX_INIT_GUI = 2,
  NX_INIT_AUDIO = 4
};

/** Initialize the game engine */
int NX_API nx_init(int subsystems);

/** Shutdown the game engine */
void NX_API nx_shutdown(void);

/** Start the message loop */
void NX_API nx_exec(void);

/** Quits the message loop */
void NX_API nx_quit(void);

/** Initialized subsystems */
int nx_subsystems();

#endif
