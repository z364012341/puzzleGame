#include "StageCellRabbit.h"

const std::string RABBIT_ARMATURE_NAME = "tuzizuan";
const cocos2d::Size RABBIT_STENCIL_SIZE(80.0f, 70.0f);
namespace bubble_second {
    StageCellRabbit::StageCellRabbit()
    {
    }

    StageCellRabbit::~StageCellRabbit()
    {
    }

    bool StageCellRabbit::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::LayerColor* stencil = cocos2d::LayerColor::create(cocos2d::Color4B::WHITE, RABBIT_STENCIL_SIZE.width, RABBIT_STENCIL_SIZE.height);
        //stencil->setContentSize(RABBIT_STENCIL_SIZE);
        stencil->setPositionX(RABBIT_STENCIL_SIZE.width/-2);
        cocos2d::ClippingNode* clipping = cocos2d::ClippingNode::create(stencil);
        armature_ = cocostudio::Armature::create(RABBIT_ARMATURE_NAME);
        clipping->addChild(armature_);
        this->addChild(clipping);

        this->playAnimationRandomTime();
        return true;
    }
    void StageCellRabbit::playAnimationRandomTime()
    {
        armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->playAnimationRandomTime();
            }
        });
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(cocos2d::random(0, 5)), cocos2d::CallFunc::create([=]() {
            armature_->getAnimation()->playWithIndex(0);
        })));
    }
}