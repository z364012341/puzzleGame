//*******************************************************************************
//类名称   : GameClingAnimationComponent
//功能     : <小球附着操作动画组件>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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