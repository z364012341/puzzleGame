//*******************************************************************************
//������   : GameShareButton
//����     : <��Ϸ����ť>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_SHARE_BUTTON_H_
#define _GAME_SHARE_BUTTON_H_
#include "cocos2d.h"
//#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameShareButton : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameShareButton);
        ~GameShareButton();
    private:
        GameShareButton();
        bool init();
    };
}
#endif //_GAME_SHARE_BUTTON_H_