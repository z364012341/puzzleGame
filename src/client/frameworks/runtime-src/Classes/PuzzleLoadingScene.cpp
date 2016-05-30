#include <thread>
#include "PuzzleLoadingScene.h"
#include "cocostudio\CocoStudio.h"
#include "UserDataManager.h"
#include "SpriteTextureController.h"
#include "PuzzleStageDataManager.h"
#include "PuzzleStoreItemFactory.h"
#include "CCLuaEngine.h"
const std::string PUZZLE_LOADING_CSB_PATH = "PuzzleLoadingLayer.csb";
namespace bubble_second {
    cocos2d::Scene * bubble_second::PuzzleLoadingScene::createScene()
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        PuzzleLoadingScene* layer = PuzzleLoadingScene::create();
        scene->addChild(layer);
        return scene;
    }

    PuzzleLoadingScene::PuzzleLoadingScene()
    {
    }


    PuzzleLoadingScene::~PuzzleLoadingScene()
    {
    }
    bool PuzzleLoadingScene::init()
    {
        if (!Layer::init())
        {
            return false;
        }
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(PUZZLE_LOADING_CSB_PATH);
        this->addChild(csb_node);
        //csb_node->getChildByName("loading_2")->runAction(cocos2d::RepeatForever::create(cocos2d::RotateBy::create(3, 360)));
        //auto action = cocos2d::CSLoader::createTimeline(PUZZLE_LOADING_CSB_PATH);
        //csb_node->runAction(action);
        //action->gotoFrameAndPlay(0, true);
        //this->schedule([]() {}, );
        this->runAction(cocos2d::CallFunc::create([=]() {
            this->beginLoading();
        }));
        return true;
    }
    void PuzzleLoadingScene::beginLoading()
    {
        UserDataManager::getInstance()->readDataFile();
        SpriteTextureController::getInstance()->addResourcesTexture();
        PuzzleStageDataManager::getInstance()->loadPuzzleStageData();
        PuzzleStoreItemFactory::getInstance()->loadItemData();


#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
        // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
        auto runtimeEngine = RuntimeEngine::getInstance();
        runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
        runtimeEngine->start();
#else
        //cocos2d::LuaEngine::getInstance()->executeScriptFile("src/ReplacePuzzlePlayScene.lua");
        cocos2d::LuaEngine::getInstance()->executeString("cc.Director:getInstance():replaceScene(require(PUZZLE_START_SCENE_PATH):createScene());");
#endif
    }
}