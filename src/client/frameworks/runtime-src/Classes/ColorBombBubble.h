//*******************************************************************************
//������   : ColorBombBubble
//����     : <���������ȥʹ���˵��ߵĲ���ը��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _COLOR_BOMB_BUBBLE_H_
#define _COLOR_BOMB_BUBBLE_H_
#include "cocos2d.h"
#include "ColorBubble.h"
namespace bubble_second {
    class ColorBombBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(ColorBombBubble);
        virtual ~ColorBombBubble();
    public:
        void dispatchEventAfterShooted() override;
        void bubbleEliminate(int = 0) override;
        float playTheSpecialEffects() override;
        void downFromAir() override;
    private:
        ColorBombBubble();
        bool init();
    };
}
#endif //_COLOR_BOMB_BUBBLE_H_