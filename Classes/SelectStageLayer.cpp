//
//  SelectStageLayer.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/03/02.
//
//

#include "SelectStageLayer.h"


SelectStageLayer::SelectStageLayer() :
_winSize(CCDirector::sharedDirector()->getWinSize())
{
    _score = 0;
    createSelectStageSceen();
    
    
}

SelectStageLayer::~SelectStageLayer()
{
    
}

bool SelectStageLayer::init()
{
    if (!CCLayer::init()) return false;
    
    
    CCLog("select stage layer");
    
    bg = CCSprite::create("RockOn_1.png");
    bg->setPosition(ccp(_winSize.width / 2, _winSize.height / 2));
    this->addChild(bg);
    
    
    this->setTouchEnabled(true);
    setTouchMode(kCCTouchesOneByOne);
    
    
    scheduleUpdate();
    
    return true;
}

void SelectStageLayer::ccTouchesBegan(cocos2d::CCSet *touches, cocos2d::CCEvent *event)
{
    
}

void SelectStageLayer::ccTouchesEnded(cocos2d::CCSet *touches, cocos2d::CCEvent *event)
{
    CCTouch * touch = (CCTouch *) touches->anyObject();
    
    CCLog("oooooggg");
    
    if (touch) {
        
        CCLog("hasahsha");
        
        CCPoint tap = touch->getLocation();
        CCRect boundsStageLabel = _stage->boundingBox();
        CCRect boundsrock = bg->boundingBox();
        
        
        if (boundsStageLabel.containsPoint(tap)) {
            CCLog("tap stage");
            
        } else if (boundsrock.containsPoint(tap)) {
            CCLog("hey");
        }
        
        
    }
}



void SelectStageLayer::createSelectStageSceen()
{
    int i;
    /* Sceen Title */
    _title = CCLabelTTF::create("Select Stages", "Arial", 60);
    _title->setContentSize(_title->getContentSize());
    _title->setPosition( ccp(_winSize.width * 0.5, _winSize.height * 0.9) );
    this->addChild(_title, 100);
    
    _manager = GameManager::sharedGameManager();
    
//    for (i = 1; i <= _manager->getGameStage(); i++) {
//        _title = CCLabelTTF::create("Stage", "Arial", 40);
//        _title->setPosition(ccp(_winSize.width * 0.5, _winSize.height * 0.5 * i));
//        this->addChild(_title,100);
//    }
    
    int gameStage = _manager->getGameStage();
    
    switch (gameStage) {
        
        case kGameStage1:
            _stage = CCLabelTTF::create("Stage 1", "Arial", 40);
            _stage->setPosition( ccp(_winSize.width * 0.5, _winSize.height * 0.6) );
            _stage->setTag(kGameStage1);
           // _manager->setGameStage(kGameStage1);
            this->addChild(_stage, 100);
            break;
            
        case kGameStage2:
            _stage = CCLabelTTF::create("Stage 2", "Arial", 40);
            _stage->setPosition( ccp(_winSize.width * 0.5, _winSize.height * 0.6 * 0.15) );
            _stage->setTag(kGameStage2);
            this->addChild(_stage, 100);
            break;
            
        case kGameStage3:
            _stage = CCLabelTTF::create("Stage 3", "Arial", 40);
            _stage->setPosition( ccp(_winSize.width * 0.5, _winSize.height * 0.6 * 0.30) );
            _stage->setTag(kGameStage3);
            //_manager->setGameStage(kGameStage3);
            this->addChild(_stage, 100);
            break;
        default:
            break;
    }
    
}

void SelectStageLayer::showAnimationStageBackground(GameStage *stage)
{
    
}

//void SelectStageLayer::selectStage(GameStage * stage)
//{
//    
//}

CCScene * SelectStageLayer::scene()
{
    CCScene * scene = CCScene::create();
    SelectStageLayer * layer = SelectStageLayer::create();
    scene->addChild(layer);
    
    return scene;
}
