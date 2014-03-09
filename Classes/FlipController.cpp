//
//  FlipController.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/24.
//
//

#include "FlipController.h"

void FlipController::executeAction(CCNode * target, CCSize winSize)
{
    CCAction * action = NULL;
    
}

double FlipController::angle()
{
    CCPoint touchEndPoint;
    
    /* x */
    if (touchEndPoint.x - _touchStartPoint.x < 0) {

        
    } else {
        
    }
    /* y */
    if (touchEndPoint.y - _touchStartPoint.y < 0) {
        
    } else {
        
    }
    
    CCPoint p = ccp(xV, yV);
    
    return atan( ((double)p.y / (double)p.x) ) * 180 / M_PI;
    
}
