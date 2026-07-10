#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>
#include <rand.h>

#include "ballTiles.h"
#include "mainLevelBackground.h"
#include "backgroundTilesAndHoops.h"
#include "loadScreens.h"

GameState currentState = MAIN_LEVEL;

struct Balls ball[2] = {
    {76, 84, 0, 0, 2, 3, 5, 0, 0, 0, 0, 0, 0},
    {76, 84, 0, 0, 2, 3, 5, 0, 0, 0, 0, 0, 0}
};

uint8_t turnHoops = 1;
uint16_t score = 0;

int main(void) {
        initMainLevelTiles();
    while(1) {
        initMainLevelLogic();

        wait_vbl_done();
    }
}