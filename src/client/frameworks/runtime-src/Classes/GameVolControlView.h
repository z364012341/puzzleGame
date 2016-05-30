//*******************************************************************************
//������   : GameVolControlView
//����     : <�����������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_VOL_CONTROL_VIEW_H_
#define _GAME_VOL_CONTROL_VIEW_H_
#include "cocos2d.h"
namespace bubble_second {
    class GameVoluemSwitch;
    class GameVolControlView : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameVolControlView);
        ~GameVolControlView();
        void onExit() override;
    private:
        GameVolControlView();
        bool init();
        void addVolumeSwitch();
    private:
        GameVoluemSwitch* effect_switch_ = nullptr;
        GameVoluemSwitch* music_switch_ = nullptr;
    };
}
#endif //_GAME_VOL_CONTROL_VIEW_H_