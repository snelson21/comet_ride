//
//  PhysicsSprite.h
//  Comet Pride
//
//  Created by Steele Nelson on 2013-06-02.
//
//

#ifndef __Comet_Pride__PhysicsSprite__
#define __Comet_Pride__PhysicsSprite__

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include "Box2D.h"

class PhysicsSprite : public cocos2d::CCSprite
{
public:
    PhysicsSprite();
    void setPhysicsBody(b2Body * body);
    virtual bool isDirty(void);
    virtual cocos2d::CCAffineTransform nodeToParentTransform(void);
private:
    b2Body* m_pBody;    // strong ref
};

#endif /* defined(__Comet_Pride__PhysicsSprite__) */
