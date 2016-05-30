//*******************************************************************************
//������   : UserDiamondInfoBoard
//����     : <��Ϸ�ؿ����������שʯ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _USER_DIAMOND_INFO_BOARD_H_
#define _USER_DIAMOND_INFO_BOARD_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class UserDiamondInfoBoard : public cocos2d::Node
    {
    public:
        CREATE_FUNC(UserDiamondInfoBoard);
        ~UserDiamondInfoBoard();
    private:
        UserDiamondInfoBoard();
        bool init();
        void playRandomTimeAnimation();
    private:
        cocostudio::Armature* armature_ = nullptr;
    };
}
#endif//_USER_DIAMOND_INFO_BOARD_H_