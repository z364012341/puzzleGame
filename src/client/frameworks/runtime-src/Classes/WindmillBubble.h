//*******************************************************************************
//类名称   : WindmillBubble
//功能     : <风车泡泡类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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
        //是否无操作状态
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