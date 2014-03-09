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

void GameManager::starGameCountdown()
{
//    /* first setting */
//    _coundownLabel = CCLabelBMFont::create("3", "font.fnt", _winSize.width * 0.3);
//    _coundownLabel->setAnchorPoint(ccp(0.5, 0.5));
//    _coundownLabel->setPosition(ccp(_winSize.width * 0.5f, _winSize.height * 0.5));
//    _coundownLabel->setScale(0);
//
//    // 3
//    _coundownLabel->runAction(StartGameAnimation::num3Animation());
//    gameLayer->addChild(_coundownLabel, 1);
//    
//    // 2
//    _coundownLabel = CCLabelBMFont::create("2", "font.fnt", _winSize.width * 0.3);
//    _coundownLabel->runAction(StartGameAnimation::num2Animation());
//    gameLayer->addChild(_coundownLabel, 1);
//    
//    // 1
//    _coundownLabel = CCLabelBMFont::create("1", "font.fnt", _winSize.width * 0.3);
//    _coundownLabel->runAction(StartGameAnimation::num1Animation());
//    gameLayer->addChild(_coundownLabel, 1);
//    
//    // GO
//    CCSprite * start = CCSprite::create("go.png");
//    start->cocos2d::CCNode::setPosition(start->getPosition());
//    start->setScale(0);
//    start->runAction(StartGameAnimation::num0Animation(this, callfunc_selector(GameManager::startGameAnimation)));
//    gameLayer->addChild(start, 1);

}

void GameManager::commonGameScreen(CCLayer * layer)
{
    // Score
    _scoreLabel = CCLabelBMFont::create("0", "font.fnt", _winSize.width * 0.3);
    _scoreLabel->setAnchorPoint(ccp(1, 0.5));
    _scoreLabel->setPosition(ccp(_winSize.width * 0.8f, _winSize.height * 0.94f));
    layer->addChild(_scoreLabel);
    
    // Time
    _timeLabel = CCLabelBMFont::create("120", "font.fnt", _winSize.width * 0.3);
    _timeLabel->setPosition(ccp(_winSize.width * 0.9f, _winSize.height * 0.1));
    layer->addChild(_timeLabel);
    
    // Energy
    _enegyLabel = CCLabelBMFont::create("100%", "font.fnt", _winSize.width * 0.1f, kCCTextAlignmentRight);
    _enegyLabel->setPosition(ccp(_winSize.width * 0.3f, _winSize.height * 0.94f));
    layer->addChild(_enegyLabel);
    
    
    // Game Over Message
//    GameSprite * gameOverMessage = GameSprite::gameSpriteWithFileName("gameover.png");
//    gameOverMessage->setPosition(ccp(_winSize.width / 2, _winSize.height / 2));
//    gameOverMessage->setVisible(false);
//    background->addChild(gameOverMessage);
    
    
    
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

void GameManager::addScore(int reward)
{
    reward += reward;
}

void GameManager::updateGameData()
{
    
    
    
    
    
}

void GameManager::startGameAnimation()
{
    
}

void GameManager::stopGame()
{
    _running = false;
    
    // stop all actions currently running
    int i;
    int count;
    CCSprite * sprite;
    
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

