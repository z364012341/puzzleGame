#include "GameAlertMask.h"
#include "SpriteTextureController.h"
#include "SmartScaleController.h"
namespace bubble_second {
    GameAlertMask::GameAlertMask()
    {
    }


    GameAlertMask * GameAlertMask::createTransparentMask()
    {
        GameAlertMask *pRet = new(std::nothrow) GameAlertMask();
            if (pRet && pRet->initTransparentMask())
            { 
                pRet->autorelease(); 
                return pRet; 
            } 
            else
            { 
                delete pRet;
                pRet = nullptr; 
                return nullptr;
            } 
    }

    GameAlertMask::~GameAlertMask()
    {
    }

    void GameAlertMask::backgroundFadeOut(float duration, cocos2d::CallFunc * func)
    {
        layer_->runAction(cocos2d::Sequence::create(cocos2d::FadeOut::create(duration), func, nullptr));
    }

    bool bubble_second::GameAlertMask::init()
    {
        if (!this->initTransparentMask())
        {
            return false;
        }
        this->addColorLayer();
        return true;
    }
    bool GameAlertMask::initTransparentMask()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->setScale(1 / SmartScaleController::getInstance()->getFixedHeightZoom());
        this->addMaskMenu();
        return true;
    }
    void GameAlertMask::addMaskMenu()
    {
        cocos2d::Sprite* item_select = cocos2d::Sprite::create();
        item_select->setContentSize(cocos2d::Size(GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT));
        cocos2d::Sprite* item_normal = cocos2d::Sprite::create();
        item_normal->setContentSize(cocos2d::Size(GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT));
        cocos2d::MenuItemSprite* item = cocos2d::MenuItemSprite::create(item_normal, item_select);
        cocos2d::Menu* menu = cocos2d::Menu::createWithItem(item);
        menu->setPosition(cocos2d::Vec2::ZERO);
        this->addChild(menu);
    }
    void GameAlertMask::addColorLayer()
    {
        layer_ = cocos2d::LayerColor::create(cocos2d::Color4B(0, 0, 0, 180), GAME_ALERT_MASK_WIDTH, GAME_ALERT_MASK_HEIGHT);
        layer_->setPosition(-GAME_ALERT_MASK_WIDTH / 2, -GAME_ALERT_MASK_HEIGHT / 2);
        this->addChild(layer_);
    }
}