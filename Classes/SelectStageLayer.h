//
//  SelectStageLayer.h
//  SadMemoryonYourWhiteCampus
//
//  Created by KubokawaTakeshi on 2014/03/02.
//
//

#ifndef __SadMemoryonYourWhiteCampus__SelectStageLayer__
#define __SadMemoryonYourWhiteCampus__SelectStageLayer__

#include <iostream>
#include "GameManager.h"
#include "GameScene1.h"
#include "GameScene2.h"
#include "GameScene3.h"


struct Stage1
{
    
};

struct Stage2
{
    
};

struct Stage3
{
    
};

class SelectStageLayer : public cocos2d::CCLayer
{
private:
    
    /* Screen Size */
    cocos2d::CCSize _winSize;
    
    /* Singleton */
    GameManager * _manager;
    
    
    CCArray * _selectStageButton;
    
    
    cocos2d::CCLabelBMFont * _bestScore;
    
    CCSprite *bg;
    CCSprite *rock;
    
    int _score;
    
    /** Labels **/
    CCLabelTTF * _title;
    CCLabelTTF * _stage;
    
    /** Button **/
    CCSprite * _btnPlayStage1;
    CCSprite * _btnPlayStage2;
    CCSprite * _btnPlayStage3;
    
    
    
    /*** Select Game Stages ***/
    inline void selectStage(GameStage * stage)
    {
        int i;
        _manager = GameManager::sharedGameManager();
        
        for (i = 1; i < 3; i++) {
            
            
        }
    
        _manager->setGameStage(kGameStage1);
        
    }
    // Stage1 //
    inline void selectStage1(){
        CCScene * pScene = GameScene1::scene();
        CCDirector::sharedDirector()->replaceScene(pScene);
        
    };
    // Stage2 //
    inline void selectStage2(){
    //
        
    };
    // Stage3 //
    inline void selectStage3(){
        
    };
    
    /** Stage1 Show Animation **/
    
    
    
    /** Stage2 Show Animation **/
    
    
    
    /** Stage3 Show Animation **/
    int _starsUpdateIndex;
    int _starsUpdateRange;
    int _starsUpdateInterval;
    int _starsUpdateTimer;
    
    /*** Show Animation ***/
    void showAnimationStageBackground(GameStage * stage);
    
    
    
    /*** Scene ***/
    void createSelectStageSceen(void);
    
    
public:
    SelectStageLayer();
    ~SelectStageLayer();
    
    virtual void ccTouchesBegan(cocos2d::CCSet * touches, cocos2d::CCEvent * event);
    virtual void ccTouchesEnded(cocos2d::CCSet * touches, cocos2d::CCEvent* event);
    
    virtual bool init();
    static CCScene * scene();
    CREATE_FUNC(SelectStageLayer);

};


#endif /* defined(__SadMemoryonYourWhiteCampus__SelectStageLayer__) */
