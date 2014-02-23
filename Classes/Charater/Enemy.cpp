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
    if (!CCSprite::initWithFile(getImageFileName(type))) return false;
    
    setTag(tag);
    setType(type);
    
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
    int i;
    
    /* Stage */
    switch (stage)
    {
        // Stage 1 //
        case kGameStage1:
            _manager->setGameStage(kGameStage1);
            
            /* Enemy */
            switch (enemy) {
                case kEnemy01:
                    _enemy1 = CCArray::createWithCapacity(30);
                    _enemy1->retain();
                    _enemy1Index = 0;
                    for (i = 0; i < ENEMY1; i++) {
                        sprite->gameSpriteWithFile(getImageFileName(kEnemy01));
                        
                    }
                    break;
                    
                default:
                    break;
            }
            
        // Stage 2 //
        case kGameStage2:
            _manager->setGameStage(kGameStage2);
            
            /* Enemy */
            
            
            
        case kGameStage3:
            _manager->setGameStage(kGameStage3);
            
            break;
            
        default:
            break;
    }
    
    
    
    // stage1 enemy1
    _enemy1 = CCArray::createWithCapacity(30);
    _enemy1->retain();
    _enemy1Index = 0;
    for (i = 0; i < 30; i++)
    {
        sprite = GameSprite::gameSpriteWithFile("");
        sprite->setTag(kEnemy01);
        
    }

    
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
