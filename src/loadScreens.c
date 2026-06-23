#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>

#include "mainLevelBackground.h"
#include "backgroundTilesAndHoops.h"
#include "loadScreens.h"

extern GameState currentState;

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

//Blank hoop
const unsigned char blankHoopMap[9] = {
    4, 4, 4, 
    4, 4, 4, 
    4, 4, 4 
};

const unsigned char blankHoopAttributes[9] = {
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0 
};

//Blue hoop
const unsigned char blueHoopMap[9] = {
    0, 1, 2, // Top row
    3, 4, 5, // Middle row
    6, 7, 8  // Bottom row
};

const unsigned char blueHoopAttributes[9] = {
    0, 0, 0, 
    0, 0, 0, 
    0, 0, 0 
};

//Red hoop
const unsigned char redHoopMap[9] = {
    17, 18, 19, // Top row
    20, 21, 22, // Middle row
    23, 24, 25  // Bottom row
};

const unsigned char redHoopAttributes[9] = {
    1, 1, 1, 
    1, 1, 1, 
    1, 1, 1 
};

//Green hoop
const unsigned char greenHoopMap[9] = {
    26, 27, 28, // Top row
    29, 30, 31, // Middle row
    32, 33, 34  // Bottom row
};

const unsigned char greenHoopAttributes[9] = {
    2, 2, 2, 
    2, 2, 2, 
    2, 2, 2 
};

//Yellow hoop
const unsigned char yellowHoopMap[9] = {
    35, 36, 37, // Top row
    38, 39, 40, // Middle row
    41, 42, 43  // Bottom row
};

const unsigned char yellowHoopAttributes[9] = {
    3, 3, 3, 
    3, 3, 3, 
    3, 3, 3 
};

void turnHoopsRight(void){
    unsigned char currentTileId;
    // Fetch the 1 tile at X=9, Y=1 from the live screen 
    // and store it in our 'currentTileId' variable
    get_bkg_tiles(9, 1, 1, 1, &currentTileId);

    if (currentTileId == 1){
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, blankHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(3, 3, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(3, 3, 3, 3, redHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(3, 13, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(3, 13, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(13, 13, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(13, 13, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(13, 3, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(13, 3, 3, 3, blueHoopMap);

            for (uint8_t i = 0; i < 10; i++) {
            wait_vbl_done();
            }

            VBK_REG = 1;
            set_bkg_tiles(13, 3, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(13, 3, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(13, 13, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(13, 13, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(3, 13, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(3, 13, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(3, 3, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(3, 3, 3, 3, blankHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, redHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, blueHoopMap);
    }
    if (currentTileId == 18){
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, blankHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(3, 3, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(3, 3, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(3, 13, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(3, 13, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(13, 13, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(13, 13, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(13, 3, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(13, 3, 3, 3, redHoopMap);

            for (uint8_t i = 0; i < 10; i++) {
            wait_vbl_done();
            }

            VBK_REG = 1;
            set_bkg_tiles(13, 3, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(13, 3, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(13, 13, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(13, 13, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(3, 13, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(3, 13, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(3, 3, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(3, 3, 3, 3, blankHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, redHoopMap);        
    }
    if (currentTileId == 27){
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, blankHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(13, 3, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(13, 3, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(3, 3, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(3, 3, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(3, 13, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(3, 13, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(13, 13, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(13, 13, 3, 3, redHoopMap);

            for (uint8_t i = 0; i < 10; i++) {
            wait_vbl_done();
            }

            VBK_REG = 1;
            set_bkg_tiles(13, 3, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(13, 3, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(13, 13, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(13, 13, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(3, 13, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(3, 13, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(3, 3, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(3, 3, 3, 3, blankHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, redHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, greenHoopMap);        
    }
    if (currentTileId == 36){
                        VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, blankHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(13, 13, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(13, 13, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(13, 3, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(13, 3, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(3, 3, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(3, 3, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(3, 13, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(3, 13, 3, 3, redHoopMap);

            for (uint8_t i = 0; i < 10; i++) {
            wait_vbl_done();
            }

            VBK_REG = 1;
            set_bkg_tiles(13, 3, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(13, 3, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(13, 13, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(13, 13, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(3, 13, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(3, 13, 3, 3, blankHoopMap);

            VBK_REG = 1;
            set_bkg_tiles(3, 3, 3, 3, blankHoopMap);

            VBK_REG = 0;
            set_bkg_tiles(3, 3, 3, 3, blankHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, redHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, yellowHoopMap);        
    }
}

void turnHoopsLeft(void){
    unsigned char currentTileId;
    // Fetch the 1 tile at X=9, Y=1 from the live screen 
    // and store it in our 'currentTileId' variable
    get_bkg_tiles(9, 1, 1, 1, &currentTileId);

    if (currentTileId == 27){
            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, redHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, blueHoopMap);
    }
    if (currentTileId == 36){
            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, redHoopMap);        
    }
    if (currentTileId == 1){
            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, yellowHoopMap);

            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, redHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, greenHoopMap);        
    }
    if (currentTileId == 18){
            // Blue hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 1, 3, 3, blueHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 1, 3, 3, blueHoopMap);

            // Red hoop
            VBK_REG = 1;
            set_bkg_tiles(1, 8, 3, 3, redHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(1, 8, 3, 3, redHoopMap);

            // Green hoop
            VBK_REG = 1;
            set_bkg_tiles(8, 15, 3, 3, greenHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(8, 15, 3, 3, greenHoopMap);

            // Yellow hoop
            VBK_REG = 1;
            set_bkg_tiles(15, 8, 3, 3, yellowHoopAttributes);

            VBK_REG = 0;
            set_bkg_tiles(15, 8, 3, 3, yellowHoopMap);        
    }
}

//For Main
void initMainLevelTiles(void){
    wait_vbl_done();
    DISPLAY_OFF;

    static uint8_t hoopX = 0;
    static uint8_t hoopY = 0;

    BGP_REG = 0xE4;

    set_bkg_palette(0, 5, backgroundPalettes);

    set_bkg_data(0, 53, bgTiles);

    VBK_REG = 1;
    set_bkg_tiles(0, 0, 20, 18, MainLevelBackgroundPLN1);

    VBK_REG = 0;
    set_bkg_tiles(0, 0, 20, 18, MainLevelBackgroundPLN0);

    // Blue hoop
    VBK_REG = 1;
    set_bkg_tiles(8, 1, 3, 3, blueHoopAttributes);

    VBK_REG = 0;
    set_bkg_tiles(8, 1, 3, 3, blueHoopMap);

    // Red hoop
    VBK_REG = 1;
    set_bkg_tiles(1, 8, 3, 3, redHoopAttributes);

    VBK_REG = 0;
    set_bkg_tiles(1, 8, 3, 3, redHoopMap);

    // Green hoop
    VBK_REG = 1;
    set_bkg_tiles(8, 15, 3, 3, greenHoopAttributes);

    VBK_REG = 0;
    set_bkg_tiles(8, 15, 3, 3, greenHoopMap);

    // Yellow hoop
    VBK_REG = 1;
    set_bkg_tiles(15, 8, 3, 3, yellowHoopAttributes);

    VBK_REG = 0;
    set_bkg_tiles(15, 8, 3, 3, yellowHoopMap);

    SHOW_BKG;
    DISPLAY_ON;
}

void initMainLevelLogic(void){
    uint8_t input = joypad();
    static uint8_t previousInput = 0;

    if ((input & J_RIGHT) && !(previousInput & J_RIGHT)){
        turnHoopsRight();
    }
    if ((input & J_LEFT) && !(previousInput & J_LEFT)){
        turnHoopsLeft();
    }

    previousInput = input;
}