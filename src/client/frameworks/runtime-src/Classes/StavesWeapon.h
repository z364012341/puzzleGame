//*******************************************************************************
//������   : StavesWeapon
//����     : <��������>
//-------------------------------------------------------------------------------
//��ע     : <���ȵ�ѡ��ͼ��>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAVES_WEAPON_H_
#define _STAVES_WEAPON_H_
#include "BaseWeapon.h"
namespace bubble_second {
    class StavesWeapon : public BaseWeapon
    {
    public:
        CREATE_FUNC(StavesWeapon);
        virtual ~StavesWeapon();
        void onEnter() override;
        void onExit() override;
        void attackBubble() override;
        bool inAttackRange(BubbleType color);
        void selectBubble(const cocos2d::Vec2& point) override;
    private:
        StavesWeapon();
        bool init();
    //private:
    //    std::map<BubbleType, bool> color_to_range_;
    };
}
#endif //_STAVES_WEAPON_H_