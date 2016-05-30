//*******************************************************************************
//������   : GameNoneBubbleDownAnimationComponent
//����     : <û��С����䶯�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_NONE_BUBBLE_DOWN_ANIMATION_COMPONENT_H_
#define _GAME_NONE_BUBBLE_DOWN_ANIMATION_COMPONENT_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class GameNoneBubbleDownAnimationComponent : public cocos2d::Node
    {
    public:
        static GameNoneBubbleDownAnimationComponent* createRandomPlayAnimation(cocostudio::Armature* armature, const std::vector<std::string>& animation_name, const std::function<void()>& animation_end_func = nullptr);
        GameNoneBubbleDownAnimationComponent();
        ~GameNoneBubbleDownAnimationComponent();
        void onEnter() override;
        void onExit() override;
    private:
        bool initRandomPlayAnimation(cocostudio::Armature* armature, const std::vector<std::string>& names, const std::function<void()>& animation_end_func);
        void playRandomAnimation();
    private:
        cocostudio::Armature* armature_ = nullptr;
        std::vector<std::string> animation_names_;
        std::function<void()> animation_end_func_ = nullptr;
        cocos2d::EventListenerCustom* listener_ = nullptr;
    };
}
#endif //_GAME_NONE_BUBBLE_DOWN_ANIMATION_COMPONENT_H_