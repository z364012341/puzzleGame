--
-- Author: 黄泽昊
-- 功能: 道具冷却进度条

local PuzzlePropCoolingTimerComponent = class("PuzzlePropCoolingTimerComponent", function (path, time)
    return cc.Node:create();
end)

function PuzzlePropCoolingTimerComponent:ctor(path, time)
    local progressTimer = cc.ProgressTimer:create(GlobalFunction.createGameSpriteWithPath(path));
    progressTimer:setReverseDirection(true);
    progressTimer:setPercentage(100);
    self:addChild(progressTimer);

    local percent_seq = cc.Sequence:create(cc.CallFunc:create(function ()
        progressTimer:setPercentage(progressTimer:getPercentage()-1);
    end), cc.DelayTime:create(time/100), nil);
    local seq = cc.Sequence:create(cc.Repeat:create(percent_seq, 100), cc.CallFunc:create(function ()
        self:removeFromParent();
        -- if callback ~= nil then
        --     callback();
        -- end
    end));

    self:runAction(seq);
end
return PuzzlePropCoolingTimerComponent