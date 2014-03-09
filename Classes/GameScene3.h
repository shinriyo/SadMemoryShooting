//
//  GameScene3.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/25.
//
//

#ifndef __SadMemoryonYourWhiteCampus__GameScene3__
#define __SadMemoryonYourWhiteCampus__GameScene3__

#include <iostream>
#include "GameManager.h"

struct Space
{
    
};

class GameScene3 : public cocos2d::CCLayer
{
private:
    
    CCSize _winSize;
    
    GameManager * _manager;
    
    
    int _gameState;
    bool _running;
    
    /* Game Control */
    void initGame(void);
    void createGameScreen(void);
    void createGameAction(void);
    void gameOver(void);
    void reset(void);
    
    inline bool pointEqualsPoints (CCPoint point1, CCPoint point2)
    {
        return point1.x == point2.x && point1.y == point2.y;
    }
    

    
    
public:
    
    GameScene3();
    ~GameScene3();
    
    static GameScene3 * create();
    static CCScene * scene();
    
    virtual void ccTouchesBegan(CCSet * touches, CCEvent * event);
    virtual void ccTouchesMoved(CCSet * touches, CCEvent * event);
    virtual void ccTouchedEnded(CCSet * touches, CCEvent * event);
    
    void update(float dt);
    
    
};


#endif /* defined(__SadMemoryonYourWhiteCampus__GameScene3__) */
