//*******************************************************************************
//�ļ���         : <BubbleComponent.h>
//�ļ�ʵ�ֹ���  : <�ʺ��ӡde���>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BUBBLE_COMPONENT_H_
#define _BUBBLE_COMPONENT_H_
#include "BaseBubble.h"
namespace bubble_second {
    class BubbleComponent : public BaseBubble
    {
    public:
        static BubbleComponent* createWithCore(BaseBubble* bubble)
        {
            BubbleComponent *pRet = new(std::nothrow) BubbleComponent();
            if (pRet && pRet->initWithCore(bubble))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
        ~BubbleComponent();
        void setCoreBubble(BaseBubble* bubble);
        BaseBubble* getCoreBubble();
        BubbleVector getTotalBubbles();
        void bubbleEliminate(int combo = 0) override;
        bool isEliminateByProperty() override;
        void downFromAir() override;
        cocos2d::Vec2 getBubblePropsWeaponPosition() override;
    private:
        BubbleComponent();
        bool initWithCore(BaseBubble* bubble);
    private:
        BaseBubble* core_bubble_;
    };
}
#endif //_BUBBLE_COMPONENT_H_