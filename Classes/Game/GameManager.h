//
//  GameManager.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/02/20.
//
//

#ifndef __SadMemoryonYourWhiteCampus__GameManager__
#define __SadMemoryonYourWhiteCampus__GameManager__

#include <iostream>
#include "GameConfig.h"
#include "GameSprite.h"

class GameManager : public cocos2d::CCObject
{
private:
    
    CCSize _winSize;
    
    GameSprite * background;
    
    float _initialLineDecrement;
    float _lineDecrementRatio;
    
    float _initialTimeDecrement;
    float _timeDecrementRatio;
    
    void updateGameData(void);
    
public:
    
    GameManager();
    ~GameManager();
    
    CC_SYNTHESIZE(int, _gameStage, GameStage);
    CC_SYNTHESIZE(bool, _gameState, GameState);
    CC_SYNTHESIZE_READONLY(int, _col, Columns);
    CC_SYNTHESIZE_READONLY(int, _rows, Rows);
    CC_SYNTHESIZE_READONLY(bool, _boosting, Boosting);
    
    /* Game Data */
    CC_SYNTHESIZE(int, _score, Score);
    CC_SYNTHESIZE_READONLY(int, _level, Level);
    CC_SYNTHESIZE_READONLY(int, _bestScore, BestScore);
    CC_SYNTHESIZE_READONLY(float, _lineDecrement, LineDecrement);
    CC_SYNTHESIZE_READONLY(float, _timeDecrement, TimeDecrement);
    CC_SYNTHESIZE(float, _lineEnergy, LineEnergy);
    
    CC_SYNTHESIZE_READONLY(float, _time, Time);
    
    static GameManager * sharedGameManager();
    
    void createGameScreen(GameStage stage, kTag type);
    CCNode * createGameParticle(const char * plistFile, kTag tag);
    CCNode * attackingParticle(const char * plistFile, kTag tag);
    
    void setBestScore(int var);
    
    void reset(void);
    void update(float dt);
    
};


#endif /* defined(__SadMemoryonYourWhiteCampus__GameManager__) */
