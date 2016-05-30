--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用:

local PuzzlePlayArea = class("PuzzlePlayArea", function ()
    return cc.Node:create();
end)
local PuzzlePlayAreaInnerContainer = require(PUZZLE_PLAY_AREA_INNER_CONTAINER);
local PUZZLE_AREA_EDGE_PATH = "pintudi.PNG";
local COLOR_LAYER_WIDTH = 656;
local COLOR_LAYER_HEIGHT = 805;

function PuzzlePlayArea:ctor()
    self:init();
end
function PuzzlePlayArea:init()

    local background = self:getBackgroundColorLayer();
    self:addChild(background, -1);
    self:initPlayArea();
    self:addAreaWindowsEdge();
end
function PuzzlePlayArea:initPlayArea()
    local win_clip = cc.ClippingNode:create(self:getBackgroundColorLayer());
    self:addChild(win_clip);
    self.play_area_ = PuzzlePlayAreaInnerContainer:create();
    win_clip:addChild(self.play_area_);
    self.play_area_:setScale(self:calculatePuzzleScale());
end
function PuzzlePlayArea:calculatePuzzleScale()
    return self:calculatePuzzleScaleWithSize(self.play_area_:getContentSize());
end
function PuzzlePlayArea:calculatePuzzleScaleWithSize(size)
    return GlobalFunction.calculateMinSizeScale(cc.size(COLOR_LAYER_WIDTH, COLOR_LAYER_HEIGHT), size)*0.96;
end
function PuzzlePlayArea:getBackgroundColorLayer()
    local colorLayer = cc.LayerColor:create(PUZZLE_SHOW_LAYER_COLOR_C4B, COLOR_LAYER_WIDTH, COLOR_LAYER_HEIGHT);
    colorLayer:setPosition(cc.p(colorLayer:getContentSize().width/-2, colorLayer:getContentSize().height/-2));
    return colorLayer;
end
function PuzzlePlayArea:createWindowsEdge()
    return GlobalFunction.createGameSpriteWithPath(PUZZLE_AREA_EDGE_PATH);
end
function PuzzlePlayArea:addAreaWindowsEdge()
    local win_edge = self:createWindowsEdge();
    self:addChild(win_edge, 1);
    local listener = cc.EventListenerTouchOneByOne:create();
    listener:setSwallowTouches(true);
    local function onTouchBegan(touch, event)
        if cc.rectContainsPoint(win_edge:getBoundingBox(), win_edge:getParent():convertTouchToNodeSpace(touch)) then
            return false;
        end
        return true;
    end
    listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN);
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, win_edge);
end
function PuzzlePlayArea:getThumbnail()
    local color_layer = self:getBackgroundColorLayer();
    local node = cc.Node:create();
    node:addChild(color_layer);
    local thumbnail = self:getThumbnailWithoutBackground();
    thumbnail:setScale(self:calculatePuzzleScale());
    local thumbnail_x = thumbnail:getContentSize().width*thumbnail:getScale()/-2;
    local thumbnail_y = thumbnail:getContentSize().height*thumbnail:getScale()/-2;
    thumbnail:setPosition(cc.p(thumbnail_x, thumbnail_y));
    node:addChild(thumbnail, 1);
    node:addChild(self:createWindowsEdge());
    return node;
end

function PuzzlePlayArea:getThumbnailWithoutBackground()
    local node = cc.Node:create();
    local thumbnail = self.play_area_:getAnswersThumbnail();
    thumbnail:retain();
    thumbnail:removeFromParent();
    node:addChild(thumbnail);
    thumbnail:release();
    return node;
end
function PuzzlePlayArea:getAnswersThumbnail()
    return self.play_area_:getAnswersThumbnail()
end
return PuzzlePlayArea