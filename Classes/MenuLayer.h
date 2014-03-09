//
//  MenuLayer.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/03/02.
//
//

#ifndef __SadMemoryonYourWhiteCampus__MenuLayer__
#define __SadMemoryonYourWhiteCampus__MenuLayer__

#include <iostream>
#include "GameManager.h"

class MenuLayer : public cocos2d::CCLayer
{
public:
    MenuLayer();
    ~MenuLayer();
    
    virtual bool init();
    static cocos2d::CCScene * scene();
    CREATE_FUNC(MenuLayer);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    
    virtual void update(float dt);
    
    
private:
    
    CCSpriteBatchNode * _gameBatchNode;
    
    GameManager * _manager;
    cocos2d::CCSize _winSize;
    cocos2d::CCSprite * background;
    
    cocos2d::CCLabelBMFont * _titleDisplay;
    cocos2d::CCMotionStreak * streak;
    cocos2d::CCParticleSystemQuad * backParticle;
    
   // void init(void);
    void startGameAnimation(void);
    void createMenuScreen(void);
    void selectGameStage(void);
};

#endif /* defined(__SadMemoryonYourWhiteCampus__MenuLayer__) */
