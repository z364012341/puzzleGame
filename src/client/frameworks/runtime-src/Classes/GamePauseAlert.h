//*******************************************************************************
//类名称   : GamePauseAlert
//功能     : <游戏设置菜单>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_PAUSE_ALERT_H_
#define _GAME_PAUSE_ALERT_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class GameStartButton;
    class GamePauseAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GamePauseAlert);
        ~GamePauseAlert();
        void setReturnCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback);
        void setReplayCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback);
        void setContinueCallback(const cocos2d::ui::Widget::ccWidgetClickCallback& callback);
    private:
        GamePauseAlert();
        bool init();
        void loadView();

        //void addVolumeItem();
        //void addButtonItem();
        //void addBigBackground() override;
        //void addTopLabel();
    //private:
        //cocos2d::MenuItem* return_item_ = nullptr;
        //cocos2d::MenuItem* replay_item_ = nullptr;
        //cocos2d::MenuItem* continue_item_ = nullptr;
    private:
        cocos2d::Node* csb_node_ = nullptr; 
        GameStartButton* continue_button_ = nullptr;

    };
}
#endif //_GAME_PAUSE_ALERT_H_