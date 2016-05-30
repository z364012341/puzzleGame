//*******************************************************************************
//类名称   : GameStageVehicle
//功能     : <游戏关卡选择场景中的载具>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _Game_Stage_Vehicle_H_
#define _Game_Stage_Vehicle_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
	class GameStageVehicle : public cocos2d::Node
	{
	public:
		CREATE_FUNC(GameStageVehicle);
		~GameStageVehicle();
        void moveVehicle(cocos2d::CallFunc* call_func);
        void setVehicleDirection();
        void setPositionWithWorldPosition(const cocos2d::Vec2& point);
	private:
		GameStageVehicle();
		bool init();
		void addArmature();
		void playStandbyAnimation();

	private:
		cocostudio::Armature* vehicle_armature_ = nullptr;
	};
}
#endif //_Game_Stage_Vehicle_H_
