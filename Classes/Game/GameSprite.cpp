//
//  GameSprite.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/16.
//
//

#include "GameSprite.h"

USING_NS_CC;

GameSprite::GameSprite(float radius) : _winSize(CCDirector::sharedDirector()->getWinSize())
{
    _radius = radius;
    _squaredRadius = _radius * _radius;
    _vector = CCPointZero;
    _active = true;
}

GameSprite::GameSprite()
{
    
}



GameSprite * GameSprite::gameSpriteWithFileName(const char * pszFileName, float radius)
{
    GameSprite * sprite = new GameSprite(radius);
    
    if (sprite && sprite->initWithFile(pszFileName)) {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}

GameSprite * GameSprite::gameSpriteWithFileName(const char * pszFileName)
{
//   // GameSprite * sprite = new GameSprite();
//    
//    if (sprite && sprite->initWithFile(pszFileName)) {
//        sprite->autorelease();
//        return sprite;
//    }
//    CC_SAFE_DELETE(sprite);
//    return NULL;
    GameSprite * sprite = new GameSprite();
	if (sprite && sprite->initWithFile(pszFileName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}


void GameSprite::reset(void)
{
    _vector = ccp(0, 0);
    _nextPosition = this->getPosition();
    _active = true;
    
}

void GameSprite::destroy(void)
{
    
}

void GameSprite::update(float dt)
{
    _nextPosition = ccp(this->getPositionX() + _vector.x, this->getPositionY() + _vector.y);
}