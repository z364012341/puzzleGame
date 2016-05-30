--
-- Author: 黄泽昊
-- 功能: 胜利条件组件

local PuzzleVictoryCountdownComponent = class("PuzzleVictoryCountdownComponent", function ()
    return cc.Node:create();
end)
function PuzzleVictoryCountdownComponent:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
    	end
    end
    self:registerScriptHandler(onNodeEvent);
    self.current_answer_numble_ = 0;
end
function PuzzleVictoryCountdownComponent:onEnter()
	self.listener_ = {};
	local function addPuzzleAnswerNumble( event )
        self.answer_numble_ = #GlobalFunction.getCustomEventUserData(event);
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_ANSWER_LOAD, addPuzzleAnswerNumble));

	local function addOnePuzzleAnswerNumble( event )
        self.current_answer_numble_ = self.current_answer_numble_ + 1;
        if self.current_answer_numble_ == self.answer_numble_ then
        	cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUZZLE_GAME_VICTORY);
        end
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_ANSWER_ADD, addOnePuzzleAnswerNumble));
    for _, listener in ipairs(self.listener_) do
    	self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleVictoryCountdownComponent:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
    	eventDispatcher:removeEventListener(listener);
    end
end
return PuzzleVictoryCountdownComponent