--
-- Author: 黄泽昊
-- Date: 2016-03-04 14:16:18
-- 功能: 一块拼图描边  单边

local PuzzlePieceSingleEdges = class("PuzzlePieceSingleEdges", function (direction, insideOrOutside)
    return cc.Node:create();
end)
-- local PuzzleBottomPlate = require(PUZZLE_BOTTOM_PLATE_PATH);
-- local PuzzlePieceSingleEdgesAnswer = require(PUZZLE_PIECE_ANSWER_PATH);
local EDGES_COLOR = cc.c3b(135, 123, 123);
-- PuzzlePieceSingleEdges.LING_ANCHOR_POINT = PUZZLE_COMPONENT_ANCHOR; 
function PuzzlePieceSingleEdges:ctor(direction, insideOrOutside)
    --printf("PuzzlePieceSingleEdges");
    self._edgesSprite = {};
    if insideOrOutside == PUZZLE_STENCIL_COMPONENT_PLAIN then
    	self._edgesSprite = GlobalFunction.createGameSpriteWithPath(PUZZLE_PLAIN_EDGES_PATH);
    else
    	self._edgesSprite = GlobalFunction.createGameSpriteWithPath(PUZZLE_NOT_PLAIN_EDGES_PATH);
    end
    self._edgesSprite:setAnchorPoint(PUZZLE_EDGES_ANCHOR);
    --self._edgesSprite:getTexture():setAntiAliasTexParameters();
    self._edgesSprite:setRotation(GlobalFunction.getPuzzlePiecePositionWithRotation(direction, insideOrOutside));
    self:addChild(self._edgesSprite);
    self:setPosition(GlobalFunction.getPuzzlePiecePositionWithDirection(direction));
    self:changeTextureColor(EDGES_COLOR);
end

function PuzzlePieceSingleEdges:changeTextureColor(color)
    --GlobalFunction.setGameSpriteTextureWithPath(path, self._edgesSprite);
    self._edgesSprite:setColor(color);
end
-- function PuzzlePieceSingleEdges:blink()
--     self.blink_edges_ = GlobalFunction.copyGameSprite(self._edgesSprite);
--     self.blink_edges_:setPosition(cc.p(self._edgesSprite:getPosition()));
--     self.blink_edges_:setRotation(self._edgesSprite:getRotation());
--     self.blink_edges_:setAnchorPoint(cc.p(self._edgesSprite:getAnchorPoint()));
--     --self.blink_edges_:setPosition(cc.p(0,0));
--     --self.blink_edges_:setPosition(cc.p(self._edgesSprite:getPosition()));
--     local point = self:getParent():convertToNodeSpace(self._edgesSprite:getParent():convertToWorldSpace(cc.p(self._edgesSprite:getPosition())));
--     self.blink_edges_:setPosition(point);
--     self:getParent():addChild(self.blink_edges_);
--     self.blink_edges_:setBlendFunc({src = gl.SRC_ALPHA, dst = gl.ONE})
--     --self.blink_edges_:changeTextureColor(cc.c3b(255,255,255));
--     --self.blink_edges_:setOpacity(0);
--     self.blink_edges_:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.FadeIn:create(0.2), cc.FadeOut:create(0.2), nil)));
-- end
-- function PuzzlePieceSingleEdges:noBlink()
--     self.blink_edges_:removeFromParent();
--     self.blink_edges_ = nil;
-- end
return PuzzlePieceSingleEdges