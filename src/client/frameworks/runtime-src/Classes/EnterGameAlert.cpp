#include "EnterGameAlert.h"
#include "SpriteTextureController.h"
#include "GameTextInfo.h"
#include "GameStartButton.h"
#include "GameScene.h"
#include "EnterPropsViewManager.h"
#include "cocostudio/CocoStudio.h"
#include "GameAlertMask.h"
#include "ButtonEffectController.h"
#include "ui\UIScale9Sprite.h"
#include "StageNumbleBoardController.h"
const std::string ENTER_GAME_ALERT_CSB = "EnterGameAlert.csb";
//const std::string START_BUTTON_TOP_CSB = "GameStartMenuTop.csb";
//const std::string START_BUTTON_BOTTOM_CSB = "GameStartMenuBottom.csb";
//const std::string START_BUTTON_CLIPPINT_STENCIL_PATH = "startBubbleBG1.png";
const std::string ENTER_GAME_ALERT_START_NODE_NAME = "startMenuNode";
//const std::string ENTER_GAME_ALERT_START_BUTTON_NAME = "startButton";
const std::string ENTER_GAME_ALERT_CLOSE_BUTTON_NAME = "closeButton";
const std::string ENTER_GAME_ALERT_STAGE_NUMBLE_BOARD_NAME = "stageNumbleBoard";
const std::string ENTER_GAME_ALERT_STAGE_TYPE_LABEL_NAME = "stageTypeLabel";
const cocos2d::Vec2 COMMODITY_NODE_POS(-5.0f, -238.7f);
namespace bubble_second {
    EnterGameAlert * EnterGameAlert::create(int cell_numble, int level, const StageType & type)
    {
        EnterGameAlert *pRet = new(std::nothrow) EnterGameAlert();
        if (pRet && pRet->init(cell_numble, level, type))
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
    EnterGameAlert::EnterGameAlert()
    {
    }

    EnterGameAlert::~EnterGameAlert()
    {
    }

    //void EnterGameAlert::onExit()
    //{
    //    GameBaseAlert::onExit();
    //    cocos2d::Director::getInstance()->getTextureCache()->removeUnusedTextures();
    //}

    //void EnterGameAlert::setBeginCallback(const cocos2d::ccMenuCallback & callback)
    //{
    //    begin_item_->setCallback(callback);
    //}
    bool EnterGameAlert::init(int cell_numble, int level, const StageType & type)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addChild(GameAlertMask::create());
        this->loadView();
        this->initStartButton(cell_numble, level);
        this->initCloseButton();
        this->initStageNumbleLabel(level);
        this->initStageTypeLabel(type);
        cocos2d::Node* node = EnterPropsViewManager::getInstance()->createEnterPropsAlert();
        node->setPosition(COMMODITY_NODE_POS);
        this->addChild(node);
        return true;
    }

    void EnterGameAlert::loadView()
    {
        alert_csb_node_ = cocos2d::CSLoader::createNode(ENTER_GAME_ALERT_CSB);
        this->addChild(alert_csb_node_);
        ButtonEffectController::setButtonsZoomScale(alert_csb_node_);
    }

    void EnterGameAlert::initStartButton(int cell_numble, int level)
    {
        GameStartButton* button = GameStartButton::createButtonStartForm();
		alert_csb_node_->getChildByName(ENTER_GAME_ALERT_START_NODE_NAME)->addChild(button);
		button->addButtonClickEventListener([=](Ref* target) {
		    //if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
		    //{
		        cocos2d::Scene* scene = GameScene::createScene(cell_numble, level);
		        cocos2d::Director::getInstance()->replaceScene(scene);
		    //}
		});
    }

    void bubble_second::EnterGameAlert::initCloseButton()
    {
        cocos2d::ui::Button* button = this->getCloseButton();
        button->addTouchEventListener([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                this->removeFromParent();
            }
        });
    }

    void EnterGameAlert::initStageNumbleLabel(int level)
    {
        StageNumbleBoardController::getInstance()->loadView(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_STAGE_NUMBLE_BOARD_NAME), level);
    }

    void EnterGameAlert::initStageTypeLabel(const StageType & type)
    {
        this->getStageTypeLabel()->setString(GameTextInfo::getInstance()->getTextInfoWithStageType(type));
    }

    cocos2d::ui::Button * bubble_second::EnterGameAlert::getCloseButton()
    {
        return dynamic_cast<cocos2d::ui::Button*>(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_CLOSE_BUTTON_NAME));
    }

    cocos2d::ui::TextBMFont * EnterGameAlert::getStageTypeLabel()
    {
        return dynamic_cast<cocos2d::ui::TextBMFont*>(alert_csb_node_->getChildByName(ENTER_GAME_ALERT_STAGE_TYPE_LABEL_NAME));
    }
}