//*******************************************************************************
//类名称   : StageMenuManager
//功能     : <分离精灵的纹理创建的逻辑>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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