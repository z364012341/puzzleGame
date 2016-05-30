--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图阴影

local PuzzlePieceShadow = class("PuzzlePieceShadow", function (left, right, top, bottom)
    return cc.Node:create();
end)
-- local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
-- local PuzzlePieceShadowAnswer = require(PUZZLE_PIECE_ANSWER_PATH);
function PuzzlePieceShadow:ctor(left, right, top, bottom)
    --printf("PuzzlePieceShadow");
    self:initBody(left, right, top, bottom);
    self:setScale(PUZZLE_PIECE_SCALE*0.95);
    self:setPosition(PUZZLE_PIECE_SHADOW_OFFSET_POSITION);
end

function PuzzlePieceShadow:initBody(left, right, top, bottom)
    self:addPartBody(PUZZLE_COMPONENT_LEFT, left);
    self:addPartBody(PUZZLE_COMPONENT_RIGHT, right);
    self:addPartBody(PUZZLE_COMPONENT_TOP, top);
    self:addPartBody(PUZZLE_COMPONENT_BOTTOM, bottom);
end

function PuzzlePieceShadow:addPartBody(direction, insideOrOutside)
    self:addShadowSprite(puzzle.PUZZLE_PIECE_SHADOW_DIRECTION_TO_PATH[insideOrOutside], direction);
    if insideOrOutside == PUZZLE_STENCIL_COMPONENT_OUTSIDE then
        self:addComponentBody(direction)
    end
end

function PuzzlePieceShadow:addComponentBody(direction)
    local sp =self:addShadowSprite(PUZZLE_PIECE_SHADOW_COMPONENT_PATH, direction);
    sp:setPosition(GlobalFunction.getPuzzlePiecePositionWithDirection(direction));
end

function PuzzlePieceShadow:addShadowSprite(path, direction)
    local sp = GlobalFunction.createGameSpriteWithPath(path);
    sp:setAnchorPoint(PUZZLE_PIECE_SHADOW_ANCHOR);
    sp:setRotation(puzzle.PUZZLE_PIECE_SHADOW_DIRECTION_TO_DATA[direction]);
    self:addChild(sp);
    return sp;
end

function PuzzlePieceShadow:shadowGo()
    local moveTo = cc.MoveTo:create(0.2, cc.p(20, -40));
    self:runAction(moveTo);
end

function PuzzlePieceShadow:shadowBack()
    -- printf("shadowBack");
    local moveTo = cc.MoveTo:create(0.2, cc.p(20, -20));
    self:runAction(moveTo);
end
return PuzzlePieceShadow