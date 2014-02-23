//
//  GameManager.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/20.
//
//

#include "GameManager.h"

static GameManager * _instance = NULL;

GameManager::~GameManager()
{
    
}

GameManager::GameManager() : _winSize(CCDirector::sharedDirector()->getWinSize())
{
    // create grif cells
    
    // create grid
    
    // load last best score
    if (CCUserDefault::sharedUserDefault()->getIntegerForKey("bestscore") == 0)
    {
        _bestScore = 0;
        CCUserDefault::sharedUserDefault()->setIntegerForKey("bestscore", 0);
        CCUserDefault::sharedUserDefault()->flush();
    
    } else {
        _bestScore = CCUserDefault::sharedUserDefault()->getIntegerForKey("bestcore");
    }
    
    reset();
}


GameManager * GameManager::sharedGameManager()
{
    if (!_instance)
        _instance = new GameManager();
    
    return _instance;
}

void GameManager::reset(void)
{
    updateGameData();
}

void GameManager::setBestScore(int var)
{
    _bestScore = var;
    CCUserDefault::sharedUserDefault()->setIntegerForKey("bestScore", _bestScore);
    CCUserDefault::sharedUserDefault()->flush();
}

void GameManager::update(float dt)
{
    _time -= _timeDecrement * dt;
    if (_timeDecrement) _time = 0;
    
    
}

void GameManager::updateGameData()
{
    
    
    
}

void GameManager::createGameScreen(GameStage stage, kTag type)
{
//    CCLayer * backgroundLayer;
//    CCSprite * child;
//    
//    switch (stage) {
//        case kGameStage1:
//            background->gameSpriteWithFile(kImgBackgroundStage1);
//            background->setPosition(ccp(_winSize.width * 0.5f, _winSize.height * 0.5f));
//            child = (CCSprite *) background->getChildByTag(kGameStage1);
//            backgroundLayer->addChild(background, kBackground, kBackground);
//            break;
//        case kGameStage2:
//            background->gameSpriteWithFile(kImgBackgroundStage2);
//            background->setPosition(ccp(_winSize.width * 0.5f, _winSize.height * 0.5f));
//            child = (CCSprite *) background->getChildByTag(kGameStage2);
//            backgroundLayer->addChild(background, kBackground, kBackground);
//            break;
//        case kGameStage3:
//            background->gameSpriteWithFile(kImgBackgroundStage3);
//            background->setPosition(ccp(_winSize.width * 0.5f, _winSize.height * 0.5f));
//            child = (CCSprite *) background->getChildByTag(kGameStage3);
//            backgroundLayer->addChild(background, kBackground, kBackground);
//            break;
//            
//        default:
//            break;
//    }
    
}

