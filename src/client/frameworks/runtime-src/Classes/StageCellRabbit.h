//*******************************************************************************
//类名称   : StageCellRabbit
//功能     : <游戏场景选择的兔子动画>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _STAGE_CELL_RABBIT_H_
#define _STAGE_CELL_RABBIT_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class StageCellRabbit : public cocos2d::Node
    {
    public:
        CREATE_FUNC(StageCellRabbit);
        ~StageCellRabbit();
    private:
        StageCellRabbit();
        bool init();
        void playAnimationRandomTime();
    private:
        cocostudio::Armature* armature_ = nullptr;
    };
}
#endif //_STAGE_CELL_RABBIT_H_