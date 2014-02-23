//
//  GameSprite.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/16.
//
//

#ifndef __SadMemoryonYourWhiteCampus__GameSprite__
#define __SadMemoryonYourWhiteCampus__GameSprite__

#include <iostream>
#include "GameConfig.h"

class GameSprite : public CCSprite {
    
    CCSize _winSize;
    
public:
    
    CC_SYNTHESIZE(CCPoint, _nextPosition, NextPosition);
    CC_SYNTHESIZE(float, _width, Width);
    CC_SYNTHESIZE(float, _height, Height);
    CC_SYNTHESIZE(CCPoint, _vector, Vector);
    
    GameSprite(void);
    ~GameSprite(void);
    
    static GameSprite * gameSpriteWithFile(const char * pszFileName);
    
    inline virtual void place() {
        this->setPosition(_nextPosition);
    }
    
    inline virtual float radius() {
        return _width * 0.5f;
    }
    
    inline void setSize() {
        _width = this->boundingBox().size.width;
        _height = this->boundingBox().size.height;
    }
};



#endif /* defined(__SadMemoryonYourWhiteCampus__GameSprite__) */
