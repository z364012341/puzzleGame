#include "AimingLineCommodity.h"
#include "GameAlertMask.h"
#include "GameTextInfo.h"
#include "cocostudio\CocoStudio.h"
#include "BubbleSightingDevice.h"
const std::string AIMING_LIME_COMMODITY_CSB_PATH = "AimingLineCommodity.csb";
const std::string AIMING_LINE_COMMODITY_ANIMATION_NAME = "miaozhunxian";
namespace bubble_second {
    AimingLineCommodity::AimingLineCommodity()
    {
    }

    cocos2d::Node * AimingLineCommodity::createCommodityArmature()
    {
        cocos2d::Node* node = cocos2d::Node::create();
        node->addChild(GameAlertMask::create());
        cocostudio::Armature* armature = cocostudio::Armature::create(AIMING_LINE_COMMODITY_ANIMATION_NAME);
        armature->getAnimation()->playWithIndex(0);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                armature->removeFromParent();
                BubbleSightingDevice* device = BubbleSightingDevice::create();
                device->performSightingDevice();
            }
        });
        node->addChild(armature);
        return node;
    }

    AimingLineCommodity::~AimingLineCommodity()
    {
    }

    bool AimingLineCommodity::init()
    {
        if (!EnterGamePropsView::init(AIMING_LIME_COMMODITY_CSB_PATH))
        {
            return false;
        }
        this->setCostLabelStringWithKey(COMMODITY_AIMING_LINE_KEY);
        this->setName(AIMING_LINE_COMMODITY_NAME);
        return true;
    }
}