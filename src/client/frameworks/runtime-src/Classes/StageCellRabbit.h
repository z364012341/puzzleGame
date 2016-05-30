//*******************************************************************************
//������   : StageCellRabbit
//����     : <��Ϸ����ѡ������Ӷ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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