#include "ScoreWidget.h"
#include "ScoreWidgetManager.h"
#include "GameScoreController.h"
#include "SmartScaleController.h"
#include "GameNoneBubbleDownAnimationComponent.h"
#include "PopScoreLabelComponent.h"
const std::string SCOREWIDGET_ARMATURE_NAME = "mifeng";
const std::string SCOREWIDGET_ANIMATION_FLYING_NAME = "daiji"; //飞的动画
const std::string BUBBLE_ANIMATION_STANDBY_NAME = "daiji-zhayan";
const std::string SCOREWIDGET_ANIMATION_CONTACT_NAME = "shouji"; //碰到的动画
const std::string SCOREWIDGET_ANIMATION_REMOVE_NAME = "siwang";
const std::string BUBBLE_ANIMATION_LOOK_NAME_1 = "shangxiakan";
const std::string BUBBLE_ANIMATION_LOOK_NAME_2 = "zuoyoukan";
const float SCOREWIDGET_ARMATURE_SCALE = 0.5;
//const std::string SCORE_WIDGET_UPDATE_ANIMATION_NAME = "yun3";
const float SCORE_WIDGET_BEZIER_FLYING_DURATION = 0.8f; //得分挂件的赛贝尔运动时间

namespace bubble_second {
    ScoreWidget::ScoreWidget() :widget_combo_(0), armature_(nullptr)
    {
        type_update_to_type_[kScoreWidgetLow] = kScoreWidgetMiddle;
        type_update_to_type_[kScoreWidgetMiddle] = kScoreWidgetHigh;
        type_update_to_type_[kScoreWidgetHigh] = kScoreWidgetHigh;
        type_to_score_[kScoreWidgetLow] = SCORE_WIDGET_BLUE_SCORE;
        type_to_score_[kScoreWidgetMiddle] = SCORE_WIDGET_YELLOW_SCORE;
        type_to_score_[kScoreWidgetHigh] = SCORE_WIDGET_GREEN_SCORE;
    }

    ScoreWidget::~ScoreWidget()
    {
        this->unscheduleAllCallbacks();
    }

    bool ScoreWidget::initWithType(const ScoreWidgetType& type)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addArmature();
        this->setType(type);
        this->setName(SCORE_WIDGET_NAME);
        this->initPopScoreLabel();
        armature_->setScale(SCOREWIDGET_ARMATURE_SCALE);
        return true;
    }

    void ScoreWidget::addAnimationComponent()
    {
        std::vector<std::string> names;
        names.push_back(BUBBLE_ANIMATION_LOOK_NAME_1);
        names.push_back(BUBBLE_ANIMATION_LOOK_NAME_2);
        none_bubble_component_ = GameNoneBubbleDownAnimationComponent::createRandomPlayAnimation(armature_, names, CC_CALLBACK_0(ScoreWidget::playStandbyAnimation, this));
        this->addChild(none_bubble_component_);
    }

    void ScoreWidget::initPopScoreLabel()
    {
        label_component_ = PopScoreLabelComponent::create();
        label_component_->setPositionY(30.0f);
        label_component_->setScale(0.8f);
        this->addChild(label_component_);
    }

    void ScoreWidget::removeScoreWidget()
    {
        auto body = this->getPhysicsBody();
        if (body)
        {
            body->removeFromWorld();
        }
        //armature_->getAnimation()->stop();
        none_bubble_component_->removeFromParent();
        armature_->getAnimation()->play(SCOREWIDGET_ANIMATION_REMOVE_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->removeFromParent();
            }
        });
        //armature_->getAnimation()->setMovementEventCallFunc(nullptr);
        //this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(1.67f), cocos2d::CallFunc::create([=]() {
        //    this->removeFromParent();
        //})));
    }
    void ScoreWidget::setType(const ScoreWidgetType& type)
    {
        type_ = type;
        ScoreWidgetManager::getInstance()->changeScoreWidgetArmatureDisplay(armature_, type_);
    }

    void ScoreWidget::addPhysicsBody()
    {
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(ADD_PHYSICASBODY_DELAYTIME), cocos2d::CallFunc::create([&]()
        {
            cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(SCORE_WIDGET_BODY_RADIUS,
                cocos2d::PhysicsMaterial(PHYSICS_SCORE_WIDGET_BODY_DENSITY,
                    PHYSICS_SCORE_WIDGET_BODY_RESTITUTION, PHYSICS_SCORE_WIDGET_BODY_FRICTION));
            body->setDynamic(false);
            body->setGravityEnable(false);
            body->setCategoryBitmask(BITMASK_SCORE_WIDGET_CATEGORY);
            body->setCollisionBitmask(BITMASK_SCORE_WIDGET_COLLISION);
            body->setContactTestBitmask(BITMASK_SCORE_WIDGET_CONTACTTEST);
            this->setPhysicsBody(body);
        }), NULL));
    }

    void ScoreWidget::updateScoreWidgetType()
    {
        if (this->getType() == kScoreWidgetHigh)
        {
            return;
        }
        cocostudio::Armature* armature = ScoreWidgetManager::getInstance()->getWidgetUpdateArmature(type_update_to_type_[type_]);
        this->addChild(armature);
        armature->getAnimation()->playWithIndex(0);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                this->setType(type_update_to_type_[type_]);
                this->comboClear();
                armature->removeFromParent();
            }
        });
    }

    ScoreWidgetType ScoreWidget::getType()
    {
        return type_;
    }

    void ScoreWidget::addOneCombo()
    {
        if (combo_flag_)
        {
            ++widget_combo_;
            if (widget_combo_ > SCORE_WIDGET_MAX_COMBO)
            {
                this->comboClear();
            }
			this->unschedule(CC_SCHEDULE_SELECTOR(ScoreWidget::turnOffCombo));
        }
        else
        {
            this->comboClear();
            combo_flag_ = true;
        }
		this->scheduleOnce(CC_SCHEDULE_SELECTOR(ScoreWidget::turnOffCombo), SCORE_WIDGET_COMBO_DELAY);
    }

    void ScoreWidget::turnOffCombo(float)
    {
        combo_flag_ = false;
    }

    void ScoreWidget::comboClear()
    {
        widget_combo_ = ScoreWidgetManager::getInstance()->getScoreWidgetTotalWithType(type_);
        combo_flag_ = false;
    }

    void ScoreWidget::contactOnce()
    {        
        this->addOneCombo();
        int score = this->getContactScore();
        GameScoreController::getInstance()->addScoreWithNumble(score);
        this->playContactAnimation(score);
    }

    int ScoreWidget::getContactScore()
    {
        return type_to_score_[type_]*widget_combo_;
    }

    void ScoreWidget::playContactAnimation(int score)
    {  
        if (canPlayingContactAnimation())
        {
            this->setPlayContactAnimationEnabled(false);
            armature_->getAnimation()->play(SCOREWIDGET_ANIMATION_CONTACT_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    this->setPlayContactAnimationEnabled(true);
                    this->playStandbyAnimation();
                }
            });
        }
        label_component_->popLabelWithScore(score);
    }

    void ScoreWidget::playStandbyAnimation()
    {
        std::vector<std::string> names;
        names.push_back(SCOREWIDGET_ANIMATION_FLYING_NAME);
        names.push_back(SCOREWIDGET_ANIMATION_FLYING_NAME);
        names.push_back(SCOREWIDGET_ANIMATION_FLYING_NAME);
        names.push_back(SCOREWIDGET_ANIMATION_FLYING_NAME);
        names.push_back(SCOREWIDGET_ANIMATION_FLYING_NAME);
        names.push_back(SCOREWIDGET_ANIMATION_FLYING_NAME);
        names.push_back(SCOREWIDGET_ANIMATION_FLYING_NAME);
        names.push_back(BUBBLE_ANIMATION_STANDBY_NAME);
        armature_->getAnimation()->playWithNames(names);
        armature_->getAnimation()->setMovementEventCallFunc(nullptr);
    }

    void ScoreWidget::addArmature()
    {
        armature_ = cocostudio::Armature::create(SCOREWIDGET_ARMATURE_NAME);
        this->addChild(armature_);
        this->addAnimationComponent();
    }

    void ScoreWidget::playFlyingAnimation(float duration)
    {
        armature_->getAnimation()->play(SCOREWIDGET_ANIMATION_FLYING_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(duration), cocos2d::CallFunc::create([=]() {
            this->playStandbyAnimation();
        }));
        armature_->runAction(seq);
    }

    bool ScoreWidget::canPlayingContactAnimation()
    {
        return action_flag_;
    }

    void ScoreWidget::setPlayContactAnimationEnabled(bool flag)
    {
        action_flag_ = flag;
    }

    void ScoreWidget::runEnterAction()
    {
        cocos2d::ccBezierConfig config;
        config.endPosition = this->getSelfPosition();
        config.controlPoint_1 = this->getPosition();
        config.controlPoint_2 = cocos2d::Vec2(0.0f, 0.0f);
        cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, config);
        this->setScale(2.0f);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::Spawn::createWithTwoActions(bezier, cocos2d::ScaleTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, 1.0f)), cocos2d::CallFunc::create([=]() {
            this->addPhysicsBody();
        })));
        this->playFlyingAnimation(SCORE_WIDGET_BEZIER_FLYING_DURATION);
    }

    void ScoreWidget::runFirstEnterActioin()
    {
        auto self_position = this->getSelfPosition();
        auto size = cocos2d::Director::getInstance()->getVisibleSize() / SmartScaleController::getInstance()->getPlayAreaZoom();
        if (self_position.x > 0.0f)
        {
            this->setPosition(size.width / 2, INITIAL_SCORE_WIDGET_POS_Y);
        }
        else
        {
            this->setPosition(size.width / -2, INITIAL_SCORE_WIDGET_POS_Y);
        }
        cocos2d::ccBezierConfig config;
        config.endPosition = self_position;
        config.controlPoint_1 = this->getPosition();
        config.controlPoint_2 = cocos2d::Vec2(0.0f, 0.0f);
        cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, config);
        this->runAction(bezier);
        this->playFlyingAnimation(SCORE_WIDGET_BEZIER_FLYING_DURATION);
        this->addPhysicsBody();
    }

    void ScoreWidget::setSelfPosition(const cocos2d::Vec2& point)
    {
        self_position_ = point;
    }

    cocos2d::Vec2 ScoreWidget::getSelfPosition()
    {
        return self_position_;
    }
}