--
-- Author: 黄泽昊
-- 功能: 道具背景组件

local PuzzlePropsBackground = class("PuzzlePropsBackground", function ( event_name )
    return cc.Node:create();
end)
local BACKGROUND_PATH = "daojudi.PNG";
local BACKGROUND_SHADOW_PATH = "props_shadow.png";
--PuzzlePropsBackground.isCooling_ = nil;
function PuzzlePropsBackground:ctor(event_name)
    -- self.isCooling_ = false;
    self:init(event_name);
end
function PuzzlePropsBackground:init(event_name)
    --self.event_name_ = event_name;
    self:addBackground(event_name);
    self:addBackgroundShadow()
end
function PuzzlePropsBackground:addBackground(event_name)
    local menuItem = cc.MenuItemSprite:create(GlobalFunction.createGameSpriteWithPath(BACKGROUND_PATH),
    GlobalFunction.createGameSpriteWithPath(BACKGROUND_PATH));
    menuItem:setPosition(cc.p(0, 0));
    local function callback( ... )
        -- if self.isCooling_ then
        --     return
        -- end
        -- self.isCooling_ = true;
        -- if event_end_name ~= nil then
        --     self:runAction(cc.Sequence:create(cc.DelayTime:create(time), cc.CallFunc:create(function ()
        --         self.isCooling_ = false;
        --         cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(event_end_name);
        --     end), nil));
        -- end
        --注意一定要先运行动作在发送消息, 因为播放动画会暂停
        cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(event_name);
    end
    menuItem:registerScriptTapHandler(callback);
    local menu = cc.Menu:create();
    menu:setPosition(cc.p(0, 0));
    menu:addChild(menuItem);
    self:addChild(menu);
end
function PuzzlePropsBackground:addBackgroundShadow()
    local sp = GlobalFunction.createGameSpriteWithPath(BACKGROUND_SHADOW_PATH);
    sp:setPosition(cc.p(20, -45));
    self:addChild(sp, -1);
end
return PuzzlePropsBackground