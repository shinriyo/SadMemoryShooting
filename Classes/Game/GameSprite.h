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

class GameSprite : public cocos2d::CCSprite {
    
    cocos2d::CCSize _winSize;
    
public:
    
    GameSprite (float radius);
    GameSprite ();
    
    CC_SYNTHESIZE(bool, _active, Active);
    CC_SYNTHESIZE(bool, _hit, Hit);
    CC_SYNTHESIZE(int, _life, Life);
    CC_SYNTHESIZE(float, _speed, Speed);
    CC_SYNTHESIZE(float, _interval, Interval);
    CC_SYNTHESIZE(float, _timer, Timer);
    CC_SYNTHESIZE(float, _radius, Radius);
    CC_SYNTHESIZE(float, _squaredRadius, SquaredRadius);
    CC_SYNTHESIZE(float, _width, Width);
    CC_SYNTHESIZE(float, _height, Height);
    CC_SYNTHESIZE(CCPoint, _vector, Vector);
    CC_SYNTHESIZE(CCPoint, _nextPosition, NextPosition);
    CC_SYNTHESIZE(CCTouch *, _touch, Touch);
    
    static GameSprite * gameSpriteWithFileName(const char * pszFileName, float radius);
    static GameSprite * gameSpriteWithFileName(const char * pszFileName);
    
    
    
    
    virtual void reset(void);
    virtual void destroy(void);
    virtual void update(float dt);
    
    inline virtual void place() {
     //   this->setPosition(_nextPosition);
        this->setPositionX(_nextPosition.x);
        this->setPositionY(_nextPosition.y);
    }
    
    inline virtual void setPosition(const CCPoint& pos)
    {
        CCSprite::setPosition(pos);
        if (!_nextPosition.equals(pos)) _nextPosition = pos;
    }
    
    inline virtual float radius() {
        // return _width * 0.5f;
        return getTexture()->getContentSize().width * 0.5f;
    }
    
    inline void setSize() {
        _width = this->boundingBox().size.width;
        _height = this->boundingBox().size.height;
    }
};



#endif /* defined(__SadMemoryonYourWhiteCampus__GameSprite__) */
