//
//  Enemy.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/03/05.
//
//

#ifndef __SadMemoryonYourWhiteCampus__Enemy__
#define __SadMemoryonYourWhiteCampus__Enemy__

#include "GameManager.h"

typedef enum
{
    kEnemyIsMoving,
    kEnemyIsDying
    
} EnemyState;


struct Enemy1
{
    GameSprite * _enemy1;
    CCArray * _enemies1;
    int _enemyIndex1;
    // GameAnimation * enemy1Animation;
    
};

struct Enemy2
{
    GameSprite * _enemy2;
    CCArray * _enemies2;
    int _enemyIndex2;
    
};

struct Enemy3
{
    GameSprite * _enemy3;
    CCArray * _enemies3;
    int _enemyIndex3;
    
};


class Player;
class GameAnimation;

class Enemy : public GameSprite
{
    GameManager * _manager;
    cocos2d::CCSize _winSize;
    
    
public:
    
    Enemy1 * _smallEnemy;
    Enemy2 * _middleEnemy;
    Enemy3 * _bigEnemy;
    
//    GameSprite * _enemy1;
//    CCArray * _enemies1;
//    int _enemyIndex1;
//    
//    GameSprite * _enemy2;
//    CCArray * _enemies2;
//    int _enemyIndex2;
//    
//    GameSprite * _enemy3;
//    CCArray * _enemies3;
//    int _enemyIndex3;
    
    CCArray * _allEnemies;
    
    bool isStaged;

    /* Property */
    CC_SYNTHESIZE(float, _radius, Radius );
    CC_SYNTHESIZE(int,   _life,   Life   );
    CC_SYNTHESIZE(float, _speed,  Speed  );
    CC_SYNTHESIZE(float, _interval, Interval);
    CC_SYNTHESIZE(float, _enemyTimer, EnemyTimer);
    
    void initEnemies(GameStage stage);
    void smallEnemy(GameStage stage, Enemy1 * small);
    void middleEenmy(GameStage stage, Enemy2 * middle);
    void bigEnemy(GameStage stage, Enemy3 * big);
    
    static void moveFrom(cocos2d::CCPoint position, float scale, float velocity, cocos2d::CCLayer);
    

    
};


/**** Stage 1 ****/
class EnemyStage1 : public Enemy, PlayingGameAnimation
{
public:
    
    EnemyStage1(void);
    ~EnemyStage1(void);
    
    static EnemyStage1 * create(void);
    void initEnemy(void);
    
    void resetEnemy(void);
    void resetEnemy1(void);
    
    PlayingGameAnimation * animation;
    void enemyObjectDone(void);
    void animationDone(CCNode * pSender);
    
private:
    
    cocos2d::CCSize _winSize;
    
    
};


/**** Stage 2 ****/
class EnemyStage2 : public Enemy
{
public:
    EnemyStage2();
    ~EnemyStage2();
    
};


/**** Stage 3 ****/
class EnemyStage3 : public Enemy
{
public:
    EnemyStage3();
    ~EnemyStage3();
    
};




#endif /* defined(__SadMemoryonYourWhiteCampus__Enemy__) */
