//*******************************************************************************
//������   : AddBubbleNumbleCommodity
//����     : <��10������������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _ADD_BUBBLE_NUMBLE_COMMODITY_H_
#define _ADD_BUBBLE_NUMBLE_COMMODITY_H_
#include "EnterGamePropsView.h"

namespace bubble_second {
    class AddBubbleNumbleCommodity : public EnterGamePropsView
    {
    public:
        static cocos2d::Node* createCommodityArmature();
        CREATE_FUNC(AddBubbleNumbleCommodity);
        AddBubbleNumbleCommodity();
        ~AddBubbleNumbleCommodity();
    private:
        bool init();
    };
}
#endif // _ADD_BUBBLE_NUMBLE_COMMODITY_H_