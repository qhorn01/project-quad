#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>

#ifndef LOAD_SCREENS
#define LOAD_SCREENS

typedef enum {
    START,
    MAIN_LEVEL,
    GAMEOVER
} GameState;

void initMainLevelTiles(void);

#endif