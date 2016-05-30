--
-- Author: 黄泽昊
-- 功能: 游戏时间计时器组件

local PuzzleGamePlayTimerComponent = class("PuzzleGamePlayTimerComponent", function ()
    return cc.Node:create();
end)

function PuzzleGamePlayTimerComponent:ctor()
    self.play_time_ = 0;
    self:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1), cc.CallFunc:create(function ()
        self:setPlayTime(self:getPlayTime() + 1);
    end), nil)));
end
function PuzzleGamePlayTimerComponent:setPlayTime(time)
    self.play_time_ = time;
end
function PuzzleGamePlayTimerComponent:getPlayTime()
    return self.play_time_;
end
function PuzzleGamePlayTimerComponent:getTimeConsuming()
    return self.play_time_;
end
function PuzzleGamePlayTimerComponent:getRemainTime()
    return nil;
end
return PuzzleGamePlayTimerComponent