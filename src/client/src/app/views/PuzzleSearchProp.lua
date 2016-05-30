--
-- Author: 黄泽昊
-- 功能: 答案搜索道具

local PuzzleSearchProp = class("PuzzleSearchProp", function ()
    return cc.Node:create();
end)
local PuzzlePropsBackground = require(PUZZLE_PROPS_BACKGROUND_PATH);
local PuzzlePropCoolingTimerComponent = require(PUZZLE_PROP_COOLING_TIMER_COMPONENT_PATH);
local PROP_SEARCH_PATH = "daoju1.PNG";
local PROP_SEARCH_COOLING_GRAY_PATH = "search_gray.png";
local PROP_SEARCH_TIME = 10;
function PuzzleSearchProp:ctor()
	local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    -- self.selfisCooling_ = false;
    self:init();
end
function PuzzleSearchProp:init()
    --EVENT_TOUCH_SEARCH_PROP
    self.isCooling_ = false;
    self:addChild(PuzzlePropsBackground:create(EVENT_TOUCH_SEARCH_PROP));
    self:addChild(GlobalFunction.createGameSpriteWithPath(PROP_SEARCH_PATH));
    self.numble_show_ = bs.PropsNumbleShow:create(bs.UserDataManager:getPuzzleSearchPropKey());
    --self.numble_show_:setPropNumble(1);
    self:addChild(self.numble_show_, 1);
end
function PuzzleSearchProp:propCoolDown()
    if self.isCooling_ then
        return
    end
    self.isCooling_ = true;
    self:runAction(cc.Sequence:create(cc.DelayTime:create(PROP_SEARCH_TIME), cc.CallFunc:create(function ()
        self.isCooling_ = false;
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_END_SEARCH_PROP);
    end), nil));

    --注意一定要先运行动作在发送消息, 因为播放动画会暂停
    --cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_USE_SEARCH_PROP);
end
function PuzzleSearchProp:onEnter()
    self.listener_ = {};

    -- table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_SEARCH_PROP, function ( event )
	   --  local timer = PuzzlePropCoolingTimerComponent:create(PROP_SEARCH_COOLING_GRAY_PATH, PROP_SEARCH_TIME);
	   --  timer:setPosition(cc.p(-3, 4))
	   --  self:addChild(timer);
    --     self:propCoolDown();
    -- end));

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_TOUCH_SEARCH_PROP, function ( event )
        if self.isCooling_ == true then
            return;
        end
        if self.numble_show_:cutPropNumble() then
            local timer = PuzzlePropCoolingTimerComponent:create(PROP_SEARCH_COOLING_GRAY_PATH, PROP_SEARCH_TIME);
            timer:setPosition(cc.p(-3, 4))
            self:addChild(timer);
            self:propCoolDown();
            self:getEventDispatcher():dispatchCustomEvent(EVENT_USE_SEARCH_PROP);
        end
    end));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleSearchProp:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleSearchProp