//*******************************************************************************
//������   : WoodenHammerSprite
//����     : <Сľ������>
//-------------------------------------------------------------------------------
//��ע     : <���ڵ���ͼ���ʹ�õ�ʱ����ʾ��>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _WOODEN_HAMMER_WEAPON_H_
#define _WOODEN_HAMMER_WEAPON_H_
#include "cocos2d.h"
#include "BaseWeapon.h"
namespace bubble_second {
    class WoodenHammerWeapon : public BaseWeapon
    {
    public:
        CREATE_FUNC(WoodenHammerWeapon);
        virtual ~WoodenHammerWeapon();
        void attackBubble() override;
    private:
        WoodenHammerWeapon();
        bool init();
    };
}
#endif //_WOODEN_HAMMER_WEAPON_H_