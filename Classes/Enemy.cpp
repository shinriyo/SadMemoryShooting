//
//  Enemy.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/03/05.
//
//

#include "Enemy.h"

/**** Enemy ****/
void Enemy::initEnemies (GameStage stage)
{
    switch (stage) {
        // Game Stage 1
        case kGameStage1:
            CCLog("this Stage is in Stage 1");
            
            break;
        
        // Game Stage 2
        case kGameStage2:
            CCLog("this Stage is in Stage 2");
            
            break;
        
        // Game Stage 3
        case kGameStage3:
            CCLog("this Stage is in Stage 3");
            
            break;
            
        // None Stage
        default:
            break;
    }
    
}

void Enemy::smallEnemy(GameStage stage, Enemy1 * small)
{
    switch (stage) {
        case kGameStage1:
            small->_enemy1 = GameSprite::gameSpriteWithFileName(STAGE1_ENEMY1);
            
            break;
        
        case kGameStage2:
            
            break;
            
        case kGameStage3:
            
            break;
            
        default:
            break;
    }
    
}




/**** Stage 1 ****/
EnemyStage1::EnemyStage1() :
_winSize(CCDirector::sharedDirector()->getWinSize())
{
    Enemy1 * enemy1;
    enemy1->_enemy1->gameSpriteWithFileName("stage1enemy1.png");
    enemy1->_enemy1->setSpeed(100);
    
    
    
    /**** Enemy Init Property ****/ // (GameSprite)
    /* enemy1 */
//    _enemy1->setSpeed(10);
//    _enemy1->setInterval(1.0);
//    _enemy1->setTimer(_enemy1->getInterval() * 0.99f);
//    
//    // test
//
//    /* enemy2 */
//    _enemy2->setSpeed(20);
//    _enemy2->setInterval(1.5);
//    _enemy2->setTimer(_enemy2->getInterval() * 0.6f);
//    
//    /* enemy3 */
//    _enemy3->setSpeed(30);
//    _enemy3->setInterval(2.0);
//    _enemy3->setTimer(_enemy3->getInterval() * 0.4f);
    
    
    
    
}

EnemyStage1::~EnemyStage1()
{
    
}

EnemyStage1 * EnemyStage1::create ()
{
//    EnemyStage1 * enemy = new EnemyStage1();
//    if (enemy) {
//        enemy->autorelease();
//        enemy->initEnemy();
//        enemy->initEnemies(kGameStage1);
//        return enemy;
//    }
//    CC_SAFE_DELETE(enemy);
//    return NULL;
}

void EnemyStage1::initEnemy()
{
    int i;
    
   // small_boss->_enemies1 = ccr
    


    
    
    
//    GameSprite * enemy;
//    int i;
//    
//    /* Enemy 1 */
//    _enemies1 = CCArray::createWithCapacity(30);
//    _enemies1->retain();
//    _enemyIndex1 = 0;
//    for (i = 0; i < 30; i++) {
//        enemy = GameSprite::gameSpriteWithFileName("stage1enemy1.png");
//        enemy->setVisible(false);
//        this->addChild(enemy, kBackground, kGameStage1);
//        _enemies1->addObject(enemy);
//    }
//    
//    /* Enemy 2 */
//    _enemies2 = CCArray::createWithCapacity(20);
//    _enemies2->retain();
//    _enemyIndex2 = 0;
//    for (i = 0; i < 20; i++) {
//        enemy = GameSprite::gameSpriteWithFileName("stage1enemy2.png");
//        enemy->setVisible(false);
//        _enemies2->addObject(enemy);
//    }
//    
//    /* Enemy 3 */
//    _enemies3 = CCArray::createWithCapacity(10);
//    _enemies3->retain();
//    _enemyIndex3 = 0;
//    for (i = 0; i < 10; i++) {
//        enemy = GameSprite::gameSpriteWithFileName("stage1enemy3.png");
//        enemy->setVisible(false);
//        _enemies3->addObject(enemy);
//    }
    
}

void EnemyStage1::resetEnemy1()
{
    // if too many objects on screen, return
//    if (_allEnemies->count() > 30) return;
//    
//    
//    _enemy1 = (GameSprite *)_enemies1->objectAtIndex(_enemyIndex1);
//    _enemyIndex1++;
//    if (_enemyIndex1 == _enemies1->count()) _enemyIndex1 = 0;
//    
//    int enemy1_x = rand() % (int) (_winSize.width * 0.8f) + _winSize.width * 0.1f;
//    int enemy1_target_x = rand() % (int) (_winSize.width * 0.8f) + _winSize.width * 0.1f;
//    
//    _enemy1->stopAllActions();
//    _enemy1->setPosition(ccp(enemy1_x, _winSize.height + _enemy1->boundingBox().size.height * 0.5f));
//    
//    
//    /* action for enemy1 on stage1 */
//    CCActionInterval * rotate = CCRotateBy::create(0.5f, -90);
//    CCAction * repeatRotate = CCRepeatForever::create( rotate );
//    CCFiniteTimeAction * sequence = CCSequence::create(CCMoveTo::create(_enemy1->getSpeed(), ccp(enemy1_target_x, _winSize.height * 0.15f)));
//    
//    _enemy1->setVisible(true);
//    _enemy1->runAction(repeatRotate);
//    _enemy1->runAction(sequence);
//    _allEnemies->addObject(_enemy1);
    
}

void EnemyStage1::enemyObjectDone()
{
    
}

void EnemyStage1::animationDone(CCNode * pSender)
{
    pSender->setVisible(false);
    
}







/**** Stage 2 ****/


/**** Stage 3 ****/




