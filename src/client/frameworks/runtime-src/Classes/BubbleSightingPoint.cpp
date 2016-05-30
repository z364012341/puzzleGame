#include "BubbleSightingPoint.h"
#include "BubbleSecondConstant.h"
#include "SpriteTextureController.h"
#include "BubbleSightingDevice.h"
//const float SIGHTING_POINT_BODY_RADIUS = BUBBLE_RADIUS * 2-4;  //¸ÕÌå°ë¾¶
namespace bubble_second {
    void BubbleSightingPoint::pointStop()
    {
        this->getPhysicsBody()->removeFromWorld();
        this->stopAllActions();
    }
    BubbleSightingPoint::BubbleSightingPoint()
    {
    }


    BubbleSightingPoint::~BubbleSightingPoint()
    {
    }

    bool BubbleSightingPoint::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        //SpriteTextureController::getInstance()->setSpriteTexture(BUBBLE_SIGHTING_POINT_PATH, this);
        sprite_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(BUBBLE_SIGHTING_POINT_PATH);
        this->addChild(sprite_);
        this->setName(NAME_BUBBLE_SIGHTING_POINT);
        return true;
    }

    void BubbleSightingPoint::addPhysicsBodyCanntWorld()
    {
        cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createBox(cocos2d::Size(BUBBLE_BODY_DIAMETER, BUBBLE_BODY_DIAMETER),
            cocos2d::PhysicsMaterial(PHYSICS_SIGHTING_POINT_BODY_DENSITY, PHYSICS_SIGHTING_POINT_BODY_RESTITUTION, PHYSICS_SIGHTING_POINT_BODY_FRICTION));
        body->setDynamic(true);

        body->setCategoryBitmask(BITMASK_SIGHTING_POINT_CATEGORY);
        body->setCollisionBitmask(0);
        body->setContactTestBitmask(BITMASK_SIGHTING_POINT_CONTACTTEST);
        body->setGravityEnable(false);
        body->setGroup(BUBBLE_BODY_GROUP);
        this->setPhysicsBody(body);
    }

    void BubbleSightingPoint::setPointEnabled(bool flag)
    {
        this->setVisible(flag);
    }

    void BubbleSightingPoint::addContactCount()
    {
        ++contact_count_;
    }

    void BubbleSightingPoint::cutContactCount()
    {
        if (contact_count_ != 0)
        {
            --contact_count_;
        }
    }
    void BubbleSightingPoint::clearContactCount()
    {
        contact_count_ = 0;
        this->setPointEnabled(true);
    }
    bool BubbleSightingPoint::isContacting()
    {
        if (0 != contact_count_)
        {
            return true;
        }
        return false;
    }

    void BubbleSightingPoint::changeSelfColor(BubbleType color)
    {
        auto controller = SpriteTextureController::getInstance();
        switch (color)
        {   
        case kBubbleYellow:
            controller->setSpriteTexture(SIGHT_POINT_YELLOW_PATH, sprite_);
            break;
        case kBubblePurple:
            controller->setSpriteTexture(SIGHT_POINT_PURPLE_PATH, sprite_);
            break;
        case kBubbleBlue:
            controller->setSpriteTexture(SIGHT_POINT_BLUE_PATH, sprite_);
            break;
        case kBubbleRed:
            controller->setSpriteTexture(SIGHT_POINT_RED_PATH, sprite_);
            break;
        case kBubbleGreen:
            controller->setSpriteTexture(SIGHT_POINT_GREEN_PATH, sprite_);
            break;
        case kBubbleOrange:
            controller->setSpriteTexture(SIGHT_POINT_ORANGE_PATH, sprite_);
            break;
        case kBubblePink:
            controller->setSpriteTexture(SIGHT_POINT_PINK_PATH, sprite_);
            break;
        case kBubbleBombBombProperty:
            controller->setSpriteTexture(BUBBLE_SIGHTING_POINT_PATH, sprite_);
            break;
        case kBubbleColorBomb:
            controller->setSpriteTexture(SIGHT_POINT_COLORFUL_PATH, sprite_);
            break;
        default:
            assert(false);
            break;
        }
    }

}