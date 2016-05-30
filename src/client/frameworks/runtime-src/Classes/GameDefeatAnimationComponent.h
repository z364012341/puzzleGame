//*******************************************************************************
//������   : GameDefeatAnimationComponent
//����     : <ʧ�ܺ�С�򶯻����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_DEFEAT_ANIMATION_COMPONENT_H_
#define _GAME_DEFEAT_ANIMATION_COMPONENT_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class GameDefeatAnimationComponent : public cocos2d::Node
    {
    public:
        static GameDefeatAnimationComponent* create(cocostudio::Armature* armature, const std::string& noop_name);
        ~GameDefeatAnimationComponent();
        void onEnter() override;
        void onExit() override;
    private:
        GameDefeatAnimationComponent();
        bool init(cocostudio::Armature* armature, const std::string& noop_name);
        void playDefeatAnimation();
    private:
        cocostudio::Armature* armature_ = nullptr;
        std::string animation_name_;
        //std::function<void()> animation_end_func_ = nullptr;
        cocos2d::EventListenerCustom* listener_ = nullptr;
    };
}
#endif //_GAME_DEFEAT_ANIMATION_COMPONENT_H_

