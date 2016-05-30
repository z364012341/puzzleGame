//*******************************************************************************
//������   : GameDefeatBuyPropsAlert
//����     : <��Ϸʧ�ܵ�������������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_DEFEAT_BUY_PROPS_ALERT_H_
#define _GAME_DEFEAT_BUY_PROPS_ALERT_H_
#include "cocos2d.h"
#include "GameBaseAlert.h"
const std::string GAME_DEFEAT_BUY_PROPS_ALERT_NAME = "GameDefeatBuyPropsAlert";
namespace bubble_second {
    class GameDefeatBuyPropsAlert : public GameBaseAlert
    {
    public:
        CREATE_FUNC(GameDefeatBuyPropsAlert);
        ~GameDefeatBuyPropsAlert();
        //void setCancelCallback(const cocos2d::ccMenuCallback& callback);
        void setContinueCallback(const cocos2d::ccMenuCallback& callback);
    private:
        GameDefeatBuyPropsAlert();
        bool init();
        //void addBackground();
        void addTopLabel();
        void addButtonItem();
        void addPropsItem();
        void addDescriptionLabel();
    private:
        cocos2d::MenuItem* cancel_item_ = nullptr;
        cocos2d::MenuItem* continue_item_ = nullptr;
    };
}
#endif //_GAME_DEFEAT_BUY_PROPS_ALERT_H_