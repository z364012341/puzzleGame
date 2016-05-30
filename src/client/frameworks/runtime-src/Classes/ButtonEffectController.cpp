#include "ButtonEffectController.h"
//#include "BubbleSecondConstant.h"
const float GAME_BUTTON_ZOOM_SCALE = -0.1f;    //BUTTON点击时的放大比例
namespace bubble_second {

    void ButtonEffectController::setButtonZoomScale(cocos2d::ui::Button * button)
    {
        button->setZoomScale(GAME_BUTTON_ZOOM_SCALE);
    }

    void ButtonEffectController::setButtonsZoomScale(cocos2d::Node * rootNode)
    {
        for (auto var : rootNode->getChildren())
        {
            if (cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(var))
            {
                ButtonEffectController::setButtonZoomScale(button);
            }
            else
            {
                ButtonEffectController::setButtonsZoomScale(var);
            }
        }
    }

    ButtonEffectController::ButtonEffectController()
    {
    }


    ButtonEffectController::~ButtonEffectController()
    {
    }
}