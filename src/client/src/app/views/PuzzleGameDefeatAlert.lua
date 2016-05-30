--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图游戏的暂停面板

local PuzzleGameDefeatAlert = class("PuzzleGameDefeatAlert", function (time_consuming)
    return cc.Node:create();
end)
local PUZZLE_DEFEAT_ALERT_CSB_PATH = "PuzzleDefeatAlert.csb";
local RETURN_BUTTON_NODE_NAME = "returnButton";
local REPLAY_BUTTON_NODE_NAME = "replayButton";
local THUMBNAIL_POS_NODE_NAME = "thumbnail_pos";
local TIME_CONSUMING_NODE_NAME = "Node_1";
local PuzzleTimeDisplay = require(PUZZLE_TIME_DISPLAY_PATH);
function PuzzleGameDefeatAlert:ctor(time_consuming)
    self:init(time_consuming);
end
function PuzzleGameDefeatAlert:init(time_consuming)
    self:loadCSB();
    self:addMaskBackground();
    self:addTimeConsumingLabel(time_consuming);
end
function PuzzleGameDefeatAlert:loadCSB()
    self.csb_node_ = cc.CSLoader:createNode(PUZZLE_DEFEAT_ALERT_CSB_PATH);
    self:addChild(self.csb_node_);
    self.csb_node_:getChildByName(RETURN_BUTTON_NODE_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_RETURN);
    end);
    self.csb_node_:getChildByName(REPLAY_BUTTON_NODE_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_REPLAY);
    end);
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_);
end
function PuzzleGameDefeatAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), -1);
end

function PuzzleGameDefeatAlert:getThumbnailPosNode()
    return self.csb_node_:getChildByName(THUMBNAIL_POS_NODE_NAME);
end
function PuzzleGameDefeatAlert:addChildToThumbnailPosNode( node )
    self:getThumbnailPosNode():addChild(node);
end
function PuzzleGameDefeatAlert:addTimeConsumingLabel(time_consuming)
    local time_display = PuzzleTimeDisplay:create();
    time_display:setTimeString(time_consuming);
    time_display:setScale(0.75);
    self.csb_node_:getChildByName(TIME_CONSUMING_NODE_NAME):addChild(time_display);
end
return PuzzleGameDefeatAlert