//*******************************************************************************
//������   : GameSettingAlert
//����     : <��Ϸ�������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_SETTING_ALERT_H_
#define _GAME_SETTING_ALERT_H_
#include "GameBaseAlert.h"
#include "ui\UITextField.h"
namespace bubble_second {
    class GameSettingAlert : public GameBaseAlert
    {
    public:
        CREATE_FUNC(GameSettingAlert);
        virtual ~GameSettingAlert();
        void onExit() override;
    private:
        GameSettingAlert();
        bool init();
        void addVolumeItem();
        void addTopLabel();
        void addNicknameInput();
        void addHelpInfo();
        void cancelButtonCallback(cocos2d::Ref* ref) override;
    private:
        cocos2d::ui::TextField* nickname_textfield = nullptr;
    };
}
#endif //_GAME_SETTING_ALERT_H_