//*******************************************************************************
//������   : GameVoluemSwitch
//����     : <��Ϸ���ò˵���������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_VOLUEM_SWITCH_H_
#define _GAME_VOLUEM_SWITCH_H_
#include "cocos2d.h"
namespace bubble_second {
    class SimpleControlSwitch;
    class GameVoluemSwitch : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameVoluemSwitch);
        ~GameVoluemSwitch();
        void setSwitchState(bool flag);
        void setMenuCallback(const cocos2d::ccMenuCallback& callback);
        bool getSwitchState();
    private:
        GameVoluemSwitch();
        bool init();
    private:
        SimpleControlSwitch* vol_switch_ = nullptr;
    };
}
#endif //_GAME_VOLUEM_SWITCH_H_