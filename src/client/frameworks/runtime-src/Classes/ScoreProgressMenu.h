//*******************************************************************************
//类名称   : ScoreMenu
//功能     : <游戏场景顶部的分数进度条>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _SCORE_PROGRESS_MENU_H_
#define _SCORE_PROGRESS_MENU_H_
#include "BubbleSecondConstant.h"
#include "StageDataModule.h"
#include "ui\UILoadingBar.h"
#include "StartNumbleModule.h"

namespace bubble_second {
    class ScoreProgressStar;
    class ScoreProgressMenu : public cocos2d::Node
    {
    public:
        CREATE_FUNC(ScoreProgressMenu);
        ~ScoreProgressMenu();
        void initialStartNumble(StartNumbleModule start_numble);
        void setScoreProgressTimerPercent(float score);
        int getStartOnNumble();
    private:
        ScoreProgressMenu();
        bool init();
        void initScoreMenu();
        void initStartSprite();
        void addProgressTimerHead();
        //void updateHeadPosition();
        //cocos2d::Vec2 getHeadPosition();
        cocos2d::Vec2 getStartPositionWithPercent(float percent);
        cocos2d::Vec2 calculateCirclePositionWithPercent(float percent);
        //void lightenStartSpriteWithKey(const std::string& key);
        //void lightenStartSpriteWithPercent(float percent);
        //cocos2d::ProgressTimer* getScoreProgressTimer();
        //增长进度条
        void increaseProgressTimer();
        //设置目标百分比, 到达了计时器就会停
        void setGoalPercent(float percent);
        float getGoalPercent();
        void setLastScore(int last_score);
        int getLastScore();
        bool isEqualLastScore(int score);
        //判断是否完成了目标百分比
        bool isCompletedGoalPercent(float percent);
        //判断是否退到位
        //bool isCompletedBack(float percent);
        StartNumbleModule getStartNumbleModule();
        void controlStartLight(float percent);
        //设置进度条实际的进度
        void setPercentage(float percentage);
        float getPercentage();
        void rotateProgressTimerWithPercentDelta(float percent_delta);
    private:
        cocos2d::Sprite* score_progress_timer_ = nullptr;
        //cocos2d::Sprite* progress_timer_head_ = nullptr;
        StartNumbleModule start_numble_;
        float global_percent_;
        //0 to 100 percent
        float current_percentage_;
        int last_score_ = 0;
        //星星容器
        cocos2d::Map<std::string, ScoreProgressStar*> start_sprite_map_;
    };
}
#endif 