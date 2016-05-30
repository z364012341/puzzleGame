#include "EnterGamePropsView.h"
//#include "SpriteTextureController.h"
//#include "GamePropsNumbleView.h"
#include "EnterPropsViewManager.h"
#include "cocostudio\CocoStudio.h"
#include "GameTextInfo.h"
//const std::string ENTER_GAME_PROPS_CSB = "EnterGameProps.csb";
namespace bubble_second {
    //EnterGamePropsView * EnterGamePropsView::create(cocos2d::Sprite * props)
    //{
    //    EnterGamePropsView *pRet = new(std::nothrow) EnterGamePropsView();
    //    if (pRet && pRet->init(props))
    //    {
    //        pRet->autorelease();
    //        return pRet;
    //    }
    //    else
    //    {
    //        delete pRet;
    //        pRet = NULL;
    //        return NULL;
    //    }
    //}
    EnterGamePropsView::EnterGamePropsView()
    {
    }

    EnterGamePropsView::~EnterGamePropsView()
    {
    }

    bool EnterGamePropsView::init(const std::string & csb_path)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->loadView(csb_path);
        return true;
    }

    void EnterGamePropsView::setCostLabelStringWithKey(const std::string& key)
    {
        cost_label_->setString(GameTextInfo::getInstance()->getCommodityCoinValueWithKey(key).asString());
    }

    void EnterGamePropsView::loadView(const std::string & csb_path)
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(csb_path);
        this->addChild(csb_node);
        cost_label_ = dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName("cost_node")->getChildByName("cost_label"));
        assert(cost_label_);
        selected_sprite_ = dynamic_cast<cocos2d::Sprite*>(csb_node->getChildByName("cost_node")->getChildByName("selected_sprite"));
        assert(selected_sprite_);
        button_ = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("background_node")->getChildByName("Button"));
        assert(button_);
        button_->addTouchEventListener([=](cocos2d::Ref* target, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                selected_sprite_->setVisible(!selected_sprite_->isVisible());
                EnterPropsViewManager::getInstance()->setPropsSwitch(this->getName(), selected_sprite_->isVisible());
            }
        });
    }


    //void EnterGamePropsView::addMenuCallback(const cocos2d::ccMenuCallback & callback)
    //{
    //    menu_callback_ = callback;
    //}

    //bool bubble_second::EnterGamePropsView::init(cocos2d::Sprite* props)
    //{
    //    this->addBackground();
    //    this->addPropsTexture(props);
    //    //this->addPropsNumbleView();
    //    return true;
    //}

    //void EnterGamePropsView::addBackground()
    //{
    //    cocos2d::Sprite* normal_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_PROPS_VIEW_BACKGROUND_PATH);
    //    cocos2d::Sprite* select_sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(ENTER_GAME_PROPS_VIEW_BACKGROUND_PATH);
    //    background_ = cocos2d::MenuItemSprite::create(normal_sp, select_sp);
    //    cocos2d::Menu* menu = cocos2d::Menu::createWithItem(background_);
    //    menu->setPosition(cocos2d::Vec2::ZERO);
    //    this->addChild(menu);

    //    this->addChild(cocos2d::CSLoader::createNode(ENTER_GAME_PROPS_CSB));
    //}

    //void EnterGamePropsView::addPropsTexture(cocos2d::Sprite * props)
    //{
    //    //props->setContentSize(background_->getContentSize());
    //    //cocos2d::Rect rect = background_->getBoundingBox();
    //    //props->setPosition(rect.size.width/2, rect.size.height/2);;
    //    this->addChild(props);
    //}

    //void EnterGamePropsView::addPropsNumbleView()
    //{
    //    props_numble_view_ = GamePropsNumbleView::create();
    //    //cocos2d::Rect rect = background_->getBoundingBox();
    //    props_numble_view_->setPosition(50.0, -40.0);
    //    this->addChild(props_numble_view_);
    //    background_->setCallback([=](cocos2d::Ref* ref) {
    //        props_numble_view_->selected(); 
    //        //EnterPropsViewManager::getInstance()->setPropsSwitch(this->getName(), !EnterPropsViewManager::getInstance()->getPropsSwitchEnable(this->getName()));
    //        if (menu_callback_)
    //        {
    //            menu_callback_(ref);
    //        }
    //    });
    //}

    //void EnterGamePropsView::addCostView(const cocos2d::Value& value)
    //{
    //    props_value_ = value;
    //    cocos2d::Sprite* coin = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_COIN_PATH);
    //    coin->setPosition(-50.0f, -80.0f);
    //    this->addChild(coin);

    //    cocos2d::Label* cost_label = cocos2d::Label::createWithSystemFont(props_value_.asString(), "", ENTER_GAME_ALERT_PROPS_LABEL_FONTSIZE);
    //    cost_label->setPosition(10.0f, coin->getPositionY()+5);
    //    this->addChild(cost_label);
    //}

}