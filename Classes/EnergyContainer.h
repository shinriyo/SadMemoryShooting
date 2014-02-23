//
//  EnergyContainer.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/22.
//
//

#ifndef __SadMemoryonYourWhiteCampus__EnergyContainer__
#define __SadMemoryonYourWhiteCampus__EnergyContainer__

#include <iostream>
#include "GameConfig.h"
#include "GameManager.h"

class EnergyContainer : public CCNode
{
public:
    CC_SYNTHESIZE(float, _energy, Energy);
    CC_SYNTHESIZE(float, _energyLength, EnergyLength);
    
    EnergyContainer();
    static EnergyContainer * create();
    
    virtual void draw();
    void update(float dt);
    void setEnergyDecrement(float value);
    void reset(void);
    
private:
    
    CCSize _winSize;
    GameManager * _manager;
    
    float _energyX;
    float _energyY;
    float _energyDecrement;
    
    bool pointEqualsZero (CCPoint point ) {
        return (point.x == 0 && point.y == 0);
    }
    
    
};


#endif /* defined(__SadMemoryonYourWhiteCampus__EnergyContainer__) */
