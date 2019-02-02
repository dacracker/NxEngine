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

#include <SDL.h>
#include <SDL_stdinc.h>
#include <SDL_assert.h>

#include "../../nx_application.h"
#include "../nx_platform_impl.h"

/******************************************************************************************/
static int _sdl2_init(void)
{
    if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0){
        SDL_Log("NxEngine - failed to initialize SDL2, error %s", SDL_GetError());
        return 1;
    }
    
    if(nx_subsystems() & NX_INIT_GUI){
        if(SDL_InitSubSystem(SDL_INIT_VIDEO) != 0){
            SDL_Log("NxEngine - failed to initialize SDL2 video subsystem, error %s", SDL_GetError());
            return 2;
        }
    }
    
    return 0;
}

/******************************************************************************************/
static void _sdl2_shutdown()
{
    SDL_Quit();
}

/******************************************************************************************/
int _nx_platform_init(struct _nx_platform_impl *impl)
{
    impl->init = &_sdl2_init;
    impl->shutdown = &_sdl2_shutdown;
    
    return 0;
}
