//*******************************************************************************
//�ļ���         : <DarkCloudBubble.h>
//�ļ�ʵ�ֹ���  : <��������, �ڸ�>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BLACK_HOLE_BUBBLE_H_
#define _BLACK_HOLE_BUBBLE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class BlackHoleBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(BlackHoleBubble);
        ~BlackHoleBubble();
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
        //����С��
        void swallowBubble(BaseBubble* bubble);
        cocos2d::Vec2 getControlPointWithVectors(const cocos2d::Vec2& point_1, const cocos2d::Vec2& point_2);
        //�Ƿ���Ҫ����
        bool isNeedEliminate();
        //��Ϊ�ڶ�С����������
        bool needRemoveFromBubbleMap() override;
        void forceEliminate();
    private:
        BlackHoleBubble();
        bool init();
        void swallowBubbleOnce();
        void addSwallowTimes();
        //void initAnimation();
        void setBubbleTexture(BubbleType) override;
        void addTouchEventListener() override;
        void removeTouchEventListener() override;
        //����һ������
        void playFirstAction();
        void playSecondAction();
        //�����׵����߶���
        void playAchimedeanSpiralAction(BaseBubble* bubble);
    private:
        int swallow_times_;
        BubbleVector swallow_vector_;
        cocostudio::Armature* armature_;
    };
}
#endif //_BLACK_HOLE_BUBBLE_H_