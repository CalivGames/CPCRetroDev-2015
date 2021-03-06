//-----------------------------LICENSE NOTICE------------------------------------
//  This file is part of CPCtelera: An Amstrad CPC Game Engine
//  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------------

#include "constantes.h"
#include "game.h"
#include "screens.h"
#include "music.c"

void initCPC() {
	cpct_disableFirmware();
	cpct_fw2hw(g_palette,16);
	cpct_fw2hw(g_palette2,16);
	cpct_fw2hw(g_palette3,16);
	cpct_setPalette(g_palette,16);
	cpct_setBorder (g_palette[0]);
	cpct_setVideoMode(0);
	cpct_akp_musicInit(G_menu);	
//	cpct_akp_SFXInit (G_menu);
}

void main(void) {
	// Clear Screen
	cpct_memset(SCR_VMEM, 0, 0x4000);
	initCPC();
	gameScene=CALIVGAMESSCREEN;
	//gameScene=MENUSCREEN;
	// Loop forever
	while (1) {
		switch (gameScene) {
		    case CALIVGAMESSCREEN: calivGames();
				break;
			case MENUSCREEN: mainMenu();
				break;
			case PLAYGAMESCREEN: infinityMode();
				break;
    		case NEXTLEVELSCREEN: newLevel();
	    		break;
			case CONTROLSSCREEN: controls();
				break;
		    case GAMEOVERSCREEN: gameOver();
				break;
			case CREDITSSCEENE: credits();
				break;
		}
	};
}
