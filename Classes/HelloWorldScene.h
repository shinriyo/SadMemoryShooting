#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameSprite.h"

class HelloWorld : public cocos2d::CCLayer
{
    cocos2d::CCParticleSystemQuad * _backParticle;
    
    GameSprite* pSprite;
    
    CCPoint touchStartPoint;
    
    CCLayer * baseLayer;
    
    CCSprite * background;
    
    CCCamera * pCamera;
    
public:
    
    HelloWorld();
    ~HelloWorld();

    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(HelloWorld);
    
    
    virtual void ccTouchesBegan(cocos2d::CCSet* pTouches, cocos2d::CCEvent* event);
	virtual void ccTouchesMoved(cocos2d::CCSet* pTouches, cocos2d::CCEvent* event);
	virtual void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* event);
	
	void update (float dt);
};

#endif // __HELLOWORLD_SCENE_H__
