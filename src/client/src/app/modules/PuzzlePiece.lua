--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图碎片
--[[params =
	{
        index_x = 1, --拼图碎片的x索引
        index_y = 1, --拼图碎片的y索引
        path = "puzzle_1.png",    --底板的资源路径
        left = PUZZLE_STENCIL_COMPONENT_INSIDE,    --左边凹凸方向
        right = PUZZLE_STENCIL_COMPONENT_OUTSIDE,   --右边凹凸方向
        top = PUZZLE_STENCIL_COMPONENT_PLAIN,     --上边凹凸方向
        bottom = PUZZLE_STENCIL_COMPONENT_PLAIN  --下边凹凸方向
    }
]]
local PuzzlePiece = class("PuzzlePiece", function (params)
    --dump(params);
    return cc.Node:create();
end)
local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
local PuzzleStencil = require(PUZZLE_STENCIL_PATH);
local PuzzlePieceEdges = require(PUZZLE_PIECE_EDGES_PATH);
local PuzzlePieceShadow = require(PUZZLE_PIECE_SHADOW_PATH);
--local PuzzlePiecesCollection = require(PUZZLE_PIECES_COLLECTION_PATH);
--local numble = 0
local PUZZLE_RENDER_SPRITE_NAME = "puzzle_render_sprite_name";
local PUZZLE_MOVE_ANSWER_ANIMATION_NAME = "pintuTX3";
PuzzlePiece.need_blink_answer_ = false;
function PuzzlePiece:ctor(params)
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self:savePuzzleDirection(params);
    self:addTouchEvent();
    self:initPuzzleRenderTexture(params);
    self:addPuzzlePieceShadow(params);
end
function PuzzlePiece:savePuzzleDirection( params )
    self.left_ = params.left;
    self.right_ = params.right;
    -- self.top_ = params.top;
    -- self.bottom_ = params.bottom;
end
function PuzzlePiece:getLeftWidth()
    return self:getDirectionWidth(self.left_);
end
function PuzzlePiece:getRightWidth()
    return self:getDirectionWidth(self.right_);
end
function PuzzlePiece:getDirectionWidth(direction)
    --dump(direction);
    if direction == PUZZLE_STENCIL_COMPONENT_OUTSIDE then
        return PUZZLE_STENCIL_WIDTH/2 +PUZZLE_PIECE_RAISED_WIDTH;
    else
        return PUZZLE_STENCIL_WIDTH/2;
    end
end
function PuzzlePiece:initPuzzleRenderTexture(params)
    self.node_ = cc.Node:create();
    self:addChild(self.node_);

    self:addClippingNode(params);
    self:addPuzzlePieceEdges(params)
    --GL_DEPTH24_STENCIL8 = 0x88F0
    local puzzleRender = cc.RenderTexture:create(400, 400, cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888, 0x88F0);
    puzzleRender:beginWithClear(0.0, 0.0, 0.0, 0.0);
    self.node_:setPosition(200, 200);
    self.node_:visit();
    puzzleRender:endToLua();
    local render_sp = cc.Sprite:createWithTexture(puzzleRender:getSprite():getTexture());
    render_sp:setName(PUZZLE_RENDER_SPRITE_NAME);
    render_sp:setScaleY(-1);
    self:addChild(render_sp);
    self.node_:removeFromParent();
end

function PuzzlePiece:addTouchEvent()
    self.touch_listener_ = cc.EventListenerTouchOneByOne:create();
    self.touch_listener_:setSwallowTouches(false);
    self.touch_listener_:registerScriptHandler(self.onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN);
    self.touch_listener_:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED);
    self.touch_listener_:registerScriptHandler(self.onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(self.touch_listener_, self);
end

function PuzzlePiece.onTouchBegan(touch, event)
    --printf("PuzzlePiece onTouchBegan");
    if PuzzlePiece.isTouchOnPuzzle(touch, event) then
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUZZLE_TOUCH);
        local puzzle = event:getCurrentTarget();
        puzzle:setLocalZOrder(require(PUZZLE_PIECES_COLLECTION_PATH):getZOrderNumble());
        puzzle:retain();
        local point = puzzle._moveNode:convertToNodeSpace(puzzle:getParent():convertToWorldSpace(cc.p(puzzle:getPosition())));
        puzzle:removeFromParent();
        puzzle._moveNode:addChild(puzzle);
        puzzle:setPosition(point);
        puzzle:release();
        puzzle._shadow:shadowGo();
        puzzle._moveNode:moveOutPuzzlePiece(puzzle);
        if puzzle.need_blink_answer_ then
            puzzle:blinkAnswer();
        end
        return true;
    end
    return false;
end

function PuzzlePiece.onTouchMoved(touch, event)
    --printf("PuzzlePiece onTouchMoved");
    local node = event:getCurrentTarget();
    local dis = touch:getDelta()
    local zoomScale = node:getParent():getParent():getScale();
    node:setPositionX(node:getPositionX() + dis.x/zoomScale);
    node:setPositionY(node:getPositionY() + dis.y/zoomScale);
end

function PuzzlePiece.onTouchEnded(touch, event)
    --printf("PuzzlePiece onTouchEnded");
    local puzzle = event:getCurrentTarget();

    local isOnMoveNode = puzzle.isTouchOnMoveNode(touch, event);
    if puzzle:isToucnOnAnswer() then
        puzzle:moveToAnswer();
    elseif isOnMoveNode then
        puzzle._moveNode:insertPuzzlePiece(puzzle);
    end
    puzzle.touch_listener_:setSwallowTouches(not isOnMoveNode);
    puzzle._moveNode:adjustPuzzlePiecesPosition();
    puzzle:noBlinkAnswer();
    puzzle:moveBackShadow();
    --dump(puzzle._moveNode:getBoundingBox());
    --dump(touch:getLocationInView());
end

function PuzzlePiece.isTouchOnPuzzle(touch, event)
    local node = event:getCurrentTarget();
    return cc.pGetDistance(node:convertTouchToNodeSpace(touch), cc.p(0, 0)) < PUZZLE_STENCIL_WIDTH / 2;
end

function PuzzlePiece.isTouchOnMoveNode(touch, event)
    local puzzle = event:getCurrentTarget();
    return cc.rectContainsPoint(puzzle._moveNode:getBoundingBox(), puzzle._moveNode:getParent():convertTouchToNodeSpace(touch));
end
function PuzzlePiece:isToucnOnAnswer()
    local puzzlePoint = self:getParent():convertToWorldSpace(cc.p(self:getPosition()));
    local answerPoint = self:getPuzzlePieceAnswer():convertToNodeSpace(puzzlePoint);
    --printf("distance" .. cc.pGetDistance(cc.p(0,0), answerPoint));
    return cc.pGetDistance(cc.p(0,0), answerPoint) < PUZZLE_STENCIL_LENGTH/2;
end

function PuzzlePiece:moveToAnswer()
    local answer = self:getPuzzlePieceAnswer();
    --local answerPoint = answer:getParent():convertToWorldSpace(cc.p(answer:getPosition()));
    --self:setPosition(self:getParent():convertToNodeSpace(answerPoint));
    self._shadow:removeFromParent();
    self._shadow = nil;
    --self:setLocalZOrder(0);
    self:retain();
    self:removeFromParent();
    answer:getParent():addChild(self);
    self:setPosition(cc.p(answer:getPosition()));
    self:release();
    self:setScale(1);
    cc.Director:getInstance():getEventDispatcher():removeEventListenersForTarget(self);
    cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_PUZZLE_ANSWER_ADD);
    self:playMoveAnswerAnimation();
end
function PuzzlePiece:moveBackShadow()
    if self._shadow ~= nil then
        self._shadow:shadowBack();
    end
end
function PuzzlePiece:playMoveAnswerAnimation()
    local armature = ccs.Armature:create(PUZZLE_MOVE_ANSWER_ANIMATION_NAME);
    armature:setScale(PUZZLE_STENCIL_WIDTH / armature:getContentSize().width*1.3);
    --armature:addChild(bs.GameAlertMask:create());
    armature:setPosition(cc.p(0, 0));
    self:addChild(armature);
    armature:getAnimation():playWithIndex(0);
    armature:getAnimation():setMovementEventCallFunc(function ( armature, movementType, movementID)
        armature:removeFromParent();
    end);
end

function PuzzlePiece:setPuzzlePieceAnswer(answer)
    self._answer = answer;
end

function PuzzlePiece:setPuzzlePieceMoveNode(node)
    self._moveNode = node;
end

function PuzzlePiece:getPuzzlePieceAnswer()
    return self._answer;
end

function PuzzlePiece:addClippingNode(params)
    local clippingNode = cc.ClippingNode:create(PuzzleStencil:create(params.left, params.right, params.top, params.bottom));
    clippingNode:addChild(PuzzleBottomPlate:create(params.index_x, params.index_y, params.path));
    clippingNode:setAlphaThreshold(0.0);
    self.node_:addChild(clippingNode);
end

function PuzzlePiece:addPuzzlePieceEdges(params)
    self.node_:addChild(PuzzlePieceEdges:create(params.left, params.right, params.top, params.bottom));
end

function PuzzlePiece:addPuzzlePieceShadow(params)
    self._shadow = PuzzlePieceShadow:create(params.left, params.right, params.top, params.bottom);
    self:addChild(self._shadow, -1);
end
function PuzzlePiece:blinkAnswer()
    --self:getPuzzlePieceAnswer():blink();
    self.blink_edges_ = GlobalFunction.copyGameSprite(self:getChildByName(PUZZLE_RENDER_SPRITE_NAME));
    self.blink_edges_:setBlendFunc({src = gl.SRC_ALPHA, dst = gl.ONE})
    self.blink_edges_:setPosition(cc.p(self:getPuzzlePieceAnswer():getPosition()));
    self:getPuzzlePieceAnswer():getParent():addChild(self.blink_edges_, -1);
    self.blink_edges_:setScaleY(-1);
    self.blink_edges_:setOpacity(0);
    self.blink_edges_:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.FadeIn:create(0.5), cc.FadeOut:create(0.5), nil)));
end
function PuzzlePiece:noBlinkAnswer()
    --self:getPuzzlePieceAnswer():noBlink();
    if self.blink_edges_ ~= nil then
        self.blink_edges_:removeFromParent();
        self.blink_edges_ = nil;
    end
end
function PuzzlePiece:getAnswerWidth()
    local answer = self:getPuzzlePieceAnswer();
    return answer:getWidthInWorld();
    -- return cc.pGetDistance(answer:convertToWorldSpace(cc.p(PUZZLE_STENCIL_LENGTH/-2, 0)), answer:convertToWorldSpace(cc.p(PUZZLE_STENCIL_LENGTH/2, 0)));
end
function PuzzlePiece:saveNewPosition(point)
    self.new_position_ = point;
end
function PuzzlePiece:getNewPosition()
    return self.new_position_;
end
function PuzzlePiece:onEnter()
    self.listener_ = {};
    -- local function blink( event )
    --     self:addPuzzleScrollView(GlobalFunction.getCustomEventUserData(event));
    -- end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_SEARCH_PROP, function ( event )
        self.need_blink_answer_ = true;
    end));
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_END_SEARCH_PROP, function ( event )
        self.need_blink_answer_ = false;
    end));
    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzlePiece:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzlePiece