--
-- Author: 黄泽昊
-- 功能: 失败倒计时组件

local PuzzleDefeatCountdownComponent = class("PuzzleDefeatCountdownComponent", function (game_time)
    return cc.Node:create();
end)
local ADD_TIME_NUMBLE = 20;
local ANIMATION_TOTAL_TIME = 2.91;
local ANIMATION_DELAYTIME = 0.83;
local ANIMATION_ADD_TOTAL_TIME = 1.41
local ANIMATION_PER_ADD_DELAYTIME = ANIMATION_ADD_TOTAL_TIME / ADD_TIME_NUMBLE;
function PuzzleDefeatCountdownComponent:ctor(game_time)
    -- dump(game_time);
	self:setInitailTime(game_time);
    --self.prop_add_time_ = 0
    self:setRemainTime(self:getInitailTime());
   	local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
end
function PuzzleDefeatCountdownComponent:beginCountDown(  )
    self:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1), cc.CallFunc:create(function ()
        self:setRemainTime(self:getRemainTime() -1);
        --self:getEventDispatcher():dispatchEvent(GlobalFunction.createCustomEvent(EVENT_UPDATE_TIME_LABEL, self.remain_time_));
        self:updateTimeLabel();
        if self:getRemainTime() == 0 then
            self:stopAllActions();
            cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUZZLE_GAME_DEFEAT);
        end
    end), nil)));
end
function PuzzleDefeatCountdownComponent:getInitailTime()
    return self.initail_time_;
end
function PuzzleDefeatCountdownComponent:setInitailTime(time)
    self.initail_time_ = time;
end
function PuzzleDefeatCountdownComponent:getTimeConsuming()
	return self:getInitailTime() - self:getRemainTime();
end
function PuzzleDefeatCountdownComponent:getRemainTime()
	return self.remain_time_;
end
function PuzzleDefeatCountdownComponent:setRemainTime(time)
    self.remain_time_ = time;
end
function PuzzleDefeatCountdownComponent:addOneSecond()
    self:setRemainTime(self:getRemainTime() + 1);
    self:updateTimeLabel();
end
function PuzzleDefeatCountdownComponent:updateTimeLabel()
    self:getEventDispatcher():dispatchEvent(GlobalFunction.createCustomEvent(EVENT_UPDATE_TIME_LABEL, self:getRemainTime()));
end
function PuzzleDefeatCountdownComponent:onEnter()
	self:updateTimeLabel();

    self.begin_listener_ = cc.EventListenerCustom:create(EVENT_PUZZLE_TOUCH, function (event)
        self:beginCountDown();
        self:getEventDispatcher():removeEventListener(self.begin_listener_);
    end);
    self:getEventDispatcher():addEventListenerWithFixedPriority(self.begin_listener_, 1);


    self.listener_ = {};
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_ADD_TIME_PROP, function ( event )
        local scheduler, numble = cc.Director:getInstance():getScheduler(), 0;
        self.scheduler_id_1_ = nil;
        local function addTimeFunc( ... )
                self.scheduler_id_2_ = nil
                self.scheduler_id_2_ = scheduler:scheduleScriptFunc(function( ... )
                if numble < ADD_TIME_NUMBLE then
                    self:addOneSecond();
                    numble = numble+1;
                else
                    scheduler:unscheduleScriptEntry(self.scheduler_id_2_);
                end
            end, ANIMATION_PER_ADD_DELAYTIME,false);
        scheduler:unscheduleScriptEntry(self.scheduler_id_1_);
        end
        self.scheduler_id_1_ = scheduler:scheduleScriptFunc(addTimeFunc, ANIMATION_DELAYTIME, false);
        self:setInitailTime(self:getInitailTime() + ADD_TIME_NUMBLE);
    end));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleDefeatCountdownComponent:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleDefeatCountdownComponent