//*******************************************************************************
//������   : ScoreProgressStar
//����     : <��Ϸ���������ķ������������������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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