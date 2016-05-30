//*******************************************************************************
//������   : BombBombBubble
//����     : <��ͼ�ϵ�ը��������>
//-------------------------------------------------------------------------------
//��ע     : <./.���������  �����֪��ΪʲôҪ��bombbomb>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BOMB_BOMB_BUBBLE_H_
#define _BOMB_BOMB_BUBBLE_H_
//#include "cocos2d.h"
#include "BaseBubble.h"
namespace bubble_second {
    class BombBombBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(BombBombBubble);
        ~BombBombBubble();
    public:
        void downFromAir() override;
        //С����������
        void bubbleEliminate(int combo = 0) override;
        //float playTheSpecialEffects() override;
        void playEliminateEffect();
    private:
        BombBombBubble();
        bool init();
        void addCenterFire();
    };
}
#endif //_BOMB_BOMB_BUBBLE_H_