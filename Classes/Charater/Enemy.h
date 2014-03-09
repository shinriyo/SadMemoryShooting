//
//  Enemy.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/16.
//
//

#ifndef __SadMemoryonYourWhiteCampus__Enemy__
#define __SadMemoryonYourWhiteCampus__Enemy__

#include <iostream>
#include "GameConfig.h"
#include "GameManager.h"
#include "GameSprite.h"

class Enemy : public cocos2d::CCNode
{
    
    GameManager * _manager;
    cocos2d::CCSize _winSize;
    
    int life;
    const char * getImageFileName(kEnemy type);
    
    CCArray * _enemy1;
    int _enemy1Index;
    
    CCArray * _enemy2;
    int _enemy2Index;
    
    CCArray * _enemy3;
    int _enemy3Index;
    
    CCArray * _enemyObjects;
    
    void createEnemies(kEnemy & enemy);
    void createEnemies(GameStage & stage, kEnemy & enemy, GameSprite * sprite);
    void createEnemies(GameStage & stage, std::vector<kEnemy> & enemy, GameSprite * sprite);
    void createEnemies(GameStage & stage, std::map<kEnemy, GameSprite> * info);
    void createEnemyActions(void);
    
    
public:
    
    Enemy();
    virtual ~Enemy();
    
    virtual bool init(int tag, kEnemy type);
    static Enemy * create(int tag, kEnemy type);
    
    CC_SYNTHESIZE(int, tag, Tag);
    CC_SYNTHESIZE(kEnemy, type, Type);
    CC_SYNTHESIZE(CCSprite, _sprite, Sprite);
    CC_SYNTHESIZE(CCPoint, _vector, Vector);
    CC_SYNTHESIZE(CCPoint, _pivot, Pivot);
    CC_SYNTHESIZE(float, _speed, Speed);
    CC_SYNTHESIZE(bool, _staged, Staged);
    CC_SYNTHESIZE(float, radius, Radius);
    
    void select(bool flag, CCPoint point);
    bool collidedWithBeam(void);
    bool collidedWithPlayer(void);
    
    
    void update(float dt);
    
    
    
};


#endif /* defined(__SadMemoryonYourWhiteCampus__Enemy__) */
