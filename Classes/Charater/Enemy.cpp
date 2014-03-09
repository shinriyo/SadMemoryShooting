//
//  Enemy.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/16.
//
//

#include "Enemy.h"

USING_NS_CC;

#define ENEMY1 30
#define ENEMY2 20
#define ENEMY3 10

Enemy::Enemy() :
_manager(GameManager::sharedGameManager()),
_winSize(CCDirector::sharedDirector()->getWinSize())
{

    
}

Enemy::~Enemy()
{
    // release all retained actions
    
    
    // release all retained arrays
    CC_SAFE_RELEASE(_enemy1);
    CC_SAFE_RELEASE(_enemy2);
    CC_SAFE_RELEASE(_enemy3);
    CC_SAFE_RELEASE(_enemyObjects);
}

Enemy * Enemy::create(int tag, kEnemy type)
{
    Enemy * enemy = new Enemy();
    if (enemy && enemy->init(tag, type)) {
        
        enemy->autorelease();
        
        return enemy;
    }
    CC_SAFE_DELETE(enemy);
    return NULL;
    
}

bool Enemy::init(int tag, kEnemy type)
{
    
    
    return true;
}

void Enemy::update(float dt)
{
    
}

const char * Enemy::getImageFileName(kEnemy type)
{
    switch (type) {
        case kEnemy01:
            return STAGE1_ENEMY1;
        case kEnemy02:
            return STAGE1_ENEMY2;
        case kEnemy03:
            return STAGE1_ENEMY3;
        
        default:
            CCAssert(false, "invalid enemyType");
            return "";
    }
    
}

void Enemy::createEnemies(GameStage & stage, kEnemy & enemy, GameSprite * sprite)
{


    
}

void Enemy::select(bool flag, CCPoint point)
{
    int i;
    GameSprite * enemy;
    if (flag) {
        enemy->setOpacity(200);
    } else {
        
    }
        
}

void Enemy::createEnemyActions()
{
    
    
}


