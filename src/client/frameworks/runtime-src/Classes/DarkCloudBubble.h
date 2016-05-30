//*******************************************************************************
//�ļ���         : <DarkCloudBubble.h>
//�ļ�ʵ�ֹ���  : <��������, �ڸ����ݵ���ʵ����>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//�޸ļ�¼ :
//�� ��        �汾     �޸���              �޸�����
//2015/09/15   1.0     <�����>            <�����>
//*******************************************************************************
#ifndef _DARK_CLOUD_BUBBLE_H_
#define _DARK_CLOUD_BUBBLE_H_
#include "BaseBubble.h"
#include "cocos2d.h"
namespace bubble_second {
    class DarkCloudBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(DarkCloudBubble);
        ~DarkCloudBubble();
    public:
        void downFromAir() override;
        void bubbleEliminate(int unused_combo = 0) override;
    private:
        DarkCloudBubble();
        bool init();
        void addStandbyAction();
        cocos2d::Sprite* getCenterDarkCloud();
        void playEliminateEffect();
    };
}
#endif //_DARK_CLOUD_BUBBLE_H_