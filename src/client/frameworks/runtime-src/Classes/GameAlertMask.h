//*******************************************************************************
//类名称   : EnterGameAlert
//功能     : <进入游戏场景前的面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_ALERT_MASK_H_
#define _GAME_ALERT_MASK_H_
#include "BubbleSecondConstant.h"
#include "ui\UIButton.h"
namespace bubble_second {
    class GameAlertMask : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameAlertMask);
        static GameAlertMask* createTransparentMask();
        ~GameAlertMask();
        //cocos2d::LayerColor* getBackgroundLayer();
        void backgroundFadeOut(float duration, cocos2d::CallFunc* func = nullptr);
    private:
        GameAlertMask();
        bool init();
        bool initTransparentMask();
        void addMaskMenu();
        void addColorLayer();
    private:
        cocos2d::LayerColor* layer_ = nullptr;
    };
}
#endif //_GAME_ALERT_MASK_H_
