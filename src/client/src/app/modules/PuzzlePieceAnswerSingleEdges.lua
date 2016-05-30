--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图答案描边  单边

local PuzzlePieceAnswerSingleEdges = class("PuzzlePieceAnswerSingleEdges", function (direction, insideOrOutside)
    return cc.Node:create();
end)
-- local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
local ANSWER_EDGES_COLOR = cc.c3b(231, 213, 186);
local PuzzlePieceSingleEdges = require(PUZZLE_PIECE_SINGLE_EDGES_PATH);

-- PuzzlePieceAnswerSingleEdges.LING_ANCHOR_POINT = PUZZLE_COMPONENT_ANCHOR; 
function PuzzlePieceAnswerSingleEdges:ctor(direction, insideOrOutside)
    --printf("PuzzlePieceAnswerSingleEdges");
    --local path = insideOrOutside == PUZZLE_STENCIL_COMPONENT_PLAIN and 
    --  PUZZLE_PIECE_ANSWER_SINGLE_EDGES_PLAIN_PATH or PUZZLE_PIECE_ANSWER_SINGLE_EDGES_NOT_PLAIN_PATH;
    self.single_edges_ = PuzzlePieceSingleEdges:create(direction, insideOrOutside);
    self.single_edges_:changeTextureColor(ANSWER_EDGES_COLOR); 
    --singleEdges._edgesSprite:setAnchorPoint({x = 5/189, y = 0.5}); 
    self:addChild(self.single_edges_);
end
function PuzzlePieceAnswerSingleEdges:blink()
    self.single_edges_:blink();
end
function PuzzlePieceAnswerSingleEdges:noBlink()
    self.single_edges_:noBlink();
end
return PuzzlePieceAnswerSingleEdges