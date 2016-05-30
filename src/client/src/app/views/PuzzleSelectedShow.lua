--
-- Author: 黄泽昊
-- 功能: 拼图的选择pageview部分

local PuzzleSelectedShow = class("PuzzleSelectedShow", function ()
    return cc.Node:create();
end)
local PuzzleSelectedPageView = require(PUZZLE_SELECTED_PAGEVIEW_PATH);
PuzzleSelectedShow.selected_puzzle_path_ = "";


function PuzzleSelectedShow:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
    	end
    end
    self:registerScriptHandler(onNodeEvent);
    self:addTreasureMapPuzzlePageview();
    self:addLandscapePuzzlePageview();
	self:setCurrentPageView();
end

function PuzzleSelectedShow:addTreasureMapPuzzlePageview()
    self.treasure_map_pageview_ = self:createPageViewWithTypeName(TREASURE_MAP_PAGEVIEW_NAME);
    self:addChild(self.treasure_map_pageview_);
end
function PuzzleSelectedShow:addLandscapePuzzlePageview()
    self.landscape_pageview_ = self:createPageViewWithTypeName(LANDSCAPE_PAGEVIEW_NAME);
    self:addChild(self.landscape_pageview_);
end

function PuzzleSelectedShow:createPageViewWithTypeName( name )
 --    local pageview= ccui.PageView:create();
 --    pageview:setContentSize(SHOW_CONTENT_SIZE);
 --    --self:addChild(pageview);
	-- for _, path in ipairs(PAGEVIEW_INITAIL_DATA[name].PAGE_PATH) do
	--     pageview:addPage(self:createPageWithPath(path));
	-- end
	-- pageview:setVisible(PAGEVIEW_INITAIL_DATA[name].VISIBLE);
 --    pageview:setName(name);
 --    pageview:setCurrentPageIndex(0);
 --    pageview:setTouchEnabled(false);

 --    local guide_point = PuzzleSelectedPageViewPoint:create(#PAGEVIEW_INITAIL_DATA[name].PAGE_PATH);
 --    guide_point:setPosition();
 --    --guide_point:setPosition(cc.p(100, -50));
 --    --pageview:addChild(guide_point);
 --    return pageview, guide_point;
    return PuzzleSelectedPageView:create(name);
end
function PuzzleSelectedShow:changePageViewType()
	self.treasure_map_pageview_:setVisible(not self.treasure_map_pageview_:isVisible());
	self.landscape_pageview_:setVisible(not self.landscape_pageview_:isVisible());
	self:setCurrentPageView();
end
function PuzzleSelectedShow:setCurrentPageView()
	self.current_pageview_ = self.treasure_map_pageview_:isVisible() and self.treasure_map_pageview_ or self.landscape_pageview_;
end
function PuzzleSelectedShow:getCurrentPagePath()
	return PAGEVIEW_INITAIL_DATA[self.current_pageview_:getName()].PAGE_PATH[self.current_pageview_:getCurrentPageIndex()+1];
end
function PuzzleSelectedShow:onEnter()
    self.listener_ = {};
    local function changePageViewType( event )
		self:changePageViewType();
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_CHANGE_PAGEVIEW_TYPE, changePageViewType));

	local function scrollLeft( event )
		self.current_pageview_:scrollLeft();
	end
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_SELECTED_SCROLL_LEFT, scrollLeft));

	local function scrollRight( event )
		self.current_pageview_:scrollRight();
	end
	table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUZZLE_SELECTED_SCROLL_RIGHT, scrollRight));

    for _, listener in ipairs(self.listener_) do
    	self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzleSelectedShow:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
    	eventDispatcher:removeEventListener(listener);
    end
	PuzzleSelectedShow.selected_puzzle_path_ = self:getCurrentPagePath();
end
function PuzzleSelectedShow:getSelectedPicturePath()
    return PuzzleSelectedShow.selected_puzzle_path_
end
return PuzzleSelectedShow