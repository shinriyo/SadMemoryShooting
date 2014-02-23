//
//  SelectStageLayer.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/23.
//
//

#ifndef __SadMemoryonYourWhiteCampus__SelectStageLayer__
#define __SadMemoryonYourWhiteCampus__SelectStageLayer__

#include <iostream>
#include "GameManager.h"
#include "GameLayer.h"

class SelectStageLayer :
public CCLayer, CCBSelectorResolver, CCBMemberVariableAssigner
{
public:
    
    SelectStageLayer();
    virtual ~SelectStageLayer();
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SelectStageLayer, create);
    
    void setAnimationManager(CCBAnimationManager * pAnimatiionManager);
    
private:
    
    /* SpriteBuilder */
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName);
    virtual SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName);
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode);
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, CCBValue* pCCBValue);
    
    void createTapStageActions(void);
    
    
};



#endif /* defined(__SadMemoryonYourWhiteCampus__SelectStageLayer__) */
