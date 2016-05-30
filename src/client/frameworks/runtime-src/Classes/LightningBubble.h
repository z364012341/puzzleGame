//*******************************************************************************
//�ļ���         : <LightningBubble.h>
//�ļ�ʵ�ֹ���  : <��������, �����������ڵ�һ��>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//�޸ļ�¼ :
//�� ��        �汾     �޸���              �޸�����
//2015/09/15   1.0     <�����>            <�����>
//*******************************************************************************
#ifndef _LIGHTNING_BUBBLE_H_
#define _LIGHTNING_BUBBLE_H_
#include "BaseBubble.h"
namespace bubble_second {
    class LightningBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(LightningBubble);
        ~LightningBubble();
    public:
        void downFromAir() override;
        void bubbleEliminate(int) override;
        float playTheSpecialEffects() override;
    private:
        LightningBubble();
        bool init();
    };
}
#endif //_LIGHTNING_BUBBLE_H_