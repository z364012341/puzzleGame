#include "NullBubble.h"


namespace bubble_second {
    NullBubble::NullBubble()
    {
    }


    NullBubble::~NullBubble()
    {
    }
    void NullBubble::bubbleEliminate(int combo)
    {
        return;
    }
    void NullBubble::downFromAir()
    {
    }
    bool NullBubble::needRemoveFromBubbleMap()
    {
        return false;
    }
    void NullBubble::addBubbleStaticBody()
    {
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(ADD_PHYSICASBODY_DELAYTIME), cocos2d::CallFunc::create([=]()
        {
            cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(MAP_BUBBLE_RADIUS,
                cocos2d::PhysicsMaterial(BUBBLE_BODY_DENSITY,
                    BUBBLE_STATIC_BODY_RESTITUTION, BUBBLE_BODY_FRICTION));
            body->setDynamic(false);
            body->setGravityEnable(false);
            body->setMass(BUBBLE_BODY_MASS);
            body->setCategoryBitmask(BITMASK_BUBBLE_STATIC_CATEGORY);
            body->setCollisionBitmask(BITMASK_BUBBLE_STATIC_COLLISION);
            body->setContactTestBitmask(BITMASK_BUBBLE_STATIC_CONTACTTEST);
            this->setPhysicsBody(body);
        }), NULL));
    }
    bool NullBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleTransparent);
        this->setSupensionPoint(true);
        return true;
    }
}