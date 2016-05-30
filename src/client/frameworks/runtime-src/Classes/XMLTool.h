//*******************************************************************************
//������   : CXXX
//����     : <����Ŀ����,�޸�,����xml>
//-------------------------------------------------------------------------------
//��ע     : <����xml�ļ�>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _XML_TOOL_H_
#define _XML_TOOL_H_
#include <string>
namespace bubble_second {
    class StageDataModule;
    class XMLTool
    {
    public:
        XMLTool();
        ~XMLTool();
    public:
        //��ȡ�ؿ�������Ϣ
        StageDataModule* decodeStageXMLWithStageNumble(int stageNumble);
        static int convertStringToInt(const std::string& str);
        static std::string convertIntToString(int numble);
    };
}
#endif //_XML_TOOL_H_