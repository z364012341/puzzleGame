//*******************************************************************************
//������   : AddSpecialCommodity
//����     : <��3�������ݵ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _ADD_SPECIAL_COMMODITY_H_
#define _ADD_SPECIAL_COMMODITY_H_
#include "EnterGamePropsView.h"
namespace bubble_second {
    class AddSpecialCommodity : public EnterGamePropsView
    {
    public:
        CREATE_FUNC(AddSpecialCommodity);
        AddSpecialCommodity();
        ~AddSpecialCommodity();
        bool init();
    };
}
#endif //_ADD_SPECIAL_COMMODITY_H_