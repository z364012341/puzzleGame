//*******************************************************************************
//������   : GameJNIHelper
//����     : <>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_JNI_HELPER_H_
#define _GAME_JNI_HELPER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameJNIHelper
    {
    public:
        GETINSTANCE_FUNC(GameJNIHelper);
        ~GameJNIHelper();
        void payWithTargetID(int targetID);
    private:
        GameJNIHelper();

    };
}
#endif