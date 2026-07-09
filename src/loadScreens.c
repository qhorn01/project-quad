#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>
#include <rand.h>

#include "ballTiles.h"
#include "mainLevelBackground.h"
#include "backgroundTilesAndHoops.h"
#include "loadScreens.h"

extern GameState currentState;

extern struct Balls ball[2];

extern uint8_t turnHoops;

static const palette_color_t backgroundPalettes[20] = {
    RGB(30, 26, 30),
    RGB(14, 25, 30),
    RGB(0, 9, 28),
    RGB(3, 3, 0),

    RGB(30, 26, 30),
    RGB(31, 11, 11),
    RGB(26, 8, 0),
    RGB(3, 3, 0),

    RGB(30, 26, 30),
    RGB(13, 21, 9),
    RGB(0, 20, 3),
    RGB(3, 3, 0),

    RGB(30, 26, 30),
    RGB(30, 31, 9),
    RGB(25, 23, 0),
    RGB(3, 3, 0),

    RGB(30, 26, 30),
    RGB(30, 19, 30),
    RGB(28, 0, 24),
    RGB(3, 3, 0)
};

static const palette_color_t spritePalettes[16] = {
    RGB(30, 26, 30),
    RGB(14, 25, 30),
    RGB(0, 9, 28),
    RGB(1, 2, 11),

    RGB(30, 26, 30),
    RGB(31, 11, 11),
    RGB(26, 8, 0),
    RGB(14, 2, 1),

    RGB(30, 26, 30),
    RGB(13, 21, 9),
    RGB(0, 20, 3),
    RGB(2, 11, 1),

    RGB(30, 26, 30),
    RGB(30, 31, 9),
    RGB(25, 23, 0),
    RGB(14, 16, 1)
};

//Blank hoop
const uint8_t blankHoopMap[9] = {
    4, 4, 4, 
    4, 4, 4, 
    4, 4, 4 
};

const uint8_t blankHoopAttributes[9] = {
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0 
};

//Blue hoop
const uint8_t blueHoopMap[9] = {
    0, 1, 2, // Top row
    3, 4, 5, // Middle row
    6, 7, 8  // Bottom row
};

const uint8_t blueHoopAttributes[9] = {
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0 
};

//Red hoop
const uint8_t redHoopMap[9] = {
    17, 18, 19, // Top row
    20, 21, 22, // Middle row
    23, 24, 25  // Bottom row
};

const uint8_t redHoopAttributes[9] = {
    1, 1, 1, 
    1, 1, 1, 
    1, 1, 1 
};

//Green hoop
const uint8_t greenHoopMap[9] = {
    26, 27, 28, // Top row
    29, 30, 31, // Middle row
    32, 33, 34  // Bottom row
};

const uint8_t greenHoopAttributes[9] = {
    2, 2, 2, 
    2, 2, 2, 
    2, 2, 2 
};

//Yellow hoop
const uint8_t yellowHoopMap[9] = {
    35, 36, 37, // Top row
    38, 39, 40, // Middle row
    41, 42, 43  // Bottom row
};

const uint8_t yellowHoopAttributes[9] = {
    3, 3, 3, 
    3, 3, 3, 
    3, 3, 3 
};

void setHoop(uint8_t x, uint8_t y, const uint8_t *hoopAttributes, const uint8_t *hoopMap){
    VBK_REG = 1;
    set_bkg_tiles(x, y, 3, 3, hoopAttributes);

    VBK_REG = 0;
    set_bkg_tiles(x, y, 3, 3, hoopMap);
}

void rotateHoops(uint8_t index){
    switch(index){
        case 1:
            setHoop(13, 3, blankHoopAttributes, blankHoopMap);
            setHoop(13, 13, blankHoopAttributes, blankHoopMap);
            setHoop(3, 13, blankHoopAttributes, blankHoopMap);
            setHoop(3, 3, blankHoopAttributes, blankHoopMap);

            setHoop(8, 1, blueHoopAttributes, blueHoopMap);
            setHoop(15, 8, yellowHoopAttributes, yellowHoopMap);
            setHoop(8, 15, greenHoopAttributes, greenHoopMap);
            setHoop(1, 8, redHoopAttributes, redHoopMap);
            break;
        case 2:
            setHoop(13, 3, blueHoopAttributes, blueHoopMap);
            setHoop(13, 13, yellowHoopAttributes, yellowHoopMap);
            setHoop(3, 13, greenHoopAttributes, greenHoopMap);
            setHoop(3, 3, redHoopAttributes, redHoopMap);

            setHoop(8, 1, blankHoopAttributes, blankHoopMap);
            setHoop(15, 8, blankHoopAttributes, blankHoopMap);
            setHoop(8, 15, blankHoopAttributes, blankHoopMap);
            setHoop(1, 8, blankHoopAttributes, blankHoopMap);
            break;
        case 3:
            setHoop(13, 3, blankHoopAttributes, blankHoopMap);
            setHoop(13, 13, blankHoopAttributes, blankHoopMap);
            setHoop(3, 13, blankHoopAttributes, blankHoopMap);
            setHoop(3, 3, blankHoopAttributes, blankHoopMap);

            setHoop(8, 1, redHoopAttributes, redHoopMap);
            setHoop(15, 8, blueHoopAttributes, blueHoopMap);
            setHoop(8, 15, yellowHoopAttributes, yellowHoopMap);
            setHoop(1, 8, greenHoopAttributes, greenHoopMap);
            break;
        case 4:
            setHoop(13, 3, redHoopAttributes, redHoopMap);
            setHoop(13, 13, blueHoopAttributes, blueHoopMap);
            setHoop(3, 13, yellowHoopAttributes, yellowHoopMap);
            setHoop(3, 3, greenHoopAttributes, greenHoopMap);

            setHoop(8, 1, blankHoopAttributes, blankHoopMap);
            setHoop(15, 8, blankHoopAttributes, blankHoopMap);
            setHoop(8, 15, blankHoopAttributes, blankHoopMap);
            setHoop(1, 8, blankHoopAttributes, blankHoopMap);
            break;
        case 5:
            setHoop(13, 3, blankHoopAttributes, blankHoopMap);
            setHoop(13, 13, blankHoopAttributes, blankHoopMap);
            setHoop(3, 13, blankHoopAttributes, blankHoopMap);
            setHoop(3, 3, blankHoopAttributes, blankHoopMap);

            setHoop(8, 1, greenHoopAttributes, greenHoopMap);
            setHoop(15, 8, redHoopAttributes, redHoopMap);
            setHoop(8, 15, blueHoopAttributes, blueHoopMap);
            setHoop(1, 8, yellowHoopAttributes, yellowHoopMap);
            break;
        case 6:
            setHoop(13, 3, greenHoopAttributes, greenHoopMap);
            setHoop(13, 13, redHoopAttributes, redHoopMap);
            setHoop(3, 13, blueHoopAttributes, blueHoopMap);
            setHoop(3, 3, yellowHoopAttributes, yellowHoopMap);

            setHoop(8, 1, blankHoopAttributes, blankHoopMap);
            setHoop(15, 8, blankHoopAttributes, blankHoopMap);
            setHoop(8, 15, blankHoopAttributes, blankHoopMap);
            setHoop(1, 8, blankHoopAttributes, blankHoopMap);
            break;
        case 7:
            setHoop(13, 3, blankHoopAttributes, blankHoopMap);
            setHoop(13, 13, blankHoopAttributes, blankHoopMap);
            setHoop(3, 13, blankHoopAttributes, blankHoopMap);
            setHoop(3, 3, blankHoopAttributes, blankHoopMap);

            setHoop(8, 1, yellowHoopAttributes, yellowHoopMap);
            setHoop(15, 8, greenHoopAttributes, greenHoopMap);
            setHoop(8, 15, redHoopAttributes, redHoopMap);
            setHoop(1, 8, blueHoopAttributes, blueHoopMap);
            break;
        case 8:
            setHoop(13, 3, yellowHoopAttributes, yellowHoopMap);
            setHoop(13, 13, greenHoopAttributes, greenHoopMap);
            setHoop(3, 13, redHoopAttributes, redHoopMap);
            setHoop(3, 3, blueHoopAttributes, blueHoopMap);

            setHoop(8, 1, blankHoopAttributes, blankHoopMap);
            setHoop(15, 8, blankHoopAttributes, blankHoopMap);
            setHoop(8, 15, blankHoopAttributes, blankHoopMap);
            setHoop(1, 8, blankHoopAttributes, blankHoopMap);
            break;
    }

}

void balls(struct Balls *b, uint8_t i, uint8_t ballSpeed){
    b->baseSprite = i * 4;
    switch (b->ballDirect){
            case 0:
                if (b->y != 28){
                    b->spriteAnimationTimer++;
                    b->ballFrame++;

                    if (b->ballFrame > ballSpeed){
                        b->ballFrame = 0;
                        b->y -= 1;
                    }
                    
                    if (b->spriteAnimationTimer >= 12){
                        b->spriteAnimationTimer = 0;
                        b->frame++;
                        b->upFrame -= 1;

                        if (b->frame > 2) {
                            b->frame = 0;
                            b->upFrame = 2;
                        }

                        b->tileOffset = b->tileIndex + (b->upFrame * 4);
                        set_sprite_tile(b->baseSprite + 0, b->tileOffset + 0);
                        set_sprite_tile(b->baseSprite + 1, b->tileOffset + 1);
                        set_sprite_tile(b->baseSprite + 2, b->tileOffset + 2);
                        set_sprite_tile(b->baseSprite + 3, b->tileOffset + 3);
                    }

                    set_sprite_prop(b->baseSprite + 0, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 1, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 2, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 3, b->paletteIndex);

                    move_sprite(b->baseSprite + 0, b->x, b->y);
                    move_sprite(b->baseSprite + 2, b->x + 8, b->y);
                    move_sprite(b->baseSprite + 1, b->x, b->y + 8);
                    move_sprite(b->baseSprite + 3, b->x + 8, b->y + 8);
                } else {
                    b->x = 76;
                    b->y = 84;
                    b->paletteIndex = (rand() % 4);
                    b->ballDirect = (rand() % 4);
                }
                break;
                
            case 1:
                if (b->y != 144) {
                    b->spriteAnimationTimer++;
                    b->ballFrame++;
                    
                    if (b->ballFrame > ballSpeed){
                        b->ballFrame = 0;
                        b->y += 1;
                    }

                    if (b->spriteAnimationTimer >= 12){
                        b->spriteAnimationTimer = 0;
                        b->frame++;

                        if (b->frame > 2) {
                            b->frame = 0;
                        }

                        b->tileOffset = b->tileIndex + (b->frame * 4);
                        set_sprite_tile(b->baseSprite + 0, b->tileOffset + 0);
                        set_sprite_tile(b->baseSprite + 1, b->tileOffset + 1);
                        set_sprite_tile(b->baseSprite + 2, b->tileOffset + 2);
                        set_sprite_tile(b->baseSprite + 3, b->tileOffset + 3);
                    }

                    set_sprite_prop(b->baseSprite + 0, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 1, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 2, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 3, b->paletteIndex);

                    move_sprite(b->baseSprite + 0, b->x, b->y);
                    move_sprite(b->baseSprite + 2, b->x + 8, b->y);
                    move_sprite(b->baseSprite + 1, b->x, b->y + 8);
                    move_sprite(b->baseSprite + 3, b->x + 8, b->y + 8);
                } else {
                    b->x = 76;
                    b->y = 84;
                    b->paletteIndex = (rand() % 4);
                    b->ballDirect = (rand() % 4);
                }
                break;

            case 2:
                if (b->x != 24) {
                    b->spriteAnimationTimer++;
                    b->ballFrame++;

                    if (b->ballFrame > ballSpeed){
                        b->ballFrame = 0;
                        b->x -= 1;
                    }

                    if (b->spriteAnimationTimer >= 12){
                        b->spriteAnimationTimer = 0;
                        b->frame++;
                        b->leftFrame++;

                        if (b->frame > 2) {
                            b->frame = 0;
                            b->leftFrame = 3;
                        }

                        b->tileOffset = b->tileIndex + (b->leftFrame * 4);
                        set_sprite_tile(b->baseSprite + 0, b->tileOffset + 0);
                        set_sprite_tile(b->baseSprite + 1, b->tileOffset + 1);
                        set_sprite_tile(b->baseSprite + 2, b->tileOffset + 2);
                        set_sprite_tile(b->baseSprite + 3, b->tileOffset + 3);
                    }

                    set_sprite_prop(b->baseSprite + 0, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 1, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 2, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 3, b->paletteIndex);

                    move_sprite(b->baseSprite + 0, b->x, b->y);
                    move_sprite(b->baseSprite + 2, b->x + 8, b->y);
                    move_sprite(b->baseSprite + 1, b->x, b->y + 8);
                    move_sprite(b->baseSprite + 3, b->x + 8, b->y + 8);
                } else {
                    b->x = 76;
                    b->y = 84;
                    b->paletteIndex = (rand() % 4);
                    b->ballDirect = (rand() % 4);
                }
                break;

            case 3:
                if (b->x != 132) {
                    b->spriteAnimationTimer++;
                    b->ballFrame++;

                    if (b->ballFrame > ballSpeed){
                        b->ballFrame = 0;
                        b->x += 1;
                    }

                    if (b->spriteAnimationTimer >= 12){
                        b->spriteAnimationTimer = 0;
                        b->frame++;
                        b->rightFrame -= 1;

                        if (b->frame > 2) {
                            b->frame = 0;
                            b->rightFrame = 5;
                        }

                        b->tileOffset = b->tileIndex + (b->rightFrame * 4);
                        set_sprite_tile(b->baseSprite + 0, b->tileOffset + 0);
                        set_sprite_tile(b->baseSprite + 1, b->tileOffset + 1);
                        set_sprite_tile(b->baseSprite + 2, b->tileOffset + 2);
                        set_sprite_tile(b->baseSprite + 3, b->tileOffset + 3);
                    }

                    set_sprite_prop(b->baseSprite + 0, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 1, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 2, b->paletteIndex);
                    set_sprite_prop(b->baseSprite + 3, b->paletteIndex);

                    move_sprite(b->baseSprite + 0, b->x, b->y);
                    move_sprite(b->baseSprite + 2, b->x + 8, b->y);
                    move_sprite(b->baseSprite + 1, b->x, b->y + 8);
                    move_sprite(b->baseSprite + 3, b->x + 8, b->y + 8);
                } else {
                    b->x = 76;
                    b->y = 84;
                    b->paletteIndex = (rand() % 4);
                    b->ballDirect = (rand() % 4);
                }
                break;
        }
}

//For Main
void initMainLevelTiles(void){
    wait_vbl_done();
    DISPLAY_OFF;

    BGP_REG = 0xE4;

    set_bkg_palette(0, 5, backgroundPalettes);

    set_bkg_data(0, 58, bgTiles);

    VBK_REG = 1;
    set_bkg_tiles(0, 0, 20, 18, MainLevelBackgroundPLN1);

    VBK_REG = 0;
    set_bkg_tiles(0, 0, 20, 18, MainLevelBackgroundPLN0);

    setHoop(8, 1, blueHoopAttributes, blueHoopMap);
    setHoop(1, 8, redHoopAttributes, redHoopMap);
    setHoop(8, 15, greenHoopAttributes, greenHoopMap);
    setHoop(15, 8, yellowHoopAttributes, yellowHoopMap);

    set_sprite_data(0, 24, BallTiles);
    set_sprite_palette(0, 4, spritePalettes);

    ball[0].ballDirect = 2;
    ball[1].ballDirect = 3;

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;
}

void initMainLevelLogic(void){
    uint8_t input = joypad();
    static uint8_t previousInput = 0;
    static bool ballSpawn = false;

    balls(&ball[0], 0, 2); // first ball

    //balls(&ball[1], 1, 2); // second ball

    if ((input & J_RIGHT) && !(previousInput & J_RIGHT)){
        turnHoops++;
        if (turnHoops > 9){
            turnHoops = 1;
            rotateHoops(turnHoops);
        } else {
            rotateHoops(turnHoops);
        }
    }
    if ((input & J_LEFT) && !(previousInput & J_LEFT)){
        turnHoops--;
        if (turnHoops < 1){
            turnHoops = 9;
            rotateHoops(turnHoops);
        } else {
            rotateHoops(turnHoops);
        }
    }
    previousInput = input;
}