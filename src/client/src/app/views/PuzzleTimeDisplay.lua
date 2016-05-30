--
-- Author: 黄泽昊
-- 功能: 时间显示组件

local PuzzleTimeDisplay = class("PuzzleTimeDisplay", function ()
    return cc.Node:create();
end)
local TIME_DISPLAY_CSB_PATH = "PuzzleTimeDisplay.csb";
local HOUR_LABEL_NAME = "hourLabel";
local MINUTE_LABEL_NAME = "minuteLabel";

function PuzzleTimeDisplay:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
    	end
    end
    self:registerScriptHandler(onNodeEvent);
    self:loadCsb();
end

function PuzzleTimeDisplay:loadCsb()
    local csb_node = cc.CSLoader:createNode(TIME_DISPLAY_CSB_PATH);
    self:addChild(csb_node);
    self.hour_label_ = csb_node:getChildByName(HOUR_LABEL_NAME);
    self.minute_label_ = csb_node:getChildByName(MINUTE_LABEL_NAME);
end
function PuzzleTimeDisplay:setTimeString( time )
    self.hour_label_:setString(string.format("%02d",math.floor(time / 60)));
    self.minute_label_:setString(string.format("%02d",math.floor(time % 60)));
end
function PuzzleTimeDisplay:onEnter()
    self.listener_ = {}
    local function updateTimeLabel( event )
        local time = GlobalFunction.getCustomEventUserData(event);
        self:setTimeString(time);
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_UPDATE_TIME_LABEL, updateTimeLabel));
    for _, listener in ipairs(self.listener_) do
    	self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleTimeDisplay:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
    	eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleTimeDisplay