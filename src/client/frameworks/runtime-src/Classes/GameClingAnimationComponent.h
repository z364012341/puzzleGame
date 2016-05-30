//*******************************************************************************
//������   : GameClingAnimationComponent
//����     : <С���Ų����������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_CLING_ANIMATION_COMPONENT_H_
#define _GAME_CLING_ANIMATION_COMPONENT_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class GameClingAnimationComponent : public cocos2d::Node
    {
    public:
        static GameClingAnimationComponent* create(cocostudio::Armature* armature, const std::string& noop_name, std::function<void()> animation_end_func_ = nullptr);
        ~GameClingAnimationComponent();
        void onEnter() override;
        void onExit() override;
    private:
        GameClingAnimationComponent();
        bool init(cocostudio::Armature* armature, const std::string& noop_name, std::function<void()> animation_end_func_);
        void playClingAnimation();
    private:
        cocostudio::Armature* armature_ = nullptr;
        std::string animation_name_;
        std::function<void()> animation_end_func_ = nullptr;
        cocos2d::EventListenerCustom* listener_ = nullptr;
    };
}
#endif //_GAME_CLING_ANIMATION_COMPONENT_H_