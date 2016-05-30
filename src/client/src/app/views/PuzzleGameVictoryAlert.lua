--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图游戏的胜利面板

local PuzzleGameVictoryAlert = class("PuzzleGameVictoryAlert", function (time_consuming)
    return cc.Node:create();
end)
local PUZZLE_VICTORY_ALERT_CSB_PATH = "PuzzleVictoryAlert.csb";
local REPLAY_BUTTON_NAME = "replayButton";
local RETURN_BUTTON_NODE_NAME = "returnButton";
local PuzzleTimeDisplay = require(PUZZLE_TIME_DISPLAY_PATH);
local PuzzlePlayArea = require(PUZZLE_PLAY_AREA_PATH);
local TIME_CONSUMING_NODE_NAME = "time_consuming_node";
local THUMBNAIL_POS_NODE_NAME = "thumbnail_pos";
local TIME_BEST_CONSUMING_NODE_NAME = "Node_5";
local inlayAnswers_DURATION
local TIME_LABEL_SCALE = 0.75;
local ALERT_SHARE_BUTTON_POS = cc.p(187, -155);
function PuzzleGameVictoryAlert:ctor(time_consuming)
    self:init(time_consuming);
end
function PuzzleGameVictoryAlert:init(time_consuming)
    self:loadCSB();
    self:addMaskBackground();
    self:addTimeConsumingLabel(time_consuming);
    self:addBestTimeConsumingLabel();
    --self.csb_node_:getChildByName("share_10"):setLocalZOrder(2);
end
function PuzzleGameVictoryAlert:loadCSB()
    self.csb_node_ = cc.CSLoader:createNode(PUZZLE_VICTORY_ALERT_CSB_PATH);
    self:addChild(self.csb_node_);
    local continue_button = bs.GameStartButton:createButtonContinueForm();
    continue_button:getStartButton():addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_VICTORY_RETURN);
    end);
    self.csb_node_:getChildByName(RETURN_BUTTON_NODE_NAME):addChild(continue_button);
    self.csb_node_:getChildByName(REPLAY_BUTTON_NAME):addClickEventListener(function ( ... )
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_REPLAY);
    end);
    bs.ButtonEffectController:setButtonsZoomScale(self.csb_node_);

    local colorlayer = PuzzlePlayArea:getBackgroundColorLayer();
    -- dump(colorlayer);
    colorlayer:setScale(PUZZLE_ALERT_THUMBNAIL_SCALE);
    self:addChildToThumbnailPosNode(colorlayer);
    local edge = PuzzlePlayArea:createWindowsEdge();
    edge:setScale(PUZZLE_ALERT_THUMBNAIL_SCALE);
    self:addChildToThumbnailPosNode(edge);
end
function PuzzleGameVictoryAlert:addMaskBackground()
    self:addChild(bs.GameAlertMask:create(), -1);
end

function PuzzleGameVictoryAlert:addTimeConsumingLabel(time_consuming)
    local time_display = PuzzleTimeDisplay:create();
    time_display:setTimeString(time_consuming);
    time_display:setScale(TIME_LABEL_SCALE);
    self.csb_node_:getChildByName(TIME_CONSUMING_NODE_NAME):addChild(time_display);
end
function PuzzleGameVictoryAlert:addBestTimeConsumingLabel()
    local time_display = PuzzleTimeDisplay:create();
    time_display:setTimeString(bs.UserDataManager:getInstance():getPuzzleStageBestScoreWithKey(require(PUZZLE_SELECTED_SHOW_PATH):getSelectedPicturePath()));
    time_display:setScale(TIME_LABEL_SCALE);
    self.csb_node_:getChildByName(TIME_BEST_CONSUMING_NODE_NAME):addChild(time_display);
end
function PuzzleGameVictoryAlert:getThumbnailPosNode()
    return self.csb_node_:getChildByName(THUMBNAIL_POS_NODE_NAME);
end
function PuzzleGameVictoryAlert:addChildToThumbnailPosNode( node )
    self:getThumbnailPosNode():addChild(node);
end
function PuzzleGameVictoryAlert:inlayAnswers(flash_answers_node, callFunc)
    local point = flash_answers_node:getParent():convertToWorldSpace(cc.p(flash_answers_node:getPosition()));
    flash_answers_node:retain();
    flash_answers_node:removeFromParent();
    self:addChildToThumbnailPosNode(flash_answers_node);
    flash_answers_node:release();
    flash_answers_node:setPosition(self:getThumbnailPosNode():convertToNodeSpace(point));
    local duration = 0.15
    flash_answers_node:runAction(cc.Sequence:create(cc.MoveTo:create(duration, cc.p(0,0)), callFunc--[[, cc.CallFunc:create(function ()
        local share_button = bs.GameShareButton:create();
        share_button:setPosition(ALERT_SHARE_BUTTON_POS);
        self.csb_node_:addChild(share_button);
    end)]] , nil));
    flash_answers_node:runAction(cc.EaseOut:create(cc.ScaleTo:create(duration, PuzzlePlayArea:calculatePuzzleScaleWithSize(flash_answers_node:getContentSize())*PUZZLE_ALERT_THUMBNAIL_SCALE), 1.5));

end
return PuzzleGameVictoryAlert