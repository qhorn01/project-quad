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
    uint8_t frame;
    uint8_t upFrame;
    uint8_t leftFrame;
    uint8_t rightFrame;
    uint8_t spriteAnimationTimer;
    uint8_t tileIndex;
    uint8_t baseSprite;
    uint8_t tileOffset;
    uint8_t ballDirect;
    uint8_t ballFrame;
};

void initMainLevelTiles(void);
void initMainLevelLogic(void);

#endif