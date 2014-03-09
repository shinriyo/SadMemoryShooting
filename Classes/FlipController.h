//
//  FlipController.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/24.
//
//

#ifndef __SadMemoryonYourWhiteCampus__FlipController__
#define __SadMemoryonYourWhiteCampus__FlipController__

#include <iostream>
#include "GameManager.h"

enum kFlipController
{
    kFlipControllerUp,
    kFlipControllerRighttUp,
    kFlipControllerRight,
    kFlipControllerRightDown,
    kFlipControllerDown,
    kFlipControllerLeftDown,
    kFlipControllerLeft,
    kFlipControllerLeftUp
};

class FlipController : public CCNode
{
private:
    CCNode * target;
    
    float xV, yV;
    bool isXLessThanZero, isYLessThanZero = false;
    CCPoint _touchStartPoint;
    
    GameManager * _manager;
    
    
public:
    CC_SYNTHESIZE(int, tag, Tag);
    CC_SYNTHESIZE(kFlipController, type, Type);
    
    FlipController(void);
    virtual ~FlipController(void);
    
    double angle();
    

    void executeAction(CCNode * target, CCSize);
};

#endif /* defined(__SadMemoryonYourWhiteCampus__FlipController__) */
