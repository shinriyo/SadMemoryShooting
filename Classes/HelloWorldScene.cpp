#include "HelloWorldScene.h"

USING_NS_CC;

HelloWorld::HelloWorld()
{
    
}

HelloWorld::~HelloWorld()
{
    CC_SAFE_RELEASE(_backParticle);
    
}

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    
    
    pSprite = GameSprite::gameSpriteWithFileName("RockOn_1.png");
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    background = CCSprite::create("HelloWorld.png");
    background->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(background,0);
    
    float barX;
	float barY;
    float totalWidth = visibleSize.width * 0.8f;
    barX = visibleSize.width * 0.1f;
    barY = visibleSize.height * 0.03f;
    glLineWidth(9.0 * CC_CONTENT_SCALE_FACTOR());
    ccDrawColor4F(0.0, 0.0, 0.0, 1.0);
    ccDrawLine(ccp(barX, barY), ccp(barX + totalWidth, barY));
    
    _backParticle = CCParticleFlower::create();
    //_backParticle->setTexture(CCTextureCache::sharedTextureCache()->textureForKey("fire.png"));
    _backParticle->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
    _backParticle->setLife(10);
    _backParticle->setStartSpin(180);
    _backParticle->setDuration(-1);
    _backParticle->autorelease();
    
    pSprite->addChild(_backParticle);
    
    
    


    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    
    this->baseLayer = CCLayer::create();
    this->addChild(baseLayer, 0);
    
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
  //  CCSprite* pSprite = CCSprite::create("RockOn_1.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    baseLayer->addChild(pSprite, 0);
    
    float x, y, z;
    pCamera = background->getCamera();
    pCamera->getCenterXYZ(&x, &y, &z);
    //pCamera->getEyeXYZ(&x, &y, &z);
    pCamera->setCenterXYZ(x, y+0.0000001, z);
    
    
    this->setTouchEnabled(true);
    
    this->schedule(schedule_selector(HelloWorld::update));
    
    return true;
}


void HelloWorld::ccTouchesBegan(CCSet * pTouches, CCEvent* event) {
    
    CCSetIterator i;
    CCTouch * touch;
    CCPoint tap;
    

    
    CCLog("touch");
    
    // loop through beginning touches
    for (i = pTouches->begin(); i != pTouches->end(); i++)
    {
        CCLog("you");
        touch = (CCTouch *)(*i);
        
        if (touch) {
            tap = touch->getLocation();
            touchStartPoint = touch->getLocation();
            CCLog("%f", tap.x);
            CCLog("%f, %f", touchStartPoint.x,touchStartPoint.y);
            
            if (pSprite->boundingBox().containsPoint(tap)) {
                pSprite->setTouch(touch);
                CCLog("touch!!");
            }
        }
        
    }
    
}

void HelloWorld::ccTouchesMoved(CCSet * pTouches, CCEvent * event) {
    
    CCSetIterator i;
    CCTouch * touch;
    CCPoint tap;
    
    for (i = pTouches->begin(); i != pTouches->end(); i++)
    {
     //   CCLog("you2");
        touch = (CCTouch *)(*i);
        
        if (touch) {
            tap = touch->getLocation();
            
            if (pSprite->getTouch() != NULL && pSprite->getTouch()) {
                CCPoint nextPosition = tap;
                
           //     pSprite->setNextPosition(nextPosition);
           //     pSprite->setVector(ccp(tap.x - pSprite->getPositionX(), tap.y - pSprite->getPositionY()));
            }
            
            
            
            
        }
        
        
    }
    
}

void HelloWorld::ccTouchesEnded(CCSet * pTouches, CCEvent * event) {
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSetIterator i;
    CCTouch * touch;
    CCPoint tap;
    CCPoint touchEndPoint;
    CCAction * action = NULL;
    
    // loop through all ending touches
    for (i = pTouches->begin(); i != pTouches->end(); i++)
    {
        touch = (CCTouch *)(*i);
        
        if (touch) {
            tap = touch->getLocation();
            touchEndPoint = touch->getLocation();
            CCLog("%f, %f", touchEndPoint.x, touchEndPoint.y);
            
            if (pSprite->getTouch() != NULL && pSprite->getTouch() == touch)
            {
                CCPoint nextPosition = tap;
                
                //keep player inside screen
                if (nextPosition.x < pSprite->radius())
                    nextPosition.x = pSprite->radius();
                if (nextPosition.x > winSize.width - pSprite->radius())
                    nextPosition.x = winSize.width - pSprite->radius();
                if (nextPosition.y < pSprite->radius())
                    nextPosition.y  = pSprite->radius();
                if (nextPosition.y > winSize.height - pSprite->radius())
                    nextPosition.y = winSize.height - pSprite->radius();
                
                pSprite->setNextPosition(nextPosition);
             //   pSprite->setVector(ccp(tap.x - pSprite->getPositionX(), tap.y - pSprite->getPositionY()));
                
            }
           // pSprite->setNextPosition(nextPosition);
            pSprite->setVector(ccp(tap.x - pSprite->getPositionX(), tap.y - pSprite->getPositionY()));
        }
        
        double angle;
        double angle2;
        double angle3;
        float dx;
        float dy;
        float diffx;
        float diffy;
        bool isXlessThanZero = false;
        bool isYlessThanZero = false;
        CCPoint pSpriteNextPosition = pSprite->getNextPosition();
        CCPoint pSpriteVector = pSprite->getVector();
    
        
        if (touchEndPoint.x - touchStartPoint.x < 0) {
            diffx = -(touchEndPoint.x - touchStartPoint.x);
            dx = - (pSpriteNextPosition.x - pSprite->getPositionX());
            CCLog("ss_x :%f", diffx);
            isXlessThanZero = true;
        }
        else
        {
            diffx = touchEndPoint.x - touchStartPoint.x;
            dx = pSpriteNextPosition.x - pSprite->getPositionX();
            CCLog("ss_x :%f", diffx);
        }
        if(touchEndPoint.y - touchStartPoint.y < 0)
        {
            diffy = -(touchEndPoint.y - touchStartPoint.y);
            dy = -(pSpriteNextPosition.y - pSprite->getPositionY());
            CCLog("ss_y :%f", diffy);
            isYlessThanZero = true;
        }
        else
        {
            diffy = touchEndPoint.y - touchStartPoint.y;
            dy = pSpriteNextPosition.y - pSprite->getPositionY();
            CCLog("ss_y :%f", diffy);
        }
        CCPoint p = ccp(diffy, diffx);
        
        angle = atan2(diffy, diffx);
        CCLog("angle : %f",angle);
        
        angle2 = atan(p.y / p.x) * 180 / M_PI;
        CCLog("angle2 : %f", angle2);
        
        /* fix angle */
        if (isXlessThanZero && isYlessThanZero) angle2 += 180.0f;
        else if (isXlessThanZero)               angle2 = 180.0f - angle2;
        else if (isYlessThanZero)               angle2 = 360.0f - angle2;
        
        CCLog("angle2_2 : %f", angle2);
        CCPoint y= ccp(dx, dy);
        
        
        /**** Flick ****/
        if (angle2 >= 335 || angle2 < 20) {
            action = CCMoveTo::create(0.1f,p );
            pSprite->runAction(action);
            
            
            
            
        } else if (angle2 >= 20 && angle2 < 65) {
            
            action = CCMoveTo::create(0.1f,p );
            pSprite->runAction(action);
            
            
        } else if (angle2 >= 65 && angle2 < 110) {
            
            action = CCMoveTo::create(0.1f,p );
            pSprite->runAction(action);
            
            
        } else if (angle2 >= 65 && angle2 < 110) {
            
            action = CCMoveTo::create(0.1f,p );
            pSprite->runAction(action);
            
        } else if (angle2 >= 110 && angle2 < 155) {
            
            action = CCMoveTo::create(0.1f,p );
            pSprite->runAction(action);
        } else if (angle2 >= 155 && angle2 < 200) {
            action = CCMoveBy::create(0.1f,p );
            pSprite->runAction(action);
            
        } else if (angle2 >= 200 && angle2 < 245) {
            action = CCMoveTo::create(0.1f,p );
            pSprite->runAction(action);
            
        } else if (angle2 >= 245 && angle2 < 290) {
            action = CCMoveTo::create(0.1f,p );
            pSprite->runAction(action);
            
        } else if (angle2 >= 290 && angle2 < 335) {
            action = CCMoveTo::create(0.1f,p );
            pSprite->runAction(action);
        }
        
        
        
//        CCPoint pSpriteNextPosition = pSprite->getNextPosition();
//        CCPoint pSpriteVector = pSprite->getVector();
        
        pSpriteNextPosition.x += pSpriteVector.x;
        pSpriteNextPosition.y += pSpriteVector.y;
        
        diffx = pSpriteNextPosition.x - pSprite->getPositionX();
        diffy = pSpriteNextPosition.y - pSprite->getPositionY();
        float d     = sqrtf(pow(diffy,2) + pow(diffx, 2));
        CCLog("ssssss: %f,%f",pSprite->getPositionX(), pSprite->getPositionY());
        CCLog("next-position-> %f, %f",pSpriteNextPosition.x, pSpriteNextPosition.y);
        CCLog("why->x:%f, y:%f",diffx, diffy);
        
        CCLog("d: %f",d);
        CCLog("angle6 : %f", angle2);
        float angle6 = atan2(diffy, diffx) * 180 * M_PI;
        /* fix angle */
        if (isXlessThanZero && isYlessThanZero) angle6 += 180.0f;
        else if (isXlessThanZero)               angle6 = 180.0f - angle6;
        else if (isYlessThanZero)               angle6 = 360.0f - angle6;
        
        CCLog("angle6_2 : %f", angle6);
        pSprite->setPosition(pSprite->getNextPosition());
        
       // pSprite->setVector(pSpriteVector);
       // pSprite->setNextPosition(pSpriteNextPosition);

        
        
        
        angle3 = atan2(diffy, diffx);
        CCLog("angle3 : %f", angle3);
        
        pSpriteVector.x = cos(angle3);
        pSpriteVector.y = sin(angle3);
        CCLog("this is -> %f, %f", pSpriteVector.x, pSpriteVector.y);
        
        pSpriteNextPosition.x = pSpriteNextPosition.x * 0.6 * pSpriteVector.x;
        pSpriteNextPosition.y = pSpriteNextPosition.y * 0.6 * pSpriteVector.y;
        
        CCLog("yooooo-> %f, %f", pSpriteNextPosition.x, pSpriteNextPosition.y);
        
        float angle4 = atan2(diffy, diffx);
        CCLog("angle4: %f", angle4);
        angle4 = atan2(diffy, diffx) * 180;
        CCLog("angle4 angle: %f", angle4);
        
        
//        pSprite->setVector(pSpriteVector);
//        pSprite->setNextPosition(pSpriteNextPosition);
        
    //    action = CCMoveTo::create(0.1f,pSpriteNextPosition);
   //     action = CCMoveBy::create(0.1f, pSpriteNextPosition);
//        pSprite->runAction(action);
        
    
        
    }
    
    
}


void HelloWorld::update(float dt)
{
    CCPoint playerNextPosition;
    CCPoint playerVector;
    
    playerNextPosition = pSprite->getNextPosition();
    playerVector = pSprite->getVector();
    
    playerNextPosition.x += playerVector.x;
    playerNextPosition.y += playerVector.y;
    
    
    
    float diffx = playerNextPosition.x - pSprite->getPositionX();
    float diffy = playerNextPosition.y - pSprite->getPositionY();
    
    float angle = atan2(diffy, diffx);
    
    playerVector.x = cos(angle);
    playerVector.y = sin(angle);
    
  //  CCLog("angle->update() : %f", angle);
    
    playerNextPosition.x = playerNextPosition.x * cos(angle);
    playerNextPosition.y = playerNextPosition.y * sin(angle);
    
    pSprite->setPosition(pSprite->getNextPosition());
    
    
    
    
    
    float x, y, z;
    CCCamera * pCamera = background->getCamera();
    pCamera->getCenterXYZ(&x, &y, &z);
    //pCamera->getEyeXYZ(&x, &y, &z);
    pCamera->setCenterXYZ(x, y+0.0000000005, z+0.0000000005);
    
//    
//    CCSize size = CCDirector::sharedDirector()->getWinSize();
//    CCRect rect = CCRectMake(0, 0, size.width, size.height);
//    this->runAction(CCFollow::create(pSprite, rect));
    
//    CCSequence::create(CCMoveTo::create(1.0f, ccp(480*2, 320*2)),
//                       CCMoveTo::create(1.0f, CCPointZero),
//                       NULL);
//    CCRect rect;
//    rect.origin = CCPointZero;
//    rect.size = CCSizeMake(480*2, 320*2);
//    runAction(CCFollow::create(pSprite, rect));
    
    
    
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
