//*******************************************************************************
//������   : PuzzleStageDataManager
//����     : <ƴͼ�ؿ����ݹ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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