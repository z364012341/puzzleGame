#include "BubbleMainSightingDevice.h"
#include "BubbleReflectionPointComponent.h"
#include "EnterPropsViewManager.h"
#include "GamePlayController.h" 
#include "BubbleSecondConstant.h"
const int MAIN_SIGHTING_DEVICE_TARGET_ID = 0;
//const std::string SIGHTING_POINTS_VISIBLE_SCHEDULE_KEY = "sighting_points_visible_schedule_key";
namespace bubble_second {
    BubbleMainSightingDevice::BubbleMainSightingDevice()
    {
    }

    bool BubbleMainSightingDevice::init()
    {  
        if (!BubbleSightingDevice::init())
        {
            return false;
        }
        this->addChild(reflection_point_component_ = BubbleReflectionPointComponent::create());
        return true;
    }

    void BubbleMainSightingDevice::initRemainDevice()
    {
        this->setTargetID(MAIN_SIGHTING_DEVICE_TARGET_ID);
        this->setVisible(false);
        int device_numble_max = EnterPropsViewManager::getInstance()->getPropsSwitchEnable(AIMING_LINE_COMMODITY_NAME) ?
            BUBBLE_SIGHTING_DEVICE_TOTAL : BUBBLE_SIGHTING_DEVICE_UNUSED_PROPS_TOTAL;
        BubbleSightingDevice* last_device = this;
        for (int i = MAIN_SIGHTING_DEVICE_TARGET_ID+1; i <= device_numble_max; i++)
        {
            BubbleSightingDevice* device = BubbleSightingDevice::create();
            device->setPositionX(BUBBLE_SIGHTING_DEVICE_GO_AWAY_Y);
            this->getParent()->addChild(device, UI_ZORDER_SIGHTING_DEVICE);
            last_device->setNextSightingDevice(device);
            device->setTargetID(i);
            last_device = device;
        }
    }

    void BubbleMainSightingDevice::rotateDevice(const cocos2d::Vec2 & touch_point)
    {
        reflection_point_component_->calculateReflectionPoints(touch_point);
        auto points = reflection_point_component_->getReflectionPoints();
        int relection_offset = (int)(points.front().getDistance(GamePlayController::getInstance()->getShootingInitialPosition())) % (int)MAP_BUBBLE_DIAMETER;
        this->getNextSightingDevice()->setReflectionPointOffset(reflection_point_component_->getReflectionoffset());
        this->setDeviceRotation(reflection_point_component_->getReflectionAngles());
        this->getNextSightingDevice()->setDevicePosition(points);
        //this->setContactMinPosition(points);
        this->getNextSightingDevice()->setDevicePointHidden(reflection_point_component_->getHiddenFlags());
        //this->runAction(cocos2d::CallFunc::create([=]() {
        //    this->setSightingPointsVisibled();
        //}));
    }
    BubbleMainSightingDevice::~BubbleMainSightingDevice()
    {

    }
    void BubbleMainSightingDevice::setParent(cocos2d::Node * parent)
    {
        BubbleSightingDevice::setParent(parent);
        this->initRemainDevice();
    }
    void BubbleMainSightingDevice::onEnter()
    {
        BubbleSightingDevice::onEnter();
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_MAIN_ROTATE_SIGHTING_DEVICE, [=](cocos2d::EventCustom* event) {
            cocos2d::Vec2 touch_point = *static_cast<cocos2d::Vec2*>(event->getUserData());
            this->rotateDevice(touch_point);
            this->turnOnSightingDevice();
            this->setVisible(true);
        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_TURN_ON_SIGHTING_DEVICE, [=](cocos2d::EventCustom* event) {
            cocos2d::Vec2 touch_point = *static_cast<cocos2d::Vec2*>(event->getUserData());
            this->turnOnMainSightingDevice(touch_point);
        });
    }
    void BubbleMainSightingDevice::onExit()
    {
        BubbleSightingDevice::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_MAIN_ROTATE_SIGHTING_DEVICE);
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_TURN_ON_SIGHTING_DEVICE);
    }
    void BubbleMainSightingDevice::turnOnMainSightingDevice(const cocos2d::Vec2 & touch_point)
    {
        this->rotateDevice(touch_point);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.01f), cocos2d::CallFunc::create([=]() {
            this->turnOnSightingDevice();
            this->setVisible(true);
        })));
    }
    //void BubbleMainSightingDevice::turnOnSightingDevice()
    //{
    //    //this->setVisible(false);
    //    this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.01), cocos2d::CallFunc::create([=]() {
    //        BubbleSightingDevice::turnOnSightingDevice();
    //        this->setVisible(true);
    //    })));
    //    //this->setSightingPointsVisibled();
    //}
    void BubbleMainSightingDevice::turnOffSightingDevice()
    {
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.01f), cocos2d::CallFunc::create([=]() {
            BubbleSightingDevice::turnOffSightingDevice();
            this->setVisible(false);
        })));
    }
}