//
//  GameScene1.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/25.
//
//

#include "GameScene1.h"

GameScene1::~GameScene1()
{
    CC_SAFE_RELEASE(sampleParticle);
    
    // release all retained arrays
    CC_SAFE_RELEASE(_allEnemies);
}

GameScene1::GameScene1() :
_manager(GameManager::sharedGameManager()),
_winSize(CCDirector::sharedDirector()->getWinSize())
{
   // _manager->commonGameScreen(this);
    
}



GameScene1 * GameScene1::create()
{
    GameScene1 * layer = new GameScene1();
    
    if (layer) {
        layer->autorelease();
        layer->initGame();
        
        return layer;
    }
    CC_SAFE_DELETE(layer);
    
    return NULL;
}

void GameScene1::initGame()
{
    _manager->reset();
    _running = false;
    
    
    createGameScreen();
    _manager->commonGameScreen(this);
    reset();
    
    _allEnemies = CCArray::createWithCapacity(50);
    _allEnemies->retain();
    
    _running = true;
    
    setTouchEnabled(true);
    scheduleUpdate();
    
}


void GameScene1::update(float dt)
{
    if (_gameState == kGameStatePlay) {
        
        /* running game logic */
        if (_running) {
            
            _manager->update(dt);
           // dt *= dt_rate
            
            
        }
    }
    
    //
    if (!sampleParticle->isActive()) sampleParticle->resetSystem();
    sampleParticle->setRotation(_player->getRotation());
    sampleParticle->setPosition(_player->getPosition());
    
    
    _player->setPosition(_player->getNextPosition());
    
    
}

void GameScene1::allEnemyObjectDone(CCNode * pSender)
{
    _allEnemies->removeObject(pSender);
    pSender->stopAllActions();
    pSender->setRotation(0);
    
    // small enemy
    
    // middle enemy
    
    // big enemy
}

void GameScene1::reset()
{
    
    
    
    _manager->setGameState(kGameStatePlay);
}

void GameScene1::ccTouchesBegan(CCSet * touches, CCEvent * event)
{
    if (!_running) return;
    
    CCTouch * touch = (CCTouch *) touches->anyObject();
    
    if (touch)
    {
        CCPoint tap = touch->getLocation();
        
        if (_player->boundingBox().containsPoint(tap)) {
            // Log
            CCLog("you touch player");
            
            _player->setColor(ccc3(255*CCRANDOM_0_1(), 255*CCRANDOM_0_1(), 255*CCRANDOM_0_1()));
            _player->setTouch(touch);
        }
        
    }
    
    
    
}

void GameScene1::ccTouchesMoved(CCSet * touches, CCEvent * event)
{
    /* Setting */
    CCSetIterator i;
    CCTouch * touch;
    CCPoint tap;
    
    if (!_running) return;
    
    touch = (CCTouch *) touches->anyObject();
    
    if (touch) {
        tap = touch->getLocation();
        
        if (_player->getTouch() != NULL && _player->getTouch() == touch) {
            
            CCPoint nextPosition = tap;
            
            // keep player inside screen
            if (nextPosition.x < _player->radius())
                nextPosition.x = _player->radius();
            if (nextPosition.x > _winSize.width - _player->radius())
                nextPosition.x = _winSize.width - _player->radius();
            if (nextPosition.y < _player->radius())
                nextPosition.y  = _player->radius();
            if (nextPosition.y > _winSize.height - _player->radius())
                nextPosition.y = _winSize.height - _player->radius();
            
            //keep player inside its court
//            if (_player->getPositionY() < _winSize.height * 0.5f) {
//                if (nextPosition.y > _winSize.height * 0.5 - _player->radius())
//                    nextPosition.y = _winSize.height * 0.5 - _player->radius();
//            } else {
//                if (nextPosition.y < _winSize.height * 0.5 + _player->radius())
//                    nextPosition.y = _winSize.height * 0.5 + _player->radius();
//            }
            
            _player->setNextPosition(nextPosition);
            _player->setVector(ccp(tap.x - _player->getPositionX(), tap.y - _player->getPositionY()));
            
            
        }
    
    
    }
    
    
    
}

void  GameScene1::ccTouchedEnded(CCSet * touches, CCEvent * event)
{
    /* Setting */
    CCSetIterator i;
    CCTouch * touch;
    CCPoint tap;
    
    if (!_running) return;
    
    touch = (CCTouch *) touches->anyObject();
    
    if (touch) {
        tap = touch->getLocation();
        
        if (_player->getTouch() != NULL && _player->getTouch() == touch) {
            
            //if touch ending belongs to this player, clear it
            _player->setTouch(NULL);
            _player->setVector(CCPointZero);
        }
        
        
    }
    
}



void GameScene1::createGameScreen()
{
    // Common //
    _manager->commonGameScreen(this);
    
    _winSize = CCDirector::sharedDirector()->getWinSize();
    
//    // Background //
    _background = GameSprite::gameSpriteWithFileName("gamestage1.png");
    _background->setPosition(ccp(_winSize.width * 0.5, _winSize.height * 0.5));
    _background->setVisible(true);
    this->addChild(_background, kBackground);
    
  //  PlayingGameAnimation * backgroundAnimation;
  //   backgroundAnimation->setBackgroundAnimation(kGameStage1);
    
//
//    // Player //
    _player = Player::create();
    _player->setPosition(ccp(_winSize.width * 0.5, _winSize.height * 0.5));
    _player->setVisible(true);
    this->addChild(_player, kForeground);
    
    sampleParticle = CCParticleSystemQuad::create("sample.plist");
   // sampleParticle->setSourcePosition(ccp(-_player->getRadius() * 0.8, 0));
    sampleParticle->setAngle(180);
    sampleParticle->stopSystem();
    this->addChild(sampleParticle, kBackground);
    
    // Enemy //
    
    

    
    
    
}

void GameScene1::createGameAction()
{
    
}

void GameScene1::gameOver()
{
    /* Music */
    
    /* Setting */
    _manager->setGameState(kGameStateGameOver);
    
    
    
    int totalEmemies = _manager->getTotalCollectedEnemies();
    
    if (totalEmemies > 1)
    {
        CCString * enemies = CCString::createWithFormat("Enemies: %i enemies", totalEmemies);
        
    }
    
    int totalScore = _manager->getTotalScore();
    if (totalScore > 1)
    {
        CCString * ur_score = CCString::createWithFormat("Score: %i score", totalScore);
        
        _manager->_scoreLabel->setString(ur_score->getCString());
        _manager->_scoreLabel->setVisible(true);
        
        if (totalScore > _manager->getBestScore()) {
            _manager->setBestScore(totalScore);
         //   _manager-> _labelBestScore->setVisible(true);
        }
        
        
        
    }
    
    
    
    
    
}


/* GameScene */
CCScene * GameScene1::scene()
{
    CCScene * scene = CCScene::create();
    scene->addChild(GameScene1::create());
    return scene;
}













