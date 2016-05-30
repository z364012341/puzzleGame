//*******************************************************************************
//������   : UserCoinInfoBoard
//����     : <��Ϸ�ؿ���������Ľ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _USER_COIN_INFO_BOARD_H_
#define _USER_COIN_INFO_BOARD_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
	class UserCoinInfoBoard : public cocos2d::Node
	{
	public:
		CREATE_FUNC(UserCoinInfoBoard);
		~UserCoinInfoBoard();
	private:
		UserCoinInfoBoard();
		bool init();
        void playRandomTimeAnimation();
    private:
        cocostudio::Armature* armature_ = nullptr;
	};
}
#endif //_USER_COIN_INFO_BOARD_H_