//
//  GameConfig.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/16.
//
//

#ifndef __SadMemoryonYourWhiteCampus__GameConfig__
#define __SadMemoryonYourWhiteCampus__GameConfig__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace CocosDenshion;


/* DEFINE */
// Game //
#define ENERGY_DRAW     10.0


// Background //
#define BACKGROUND1     "stage_1.png"
#define BACKGROUND2     "stage_2.png"
#define BACKGROUND3     "stage_3.png"
// player //
#define PLAYER          "player_off.png"
#define STAGE1_PLAYER   "rockon_1.png"
#define STAGE2_PLAYER   "rockon_2.png"
// Beam //
#define STAGE1_BEAM     "beam_1.png"
#define STAGE2_BEAM     "beam_2.png"
// Life //
#define STAGE1_LIFE     "life_1.png"
#define STAGE2_LIFE     "life_2.png"
// Enemy //
#define STAGE1_ENEMY1   "stage1enemy1.png"
#define STAGE1_ENEMY2   "stage1enemy2.png"
#define STAGE1_ENEMY3   "stage1enemy3.png"
#define STAGE1_BOSS     "boss_1.png"
#define STAGE2_ENEMY1   "stage2enemy1.png"
#define STAGE2_ENEMY2   "stage2enemy2.png"
#define STAGE2_ENEMY3   "stage2enemy3.png"
#define STAGE2_BOSS     "boss_2.png"
#define STAGE3_ENEMY1   "stage3enemy1.png"
#define STAGE3_ENEMY2   "stage3enemy2.png"
#define STAGE3_ENEMY3   "stage3enemy3.png"


/* IMAGE */

//const char * enemy1 = "enemy1.png";
//const char * enemy2 = "enemy2.png";
//const char * enemy3 = "enemy3.png";

/* font */
//const char * const kFontRed     = "redFont.fnt";
//const char * const kFondBlue    = "blueFont.fnt";
//const char * const kFontYellow  = "yellowFont.fnt";
//const char * const kFontGreen   = "greenFont.fnt";
//const char * const kFontWhite   = "whiteFont.fnt";

/* Stage1 */
struct StageOne
{
    
};

/* Stage2 */


/* Stage3 */

/* Tag */
enum kTag
{
    kTagBackground = 1,
    kTagPlayer,
    kTagStage,
    kTagEnemy,
    kTagBoss,
};

/* Game Background */
enum kZOrder
{
    kBackground,
    kMiddleground,
    kForeground,
    kParticle,
    kController
};

/* GameScene */
typedef enum
{
    kGameStage1,
    kGameStage2,
    kGameStage3,
    
} GameStage;


/* Game State */
typedef enum
{
    kGameStateOpening,
    kGameStatePlay,
    kGameStatePause,
    kGameStateGameOver,
    kGameStateMenu
    
} GameState;

/* RockOn */
typedef enum
{
    kPlayerStopping,
    kPlayerMoving,
    kPlayerinCollision

} PlayerState;

/* Enemy */
enum kEnemy
{
    kEnemy01,
    kEnemy02,
    kEnemy03
};



/* Beam */
typedef enum
{
    stage1Beam,
    stage2Beam,
    stage3Beam
    
} StageBeam;





#endif /* defined(__SadMemoryonYourWhiteCampus__GameConfig__) */
