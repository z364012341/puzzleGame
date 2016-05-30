//*******************************************************************************
//类名称   : GameDefeatAnimationComponent
//功能     : <失败后小球动画组件>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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

