//*******************************************************************************
//类名称   : PuzzleStageDataManager
//功能     : <拼图关卡数据管理>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _PUZZLE_STAGE_DATA_MANAGER_H_
#define _PUZZLE_STAGE_DATA_MANAGER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class PuzzleStageDataManager
    {
    public:
        GETINSTANCE_FUNC(PuzzleStageDataManager);
        void loadPuzzleStageData();
        int getGameTimeWithkey(const std::string& key);
    private:
        PuzzleStageDataManager();
        ~PuzzleStageDataManager();
    private:
        cocos2d::ValueMap puzzle_stage_data_;
    };
}
#endif //_PUZZLE_STAGE_DATA_MANAGER_H_