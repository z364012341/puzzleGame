//*******************************************************************************
//������   : ScoreMenu
//����     : <��Ϸ���������ķ���������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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
        //����������
        void increaseProgressTimer();
        //����Ŀ��ٷֱ�, �����˼�ʱ���ͻ�ͣ
        void setGoalPercent(float percent);
        float getGoalPercent();
        void setLastScore(int last_score);
        int getLastScore();
        bool isEqualLastScore(int score);
        //�ж��Ƿ������Ŀ��ٷֱ�
        bool isCompletedGoalPercent(float percent);
        //�ж��Ƿ��˵�λ
        //bool isCompletedBack(float percent);
        StartNumbleModule getStartNumbleModule();
        void controlStartLight(float percent);
        //���ý�����ʵ�ʵĽ���
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
        //��������
        cocos2d::Map<std::string, ScoreProgressStar*> start_sprite_map_;
    };
}
#endif 