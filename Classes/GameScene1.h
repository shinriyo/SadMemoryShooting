//
//  GameScene1.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/25.
//
//

#ifndef __SadMemoryonYourWhiteCampus__GameScene1__
#define __SadMemoryonYourWhiteCampus__GameScene1__

#include <iostream>
#include "GameManager.h"
#include "GameAnimation.h"
#include "Player.h"
#include "Enemy.h"


struct Sun
{

};


class GameScene1 : public CCLayer
{
public:
    GameScene1();
    ~GameScene1();
    
//    /* Singleton */
//    GameManager * _manager;
    
    static GameScene1 * create();
    static CCScene * scene();
    
    virtual void ccTouchesBegan(CCSet * touches, CCEvent * event);
    virtual void ccTouchesMoved(CCSet * touches, CCEvent * event);
    virtual void ccTouchedEnded(CCSet * touches, CCEvent * event);
    
    void update(float dt);
    
    void allEnemyObjectDone(CCNode * pSender);
    
    
private:
    
    /* Setting */
    CCSize _winSize;
    
    /* Singleton */
    GameManager * _manager;
    
    /* Background */
    GameSprite * _background;
    CCSpriteBatchNode * _backgroundSprites;
    CCCamera * backgroundAction;
    CCArray * _backgrounds;
    
    /* Class */
    Player * _player;
    EnemyStage1 * enemies;
    
    CCArray * _allEnemies;
    
    /* Particles */
    CCParticleSystemQuad * sampleParticle;
    

    /* Actions */

    
    

    /* Setting */
    int _gameState;
    
    /* Game Flag */
    bool _running;
    
    /* Game Label */
    
    /* Game Button */
    
    /* Game Control */
    void initGame(void);
    void createGameScreen(void);
    void createGameAction(void);
    void gameOver(void);
    void reset(void);
    
    inline bool pointEqualsPoint (CCPoint point1, CCPoint point2)
    {
        return point1.x == point2.x && point1.y == point2.y;
    }
    
    inline void clearLabels (void)
    {
        
    }
    
};



#endif /* defined(__SadMemoryonYourWhiteCampus__GameScene1__) */
