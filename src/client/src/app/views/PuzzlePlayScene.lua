--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用:

local PuzzlePlayScene = class("PuzzlePlayScene", function ()
    return cc.Layer:create();
end)
local PuzzlePlayArea = require(PUZZLE_PLAY_AREA_PATH);
local PuzzlePiecesScrollView = require(PUZZLE_PIECES_SCROLLVIEW_PATH);
local PuzzleGamePauseAlert = require(PUZZLE_GAME_PAUSE_ALERT_PATH);
local PuzzleSelectedScene = require(PUZZLE_SELECTED_SCENE_PATH);
local PuzzleDefeatCountdownComponent = require(PUZZLE_DEFEAT_COUNTDOWN_COMPONENT_PATH);
local PuzzleGameDefeatAlert = require(PUZZLE_GAME_DEFEAT_ALERT_PATH);
local PuzzleTimeDisplay = require(PUZZLE_TIME_DISPLAY_PATH);
local PuzzleGameVictoryAlert = require(PUZZLE_GAME_VICTORY_ALERT_PATH);
local PuzzleVictoryCountdownComponent = require(PUZZLE_VICTORY_COUNTDOWN_COMPONENT_PATH);
local PuzzleSmallEyesProp = require(PUZZLE_SMALL_EYES_PROP_PATH);
local PuzzleSearchProp = require(PUZZLE_SEARCH_PROP_PATH);
local PuzzleBigEyesProp = require(PUZZLE_BIG_EYES_PROP_PATH);
local PuzzleAddTimeProp = require(PUZZLE_ADD_TIME_PROP_PATH);
local PuzzleSelectedShow = require(PUZZLE_SELECTED_SHOW_PATH);
local PuzzleGamePlayTimerComponent = require(PUZZLE_GAME_PLAY_TIMER_COMPONENT_PATH);
local PuzzleStoreAlert = require(PUZZLE_STORE_ALERT_PATH);
local PUZZLE_PLAY_SCENE_CSB_PATH = "PuzzlePlayLayer.csb";
local CSB_DESK_NAME = "pintutaizi_2";
local PAUSE_BUTTON_NAME = "Button_1";
local SMALL_EYES_BUTTON_NAME = "Node_2";
local BACKGROUND_NAME = "pintubeijing02_1";
local SEARCH_PROP_POS_NODE_NAME_1 = "Node_3";
local SEARCH_PROP_POS_NODE_NAME_2 = "Node_1";
local BIG_EYES_PROP_POS_NODE_NAME_1 = "Node_4";
local BIG_EYES_PROP_POS_NODE_NAME_2 = "Node_6";
local ADD_TIME_POS_NODE_NAME = "Node_5";
local PROP_SEARCH_ANIMATION_NAME = "fangdajing";
local PROP_BIG_EYES_ANIMATION_NAME = "yanjingTX";
local PROP_ADD_TIME_ANIMATION_NAME = "pintunaozhong";
local PUZZLE_PIECES_SCROLLVIEW_ZORDER = 1;
local PUZZLE_PLAY_AREA_ZORDER = -1;
local BACKGROUND_ZORDER = PUZZLE_PLAY_AREA_ZORDER-1;
local TOP_WIDGET_POS_Y_PERCENT = 0.95;
local ANSWER_FLASH_BACKGROUND = "pintuguang_0000_8.png";
local ANSWER_FLASH_INNER_SIZE = cc.size(728, 1096);
local ANSWER_FLASH_INITAIL_SCALE = 0.98;
function PuzzlePlayScene:ctor()
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

function PuzzlePlayScene:createScene()
    local scene = cc.Scene:create()
    local layer = PuzzlePlayScene:create()
    scene:addChild(layer)
    return scene
end
function PuzzlePlayScene:init()
	self:loadCsb();
	self:initPauseButton();
    self:addSmallEyesButton();
	self:initZOrder();
    self:addChild(PuzzleVictoryCountdownComponent:create());
end
function PuzzlePlayScene:addPuzzleProps(class, pos_name)
    local search_node = self.csb_node_:getChildByName(pos_name);
    search_node:addChild(class:create());
    search_node:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    search_node:setPositionY(search_node:getPositionY()*bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function PuzzlePlayScene:initGameTime()
    local time = bs.PuzzleStageDataManager:getInstance():getGameTimeWithkey(PuzzleSelectedShow:getSelectedPicturePath());
    if time > 0 then
        self:addPuzzleProps(PuzzleSearchProp, SEARCH_PROP_POS_NODE_NAME_1);
        self:addPuzzleProps(PuzzleBigEyesProp, BIG_EYES_PROP_POS_NODE_NAME_1);
        self:addPuzzleProps(PuzzleAddTimeProp, ADD_TIME_POS_NODE_NAME);
        self:addTimeClock();
        self.countdown_ = PuzzleDefeatCountdownComponent:create(time);
    else
        self:addPuzzleProps(PuzzleSearchProp, SEARCH_PROP_POS_NODE_NAME_2);
        self:addPuzzleProps(PuzzleBigEyesProp, BIG_EYES_PROP_POS_NODE_NAME_2);
        self.countdown_ = PuzzleGamePlayTimerComponent:create();
    end
    self:addChild(self.countdown_);
end
function PuzzlePlayScene:addTimeClock()
    local clock = PuzzleTimeDisplay:create();
    local size = cc.Director:getInstance():getVisibleSize();
    clock:setPosition(cc.p(size.width*0.5, size.height*TOP_WIDGET_POS_Y_PERCENT));
    self.csb_node_:addChild(clock);
end
function PuzzlePlayScene:loadCsb()
    self.csb_node_ = cc.CSLoader:createNode(PUZZLE_PLAY_SCENE_CSB_PATH);
    self:addChild(self.csb_node_);
    self.csb_node_:getChildByName(CSB_DESK_NAME):setScaleY(bs.SmartScaleController:getInstance():getPlayAreaZoom());
end
function PuzzlePlayScene:initPauseButton()
	local button = self.csb_node_:getChildByName(PAUSE_BUTTON_NAME);
	button:setPositionY(cc.Director:getInstance():getVisibleSize().height*TOP_WIDGET_POS_Y_PERCENT);
	bs.ButtonEffectController:setButtonZoomScale(button);
	button:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    -- button:addTouchEventListener(function ( pSender, touchType )
    --     if touchType == ccui.TouchEventType.began then
    --         local size = cc.Director:getInstance():getVisibleSize();
    --         local puzzleRender = cc.RenderTexture:create(size.width, size.height, cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888, 0x88F0);
    --         puzzleRender:beginWithClear(0.0, 0.0, 0.0, 0.0);
    --         self:visit();
    --         puzzleRender:endToLua();
    --         self.screen_sp_ = cc.Sprite:createWithTexture(puzzleRender:getSprite():getTexture());
    --         self.screen_sp_:setFlippedY(true);
    --         self.screen_sp_:setAnchorPoint(cc.p(0, 0));
    --         self.screen_sp_:setVisible(false);
    --         self:addChild(self.screen_sp_);
    --     elseif touchType == ccui.TouchEventType.ended then
    --         self:popPauseAlert();
    --     end
    -- end);
	button:addClickEventListener(function (...)
	   self:popPauseAlert();
    end);
end
function PuzzlePlayScene:addSmallEyesButton()
    local pos_node = self.csb_node_:getChildByName(SMALL_EYES_BUTTON_NAME);
    pos_node:setPositionY(cc.Director:getInstance():getVisibleSize().height*TOP_WIDGET_POS_Y_PERCENT);
    pos_node:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    pos_node:addChild(PuzzleSmallEyesProp:create());
end
function PuzzlePlayScene:initZOrder()
	self.csb_node_:getChildByName(BACKGROUND_NAME):setLocalZOrder(BACKGROUND_ZORDER);
end
function PuzzlePlayScene:addPuzzlePlayArea()
	self.puzzle_area_ = PuzzlePlayArea:create();
    self.csb_node_:addChild(self.puzzle_area_, PUZZLE_PLAY_AREA_ZORDER);
    self.puzzle_area_:setScale(bs.SmartScaleController:getInstance():getPlayAreaZoom());
    local size = cc.Director:getInstance():getVisibleSize();
    self.puzzle_area_:setPosition(self:getPuzzlePlayAreaPosition());
end
function PuzzlePlayScene:getPuzzlePlayAreaPosition()
    return cc.p(cc.Director:getInstance():getVisibleSize().width/2, cc.Director:getInstance():getVisibleSize().height*0.6)
end
function PuzzlePlayScene:addPuzzleScrollView( puzzleTable )
	self.csb_node_:addChild(PuzzlePiecesScrollView:create(puzzleTable), PUZZLE_PIECES_SCROLLVIEW_ZORDER);
end
function PuzzlePlayScene:popPropsAnimation( animation_name )
    self:gamePause();
    local armature = ccs.Armature:create(animation_name);
    armature:setScale(1.5);
    armature:addChild(bs.GameAlertMask:create());
    armature:setPosition(cc.p(cc.Director:getInstance():getVisibleSize().width/2, cc.Director:getInstance():getVisibleSize().height*0.4));
    self:addChild(armature);
    armature:getAnimation():playWithIndex(0);
    armature:getAnimation():setMovementEventCallFunc(function ( armature, movementType, movementID)
        self:gameResum();
        armature:removeFromParent();
    end);
end
function PuzzlePlayScene:onEnter()
	self.listener_ = {};
	local function addPuzzleAnswer( event )
		self:addPuzzleScrollView(GlobalFunction.getCustomEventUserData(event));
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_ANSWER_LOAD, addPuzzleAnswer));

	local function gameContinue( event )
        if self.screen_sp_ ~= nil then
            cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUSH_ANSWERS_THUMBNAIL);
            self.screen_sp_:removeFromParent();
            self.screen_sp_ = nil;
        end
        if self.alert_ ~= nil then
        	self.alert_:removeFromParent();
        	self.alert_ = nil;
        end
        self:gameResum();
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_CONTINUE, gameContinue));

	local function gameReturn( event )
        PuzzleSelectedScene:setPageDownFlag(false);
        cc.Director:getInstance():popScene();
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_RETURN, gameReturn));

    local function gameVictoryReturn( event )
        PuzzleSelectedScene:setPageDownFlag(true);
        cc.Director:getInstance():popScene();
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_VICTORY_RETURN, gameVictoryReturn));

	local function gameRePlay( event )
        cc.Director:getInstance():replaceScene(self:createScene());
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_REPLAY, gameRePlay));

	local function gameDefeat( event )
        self:popDefeatAlert();
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_GAME_DEFEAT, gameDefeat));

    local function gameVictory( event )
        self:popVictoryAlert();
    end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_GAME_VICTORY, gameVictory));

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_SEARCH_PROP, function ( event )
        self:popPropsAnimation(PROP_SEARCH_ANIMATION_NAME);
    end));
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_BIG_EYES_PROP, function ( event )
        self:popPropsAnimation(PROP_BIG_EYES_ANIMATION_NAME);
    end));
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_ADD_TIME_PROP, function ( event )
        self:popPropsAnimation(PROP_ADD_TIME_ANIMATION_NAME);
    end));
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_POP_PUZZLE_STORE_ALERT, function ( event )
        self:popStoreAlert();
    end));
    for _, listener in ipairs(self.listener_) do
    	self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
	self:addPuzzlePlayArea();
    self:initGameTime();
    self:getEventDispatcher():dispatchCustomEvent(EVENT_ADJUST_PUZZLE_PIECES_SCALE);
end
function PuzzlePlayScene:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
    	eventDispatcher:removeEventListener(listener);
    end
end
function PuzzlePlayScene:gameResum()
    --printf("gameResum");
    cc.Director:getInstance():getActionManager():resumeTargets(self.pause_nodes_);
end
function PuzzlePlayScene:gamePause()
    --printf("pause");
    self.pause_nodes_ = cc.Director:getInstance():getActionManager():pauseAllRunningActions();
end
function PuzzlePlayScene:popPauseAlert()
    self:gamePause();
	self:popAlert(PuzzleGamePauseAlert, self.countdown_:getRemainTime());
end
function PuzzlePlayScene:popDefeatAlert()
	self:popAlert(PuzzleGameDefeatAlert, self.countdown_:getTimeConsuming());
end
function PuzzlePlayScene:popVictoryAlert()
    self.countdown_:pause();
    bs.UserDataManager:getInstance():insertPuzzleStageData(require(PUZZLE_SELECTED_SHOW_PATH):getSelectedPicturePath(),
        self.countdown_:getTimeConsuming());
    local answer = self.puzzle_area_:getAnswersThumbnail();
    local point = answer:convertToWorldSpace(cc.p(answer:getContentSize().width/2, answer:getContentSize().height/2));
    local point_00 = answer:convertToWorldSpace(cc.p(0, 0));
    local point_01 = answer:convertToWorldSpace(cc.p(answer:getContentSize().width, 0));
    local distance = cc.pGetDistance(point_00, point_01);
    local node = cc.Node:create();
    node:setContentSize(answer:getContentSize());
    answer:retain();
    answer:removeFromParent();
    node:addChild(answer, 2);
    answer:release();
    node:setScale(distance / answer:getContentSize().width);
    local flash_bg = GlobalFunction.createGameSpriteWithPath(ANSWER_FLASH_BACKGROUND);
    local answer_size = answer:getContentSize();
    flash_bg:setScale(answer_size.width / ANSWER_FLASH_INNER_SIZE.width*ANSWER_FLASH_INITAIL_SCALE,
        answer:getContentSize().height / ANSWER_FLASH_INNER_SIZE.height*ANSWER_FLASH_INITAIL_SCALE);
    node:addChild(flash_bg, -1);
    node:setPosition(self:convertToNodeSpace(point));
    self:addChild(node);
    node:runAction(cc.Sequence:create(cc.EaseOut:create(cc.ScaleBy:create(0.3, 1.7), 1.5), cc.DelayTime:create(0.05) , cc.CallFunc:create(
        function ()
            self.alert_ = PuzzleGameVictoryAlert:create(self.countdown_:getTimeConsuming());
            self.alert_:setPosition(GlobalFunction.getVisibleCenterPosition());
            self:addChild(self.alert_);
            self.alert_:inlayAnswers(node, cc.CallFunc:create(function ()
                flash_bg:removeFromParent();
            end));
        end), nil));
    flash_bg:runAction(cc.ScaleBy:create(0.5, 1.05));
end
function PuzzlePlayScene:popAlert( alert_class , params)
    local size = cc.Director:getInstance():getVisibleSize();
    local puzzleRender = cc.RenderTexture:create(size.width, size.height, cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888, 0x88F0);
    puzzleRender:beginWithClear(0.0, 0.0, 0.0, 0.0);
    self:visit();
    puzzleRender:endToLua();
    self.screen_sp_ = cc.Sprite:createWithTexture(puzzleRender:getSprite():getTexture());
    self.screen_sp_:setFlippedY(true);
    self.screen_sp_:setAnchorPoint(cc.p(0, 0));
    self.screen_sp_:setVisible(false);
    self:addChild(self.screen_sp_);
    local function callfunc()
        self.screen_sp_:setVisible(true);
        self.alert_ = alert_class:create(params);
        local thumbnail = self.puzzle_area_:getThumbnail();
        thumbnail:setScale(PUZZLE_ALERT_THUMBNAIL_SCALE);
        self.alert_:addChildToThumbnailPosNode(thumbnail);
        self.alert_:setPosition(GlobalFunction.getVisibleCenterPosition());
        self:addChild(self.alert_);
    end
    self:runAction(cc.Sequence:create(cc.DelayTime:create(0.01), cc.CallFunc:create(callfunc)));
end
function PuzzlePlayScene:popStoreAlert()
    self:gamePause();
    self.alert_ = PuzzleStoreAlert:create();
    self.alert_:setPosition(GlobalFunction.getVisibleCenterPosition());
    self:addChild(self.alert_);
end
return PuzzlePlayScene