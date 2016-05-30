--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的遮罩模板

local PuzzleStencil = class("PuzzleStencil", function (left, right, top, bottom)
    return cc.Node:create();
end)
local PuzzleStencilComponent = require(PUZZLE_STENCIL_COMPONENT_PATH);


function PuzzleStencil:ctor(left, right, top, bottom)
    --printf("PuzzleStencil");
    self:initHandle();
    self:initPuzzleComponent(left, right, top, bottom);
    self:setScale(PUZZLE_PIECE_SCALE);
end

function PuzzleStencil:initHandle()
    self.componentInsideOrOutsideToHandle = {
        [PUZZLE_STENCIL_COMPONENT_INSIDE] = self.addInsideComponent, 
        [PUZZLE_STENCIL_COMPONENT_OUTSIDE] = self.addOutsideComponent,
        [PUZZLE_STENCIL_COMPONENT_PLAIN] = self.addPlainComponent,
    };

end

function PuzzleStencil:initPuzzleComponent(left, right, top, bottom)
    local bodySprite = GlobalFunction.createGameSpriteWithPath(PUZZLE_STENCIL_MAINBODY_PATH);
    --bodySprite:setScale(0.99);
    self:addChild(bodySprite);

    self.componentInsideOrOutsideToHandle[left](self, PUZZLE_COMPONENT_LEFT);
    self.componentInsideOrOutsideToHandle[right](self, PUZZLE_COMPONENT_RIGHT);
    self.componentInsideOrOutsideToHandle[top](self, PUZZLE_COMPONENT_TOP);
    self.componentInsideOrOutsideToHandle[bottom](self, PUZZLE_COMPONENT_BOTTOM);
end

function PuzzleStencil:addOutsideComponent(componentDirection)
    self:addChild(PuzzleStencilComponent:create(componentDirection, PUZZLE_STENCIL_COMPONENT_OUTSIDE))
    self:addPlainComponent(componentDirection)
end

function PuzzleStencil:addInsideComponent(componentDirection)
    --print("inside component do nothing!");
end

function PuzzleStencil:addPlainComponent(componentDirection)
    self:addChild(PuzzleStencilComponent:create(componentDirection))
end
return PuzzleStencil