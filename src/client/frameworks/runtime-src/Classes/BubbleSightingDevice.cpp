#include "BubbleSightingDevice.h"
#include "BubbleSightingPoint.h"
#include "EnterPropsViewManager.h"
#include "GamePlayController.h"
const float SIGHTING_POINT_BUBBLE_RADIUS = BUBBLE_RADIUS;
const float SIGHTING_POINT_REFLECTION_WIDTH = /*700.0f;*/GAME_DESIGN_RESOLUTION_WIDTH - SIGHTING_POINT_BUBBLE_RADIUS * 2;
const float SIGHTING_POINT_WORLD_MAX_X = GAME_DESIGN_RESOLUTION_WIDTH - SIGHTING_POINT_BUBBLE_RADIUS;
const float SIGHTING_POINT_MOVE_SPEED = 75.0f; //瞄准点移动速度
const float BUBBLE_SIGHTING_POINT_TOP_MOVEBY_Y = BUBBLE_RADIUS *4;  //瞄准线碰到顶部只反弹2颗
const std::string SIGHTING_POINTS_VISIBLE_SCHEDULE_KEY = "sighting_points_visible_schedule_key";
namespace bubble_second {
    BubbleSightingDevice::BubbleSightingDevice()
    {
    }

    BubbleSightingDevice::~BubbleSightingDevice()
    {
    }

    bool BubbleSightingDevice::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }

        this->setName(NAME_BUBBLE_SIGHTING_DEVICE);
        for (int i = 0; i < BUBBLE_SIGHTING_POINT_NUMBLE; i++)
        {
            sighting_points_.pushBack(BubbleSightingPoint::create());
        }
        this->sightingPointMove();
        return true;
    }

    void BubbleSightingDevice::onEnter()
    {
        cocos2d::Node::onEnter();
        this->schedule([=](float) {
            this->setSightingPointsVisibled();
        }, SIGHTING_POINTS_VISIBLE_SCHEDULE_KEY);
    }
    void BubbleSightingDevice::onExit()
    {
        cocos2d::Node::onExit();
        this->unschedule(SIGHTING_POINTS_VISIBLE_SCHEDULE_KEY);
    }

    void BubbleSightingDevice::setDeviceRotation(const std::vector<float>& angles)
    {
        if (this->getTargetID() < (int)angles.size())
        {
            this->setRotation(angles.at(this->getTargetID()));
            if (sight_device_)
            {
                sight_device_->setDeviceRotation(angles);
            }
        }
        else 
        {
            this->deviceGoAway();
            return;
        }
    }

    void BubbleSightingDevice::setDevicePosition(const std::vector<cocos2d::Vec2>& points)
    {
        if (this->getTargetID()-1 < (int)points.size())
        {
            this->setPosition(points.at(this->getTargetID()-1));
            if (sight_device_)
            {
                sight_device_->setDevicePosition(points);
            }
        }
        else
        {
            this->deviceGoAway();
            return;
        }
    }

    void BubbleSightingDevice::turnOnSightingDevice()
    {

        //this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0), cocos2d::CallFunc::create([=]() {
            switch_flag_ = true;
            //this->setSightingPointsVisibled();
        //})));
        if (nullptr != sight_device_)
        {
            sight_device_->turnOnSightingDevice();
        }

    }

    void BubbleSightingDevice::turnOffSightingDevice()
    {
        switch_flag_ = false;
        if (nullptr != sight_device_)
        {
            sight_device_->turnOffSightingDevice();
        }
    }

    bool BubbleSightingDevice::isDeviceOnStage()
    {
        return switch_flag_;
    }

    void BubbleSightingDevice::setReflectionPointOffset(const std::vector<float>& offset_vector)
    {
        if (this->getTargetID() - 1 < (int)offset_vector.size())
        {
            points_node_->setPositionY(-offset_vector.at(this->getTargetID() - 1));
            if (sight_device_ != nullptr)
            {
                sight_device_->setReflectionPointOffset(offset_vector);
            }
        }
    }

    void BubbleSightingDevice::setDevicePointHidden(const std::vector<bool>& flags)
    {
        if (this->getTargetID()-1 < (int)flags.size())
        {
            this->setHidePointEnable(flags.at(this->getTargetID()-1));
            if (sight_device_)
            {
                sight_device_->setDevicePointHidden(flags);
            }
            else
            {
                this->setHidePointEnable(true);
            }
        }
        else
        {
            this->deviceGoAway();
            return;
        }
    }

    void BubbleSightingDevice::setVisible(bool visible)
    {
        //this->runAction(cocos2d::CallFunc::create([=]() {  
            cocos2d::Node::setVisible(visible && this->isDeviceOnStage());
            //this->setSightingPointsVisibled();
            //this->setSightingPointsVisibled();
           //}));
            if (sight_device_ != nullptr)
            {
                bool f = this->isContactBubble();
                sight_device_->setVisible(visible && !this->isContactBubble());
            }



    }

    void BubbleSightingDevice::deviceGoAway()
    {
        this->setRotation(0.0f);
        this->setPositionX(BUBBLE_SIGHTING_DEVICE_GO_AWAY_Y);
        if (sight_device_)
        {
            sight_device_->deviceGoAway();
        }
    }

    void BubbleSightingDevice::stopDevicePoint()
    {
        for (auto var : sighting_points_)
        {
            var->pointStop();
        }
    }

    void BubbleSightingDevice::performSightingDevice()
    {
       // this->turnOnDeviceOnce();
        this->stopDevicePoint();
        this->schedule([=](float) {
            float angle = this->getRotation();
        }, "unused_key");
    }

    cocos2d::Vec2 BubbleSightingDevice::convertLocalToCsbSpace(const cocos2d::Vec2& local_point)
    {
        cocos2d::Vec2 point = local_point;
        cocos2d::Node* parent = points_node_;
        do
        {
            parent = parent->getParent();
        } while (parent->getName() != UI_NAME_GAME_PLAY_AREA_NODE);
        auto p1 = points_node_->convertToWorldSpaceAR(local_point);
        auto p2 = parent->convertToNodeSpaceAR(p1);
        return p2;
    }

    void BubbleSightingDevice::setHidePointEnable(bool flag)
    {
        is_hide_point_ = flag;
        if (is_hide_point_ && sight_device_)
        {
            sight_device_->deviceGoAway();
        }
    }

    bool BubbleSightingDevice::isHidePoint()
    {
        return is_hide_point_;
    }

    //void BubbleSightingDevice::turnOnDeviceOnce(int device_numble)
    //{
    //    this->setTargetID(device_numble);
    //    //this->setVisible(false);
    //    this->sightingPointMove();
    //    int device_numble_max = EnterPropsViewManager::getInstance()->getPropsSwitchEnable(AIMING_LINE_COMMODITY_NAME) ?
    //        BUBBLE_SIGHTING_DEVICE_TOTAL : BUBBLE_SIGHTING_DEVICE_UNUSED_PROPS_TOTAL;
    //    if (this->getTargetID() < device_numble_max)
    //    {
    //        sight_device_ = BubbleSightingDevice::create();
    //        this->addChild(sight_device_);
    //        sight_device_->turnOnDeviceOnce(this->getTargetID()+1);
    //    }
    //}

    void BubbleSightingDevice::sightingPointMove()
    {
        float distance = MAP_BUBBLE_DIAMETER*sighting_points_.size();
        float sighting_point_y = 0.0f;
        float y_offs = MAP_BUBBLE_DIAMETER;
        points_node_ = cocos2d::Node::create();
        this->addChild(points_node_);
        for (auto var : sighting_points_)
        {
            var->stopAllActions();
            var->setPosition(0.0f, sighting_point_y);
            if (!var->getParent())
            {
                points_node_->addChild(var);
            }
            var->clearContactCount();
            var->addPhysicsBodyCanntWorld();
            cocos2d::MoveBy* move_go = cocos2d::MoveBy::create((distance - sighting_point_y)/ SIGHTING_POINT_MOVE_SPEED, cocos2d::Vec2(0.0f, distance - sighting_point_y));

            cocos2d::CallFunc* callfunc = cocos2d::CallFunc::create([=]() {
                cocos2d::MoveBy* move_back = cocos2d::MoveBy::create(0.0f, cocos2d::Vec2(0.0f, -distance));
                cocos2d::MoveBy* move_go2 = cocos2d::MoveBy::create(distance / SIGHTING_POINT_MOVE_SPEED, cocos2d::Vec2(0.0f, distance));
                var->runAction(cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create([=]() {var->clearContactCount(); }), move_back, move_go2, nullptr)));
            });
            cocos2d::Sequence* seq = cocos2d::Sequence::create(move_go, callfunc, nullptr);
            var->runAction(seq);
            sighting_point_y += y_offs;
        }   
    }

    float BubbleSightingDevice::getHypotenuseOffset()
    {
        return points_node_->getPositionY();
    }

    float BubbleSightingDevice::getMaxTopY()
    {
        return GamePlayController::getInstance()->getPlayAreaMaxY();
    }

    float BubbleSightingDevice::getSightingPointsMinPositionY()
    {
        float top_min_y = BUBBLE_SIGHTING_POINT_TOP_MOVEBY_Y + abs(this->getHypotenuseOffset());
        float min_y = this->isHidePoint() ? top_min_y : BUBBLE_SIGHTING_POINT_MOVEBY_Y;
        for (auto var : sighting_points_)
        {
            if (var->isContacting() && var->getPositionY() < min_y)
            {
                min_y = var->getPositionY();
            }
        }
        return min_y;
        //return min_position_->y;
    }

    bool BubbleSightingDevice::isSightingPointsNeedHidden(const cocos2d::Vec2& point)
    {
        cocos2d::Vec2 var_point = this->convertLocalToCsbSpace(point);
        return point.y >= this->getSightingPointsMinPositionY() || var_point.x <= SIGHTING_POINT_BUBBLE_RADIUS || var_point.x >= SIGHTING_POINT_WORLD_MAX_X || var_point.y >= this->getMaxTopY();
    }

    void BubbleSightingDevice::setSightingPointsVisibled()
    {
        for (auto var : sighting_points_)
        {
            bool visible = (!this->isSightingPointsNeedHidden(var->getPosition())) && this->isDeviceOnStage();
            var->setPointEnabled(visible);
        }

        bool contact_bubble = this->isContactBubble();
        if (sight_device_&&contact_bubble)
        {
            //sight_device_->setVisible(!contact_bubble);
            sight_device_->turnOffSightingDevice();
        }

    }

    //void BubbleSightingDevice::setContactMinPosition(const std::vector<cocos2d::Vec2>& points)
    //{
    //    if (this->getTargetID() < (int)points.size())
    //    {
    //        //cocos2d::Vec2 point1 = this->getParent()->convertToWorldSpace(this->getPosition());
    //        //cocos2d::Vec2 point2 = this->getParent()->convertToWorldSpace(points.at(this->getTargetID()));
    //        //min_position_ = this->convertToNodeSpace(this->calculateContactMinPosition(point1, point2));
    //        //this->calculateContactMinPosition(point1, point2);
    //        if (sight_device_)
    //        {
    //            sight_device_->setContactMinPosition(points);
    //        }
    //    }
    //}

    //cocos2d::Vec2 BubbleSightingDevice::calculateContactMinPosition(const cocos2d::Vec2 & point1, const cocos2d::Vec2 & point2)
    //{
    //    cocos2d::Vec2 min_position = cocos2d::Vec2::ZERO;
    //    //min_position_ = &cocos2d::Vec2(0.0, 0.0);
    //    cocos2d::PhysicsRayCastCallbackFunc func = [=](cocos2d::PhysicsWorld& world, const cocos2d::PhysicsRayCastInfo& info, void* data)->bool
    //    {
    //        min_position_ = &cocos2d::Vec2(info.contact.x, info.contact.y);
    //        return true;
    //    };
    //    //GamePlayController::getInstance()->gamePhysicsRayCast(CC_CALLBACK_3(BubbleSightingDevice::devicePhysicsRayCastCallbackFunc, this), point1, point2);
    //    GamePlayController::getInstance()->gamePhysicsRayCast(func, point1, point2);
    //    //auto p = this->convertToNodeSpace(min_position);
    //    return min_position;
    //}

    //bool BubbleSightingDevice::devicePhysicsRayCastCallbackFunc(cocos2d::PhysicsWorld & world, const cocos2d::PhysicsRayCastInfo & info, void * data)
    //{
    //    //auto p = this->convertToNodeSpaceAR(info.contact);
    //    //min_position_ = this->convertToNodeSpace(info.contact);
    //    return false;
    //}

    bool BubbleSightingDevice::isContactBubble()
    {
        bool contact_bubble = false;
        for (auto var : sighting_points_)
        {
            if (var->isContacting())
            {
                contact_bubble = !contact_bubble;
                break;
            }
        }
        return contact_bubble;
    }

    void BubbleSightingDevice::contactBubble()
    {
        if (sight_device_)
        {
            //sight_device_->setVisible(false);
            sight_device_->turnOffSightingDevice();
        }
    }

    void BubbleSightingDevice::setTargetID(int numble)
    {
        target_id_ = numble;
    }

    int BubbleSightingDevice::getTargetID() const
    {
        return target_id_;
    }

    void BubbleSightingDevice::setNextSightingDevice(BubbleSightingDevice * device)
    {
        sight_device_ = device;
    }

    BubbleSightingDevice * BubbleSightingDevice::getNextSightingDevice()
    {
        return sight_device_;
    }

    void BubbleSightingDevice::changePointsColor(BubbleType color)
    {
        sighting_points_;
        for (auto var : sighting_points_)
        {
            var->changeSelfColor(color);
        }
        if (sight_device_)
        {
            sight_device_->changePointsColor(color);
        }
    }

}