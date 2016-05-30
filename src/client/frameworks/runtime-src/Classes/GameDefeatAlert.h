//*******************************************************************************
//������   : GameDefeatAlert
//����     : <��Ϸʧ�ܵ������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_DEFEAT_ALERT_H_
#define _GAME_DEFEAT_ALERT_H_
#include "cocos2d.h"
#include "GameBaseAlert.h"
namespace bubble_second {
    class GameDefeatAlert : public GameBaseAlert
    {
    public:
        //CREATE_FUNC(GameDefeatAlert);
        static GameDefeatAlert* createWithLevelNumble(int numble);
        ~GameDefeatAlert();
        void setReplayCallback(const cocos2d::ccMenuCallback& callback);
        //void setCancelCallback(const cocos2d::ccMenuCallback& callback);
    private:
        GameDefeatAlert();
        bool initWithWithLevelNumble(int numble);
        //void addBackground();
        void addButtonItem();
        void addDefeatCharactor();
        void addTopLabel(int numble);
    private:
        cocos2d::MenuItem* replay_item_ = nullptr;
        cocos2d::MenuItem* store_item_ = nullptr;
        cocos2d::MenuItem* cancel_item_ = nullptr;
    };
}
#endif //_GAME_DEFEAT_ALERT_H_