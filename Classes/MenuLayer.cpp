//
//  MenuLayer.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/03/02.
//
//

#include "MenuLayer.h"
#include "SelectStageLayer.h"
#include "GameScene1.h"


MenuLayer::MenuLayer() :
_winSize(CCDirector::sharedDirector()->getWinSize()),
_manager(GameManager::sharedGameManager())
{
   
    _manager->starGameCountdown();
   // startGameAnimation();
}


MenuLayer::~MenuLayer()
{
    
}

bool MenuLayer::init()
{
    /* super first init */
    if (!CCLayer::init()) return false;
    
    
    /* Menu Game Scene */
    createMenuScreen();
    
    /* listen to Touch */
    setTouchEnabled(true);
    
    
    /* loop Screen */
    this->scheduleOnce(schedule_selector(MenuLayer::startGameAnimation), 1);
    this->scheduleUpdate();
    
    return true;
}

void MenuLayer::update(float dt)
{
    
}


bool MenuLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}

void MenuLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    /* */
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCPoint touchPoint = pDirector->convertToGL(pTouch->getLocationInView());
    
    /* */
    streak->setPosition(touchPoint);
}

void MenuLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (pTouch) {
        CCPoint tap = pTouch->getLocation();
    }
}

void MenuLayer::createMenuScreen()
{
    /* Label */
    CCLabelTTF* pLabel = CCLabelTTF::create("ColorfulBeats2-x", "Hevetica-BoldOblique", 100);
    pLabel->setPosition( ccp(_winSize.width / 2, _winSize.height/2+100) );
    this->addChild(pLabel, 1);
    
    
    /* Play the Game */
    CCMenuItemFont::setFontName("Hevetica-BoldOblique");
    CCMenuItemFont::setFontSize(50);
    CCMenuItemFont* item = CCMenuItemFont::create("play the game", this, menu_selector(MenuLayer::selectGameStage));
    CCMenu *menu = CCMenu::createWithItem(item);
    menu->setPosition(ccp(_winSize.width / 2, _winSize.height / 2 - _winSize.height * 0.3));
    CCFadeTo* fadeIn = CCFadeTo::create(1.0f, 127);
    CCFadeTo* fadeOut = CCFadeTo::create(1.0f, 255);
    CCSequence *pulseSequence = CCSequence::createWithTwoActions(fadeIn, fadeOut);
    CCRepeatForever *repeat = CCRepeatForever::create(pulseSequence);
    menu->runAction(repeat);
    this->addChild(menu,100);
    
    this->setTouchEnabled(true);
    this->setTouchMode(kCCTouchesOneByOne);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    streak = CCMotionStreak::create(2, 3, 32, ccGREEN, "fire.png");
    streak->setPosition(ccp(winSize.width / 2, winSize.height / 2));
    this->addChild(streak);
    
    CCFiniteTimeAction* action = CCSequence::create(CCTintTo::create(0.2f, 255, 0, 0),
                                                    CCTintTo::create(0.2f, 0, 255, 0),
                                                    CCTintTo::create(0.2f, 0, 0, 255),
                                                    CCTintTo::create(0.2f, 0, 255, 255),
                                                    CCTintTo::create(0.2f, 255, 255, 0),
                                                    CCTintTo::create(0.2f, 255, 0, 255),
                                                    CCTintTo::create(0.2f, 255, 255, 255),
                                                    NULL);
    CCActionInterval *colorAction = CCRepeatForever::create((CCActionInterval *)action);
    streak->runAction(colorAction);
    
    _manager->commonGameScreen(this);
    
    
}

/* Play the Game */
void MenuLayer::selectGameStage()
{
   // CCScene * pScene = SelectStageLayer::scene();
    CCScene * pScene = GameScene1::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
}

void MenuLayer::startGameAnimation()
{
    /* first setting */
    CCLabelBMFont * _countdownLabel3;
    CCLabelBMFont * _countdownLabel2;
    CCLabelBMFont * _countdownLabel1;
    
    // 3
    _countdownLabel3 = CCLabelBMFont::create("3", "font.fnt", _winSize.width * 0.3);
    _countdownLabel3->setAnchorPoint(ccp(0.5, 0.5));
    _countdownLabel3->setPosition(ccp(_winSize.width * 0.5, _winSize.height * 0.5));
    _countdownLabel3->setScale(10);
    _countdownLabel3->runAction(StartGameAnimation::num3Animation());
    this->addChild(_countdownLabel3, 1);
    
    // 2
    _countdownLabel2 = CCLabelBMFont::create("2", "font.fnt", _winSize.width * 0.3);
    _countdownLabel2->setAnchorPoint(ccp(0.5, 0.5));
    _countdownLabel2->setPosition(ccp(_winSize.width * 0.5, _winSize.height * 0.5));
    _countdownLabel2->setScale(10);
    _countdownLabel2->runAction(StartGameAnimation::num2Animation());
    this->addChild(_countdownLabel2, 1);
    
    // 1
    _countdownLabel1 = CCLabelBMFont::create("1", "font.fnt", _winSize.width * 0.3);
    _countdownLabel1->setAnchorPoint(ccp(0.5, 0.5));
    _countdownLabel1->setPosition(ccp(_winSize.width * 0.5, _winSize.height * 0.5));
    _countdownLabel1->setScale(10);
    _countdownLabel1->runAction(StartGameAnimation::num1Animation());
    this->addChild(_countdownLabel1, 1);
    
    // GO
//    CCSprite * start = CCSprite::create("go.png");
//    start->cocos2d::CCNode::setPosition(start->getPosition());
//    start->setScale(0);
//    start->runAction(StartGameAnimation::num0Animation(this, callfunc_selector(MenuLayer::createMenuScreen)));
//    this->addChild(start, 1);
}


/* Scene */
CCScene * MenuLayer::scene()
{
    CCScene *scene = CCScene::create();
    MenuLayer *layer = MenuLayer::create();
    scene->addChild(layer);
    return scene;
}





