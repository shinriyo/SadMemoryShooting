//
//  GameLayer.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/16.
//
//

#include "GameLayer.h"

GameLayer::GameLayer()
{
    
}

GameLayer::~GameLayer()
{
    // release all retained actions
    
    
    // release all retained arrays
    
    
}

CCScene * GameLayer::scene()
{
    CCScene * scene = CCScene::create();
    GameLayer * layer = GameLayer::create();
    scene->addChild(layer);
    
    return scene;
}

GameLayer * GameLayer::create()
{
    GameLayer * layer = new GameLayer();
    
    if (layer) {
        layer->autorelease();
      //  layer->initGame();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return NULL;
}
//
//
//void GameLayer::initGame()
//{
//    
//    /* ScreenSize */
//    _winSize = CCDirector::sharedDirector()->getWinSize();
//    
//    /* Singleton */
//    _manager = GameManager::sharedGameManager();
//    _manager->reset();
//    
//    /* Boolean */
//    _running = false;
//    
//    /* Game Init */
//    createGameScreen();
//    resetGame();
//    
//    /* listen for touches */
//    this->setTouchEnabled(true);
//    scheduleUpdate();
//    
//    
//    // Delay
//    _enemyObjects = CCArray::createWithCapacity(50);
//    _enemyObjects->retain();
//    
//    /* Stage */
//    CCLabelTTF * _timeLabel = CCLabelTTF::create("0", "Marker Felt", 25);
//    _timeLabel->setAnchorPoint(CCPointMake(1.0f, 0.5f));
//    _timeLabel->setColor(ccc3(255, 0, 0));
//    
//    
//    _manager = GameManager::sharedGameManager();
//    
//    _manager->setGameState(kGameStatePlay);
//    
//    
//    
//    
//    
//    /* create main loop */
//
//}
//
//void GameLayer::resetGame()
//{
//    _manager = GameManager::sharedGameManager();
//    _manager->setGameState(kGameStateOver);
//}
//
//
//
//
//
//void GameLayer::ccTouchesBegan(CCSet* pTouches, CCEvent* event)
//{
//    if (_manager->getGameState() != kGameStatePlay) return;
//    
//    
//    CCTouch * touch = (CCTouch *) pTouches->anyObject();
//    
//    if (touch) {
//        CCPoint tap = touch->getLocation();
//    }
//	
//
//    
//	
//}
//
//void GameLayer::ccTouchesMoved(CCSet* pTouches, CCEvent* event)
//{
//    if (_manager->getGameState() != kGameStatePlay) return;
//	
//    
//    
//}
//
//void GameLayer::ccTouchesEnded(CCSet* pTouches, CCEvent* event) {
//    
//	if (_manager->getGameState() != kGameStatePlay) return;
//    
//    
//	
//}
//
//
void GameLayer::update (float dt)
{
    
    
    
    
    
    
	
	
		
}
//
//
//void GameLayer::enemyObjectsDone(CCNode * pSender)
//{
//    // remove it from array //
//    _enemyObjects->removeObject(pSender);
//    pSender->stopAllActions();
//    pSender->setRotation(0);
//    
//
//    
//
//    
//    // enemy 1
//    
//    
//    // enemy 2
//    
//    // enemy 3
//    
//}
//
//
//
//void GameLayer::resetEnemy()
//{
//    if (_enemyObjects->count() > 50) return;
//    
//    CCSprite * enemy = (CCSprite *) _enemyPool_1->objectAtIndex(_enemyPoolIndex_1);
//    _enemyPoolIndex_1++;
//    if (_enemyPoolIndex_1 == _enemyPool_1->count()) _enemyPoolIndex_1 = 0;
//    
//    int enemy_x = rand() % (int) (_winSize.width * CCRANDOM_0_1()) + _winSize.width * 0.1f;
//    int enemy_y = rand() % (int) (_winSize.height * CCRANDOM_0_1()) + _winSize.height * CCRANDOM_0_1();
//    
//    enemy->stopAllActions();
//    enemy->setPosition(ccp(enemy_x, enemy_y));
//    
//    // create action
//    //CCFiniteTimeAction * sequence = CCSequence::create();
//
//}
//
//void GameLayer::createEnemies()
//{
//    CCSprite * sprite;
//    int i;
//    
//    // create enemy1 pool;
//    _enemyPool_1 = CCArray::createWithCapacity(30);
//    _enemyPool_1->retain();
//    _enemyPoolIndex_1 = 0;
//    for (i = 0; i < 50; i++)
//    {
//        sprite = CCSprite::createWithSpriteFrameName("");
//        sprite->setVisible(false);
//        _gameBatchNode->addChild(sprite, kMiddleground, kEnemy01);
//        _enemyPool_1->addObject(sprite);
//    }
//    
//    // create enemy2 pool
//    _enemyPool_2 = CCArray::createWithCapacity(20);
//    _enemyPool_2->retain();
//    _enemyPoolIndex_2 = 0;
//    for (i = 0; i < 20; i++)
//    {
//        sprite = CCSprite::createWithSpriteFrameName("");
//        sprite->setVisible(false);
//        _gameBatchNode->addChild(sprite, kMiddleground, kEnemy02);
//        _enemyPool_2->addObject(sprite);
//    }
//    
//    // create enemy3 pool
//    _enemyPool_3 = CCArray::createWithCapacity(10);
//    _enemyPool_3->retain();
//    _enemyPoolIndex_3 = 0;
//    for (i = 0; i < 10; i++)
//    {
//        sprite = CCSprite::createWithSpriteFrameName("");
//        sprite->setVisible(false);
//        _gameBatchNode->addChild(sprite, kMiddleground, kEnemy03);
//        _enemyPool_3->addObject(sprite);
//    }
//}
//
//void GameLayer::createEnemyActions()
//{
//    // type Actions //
//    CCFiniteTimeAction * ease;
//    
//    
//    
//    /* enemy1 Actions */
//    
//    
//    /* enemy2 Actions */
//
//
//    /* enemy3 Actions */
//    
//}
//
//void GameLayer::createGameScreen()
//{
//    
//}
//
//
//void GameLayer::stopGame()
//{
//    _running = false;
//    int i;
//    int count;
//    CCSprite * sprite;
//    count = _enemyObjects->count();
//    for (i = count - 1; i >= 0; i--)
//    {
//        sprite = (CCSprite *) _enemyObjects->objectAtIndex(i);
//        sprite->stopAllActions();
//        sprite->setVisible(false);
//        _enemyObjects->removeObjectAtIndex(i);
//    }
//
//    
//}
//
//void GameLayer::removingNode(CCNode * node)
//{
//    node->removeFromParentAndCleanup(true);
//}






















