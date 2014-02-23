//
//  Player.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/19.
//
//

#ifndef __SadMemoryonYourWhiteCampus__Player__
#define __SadMemoryonYourWhiteCampus__Player__

#include <iostream>
#include "GameManager.h"
#include "GameLayer.h"

class Player : public cocos2d::CCNode
{
public:
    
    CC_SYNTHESIZE(float, _length, Length);
    CC_SYNTHESIZE(CCPoint, _startPoint, StartPoint);
    CC_SYNTHESIZE(CCPoint, _touchPoint, TouchPoint);
    
    Player();
    static Player * create ();
    void setBlinking (bool var);
    
    
private:
    
    
    inline bool pointEqualsZero(CCPoint point) {
        return (point.x == 0 && point.y == 0);
    };
    
    
};




#endif /* defined(__SadMemoryonYourWhiteCampus__Player__) */
