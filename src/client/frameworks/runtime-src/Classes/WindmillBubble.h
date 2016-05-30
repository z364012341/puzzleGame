//*******************************************************************************
//������   : WindmillBubble
//����     : <�糵������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _WINDMILL_BUBBLE_H_
#define _WINDMILL_BUBBLE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class WindmillBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(WindmillBubble);
        ~WindmillBubble();
        void onEnter() override;
        void onExit() override;
        void setParent(cocos2d::Node* parent) override;
        void bubbleEliminate(int combo = 0) override;
    private:
        WindmillBubble();
        bool init();
        void setBubbleTexture(BubbleType type) override {};
        void addArmature(cocos2d::Node* ndoe, const cocos2d::Vec2& point);
        //void addArmature();
        void addNoopComponent();
        void playStandbyAnimation();
        //�Ƿ��޲���״̬
        //bool isNoop();
        //void playNoopAnimation();
        void playContactAnimation();
        void disposedAroundEliminate(cocos2d::EventCustom* event);
        bool needPlayContactAnimation(const cocos2d::Vec2& bubble_index, const BubbleIndexVector& around_index);
        //cocos2d::Node* getFlyingTexture();
        //cocos2d::Action* getFlyingAction();
        cocos2d::CardinalSplineBy* getArchimedeanSpiralAction();
    private:
        //cocos2d::Sprite* sp_ = nullptr;
        cocostudio::Armature* armature_ = nullptr;
    };
}
#endif //_WINDMILL_BUBBLE_H_