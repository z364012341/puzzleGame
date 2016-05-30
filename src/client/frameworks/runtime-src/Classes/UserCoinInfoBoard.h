//*******************************************************************************
//类名称   : UserCoinInfoBoard
//功能     : <游戏关卡场景上面的金币面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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