#include "GamePauseAlert.h"
#include "ButtonEffectController.h"
#include "ui\UIButton.h"
#include "GameAlertMask.h"
#include "BubbleSecondConstant.h"
#include "GameStartButton.h"
//#include "CenteredMenuItemSprite.h"
//#include "GameVolControlView.h"
const std::string GAME_PAUSE_ALERT_CSB_PATH = "GamePauseAlert.csb";
const std::string GAME_PAUSE_ALERT_REPALY_NODE = "FileNode_1";
const std::string GAME_PAUSE_ALERT_RETUREN_NODE = "returnNode";
//const std::string GAME_PAUSE_ALERT_CONTINUE_NODE = "FileNode_4";
namespace bubble_second {
    GamePauseAlert::GamePauseAlert()
    {
    }

    GamePauseAlert::~GamePauseAlert()
    {
    }

    void GamePauseAlert::setReturnCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback & callback)
    {
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(GAME_PAUSE_ALERT_RETUREN_NODE))->addTouchEventListener(callback);
    }

    bool GamePauseAlert::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create());
        this->loadView();
        return true;
    }

    void GamePauseAlert::loadView()
    {
        csb_node_ = cocos2d::CSLoader::createNode(GAME_PAUSE_ALERT_CSB_PATH);
        this->addChild(csb_node_);
        continue_button_ = GameStartButton::createButtonContinueForm();
        csb_node_->addChild(continue_button_);
        ButtonEffectController::setButtonsZoomScale(csb_node_);
    }

    void GamePauseAlert::setReplayCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback)
    {
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(GAME_PAUSE_ALERT_REPALY_NODE))->addTouchEventListener(callback);
    }

    void GamePauseAlert::setContinueCallback(const cocos2d::ui::Widget::ccWidgetClickCallback & callback)
    {
        continue_button_->addButtonClickEventListener(callback);
    }

}