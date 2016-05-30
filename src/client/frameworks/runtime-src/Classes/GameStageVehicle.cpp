#include "GameStageVehicle.h"
#include "BubbleSecondConstant.h"
#include "StageMenuManager.h"
const std::string FIRE_BALLON_ARMATURE_NAME = "qiting";
const std::string FIRE_BALLON_ANIMATION_STANDBY_NAME = "yidong";
const float STAGE_VEHICLE_MOVE_DURATION = 2.0f;
const std::string VEHICLE_FLAG_BONE_NAME = "Layer8";
namespace bubble_second {
	GameStageVehicle::GameStageVehicle()
	{
	}


	GameStageVehicle::~GameStageVehicle()
	{
	}

	bool GameStageVehicle::init()
	{
		if (!cocos2d::Node::init())
		{
			return false;
		}
		this->addArmature();
		return true;
	}

	void GameStageVehicle::addArmature()
	{
		vehicle_armature_ = cocostudio::Armature::create(FIRE_BALLON_ARMATURE_NAME);
		this->addChild(vehicle_armature_);
		this->playStandbyAnimation();
	}

	void GameStageVehicle::playStandbyAnimation()
	{
		vehicle_armature_->getAnimation()->play(FIRE_BALLON_ANIMATION_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
	}

	void GameStageVehicle::setPositionWithWorldPosition(const cocos2d::Vec2& point)
	{
		this->setPosition(this->getParent()->convertToNodeSpace(point));
        this->setVehicleDirection();
	}
    void GameStageVehicle::moveVehicle(cocos2d::CallFunc * call_func)
    {
        this->setPositionWithWorldPosition(StageMenuManager::getInstance()->getLastStageWorldPosition());
        cocos2d::MoveBy * move = cocos2d::MoveBy::create(STAGE_VEHICLE_MOVE_DURATION, 
            StageMenuManager::getInstance()->getCurrentStagePositionDelta());
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(move, call_func);
        this->runAction(seq);
    }

    void GameStageVehicle::setVehicleDirection()
    {
        if (StageMenuManager::getInstance()->getCurrentStagePositionDelta().x >= 0.0f)
        {
            vehicle_armature_->getBone(VEHICLE_FLAG_BONE_NAME)->setScaleX(1);
        }
        else
        {
            vehicle_armature_->getBone(VEHICLE_FLAG_BONE_NAME)->setScaleX(-1);
        }
    }
}