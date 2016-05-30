//*******************************************************************************
//类名称   : ScoreProgressStar
//功能     : <游戏场景顶部的分数进度条上面的星星>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _SCORE_PROGRESS_STAR_H_
#define _SCORE_PROGRESS_STAR_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class ScoreProgressStar : public cocos2d::Sprite
    {
    public:
        static ScoreProgressStar* createWithPercent(float percent);
        //static ScoreProgressStart* createWithSwitchFlag(bool flag);
        CREATE_FUNC(ScoreProgressStar);
        ~ScoreProgressStar(); 
        void controlLightWithPercent(float percent);
        void controlLightWithFlag(bool flag);
        bool startIsOn();
		float getStartPercent();
    private:
        bool initWithPercent(float percent);
        //bool initWithSwitchFlag(bool flag);
        bool init();
        void startTurnOn();
        void startTurnOff();
        void playTurnOnAnimation();
        ScoreProgressStar();
        void setStartPercent(float percent);
        void setStartSpriteShader(const std::string& shader_path);
        bool isNeedTurnOn(float percent);
    private:
        float start_percent_ = 0.0f;
        bool start_on_flag_ = true;
    };
}
#endif