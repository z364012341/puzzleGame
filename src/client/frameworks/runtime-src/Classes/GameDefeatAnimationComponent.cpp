#include "GameDefeatAnimationComponent.h"
#include "BubbleSecondConstant.h"

namespace bubble_second {
    GameDefeatAnimationComponent::GameDefeatAnimationComponent()
    {
    }

    bool GameDefeatAnimationComponent::init(cocostudio::Armature * armature, const std::string& noop_name)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        armature_ = armature;
        animation_name_ = noop_name;
        return true;
    }


    GameDefeatAnimationComponent * GameDefeatAnimationComponent::create(cocostudio::Armature * armature, const std::string & noop_name)
    {
        GameDefeatAnimationComponent *pRet = new(std::nothrow) GameDefeatAnimationComponent();
        if (pRet && pRet->init(armature, noop_name))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = nullptr;
            return nullptr;
        }
    }

    GameDefeatAnimationComponent::~GameDefeatAnimationComponent()
    {
    }


    void GameDefeatAnimationComponent::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_GAME_DEFEAT, [=](cocos2d::EventCustom* event) {
            this->playDefeatAnimation();
        });
        dispatcher->addEventListenerWithFixedPriority(listener_, 1);
    }

    void GameDefeatAnimationComponent::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
    }

    void GameDefeatAnimationComponent::playDefeatAnimation()
    {
        if (armature_->getAnimation()->getCurrentMovementID() != animation_name_)
        {
            armature_->getAnimation()->play(animation_name_, SPECIAL_BUBBLE_EFFECT_DURATION, true);
            armature_->getAnimation()->setMovementEventCallFunc(nullptr);
        }
    }
}
