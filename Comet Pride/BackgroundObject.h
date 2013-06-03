//
//  BackgroundObject.h
//  Comet Pride
//
//  Created by Steele Nelson on 2013-06-02.
//
//

#ifndef __Comet_Pride__BackgroundObject__
#define __Comet_Pride__BackgroundObject__

#include "cocos2d.h"
#include "Box2D.h"

class BackgroundObject : public cocos2d::CCNode
{
public:
    static BackgroundObject *createFromFile(const char *filename, cocos2d::CCPoint position, float speed);
    
    bool initWithTexture(cocos2d::CCTexture2D *texture, cocos2d::CCPoint position, float speed);
    
    void step(cocos2d::CCTime deltaTime);
    
    void draw();
    
private:
    cocos2d::CCTexture2D *_texture;
    cocos2d::CCPoint _position;
    float _speed;
    cocos2d::CCSize _deviceSize;
};

#endif /* defined(__Comet_Pride__BackgroundObject__) */
