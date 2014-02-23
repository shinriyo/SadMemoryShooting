//
//  GameSprite.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/16.
//
//

#include "GameSprite.h"

USING_NS_CC;

GameSprite::GameSprite(void) : _vector(CCPointZero)
{
    _winSize = CCDirector::sharedDirector()->getWinSize();
}

GameSprite::~GameSprite(void)
{
    
}

GameSprite * GameSprite::gameSpriteWithFile(const char * pszFileName)
{
    GameSprite * sprite = new GameSprite();
    if (sprite && sprite->initWithFile(pszFileName)) {
        sprite->autorelease();
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}
