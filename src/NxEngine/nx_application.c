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

#include "nx_application.h"
#include "nx_log.h"

#include "platforms/nx_platform_impl.h"

#include <string.h>

struct nx_app {
    struct _nx_platform_impl platform;
    int subsystems;
    bool quit;
} app;

NX_EXPORT_SYMBOLS_BEGIN

/******************************************************************************************/
int nx_init(int subsystems)
{
    memset(&app, 0, sizeof(struct nx_app));
    app.subsystems = NX_INIT_CORE;
    
    if(subsystems & NX_INIT_GUI)
        app.subsystems &= NX_INIT_GUI;
    
    if(subsystems & NX_INIT_AUDIO)
        app.subsystems &= NX_INIT_AUDIO;
    
    nx_log(NX_LOG_SYSTEM, "NxEngine - Initializing...");
    
    if(_nx_platform_init(&app.platform) != 0) {
        nx_log(NX_LOG_ERROR, "NxEngine - Error: failed to detect platform!");
        return 1;
    }
    
    if((*app.platform.init)() != 0) {
        nx_log(NX_LOG_ERROR, "NxEngine - Error: failed to initialize platform!");
        return 1;
    }
    
    return 0;
}

/******************************************************************************************/
void nx_shutdown(void)
{
    if(app.platform.shutdown != 0)
        (*app.platform.shutdown)();
    
    nx_log(NX_LOG_SYSTEM, "NxEngine - shutdown, bye!");
}

/******************************************************************************************/
int nx_subsystems()
{
    return app.subsystems;
}

/******************************************************************************************/
void nx_exec(void)
{
    
}

/******************************************************************************************/
void nx_quit(void)
{
    app.quit = true;
}

NX_EXPORT_SYMBOLS_END
