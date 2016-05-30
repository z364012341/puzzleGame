//*******************************************************************************
//类名称   : GameNoopAnimationComponent
//功能     : <误操作动画组件>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_NOOP_ANIMATION_COMPONENT_H_
#define _GAME_NOOP_ANIMATION_COMPONENT_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class GameNoopAnimationComponent : public cocos2d::Node
    {
    public:
        static GameNoopAnimationComponent* create(cocostudio::Armature* armature, const std::string& noop_name, std::function<void()> clear_func = nullptr);
        ~GameNoopAnimationComponent();
        void onEnter() override;
        void onExit() override;
    private:
        GameNoopAnimationComponent();
        bool init(cocostudio::Armature* armature, const std::string& noop_name, std::function<void()> clear_func);
        //是否无操作状态
        bool isNoop();
        void playNoopAnimation();
    private:
        cocostudio::Armature* armature_ = nullptr;
        std::string animation_name_;
        std::function<void()> clear_func_ = nullptr;
        bool noop_state_ = false;
    };
}
#endif //_GAME_NOOP_ANIMATION_COMPONENT_H_