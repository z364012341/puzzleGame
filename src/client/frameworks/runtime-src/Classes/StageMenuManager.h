//*******************************************************************************
//类名称   : StageMenuManager
//功能     : <分离精灵的纹理创建的逻辑>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAGE_MENU_MANAGER_H_
#define _STAGE_MENU_MANAGER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class StageSelectionMenu;
	class StageMenuManager
	{
	public:
		GETINSTANCE_FUNC(StageMenuManager);
		~StageMenuManager();
		void setCurrentStageMenu(StageSelectionMenu* menu);
        StageSelectionMenu* getCurentStagemenu();
		void setLastStageMenu(StageSelectionMenu* menu);
		cocos2d::Vec2 getCurrentStageWorldPosition() const;
		cocos2d::Vec2 getLastStageWorldPosition() const;
		cocos2d::Vec2 getCurrentStagePositionDelta() const;
	private:
		StageMenuManager();
	private:
        StageSelectionMenu* current_menu_ = nullptr;
        StageSelectionMenu* last_menu_ = nullptr;
	};
}
#endif //_STAGE_MENU_MANAGER_H_