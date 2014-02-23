//
//  GameLayer.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/16.
//
//

#ifndef __SadMemoryonYourWhiteCampus__GameLayer__
#define __SadMemoryonYourWhiteCampus__GameLayer__

#include <iostream>
#include "GameConfig.h"
#include "GameManager.h"
#include "GameSprite.h"


class GameLayer : public CCLayer
{
private:
    
//    GameSprite * _rockon;
//    
//    CCSize _winSize;
//    GameState _state;
//    
//    CCArray * _enemyPool_1;
//    int _enemyPoolIndex_1;
//    
//    CCArray * _enemyPool_2;
//    int _enemyPoolIndex_2;
//    
//    CCArray * _enemyPool_3;
//    int _enemyPoolIndex_3;
//    
//    CCArray * _enemies;
//    
//    GameSprite * _boss;
//    
//    CCArray * _enemyObjects;
//    CCSpriteBatchNode * _gameBatchNode;
//    
//    CCAction * _enemyAction_1;
//    CCAction * _enemyAction_2;
//    CCAction * _enemyAction_3;
//    
    GameManager * _manager;
//    
//    // Time Label
//    CCLabelBMFont * timeLabel;
//    
//    // Score Label
//    
//  //  int _gameState;
//    int _energy;
//    int _score;
//    bool _running;
//    
//    
//    // Enemy Interval
//    float _enemy1Interval;
//    float _enemy2Interval;
//    float _enemy3Interval;
//    
//    // Enemy Timer
//    float _enemy1Timer;
//    float _enemy2Timer;
//    float _enemy3Timer;
//    
//    // Difficulty
//    float _difficultyInterval;
//    float _difficultyTimer;
//    
//    void resetEnemy(void);
//    void createEnemies(void);
//    void createEnemies(kTag tag, kEnemy type, CCPoint spawnPoint);
//    CCNode * createParticle(const char * particleListFile, kTag tag, const CCPoint point);
//    //void resetHealth(void);
//    void initForVariables(void);
//    void initGame(void);
//    void resetGame(void);
//    void startGame(void);
//    void stopGame(void);
//    void increaseDifficulty(void);
//    
//    void createGameScreen(void);
//    void createEnemyActions(void);
//    
//    inline bool pointEqualsPoint (CCPoint point1, CCPoint point2)
//    {
//        return point1.x == point2.x && point1.y == point2.y;
//    }
//    
//    inline void clearLabels (void)
//    {
//
//    }
//    
//    
//    void removingNode(CCNode * node);
    
    
    
    
public:
        GameLayer();
        virtual ~GameLayer();
    
        /* Singleton */
        static GameLayer * sharedInstance();
//    
//    
//    /* cocos2dx Layer */
//    //virtual bool init();
        static GameLayer * create();
        static CCScene * scene();
        static CCScene * sceneWithGameStage(GameStage stage);
//    // CREATE_FUNC(GameLayer);
//    
//    
//    void enemyObjectsDone(CCNode * pSender);
//    
//    
    void update(float dt);
    
    virtual void ccTouchesBegan(CCSet * pTouches, CCEvent * event);
    virtual void ccTouchesMoved(CCSet * pTouches, CCEvent * event);
    virtual void ccTouchesEnded(CCSet* pTouches, CCEvent* event);

//    void startGame(CCObject * pSender);
//    void stopGame(CCObject * pSender);
//    
//    void pause(void);
//    void resume(void);
//    
//    void gameover(CCObject * pSender);
//    
//    void addScore(int score);
//    void resetScore();

};




#endif /* defined(__SadMemoryonYourWhiteCampus__GameLayer__) */
