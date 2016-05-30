
cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")
cc.FileUtils:getInstance():addSearchPath("res/ui/", false);
cc.FileUtils:getInstance():addSearchPath("res/fonts/", false);
cc.FileUtils:getInstance():addSearchPath("res/ui/gameRes/", false);
cc.FileUtils:getInstance():addSearchPath("res/ui/menuRes/", false);
cc.FileUtils:getInstance():addSearchPath("res/ui/daochu/", false);
cc.FileUtils:getInstance():addSearchPath("res/puzzle_ui/", false);
cc.FileUtils:getInstance():addSearchPath("res/animation/", false);
cc.FileUtils:getInstance():addSearchPath("res/stage/", false);
require "config"
require "cocos.init"
require("app.PuzzleMacro")
require("app.PuzzleGlobalFunction")
local function main()
    --local sceneGame = require("app.views.PuzzlePlayScene"):create()
    --local hello = bs.LoadingScene:createScene()
    --sceneGame:addChild(hello)
    --release_print(bubble_second);
	--require("app.MyApp"):create():run();

	--require("app.MyApp"):run("PuzzlePlayScene");

    --ccui.Button:create();
    math.randomseed(os.time());
    cc.Director:getInstance():runWithScene(bs.PuzzleLoadingScene:createScene());

    --cc.Director:getInstance():runWithScene(require(PUZZLE_START_SCENE_PATH):createScene());
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
