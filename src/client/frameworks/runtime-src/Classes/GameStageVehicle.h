//*******************************************************************************
//������   : GameStageVehicle
//����     : <��Ϸ�ؿ�ѡ�񳡾��е��ؾ�>
//-------------------------------------------------------------------------------
//��ע     : <>
//           
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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
