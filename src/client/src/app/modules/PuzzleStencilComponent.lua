--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的遮罩模板的凸起部分

local PuzzleStencilComponent = class("PuzzleStencilComponent", function (direction, insideOrOutside)
    return cc.Node:create();
end)

-- PuzzleStencilComponent.PUZZLE_COMPONENT_DIRECTION_TO_DATA = {
--     [PUZZLE_COMPONENT_LEFT] = {[PUZZLE_COMPONENT_ROTATION] = 0, [PUZZLE_COMPONENT_POSITION] = {x = PUZZLE_STENCIL_WIDTH/-2, y = 0}},
--     [PUZZLE_COMPONENT_RIGHT] = {[PUZZLE_COMPONENT_ROTATION] = 180, [PUZZLE_COMPONENT_POSITION] = {x = PUZZLE_STENCIL_WIDTH/2, y = 0}},
--     [PUZZLE_COMPONENT_TOP] = {[PUZZLE_COMPONENT_ROTATION] = 90, [PUZZLE_COMPONENT_POSITION] = {x = 0, y = PUZZLE_STENCIL_HEIGHT/2}},
--     [PUZZLE_COMPONENT_BOTTOM] = {[PUZZLE_COMPONENT_ROTATION] = -90, [PUZZLE_COMPONENT_POSITION] = {x = 0, y = PUZZLE_STENCIL_HEIGHT/-2}}
-- };

function PuzzleStencilComponent:ctor(direction, insideOrOutside)
    --printf("PuzzleStencilComponent");
    self:addPuzzleComponent(direction, insideOrOutside);
end

function PuzzleStencilComponent:addPuzzleComponent(direction, insideOrOutside)
    local sp = GlobalFunction.createGameSpriteWithPath(PUZZLE_COMPONENT_PATH);
    sp:setAnchorPoint(PUZZLE_COMPONENT_ANCHOR);

    -- if insideOrOutside == PUZZLE_STENCIL_COMPONENT_OUTSIDE then
    --     sp:setRotation(GlobalFunction.getPuzzlePiecePositionWithRotation(direction)+180);
    -- else
    --     sp:setRotation(GlobalFunction.getPuzzlePiecePositionWithRotation(direction));
    -- end
    sp:setRotation(GlobalFunction.getPuzzlePiecePositionWithRotation(direction, insideOrOutside));
    sp:setPosition(GlobalFunction.getPuzzlePiecePositionWithDirection(direction));
    self:addChild(sp);
end

return PuzzleStencilComponent