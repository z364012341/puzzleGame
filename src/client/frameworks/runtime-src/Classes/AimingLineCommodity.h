//*******************************************************************************
//������   : AimingLineCommodity
//����     : <��׼�ߵ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _AIMING_LINE_COMMODITY_H_
#define _AIMING_LINE_COMMODITY_H_
#include "EnterGamePropsView.h"
namespace bubble_second {
    class AimingLineCommodity : public EnterGamePropsView
    {
    public:
        static cocos2d::Node* createCommodityArmature();
        CREATE_FUNC(AimingLineCommodity);
        ~AimingLineCommodity();
    private:
        AimingLineCommodity();
        bool init();
    };
}
#endif //_AIMING_LINE_COMMODITY_H_