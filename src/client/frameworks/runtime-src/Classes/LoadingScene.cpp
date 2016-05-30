#include "LoadingScene.h"
#include "StageDataManager.h"
#include "GameTextInfo.h"
#include "UserDataManager.h"
#include "SpriteTextureController.h"
#include "GameStageSelectionScene.h"
#include "SmartScaleController.h"
#include "ScoreWidgetManager.h"
#include "PuzzleStageDataManager.h"
#include "PuzzleStoreItemFactory.h"
namespace bubble_second {
    cocos2d::Scene * LoadingScene::createScene()
    {
        cocos2d::Scene* scene = cocos2d::Scene::create();
        LoadingScene* layer = LoadingScene::create();
        scene->addChild(layer);
        return scene;
    }

    LoadingScene::LoadingScene()
    {
    }

    LoadingScene::~LoadingScene()
    {
    }

    bool LoadingScene::init()
    {
        if (!Layer::init())
        {
            return false;
        }
        this->addBackground();
        this->runAction(cocos2d::CallFunc::create([=]() {
            this->beginLoading();
        }));
        return true;
    }

    void LoadingScene::beginLoading()
    {
        StageDataManager::getInstance()->initStageData();
        GameTextInfo::getInstance()->plistToMap();
        UserDataManager::getInstance()->readDataFile();
        SpriteTextureController::getInstance()->addResourcesTexture();
        ScoreWidgetManager::getInstance()->readBoneDateFromFile();
        PuzzleStageDataManager::getInstance()->loadPuzzleStageData();
        PuzzleStoreItemFactory::getInstance()->loadItemData();
        cocos2d::Director::getInstance()->replaceScene(GameStageSelectionScene::createScene());
    }

    void LoadingScene::addBackground()
    {
        auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        cocos2d::LayerColor* layer = cocos2d::LayerColor::create(cocos2d::Color4B::ORANGE, visibleSize.width, visibleSize.height);
        this->addChild(layer);


        cocos2d::Label* label = cocos2d::Label::createWithSystemFont("   Loading...", "", 80 * SmartScaleController::getInstance()->getPlayAreaZoom());
        label->setPosition(visibleSize.width/2, visibleSize.height/2);
        this->addChild(label);
    }
}