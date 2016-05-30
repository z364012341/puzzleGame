--
-- Author: 黄泽昊
-- 功能: 小眼睛道具

local PuzzleSmallEyesProp = class("PuzzleSmallEyesProp", function ()
    return cc.Node:create();
end)
local PuzzlePropCoolingTimerComponent = require(PUZZLE_PROP_COOLING_TIMER_COMPONENT_PATH);
local PROP_TEXTURE_PATH = "anniuchakan.PNG";
local PROP_PROGRESS_TIMER_PATH = "small_eyes_gray.png";
local COOLING_SEQUENCE_TAG = 123
PuzzleSmallEyesProp.selfisCooling_ = nil;
function PuzzleSmallEyesProp:ctor()
    PuzzleSmallEyesProp.selfisCooling_ = false;
    self:init();
end
function PuzzleSmallEyesProp:init()
    self:addPropButton();
end
function PuzzleSmallEyesProp:addPropButton()
    local menuItem = cc.MenuItemSprite:create(GlobalFunction.createGameSpriteWithPath(PROP_TEXTURE_PATH), 
        GlobalFunction.createGameSpriteWithPath(PROP_TEXTURE_PATH));
    menuItem:setPosition(cc.p(0, 0));
    menuItem:registerScriptTapHandler(function ( sender )
        if self.selfisCooling_ then
            return;
        end
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_USE_SMALL_EYES);
        self:propCooling();
    end)
    local menu = cc.Menu:create();
    menu:setPosition(cc.p(0, 0));
    menu:addChild(menuItem);
    self:addChild(menu);
end
function PuzzleSmallEyesProp:propCooling()
    self.selfisCooling_ = true;
    local timer = PuzzlePropCoolingTimerComponent:create(PROP_PROGRESS_TIMER_PATH, PROP_SMALL_EYES_TIME*2, function (  )
        self.selfisCooling_ = false;
    end);
    timer:setPosition(cc.p(-4, 4))
    self:addChild(timer);
end
return PuzzleSmallEyesProp