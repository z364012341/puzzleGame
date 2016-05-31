--
-- Author: 黄泽昊
-- 作用: 拼图游戏的开始界面
local PuzzleStartScene = class("PuzzleStartScene", function ()
    return cc.Layer:create();
end)
local PuzzleSelectedScene = require(PUZZLE_SELECTED_SCENE_PATH);
local PuzzleStoreAlert = require(PUZZLE_STORE_ALERT_PATH);
local LAYER_CSB_PATH = "PuzzleStartLayer.csb";
local START_NODE_NAME = "start_button_node";
local STORE_BUTTON_NAME = "Button_1";
local NEWBIE_GIFT_BUTTON_NAME = "Button_2";

function PuzzleStartScene:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzleStartScene:create()
    scene:addChild(layer)
    return scene
end
function PuzzleStartScene:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self:loadCSB();
end
function PuzzleStartScene:loadCSB()
    self.alert_ = nil;
    self.csb_node_ = cc.CSLoader:createNode(LAYER_CSB_PATH);
    self:addChild(self.csb_node_);
    self.csb_node_:getChildByName(STORE_BUTTON_NAME):addClickEventListener(function ( ... )
        self.alert_ = PuzzleStoreAlert:create();
        self.alert_:setPosition(GlobalFunction.getVisibleCenterPosition());
        self:addChild(self.alert_);
    end);
    local start_button = bs.GameStartButton:createButtonStartForm()
    self.csb_node_:getChildByName(START_NODE_NAME):addChild(start_button);
    self.csb_node_:getChildByName(START_NODE_NAME):setPositionY(cc.Director:getInstance():getVisibleSize().height*0.24)
    start_button:getStartButton():addClickEventListener(function ( ... )
        cc.Director:getInstance():replaceScene(PuzzleSelectedScene:createScene());
    end);
    self:updateNewbieGiftVisible();
    self.csb_node_:getChildByName(NEWBIE_GIFT_BUTTON_NAME):addClickEventListener(function ( ... )
        self.alert_ = bs.PuzzleStoreItemFactory:getInstance():createNewbieAlert();
        self.alert_:getChildByName("Button_1"):addClickEventListener(function ( ... )
            self:getEventDispatcher():dispatchCustomEvent(EVENT_CONTINUE);
        end);
        self.alert_:setPosition(GlobalFunction.getVisibleCenterPosition());
        self:addChild(self.alert_);
    end);
    self.csb_node_:getChildByName(NEWBIE_GIFT_BUTTON_NAME):setPositionY(cc.Director:getInstance():getVisibleSize().height*0.5)
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_)

    self.csb_node_:getChildByName("pintu01_2"):setPositionY(cc.Director:getInstance():getVisibleSize().height*0.8);
end
function PuzzleStartScene:updateNewbieGiftVisible( )
   self.csb_node_:getChildByName(NEWBIE_GIFT_BUTTON_NAME):setVisible(bs.UserDataManager:getInstance():canBuyNewbieGift());
end
function PuzzleStartScene:onEnter()
    self.listener_ = {};

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_CONTINUE, function ( ... )
        self.alert_:removeFromParent();
        self.alert_ = nil;
    end));

    table.insert(self.listener_, cc.EventListenerCustom:create("event_buy_props_pay_success", function ( ... )
        self:getEventDispatcher():dispatchCustomEvent(EVENT_CONTINUE);
        self:updateNewbieGiftVisible();
    end));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 2);
    end


    local function onKeyReleased(keyCode, event)
        if keyCode == cc.KeyCode.KEY_BACK then
            cc.Director:getInstance():endToLua();
        end
    end
    local listener = cc.EventListenerKeyboard:create()
    listener:registerScriptHandler(onKeyReleased, cc.Handler.EVENT_KEYBOARD_RELEASED)

    self:getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self)
end
function PuzzleStartScene:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleStartScene