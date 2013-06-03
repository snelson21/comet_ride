//
//  SpaceScene.cpp
//  Comet Pride
//
//  Created by Steele Nelson on 2013-06-02.
//
//

#include "SpaceScene.h"
#include "SimpleAudioEngine.h"
#include "BackgroundObject.h"

using namespace cocos2d;
using namespace CocosDenshion;

Space::Space()
{
    timeAccumulator = 0;
    setTouchEnabled( true );
    
    // init physics
    this->initPhysics();
    this->initStars();
    
    schedule(schedule_selector(Space::update), 1.0/60.0);
}

Space::~Space()
{
    delete world;
    world = NULL;
}

void Space::initStars()
{
    addChild(BackgroundObject::createFromFile("stars.jpg", ccp(0.0,0.0), 0.5));
}

void Space::initPhysics()
{
    b2Vec2 gravity;
    gravity.Set(0.0, 0.0);
    world = new b2World(gravity);
    world->SetAllowSleeping(true);
    world->SetContinuousPhysics(true);
}

void Space::update(float dt)
{
    int velocityIterations = 8;
    int positionIterations = 1;
    
    float fixedTimestamp = 1.0/60.0;
    float timeToRun = dt + timeAccumulator;
    while(timeToRun >= fixedTimestamp)
    {
        world->Step(fixedTimestamp, velocityIterations, positionIterations);
        timeToRun = timeToRun - fixedTimestamp;
    }
    timeAccumulator = timeToRun;
    
    
}

CCScene* Space::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new Space();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}
