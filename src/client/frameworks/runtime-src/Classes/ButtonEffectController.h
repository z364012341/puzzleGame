//*******************************************************************************
//������   : ButtonEffectController
//����     : <�������ð�ť����Ч>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BUTTON_EFFECT_CONTROLLER_H_
#define _BUTTON_EFFECT_CONTROLLER_H_
//#include "BubbleSecondConstant.h"
#include "ui\UIButton.h"
namespace bubble_second {
    class ButtonEffectController
    {
    public:
        static void setButtonZoomScale(cocos2d::ui::Button* button);
        static void setButtonsZoomScale(cocos2d::Node* rootNode);
        ~ButtonEffectController();
    private:
        ButtonEffectController();
    };
}
#endif //_BUTTON_EFFECT_CONTROLLER_H_
