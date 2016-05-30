//*******************************************************************************
//������   : ScoreProgressStart
//����     : <��Ϸ���������ķ������������������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _SCORE_PROGRESS_START_H_
#define _SCORE_PROGRESS_START_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class ScoreProgressStart : public cocos2d::Sprite
    {
    public:
        static ScoreProgressStart* createWithPercent(float percent);
        //static ScoreProgressStart* createWithSwitchFlag(bool flag);
        CREATE_FUNC(ScoreProgressStart);
        ~ScoreProgressStart(); 
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
        ScoreProgressStart();
        void setStartPercent(float percent);
        void setStartSpriteShader(const std::string& shader_path);
        bool isNeedTurnOn(float percent);
    private:
        float start_percent_ = 0.0f;
        bool start_on_flag_ = true;
    };
}
#endif