/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Mupen64plus-ui-console - core_interface.h                             *
 *   Mupen64Plus homepage: http://code.google.com/p/mupen64plus/           *
 *   Copyright (C) 2009 Richard Goedeken                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if !defined(CORE_INTERFACE_H)
#define CORE_INTERFACE_H

#include "m64p_types.h"
#include "m64p_common.h"
#include "m64p_frontend.h"
#include "m64p_config.h"
#include "m64p_debugger.h"

/* global variables from core_interface.c */
extern int g_CoreCapabilities;
extern int g_CoreAPIVersion;

extern m64p_handle g_ConfigCore;
extern m64p_handle g_ConfigVideo;
extern m64p_handle g_ConfigUI;

/* declarations of Core library handle and pointers to common functions */
extern m64p_dynlib_handle      CoreHandle;
extern ptr_CoreErrorMessage    CoreErrorMessage;

/* declarations of pointers to Core front-end functions */
extern ptr_CoreStartup         CoreStartup;
extern ptr_CoreShutdown        CoreShutdown;
extern ptr_CoreAttachPlugin    CoreAttachPlugin;
extern ptr_CoreDetachPlugin    CoreDetachPlugin;
extern ptr_CoreDoCommand       CoreDoCommand;
extern ptr_CoreOverrideVidExt  CoreOverrideVidExt;
extern ptr_CoreAddCheat        CoreAddCheat;
extern ptr_CoreCheatEnabled    CoreCheatEnabled;

/* declarations of pointers to Core config functions */
extern ptr_ConfigListSections     ConfigListSections;
extern ptr_ConfigOpenSection      ConfigOpenSection;
extern ptr_ConfigListParameters   ConfigListParameters;
extern ptr_ConfigSaveFile         ConfigSaveFile;
extern ptr_ConfigSetParameter     ConfigSetParameter;
extern ptr_ConfigGetParameter     ConfigGetParameter;
extern ptr_ConfigGetParameterType ConfigGetParameterType;
extern ptr_ConfigGetParameterHelp ConfigGetParameterHelp;
extern ptr_ConfigSetDefaultInt    ConfigSetDefaultInt;
extern ptr_ConfigSetDefaultFloat  ConfigSetDefaultFloat;
extern ptr_ConfigSetDefaultBool   ConfigSetDefaultBool;
extern ptr_ConfigSetDefaultString ConfigSetDefaultString;
extern ptr_ConfigGetParamInt      ConfigGetParamInt;
extern ptr_ConfigGetParamFloat    ConfigGetParamFloat;
extern ptr_ConfigGetParamBool     ConfigGetParamBool;
extern ptr_ConfigGetParamString   ConfigGetParamString;

extern ptr_ConfigGetSharedDataFilepath ConfigGetSharedDataFilepath;
extern ptr_ConfigGetUserConfigPath     ConfigGetUserConfigPath;
extern ptr_ConfigGetUserDataPath       ConfigGetUserDataPath;
extern ptr_ConfigGetUserCachePath      ConfigGetUserCachePath;

/* declarations of pointers to Core debugger functions */
extern ptr_DebugSetCallbacks      DebugSetCallbacks;
extern ptr_DebugSetCoreCompare    DebugSetCoreCompare;
extern ptr_DebugSetRunState       DebugSetRunState;
extern ptr_DebugGetState          DebugGetState;
extern ptr_DebugStep              DebugStep;
extern ptr_DebugDecodeOp          DebugDecodeOp;
extern ptr_DebugMemGetRecompInfo  DebugMemGetRecompInfo;
extern ptr_DebugMemGetMemInfo     DebugMemGetMemInfo;
extern ptr_DebugMemGetPointer     DebugMemGetPointer;

extern ptr_DebugMemRead64         DebugMemRead64;
extern ptr_DebugMemRead32         DebugMemRead32;
extern ptr_DebugMemRead16         DebugMemRead16;
extern ptr_DebugMemRead8          DebugMemRead8;

extern ptr_DebugMemWrite64        DebugMemWrite64;
extern ptr_DebugMemWrite32        DebugMemWrite32;
extern ptr_DebugMemWrite16        DebugMemWrite16;
extern ptr_DebugMemWrite8         DebugMemWrite8;

extern ptr_DebugGetCPUDataPtr     DebugGetCPUDataPtr;
extern ptr_DebugBreakpointLookup  DebugBreakpointLookup;
extern ptr_DebugBreakpointCommand DebugBreakpointCommand;

/* function declarations */
extern m64p_error AttachCoreLib(const char *CoreLibFilepath);
extern m64p_error DetachCoreLib(void);
extern m64p_error OpenConfigurationHandles(void);

void stop_emu(void);
void toggle_fullscreen(void);
void savestates_set_slot(int slot);
void savestate_save(int type, char *filename);
void savestate_load(char *filename);
void savestate_inc_slot(void);
void volume_mute(void);
void volume_up(void);
void volume_down(void);
void set_fastforward(int enable);
void soft_reset(void);
void speed_delta(int delta);
void frame_advance(void);
void send_key_down(unsigned short keysym, unsigned short keymod);
void send_key_up(unsigned short keysym, unsigned short keymod);
void take_screenshot(void);
void set_gameshark_button(int enable);

#endif /* #define CORE_INTERFACE_H */

