//
//  SpaceScene.h
//  Comet Pride
//
//  Created by Steele Nelson on 2013-06-02.
//
//

#ifndef __Comet_Pride__SpaceScene__
#define __Comet_Pride__SpaceScene__

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include "Box2D.h"


class Space : public cocos2d::CCLayer {
public:
    ~Space();
    Space();
    
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    
    void initPhysics();
    
    void initStars();
    
    void update(float dt);
    
private:
    b2World* world;
    cocos2d::CCTexture2D* m_pSpriteTexture; // weak ref
    float timeAccumulator;
};

#endif /* defined(__Comet_Pride__SpaceScene__) */
