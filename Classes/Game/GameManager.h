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
#include "GameAnimation.h"

class GameManager : public cocos2d::CCObject
{
private:
    
    cocos2d::CCSize _winSize;
    
    GameSprite * background;
    
    cocos2d::CCLayer * gameLayer;
    
    cocos2d::CCAction * _beforeGameStart;
    
    /* Common Game */
    cocos2d::CCSprite * _labelGameOver;
    cocos2d::CCSprite * _labelBestScore;
    cocos2d::CCSprite * _labelGameStart;
    cocos2d::CCLabelBMFont * _coundownLabel;
 //   cocos2d::CCLabelBMFont * _scoreLabel;
    CCLabelBMFont * _timeLabel;
    CCLabelBMFont * _enegyLabel;
    
    
    float _initialLineDecrement;
    float _lineDecrementRatio;
    
    float _initialTimeDecrement;
    float _timeDecrementRatio;
    
    void updateGameData(void);
    
    void startGameAnimation(void);
    
    
    inline void clearLabels(void)
    {
        _labelGameOver->setVisible(false);
        _labelBestScore->setVisible(false);
        _labelGameStart->setVisible(false);
        _scoreLabel->setVisible(false);
        _timeLabel->setVisible(false);
    
        
    }
    
public:
    
    GameManager();
    ~GameManager();
    
    CC_SYNTHESIZE(int, _gameStage, GameStage);
    CC_SYNTHESIZE(int, _gameState, GameState);
    CC_SYNTHESIZE(bool, _running, Running);
    CC_SYNTHESIZE_READONLY(int, _col, Columns);
    CC_SYNTHESIZE_READONLY(int, _rows, Rows);
    CC_SYNTHESIZE_READONLY(bool, _boosting, Boosting);
    
    
    /* Common Label */
  //  CC_SYNTHESIZE(CCLabelBMFont, * _scoreLabel, ScoreLabel);
    CCLabelBMFont * _scoreLabel;
    
    /* Game Data */
    CC_SYNTHESIZE(int, _score, Score);
    CC_SYNTHESIZE_READONLY(int, _level, Level);
    CC_SYNTHESIZE(int, _totalCollectedEnemies, TotalCollectedEnemies);
    CC_SYNTHESIZE(int, _totalScore, TotalScore);
    CC_SYNTHESIZE_READONLY(int, _bestScore, BestScore);
    CC_SYNTHESIZE_READONLY(float, _lineDecrement, LineDecrement);
    CC_SYNTHESIZE_READONLY(float, _timeDecrement, TimeDecrement);
    CC_SYNTHESIZE(float, _lineEnergy, LineEnergy);
    CC_SYNTHESIZE_READONLY(float, _time, Time);
    
    static GameManager * sharedGameManager();
    
    void commonGameScreen(cocos2d::CCLayer * layer);
    void createGameScreen(GameStage stage, kTag type);
    CCNode * createGameParticle(const char * plistFile, kTag tag);
    CCNode * attackingParticle(const char * plistFile, kTag tag);
    
    void setBestScore(int var);
    
    void starGameCountdown();
    void stopGame();
    
    void reset(void);
    void addScore(int reward);
    void update(float dt);
    
};


#endif /* defined(__SadMemoryonYourWhiteCampus__GameManager__) */
