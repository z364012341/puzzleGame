--
-- Author: 黄泽昊
-- Date: 2016-03-04 12:06:13
-- 作用: 拼图的layer, 最下面的那层
local vertDefaultSource = "\n".."\n" ..
                  "attribute vec4 a_position;\n" ..
                  "attribute vec2 a_texCoord;\n" ..
                  "attribute vec4 a_color;\n\n" ..
                  "\n#ifdef GL_ES\n" ..
                  "varying lowp vec4 v_fragmentColor;\n" ..
                  "varying mediump vec2 v_texCoord;\n" ..
                  "\n#else\n" ..
                  "varying vec4 v_fragmentColor;" ..
                  "varying vec2 v_texCoord;" ..
                  "\n#endif\n" ..
                  "void main()\n" ..
                  "{\n" ..
                  "   gl_Position = CC_MVPMatrix * a_position;\n"..
                  "   v_fragmentColor = a_color;\n"..
                  "   v_texCoord = a_texCoord;\n" ..
                  "} \n"
local PuzzlePlayAreaInnerContainer = class("PuzzlePlayAreaInnerContainer", function ()
    return cc.Node:create();
end)
local PuzzlePiecesCollection = require(PUZZLE_PIECES_COLLECTION_PATH);
local PuzzleSelectedShow = require(PUZZLE_SELECTED_SHOW_PATH);
local PUZZLE_PLAY_SCENE_ZOOM_SCALE_PER_NUMBLE = 0.02;
local ANSWERS_NODE_ZORDER = -1;
local ANSWERS_BACKGROUND_ZORDER = ANSWERS_NODE_ZORDER-1;
function PuzzlePlayAreaInnerContainer:ctor()
    local function onNodeEvent(event)
        if event == "enter" then
            self:onEnter();
        elseif event == "exit" then
            self:onExit();
        end
    end
    self:registerScriptHandler(onNodeEvent);
    self:init();
end
function PuzzlePlayAreaInnerContainer:init()
    local collection = PuzzlePiecesCollection:create(PuzzleSelectedShow:getSelectedPicturePath());
    local puzzleNode = collection:getPuzzleNode();

    self:getEventDispatcher():dispatchEvent(GlobalFunction.createCustomEvent(EVENT_PUZZLE_ANSWER_LOAD, puzzleNode));
    self.answerNode_ = collection:getAnswerNode();
    self:setContentSize(self.answerNode_:getContentSize());
    self.answerNode_:setPositionX(self.answerNode_:getContentSize().width/-2);
    self.answerNode_:setPositionY(self.answerNode_:getContentSize().height/-2);
    self:addChild(self.answerNode_, ANSWERS_NODE_ZORDER);

    self:addAnswersBackground();
end
function PuzzlePlayAreaInnerContainer:addAnswersBackground()
    self.answer_background_ = GlobalFunction.createGameSpriteWithPath(PuzzleSelectedShow:getSelectedPicturePath());
    self.answer_background_:setOpacity(0);
    self:addChild(self.answer_background_, ANSWERS_BACKGROUND_ZORDER);
end

-- function PuzzlePlayAreaInnerContainer:addTouchesListerner()
--     local listener = cc.EventListenerTouchAllAtOnce:create();
--     listener:registerScriptHandler(self.onTouchMoved,cc.Handler.EVENT_TOUCHES_MOVED);
--     cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self);
--     local mouseListener = cc.EventListenerMouse:create();
--     mouseListener:registerScriptHandler(function(event)
--         self:setScale(math.max(0.1, self:getScale() + event:getScrollY()*-0.1));
--     end,cc.Handler.EVENT_MOUSE_SCROLL);
--     cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(mouseListener, self);
-- end
-- function PuzzlePlayAreaInnerContainer.onTouchMoved(touches, event)
--     if #touches == 1 then
--         event:getCurrentTarget():touchToMove(touches);
--         return;
--     end
--     event:getCurrentTarget():pinchToZoom(touches);
-- end

-- function PuzzlePlayAreaInnerContainer:calculateZoomScale(preDistance, locDistance)
--     local scale = self:getScale();
--     if locDistance>preDistance then
--         scale = scale + PUZZLE_PLAY_SCENE_ZOOM_SCALE_PER_NUMBLE;
--     else
--         scale = scale - PUZZLE_PLAY_SCENE_ZOOM_SCALE_PER_NUMBLE;
--     end
--     scale = math.min(scale, PUZZLE_PLAY_SCENE_ZOOM_SCALE_MAX);
--     scale = math.max(scale, PUZZLE_PLAY_SCENE_ZOOM_SCALE_MIN);
--     return scale;
-- end

-- function PuzzlePlayAreaInnerContainer:pinchToZoom(touches)
--     local dis1 = cc.pGetDistance(touches[1]:getPreviousLocation(), touches[2]:getPreviousLocation());
--     local dis2 = cc.pGetDistance(touches[1]:getLocation(), touches[2]:getLocation());
--     local middlePoint = cc.pMidpoint(touches[1]:getPreviousLocation(), touches[2]:getPreviousLocation());
--     local pointInLayer = self:convertToNodeSpace(middlePoint);
--     self:setScale(self:calculateZoomScale(dis1, dis2));
--     local pointAfterScale = self:convertToWorldSpace(pointInLayer);
--     local newPoint = cc.pAdd(cc.pSub(middlePoint, pointAfterScale), cc.p(self:getPosition()));
--     self:setPosition(newPoint);
-- end

-- function PuzzlePlayAreaInnerContainer:touchToMove(touches)
--     local dis = touches[1]:getDelta()
--     local zoomScale = self:getScale();
--     self:setPositionX(self:getPositionX() + dis.x);
--     self:setPositionY(self:getPositionY() + dis.y);
-- end
function PuzzlePlayAreaInnerContainer:getAnswersThumbnail()
    self:saveAnswerNodeData();
    return self.answerNode_;
end
function PuzzlePlayAreaInnerContainer:pushAnswersThumbnail()
    self.answerNode_:retain();
    self.answerNode_:removeFromParent();
    self.answerNode_:setScale(self.answer_node_scale_save_);
    self.answerNode_:setPosition(self.answer_node_pos_save_);
    self:addChild(self.answerNode_, ANSWERS_NODE_ZORDER);
    self.answerNode_:release();
end
function PuzzlePlayAreaInnerContainer:saveAnswerNodeData()
    self.answer_node_pos_save_ = cc.p(self.answerNode_:getPosition());
    self.answer_node_scale_save_ = self.answerNode_:getScale();
end
function PuzzlePlayAreaInnerContainer:useSmallEyesProp()
    local action = cc.Sequence:create(cc.FadeIn:create(PROP_SMALL_EYES_TIME), cc.FadeOut:create(PROP_SMALL_EYES_TIME), nil);
    self.answer_background_:runAction(action);
end
-- function PuzzlePlayAreaInnerContainer:playAnswersZoomInAction()

-- end
function PuzzlePlayAreaInnerContainer:onEnter()
    self.listener_ = {};
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_PUSH_ANSWERS_THUMBNAIL, function ( event )
        self:pushAnswersThumbnail();
    end));
    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_SMALL_EYES, function ( event )
        self:useSmallEyesProp();
    end));

    table.insert(self.listener_, cc.EventListenerCustom:create(EVENT_USE_BIG_EYES_PROP, function ( event )
        local answer_sp = GlobalFunction.createGameSpriteWithPath(PuzzleSelectedShow:getSelectedPicturePath());
        answer_sp:setPosition(answer_sp:getContentSize().width/2, answer_sp:getContentSize().height/2);
        bs.SpriteTextureController:getInstance():setGrayShader(answer_sp);
        local render = cc.RenderTexture:create(answer_sp:getContentSize().width, answer_sp:getContentSize().height);
        render:beginWithClear(0,0,0,0);
        answer_sp:visit();
        render:endToLua();
        local render_sp = cc.Sprite:createWithTexture(render:getSprite():getTexture());
        render_sp:setFlippedY(true);
        render_sp:setOpacity(0);
        render_sp:runAction(cc.Sequence:create(cc.DelayTime:create(1.24), cc.FadeIn:create(1.1), nil));--动画的播放时间2.25
        self:addChild(render_sp, ANSWERS_BACKGROUND_ZORDER-1);
    end));
    for _, listener in ipairs(self.listener_) do
        self:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1);
    end
end
function PuzzlePlayAreaInnerContainer:onExit()
    local eventDispatcher = self:getEventDispatcher();
    for _, listener in ipairs(self.listener_) do
        eventDispatcher:removeEventListener(listener);
    end
end
return PuzzlePlayAreaInnerContainer