--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 拼图的滚动区域

local PuzzlePiecesScrollView = class("PuzzlePiecesScrollView", function (puzzleTable)
    return cc.Node:create();
end)
local PUZZLE_PIECES_DESK_HEIGHT = 270;
local PUZZLE_PIECES_POS_Y = 110;
local PUZZLE_PIECES_INITIAL_POS_X = 200;
local PUZZLE_PIECES_POS_X_DELTA = PUZZLE_STENCIL_WIDTH;
local PUZZLE_PIECES_SCALE = 0.55;
local PUZZLE_PIECES_MOVE_DURATION = 0.3;
local PUZZLE_PIECES_INTERVAL_POS_X = 20;
local PuzzlePlayArea = require(PUZZLE_PLAY_AREA_PATH);
function PuzzlePiecesScrollView:ctor(puzzleTable)
	local function onNodeEvent(event)
	     if event == "enter" then
	         self:onEnter();
	     elseif event == "exit" then
	         self:onExit();
	     end
	 end
	 self:registerScriptHandler(onNodeEvent);
	self.puzzle_table_ = puzzleTable;
	self:init();
end

function PuzzlePiecesScrollView:init()
	self.scrollView_ = ccui.ScrollView:create();
	self.scrollView_:setPosition(0, 0);
	self.scrollView_:setContentSize(cc.size(cc.Director:getInstance():getVisibleSize().width,
		PUZZLE_PIECES_DESK_HEIGHT*bs.SmartScaleController:getInstance():getPlayAreaZoom()));
	self.scrollView_:setBounceEnabled(true);
	self.scrollView_:setScrollBarEnabled(false);
	self.scrollView_:setDirection(cc.SCROLLVIEW_DIRECTION_HORIZONTAL);
	for i, puzzle in ipairs(self.puzzle_table_) do
		self.scrollView_:addChild(puzzle);
		puzzle:setPuzzlePieceMoveNode(self);
	end
	self.scrollView_:addEventListener(function ( pSender,  eventType)
		pSender:getInnerContainer():setPositionY(0);
	end);

	self:addChild(self.scrollView_);
	self:setContentSize(self.scrollView_:getContentSize());
end

function PuzzlePiecesScrollView:moveOutPuzzlePiece(puzzle)
	for i,v in ipairs(self.puzzle_table_) do
		if v == puzzle then
			table.remove(self.puzzle_table_, i);
			return;
		end
	end
end
function PuzzlePiecesScrollView:calculatePuzzlePiecePositionX( index )
	if index == 1 then
		return self.puzzle_table_[1]:getLeftWidth()*self.puzzle_scale_;
	end
	local x = self.puzzle_table_[index-1]:getNewPosition().x + (self.puzzle_table_[index]:getLeftWidth()+
		self.puzzle_table_[index-1]:getRightWidth())*self.puzzle_scale_ ;
	return x
end

function PuzzlePiecesScrollView:getPuzzlePiecePositionWithIndex( index )
	return cc.p(self:calculatePuzzlePiecePositionX(index)+PUZZLE_PIECES_INTERVAL_POS_X, PUZZLE_PIECES_POS_Y);
end
function PuzzlePiecesScrollView:adjustPuzzlePiecesPosition()
	for i,puzzle in ipairs(self.puzzle_table_) do
		self.puzzle_table_[i]:stopAllActions();
		local new_point = self:getPuzzlePiecePositionWithIndex(i)
		puzzle:saveNewPosition(new_point);
		self.puzzle_table_[i]:runAction(cc.MoveTo:create(PUZZLE_PIECES_MOVE_DURATION, new_point));
	end
	self:adjustScrollViewInnerContainerSize();
end
function PuzzlePiecesScrollView:adjustScrollViewInnerContainerSize()
	local inner_width = self:calculatePuzzlePiecePositionX(#self.puzzle_table_) + self.pos_delta_/2;
	local point = cc.p(self.scrollView_:getInnerContainerPosition());
	self.scrollView_:setInnerContainerSize(cc.size(inner_width, PUZZLE_PIECES_DESK_HEIGHT));
	self.scrollView_:setInnerContainerPosition(point);
	local inner_min_pos_x = -inner_width+self.scrollView_:getContentSize().width;
	if point.x < inner_min_pos_x and #self.puzzle_table_ > 3 then
		self.scrollView_:getInnerContainer():stopAllActions();
		self.scrollView_:getInnerContainer():runAction(cc.MoveTo:create(PUZZLE_PIECES_MOVE_DURATION, cc.p(inner_min_pos_x, 0)));
	elseif point.x > 0 then
		self.scrollView_:scrollToLeft(PUZZLE_PIECES_MOVE_DURATION, false);
	end
end
function PuzzlePiecesScrollView:insertPuzzlePiece( puzzle )
	local point = self.scrollView_:getInnerContainer():convertToNodeSpace(puzzle:getParent():convertToWorldSpace(cc.p(puzzle:getPosition())));
	puzzle:retain();
	puzzle:removeFromParent();
	puzzle:setPosition(point);
	self.scrollView_:addChild(puzzle);
	puzzle:release();
	if self:insertPuzzleToTable(puzzle) ~= true or #self.puzzle_table_ == 0 then
		table.insert(self.puzzle_table_, puzzle);
	end
end

function PuzzlePiecesScrollView:insertPuzzleToTable( puzzle )
	for i,v in ipairs(self.puzzle_table_) do
		if puzzle:getPositionX() < v:getPositionX() then
			table.insert(self.puzzle_table_, i,  puzzle);
			return true
		end
	end
	return false;
end
function PuzzlePiecesScrollView:adjustPuzzleScaleAndPosition()
	local width = self.puzzle_table_[1]:getAnswerWidth();
	self.puzzle_scale_ = width / PUZZLE_STENCIL_WIDTH*1.2;
	self.pos_delta_ = (PUZZLE_STENCIL_WIDTH+100)*self.puzzle_scale_;
	for index,puzzle in ipairs(self.puzzle_table_) do
		puzzle:setScale(self.puzzle_scale_);
		local new_point = self:getPuzzlePiecePositionWithIndex(index)
		puzzle:saveNewPosition(new_point);
		puzzle:setPosition(new_point);
	end
	self:adjustScrollViewInnerContainerSize();
end
function PuzzlePiecesScrollView:onEnter()
    self.listener_ = {};
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_ADJUST_PUZZLE_PIECES_SCALE, function ( event )
    	self:adjustPuzzleScaleAndPosition();
    end));

    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzlePiecesScrollView:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzlePiecesScrollView