//
//  MenuLayer.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/22.
//
//

#ifndef __SadMemoryonYourWhiteCampus__MenuLayer__
#define __SadMemoryonYourWhiteCampus__MenuLayer__

#include <iostream>
#include "GameConfig.h"
#include "GameManager.h"

class MenuLayer :
public CCLayer,
public CCBSelectorResolver,
public CCBMemberVariableAssigner
{
public:
    
    virtual ~MenuLayer();
    MenuLayer();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MenuLayer, create);
    
    void setAnimationManager(CCBAnimationManager *pAnimationManager);
    
//    virtual void ccTouchesEnded(CCSet * touches, CCEvent * event);
//    void update(float dt);
    
private:
    
    /* Singleton */
    GameManager * _manager;
    
    /* ScreenSize */
    CCSize _winSize;
    
    CCBAnimationManager * mAnimationManager;
    
    CCSpriteBatchNode * _gameBatchNode;
    
    CCSprite * selectStage;
    CCSprite * gameStory;
    
    /* Stage */
    CCSprite * gameStageOne;
    CCSprite * gameStageTwo;
    CCSprite * gameStageThree;
    void stagemenuLayer(CCObject * pSender, CCControlEvent pCCControlEvent);
    CC_SYNTHESIZE(int, _gameStage, GameStage);
    
    /* Score */
    int bestScore;
    CCString * score;
    CCLabelBMFont * scoreLabel;
    

    
    /* SpriteBuilder */
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
  
    
    void createMenuScreen();
    
};


#endif /* defined(__SadMemoryonYourWhiteCampus__MenuLayer__) */
