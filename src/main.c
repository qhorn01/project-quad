#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>

#include "ballTiles.h"
#include "mainLevelBackground.h"
#include "backgroundTilesAndHoops.h"
#include "loadScreens.h"

GameState currentState = MAIN_LEVEL;

struct Balls ball1 = {76, 84, 0};

int main(void) {
        initMainLevelTiles();
    while(1) {
        initMainLevelLogic();

        wait_vbl_done();
    }
}