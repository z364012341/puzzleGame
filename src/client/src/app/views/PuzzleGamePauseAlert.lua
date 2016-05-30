--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图游戏的暂停面板

local PuzzleGamePauseAlert = class("PuzzleGamePauseAlert", function (remainingTime)
    return cc.Node:create();
end)
local PuzzleTimeDisplay = require(PUZZLE_TIME_DISPLAY_PATH);
local PUZZLE_GAME_PAUSE_ALERT_CSB_PATH = "PuzzlePauseAlert.csb";
local CONTINUE_BUTTON_NODE_NAME = "Node_1";
local RETURN_BUTTON_NODE_NAME = "returnButton";
local REPLAY_BUTTON_NODE_NAME = "replayButton";
local THUMBNAIL_POS_NODE_NAME = "thumbnail_pos";
local REMAINING_TIME_NODE_NAME = "remainingTime";
local MASK_ZORDER = -1;
local SCREEN_SHOT_ZORDER = MASK_ZORDER-1;
function PuzzleGamePauseAlert:ctor(remainingTime)
    self:init(remainingTime);
end
function PuzzleGamePauseAlert:init(remainingTime)
    self:loadCSB();
    self:addMaskBackground();
    self:addRemainingTimeLabel(remainingTime);
end

function PuzzleGamePauseAlert:addRemainingTimeLabel(remainingTime)
    if remainingTime == nil then
        self.csb_node_:getChildByName("wenzishengyushijian_7"):setVisible(false);
        return;
    end
    local time_display = PuzzleTimeDisplay:create();
    time_display:setScale(0.8);
    time_display:setTimeString(remainingTime);
    self.csb_node_:getChildByName(REMAINING_TIME_NODE_NAME):addChild(time_display);
end
function PuzzleGamePauseAlert:loadCSB()
    self.csb_node_ = cc.CSLoader:createNode(PUZZLE_GAME_PAUSE_ALERT_CSB_PATH);
    self:addChild(self.csb_node_);
    self.continue_button_ = bs.GameStartButton:createButtonContinueForm();
    self.continue_button_:getStartButton():addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_CONTINUE);
    end);
    self.csb_node_:getChildByName(RETURN_BUTTON_NODE_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_RETURN);
    end);
    self.csb_node_:getChildByName(REPLAY_BUTTON_NODE_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_REPLAY);
    end);
    self.csb_node_:getChildByName(CONTINUE_BUTTON_NODE_NAME):addChild(self.continue_button_);
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_);
end
function PuzzleGamePauseAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), MASK_ZORDER);
end

function PuzzleGamePauseAlert:getThumbnailPosNode()
    return self.csb_node_:getChildByName(THUMBNAIL_POS_NODE_NAME);
end
function PuzzleGamePauseAlert:addChildToThumbnailPosNode( node )
    self:getThumbnailPosNode():addChild(node);
end
return PuzzleGamePauseAlert