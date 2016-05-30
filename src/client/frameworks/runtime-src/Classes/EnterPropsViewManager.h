//*******************************************************************************
//������   : EnterPropsViewManager
//����     : <������ߵĹ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _ENTER_PROPS_VIEW_MANAGER_H_
#define _ENTER_PROPS_VIEW_MANAGER_H_
#include "BubbleSecondConstant.h"
const std::string AIMING_LINE_COMMODITY_NAME = "AimingLineCommodity";
const std::string ADD_SPECIAL_COMMODITY_NAME = "AddSpecialCommodity";
const std::string ADD_BUBBLE_NUMBLE_COMMODITY_NAME = "AddBubbleNumbleCommodity";
namespace bubble_second {
    class EnterPropsViewManager
    {
    public:
        GETINSTANCE_FUNC(EnterPropsViewManager);
        ~EnterPropsViewManager();
        cocos2d::Node* createEnterPropsAlert();
        void setPropsSwitch(const std::string& props, bool pros_switch = false);
        bool getPropsSwitchEnable(const std::string& props);
        int getAddBubbleNumblePropsNumble();
    private:
        EnterPropsViewManager();
        std::map<std::string, bool> props_switch_;
    };
}
#endif //_ENTER_PROPS_VIEW_MANAGER_H_