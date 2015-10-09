#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <cpctelera.h>
#include "constantes.h"
#include "background.h"
// Provisional
#include "car.h"

// Player constants
#define PLAYER_WIDTH_BYTES         8
#define PLAYER_HEIGHT_BYTES        24
#define PLAYER_WIDTH_TILES         4
#define PLAYER_HEIGHT_TILES        6
#define PLAYER_MAX_X     10
#define PLAYER_MIN_X      1
#define PLAYER_MAX_Y     40
#define PLAYER_MIN_Y     30

// Player sprites
extern const u8 sprite_skate[32];
extern const u8 sprite_character[384];
extern const u8 bloque [32];
// Player struct
typedef struct {
  u8 x;
  u8 y;
  u8* memptr; // no se seguro si esto debe ser propio del player
  u8 maxLifes;
  u8 lifes;
}TPlayer;

void initPlayer();
void player();
void move();
void drawLifes();
void lessLife();

void Road();
void widthImageScroll(u8 tile[], u8 shadowTile[], i8 posY, u8 widthImage);
void scroll(u8 tile[], u8 shadowTile[], i8 posX, i8 posY, i8 nextLine);

// Estos metodos no son de esta clase
void drawCars(u8 vNumber);

#endif
