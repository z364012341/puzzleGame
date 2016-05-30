//*******************************************************************************
//类名称   : UserDiamondInfoBoard
//功能     : <游戏关卡场景上面的砖石面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _USER_DIAMOND_INFO_BOARD_H_
#define _USER_DIAMOND_INFO_BOARD_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class UserDiamondInfoBoard : public cocos2d::Node
    {
    public:
        CREATE_FUNC(UserDiamondInfoBoard);
        ~UserDiamondInfoBoard();
    private:
        UserDiamondInfoBoard();
        bool init();
        void playRandomTimeAnimation();
    private:
        cocostudio::Armature* armature_ = nullptr;
    };
}
#endif//_USER_DIAMOND_INFO_BOARD_H_