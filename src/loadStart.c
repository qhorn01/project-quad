#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>
#include <rand.h>

#include "ballTiles.h"
#include "mainLevelBackground.h"
#include "backgroundTilesAndHoops.h"
#include "loadMainLevel.h"
#include "globalTypes.h"
#include "loadStart.h"

extern GameState currentState;

extern bool isInit;

void initStartTiles(void){

}

void initStartLogic(void){
    uint8_t input = joypad();
    if (input & J_START){
        currentState = MAIN_LEVEL;
        isInit = false;
    }

}