//*******************************************************************************
//�ļ���       : <BaseComponentBubble.h>
//�ļ�ʵ�ֹ���  : <������ݵĸ���>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BASE_COMPONENT_BUBBLE_H_
#define _BASE_COMPONENT_BUBBLE_H_
#include "BaseBubble.h"
namespace bubble_second {
    class BubbleComponent;
    typedef cocos2d::Vector<BubbleComponent*> ComponentVector;
    class BaseComponentBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(BaseComponentBubble);
        virtual ~BaseComponentBubble();
        virtual void addBubbleComponent(BubbleComponent* component);
        ComponentVector getComponents();
        BubbleVector getTotalBubbles();
        void downFromAir() override;
    protected:
        BaseComponentBubble();
        bool init();
        void addCompletedTaskNumble();
        void addGameTaskNumble();
    private:
        ComponentVector components_;
    };
}
#endif //_BASE_COMPONENT_BUBBLE_H_