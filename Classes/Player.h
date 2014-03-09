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


typedef enum
{
    kUP,
    kRIGHTUP,
    kRIGHT,
    kRIGHTDOWN,
    kDOWN,
    kLEFTDOWN,
    kLEFT,
    kLEFTUP

} MovingState;


class Player : public GameSprite
{
private:
    
    /* first setting */
    GameManager * _manager;
    CCSize  _winSize;

    /* */
    int _targetInterval;
    
    void initPlayer(void);
    

public:
    
    CC_SYNTHESIZE(CCPoint, _vector, Vector);
    CC_SYNTHESIZE(float, _length, Length);
    CC_SYNTHESIZE(float, _speed, Speed);
    CC_SYNTHESIZE(float, _radius, Radius);
    CC_SYNTHESIZE(CCPoint, _startPoint, StartPoint);
    CC_SYNTHESIZE(CCPoint, _touchPoint, TouchPoint);
    CC_SYNTHESIZE(MovingState, type, Type);
    
    Player(void);
    ~Player(void);
    
    GameSprite * _player;
    
    static Player * create ();
    
    virtual void update(float dt);
    void reset(void);
    bool select(bool flag);
    
    bool collidedWithSides(void);  
    
    
    
    void setBlinking (bool var);
    
    inline float Radius(void) {

    }
};




#endif /* defined(__SadMemoryonYourWhiteCampus__Player__) */
