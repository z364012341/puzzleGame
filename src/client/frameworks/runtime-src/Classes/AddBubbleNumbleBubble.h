//*******************************************************************************
//�ļ���         : <AddBubbleNumbleBubble.h>
//�ļ�ʵ�ֹ���  : <++����, ���ӷ���������>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//�޸ļ�¼ :
//�� ��        �汾     �޸���              �޸�����
//2015/09/15   1.0     <�����>            <�����>
//*******************************************************************************
#ifndef _ADD_BUBBLE_NUMBLE_BUBBLE_H_
#define _ADD_BUBBLE_NUMBLE_BUBBLE_H_
#include "BaseBubble.h"
namespace bubble_second {
    class AddBubbleNumbleBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(AddBubbleNumbleBubble);
        ~AddBubbleNumbleBubble();
    public:
        void downFromAir() override;
        void bubbleEliminate(int numble = 0) override;
        float playTheSpecialEffects() override;
    private:
        AddBubbleNumbleBubble();
        bool init();
    };
}
#endif //_ADD_BUBBLE_NUMBLE_BUBBLE_H_