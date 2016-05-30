--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的底板类
-- 索引坐标从左下角开始(1,1)
local PuzzleBottomPlate = class("PuzzleBottomPlate", function (index_x, index_y, path)
    return GlobalFunction.createGameSpriteWithPath(path);
end)

function PuzzleBottomPlate:ctor(index_x, index_y)
    --printf("PuzzleBottomPlate");
    assert(type(index_x) == "number")
    assert(type(index_y) == "number")
    self:setAnchorPoint(0, 0);
    --self:setScale(0.43);
    self:setPosition(self:getPosWithIndex(index_x, index_y));
end

function PuzzleBottomPlate:getPosWithIndex(index_x, index_y)
	assert(index_x >= PUZZLE_PIECES_COLLECTION_INDEX_START);
	assert(index_y >= PUZZLE_PIECES_COLLECTION_INDEX_START);
	local posX = PUZZLE_STENCIL_WIDTH * (-0.5 + index_x);
	local posY = PUZZLE_STENCIL_HEIGHT * (-0.5 + index_y);
	return -1*posX, -1*posY;
end
return PuzzleBottomPlate