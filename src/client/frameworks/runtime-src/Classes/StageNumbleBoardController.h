//*******************************************************************************
//������   : GameScoreController
//����     : <�ؿ�����������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _Stage_Numble_Board_Controller_H_
#define _Stage_Numble_Board_Controller_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class StageNumbleBoardController
    {
    public:
        GETINSTANCE_FUNC(StageNumbleBoardController);
        ~StageNumbleBoardController();
        void loadView(cocos2d::Node* node, int numble);
    private:
        StageNumbleBoardController();
    };
}
#endif//_Stage_Numble_Board_Controller_H_ 