#include "WindmillBubble.h"
#include "SpriteTextureController.h"
#include "BubbleFactory.h"
#include "GameScene.h"
#include "GameScoreController.h"
#include "GameBubbleMapImple.h"
#include "GameNoopAnimationComponent.h"
const std::string BUBBLE_WINDMILL_ARMATURE_NAME = "laoshu";
const std::string BUBBLE_ANIMATION_NAME_0 = "daiji-zhayan";
const std::string BUBBLE_ANIMATION_NAME_1 = "shouji";
const std::string BUBBLE_ANIMATION_NAME_2 = "wucaozuo";
const std::string BUBBLE_ANIMATION_NAME_3 = "siwang";
const std::string BUBBLE_ANIMATION_NAME_4 = "chuancha-zuoyoukan";
const float ARMATURE_SCALE = 0.9f;
const std::string UI_NAME_WINDMILL_BUBBLE_FLYING_MOTIONSTREAK_PATH = "bubbleMotionStreak.png";
const std::string WINDMILL_BUBBLE_MOTIONSTREAK_SCHEDULE_KEY = "windmill_bubble_motionstreak_schedule_key";
const float WINDMILL_BUBBLE_FLYING_HEAD_POS_Y = 40.0f;
const float WINDMILL_BUBBLE_FLYING_BODY_POS_Y = -40.0f;
const float WINDMILL_BUBBLE_FLYING_INITIAL_SCALE = 0.3f; //初始大小
const float WINDMILL_BUBBLE_FLYING_FINAL_SCALE = 1.3f; //最后大小
const float WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_A = -20.0f; //公式的参数a
const float WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_B = 0.9f;  //改变参数 a相当于旋转螺线线，而参数 b 则控制相邻两条曲线之间的距离
const int WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA = 390;
const int WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_DIRECTION = 1; //方向
const float WINDMILL_BUBBLE_FLYING_ACTION_DURATION = 1.5f;
const float WINDMILL_BUBBLE_FLYING_ACTION_DURATION_2 = 0.375f;
const float WINDMILL_BUBBLE_FLYING_2_MOVE_Y = 450.0f;
const float WINDMILL_BUBBLE_FLYING_ACTION_DURATION_TOTAL = WINDMILL_BUBBLE_FLYING_ACTION_DURATION+ WINDMILL_BUBBLE_FLYING_ACTION_DURATION_2;
namespace bubble_second {
    WindmillBubble::WindmillBubble()
    {
    }

    WindmillBubble::~WindmillBubble()
    {
    }

    void WindmillBubble::onEnter()
    {
        cocos2d::Node::onEnter();
        //cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_CLOCK_RANG, [=](cocos2d::EventCustom* event) {
        //    this->playNoopAnimation();
        //});

        //cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_CLOCK_CLEAR, [=](cocos2d::EventCustom* event) {
        //    this->playStandbyAnimation();
        //});

        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_BUBBLE_ELIMINATED, CC_CALLBACK_1(WindmillBubble::disposedAroundEliminate, this));
    }

    void WindmillBubble::onExit()
    {
        cocos2d::Node::onExit();
        //cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_CLOCK_RANG);
        //cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_CLOCK_CLEAR);
    }
    
    bool WindmillBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleWindmill);
        this->setSupensionPoint(true);
        this->setTag(WINDMILL_BUBBLE_TAG);
        GameScoreController::getInstance()->addGameTaskNumble();
        return true;
    }

    void WindmillBubble::addArmature(cocos2d::Node * ndoe, const cocos2d::Vec2 & point)
    {
        armature_ = cocostudio::Armature::create(BUBBLE_WINDMILL_ARMATURE_NAME);
        armature_->setPosition(point);
        armature_->setScale(ARMATURE_SCALE);
        ndoe->addChild(armature_);
        this->playStandbyAnimation();
        this->addNoopComponent();
    }

    void WindmillBubble::addNoopComponent()
    {
        this->addChild(GameNoopAnimationComponent::create(armature_, BUBBLE_ANIMATION_NAME_2, CC_CALLBACK_0(WindmillBubble::playStandbyAnimation, this)));
    }

    void WindmillBubble::playStandbyAnimation()
    {
        std::vector<std::string> names;
        names.push_back(BUBBLE_ANIMATION_NAME_0);
        names.push_back(BUBBLE_ANIMATION_NAME_0);
        names.push_back(BUBBLE_ANIMATION_NAME_0);
        names.push_back(BUBBLE_ANIMATION_NAME_4);
        armature_->getAnimation()->playWithNames(names);
        armature_->getAnimation()->setMovementEventCallFunc(nullptr);
    }

    //bool WindmillBubble::isNoop()
    //{
    //    return armature_->getAnimation()->getCurrentMovementID() == BUBBLE_ANIMATION_NAME_2;
    //}

    //void WindmillBubble::playNoopAnimation()
    //{
    //    if (this->isNoop())
    //    {
    //        return;
    //    }
    //    armature_->getAnimation()->play(BUBBLE_ANIMATION_NAME_2);
    //}

    void WindmillBubble::playContactAnimation()
    {
        if (armature_->getAnimation()->getCurrentMovementID() == BUBBLE_ANIMATION_NAME_1)
        {
            return;
        }
        armature_->getAnimation()->play(BUBBLE_ANIMATION_NAME_1);
        armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->playStandbyAnimation();
            }
        });
    }

    void WindmillBubble::disposedAroundEliminate(cocos2d::EventCustom * event)
    {
        BubbleVector sprites = *static_cast<BubbleVector*>(event->getUserData());
        BubbleIndexVector indexs = GameBubbleMapImple::getAroundIndexWithIndexWithoutCondition(this->getBubbleIndex());
        for (auto var : sprites)
        {
            if (this->needPlayContactAnimation(var->getBubbleIndex(), indexs))
            {
                this->playContactAnimation();
            }
        }
    }

    bool WindmillBubble::needPlayContactAnimation(const cocos2d::Vec2 & bubble_index, const BubbleIndexVector & around_index)
    {
        for (auto var : around_index)
        {
            if (bubble_index == var)
            {
                return true;
            }
        }
        return false;
    }

    //void WindmillBubble::setBubbleTexture(BubbleType type)
    //{

    //}

    //cocos2d::Node* WindmillBubble::getFlyingTexture()
    //{
    //    cocos2d::Sprite* head = SpriteTextureController::getInstance()->createGameSpriteWithPath(UI_NAME_WINDMILL_BUBBLE_FLYING_HEAD_PATH);
    //    head->setPositionY(WINDMILL_BUBBLE_FLYING_HEAD_POS_Y);
    //    cocos2d::Sprite* body = SpriteTextureController::getInstance()->createGameSpriteWithPath(UI_NAME_WINDMILL_BUBBLE_FLYING_BODY_PATH);
    //    body->setPositionY(WINDMILL_BUBBLE_FLYING_BODY_POS_Y);
    //    cocos2d::Node* node = cocos2d::Node::create();
    //    node->addChild(head,1);
    //    node->addChild(body);
    //    node->setScale(WINDMILL_BUBBLE_FLYING_INITIAL_SCALE);
    //    return node;
    //}

    //cocos2d::Action * WindmillBubble::getFlyingAction()
    //{

    //    cocos2d::RotateBy* rotate = cocos2d::RotateBy::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION, -WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA);
    //    cocos2d::ScaleTo* scale = cocos2d::ScaleTo::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION, WINDMILL_BUBBLE_FLYING_FINAL_SCALE);
    //    cocos2d::Spawn* seq = cocos2d::Spawn::create(this->getArchimedeanSpiralAction(), rotate, scale, nullptr);
    //    return seq;
    //}

    cocos2d::CardinalSplineBy* WindmillBubble::getArchimedeanSpiralAction()
    {
        float begin_theta = 0.0f;
        float a = WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_A;
        float b = WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_B;
        cocos2d::PointArray* point_array = cocos2d::PointArray::create(WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA);
        for (int theta = 0; theta != abs(WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA); ++theta)
        {
            float local_theta = WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_DIRECTION*theta;
            float r = a + b*local_theta;
            cocos2d::Vec2 point = cocos2d::Vec2(r*cos(CC_DEGREES_TO_RADIANS(local_theta + begin_theta)), r*sin(CC_DEGREES_TO_RADIANS(local_theta + begin_theta)));
            point_array->addControlPoint(point - cocos2d::Vec2(WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_A, 0.0f));
        }
        cocos2d::CardinalSplineBy* action = cocos2d::CardinalSplineBy::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION, point_array, 0);
        return action;
    }

    void WindmillBubble::setParent(cocos2d::Node* parent)
    {
        BaseBubble::setParent(parent);
        if (parent)
        {
            this->addArmature(parent->getParent(), dynamic_cast<GameScene*>(parent->getParent()->getParent())->convertMapToCsbSpace(this->getPosition()));
        }
    }

    void WindmillBubble::bubbleEliminate(int)
    {
        GameScoreController::getInstance()->addCompletedTaskNumble();
        //armature_->getAnimation()->play(BUBBLE_ANIMATION_NAME_3);
        //armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
        //    if (movementType == cocostudio::COMPLETE)
        //    {
        //        armature->removeFromParent();
        //        this->removeFromParent();
        //    }
        //});
        //using cocostudio::ArmatureDataManager;
        //using cocostudio::Armature;
        //cocos2d::Node* parent_node = sp_->getParent();
        //Armature *armature = Armature::create(WINDMILL_BUBBLE_DEMON_ARMATURE_NAME);
        //armature->setPosition(sp_->getPosition());
        //armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        //armature->getAnimation()->setMovementEventCallFunc([=](Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
        //    if (movementType == cocostudio::COMPLETE)
        //    {
        //        this->removeFromParent();
        //        armature->removeFromParent();
        //    }
        //});
        //parent_node->addChild(armature);

        cocos2d::MotionStreak* motion = cocos2d::MotionStreak::create(0.7f, 0.1f, 1.0f, cocos2d::Color3B::WHITE, UI_NAME_WINDMILL_BUBBLE_FLYING_MOTIONSTREAK_PATH);
        motion->setPosition(armature_->getPosition());
        armature_->getParent()->addChild(motion, -1);
        //motion->setScale(0.1f);
        cocos2d::BlendFunc bf = { GL_SRC_ALPHA , GL_ONE };
        motion->setBlendFunc(bf);
        //motion->runAction(cocos2d::Sequence::create(this->getArchimedeanSpiralAction(),/*cocos2d::DelayTime::create(2.0f), */cocos2d::CallFunc::create([=]() {
        //    //motion->removeFromParent();

        //    cocos2d::Vec2 point = (armature_->getPosition() + cocos2d::Vec2(0.0f, 250.0f)).rotateByAngle(armature_->getPosition(), CC_DEGREES_TO_RADIANS(-armature_->getRotation()));
        //    motion->runAction(cocos2d::Sequence::create(cocos2d::MoveTo::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION_2, point), cocos2d::DelayTime::create(1.0f), cocos2d::CallFunc::create([=]() {
        //        motion->removeFromParent();
        //        //motion->removeFromParent();
        //    }), nullptr));
        //}), nullptr));
        motion->runAction(this->getArchimedeanSpiralAction());
        motion->schedule([=](float) {
            motion->setStroke(motion->getStroke() + 1.5);
            //motion->setPosition(armature_->getPosition());
        }, WINDMILL_BUBBLE_MOTIONSTREAK_SCHEDULE_KEY);

        armature_->runAction(cocos2d::Sequence::create(this->getArchimedeanSpiralAction(), cocos2d::CallFunc::create([=]() {
            cocos2d::Vec2 point = (armature_->getPosition() + cocos2d::Vec2(0.0f, WINDMILL_BUBBLE_FLYING_2_MOVE_Y)).rotateByAngle(armature_->getPosition(), CC_DEGREES_TO_RADIANS(-armature_->getRotation()));
            armature_->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::MoveTo::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION_2, point), cocos2d::CallFunc::create([=]() {
                armature_->removeFromParent();
                this->removeFromParent();
                //motion->removeFromParent();
            })));
            //motion->stopAllActions();
            motion->runAction(cocos2d::Sequence::create(cocos2d::MoveTo::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION_2, point), cocos2d::DelayTime::create(1.0f), cocos2d::CallFunc::create([=]() {
                motion->removeFromParent();
                //motion->removeFromParent();
            }), nullptr));
        }), nullptr));
        armature_->runAction(cocos2d::Spawn::createWithTwoActions(cocos2d::RotateBy::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION, -WINDMILL_BUBBLE_FLYING_ARCHIMEDEAN_SPIRAL_THETA), 
            cocos2d::ScaleBy::create(WINDMILL_BUBBLE_FLYING_ACTION_DURATION_TOTAL, 2.0f)));


    }
}