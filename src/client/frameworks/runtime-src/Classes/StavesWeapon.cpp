#include "StavesWeapon.h"
#include "SpriteTextureController.h"
#include "GamePlayController.h"
#include "ColorBubble.h"
const std::string WOODEN_HAMMER_ANIMATION_NAME = "fazhang";
namespace bubble_second {
    StavesWeapon::StavesWeapon()
    {
    }

    bool bubble_second::StavesWeapon::init()
    {
        if (!BaseWeapon::init(WOODEN_HAMMER_ANIMATION_NAME))
        {
            return false;
        }
        //SpriteTextureController::getInstance()->setSpriteTexture(PROPS_STAVES_PATH, this);
        this->setName(WEAPON_STAVES_NAME);
        return true;
    }


    StavesWeapon::~StavesWeapon()
    {
    }

    void StavesWeapon::onEnter()
    {
        BaseWeapon::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_STAVES_SELECT_BUBBLE, [=](cocos2d::EventCustom* event) {
            BubbleVector bubbles = *static_cast<BubbleVector*>(event->getUserData());
            for (auto var : bubbles)
            {
                dynamic_cast<ColorBubble*>(var)->bubbleFlash();
            }
        });
    }

    void StavesWeapon::onExit()
    {
        BaseWeapon::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_STAVES_SELECT_BUBBLE);
    }

    void bubble_second::StavesWeapon::attackBubble()
    {
        BaseWeapon::attackBubble();
        GamePlayController::getInstance()->disposeUseStaves();
    }

    bool StavesWeapon::inAttackRange(BubbleType color)
    {
        return color>=kNormalColorFirst && color <=kNormalColorLast;
    }

    void StavesWeapon::selectBubble(const cocos2d::Vec2 & point)
    {
        BaseWeapon::selectBubble(point);
        GamePlayController::getInstance()->disposeSelectSameBubbles();
    }
}