--
-- Author: 黄泽昊
-- 作用: 拼图游戏的商城面板

local PuzzleStoreAlert = class("PuzzleStoreAlert", function ()
    return cc.Node:create();
end)
local STORE_CSB_PATH = "PuzzleStoreAlert.csb";
local CLOSE_BUTTON_NAME = "Button_1";
local PROPS_LISTVIEW_NAME = "ListView_1";
local GIFTS_LISTVIEW_NAME = "ListView_2";
local PROPS_STORE_MENU_NAME = "props";
local GIFTS_STORE_MENU_NAME = "gift";
local SELECTED_STORE_MENU_NAME = "Button_2";
function PuzzleStoreAlert:ctor()
    self:init();
end
function PuzzleStoreAlert:init()
    self:loadCSB();
    self:initPropsListView();
    self:initGiftListView();
    self:initSelectedTypeButton();
    self:addMaskBackground();
end

function PuzzleStoreAlert:loadCSB()
    self.csb_node_ = cc.CSLoader:createNode(STORE_CSB_PATH);
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_)
    self:addChild(self.csb_node_);
    self.csb_node_:getChildByName(CLOSE_BUTTON_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_CONTINUE);
    end);
    --self:initPropsListView();
end
function PuzzleStoreAlert:initPropsListView()
    self.props_store_ = self.csb_node_:getChildByName(PROPS_STORE_MENU_NAME);
    local listView = self.props_store_:getChildByName(PROPS_LISTVIEW_NAME);
    listView:setScrollBarEnabled(false);
    --dump(bs.PuzzleStoreItemFactory:getInstance():getItemTotal());
    for i = 1,bs.PuzzleStoreItemFactory:getInstance():getItemTotal() do
        local custom_item = ccui.Layout:create()
        local layer = bs.PuzzleStoreItemFactory:getInstance():createItemWithIndex(i-1);
        --layer:setScale(0.8);
        custom_item:setContentSize(layer:getContentSize())
        custom_item:addChild(layer);
        listView:pushBackCustomItem(custom_item)
    end


end
function PuzzleStoreAlert:initGiftListView()
    self.gift_store_ = self.csb_node_:getChildByName(GIFTS_STORE_MENU_NAME);
    local listView = self.gift_store_:getChildByName(GIFTS_LISTVIEW_NAME);
    listView:setScrollBarEnabled(false);
    --dump(bs.PuzzleStoreItemFactory:getInstance():getItemTotal());
    for i = 1,bs.PuzzleStoreItemFactory:getInstance():getGiftsItemTotal() do
        local custom_item = ccui.Layout:create()
        local layer = bs.PuzzleStoreItemFactory:getInstance():createGiftsItemWithIndex(i-1);
        --layer:setScale(0.8);
        custom_item:setContentSize(layer:getContentSize())
        custom_item:addChild(layer);
        listView:pushBackCustomItem(custom_item)
    end
end
function PuzzleStoreAlert:initSelectedTypeButton()
    local button = self.csb_node_:getChildByName(SELECTED_STORE_MENU_NAME);
    button:addClickEventListener(function ( ... )
        self.gift_store_:setVisible(not self.gift_store_:isVisible());
        self.props_store_:setVisible(not self.props_store_:isVisible());
    end);
end
function PuzzleStoreAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), -1);
end

return PuzzleStoreAlert