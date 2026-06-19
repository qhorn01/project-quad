#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>

#include "circleGoal.h"
#include "loadScreens.h"

#define CircleTilesCount 16

extern GameState currentState;

const uint8_t hoopMap[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

void initMainLevelTiles(void){
    static uint8_t hoopX = 0;
    static uint8_t hoopY = 0;

    wait_vbl_done();
    DISPLAY_OFF;

    set_bkg_data(0, 9, CircleGoal);

    set_bkg_tiles(hoopX, hoopY, 3, 3, hoopMap);

    SHOW_BKG;
    DISPLAY_ON;
}