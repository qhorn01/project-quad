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

struct Balls {
    uint8_t x;
    uint8_t y;
    uint8_t paletteIndex;
};

void initMainLevelTiles(void);
void initMainLevelLogic(void);

#endif