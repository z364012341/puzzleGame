#include "BombPropertyBubble.h"

const std::string TWO_ROUND_BOMB_EFFECT_NAME = "zhadanTX"; //炸2圈特效的名字
const std::string BOMB_BUBBLE_STANDBY_NAME = "ranshao";
const std::string BOMB_BUBBLE_BOMB_BOMB_NAME = "baozhaTX";
namespace bubble_second {
    BombPropertyBubble::BombPropertyBubble()
    {
    }

    BombPropertyBubble::~BombPropertyBubble()
    {
    }

    void BombPropertyBubble::dispatchEventAfterShooted()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_HAVE_USED_PROPS, this);
    }

    void BombPropertyBubble::bubbleEliminate(int)
    {
        this->removeFromParent();
    }

    bool BombPropertyBubble::init()
    {
        if (!ColorBubble::initWithTypeAndCloud(kBubbleBombBombProperty))
        {
            return false;
        }
        this->setName(COLOR_BOMB_BUBBLE_NAME);
        this->addBubblePrepareBody();
        return true;
    }

    float BombPropertyBubble::playTheSpecialEffects()
    {
        auto parent_node = this->getParent();
        if (!parent_node)
        {
            return 0.0;
        }
        //using cocostudio::ArmatureDataManager;
        //using cocostudio::Armature;
        //Armature *armature = Armature::create(TWO_ROUND_BOMB_EFFECT_NAME);
        //armature->setPosition(this->getPosition());
        //armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        //armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
        //    if (movementType == cocostudio::COMPLETE)
        //    {
        //        armature->removeFromParent();
        //    }
        //});
        //parent_node->addChild(armature);
        armature_->getAnimation()->play(BOMB_BUBBLE_BOMB_BOMB_NAME);
        armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                armature->removeFromParent();
            }
        });

        //cocos2d::NodeGrid* node = cocos2d::NodeGrid::create();
        //cocos2d::Node* game_layer = parent_node->getParent();
        //game_layer->addChild(node, parent_node->getLocalZOrder());
        //node->setTarget(parent_node);
        //auto point = this->getPosition()*parent_node->getScale() + parent_node->getPosition(); //坐标转换
        //auto action = cocos2d::Ripple3D::create(TWO_ROUND_BOMB_EFFECT_RIPPLE2D_DURATION, ACTION_3DGRID, point, 
        //    TWO_ROUND_BOMB_EFFECT_RIPPLE2D_RADIUS, TWO_ROUND_BOMB_EFFECT_RIPPLE2D_WAVES, TWO_ROUND_BOMB_EFFECT_RIPPLE2D_AMPLITUDE);
        //auto action1 = cocos2d::Ripple3D::create(0, ACTION_3DGRID, point, 0, 0, 0);
        //cocos2d::Sequence* seq = cocos2d::Sequence::create(action, action1, cocos2d::CallFunc::create([=]() {node->removeFromParent(); }), nullptr);
        //node->runAction(seq);
        return TWO_ROUND_BOMB_EFFECT_DELAY_TIME;
    }
    void BombPropertyBubble::downFromAir()
    {
        this->bubbleEliminate();
    }
    void BombPropertyBubble::setBubbleTexture(BubbleType)
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        armature_ = Armature::create(TWO_ROUND_BOMB_EFFECT_NAME);
        armature_->getAnimation()->play(BOMB_BUBBLE_STANDBY_NAME);
        this->addChild(armature_, 1);
    }
}
