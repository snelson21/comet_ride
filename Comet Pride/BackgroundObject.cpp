//
//  BackgroundObject.cpp
//  Comet Pride
//
//  Created by Steele Nelson on 2013-06-02.
//
//

#include "BackgroundObject.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

BackgroundObject *BackgroundObject::createFromFile(const char *filename, cocos2d::CCPoint position, float speed)
{
    CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(filename);
    if(texture)
    {
        BackgroundObject *backgroundObject = new BackgroundObject();
        if(backgroundObject && backgroundObject->initWithTexture(texture, position, speed))
        {
            backgroundObject->autorelease();
            return backgroundObject;
        }
        CC_SAFE_DELETE(backgroundObject);
    }
    return NULL;
}

bool BackgroundObject::initWithTexture(cocos2d::CCTexture2D *texture, cocos2d::CCPoint position, float speed)
{
    _deviceSize = CCDirector::sharedDirector()->getWinSizeInPixels();
    _texture = texture;
    _texture->setAliasTexParameters();
    _position = position;
    _speed = speed;
    schedule(schedule_selector(BackgroundObject::step));
    return true;
}

void BackgroundObject::step(cocos2d::CCTime deltaTime)
{
    _position = ccp(_position.x - _speed, _position.y);
    if(_position.x <= -_texture->getContentSizeInPixels().width)
    {
        _position = ccp(_deviceSize.width, _position.y);
    }
}

void BackgroundObject::draw()
{
    _texture->drawAtPoint(_position);
    if(_position.x > 0)
    {
        _texture->drawAtPoint(ccp(_position.x-_deviceSize.width, _position.y));
    }
    if(_position.x < 0)
    {
        _texture->drawAtPoint(ccp(_position.x+_deviceSize.width, _position.y));
    }
    CCNode::draw();
}