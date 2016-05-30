#include "GameNoopAnimationComponent.h"
#include "BubbleSecondConstant.h"

namespace bubble_second {
    GameNoopAnimationComponent::GameNoopAnimationComponent()
    {
    }

    bool GameNoopAnimationComponent::init(cocostudio::Armature * armature, const std::string& noop_name, std::function<void()> clear_func)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        armature_ = armature;
        animation_name_ = noop_name;
        clear_func_ = clear_func;
        return true;
    }


    GameNoopAnimationComponent * GameNoopAnimationComponent::create(cocostudio::Armature * armature, const std::string & noop_name, std::function<void()> clear_func)
    {
        GameNoopAnimationComponent *pRet = new(std::nothrow) GameNoopAnimationComponent();
            if (pRet && pRet->init(armature, noop_name, clear_func))
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

    GameNoopAnimationComponent::~GameNoopAnimationComponent()
    {
    }


    void GameNoopAnimationComponent::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_CLOCK_RANG, [=](cocos2d::EventCustom* event) {
            this->playNoopAnimation();
            noop_state_ = true;
        });

        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_CLOCK_CLEAR, [=](cocos2d::EventCustom* event) {
            if (noop_state_ && clear_func_)
            {
                clear_func_();
                noop_state_ = false;
            }
        });
    }

    void GameNoopAnimationComponent::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_CLOCK_RANG);
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_CLOCK_CLEAR);
    }

    bool GameNoopAnimationComponent::isNoop()
    {
        return armature_->getAnimation()->getCurrentMovementID() == animation_name_;
    }

    void GameNoopAnimationComponent::playNoopAnimation()
    {
        if (this->isNoop())
        {
            return;
        }
        armature_->getAnimation()->play(animation_name_);
    }
}