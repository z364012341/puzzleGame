//*******************************************************************************
//������   : StageMenuManager
//����     : <���뾫������������߼�>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAGE_DATA_H_
#define _STAGE_DATA_H_
namespace bubble_second {
    class StageData
    {
    public:
        StageData(int cell_numble = 0, int level_numble = 0);
        //StageData(const StageData& data);
        ~StageData();
        int cell_numble;
        int level_numble;
    };
}
#endif //_STAGE_DATA_H_