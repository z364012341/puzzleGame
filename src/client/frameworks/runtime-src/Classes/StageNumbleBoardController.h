//*******************************************************************************
//类名称   : GameScoreController
//功能     : <关卡数面板控制器>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _Stage_Numble_Board_Controller_H_
#define _Stage_Numble_Board_Controller_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class StageNumbleBoardController
    {
    public:
        GETINSTANCE_FUNC(StageNumbleBoardController);
        ~StageNumbleBoardController();
        void loadView(cocos2d::Node* node, int numble);
    private:
        StageNumbleBoardController();
    };
}
#endif//_Stage_Numble_Board_Controller_H_ 