#include "PuzzleStoreItemFactory.h"
#include "cocostudio\CocoStudio.h"
#include "XMLTool.h"
#include "ui\UITextBMFont.h"
#include "ui\UIButton.h"
#include "ui\UIScale9Sprite.h"
#include "ButtonEffectController.h"
//#include "GameJNIHelper.h"
#include "UserDataManager.h"
#include "GameAlertMask.h"
#include "GameBuyStoreMannager.h"
const std::string PUZZLE_STORE_ITEM_DATA_PATH = "res/puzzleStoreItemData.plist";
const std::string PUZZLE_STORE_GIFTS_ITEM_DATA_PATH = "res/puzzleStoreGiftsItemData.plist";
const std::string PUZZLE_STORE_ITEM_CAB_PATH = "PuzzleStoreitem.csb";
const std::string PUZZLE_STORE_GIFT_ITEM_CAB_PATH = "PuzzleStoreGiftSitem.csb";
const std::string BUY_BUTTON_CAB_PATH = "PuzzleStoreItemBuyLabel.csb";
const std::string SHOWNAME_KEY = "showName";
const std::string STORE_NUMBLE_KEY = "numble";
const std::string STORE_NAME_KEY = "storeName";
const std::string STORE_DESCRIPTION_KEY = "description";
const std::string STORE_COST_KEY = "cost";
const std::string TARGET_ID_KEY = "targetID";
const std::string STORE_NUMBLE_NAME = "BitmapFontLabel_2_0";
const std::string STORE_NAME_LABEL_NAME = "BitmapFontLabel_1";
const std::string STORE_DESCRIPTION_LABEL_NAME = "BitmapFontLabel_1_0";
const std::string BUY_COST_LABEL_NAME = "numbleLabel";
const std::string BUY_BUTTON_NAME = "Button_1";
const std::string GIFT_SEARCH_NUMBLE_KEY = "search_numble";
const std::string GIFT_BIG_EYES_NUMBLE_KEY = "big_eyes_numble";
const std::string GIFT_ADD_TIME_NUMBLE_KEY = "add_time_numble";

namespace bubble_second {
    PuzzleStoreItemFactory::PuzzleStoreItemFactory()
    {
    }



    cocos2d::Node * PuzzleStoreItemFactory::createItemWithIndex(int index)
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(PUZZLE_STORE_ITEM_CAB_PATH);
        cocos2d::ValueMap data = item_data_.at(XMLTool::convertIntToString(index)).asValueMap();
        csb_node->getChildByName(data.at(SHOWNAME_KEY).asString())->setVisible(true);

        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_NUMBLE_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_NUMBLE_NAME))->setString(data.at(STORE_NUMBLE_KEY).asString());

        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_NAME_LABEL_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_NAME_LABEL_NAME))->setString(data.at(STORE_NAME_KEY).asString());

        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_DESCRIPTION_LABEL_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(STORE_DESCRIPTION_LABEL_NAME))->setString(data.at(STORE_DESCRIPTION_KEY).asString());

        cocos2d::Node* button_label_node = cocos2d::CSLoader::createNode(BUY_BUTTON_CAB_PATH);
        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(BUY_COST_LABEL_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(BUY_COST_LABEL_NAME))->setString(data.at(STORE_COST_KEY).asString());

        assert(dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName(BUY_BUTTON_NAME)));
        cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName(BUY_BUTTON_NAME));
        ButtonEffectController::setButtonZoomScale(button);
        button->getRendererNormal()->addChild(button_label_node);
        button_label_node->setPosition(cocos2d::Vec2(button->getRendererNormal()->getContentSize().width/2, button->getRendererNormal()->getContentSize().height / 2));
        button->addClickEventListener([=](cocos2d::Ref*) {
            cocos2d::ValueMap buy_data;
            buy_data[data.at(SHOWNAME_KEY).asString()] = data.at(STORE_NUMBLE_KEY).asInt();
            UserDataManager::getInstance()->setBuyPropsKeyAndNumble(buy_data);
            GameBuyStoreMannager::getInstance()->buyProps(data.at(TARGET_ID_KEY).asInt());
            //cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("event_buy_props_pay_success");
        });

        return csb_node;
    }

    cocos2d::Node * PuzzleStoreItemFactory::createGiftsItemWithIndex(int index)
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(PUZZLE_STORE_GIFT_ITEM_CAB_PATH);
        assert(csb_node);
        cocos2d::ValueMap data = gifts_item_data_.at(XMLTool::convertIntToString(index)).asValueMap();
        csb_node->getChildByName(data.at(SHOWNAME_KEY).asString())->setVisible(true);

        cocos2d::ValueMap numble_map = data.at(STORE_NUMBLE_KEY).asValueMap();
        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(GIFT_SEARCH_NUMBLE_KEY)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(GIFT_SEARCH_NUMBLE_KEY))->setString(numble_map.at(PUZZLE_SEARCH_PROP_KEY).asString());

        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(GIFT_BIG_EYES_NUMBLE_KEY)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(GIFT_BIG_EYES_NUMBLE_KEY))->setString(numble_map.at(PUZZLE_BIG_EYES_PROP_KEY).asString());

        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(GIFT_ADD_TIME_NUMBLE_KEY)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node->getChildByName(GIFT_ADD_TIME_NUMBLE_KEY))->setString(numble_map.at(PUZZLE_ADD_TIME_PROP_KEY).asString());

        cocos2d::Node* button_label_node = cocos2d::CSLoader::createNode(BUY_BUTTON_CAB_PATH);
        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(BUY_COST_LABEL_NAME)));
        dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(BUY_COST_LABEL_NAME))->setString(data.at(STORE_COST_KEY).asString());

        cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("libaokuang_1")->getChildByName(BUY_BUTTON_NAME));
        assert(button);
        ButtonEffectController::setButtonZoomScale(button);
        button->getRendererNormal()->addChild(button_label_node);
        button_label_node->setPosition(cocos2d::Vec2(button->getRendererNormal()->getContentSize().width / 2, button->getRendererNormal()->getContentSize().height / 2));
        button->addClickEventListener([=](cocos2d::Ref*) {
            UserDataManager::getInstance()->setBuyPropsKeyAndNumble(numble_map);
            GameBuyStoreMannager::getInstance()->buyProps(data.at(TARGET_ID_KEY).asInt());
            //cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("event_buy_props_pay_success");
        });
        return csb_node;
    }

    cocos2d::Node * PuzzleStoreItemFactory::createNewbieAlert()
    {
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode("NewbieGiftAlert.csb");
        assert(csb_node);
        cocos2d::ui::Button* button = dynamic_cast<cocos2d::ui::Button*>(csb_node->getChildByName("Button_1_0"));
        assert(button);
        ButtonEffectController::setButtonZoomScale(button);
        cocos2d::Node* button_label_node = cocos2d::CSLoader::createNode(BUY_BUTTON_CAB_PATH);
        assert(dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(BUY_COST_LABEL_NAME)));
        auto numble_label = dynamic_cast<cocos2d::ui::TextBMFont*>(button_label_node->getChildByName(BUY_COST_LABEL_NAME));
        numble_label->setString("0.1");
        numble_label->setScale(0.6f);
        button->getRendererNormal()->addChild(button_label_node);
        button_label_node->setPosition(cocos2d::Vec2(button->getRendererNormal()->getContentSize().width / 2, button->getRendererNormal()->getContentSize().height / 2));
        button->addClickEventListener([=](cocos2d::Ref*) {
            cocos2d::ValueMap buy_data;
            buy_data[PUZZLE_SEARCH_PROP_KEY] = 1;
            buy_data[PUZZLE_BIG_EYES_PROP_KEY] = 1;
            buy_data[PUZZLE_ADD_TIME_PROP_KEY] = 1;
            UserDataManager::getInstance()->setBuyPropsKeyAndNumble(buy_data);
            GameBuyStoreMannager::getInstance()->buyProps(PUZZLE_NEWBIE_GIFT_TARGET_ID);
            //cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("event_buy_props_pay_success");
        });
        csb_node->addChild(GameAlertMask::create(), -1);
        return csb_node;
    }

    PuzzleStoreItemFactory::~PuzzleStoreItemFactory()
    {
    }
    void PuzzleStoreItemFactory::loadItemData()
    {
        assert(cocos2d::FileUtils::getInstance()->isFileExist(PUZZLE_STORE_ITEM_DATA_PATH));
        item_data_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(PUZZLE_STORE_ITEM_DATA_PATH);  
        this->loadGiftData();
    }

    void PuzzleStoreItemFactory::loadGiftData()
    {
        assert(cocos2d::FileUtils::getInstance()->isFileExist(PUZZLE_STORE_GIFTS_ITEM_DATA_PATH));
        gifts_item_data_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(PUZZLE_STORE_GIFTS_ITEM_DATA_PATH);
    }
    int PuzzleStoreItemFactory::getItemTotal()
    {
        return item_data_.size();
    }
    int PuzzleStoreItemFactory::getGiftsItemTotal()
    {
        return gifts_item_data_.size();
    }
}