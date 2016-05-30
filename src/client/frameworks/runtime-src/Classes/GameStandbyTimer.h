//*******************************************************************************
//������   : WindmillBubble
//����     : <������ʱ��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _Game_Standby_Timer_H_
#define _Game_Standby_Timer_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameStandbyTimer : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameStandbyTimer);
        ~GameStandbyTimer();
    private:
        GameStandbyTimer();
        bool init();
        void addTouchEventListener();
        void timerBegin();
        //void addClockNumble();
        void clearClockNumble();
        void clockGoing();
        //bool isClockRang();
    private:
        //int clock_numble_;
    };
}
#endif // _Game_Standby_Timer_H_