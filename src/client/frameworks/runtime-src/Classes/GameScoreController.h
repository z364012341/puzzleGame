//*******************************************************************************
//������   : GameScoreController
//����     : <��Ϸ�еĵ÷�����������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_SCORE_CONTROLLER_H_
#define _GAME_SCORE_CONTROLLER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameScoreController
    {
    public:
        GETINSTANCE_FUNC(GameScoreController);
        ~GameScoreController();
    public:
        int getEliminateCombo();
        void clear();
        //���������÷�
        void addScoreWithEliminateNumble(int numble);
        //����һ������
        void addOneCombo();
        //��������
        void eliminateComboClear();
        //���ӵ÷�
        void addScoreWithNumble(int numble);
        //������������
        void addGameTaskNumble();
        void setGameTaskNumble(int numble);
        //���������������
        void addCompletedTaskNumble();
        void setCompletedTaskNumble(int numble);
        //��ȡ��������
        int getGameTaskNumble() const;
        //��ȡ�����������
        int getCompletedTaskNumble() const;
        //��Ϸʤ��
        bool gameVictory();
        //�Ƿ�ʧ��
        bool gameDefeat();
        bool noUseBubbleCount();
        //С��ʹ������
        void setBubbleUseCount(int numble);
        void addBubbleUseCount(int numble);
        int getBubbleUseCount();
        void cutBubbleUseCount();
        void setBubbleUseCountEnable(bool flag);
        bool isBubbleUseCountEnable();
        //��ȡ����
        int getTotalScore();
        //����С���ڿ�����
        void addPrepareBubbleAirNumble();
        void cutPrepareBubbleAirNumble();
        void dispatchUpdateCompletedTaskEvent();
    private:
        //void addEventListenerCustom();
        //�ܵ÷ֳ�ʼ��
        void totalScoreClear();
        //����������ʼ��
        void gameTaskNumbleClear();
        //�������������ʼ��
        void completedTaskNumbleClear();
        //�ӷ�
        void addScore(int numble);
        //�ַ��÷��¼�
        void dispatchUpdateScoreEvent();
        void dispatchUpdateBubbleUseCount();

        bool isNoShootBubbleInAir();
    private:
        GameScoreController();
    private:
        int eliminate_combo_;
        int total_score_;
        int game_task_numble_add_;
        int game_task_numble_set_;
        int completed_task_numble_add_;
        int completed_task_numble_set_;
        int bubble_use_count_;
        bool use_count_enable_;
        int prepare_bubble_in_air_numble_;
    };
}
#endif //_GAME_SCORE_CONTROLLER_H_