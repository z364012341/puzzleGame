//*******************************************************************************
//类名称   : GameShareButton
//功能     : <游戏分享按钮>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SHARE_BUTTON_H_
#define _GAME_SHARE_BUTTON_H_
#include "cocos2d.h"
//#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameShareButton : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameShareButton);
        ~GameShareButton();
    private:
        GameShareButton();
        bool init();
    };
}
#endif //_GAME_SHARE_BUTTON_H_