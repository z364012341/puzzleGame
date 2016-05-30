--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 选择pageview

local PuzzleSelectedPageView = class("PuzzleSelectedPageView", function (name)
    return cc.Node:create();
end)
local SHOW_CONTENT_SIZE = cc.size(402, 604);

local PuzzleSelectedPageViewPoint = require(PUZZLE_SELECTED_PAGEVIEW_POINT_PATH);
function PuzzleSelectedPageView:ctor(name)
    self:init(name);
end
function PuzzleSelectedPageView:init(name)
    local pageview= ccui.PageView:create();

    pageview:setContentSize(SHOW_CONTENT_SIZE);
    --self:addChild(pageview);
	for _, path in ipairs(PAGEVIEW_INITAIL_DATA[name].PAGE_PATH) do
	    pageview:addPage(self:createPageWithPath(path));
	end
	self:setVisible(PAGEVIEW_INITAIL_DATA[name].VISIBLE);
    self:setName(name);
    pageview:setCurrentPageIndex(0);
    pageview:setTouchEnabled(false);
    self.pageview_ = pageview;
    self:addChild(self.pageview_);

    self.guide_point_ = PuzzleSelectedPageViewPoint:create(#PAGEVIEW_INITAIL_DATA[name].PAGE_PATH);
    self.guide_point_:setPositionX(self.pageview_:getContentSize().width/2);
    self.guide_point_:setPositionY(-70);
    self:addChild(self.guide_point_);
end
function PuzzleSelectedPageView:createPageWithPath( path )
    local layout = ccui.Layout:create();
    local sp = GlobalFunction.createGameSpriteWithPath(path);
    local sp_size = sp:getContentSize();
    local scale = SHOW_CONTENT_SIZE.height / sp:getContentSize().height;
    if sp_size.width*scale > SHOW_CONTENT_SIZE.width then
        local rext_x = (sp_size.width - SHOW_CONTENT_SIZE.width/scale)/2;
        local rect = {x = rext_x, y = 0, width = SHOW_CONTENT_SIZE.width/scale, height =  sp_size.height};
        sp:setTextureRect(rect);
    end
    sp:setScale(SHOW_CONTENT_SIZE.height / sp:getContentSize().height);
    sp:setPosition(cc.p(SHOW_CONTENT_SIZE.width/2, SHOW_CONTENT_SIZE.height/2));
    layout:addChild(sp);
    layout:setContentSize(SHOW_CONTENT_SIZE);
    return layout;
end
function PuzzleSelectedPageView:scrollToPage(index)
	self.pageview_:scrollToPage(index);
	self.guide_point_:scrollToPage(self.pageview_);
end
function PuzzleSelectedPageView:getCurrentPageIndex(index)
	return self.pageview_:getCurrentPageIndex();
end
function PuzzleSelectedPageView:scrollLeft()
	if self:getCurrentPageIndex()-1 < 0 then
		return;
	end
	self:scrollToPage(self:getCurrentPageIndex()-1);
end
function PuzzleSelectedPageView:scrollRight()
	if self:getCurrentPageIndex()+1 > #PAGEVIEW_INITAIL_DATA[self:getName()].PAGE_PATH-1 then
		return;
	end
	self:scrollToPage(self:getCurrentPageIndex()+1);
end

return PuzzleSelectedPageView