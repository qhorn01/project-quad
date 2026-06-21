#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>

#include "mainLevelBackground.h"
#include "backgroundTilesAndHoops.h"
#include "loadScreens.h"

GameState currentState = MAIN_LEVEL;

int main(void) {
        initMainLevelTiles();
    while(1) {
        initMainLevelLogic();

        wait_vbl_done();
    }
}