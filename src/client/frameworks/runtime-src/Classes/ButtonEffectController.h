//*******************************************************************************
//类名称   : ButtonEffectController
//功能     : <用于设置按钮的特效>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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
