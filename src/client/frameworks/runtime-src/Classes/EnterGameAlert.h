//*******************************************************************************
//类名称   : EnterGameAlert
//功能     : <进入游戏场景前的面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _ENTER_GAME_ALERT_H_
#define _ENTER_GAME_ALERT_H_
//#include "GameBaseAlert.h"
#include "BubbleSecondConstant.h"
#include "ui\UIButton.h"
#include "ui\UITextBMFont.h"
namespace bubble_second {
    class EnterGameAlert : public cocos2d::Node
    {
    public:
        static EnterGameAlert* create(int cell_numble, int level, const StageType& type);
        ~EnterGameAlert();
        //void onExit() override;
        //void setBeginCallback(const cocos2d::ccMenuCallback& callback);
    private:
        EnterGameAlert();
        bool init(int cell_numble, int level, const StageType& type);
        void loadView();
        void initStartButton(int cell_numble, int level);
        void initCloseButton();
        void initStageNumbleLabel(int level);
        void initStageTypeLabel(const StageType& type);
        //void initEnterProps();
    private:
        //cocos2d::ui::Button* getStartButton();
        cocos2d::ui::Button* getCloseButton();
        //cocos2d::ui::TextBMFont* getStageNumbleLabel();
        cocos2d::ui::TextBMFont* getStageTypeLabel();
        //void addBackground();
        //void addTopLabel(int level);
        //void addStageTypeLabel(const StageType& type);
        //void addCharactor();
        //void initPropsShow();
        //void addButtonItem();
    private:
        //cocos2d::MenuItem* cancel_item_ = nullptr;
        //cocos2d::MenuItem* begin_item_ = nullptr;
        cocos2d::Node* alert_csb_node_ = nullptr;
		cocos2d::Node* start_node_ = nullptr;
    };
}
#endif //_ENTER_GAME_ALERT_H_