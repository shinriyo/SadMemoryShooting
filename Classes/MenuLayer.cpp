//
//  MenuLayer.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/22.
//
//

#include "MenuLayer.h"
#include "MenuLayerLoader.h"
#include "SelectStageLayer.h"



MenuLayer::MenuLayer()
{
    selectStage = NULL;
    mAnimationManager = NULL;
    createMenuScreen();
    
}

MenuLayer::~MenuLayer()
{
    CC_SAFE_RELEASE(selectStage);
    CC_SAFE_RELEASE(mAnimationManager);
}

SEL_MenuHandler MenuLayer::onResolveCCBCCMenuItemSelector(CCObject * pTarget, const char * pSelectorName)
{
    
    
    return NULL;
}

SEL_CCControlHandler MenuLayer::onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
{
    return NULL;
}

bool MenuLayer::onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
{
    
    
    return false;
}


void MenuLayer::setAnimationManager(CCBAnimationManager * pAnimationManager)
{
    CC_SAFE_RELEASE_NULL(mAnimationManager);
    mAnimationManager = pAnimationManager;
    CC_SAFE_RETAIN(mAnimationManager);
}

void MenuLayer::stagemenuLayer(CCObject * pSender, CCControlEvent pCCControlEvent)
{
    CCScene * selectStageScene = CCTransitionFlipY::create(0.5f, GameLayer::scene());
    CCDirector::sharedDirector()->replaceScene(selectStageScene);
}

void MenuLayer::createMenuScreen()
{
    
    
    
    // add best score number
    bestScore = _manager->getBestScore();
    
    if (bestScore > 1)
    {
        score = CCString::createWithFormat("Best Score: %i points", bestScore);
        scoreLabel = CCLabelBMFont::create(score->getCString(), "", _winSize.width * 0.8f);
        scoreLabel->setPosition(ccp(_winSize.width * 0.5f, _winSize.height * 0.5f));
        this->addChild(scoreLabel, kForeground);
    }
}

