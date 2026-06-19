#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>

#include "circleGoal.h"
#include "loadScreens.h"

GameState currentState = MAIN_LEVEL;

int main(void) {
        initMainLevelTiles();
    while(1) {
        wait_vbl_done();
    }
}