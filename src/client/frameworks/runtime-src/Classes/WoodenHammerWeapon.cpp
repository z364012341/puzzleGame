#include "WoodenHammerWeapon.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"
const std::string WOODEN_HAMMER_ANIMATION_NAME = "chuizi";
const std::string WOODEN_HAMMER_ATTACK_ANIMATION_NAME = "shiyong";
namespace bubble_second {
    WoodenHammerWeapon::WoodenHammerWeapon()
    {
    }

    WoodenHammerWeapon::~WoodenHammerWeapon()
    {
    }

    void WoodenHammerWeapon::attackBubble()
    {
        GamePlayController::getInstance()->setBubbleShootEnabled(false);
        this->getWeaponArmature()->getAnimation()->stop();
        this->getWeaponArmature()->getAnimation()->play(WOODEN_HAMMER_ATTACK_ANIMATION_NAME);
        this->getWeaponArmature()->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                BaseWeapon::attackBubble();

                GamePlayController::getInstance()->setBubbleShootEnabled(true);
            }
        });
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.625f), cocos2d::CallFunc::create([=]() {
            GamePlayController::getInstance()->disposeUseWoodenHammer();
        })));
    }

    bool WoodenHammerWeapon::init()
    {
        if (!BaseWeapon::init(WOODEN_HAMMER_ANIMATION_NAME))
        {
            return false;
        }
        //SpriteTextureController::getInstance()->setSpriteTexture(PROPS_WOODEN_HAMMER_PATH, this);
        this->setName(WEAPON_WOODEN_HAMMER_NAME);
        return true;
    }
}