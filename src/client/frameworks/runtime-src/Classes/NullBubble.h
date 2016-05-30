//*******************************************************************************
//������   : NullBubble
//����     : <��Ϊ�յĲ��ɼ�Ҳ��������������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _NULL_BUBBLE_H_
#define _NULL_BUBBLE_H_
#include "BaseBubble.h"
namespace bubble_second {
    class NullBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(NullBubble);
        virtual ~NullBubble();
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
        bool needRemoveFromBubbleMap() override;
        void addBubbleStaticBody() override;
    private:
        NullBubble();
        bool init();
    };
}
#endif //_NULL_BUBBLE_H_