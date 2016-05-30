//*******************************************************************************
//������   : StartNumbleModule
//����     : <�ؿ�������Ϣģ����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAGE_NUMBLE_MODULE_H_
#define _STAGE_NUMBLE_MODULE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    typedef std::map<std::string, float> StartNumble;
    typedef std::map<std::string, float> StartPercent;
    class StartNumbleModule
    {
    public:

        StartNumbleModule();
        StartNumbleModule(int numble1, int numble2, int numble3);
        ~StartNumbleModule();
        float getPercentWithScore(float score);
        StartPercent getPercentModule();
    private:
        void init(float numble1, float numble2, float numble3);
    private:
        StartNumble start_numble_;
        StartPercent start_percent_;
    };
}
#endif