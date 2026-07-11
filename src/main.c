#include <gb/gb.h>
#include <gb/cgb.h>
#include <stdbool.h>
#include <rand.h>

#include "ballTiles.h"
#include "mainLevelBackground.h"
#include "backgroundTilesAndHoops.h"
#include "loadMainLevel.h"
#include "globalTypes.h"

GameState currentState = MAIN_LEVEL;

struct Balls ball[2] = {
    {76, 84, 0, 0, 2, 3, 5, 0, 0, 0, 0, 0, 0},
    {76, 84, 0, 0, 2, 3, 5, 0, 0, 0, 0, 0, 0}
};

bool isInit = false;

uint8_t turnHoops = 1;
uint16_t score = 0;

int main(void) {
        initMainLevelTiles();
    while(1) {
        switch(currentState) {
            case START:
                if (isInit == false){
                    initStartTiles();
                    isInit = true;
                }
                initStartLogic();
                break;
            case MAIN_LEVEL:
                if (isInit == false){
                    initLevelTiles();
                    isInit = true;
                }
                initLevelLogic();
                break;
        }
        wait_vbl_done();
    }
}