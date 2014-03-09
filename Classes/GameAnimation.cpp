//
//  GameAnimation.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/03/05.
//
//

#include "GameAnimation.h"



/**** Game Animation ****/
GameAnimation::GameAnimation()
{
    
}

GameAnimation::~GameAnimation()
{
    //

}


CCFiniteTimeAction * GameAnimation::resultAnimation(CCObject * target, SEL_CallFunc selector)
{
    CCScaleTo * scaleUp = CCScaleTo::create(0.5, 1);
    CCDelayTime * delay = CCDelayTime::create(1);
    CCCallFunc * func = CCCallFunc::create(target, selector);
    
    return CCSequence::create(scaleUp, delay, func, NULL);
}




/**** Start Game Animation ****/
StartGameAnimation::~StartGameAnimation()
{
    //
    CC_SAFE_RELEASE(num3Animation());
    CC_SAFE_RELEASE(num2Animation());
    CC_SAFE_RELEASE(num1Animation());
}

CCFiniteTimeAction * StartGameAnimation::num3Animation()
{
    CCDelayTime * delay1 = CCDelayTime::create(0.5);
    CCScaleTo * scaleUp = CCScaleTo::create(0.1, 1);
    CCDelayTime * delay2 = CCDelayTime::create(0.3);
    CCScaleTo * scaleDown = CCScaleTo::create(0.1, 0);
    
    return CCSequence::create(delay1, scaleUp, delay2, scaleDown, NULL);
}

CCFiniteTimeAction * StartGameAnimation::num2Animation()
{
    CCDelayTime * delay = CCDelayTime::create(1);
    
    return CCSequence::create(delay, StartGameAnimation::num3Animation(), NULL);
}

CCFiniteTimeAction * StartGameAnimation::num1Animation()
{
    CCDelayTime * delay = CCDelayTime::create(2);
    
    return CCSequence::create(delay, StartGameAnimation::num3Animation(), NULL);
    
}

CCFiniteTimeAction * StartGameAnimation::num0Animation(CCObject * target, SEL_CallFunc selector)
{
    CCDelayTime * delay = CCDelayTime::create(3);
    CCCallFunc * func = CCCallFunc::create(target, selector);
    
    return CCSequence::create(delay, StartGameAnimation::num3Animation(), func, NULL);
}

/**** Playing Game Animation ****/
PlayingGameAnimation::~PlayingGameAnimation()
{
    CC_SAFE_RELEASE(backgroundAnimation);
}

void PlayingGameAnimation::setBackgroundAnimation(GameStage stage)
{
    int i;
    CCSprite * background;
    backgroundAnimation = CCAnimation::create();
    
  //  background->setPosition(ccp(_mana, ));
    
    for (i = 1; i < 3; i++) {
        char szImageName[100] = {0};
        
        switch (stage) {
            case kGameStage1:
                sprintf(szImageName, "gamestage1_%i.png");
                break;
            case kGameStage2:
                break;
            case kGameStage3:
                break;
            default:
                break;
        }
        backgroundAnimation->setDelayPerUnit(0.2f / 3.0);
        backgroundAnimation->setLoops(-1);
        CCRepeatForever *action = CCRepeatForever::create( CCAnimate::create(backgroundAnimation) );
        
        background->runAction(action);
        
    }
    
}









