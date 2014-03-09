//
//  Player.cpp
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/19.
//
//

#include "Player.h"


Player::Player() :
_manager(GameManager::sharedGameManager()),
_winSize(CCDirector::sharedDirector()->getWinSize())
{
 //   this->reset();
    _speed = 0;
    _nextPosition = CCPointZero;
    
    
    
}

Player::~Player()
{
    
}

Player * Player::create()
{
    Player * player = new Player();
    
    if (player && player->initWithFile("player_off.png")) {
        player->autorelease();
        player->setSize();
     //   player->initPlayer();
        return player;
    }
    CC_SAFE_DELETE(player);
    return NULL;
}

bool Player::collidedWithSides()
{
    if (m_obPosition.x > _winSize.width - _radius) {
        m_obPosition.x = _winSize.width - _radius;
        return true;
    }
    
    if (m_obPosition.x < _radius) {
        m_obPosition.x = _radius;
        return true;
    }
    
    if (m_obPosition.y < _radius) {
        m_obPosition.y = _radius;
        return true;
    }
    
    if (m_obPosition.y > _winSize.height - _radius) {
        m_obPosition.y = _winSize.height - _radius;
        return true;
    }
    
    
    return false;
}

void Player::update(float dt)
{
    GameSprite * player;
    CCPoint playerNextPosition;
    CCPoint playerVector;
    
    playerNextPosition = player->getNextPosition();
    playerVector = player->getVector();
    
    float diffx = playerNextPosition.x - player->getPositionX();
    float diffy = playerNextPosition.y - player->getPositionY();
    
    float angle = atan2f(diffy, diffx) * 180 / M_PI;
    
    /**** Flick ****/

    
    
    
}

void Player::reset()
{
    
}






