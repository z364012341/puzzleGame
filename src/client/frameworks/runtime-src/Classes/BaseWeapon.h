//*******************************************************************************
//������   : BaseWeapon
//����     : <��Ϸ�������Ļ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BASE_WEAPON_H_
#define _BASE_WEAPON_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    //class BaseBubble;
    class BaseWeapon : public cocos2d::Node
    {
    public:
        //CREATE_FUNC(BaseWeapon);
        BaseWeapon();
        virtual ~BaseWeapon();
        //void setSelectBubble(BaseBubble* bubble);
        virtual bool inAttackRange(BubbleType color);
        virtual void attackBubble();
        virtual void selectBubble(const cocos2d::Vec2& point);
    protected:
        bool init(const std::string& armature_name);
        cocostudio::Armature* getWeaponArmature();
    private:
        BaseBubble* select_bubble_ = nullptr;
        cocostudio::Armature* armature_ = nullptr;
    };
}
#endif //_BASE_WEAPON_H_