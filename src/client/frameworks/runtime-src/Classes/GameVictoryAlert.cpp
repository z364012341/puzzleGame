#include "GameVictoryAlert.h"
//#include "SpriteTextureController.h"
//#include "CenteredMenuItemSprite.h"
//#include "GameTextInfo.h"  
//#include "GameSamsung.h"
#include "ButtonEffectController.h"
#include "GameAlertMask.h"
#include "ui\UIButton.h"
#include "ui\UITextBMFont.h"
#include "XMLTool.h"
#include "StageNumbleBoardController.h"
const std::string GAME_VICTORY_ALERT_CSB_PATH = "GameVictoryAlert.csb";
const std::string GAME_VICTORY_ALERT_SCORE_LABEL_NAME = "BitmapFontLabel_10_0";
const std::string GAME_VICTORY_ALERT_STAGE_LABEL_NODE_NAME = "FileNode_4";
const std::string ALERT_NEXT_NODE_NAME = "nextNode";
const std::string ALERT_NEXT_BUTTON_NAME = "Button_1";
const std::string ALERT_REPLAY_NODE_NAME = "replayNode";
const std::string ALERT_STAR_NODE_1_NAME = "star_1";
const std::string ALERT_STAR_NODE_2_NAME = "star_2";
const std::string ALERT_STAR_NODE_3_NAME = "star_3";
//const std::string ALERT_REPLAY_BUTTON_NAME = "Button_1";
namespace bubble_second {
    GameVictoryAlert::GameVictoryAlert()
    {
    }

    GameVictoryAlert::~GameVictoryAlert()
    {
    }

    GameVictoryAlert * bubble_second::GameVictoryAlert::create(int level, int score, int start_numble)
    {
        GameVictoryAlert *pRet = new(std::nothrow) GameVictoryAlert();
        if (pRet && pRet->init(level, score, start_numble))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    bool GameVictoryAlert::init(int level, int score, int start_numble)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create());
        this->loadView();
        this->initTopLabel(level);
        this->initScoreLabel(score);
        this->initStart(start_numble);
        return true;
    }

    void GameVictoryAlert::initTopLabel(int numble)
    {
        //ÎÄ×Ö
        StageNumbleBoardController::getInstance()->loadView(csb_node_->getChildByName(GAME_VICTORY_ALERT_STAGE_LABEL_NODE_NAME), numble);
    }

    void GameVictoryAlert::initScoreLabel(int score)
    {
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node_->getChildByName(GAME_VICTORY_ALERT_SCORE_LABEL_NAME))->setString(XMLTool::convertIntToString(score));
    }

    void GameVictoryAlert::initStart(int start_numble)
    {
        if (start_numble < 3)
        {
            csb_node_->getChildByName(ALERT_STAR_NODE_3_NAME)->setVisible(false);
        } 
        if (start_numble < 2)
        {
            csb_node_->getChildByName(ALERT_STAR_NODE_2_NAME)->setVisible(false);
        }
        if (start_numble < 1)
        {
            csb_node_->getChildByName(ALERT_STAR_NODE_1_NAME)->setVisible(false);
        }
    }

    void GameVictoryAlert::loadView()
    {
        csb_node_ = cocos2d::CSLoader::createNode(GAME_VICTORY_ALERT_CSB_PATH);
        this->addChild(csb_node_);
        ButtonEffectController::setButtonsZoomScale(csb_node_);
    }

    void GameVictoryAlert::setNextCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback)
    {
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(ALERT_NEXT_NODE_NAME)->getChildByName(ALERT_NEXT_BUTTON_NAME))->addTouchEventListener(callback);
    }

    void GameVictoryAlert::setReplayCallback(const cocos2d::ui::Widget::ccWidgetTouchCallback& callback)
    {
        dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(ALERT_REPLAY_NODE_NAME))->addTouchEventListener(callback);
    }

}