--
-- Author: 黄泽昊
-- 功能: 增加时间道具

local PuzzleAddTimeProp = class("PuzzleAddTimeProp", function ()
    return cc.Node:create();
end)
local PuzzlePropsBackground = require(PUZZLE_PROPS_BACKGROUND_PATH);
local PROP_ADD_TIME_PATH = "daoju3.PNG";
function PuzzleAddTimeProp:ctor()
	local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self:init();
end
function PuzzleAddTimeProp:init()
    --dump(PuzzlePropsBackground:create(EVENT_USE_ADD_TIME_PROP, ".,.", 0));
    self:addChild(PuzzlePropsBackground:create(EVENT_TOUCH_ADD_TIME_PROP));
    self:addChild(GlobalFunction.createGameSpriteWithPath(PROP_ADD_TIME_PATH));
    self.numble_show_ = bs.PropsNumbleShow:create(bs.UserDataManager:getPuzzleAddTimePropKey());
    self:addChild(self.numble_show_, 1);
end

function PuzzleAddTimeProp:onEnter()
    self.listener_ = {};

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_TOUCH_ADD_TIME_PROP, function ( event )
        if self.numble_show_:cutPropNumble() then
            self:getEventDispatcher():dispatchCustomEvent(EVENT_USE_ADD_TIME_PROP);
        end
    end));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleAddTimeProp:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleAddTimeProp