#include "StageMenuManager.h"
#include "StageSelectionMenu.h"
namespace bubble_second {
	StageMenuManager::StageMenuManager()
	{
	}

	StageMenuManager::~StageMenuManager()
	{
	}

	void StageMenuManager::setCurrentStageMenu(StageSelectionMenu* menu)
	{
		current_menu_ = menu;
	}

    StageSelectionMenu * StageMenuManager::getCurentStagemenu()
    {
        return current_menu_;
    }

	void StageMenuManager::setLastStageMenu(StageSelectionMenu* menu)
	{
		last_menu_ = menu;
	}

	cocos2d::Vec2 StageMenuManager::getCurrentStageWorldPosition() const
	{
		return current_menu_->getParent()->convertToWorldSpace(current_menu_->getPosition());
	}

	cocos2d::Vec2 StageMenuManager::getLastStageWorldPosition() const
	{
        if (last_menu_ != nullptr)
        {
            return last_menu_->getParent()->convertToWorldSpace(last_menu_->getPosition());
        }
        else
        {
            return this->getCurrentStageWorldPosition();
        }
	}

	cocos2d::Vec2 StageMenuManager::getCurrentStagePositionDelta() const
	{
		return this->getCurrentStageWorldPosition() - this->getLastStageWorldPosition();
	}
}