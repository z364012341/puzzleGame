//*******************************************************************************
//������   : StageNumble
//����     : <�ؿ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAGE_NUMBLE_H_
#define _STAGE_NUMBLE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class StageNumble
    {
    public:
        GETINSTANCE_FUNC(StageNumble);
        ~StageNumble();
        int getStageNumble() const;
        void nextStageNumble();
        bool moreThanStageTotal();
        void clear();
    private:
        StageNumble();
    private:
        int stage_numble_;
    };
}
#endif //_STAGE_NUMBLE_H_