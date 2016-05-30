#include "GameNoneBubbleDownAnimationComponent.h"
#include "BubbleSecondConstant.h"
#include "BaseBubble.h"
namespace bubble_second {
    GameNoneBubbleDownAnimationComponent * GameNoneBubbleDownAnimationComponent::createRandomPlayAnimation(cocostudio::Armature * armature, const std::vector<std::string>& animation_names, const std::function<void()>& animation_end_func)
    {
        GameNoneBubbleDownAnimationComponent *pRet = new(std::nothrow) GameNoneBubbleDownAnimationComponent();
        if (pRet && pRet->initRandomPlayAnimation(armature, animation_names, animation_end_func))
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
    GameNoneBubbleDownAnimationComponent::GameNoneBubbleDownAnimationComponent()
    {
    }


    GameNoneBubbleDownAnimationComponent::~GameNoneBubbleDownAnimationComponent()
    {
    }

    void GameNoneBubbleDownAnimationComponent::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_BUBBLE_AIR, [=](cocos2d::EventCustom* event) {
            auto sprites = *static_cast<BubbleVector*>(event->getUserData());
            if (sprites.empty())
            {
                this->playRandomAnimation();
            }
        });
        dispatcher->addEventListenerWithFixedPriority(listener_, 1);
    }

    void GameNoneBubbleDownAnimationComponent::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
    }
    bool GameNoneBubbleDownAnimationComponent::initRandomPlayAnimation(cocostudio::Armature * armature, const std::vector<std::string> &names, const std::function<void()>& animation_end_func)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        armature_ = armature;
        animation_names_ = names;
        animation_end_func_ = animation_end_func;
        return true;
    }

    void GameNoneBubbleDownAnimationComponent::playRandomAnimation()
    {
        assert(!animation_names_.empty());
        int index = cocos2d::random(0, (int)animation_names_.size() - 1);
        armature_->getAnimation()->play(animation_names_[index], SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                if (animation_end_func_ != nullptr)
                {
                    animation_end_func_();
                }
            }
        });
    }
}