//*******************************************************************************
//������   : ControlButtonController
//����     : <��ͣ, ����, �ر�֮�ఴť������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _CONTROL_BUTTON_CONTROLLER_H_
#define _CONTROL_BUTTON_CONTROLLER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "ui\UIWidget.h"
namespace bubble_second {
    class ControlButtonController
    {
    public:
        GETINSTANCE_FUNC(ControlButtonController);
        ~ControlButtonController();
        void initControlButton(cocos2d::ui::Widget* root);
    private:
        ControlButtonController();
        bool addButtonTouchEventListener(cocos2d::ui::Widget* root);
    private:
        std::map<std::string, std::string> name_to_event_;
    };
}
#endif //_CONTROL_BUTTON_CONTROLLER_H_