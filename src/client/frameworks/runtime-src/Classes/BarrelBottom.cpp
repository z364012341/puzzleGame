#include "BarrelBottom.h"
#include "BubbleSecondConstant.h"
#include "SmartScaleController.h"
#include "cocos2d.h"
#include "GameScoreController.h"
#include "PopScoreLabelComponent.h"
const std::string BARREL_SCORE_LABEL_FNT_PATH = "fonts/tongshuzi-export.fnt";
const float POP_SCORE_LABEL_POS_Y = 85.0f;
const std::string BARREL_PARTICLE_BLUE = "particle/guanzipenjiantexiao2.plist";
const std::string BARREL_PARTICLE_YELLOW = "particle/guanzipenjiantexiao3.plist";
const std::string BARREL_PARTICLE_PURPLE = "particle/guanzipenjiantexiao4.plist";
namespace bubble_second {
    BarrelBottom::BarrelBottom()
    {
    }

    BarrelBottom::~BarrelBottom()
    {
    }

    void BarrelBottom::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(UI_NAME_BIG_COMBO_ELIMINATE, [=](cocos2d::EventCustom*) {
            score_ = double_score_;
            standby_effect_delaytime_max_ = BARREL_BOTTOM_STANDBY_BIG_EFFECT_DELAYTIME_MAX;
        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_CUT_ELIMINATE_COMBO, [=](cocos2d::EventCustom*) {
            score_ = initial_score_;
            this->initialStacdbyEffectTime();
        });
    }

    //void BarrelBottom::onExit()
    //{
    //    cocos2d::Node::onExit();
    //    cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(UI_NAME_BIG_COMBO_ELIMINATE);
    //    cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_CUT_ELIMINATE_COMBO);
    //}

    bool BarrelBottom::initScoreWithName(const std::string& name)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        effect_flag_ = true;
        this->initialStacdbyEffectTime();
        this->setName(BARREL_BOTTOM_NAME);
        this->initScore(name);
        this->initPopLabelComponent();
        this->initPhysicsBody();
        //this->playStandbyEffect();
        //cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(UI_NAME_BIG_COMBO_ELIMINATE, [=](cocos2d::EventCustom*) {
        //    dynamic_cast<cocostudio::Armature*>(this->getChildByName(BARREL_BOTTOM_STANDBY_EFFECT_NAME))->getAnimation()->setSpeedScale(BARREL_BOTTOM_STANDBY_EFFECT_SPEED_SCALE);
        //    standby_effect_delaytime_max_ = BARREL_BOTTOM_STANDBY_BIG_EFFECT_DELAYTIME_MAX;
        //});
        //cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_CUT_ELIMINATE_COMBO, [=](cocos2d::EventCustom*) {
        //    dynamic_cast<cocostudio::Armature*>(this->getChildByName(BARREL_BOTTOM_STANDBY_EFFECT_NAME))->getAnimation()->setSpeedScale(1.0f);
        //    this->initialStacdbyEffectTime();
        //});
        return true;
    }

    void BarrelBottom::initScore(const std::string& name)
    {
        if (UI_NAME_BARREL_BOTTOM_FIRST == name)
        {
            score_ = BARREL_BOTTOM_SCORE_FIRST;
            pop_score_particle_path_ =  BARREL_PARTICLE_YELLOW;
        }
        else if (UI_NAME_BARREL_BOTTOM_SECOND == name)
        {
            score_ = BARREL_BOTTOM_SCORE_SECOND;
            pop_score_particle_path_ = BARREL_PARTICLE_BLUE;
        }
        else if (UI_NAME_BARREL_BOTTOM_THIRD == name)
        {
            score_ = BARREL_BOTTOM_SCORE_THIRD;
            pop_score_particle_path_ = BARREL_PARTICLE_PURPLE;
        }
        else if (UI_NAME_BARREL_BOTTOM_FOURTH == name)
        {
            score_ = BARREL_BOTTOM_SCORE_FOURTH;
            pop_score_particle_path_ = BARREL_PARTICLE_BLUE;
        }
        else if (UI_NAME_BARREL_BOTTOM_FIFTH == name)
        {
            score_ = BARREL_BOTTOM_SCORE_FIFTH;
            pop_score_particle_path_ = BARREL_PARTICLE_YELLOW;
        }
        double_score_ = score_*2;
        initial_score_ = score_;
    }

    void bubble_second::BarrelBottom::initPopLabelComponent()
    {
        label_component_ = PopScoreLabelComponent::create();
        label_component_->setPositionY(POP_SCORE_LABEL_POS_Y);
        this->addChild(label_component_);
    }
    //void BarrelBottom::initScoreLabel()
    //{
    //    score_label_ = cocos2d::ui::TextBMFont::create(XMLTool::convertIntToString(score_), BARREL_SCORE_LABEL_FNT_PATH);
    //    this->addChild(score_label_);
    //}

    void BarrelBottom::playEffect()
    {
        //using cocostudio::ArmatureDataManager;
        //using cocostudio::Armature;
        //if (effect_flag_)
        //{
        //    effect_flag_ = false;
        //    Armature* armature = Armature::create(BARREL_BOTTOM_EFFECT_NAME);
        //    armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        //    armature->getAnimation()->setMovementEventCallFunc([=](Armature* armature, cocostudio::MovementEventType type, const std::string&) {
        //        if (type == cocostudio::COMPLETE)
        //        {
        //            armature->removeFromParent();
        //            effect_flag_ = true;
        //        }
        //    });
        //    this->addChild(armature);
        //}
        cocos2d::ParticleSystemQuad* particle = cocos2d::ParticleSystemQuad::create(pop_score_particle_path_);
        particle->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(particle, -1);
        particle->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(1), cocos2d::CallFunc::create([=]() {particle->removeFromParent(); })));
    }

    //void BarrelBottom::playStandbyEffect()
    //{
    //    using cocostudio::ArmatureDataManager;
    //    using cocostudio::Armature;
    //    Armature* armature = Armature::create(BARREL_BOTTOM_STANDBY_EFFECT_NAME);
    //    //armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
    //    auto call_func = [=](Armature* armature, cocostudio::MovementEventType type, const std::string&) {
    //        if (type == cocostudio::COMPLETE)
    //        {
    //            armature->setVisible(false);
    //            float time = RANDOM_DECIMALS(0, standby_effect_delaytime_max_);
    //            armature->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(time), cocos2d::CallFunc::create(
    //                [=]() {
    //                armature->setVisible(true);
    //                armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
    //            })));
    //        }
    //    };
    //    armature->getAnimation()->setMovementEventCallFunc(call_func);
    //    call_func(armature, cocostudio::COMPLETE, "");
    //    armature->setPositionY(BARREL_BOTTOM_STANDBY_EFFECT_POS_Y);
    //    //armature->setPosition(-50, 50);
    //    this->addChild(armature);
    //}

    void BarrelBottom::initialStacdbyEffectTime()
    {
        standby_effect_delaytime_max_ = BARREL_BOTTOM_STANDBY_EFFECT_DELAYTIME_MAX;
    }

    void BarrelBottom::setStacdbyEffectTime(int time)
    {
        standby_effect_delaytime_max_ = time;
    }

    void BarrelBottom::initPhysicsBody()
    {
        auto body = cocos2d::PhysicsBody::createEdgeBox(PHYSICS_BARREL_BOTTOM_BODY_SIZE,
            cocos2d::PhysicsMaterial(PHYSICS_BARREL_BOTTOM_BODY_DENSITY, PHYSICS_BARREL_BOTTOM_BODY_RESTITUTION,
                PHYSICS_WORLD_FRICTION), PHYSICS_BARREL_BOTTOM_BORDER*SmartScaleController::getInstance()->getPlayAreaZoom());
        body->setCategoryBitmask(BITMASK_BARRELBOTTOM_CATEGORY);
        body->setCollisionBitmask(BITMASK_BARRELBOTTOM_COLLISION);
        body->setContactTestBitmask(BITMASK_BARRELBOTTOM_CONTACTTEST);
        this->setPhysicsBody(body);
    }

    void BarrelBottom::contactOnce()
    {
        //cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SCORE_ADD, &score_);
        GameScoreController::getInstance()->addScoreWithNumble(score_);
        label_component_->popLabelWithScore(score_);
        this->playEffect();
    }
}