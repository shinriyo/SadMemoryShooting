//
//  GameScene2.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/25.
//
//

#ifndef __SadMemoryonYourWhiteCampus__GameScene2__
#define __SadMemoryonYourWhiteCampus__GameScene2__

#include <iostream>
#include "GameManager.h"

struct Sea
{
    
};

class GameScene2 : public cocos2d::CCLayer
{
private:
    
    /* Setting */
    CCSize _winSize;
    
    /* Singleton */
    GameManager * _manager;
    
    
    
public:
    GameScene2();
    ~GameScene2();
    
    //static GameScene2 * create();
    static CCScene * scene();
    CREATE_FUNC(GameScene2);
    
    virtual void ccTouchesBegan(CCSet * touches, CCEvent * event);
    virtual void ccTouchesMoved(CCSet * touches, CCEvent * event);
    virtual void ccTouchedEnded(CCSet * touches, CCEvent * event);
    
    void update(float dt);
    
    
    
};

#endif /* defined(__SadMemoryonYourWhiteCampus__GameScene2__) */
