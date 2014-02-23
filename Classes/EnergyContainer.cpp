//
//  EnergyContainer.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/22.
//
//

#include "EnergyContainer.h"


EnergyContainer::EnergyContainer() :
_winSize(CCDirector::sharedDirector()->getWinSize()),
_manager(GameManager::sharedGameManager())
{
    _energyX = _winSize.width * 0.1f;
    _energyY = _winSize.height * 0.03f;
    
    
    glLineWidth(ENERGY_DRAW * CC_CONTENT_SCALE_FACTOR());
    
    
}

EnergyContainer * EnergyContainer::create()
{
    EnergyContainer * node = new EnergyContainer();
    if (node) {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return NULL;
}

void EnergyContainer::reset()
{
    _energy = 1.0;
    _energyDecrement = 0.015f;
    
}

void EnergyContainer::update(float dt)
{
    _energy -= dt * _energyDecrement;
    if ( _energy < 0 ) _energy = 0;
}


void EnergyContainer::draw()
{
    CCNode::draw();
    
    float totalWidth = _winSize.width * 0.8f;
    
    ccDrawColor4F(0.0, 1.0, 1.0, 1.0);
    ccDrawLine( ccp(_energyX, _energyY), ccp(_energyX + totalWidth, _energyY) );
}