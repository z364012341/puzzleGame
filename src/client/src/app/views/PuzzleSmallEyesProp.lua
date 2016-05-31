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
local COOLING_TIME = PROP_SMALL_EYES_TIME*2
PuzzleSmallEyesProp.isCooling_ = nil;
function PuzzleSmallEyesProp:ctor()
    PuzzleSmallEyesProp.isCooling_ = false;
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
        print("11111111111111111111" .. tostring(self.isCooling_));
        if self.isCooling_ then
            return;
        end
        --print("11111111111111111111");
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_USE_SMALL_EYES);
        self:propCooling();
    end)
    local menu = cc.Menu:create();
    menu:setPosition(cc.p(0, 0));
    menu:addChild(menuItem);
    self:addChild(menu);
end
function PuzzleSmallEyesProp:propCooling()
    local timer = PuzzlePropCoolingTimerComponent:create(PROP_PROGRESS_TIMER_PATH, COOLING_TIME);
    timer:setPosition(cc.p(-4, 4))
    self:addChild(timer);

    self.isCooling_ = true;
    self:runAction(cc.Sequence:create(cc.DelayTime:create(COOLING_TIME), cc.CallFunc:create(function ()
        self.isCooling_ = false;
        --cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(EVENT_END_SEARCH_PROP);
    end), nil));
end
return PuzzleSmallEyesProp