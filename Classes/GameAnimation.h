//
//  GameAnimation.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/03/05.
//
//

#ifndef __SadMemoryonYourWhiteCampus__GameAnimation__
#define __SadMemoryonYourWhiteCampus__GameAnimation__

#include <iostream>
#include "GameManager.h"

using namespace cocos2d;

class Player;
//class Enemy;

class GameAnimation : public CCNode
{
private:
    
public:
    GameAnimation();
    ~GameAnimation();
    

    
    static cocos2d::CCFiniteTimeAction * resultAnimation(cocos2d::CCObject * target, cocos2d::SEL_CallFunc selector);

    
};


class StartGameAnimation : public GameAnimation
{
public:

    ~StartGameAnimation();
    
    static cocos2d::CCFiniteTimeAction* num3Animation();
    static cocos2d::CCFiniteTimeAction* num2Animation();
    static cocos2d::CCFiniteTimeAction* num1Animation();
    static cocos2d::CCFiniteTimeAction* num0Animation(cocos2d::CCObject* target, cocos2d::SEL_CallFunc selector);
    
};


class PlayingGameAnimation : public GameAnimation
{
 //   GameManager * _manager;
    
    cocos2d::CCAnimation * backgroundAnimation;
    
public:
    
    ~PlayingGameAnimation();
    
    static void hitofSmallEnemy(GameStage * stage);
    static void hitofMiddleEnemy(GameStage * stage);
    static void hitofBigEnemy(GameStage * stage);
    
    void setBackgroundAnimation(GameStage stage);
    
};



#endif /* defined(__SadMemoryonYourWhiteCampus__GameAnimation__) */
