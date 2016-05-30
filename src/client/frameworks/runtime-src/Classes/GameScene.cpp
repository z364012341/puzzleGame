#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "GameBubbleMap.h"
#include "BubbleFactory.h"
#include "GamePlayController.h"
#include "GameBubbleMap.h"
#include "BarrelBottom.h"
#include "ScoreWidget.h"
#include "ScoreWidgetManager.h"
#include "GameScoreController.h"
#include "SpriteTextureController.h"
#include "SmartScaleController.h"
#include "ColorBubble.h"
#include "GameCharacter.h"
#include "BaseProperty.h"
#include "PropertiesFactory.h"
#include "ZCGConfigDataDict.h"
#include "PropsSelectAlert.h"
#include "BaseWeapon.h"
#include "StavesProperty.h"
#include "BubbleSightingDevice.h"
#include "BigBackgroundEffect.h"
#include "RainbowSealManager.h"
#include "ScoreProgressMenu.h"
#include "StartNumbleModule.h"
#include "GamePauseAlert.h"
#include "GameDefeatAlert.h"
#include "GameDefeatBuyPropsAlert.h"
#include "GameVictoryAlert.h"
#include "GameStageSelectionScene.h"
#include "UserDataManager.h"
#include "EnterPropsViewManager.h"
#include "StageDataManager.h"
#include "ButtonEffectController.h"
#include "BarrelScoreLabelNode.h"
#include "PopScoreLabelComponent.h"
#include "GameStandbyTimer.h"
#include "StageTypeLogo.h"
#include "AddBubbleNumbleCommodity.h"
#include "GameBubbleMapImple.h"
#include "BubbleMainSightingDevice.h"
const std::string GAME_RIGHT_INFO_CSB = "GameTaskNumble.csb";
const std::string GAME_SCORE_INFO_CSB = "GameScoreNumble.csb";
const std::string GAME_SCORE_LABEL_NAME = "gameScoreLabel";
const std::string GAME_STAGE_TYPE_SPRITE_NAME = "stageTypeSprite";
const std::string BARREL_SCORE_LABEL_NODE_NAME = "BarrelScoreLabelNode";
const std::string UI_NAME_GAME_PLAYING_MENU = "gamePlayMenu";      //��Ϸ�����Ĳ˵�
const std::string UI_NAME_COMPLETED_TASK = "completedNumble";//�����Ŀ���label
const std::string UI_NAME_GAME_TASK = "taskNumble";//ʤ������Ŀ���label
const std::string BUBBLE_MAP_LINE_PATH = "xian.PNG"; //����������
const std::string BUBBLE_MAP_LINE_NAME = "wavy_line"; //����������
const float GAME_SCORE_PERCENT_X = 0.1647f; //�÷ֵ�label��x����ٷֱ�
const float GAME_RIGHT_LABEL_PERCENT_X = 0.8353f; //�ұߵ�ʤ��������label��x����ٷֱ�
const float GAME_TOP_INFO_POS_Y_PERCENT = 0.85f; //y��λ�ðٷֱ�
const float GAME_PLAY_HEIGHT = 1130.0f;//��ȥ���²˵��ĸ߶�
const float BOTTOM_UI_BACKGROUND_HEIGHT = 90.0f; //��Ϸ��������ui�ı���ͼ��Ҫ�ĸ߶�
const float GAME_PROPS_BACKGROUND_PERCENT_Y = 0.0525f;  //����item������y����ٷֱ�                        
const float PROPS_BACKGROUND_PERCENT_X_FIRST = 0.3468f;//����item_1������X����ٷֱ�
const float PROPS_BACKGROUND_PERCENT_X_FOURTH = 0.8931f; //����item_1������X����ٷֱ�
const float PROPS_BACKGROUND_PERCENT_PER_DISTANCE = (PROPS_BACKGROUND_PERCENT_X_FOURTH - PROPS_BACKGROUND_PERCENT_X_FIRST)/3;
const float PROPS_BACKGROUND_PERCENT_X_SECOND = PROPS_BACKGROUND_PERCENT_X_FIRST+PROPS_BACKGROUND_PERCENT_PER_DISTANCE; //����item_1������X����ٷֱ�
const float PROPS_BACKGROUND_PERCENT_X_THIRD = PROPS_BACKGROUND_PERCENT_X_FIRST + PROPS_BACKGROUND_PERCENT_PER_DISTANCE*2; //����item_1������X����ٷֱ�
const std::string UI_NAME_BARRELHEAD_NODE = "barrelhead";        //Ͱ��
const std::string UI_NAME_BARREL_NODE = "barrel_body"; //Ͱ����
const std::string UI_NAME_BUBBLE_USE_COUNT = "bubble_numble_label";//С��ʹ������label
const std::string UI_NAME_SECOND_BUBBLE_STORE = "second_bubble_store";        //��׼���Աߵ�С��
const int BARRELHEADEDGE_BODY_RADIUS = 20;  //Ͱ�߸���뾶
const float POP_VICTORY_ALERT_DELAYTIME = 1.5f;
namespace bubble_second {
    cocos2d::Scene* GameScene::createScene(int cell_numble, int numble)
    {
        cocos2d::Scene* scene = cocos2d::Scene::createWithPhysics();

        //��ʾ�����������״̬, ��ʾ��ɫ�Ŀ�, �������
        if (ZCGConfigDataDict::getInstance()->getIntData(KEY_OPEN_CMD_SHOW) == 1)
        {
            scene->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
        }
        scene->getPhysicsWorld()->setGravity(PHYSICS_WORLD_GRAVITY_VEC2*SmartScaleController::getInstance()->getPlayAreaZoom());
        StageData data(cell_numble, numble);
        GameScene* layer = GameScene::createWithStageNumble(data);
        scene->addChild(layer);
        return scene;
    }

    GameScene * bubble_second::GameScene::createWithStageNumble(StageData stage_data)
    {
        GameScene *pRet = new(std::nothrow) GameScene();
        if (pRet && pRet->initWithStageNumble(stage_data))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    void GameScene::clearController()
    {
        GameScoreController::getInstance()->clear();
        ScoreWidgetManager::getInstance()->clear();
        RainbowSealManager::getInstance()->clear();
    }

    bool GameScene::initWithStageNumble(StageData stage_data)
    {
        if (!Layer::init())
        {
            return false;
        }
        this->addGameBackground(stage_data.cell_numble);
        this->setPresentStageData(stage_data);
        this->setStageType(StageDataManager::getInstance()->getStageTypeWithNumble(this->getPresentStageNumble()));
        this->clearController();
        property_bubble_ = nullptr;
        props_weapon_ = nullptr;
        first_flag_ = true;
        //barrel_score_display_flag_ = false;
        game_character_ = nullptr;
        this->initHandle();
        this->addKeyboardEventListener();



        //char a[8][16];
        //int e1 = &a[4][1] - &a[3][4];

        //char *p = "Gameloft rainbow sss";
        //char e2 = *(char*)(((short*)&p[5]) + 4);
        //int e3 = -1 >> 5;
        //int e4 = (15 ^ 0x10) << (7 & ~3);
        //char * p2;
        //int e5 = sizeof(p2);
        //char * p3[20];
        //int e6 = sizeof(p3);
        return true;
    }

    GameScene::GameScene()
    {
    }
    GameScene::~GameScene()
    {
    }

	void GameScene::updateStart(float delta)
	{
		this->getScenePhysicsWorld()->setAutoStep(false);
		scheduleUpdate();
	}

	void GameScene::update(float delta)
	{
		// use fixed time and calculate 3 times per frame makes physics simulate more precisely.
		for (int i = 0; i < 3; ++i)
		{
			this->getScenePhysicsWorld()->step(1 / 180.0f);
		}
	}
    void GameScene::onEnter()
    {
        Layer::onEnter();
        this->addEventListenerCustom();
        this->initChildren();
        this->initCharacter();
        this->initBubbleMap(this->getPresentStageNumble());
        this->addBubbleSightingDevice();
        this->addPrepareBubble();
		this->playPrepareBubbleStanbyAction();
        edge_shape_node_ = cocos2d::Node::create();
        edge_shape_node_->setName(MAP_PHYSICS_BORDER_NAME);
        addChild(edge_shape_node_);
        this->setPhysicsWorldBody();
        //this->scheduleOnce(CC_SCHEDULE_SELECTOR(GameScene::updateStart), 1);
        GamePlayController::getInstance()->setGameSceneDelegate(this);
    }

    void GameScene::onExit()
    {
        this->removeEventListenerCustom();
        GamePlayController::getInstance()->setGameSceneDelegate(nullptr);
        Layer::onExit();
    }

  //  void GameScene::addArmatureFile()
  //  {
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(LIGHTNING_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(ONE_ROUND_BOMB_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(TWO_ROUND_BOMB_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BLACK_HOLE_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BARREL_BOTTOM_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(RAINBOW_CHARACTOR_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(RAINBOW_BUBBLE_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(SCOREWIDGET_ARMATURE_BLUE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
  //  }

  //  void GameScene::removeArmatureFile()
  //  {
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(LIGHTNING_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(ONE_ROUND_BOMB_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(TWO_ROUND_BOMB_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BLACK_HOLE_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BARREL_BOTTOM_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(COLOR_BUBBLE_ELIMINATE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BALL_LIGHTNING_BUBBLE_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BARREL_BOTTOM_STANDBY_EFFECT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_ONCE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_FIRE_REPEAT_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(BIG_COMBO_EFFECT_UNDER_FIRE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(RAINBOW_CHARACTOR_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(RAINBOW_BUBBLE_ARMATURE_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_FROG_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(MUTIPLE_SEAL_BUBBLE_ARMATURE_GOG_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(SCOREWIDGET_ARMATURE_BLUE_PATH);
		//cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(GAME_CHARACTER_ARMATURE_LAOHU_PATH);
  //      cocostudio::ArmatureDataManager::getInstance()->removeArmatureFileInfo(WINDMILL_BUBBLE_DEMON_ARMATURE_PATH);
  //  }

    void GameScene::addBubbleSightingDevice()
    {
        //BubbleSightingDevice* sight = BubbleSightingDevice::create();
        main_sighting_device_ = BubbleMainSightingDevice::create();
        main_sighting_device_->setPosition(this->getGunsightPosition());
        csb_node_->addChild(main_sighting_device_, UI_ZORDER_SIGHTING_DEVICE);
        //sight->turnOnDeviceOnce();
        //sight->rotateSightingDevice(5, this->getMapMaxPositionY());//��һ����ʼ�Ƕ�..��Ȼ����һ��Ῠ
    }

    void GameScene::initChildren()
    {
        auto smart_scale = SmartScaleController::getInstance();
        float zoom = smart_scale->getPlayAreaZoom();
        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        std::function<float(float, float)> getPosFunc = [&](float visiblesize, float gamesize) {
            return (visiblesize - gamesize*zoom) / 2;
        };
        {
            csb_node_ = cocos2d::CSLoader::createNode(GAME_LAYER_CSB);
            csb_node_->setName(UI_NAME_GAME_PLAY_AREA_NODE);
            csb_node_->setScale(zoom);
            float x = (visible_size.width - GAME_DESIGN_RESOLUTION_WIDTH*zoom) / 2;
            csb_node_->setPosition(x, visible_size.height*BOTTOM_UI_BACKGROUND_HEIGHT/ GAME_DESIGN_RESOLUTION_HEIGHT);
            this->addChild(csb_node_);
            this->addExchangeBubbleListener();
            this->initUIZOrder();
            this->initBarrels();
        }
        {
            cocos2d::Sprite* bottom_ui_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(BOTTOM_UI_BACKGROUND_PATH);
            bottom_ui_bg->setPosition(cocos2d::Vec2(visible_size.width/2, 0.0f));
            bottom_ui_bg->setAnchorPoint(cocos2d::Vec2(0.5f, 0.0f));
            bottom_ui_bg->setScaleX(smart_scale->getFixedWidthZoom());
            cocos2d::Rect bottom_ui_bg_rect = bottom_ui_bg->getBoundingBox();
            float scale_y = csb_node_->getPositionY() / BOTTOM_UI_BACKGROUND_HEIGHT;
            bottom_ui_bg->setScaleY(scale_y);  
            this->addChild(bottom_ui_bg, UI_ZORDER_MENU);
        }
        {//�������
            color_bomb_property_ = PropertiesFactory::getInstance()->createPropertyWithName(PROPS_COLOR_BOMB_NAME);
            color_bomb_property_->setScale(zoom);
            color_bomb_property_->setPosition(visible_size.width * PROPS_BACKGROUND_PERCENT_X_FIRST,
                visible_size.height * GAME_PROPS_BACKGROUND_PERCENT_Y);
            this->addChild(color_bomb_property_, UI_ZORDER_MENU_INFO);
        }
        {//Сľ������
            wooden_hammer_property_ = PropertiesFactory::getInstance()->createPropertyWithName(PROPS_WOODEN_HAMMER_NAME);
            wooden_hammer_property_->setScale(zoom);
            wooden_hammer_property_->setPosition(visible_size.width * PROPS_BACKGROUND_PERCENT_X_SECOND,
                visible_size.height * GAME_PROPS_BACKGROUND_PERCENT_Y);
            this->addChild(wooden_hammer_property_, UI_ZORDER_MENU_INFO);
        }
        {//2Ȧը������
            bomb_bomb_property_ = PropertiesFactory::getInstance()->createPropertyWithName(PROPS_BOMB_BOMB_NAME);
            bomb_bomb_property_->setScale(zoom);
            bomb_bomb_property_->setPosition(visible_size.width * PROPS_BACKGROUND_PERCENT_X_THIRD, visible_size.height * GAME_PROPS_BACKGROUND_PERCENT_Y);
            this->addChild(bomb_bomb_property_, UI_ZORDER_MENU_INFO);
        }
        {//�������ȵ���
            staves_property_ = PropertiesFactory::getInstance()->createPropertyWithName(PROPS_STAVES_NAME);
            staves_property_->setScale(zoom);
            staves_property_->setPosition(visible_size.width * PROPS_BACKGROUND_PERCENT_X_FOURTH, visible_size.height * GAME_PROPS_BACKGROUND_PERCENT_Y);
            this->addChild(staves_property_, UI_ZORDER_MENU_INFO);
        }
        this->setPropertyTouchEnabled(false);
        {//���������ı���
            cocos2d::Sprite* top_ui_bg = SpriteTextureController::getInstance()->createGameSpriteWithPath(TOP_UI_BACKGROUND_PATH);
            top_ui_bg->setPosition(cocos2d::Vec2(0, visible_size.height));
            top_ui_bg->setName(UI_NAME_TOP_UI_BACKGROUND);
            top_ui_bg->setAnchorPoint(cocos2d::Vec2(0.0f, 1.0f));
            this->addChild(top_ui_bg, UI_ZORDER_MENU_INFO);
        }

        {//�������ǽ�����
            cocos2d::Rect rect = this->getChildByName(UI_NAME_TOP_UI_BACKGROUND)->getBoundingBox();
            float pos_y = visible_size.height - rect.size.height*GAME_TOP_INFO_POS_Y_PERCENT / 2;
			score_progress_ = ScoreProgressMenu::create();
			score_progress_->setPosition(cocos2d::Vec2(visible_size.width / 2, visible_size.height));
			score_progress_->setScale(zoom);
			this->addChild(score_progress_, UI_ZORDER_MENU_INFO);

            //��߷�����label
            cocos2d::Node* score_node = cocos2d::CSLoader::createNode(GAME_SCORE_INFO_CSB);
            score_node->setName(UI_NAME_SCORE_TEXT);
            score_node->setPosition(cocos2d::Vec2(visible_size.width*GAME_SCORE_PERCENT_X, pos_y));
            this->addChild(score_node, UI_ZORDER_MENU_INFO);
            //�����ұߵ�ʤ����������
            cocos2d::Node* top_right_ui = cocos2d::CSLoader::createNode(GAME_RIGHT_INFO_CSB);
            top_right_ui->setName(GAME_RIGHT_INFO_NAME);
            top_right_ui->setPosition(cocos2d::Vec2(visible_size.width*GAME_RIGHT_LABEL_PERCENT_X, pos_y));
            this->addChild(top_right_ui, UI_ZORDER_MENU_INFO);
            //�ؿ�����ͼ��
            //SpriteTextureController::getInstance()->setStageTypeSprite(
            //    dynamic_cast<cocos2d::Sprite*>(top_right_ui->getChildByName(GAME_STAGE_TYPE_SPRITE_NAME)), 
            //    this->getStageType());
            //StageTypeLogo* logo = StageTypeLogo::create(this->getStageType());
            top_right_ui->getChildByName(GAME_STAGE_TYPE_SPRITE_NAME)->addChild(StageTypeLogo::create(this->getStageType()));
            //�˵���ť
			pause_menu_ = dynamic_cast<cocos2d::ui::Button*>(top_right_ui->getChildByName(UI_NAME_GAME_PLAYING_MENU));
			ButtonEffectController::setButtonZoomScale(pause_menu_);
			pause_menu_->addTouchEventListener([=](cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
                {
                    this->popPauseAlert();
                }
            });
            //����ͺư
            {
                cocos2d::Sprite* skillSprite = SpriteTextureController::getInstance()->createGameSpriteWithPath("jineng.PNG");
                skillSprite->setAnchorPoint(cocos2d::Vec2::ZERO);
                skillSprite->setScale(zoom);
                this->addChild(skillSprite, UI_ZORDER_MENU_INFO);
            }
        }
        //{   //����̨�ϵ�����
        //    cocos2d::Sprite* swirl = SpriteTextureController::getInstance()->createGameSpriteWithPath(GUNSIGHT_SWIRL_RED_PATH);
        //    swirl->setPosition(this->getGunsightPosition());
        //    csb_node_->addChild(swirl, UI_ZORDER_GUNSIGHT_SWIRL);
        //    swirl->runAction(cocos2d::RepeatForever::create(cocos2d::RotateBy::create(UI_SWIRL_ROTATIEBY_TIME, UI_SWIRL_ROTATIEBY_DEGREE)));
        //}
        this->initBarrelScoreLabel();
        this->addStandbyTimer();
    }

    void bubble_second::GameScene::addGameBackground(int cell_numble)
    {
        cocos2d::Sprite* game_bg = SpriteTextureController::getInstance()->createGameBackgroundSprite(cell_numble);
        game_bg->setScale(SmartScaleController::getInstance()->getFixedHeightZoom());
        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        game_bg->setPosition(cocos2d::Vec2(visible_size.width / 2, visible_size.height / 2));
        this->addChild(game_bg, UI_ZORDER_BACKGROUND);
    }

    void GameScene::initCharacter()
    {
        game_character_ = GameCharacter::create();
        game_character_->setPosition(this->getGunsightPosition());
        csb_node_->addChild(game_character_, UI_ZORDER_BACKGROUND);
    }

    void GameScene::initHandle()
    {
        props_name_to_handle_[COLOR_BOMB_BUBBLE_NAME] = [=](BaseProperty* property) {this->haveShootPropsBubble(property); };
        props_name_to_color_[PROPS_COLOR_BOMB_NAME] = kBubbleColorBomb;
        props_name_to_color_[PROPS_BOMB_BOMB_NAME] = kBubbleBombBombProperty;
        //bubblecolor_to_swirl_[kBubbleTransparent] = "";
        //bubblecolor_to_swirl_[kBubbleRed] = GUNSIGHT_SWIRL_RED_PATH;
        //bubblecolor_to_swirl_[kBubbleYellow] = GUNSIGHT_SWIRL_YELLOW_PATH;
        //bubblecolor_to_swirl_[kBubbleOrange] = GUNSIGHT_SWIRL_ORANGE_PATH;
        //bubblecolor_to_swirl_[kBubbleGreen] = GUNSIGHT_SWIRL_GREEN_PATH;
        //bubblecolor_to_swirl_[kBubblePink] = GUNSIGHT_SWIRL_PINK_PATH;
        //bubblecolor_to_swirl_[kBubblePurple] = GUNSIGHT_SWIRL_PURPLE_PATH;
        //bubblecolor_to_swirl_[kBubbleBlue] = GUNSIGHT_SWIRL_BLUE_PATH;
    }

    void GameScene::initBarrelScoreLabel()
    {
        //auto pos_func = [=](const std::string& name) {
        //    cocos2d::Node* node = csb_node_->getChildByName(name);
        //    node->setPositionY(node->getPositionY() - BARREL_SCORE_LABEL_OFFS_Y);
        // };
        //this->handleBarrelScoreLabel(pos_func);
        barrel_score_node_ = BarrelScoreLabelNode::create();
        barrel_score_node_->setPosition(375.0f, 0.0f);
        barrel_score_node_->setName(BARREL_SCORE_LABEL_NODE_NAME);
        csb_node_->addChild(barrel_score_node_, UI_ZORDER_BARREL_NUMBLE_NODE);
    }

    void GameScene::addStandbyTimer()
    {
        this->addChild(GameStandbyTimer::create());
    }

    cocos2d::Node* GameScene::getGunsight()
    {
        return csb_node_->getChildByName(UI_NAME_GUNSIGHT);
    }

    cocos2d::Node* GameScene::getSecondBubbleStoreNode()
    {
        return csb_node_->getChildByName(UI_NAME_SECOND_BUBBLE_STORE);
    }

    int GameScene::getPresentStageNumble()
    {
        return stage_data_.level_numble;
    }

    void GameScene::setPresentStageData(StageData numble)
    {
        stage_data_ = numble;
    }

    int GameScene::getPresentStageCellNumble()
    {
        return stage_data_.cell_numble;
    }

    StageData GameScene::getPresentStageData()
    {
        return stage_data_;
    }

    cocos2d::ui::TextBMFont* GameScene::getScoreUI()
    {
        return dynamic_cast<cocos2d::ui::TextBMFont*>(this->getChildByName(UI_NAME_SCORE_TEXT)->getChildByName(GAME_SCORE_LABEL_NAME));
    }

    void GameScene::setPhysicsWorldBody()
    {
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        //����һ����������, ��С����Ļ�ĳߴ���ͬ, ʹ��Ĭ�ϲ���, debug��Ŀ��Ϊ3������
        float zoom = SmartScaleController::getInstance()->getPlayAreaZoom();
        cocos2d::Size world_size = cocos2d::Size(GAME_DESIGN_RESOLUTION_WIDTH, bubble_map_node_->getPositionY() + BUBBLE_RADIUS)*zoom;
        auto body = cocos2d::PhysicsBody::createEdgeBox(world_size,
            cocos2d::PhysicsMaterial(PHYSICS_WORLD_BODY_DENSITY, PHYSICS_WORLD_BODY_RESTITUTION, PHYSICS_WORLD_FRICTION), PHYSICS_WORLD_BODY_BORDER*zoom);
        //��ͼ�κ͸ոմ����������
        body->setContactTestBitmask(BITMASK_PHYSICS_WORLD_CONTACTTEST);
        body->setGroup(-2);
		if (cocos2d::PhysicsBody* body = edge_shape_node_->getPhysicsBody())
		{
			edge_shape_node_->removeComponent(body);
		}
        edge_shape_node_->setPhysicsBody(body);
        //����ͼ�ε�λ������Ļ���м�
        edge_shape_node_->setPosition(visibleSize.width / 2, world_size.height / 2 + csb_node_->getPositionY());
    }

    //void GameScene::updateStart(float delta)
    //{
    //    this->getScenePhysicsWorld()->setAutoStep(false);
    //    scheduleUpdate();
    //}

    //void GameScene::update(float delta)
    //{
    //    // use fixed time and calculate 3 times per frame makes physics simulate more precisely.
    //    for (int i = 0; i < 3; ++i)
    //    {
    //        this->getScenePhysicsWorld()->step(1 / 180.0f);
    //    }
    //}

    cocos2d::PhysicsWorld* GameScene::getScenePhysicsWorld()
    {
        return dynamic_cast<cocos2d::Scene*>(this->getParent())->getPhysicsWorld();
    }

    void GameScene::initBubbleMap(int stage_numble)
    {
        bubble_map_node_ = cocos2d::Node::create();
        bubble_map_node_->setName(BUBBLE_MAP_NODE_NAME);

        cocos2d::Sprite* line = SpriteTextureController::getInstance()->createGameSpriteWithPath(BUBBLE_MAP_LINE_PATH);
        line->setName(BUBBLE_MAP_LINE_NAME);
        line->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_LEFT);
        bubble_map_node_->addChild(line);
        bubble_map_node_->setPosition(this->getBubbleMapOrigin());
        csb_node_->addChild(bubble_map_node_, UI_ZORDER_MAP_BUBBLE);

        GamePlayController::getInstance()->loadStageMap(stage_numble);
    }

    void GameScene::initUIZOrder()
    {
        this->setUIZOrderWithNameAndNumber(UI_NAME_GUNSIGHT, UI_ZORDER_GUNSIGHT);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_PAD, UI_ZORDER_PAD);
        this->setUIZOrderWithNameAndNumber(UI_NAME_SECOND_BUBBLE_STORE, UI_ZORDER_GRASS);

        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARRELHEAD_NODE, UI_ZORDER_BARRELHEAD_FIRST);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARRELHEAD_FIRST, UI_ZORDER_BARRELHEAD_FIRST);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARRELHEAD_FIFTH, UI_ZORDER_BARRELHEAD_FIFTH);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARRELHEAD_SECOND, UI_ZORDER_BARRELHEAD_SECOND);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARRELHEAD_FOURTH, UI_ZORDER_BARRELHEAD_FOURTH);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARRELHEAD_THIRD, UI_ZORDER_BARRELHEAD_THIRD);

        this->setUIZOrderWithNameAndNumber(UI_NAME_BARRELHEAD_NODE, UI_ZORDER_BARRELHEAD_NODE);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARREL_NUMBLE_FIRST, UI_ZORDER_BARREL_NUMBLE_NODE);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARREL_NUMBLE_SECOND, UI_ZORDER_BARREL_NUMBLE_NODE);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARREL_NUMBLE_FIFTH, UI_ZORDER_BARREL_NUMBLE_NODE);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARREL_NUMBLE_FOURTH, UI_ZORDER_BARREL_NUMBLE_NODE);
        //this->setUIZOrderWithNameAndNumber(UI_NAME_BARREL_NUMBLE_THIRD, UI_ZORDER_BARREL_NUMBLE_NODE);

    }

    //cocos2d::Node * GameScene::getBarrelHeadNode()
    //{
    //    return csb_node_->getChildByName(UI_NAME_BARRELHEAD_NODE);
    //}

    void GameScene::initBarrels()
    {
        this->addBarrelheadsPhysicsBody();
        this->addBarrelBottoms();
    }

    void GameScene::addBarrelheadsPhysicsBody()
    {
        this->addBarrelheadPhysicsBodyWithName(UI_NAME_BARRELHEAD_BORDER_FIRST);
        this->addBarrelheadPhysicsBodyWithName(UI_NAME_BARRELHEAD_BORDER_SECOND);
        this->addBarrelheadPhysicsBodyWithName(UI_NAME_BARRELHEAD_BORDER_THIRD);
        this->addBarrelheadPhysicsBodyWithName(UI_NAME_BARRELHEAD_BORDER_FOURTH);
        this->addBarrelheadPhysicsBodyWithName(UI_NAME_BARRELHEAD_BORDER_FIFTH);
        this->addBarrelheadPhysicsBodyWithName(UI_NAME_BARRELHEAD_BORDER_SIXTH);
    }

    void GameScene::addBarrelheadPhysicsBodyWithName(const std::string & child_name)
    {
        cocos2d::Node* node = csb_node_->getChildByName(child_name);
        cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(BARRELHEADEDGE_BODY_RADIUS,
            cocos2d::PhysicsMaterial(PHYSICS_BARRELHEADEDGE_BODY_DENSITY,
                PHYSICS_BARRELHEADEDGE_BODY_RESTITUTION, PHYSICS_BARRELHEADEDGE_BODY_FRICTION));//�ܶ�, �ָ�,Ħ����
        body->setDynamic(false);
        body->setGravityEnable(false);
        body->setCategoryBitmask(BITMASK_BARRELHEADEDGE_CATEGORY);
        body->setCollisionBitmask(BITMASK_BARRELHEADEDGE_COLLISION);
        body->setContactTestBitmask(BITMASK_BARRELHEADEDGE_CONTACTTEST);
        node->setPhysicsBody(body);
    }

    void GameScene::addBubblePhysicsBodyToMap(BaseBubble* bubble)
    {
        bubble->addBubbleStaticBody();
        bubble_map_node_->addChild(bubble);
    }

    void GameScene::addBarrelBottoms()
    {
        this->addBarrelBottomWithName(UI_NAME_BARREL_BOTTOM_FIRST);
        this->addBarrelBottomWithName(UI_NAME_BARREL_BOTTOM_SECOND);
        this->addBarrelBottomWithName(UI_NAME_BARREL_BOTTOM_THIRD);
        this->addBarrelBottomWithName(UI_NAME_BARREL_BOTTOM_FOURTH);
        this->addBarrelBottomWithName(UI_NAME_BARREL_BOTTOM_FIFTH);
    }

    void GameScene::addBarrelBottomWithName(const std::string& child_name)
    {
        BarrelBottom* bottom = BarrelBottom::createWithName(child_name);
        auto node = csb_node_->getChildByName(child_name);
        node->setLocalZOrder(UI_ZORDER_BARRELBOTTOM);
        node->addChild(bottom);
    }

    void GameScene::addTouchEventListener()
    {
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(false);
        GamePlayController* game_controller = GamePlayController::getInstance();
        listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::onTouchBegan, game_controller);
        listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::onTouchMoved, game_controller);
        listener->onTouchEnded = CC_CALLBACK_2(GamePlayController::onTouchEnded, game_controller);
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        //����������ײ������
        auto contactListener = cocos2d::EventListenerPhysicsContact::create();
        //���ü���������ײ��ʼ����  
        contactListener->onContactBegin = CC_CALLBACK_1(GamePlayController::onContactBegin, game_controller);
        contactListener->onContactSeparate = CC_CALLBACK_1(GamePlayController::onContactSeparate, game_controller);
        //��ӵ��¼��ַ�����  
        dispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);


        //cocos2d::Sprite* gunsight = dynamic_cast<cocos2d::Sprite*>(csb_node_->getChildByName(UI_NAME_GUNSIGHT));
        //listener = cocos2d::EventListenerTouchOneByOne::create();
        //listener->setSwallowTouches(false);
        //listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchBegan, game_controller);
        //listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchMoved, game_controller);
        //listener->onTouchEnded = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchEnded, game_controller);
        //dispatcher->addEventListenerWithSceneGraphPriority(listener, this->getGunsight());
        //listener = cocos2d::EventListenerTouchOneByOne::create();
        //listener->setSwallowTouches(false);
        //listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchBegan, game_controller);
        //listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchMoved, game_controller);
        //listener->onTouchEnded = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchEnded, game_controller);
        //dispatcher->addEventListenerWithSceneGraphPriority(listener, this->getGrass());

    }

    void GameScene::addEventListenerCustom()
    {
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        auto listener = cocos2d::EventListenerCustom::create(EVENT_BUBBLE_ELIMINATED, CC_CALLBACK_1(GameScene::eliminateSprites, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_MAP_LOADED, CC_CALLBACK_1(GameScene::addBubbleMapUI, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_SHOOT_BUBBLE, CC_CALLBACK_1(GameScene::reloadPrepareBubble, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_SHOOT_BUBBLE, [=](cocos2d::EventCustom*) {
            this->setPropertyTouchEnabled(false);
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_BUBBLE_CLING, CC_CALLBACK_1(GameScene::clingBubble, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 2);
        listener = cocos2d::EventListenerCustom::create(EVENT_CAN_USED_PROPS, [=](cocos2d::EventCustom*) {
            this->setPropertyTouchEnabled(true);
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_BUBBLE_AIR, CC_CALLBACK_1(GameScene::spritesDownFromAir, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_BUBBLE_RUN_EFFECT, CC_CALLBACK_1(GameScene::runBubbleContactEffect, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_ADD_ELIMINATE_COMBO, CC_CALLBACK_1(GameScene::addEliminateCombo, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_CUT_ELIMINATE_COMBO, CC_CALLBACK_1(GameScene::removeTwoScoreWidget, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_SCORE_TEXT_UPDATE, CC_CALLBACK_1(GameScene::scoreTextUpdate, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_EXCHANGE_BUBBLE, CC_CALLBACK_1(GameScene::exchangePrepareBubble, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_DESTROY_BUBBLE_CLOUD, CC_CALLBACK_1(GameScene::destroyBubbleDarkCloud, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_ADJUST_MAP_POSITION, CC_CALLBACK_1(GameScene::adjustMapPosition, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_ADJUST_MAP_POSITION, [=](cocos2d::EventCustom* event) {
            GameScoreController::getInstance()->dispatchUpdateCompletedTaskEvent();
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_USE_BUBBLE_BOMB_PROPS, CC_CALLBACK_1(GameScene::useBubbleBombProps, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_CANCEL_BUBBLE_BOMB_PROPS, CC_CALLBACK_1(GameScene::cancelUsedBubbleBombProps, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_HAVE_USED_PROPS, CC_CALLBACK_1(GameScene::haveUsedProps, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_USE_SELECTION_PROPS, CC_CALLBACK_1(GameScene::addPropsSelectAlert, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_PROPS_SELECT_ALERT_CANCEL, [=](cocos2d::EventCustom*) {
            props_weapon_->removeFromParent();
            this->removePropsSelectAlert(nullptr);
            this->setMenuTouchEnabled(true);
            dispatcher->dispatchCustomEvent(EVENT_BUBBLE_NO_FLASH);
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_SELECT_BUBBLE, CC_CALLBACK_1(GameScene::selectBubble, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_FIND_BUBBLES_IN_VISIBLESIZE, CC_CALLBACK_1(GameScene::addListenerForBubblesInVisibleSize, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_PROPS_SELECT_ALERT_CONFIRM, CC_CALLBACK_1(GameScene::removePropsSelectAlert, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 2);
        listener = cocos2d::EventListenerCustom::create(EVENT_PROPS_SELECT_ALERT_CONFIRM, CC_CALLBACK_1(GameScene::useSelectProperties, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_RECENT_BUBBLE_CAST, CC_CALLBACK_1(GameScene::recentlyBubbleCast, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        //listener = cocos2d::EventListenerCustom::create(EVENT_ROTATE_SIGHTING_DEVICE, CC_CALLBACK_1(GameScene::rotateSightingDevice, this));
        //dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(UI_NAME_BIG_COMBO_ELIMINATE, CC_CALLBACK_1(GameScene::playBigEliminateEffect, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_CUT_ELIMINATE_COMBO, CC_CALLBACK_1(GameScene::stopBigEliminateEffect, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        //listener = cocos2d::EventListenerCustom::create(EVENT_TURN_ON_SIGHTING_DEVICE, [=](cocos2d::EventCustom*) {
        //    if (this->getBubbleSightingDevice())
        //    {
        //        this->getBubbleSightingDevice()->turnOnMainSightingDevice();
        //    }
        //});
        //dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_TURN_OFF_SIGHTING_DEVICE, [=](cocos2d::EventCustom*) {
            if (this->getBubbleSightingDevice())
            {
                this->getBubbleSightingDevice()->turnOffSightingDevice();
            }
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_UPDATE_COMPLETED_TASK_LABEL, CC_CALLBACK_1(GameScene::updateCompletedTaskLabel, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        //listener = cocos2d::EventListenerCustom::create(EVENT_SHOOT_PREPARE_BUBBLE, [=](cocos2d::EventCustom*) {
        //    this->getGameCharacter()->playShootBubbleAnimation();
        //});
        //dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_UPDATE_BUBBLE_USE_COUNT_LABEL, CC_CALLBACK_1(GameScene::updateBubbleUseCountLabel, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_ADD_AIR_BUBBLE_NUMBLE, CC_CALLBACK_1(GameScene::addOneAirBubblesNumble, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_CUT_AIR_BUBBLE_NUMBLE, CC_CALLBACK_1(GameScene::cutOneAirBubblesNumble, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_WINDMILL_MAP_BORDER_LOADED, CC_CALLBACK_1(GameScene::addWindmillBorder, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_WINDMILL_MAP_BORDER_LOADED, [=](cocos2d::EventCustom*) {
            bubble_map_node_->getChildByName(BUBBLE_MAP_LINE_NAME)->setVisible(false);
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_WINDMILL_ROTATION, CC_CALLBACK_1(GameScene::windmillBubbleRotation, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_INITIAL_START_NUMBLES, [=](cocos2d::EventCustom* event) {
            StartNumbleModule start_numbles = *static_cast<StartNumbleModule*>(event->getUserData());
            this->getScoreProgressMenu()->initialStartNumble(start_numbles);
			//GamePlayController::getInstance()->setBubbleShootEnabled(true);
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_GAME_DEFEAT, [=](cocos2d::EventCustom*) {
            //if (!GameScoreController::getInstance()->gameVictory())
            //{
                this->defeat();
            //}
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_FIND_THREE_BUBBLE, CC_CALLBACK_1(GameScene::findThreeBubble, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_FALL_STAGE_ADJUST_MAP_POSITION, CC_CALLBACK_1(GameScene::fallAdjustMapPosition, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_UPDATE_SECOND_BUBBLE, [=](cocos2d::EventCustom*) {
            if (!this->getSecondPrepareBubble())
            {
                this->addSecondPrepareBubble()->setVisible(true);
            }
        });
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_FALL_MAP_BORDER_LOADED, CC_CALLBACK_1(GameScene::addFallBorder, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        //listener = cocos2d::EventListenerCustom::create(EVENT_DEFEAT, [=](cocos2d::EventCustom*) {
        //if (!GameScoreController::getInstance()->gameVictory())
        //{
        //    this->defeat();
        //}
        //});
        //dispatcher->addEventListenerWithFixedPriority(listener, 1);
        listener = cocos2d::EventListenerCustom::create(EVENT_ADD_ELIMINATE_SCORE_LABEL, CC_CALLBACK_1(GameScene::addEliminateScoreLabel, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        dispatcher->addCustomEventListener(EVENT_BUBBLE_CONTACT_BLACKHOLE, [=](cocos2d::EventCustom * event) {
            this->setPropertyTouchEnabled(true);
        });
        dispatcher->addCustomEventListener(EVENT_BUBBLE_PRECLING, [=](cocos2d::EventCustom * event) {
            BaseBubble* bubble = static_cast<BaseBubble*>(event->getUserData());
            bubble->retain();
            bubble->removeFromParent();
            bubble_map_node_->addChild(bubble);
            bubble->release();
            //bubble->setPosition(this->convertMapToCsbSpace(bubble->getPosition()));
        });
        listener = cocos2d::EventListenerCustom::create(EVENT_TOP_ELIMINATE_BUBBLE_LOGO_LOADED, CC_CALLBACK_1(GameScene::addTopEliminateBubbleLogo, this));
        dispatcher->addEventListenerWithFixedPriority(listener, 1);
        dispatcher->addCustomEventListener(EVENT_ESTIMATE_VICTORY, [=](cocos2d::EventCustom * event) {
            this->estimateVictory();
        });
    }

    void GameScene::removeEventListenerCustom()
    {
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->removeCustomEventListeners(EVENT_BUBBLE_ELIMINATED);
        dispatcher->removeCustomEventListeners(EVENT_MAP_LOADED);
        dispatcher->removeCustomEventListeners(EVENT_SHOOT_BUBBLE);
        dispatcher->removeCustomEventListeners(EVENT_BUBBLE_CLING);
        dispatcher->removeCustomEventListeners(EVENT_BUBBLE_AIR);
        dispatcher->removeCustomEventListeners(EVENT_BUBBLE_RUN_EFFECT);
        dispatcher->removeCustomEventListeners(EVENT_ADD_ELIMINATE_COMBO);
        dispatcher->removeCustomEventListeners(EVENT_CUT_ELIMINATE_COMBO);
        dispatcher->removeCustomEventListeners(EVENT_SCORE_TEXT_UPDATE);
        dispatcher->removeCustomEventListeners(EVENT_EXCHANGE_BUBBLE);
        dispatcher->removeCustomEventListeners(EVENT_DESTROY_BUBBLE_CLOUD);
        dispatcher->removeCustomEventListeners(EVENT_ADJUST_MAP_POSITION);
        dispatcher->removeCustomEventListeners(EVENT_USE_BUBBLE_BOMB_PROPS);
        dispatcher->removeCustomEventListeners(EVENT_CANCEL_BUBBLE_BOMB_PROPS);
        dispatcher->removeCustomEventListeners(EVENT_HAVE_USED_PROPS);
        dispatcher->removeCustomEventListeners(EVENT_USE_SELECTION_PROPS);
        dispatcher->removeCustomEventListeners(EVENT_PROPS_SELECT_ALERT_CANCEL);
        dispatcher->removeCustomEventListeners(EVENT_FIND_BUBBLES_IN_VISIBLESIZE);
        dispatcher->removeCustomEventListeners(EVENT_PROPS_SELECT_ALERT_CONFIRM);
        dispatcher->removeCustomEventListeners(EVENT_RECENT_BUBBLE_CAST);
        //dispatcher->removeCustomEventListeners(EVENT_ROTATE_SIGHTING_DEVICE);
        dispatcher->removeCustomEventListeners(UI_NAME_BIG_COMBO_ELIMINATE);
        dispatcher->removeCustomEventListeners(EVENT_CUT_ELIMINATE_COMBO);
        //dispatcher->removeCustomEventListeners(EVENT_TURN_ON_SIGHTING_DEVICE);
        dispatcher->removeCustomEventListeners(EVENT_TURN_OFF_SIGHTING_DEVICE);
        dispatcher->removeCustomEventListeners(EVENT_UPDATE_COMPLETED_TASK_LABEL);
        dispatcher->removeCustomEventListeners(EVENT_SELECT_BUBBLE);
        //dispatcher->removeCustomEventListeners(EVENT_SHOOT_PREPARE_BUBBLE);
        dispatcher->removeCustomEventListeners(EVENT_UPDATE_BUBBLE_USE_COUNT_LABEL);
        dispatcher->removeCustomEventListeners(EVENT_ADD_AIR_BUBBLE_NUMBLE);
        dispatcher->removeCustomEventListeners(EVENT_CUT_AIR_BUBBLE_NUMBLE);
        dispatcher->removeCustomEventListeners(EVENT_WINDMILL_MAP_BORDER_LOADED);
        dispatcher->removeCustomEventListeners(EVENT_WINDMILL_ROTATION);
        dispatcher->removeCustomEventListeners(EVENT_INITIAL_START_NUMBLES);
        dispatcher->removeCustomEventListeners(EVENT_GAME_DEFEAT);
        dispatcher->removeCustomEventListeners(EVENT_FIND_THREE_BUBBLE);
        dispatcher->removeCustomEventListeners(EVENT_FALL_STAGE_ADJUST_MAP_POSITION);
        dispatcher->removeCustomEventListeners(EVENT_UPDATE_SECOND_BUBBLE);
        dispatcher->removeCustomEventListeners(EVENT_FALL_MAP_BORDER_LOADED);
        //dispatcher->removeCustomEventListeners(EVENT_DEFEAT);
        dispatcher->removeCustomEventListeners(EVENT_ADD_ELIMINATE_SCORE_LABEL);
        dispatcher->removeCustomEventListeners(EVENT_CAN_USED_PROPS);
        dispatcher->removeCustomEventListeners(EVENT_BUBBLE_CONTACT_BLACKHOLE);
        dispatcher->removeCustomEventListeners(EVENT_BUBBLE_PRECLING);
        dispatcher->removeCustomEventListeners(EVENT_TOP_ELIMINATE_BUBBLE_LOGO_LOADED);
        dispatcher->removeCustomEventListeners(EVENT_ESTIMATE_VICTORY);
    }

    //void GameScene::addExchangeBubbleListener()
    //{
    //    cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_EXCHANGE_BUBBLE, CC_CALLBACK_1(GameScene::reloadPrepareBubble, this));
    //}

    //void GameScene::removeExchangeBubbleListener()
    //{
    //    cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_EXCHANGE_BUBBLE);
    //}

    void GameScene::addPrepareBubble()
    {
        BaseBubble* bubble = this->createPrepareBubble();//����,û���������
        //bubble->setName(PREPARE_BUBBLE_NAME);
        bubble->setPosition(this->getGunsightPosition());
        auto controller = GamePlayController::getInstance();
        controller->setPrepareBubble(bubble);
        this->setPrepareColorBubble(bubble);
        if (BaseBubble* second_bubble = this->addSecondPrepareBubble())
        {
            second_bubble->setVisible(true);
        }
        controller->setBubbleShootEnabled(true);
        this->disposedPrepareBubbleType();
    }

    void GameScene::initScoreWidget()
    {
        auto manager = ScoreWidgetManager::getInstance();
        manager->setWidgetPointsSeed(csb_node_->getChildByName(SCORE_WIDGET_NODE_NAME)->getChildren());
        for (int i = 0; i < INITIAL_SCORE_WIDGET_NUMBLE; i++)
        {
            ScoreWidget* widget = manager->getNewScoreWidget();
            csb_node_->getChildByName(SCORE_WIDGET_NODE_NAME)->addChild(widget);
            widget->runFirstEnterActioin();
        }
    }

    BaseBubble* GameScene::addSecondPrepareBubble()
    {
        if (this->isOnlyBubbleUseCount())
        {
            second_bubble_ = nullptr;
        }
        else
        {
            second_bubble_ = this->createPrepareBubble();
            if (second_bubble_)
            {
                //second_bubble_->setName(SECOND_PREPARE_BUBBLE_NAME);
                second_bubble_->setPosition(this->getSecondBubbleStoreNodePosition());
                second_bubble_->setVisible(false);
            }
        }
		return second_bubble_;
    }

    void GameScene::reloadPrepareBubble(cocos2d::EventCustom *)
    {
        BaseBubble* bubble = this->getSecondPrepareBubble();
        if (!bubble)
        {
            return;
        }
        //bubble->setName(PREPARE_BUBBLE_NAME);
        this->setPrepareColorBubble(bubble);
        BaseBubble* second_bubble = this->addSecondPrepareBubble();
        GamePlayController::getInstance()->setPrepareBubble(bubble);
        cocos2d::MoveTo* move = cocos2d::MoveTo::create(PREPARE_RELOAD_MOVE_TIME, this->getGunsightPosition());
        cocos2d::CallFunc* func = cocos2d::CallFunc::create([=]() {
            if (second_bubble)
            {
                second_bubble->setVisible(!isOnlyBubbleUseCount());
				this->changeSightingDeviceColor();
				this->playPrepareBubbleStanbyAction();
            }
            GamePlayController::getInstance()->setBubbleShootEnabled(true);
        });
        cocos2d::Sequence* seq = cocos2d::Sequence::create(move, func, NULL);
        bubble->runAction(seq);
        //GamePlayController::getInstance()->setBubbleShootEnabled(false);
    }

    void GameScene::exchangePrepareBubble(cocos2d::EventCustom*)
    {
        if (isOnlyBubbleUseCount())
        {
            GamePlayController::getInstance()->setBubbleShootEnabled(true);
            return;
        }
        //this->setPropertyTouchEnabled(false);
        cocos2d::Node* prepare_bubble = this->getPrepareBubble();
        assert(prepare_bubble);
		cocos2d::Node* second_bubble = this->getSecondPrepareBubble();
        cocos2d::MoveTo* move_to_second = cocos2d::MoveTo::create(PREPARE_RELOAD_MOVE_TIME, this->getSecondBubbleStoreNodePosition());
        cocos2d::Sequence* seq_prepare = cocos2d::Sequence::create(move_to_second, cocos2d::CallFunc::create([=]() {
			this->setSecondPrepareBubble(dynamic_cast<BaseBubble*>(prepare_bubble));
        }), nullptr);
        prepare_bubble->runAction(seq_prepare);

        cocos2d::MoveTo* move_to_prepare = cocos2d::MoveTo::create(PREPARE_RELOAD_MOVE_TIME, this->getGunsightPosition());
        cocos2d::Sequence* seq_second = cocos2d::Sequence::create(move_to_prepare, cocos2d::CallFunc::create([=]() {
            auto control = GamePlayController::getInstance();
            control->setBubbleShootEnabled(true);
            control->setPrepareBubble(dynamic_cast<BaseBubble*>(second_bubble));
            this->setPrepareColorBubble(dynamic_cast<BaseBubble*>(second_bubble));
            this->changeSightingDeviceColor();
			this->playPrepareBubbleStanbyAction();
            //this->setPropertyTouchEnabled(true);
        }), nullptr);
        second_bubble->runAction(seq_second);
    }

    BaseBubble * GameScene::createPrepareBubble()
    {
        BubbleType color = GamePlayController::getInstance()->getBubbleColorFromPicker();
        BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(color);//����,û���������
        csb_node_->addChild(bubble, UI_ZORDER_PREPARE_BUBBLE);
        auto color_bubble = dynamic_cast<ColorBubble*>(bubble);
        if (color_bubble == nullptr)
        {
            return nullptr;
        }
        color_bubble->addBubblePrepareBody();
        return bubble;
    }

    cocos2d::Vec2 GameScene::getGunsightPosition()
    {
        return this->getGunsight()->getPosition();
    }

	cocos2d::Vec2 GameScene::getPrepareBubbleOrigin()
	{
		return this->getGunsightPosition();
	}

    cocos2d::Vec2 GameScene::getSecondBubbleStoreNodePosition()
    {
        return this->getSecondBubbleStoreNode()->getPosition();
    }

    cocos2d::Vec2 GameScene::getNodePositionWithName(const std::string& child_name)
    {
        cocos2d::Node* node = csb_node_->getChildByName(child_name);
        return node->getPosition();
    }

    BubbleMainSightingDevice* GameScene::getBubbleSightingDevice()
    {
        return main_sighting_device_;
    }

    cocos2d::ui::TextBMFont* GameScene::getCompletedTaskLabel()
    {
        return dynamic_cast<cocos2d::ui::TextBMFont*>(this->getChildByName(GAME_RIGHT_INFO_NAME)->getChildByName(UI_NAME_COMPLETED_TASK));
    }

    cocos2d::ui::TextBMFont* GameScene::getGameTaskLabel()
    {
        return dynamic_cast<cocos2d::ui::TextBMFont*>(this->getChildByName(GAME_RIGHT_INFO_NAME)->getChildByName(UI_NAME_GAME_TASK));
    }

    cocos2d::ui::TextBMFont * GameScene::getBubbleUseCountLabel()
    {
        return dynamic_cast<cocos2d::ui::TextBMFont*>(this->getSecondBubbleStoreNode()->getChildByName(UI_NAME_BUBBLE_USE_COUNT));
    }

    GameCharacter* GameScene::getGameCharacter()
    {
        return game_character_;
    }

    ScoreProgressMenu* GameScene::getScoreProgressMenu()
    {
		return score_progress_;
    }

    void GameScene::setStageType(StageType type)
    {
        stage_type_ = type;
    }

    StageType GameScene::getStageType()
    {
        return stage_type_;
    }

    void GameScene::setUIZOrderWithNameAndNumber(const std::string & child_name, int localZOrder)
    {
        cocos2d::Node* node = csb_node_->getChildByName(child_name);
        node->setLocalZOrder(localZOrder);
    }

    void GameScene::addBubbleMapUI(cocos2d::EventCustom* event)
    {
        this->updateGameTaskLabel();
        BubbleSpriteMap* sprite_vector = static_cast<BubbleSpriteMap*>(event->getUserData());
        auto controller = GamePlayController::getInstance();
        for (auto iter : *sprite_vector)
        {
            for (auto var : iter.second)
            {
                this->addBubblePhysicsBodyToMap(var.second);
                controller->addPrepareColor(var.second->getBubbleType());
            }
        }
        controller->setBubbleColorRange();
        this->initScoreWidget();

        //�ṩmap��ת��ʾ
        //****************************************************************
        /*auto body = cocos2d::PhysicsBody::createBox(cocos2d::Size(SIGHTING_POINT_BODY_RADIUS, SIGHTING_POINT_BODY_RADIUS),
            cocos2d::PhysicsMaterial(0.0, 0.0,
                0.0));
        body->setDynamic(false);
        body->setMass(0);
        body->setGravityEnable(false);
        body->setGroup(-2);
        body->setCategoryBitmask(0);
        body->setCollisionBitmask(0);
        body->setContactTestBitmask(0);

        body->setLinearDamping(0.7);
        body->setAngularDamping(0.7);
        bubble_map_node_->setPhysicsBody(body); */
        //*****************************************************************
    }

    void GameScene::addTopEliminateBubbleLogo(cocos2d::EventCustom * event)
    {
        auto points = *static_cast<std::vector<cocos2d::Vec2>*>(event->getUserData());
        for (auto point : points)
        {
            cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createStageTypeSprite(kTopEliminate);
            sp->runAction(cocos2d::RepeatForever::create(cocos2d::RotateBy::create(3.0f, 360.0f)));
            sp->runAction(cocos2d::RepeatForever::create(cocos2d::Sequence::createWithTwoActions(cocos2d::ScaleTo::create(1.0f, 0.6f), cocos2d::ScaleTo::create(1.0f, 1.0f))));
            sp->setPosition(point);
            bubble_map_node_->addChild(sp);
        }
    }

    void GameScene::addWindmillBorder(cocos2d::EventCustom *)
    {
        //auto func = [=](cocos2d::Size size, cocos2d::Vec2 point, int test_bitmask = BITMASK_WINDMILL_BORDER_CONTACTTEST) {
        //    //cocos2d::Size size = cocos2d::Size(PHYSICS_WINDMILL_BORDER_BODY_WIDTH, PHYSICS_WINDMILL_BORDER_BODY_HEIGHT);
        //    auto body = cocos2d::PhysicsBody::createBox(size,
        //        cocos2d::PhysicsMaterial(PHYSICS_WORLD_BODY_DENSITY, PHYSICS_WORLD_BODY_RESTITUTION, PHYSICS_WORLD_FRICTION));
        //    body->setDynamic(true);
        //    body->setGravityEnable(false);
        //    body->setCategoryBitmask(BITMASK_WINDMILL_BORDER_CATEGORY);
        //    body->setCollisionBitmask(BITMASK_WINDMILL_BORDER_COLLISION);
        //    body->setContactTestBitmask(test_bitmask);
        //    body->setGroup(-2);
        //    cocos2d::Node* node = cocos2d::Node::create();
        //    node->setName(UI_NAME_WINDMILL_BORDER);
        //    node->setPhysicsBody(body);
        //    node->setPosition(point);
        //    csb_node_->addChild(node);
        //};
        //func(PHYSICS_WINDMILL_BORDER_BODY_LEFT_SIZE, PHYSICS_WINDMILL_BORDER_BODY_LEFT_POSITION);
        //func(PHYSICS_WINDMILL_BORDER_BODY_RIGHT_SIZE, PHYSICS_WINDMILL_BORDER_BODY_RIGHT_POSITION);
        //func(PHYSICS_WINDMILL_BORDER_BODY_TOP_SIZE, PHYSICS_WINDMILL_BORDER_BODY_TOP_POSITION);
        //func(PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_SIZE, PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_POSITION);
        //func(PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_SIZE, PHYSICS_WINDMILL_BORDER_BODY_BOTTOM2_POSITION, BITMASK_WINDMILL_BOTTOM_BORDER_CONTACTTEST);
        

        this->addWindmillBorderFunc(PHYSICS_WINDMILL_BORDER_BODY_LEFT_SIZE, PHYSICS_WINDMILL_BORDER_BODY_LEFT_POSITION);
        this->addWindmillBorderFunc(PHYSICS_WINDMILL_BORDER_BODY_RIGHT_SIZE, PHYSICS_WINDMILL_BORDER_BODY_RIGHT_POSITION);
        this->addWindmillBorderFunc(PHYSICS_WINDMILL_BORDER_BODY_TOP_SIZE, PHYSICS_WINDMILL_BORDER_BODY_TOP_POSITION);
        this->addWindmillBorderFunc(PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_SIZE, PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_POSITION);
        this->addWindmillBorderFunc(PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_SIZE, PHYSICS_WINDMILL_BORDER_BODY_BOTTOM2_POSITION, BITMASK_WINDMILL_BOTTOM_BORDER_CONTACTTEST);
        this->runAction(cocos2d::CallFunc::create([=]() {       
            this->doSomethingAfterFirstAdjustMap(); 
        }));

    }
    void bubble_second::GameScene::addWindmillBorderFunc(cocos2d::Size size, cocos2d::Vec2 point, int test_bitmask)
    {
        auto body = cocos2d::PhysicsBody::createBox(size,
            cocos2d::PhysicsMaterial(PHYSICS_WORLD_BODY_DENSITY, PHYSICS_WORLD_BODY_RESTITUTION, PHYSICS_WORLD_FRICTION));
        body->setDynamic(true);
        body->setGravityEnable(false);
        body->setCategoryBitmask(BITMASK_WINDMILL_BORDER_CATEGORY);
        body->setCollisionBitmask(BITMASK_WINDMILL_BORDER_COLLISION);
        body->setContactTestBitmask(test_bitmask);
        body->setGroup(-2);
        cocos2d::Node* node = cocos2d::Node::create();
        node->setName(UI_NAME_WINDMILL_BORDER);
        node->setPhysicsBody(body);
        node->setPosition(point);
        csb_node_->addChild(node);
    }

    void GameScene::addFallBorder(cocos2d::EventCustom *)
    {
        auto body = cocos2d::PhysicsBody::createBox(PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_SIZE,
            cocos2d::PhysicsMaterial(PHYSICS_WORLD_BODY_DENSITY, PHYSICS_WORLD_BODY_RESTITUTION, PHYSICS_WORLD_FRICTION));
        body->setDynamic(true);
        body->setGravityEnable(false);
        body->setCategoryBitmask(BITMASK_WINDMILL_BORDER_CATEGORY);
        body->setCollisionBitmask(BITMASK_WINDMILL_BORDER_COLLISION);
        body->setContactTestBitmask(BITMASK_FALL_BOTTOM_BORDER_CONTACTTEST);
        body->setGroup(-2);
        cocos2d::Node* node = cocos2d::Node::create();
        node->setName(UI_NAME_FALL_BOTTOM_BORDER);
        node->setPhysicsBody(body);
        node->setPosition(PHYSICS_WINDMILL_BORDER_BODY_BOTTOM_POSITION);
        csb_node_->addChild(node);
        this->fallStageHandle();
    }

    void GameScene::fallStageHandle()
    {
        this->setFallStageFlag(true);
    }

    void GameScene::setFallStageFlag(bool flag)
    {
        is_fall_stage_ = flag;
    }

    bool GameScene::isFallStage()
    {
        return is_fall_stage_;
    }

    void GameScene::addEliminateScoreLabel(cocos2d::EventCustom * event)
    {
        cocos2d::ValueMap data_map = *static_cast<cocos2d::ValueMap*>(event->getUserData());
        //std::string score_text = data_map.at(EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_SCORE_KEY).asString();
        //cocos2d::ui::TextBMFont* pop_score_label = cocos2d::ui::TextBMFont::create(
        //    score_text, POP_SCORE_CHARMAP_PATH);
        //pop_score_label->setAnchorPoint(POP_SCORE_ANCHORPOINT);
        //pop_score_label->setScale(POP_SCORE_INITIAL_SCALE);
        //cocos2d::ScaleTo* scaleto_1 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_1_TIME, POP_SCORE_SCALETO_1_NUMBLE);
        //cocos2d::ScaleTo* scaleto_2 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_2_TIME, POP_SCORE_SCALETO_2_NUMBLE);
        //cocos2d::ScaleTo* scaleto_3 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_3_TIME, POP_SCORE_SCALETO_3_NUMBLE);
        //cocos2d::ScaleTo* scaleto_4 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_4_TIME, POP_SCORE_SCALETO_4_NUMBLE);
        //cocos2d::ScaleTo* scaleto_5 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_5_TIME, POP_SCORE_SCALETO_5_NUMBLE);
        //cocos2d::MoveBy* move = cocos2d::MoveBy::create(POP_SCORE_MOVEBY_TIME, POP_SCORE_MOVEBY_VEC2);
        //cocos2d::Sequence* seq = cocos2d::Sequence::create(scaleto_1, scaleto_2, scaleto_3, scaleto_4, scaleto_5,
        //    cocos2d::CallFunc::create([=]() {
        //    pop_score_label->removeFromParent();
        //}), NULL);
        //cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(move, seq);
        //pop_score_label->runAction(spawn);

        PopScoreLabelComponent* pop_score_label = PopScoreLabelComponent::create();
        //pop_score_label->setScale(POP_SCORE_INITIAL_SCALE);
        cocos2d::Vec2 point(data_map.at(EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_POS_X_KEY).asFloat(), 
            data_map.at(EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_POS_Y_KEY).asFloat());
        //if (point.y<0)
        //{
            point = this->convertMapToCsbSpace(point);
        //}
        pop_score_label->setPosition(point);
        csb_node_->addChild(pop_score_label);
        pop_score_label->popOnceLabelWithScore(data_map.at(EVENT_ADD_ELIMINATE_SCORE_LABEL_DATA_SCORE_KEY).asInt());
    }

    //void GameScene::mutipleSealBubbleFly(cocos2d::EventCustom * event)
    //{
    //    cocostudio::Armature* armature = static_cast<cocostudio::Armature*>(event->getUserData());
    //    this->addChild(armature, UI_ZORDER_MENU_INFO);
    //    cocos2d::ccBezierConfig config;
    //    config.endPosition = this->getCompletedTaskLabel();
    //    config.controlPoint_1 = this->getPosition();
    //    config.controlPoint_2 = cocos2d::Vec2(0.0f, 0.0f);
    //    cocos2d::BezierTo* bezier = cocos2d::BezierTo::create(SCORE_WIDGET_BEZIER_FLYING_DURATION, config);
    //    this->runAction(cocos2d::Sequence::createWithTwoActions(bezier, cocos2d::CallFunc::create([=]() {
    //        this->addPhysicsBody();
    //    })));
    //}

    void GameScene::clingBubble(cocos2d::EventCustom* event)
    {
        BubbleVector* bubble_vector = static_cast<BubbleVector*>(event->getUserData());
        BaseBubble* sprite = bubble_vector->at(0);
        BaseBubble* bubble = bubble_vector->at(1);
        //auto controller = GamePlayController::getInstance();
        GamePlayController::getInstance()->addPrepareColor(bubble->getBubbleType());
        dynamic_cast<ColorBubble*>(bubble)->runBubbleEffect(LONG_EFFECT_BUBBLE_KEY,
            bubble_map_node_->convertToNodeSpaceAR(sprite->getPosition()));
        sprite->removeFromParent();
        this->addBubblePhysicsBodyToMap(bubble);
        this->setPropertyTouchEnabled(true);
        GameScoreController::getInstance()->cutPrepareBubbleAirNumble();
    }

    void GameScene::windmillBubbleRotation(cocos2d::EventCustom* event)
    {
        float angle = *static_cast<float*>(event->getUserData());
        float per_angle = angle / (WINDMILL_ROTATION_CARDINAL_SPLINE_POINT_NUMBLE - 1);
        cocos2d::PointArray* point_array = cocos2d::PointArray::create(WINDMILL_ROTATION_CARDINAL_SPLINE_POINT_NUMBLE);
        cocos2d::Vec2 windmill_node_pos = bubble_map_node_->getChildByTag(WINDMILL_BUBBLE_TAG)->getPosition();
        for (int i = 0; i < WINDMILL_ROTATION_CARDINAL_SPLINE_POINT_NUMBLE; i++)
        {
            cocos2d::Vec2 point = convertMapToCsbSpace(cocos2d::Point::ZERO.rotateByAngle(windmill_node_pos, CC_DEGREES_TO_RADIANS(-per_angle*i)));
            point_array->addControlPoint(point);
        }
        cocos2d::CardinalSplineTo* action = cocos2d::CardinalSplineTo::create(WINDMILL_ROTATION_ACTIONS_DURATION, point_array, 0);
        cocos2d::RotateBy* rotate = cocos2d::RotateBy::create(WINDMILL_ROTATION_ACTIONS_DURATION, angle);
        cocos2d::EaseOut* ease_c = cocos2d::EaseOut::create(action, WINDMILL_ROTATION_EASE_RATE);
        cocos2d::EaseOut* ease_r = cocos2d::EaseOut::create(rotate, WINDMILL_ROTATION_EASE_RATE);
        cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(ease_c, ease_r);
        float speed = 1.0f;
        if (bubble_map_node_->getActionByTag(WINDMILL_ROTATION_ACTION_TAG))
        {
            speed = WINDMILL_ROTATION_SPEED_SPEED;
            bubble_map_node_->stopActionByTag(WINDMILL_ROTATION_ACTION_TAG);
        }
        cocos2d::Speed* speed_action = cocos2d::Speed::create(spawn, speed);
        speed_action->setTag(WINDMILL_ROTATION_ACTION_TAG);
        bubble_map_node_->runAction(speed_action);
    }


    void GameScene::moveMapWithDistance(float moveby_distance)
    {
        float time = 0.7f;
        if (!this->isFirstHandle())
        {
            time = abs(moveby_distance) / (MAP_MOVE_SPEED + 200.0);
        }
        cocos2d::MoveBy* move = cocos2d::MoveBy::create(time, cocos2d::Vec2(0, moveby_distance));
        cocos2d::EaseIn* ease = cocos2d::EaseIn::create(move, 0.5f);
        cocos2d::CallFunc* func = cocos2d::CallFunc::create(CC_CALLBACK_0(GameScene::setPhysicsWorldBody, this));
        cocos2d::CallFunc* first_func = cocos2d::CallFunc::create(CC_CALLBACK_0(GameScene::doSomethingAfterFirstAdjustMap, this));
        cocos2d::Sequence* seq = cocos2d::Sequence::create(ease, func, first_func, NULL);
        bubble_map_node_->stopAllActions();
        bubble_map_node_->runAction(seq);
    }

    void GameScene::adjustMapPosition(cocos2d::EventCustom* event)
    {
        float* map_min_pos = static_cast<float*>(event->getUserData());
        float distance = this->getAdjustMapDistance(*map_min_pos);
        float moveby_distance = 0;
        if (distance < MIN_MAP_DISTANCE)
        {
            moveby_distance = this->getAdjustMapUpwardDistance(distance);
        }
        else if (distance > MIN_MAP_DISTANCE)
        {
            moveby_distance = this->getAdjustMapDownwardDistance(distance);
        }
        else
        {
            return;
        }
        this->moveMapWithDistance(moveby_distance);
    }

    void GameScene::fallAdjustMapPosition(cocos2d::EventCustom * event)
    {
        if (!this->isFirstHandle())
        {
            float map_min_pos = *static_cast<float*>(event->getUserData()) - FALL_MIN_MAP_OFFSET_DISTANCE;
            float distance = this->getAdjustMapDistance(map_min_pos);
            float moveby_distance = 0;
            if (distance > MIN_MAP_DISTANCE)
            {
                moveby_distance = MIN(this->getAdjustMapDownwardDistance(distance), 0);
            }
            this->moveMapWithDistance(moveby_distance);
        }
        else
        {
            this->adjustMapPosition(event);
        }
    }

    void GameScene::useBubbleBombProps(cocos2d::EventCustom* event)
    {
        //if (nullptr == this->getPrepareBubble())
        //{
        //    return;
        //}
        
        this->removeExchangeBubbleListener();
        BaseProperty* property = static_cast<BaseProperty*>(event->getUserData());
        auto controller = GamePlayController::getInstance();
        if (color_bomb_property_->itemIsUsing() && bomb_bomb_property_->itemIsUsing())
        {
            property_bubble_->removeFromParent();
            property_bubble_ = BubbleFactory::getInstance()->createBubbleWithType(props_name_to_color_[property->getName()]);
            property_bubble_->setPosition(this->getGunsightPosition());
            csb_node_->addChild(property_bubble_);
            controller->setBubbleShootEnabled(true);
            controller->setPrepareBubble(property_bubble_);
            this->changeSightingDeviceColor();
            property->actionEnded();
            if (property->getName() != PROPS_COLOR_BOMB_NAME)
            {
                dynamic_cast<BaseProperty*>(this->getChildByName(PROPS_COLOR_BOMB_NAME))->BaseProperty::cancelUseItem();
            }
            else
            {
                dynamic_cast<BaseProperty*>(this->getChildByName(PROPS_BOMB_BOMB_NAME))->BaseProperty::cancelUseItem();
            }
        }
        else
        {
            property_bubble_ = BubbleFactory::getInstance()->createBubbleWithType(props_name_to_color_[property->getName()]);
            property_bubble_->setPosition(this->getGunsightPosition());
            csb_node_->addChild(property_bubble_);
            property->actionBegan();
            controller->setBubbleShootEnabled(false);
            if (BaseBubble* bubble = this->getSecondPrepareBubble())
            {
                bubble->setVisible(false);
            }
            cocos2d::MoveTo* move = cocos2d::MoveTo::create(PREPARE_RELOAD_MOVE_TIME, this->getSecondBubbleStoreNodePosition());
            cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(move, cocos2d::CallFunc::create([=]() {
                controller->setBubbleShootEnabled(true);
                controller->setPrepareBubble(property_bubble_);
                this->changeSightingDeviceColor();
                property->actionEnded();
            }));
            this->getPrepareBubble()->runAction(seq);   
        }
    }

    void GameScene::cancelUsedBubbleBombProps(cocos2d::EventCustom* event)
    {
        property_bubble_->removeFromParent();
        property_bubble_ = nullptr;
        this->haveShootPropsBubble(static_cast<BaseProperty*>(event->getUserData()));
    }

    void GameScene::haveShootPropsBubble(BaseProperty* property)
    {
        if (nullptr == this->getPrepareBubble())
        {
            return;
        }
        property->actionBegan();
        auto controller = GamePlayController::getInstance();
        controller->setBubbleShootEnabled(false);
        BaseBubble* pre_bubble = this->getPrepareBubble();
        cocos2d::MoveTo* move = cocos2d::MoveTo::create(PREPARE_RELOAD_MOVE_TIME, this->getGunsightPosition());
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(move, cocos2d::CallFunc::create([=]() {
            controller->setBubbleShootEnabled(true);
            if (BaseBubble* bubble = this->getSecondPrepareBubble())
            {
                bubble->setVisible(!this->isOnlyBubbleUseCount());
            }
            this->addExchangeBubbleListener();
            controller->setPrepareBubble(pre_bubble);
            property->actionEnded();
            this->changeSightingDeviceColor();
        }));
        pre_bubble->runAction(seq);
    }

    void GameScene::setPropertyTouchEnabled(bool flag)
    {
        bool game_result = GameScoreController::getInstance()->gameVictory() || GameScoreController::getInstance()->gameDefeat();
        bool enabledFlag = !game_result && flag;
        color_bomb_property_->setPropertyEnabled(enabledFlag);
        bomb_bomb_property_->setPropertyEnabled(enabledFlag);
        wooden_hammer_property_->setPropertyEnabled(enabledFlag);
        staves_property_->setPropertyEnabled(enabledFlag);
    }

    void GameScene::setMenuTouchEnabled(bool flag)
    {
        setPropertyTouchEnabled(flag);
		pause_menu_->setEnabled(flag);
    }

    void GameScene::haveUsedProps(cocos2d::EventCustom* event)
    {
        BaseProperty* property = static_cast<BaseProperty*>(event->getUserData());
        if (property)
        {
            props_name_to_handle_[property->getName()](property);
        }
    }

    void GameScene::addPropsSelectAlert(cocos2d::EventCustom* event)
    {
        props_weapon_ = static_cast<BaseWeapon*>(event->getUserData());
        props_weapon_->setVisible(false);
        //props_weapon_->setRotation(-bubble_map_node_->getRotation());
        csb_node_->addChild(props_weapon_);
        PropsSelectAlert* alert = PropsSelectAlert::create();
        csb_node_->addChild(alert, UI_ZORDER_MENU);
        cocos2d::LayerColor* layer = cocos2d::LayerColor::create(PROPS_SELECT_ALERT_LAYER_COLOR, GAME_DESIGN_RESOLUTION_WIDTH,
            GAME_DESIGN_RESOLUTION_HEIGHT);
        layer->setName(PROPS_SELECT_ALERT_LAYERCOLOR_NAME);
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(true);
        listener->onTouchBegan = [=](cocos2d::Touch *touch, cocos2d::Event *event) {
            return true;
        };
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, layer);
        csb_node_->addChild(layer, UI_ZORDER_PROPS_SELECT_ALERT);
        this->setMenuTouchEnabled(false);
        this->recentbubbleCast();
        bubble_map_node_->pause();
    }

    void GameScene::recentbubbleCast()
    {
        if (this->getStageType() != kWindmill)
        {
            GamePlayController::getInstance()->disposeMinYCenterBubble();
        }
        else
        {
            cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createPolygon(RECENT_BUBBLE_CAST_SHAPE, sizeof(RECENT_BUBBLE_CAST_SHAPE) / sizeof(RECENT_BUBBLE_CAST_SHAPE[0]),
                cocos2d::PhysicsMaterial(CAST_BODY_DENSITY, BUBBLE_STATIC_BODY_RESTITUTION, BUBBLE_BODY_FRICTION));
            body->setDynamic(true);
            body->setGroup(-1);
            body->setGravityEnable(false);
            body->setCategoryBitmask(BITMASK_BUBBLE_PREPARE_CATEGORY);
            body->setCollisionBitmask(0);
            body->setContactTestBitmask(BITMASK_BUBBLE_PREPARE_CONTACTTEST);
            cocos2d::Node* node = cocos2d::Node::create();
            node->setPhysicsBody(body);
            node->setName(WOODEN_HAMMER_CAST_NODE_NAME);
            node->setPosition(this->getGunsightPosition());
            csb_node_->addChild(node);
            body->applyImpulse(cocos2d::Vec2(0, RECENT_BUBBLE_CAST_IMPULSE_Y));
        }
    }

    void GameScene::selectBubble(cocos2d::EventCustom* event)
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_BUBBLE_NO_FLASH);
        BaseBubble* bubble = static_cast<BaseBubble*>(event->getUserData());
        if (props_weapon_ && props_weapon_->inAttackRange(bubble->getBubbleType()))
        {
            this->setPropsWeaponPosition(bubble->getBubblePropsWeaponPosition());
        }
    }

    void GameScene::setPropsWeaponPosition(const cocos2d::Vec2& point)
    {
        //props_weapon_->selectBubble(point);
        props_weapon_->selectBubble(this->convertMapToCsbSpace(point));
    }

    void GameScene::useSelectProperties(cocos2d::EventCustom*)
    {
        props_weapon_->attackBubble();
    }

    void GameScene::recentlyBubbleCast(cocos2d::EventCustom* event)
    {
        BaseBubble* bubble = static_cast<BaseBubble*>(event->getUserData());
        if (props_weapon_->inAttackRange(bubble->getBubbleType()))
        {
            if (cocos2d::Node* node = csb_node_->getChildByName(WOODEN_HAMMER_CAST_NODE_NAME))
            {
                node->removeFromParent();
            }
            this->setPropsWeaponPosition(bubble->getBubblePropsWeaponPosition());
            GamePlayController::getInstance()->findBubblesInVisibleSize();
        }
    }

    void GameScene::rotateSightingDevice(cocos2d::EventCustom* event)
    {
        float angle = *static_cast<float*>(event->getUserData());
        auto device = dynamic_cast<BubbleSightingDevice*>(csb_node_->getChildByName(NAME_BUBBLE_SIGHTING_DEVICE));
        if (device)
        {
           // device->rotateSightingDevice(angle, this->getMapMaxPositionY());
        }
    }

    float GameScene::getMapMaxPositionY()
    {
        float map_y = this->convertMapToCsbSpace(cocos2d::Vec2::ZERO).y;
        if (bubble_map_node_->getRotation() == 0)
        {
            return map_y;
        }
        return  GAME_PLAY_HEIGHT;
    }

    void GameScene::usedAddBubbleNumbleProps()
    {
        //GameScoreController::getInstance()->addBubbleUseCount(EnterPropsViewManager::getInstance()->getAddBubbleNumblePropsNumble());
        //cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(GAME_COMMODITY_TEN_BUBBLE_PATH);
        //sp->setPosition(this->getBubbleUseCountLabel()->getPosition());
        //csb_node_->addChild(sp, 5);
        //cocos2d::ScaleBy* scale = cocos2d::ScaleBy::create(ENTER_PROPS_ACTION_DURATION, 2.0f);
        //cocos2d::FadeOut* fade = cocos2d::FadeOut::create(ENTER_PROPS_ACTION_DURATION);
        //cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(scale, fade);
        //cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(spawn, cocos2d::CallFunc::create([=]() {
        //    sp->removeFromParent();
        //}));
        //sp->runAction(seq);

        cocos2d::Node* node = AddBubbleNumbleCommodity::createCommodityArmature();
        auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        node->setPosition(visibleSize.width/2, visibleSize.height/2);
        this->addChild(node);
    }

    bool GameScene::isFirstHandle()
    {
        return first_flag_;
    }

    void GameScene::setFirstHandleFlag(bool flag)
    {
        first_flag_ = flag;
    }

    void GameScene::mapFallingBegin()
    {
		if (GameScoreController::getInstance()->gameDefeat() || GameScoreController::getInstance()->gameVictory())
        {
            return;
        }
		cocos2d::MoveBy* move = cocos2d::MoveBy::create(3.0f, cocos2d::Vec2(0.0f, -100.0f));
        bubble_map_node_->runAction(cocos2d::RepeatForever::create(move));
    }

    //cocos2d::MoveBy * GameScene::getMapFallingAction()
    //{
    //    return cocos2d::MoveBy::create(3.0f, cocos2d::Vec2(0.0f, -100.0f));
    //}
    void GameScene::removePropsSelectAlert(cocos2d::EventCustom*)
    {
        csb_node_->getChildByName(PROPS_SELECT_ALERT_LAYERCOLOR_NAME)->removeFromParent();
        wooden_hammer_property_->cancelUseItem();
        staves_property_->cancelUseItem();
        props_weapon_ = nullptr;
        GamePlayController::getInstance()->findBubblesInVisibleSize();
        bubble_map_node_->resume();
    }

    //void GameScene::changeSwirlColor()
    //{
    //    BaseBubble* pre_bubble = GamePlayController::getInstance()->getPrepareBubble();
    //    if (!pre_bubble)
    //    {
    //        return;
    //    }
    //    std::string path = bubblecolor_to_swirl_[pre_bubble->getBubbleType()];
    //    if (path == "")
    //    {
    //        return;
    //    }
    //    cocos2d::Sprite* swirl_sp = dynamic_cast<cocos2d::Sprite*>(csb_node_->getChildByName(UI_NAME_GUNSIGHT_SWIRL));
    //    if (!swirl_sp)
    //    {
    //        cocos2d::Sprite* swirl = SpriteTextureController::getInstance()->createGameSpriteWithPath(path);
    //        swirl->setPosition(this->getGunsightPosition());
    //        swirl->setName(UI_NAME_GUNSIGHT_SWIRL);
    //        csb_node_->addChild(swirl, UI_ZORDER_SWIRL);
    //        swirl->runAction(cocos2d::RepeatForever::create(cocos2d::RotateBy::create(UI_SWIRL_ROTATIEBY_TIME, UI_SWIRL_ROTATIEBY_DEGREE)));
    //    }
    //    else
    //    {
    //        SpriteTextureController::getInstance()->setSpriteTexture(path, swirl_sp);
    //    }
    //    this->changeSightingDeviceColor();
    //}

	void GameScene::playPrepareBubbleStanbyAction()
	{
		dynamic_cast<ColorBubble*>(GamePlayController::getInstance()->getPrepareBubble())->playStanbyAnimation();
        if (ColorBubble* bubble = dynamic_cast<ColorBubble*>(this->getSecondPrepareBubble()))
        {
            bubble->stopStanbyAnimation();
        }
	}

    float GameScene::playBubblesEffects(BubbleVector bubbles)
    {
        float time = 0;
        for (auto iter : bubbles)
        {
            float effect_time = iter->playTheSpecialEffects();
            if (effect_time > time)
            {
                time = effect_time;
            }
        }
        return time;
    }

    float GameScene::getAdjustMapUpwardDistance(float distance)
    {
        return MIN_MAP_DISTANCE - distance;
    }

    float GameScene::getAdjustMapDownwardDistance(float distance)
    {

        float map_posY = bubble_map_node_->getPositionY();
        float move_dis = distance - MIN_MAP_DISTANCE;
        float sub_posY = map_posY - move_dis;
        cocos2d::Vec2 origin = this->getBubbleMapOrigin();
        float dis = sub_posY < origin.y ? (map_posY - origin.y)
            : move_dis;
        return dis*-1;
    }

    float GameScene::getBubbleMinPositionY()
    {
        float min_positionY = 0.0;
        float node_positionY = 0.0;
        cocos2d::Vector<Node*> children = bubble_map_node_->getChildren();
        for (Node* var : children)
        {
            node_positionY = var->getPositionY();
            if (node_positionY < min_positionY)
            {
                min_positionY = node_positionY;
            }
        }
        return min_positionY;
    }

    float GameScene::getAdjustMapDistance(float map_min_posY)
    {
        float min_csb_posY = this->convertMapToCsbSpace(cocos2d::Vec2(0, map_min_posY)).y;
        return min_csb_posY - this->getGunsightPosition().y;
    }

    cocos2d::Vec2 GameScene::convertMapToCsbSpace(const cocos2d::Vec2& point)
    {
        return csb_node_->convertToNodeSpaceAR(bubble_map_node_->convertToWorldSpaceAR(point));
    }

    cocos2d::Vec2 GameScene::convertCsbToMapSpace(const cocos2d::Vec2 & point)
    {
        return bubble_map_node_->convertToNodeSpaceAR(csb_node_->convertToWorldSpaceAR(point));
    }

    cocos2d::Vec2 GameScene::getBubbleMapOrigin()
    {
        cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        auto top_panel = dynamic_cast<cocos2d::Sprite*>(this->getChildByName(UI_NAME_TOP_UI_BACKGROUND));
        auto rect = top_panel->getBoundingBox();
        return cocos2d::Vec2(0, GAME_PLAY_HEIGHT);
    }
    void GameScene::eliminateSprites(cocos2d::EventCustom* event)
    {
        auto sprites = static_cast<BubbleVector*>(event->getUserData());
        //auto controller = GamePlayController::getInstance();
        int combo = GameScoreController::getInstance()->getEliminateCombo();
        float time = this->playBubblesEffects(*sprites);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(time), cocos2d::CallFunc::create([=]() {
            GamePlayController::getInstance()->checkAirBubbles();
        })));
        int color_bubble_numble = 0;
        for (size_t i = 0; i != sprites->size(); i++)
        {

            auto var = sprites->at(i);
            time = time + var->getEliminateDelayTime();
            if (var->isColorBubbleType())
            {
                ++color_bubble_numble;
            }
            var->bubbleEliminateInSequence(combo, time);
        }
        GameScoreController::getInstance()->addScoreWithEliminateNumble(color_bubble_numble);
    }

    void GameScene::disposedPrepareBubbleType()
    {
        GamePlayController::getInstance()->prepareBubbleChangeType(getSecondPrepareBubble());
		this->changeSightingDeviceColor();
    }

    void GameScene::changeSightingDeviceColor()
    {
		if (BaseBubble* bubble = GamePlayController::getInstance()->getPrepareBubble())
		{
            this->getBubbleSightingDevice()->changePointsColor(bubble->getBubbleType());
		}
    }

    void GameScene::addExchangeBubbleListener()
    {
        auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        auto game_controller = GamePlayController::getInstance();
        listener->setSwallowTouches(false);
        listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchBegan, game_controller);
        listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchMoved, game_controller);
        listener->onTouchEnded = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchEnded, game_controller);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this->getGunsight());
        listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(false);
        listener->onTouchBegan = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchBegan, game_controller);
        listener->onTouchMoved = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchMoved, game_controller);
        listener->onTouchEnded = CC_CALLBACK_2(GamePlayController::exchangePrepareBubbleOnTouchEnded, game_controller);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this->getSecondBubbleStoreNode());
    }

    void GameScene::removeExchangeBubbleListener()
    {
        auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->removeEventListenersForTarget(this->getGunsight());
        dispatcher->removeEventListenersForTarget(this->getSecondBubbleStoreNode());
    }

    void GameScene::setPrepareColorBubble(BaseBubble * bubble)
    {
        prepare_bubble_ = bubble;
        prepare_bubble_->setName(PREPARE_BUBBLE_NAME);
    }

    BaseBubble* GameScene::getPrepareBubble()
    {
        //return dynamic_cast<BaseBubble*>(csb_node_->getChildByName(PREPARE_BUBBLE_NAME));
        return prepare_bubble_;
    }

	void GameScene::setSecondPrepareBubble(BaseBubble* bubble)
	{
		second_bubble_ = bubble;
		//second_bubble_->setName(SECOND_PREPARE_BUBBLE_NAME);
	}

    BaseBubble* GameScene::getSecondPrepareBubble()
    {
		return second_bubble_;
    }

    void GameScene::spritesDownFromAir(cocos2d::EventCustom* event)
    {
        auto sprites = static_cast<BubbleVector*>(event->getUserData());
        auto controller = GamePlayController::getInstance();
        BubbleVector vector = *sprites;
        if (vector.empty())
        {
            GamePlayController::getInstance()->disposeGameDefeat();
        }
        cocos2d::CallFunc* callfunc = cocos2d::CallFunc::create([=]() {
            for (auto var : vector)
            {
                if (var->getParent() == nullptr)
                {
                    continue;
                }
                controller->subtractPrepareColor(var->getBubbleType());
                //var->retain();

                //var->setPosition(this->convertMapToCsbSpace(var->getPosition()));
                //csb_node_->addChild(var, UI_ZORDER_DOWN_AIR_BUBBLE);
                //var->release();
                //var->downFromAir();
                BaseBubble* bubble = var->clone();
                if (bubble != nullptr && bubble->isColorBubbleType())
                {
                    bubble->setPosition(this->convertMapToCsbSpace(var->getPosition()));
                    csb_node_->addChild(bubble, UI_ZORDER_DOWN_AIR_BUBBLE);
                    bubble->downFromAir();
                    var->removeFromParent();
                }
                else
                {
                    var->retain();
                    var->removeFromParent();
                    var->setPosition(this->convertMapToCsbSpace(var->getPosition()));
                    csb_node_->addChild(var, UI_ZORDER_DOWN_AIR_BUBBLE);
                    var->release();
                    var->downFromAir();
                }
            }
            this->disposedPrepareBubbleType();
        });
        //static int n = 0;
        //CCLOG("%d", ++n);
        float time = this->playBubblesEffects(*sprites) + BUBBLS_ADJUST_MAP_DELAYETIME;
        this->runAction(cocos2d::Sequence::create(callfunc, cocos2d::DelayTime::create(time), cocos2d::CallFunc::create([=]() {
            controller->adjustGameScenePosition();
            this->setMenuTouchEnabled(true);
        }), nullptr));
    }

    void GameScene::runBubbleContactEffect(cocos2d::EventCustom* event)
    {
        auto effect_bubbles = static_cast<BubbleVectorMap*>(event->getUserData());
        if (effect_bubbles->size() == 0) { return; }
        auto pre_bubble = effect_bubbles->at(PREPARE_EFFECT_BUBBLE_KEY).at(0);
        cocos2d::Vec2 pre_convert_pos = this->convertCsbToMapSpace(pre_bubble->getPosition());
        for (auto var_1 : *effect_bubbles)
        {
            for (auto var_2 : var_1.second)
            {
                var_2->runBubbleEffect(var_1.first, pre_convert_pos);
            }
        }
    }

    void GameScene::addEliminateCombo(cocos2d::EventCustom* event)
    {
        auto point = static_cast<cocos2d::Vec2*>(event->getUserData());
        this->addScoreWidget(this->convertMapToCsbSpace(*point));
        GameScoreController::getInstance()->addOneCombo();
    }

    void GameScene::addScoreWidget(const cocos2d::Vec2& point)
    {
        ScoreWidget* widget = ScoreWidgetManager::getInstance()->getNewScoreWidget();
        if (widget)
        {
            auto score_node = csb_node_->getChildByName(SCORE_WIDGET_NODE_NAME);
            widget->setPosition(point - score_node->getPosition());
            score_node->addChild(widget);
            widget->runEnterAction();
        }
    }

    void GameScene::removeTwoScoreWidget(cocos2d::EventCustom*)
    {
        ScoreWidgetManager::getInstance()->removeTwoScoreWidget();
        GameScoreController::getInstance()->eliminateComboClear();
    }

    void GameScene::scoreTextUpdate(cocos2d::EventCustom * event)
    {
        cocos2d::ui::TextBMFont* score_text = this->getScoreUI();
        assert(score_text);
        char text[10];
        int score = *static_cast<int*>(event->getUserData());
        sprintf(text, "%d", score);
        score_text->setString(text);
        this->getScoreProgressMenu()->setScoreProgressTimerPercent(score);
    }

    void GameScene::destroyBubbleDarkCloud(cocos2d::EventCustom* event)
    {
        cocos2d::Vector<ColorBubble*>* cloud_vector = static_cast<cocos2d::Vector<ColorBubble*>*>(event->getUserData());
        for (auto bubble : *cloud_vector)
        {
            bubble->destroyDarkCloud();
        }
    }

    void GameScene::addListenerForBubblesInVisibleSize(cocos2d::EventCustom* event)
    {
        auto bubbles = static_cast<BubbleVector*>(event->getUserData());
        if (add_props_flag)
        {
            for (auto bubble : *bubbles)
            {
                if (props_weapon_ && props_weapon_->inAttackRange(bubble->getBubbleType()))
                {
                    bubble->addTouchEventListener();
                }
            }
        }
        else
        {
            for (auto bubble : *bubbles)
            {
                bubble->removeTouchEventListener();
            }
        }
        add_props_flag = !add_props_flag;
    }

    void GameScene::removeListenerForBubblesInVisibleSize()
    {
        auto vector = bubble_map_node_->getChildren();
        for (auto var : vector)
        {
            dynamic_cast<BaseBubble*>(var)->removeTouchEventListener();
        }
    }

    void GameScene::playBigEliminateEffect(cocos2d::EventCustom*)
    {
        {//����Ĵ��
            cocostudio::Armature* armature = cocostudio::Armature::create(BIG_COMBO_EFFECT_FIRE_ONCE_NAME);
            armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature->setPosition(BIG_COMBO_EFFECT_FIRE_ONCE_POSITION);
            armature->getAnimation()->setSpeedScale(BIG_COMBO_EFFECT_FIRE_ONCE_SPEED);
            armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    armature->removeFromParent();
                }
            });
            csb_node_->addChild(armature, UI_ZORDER_ANIMATION_BIG_ELIMINATE_EFFECT_ONCE);
        }
        { //ǰ���С��
            cocostudio::Armature* armature = cocostudio::Armature::create(BIG_COMBO_EFFECT_FIRE_REPEAT_NAME);
            armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, true);
            //armature->getAnimation()->setSpeedScale(0.1f);
            armature->setPosition(BIG_COMBO_EFFECT_FIRE_REPEAT_POSITION);
            csb_node_->addChild(armature, UI_ZORDER_ANIMATION_BIG_ELIMINATE_EFFECT_REPEAT);
        }
        { //����
            cocos2d::Node* node = cocos2d::Node::create();
            node->setName(BIG_COMBO_EFFECT_POINT_NAME);
            csb_node_->addChild(node, UI_ZORDER_BACKGROUND);
            cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(BIG_COMBO_EFFECT_POINT_DELAYTIEM),
                cocos2d::CallFunc::create([=]() {
                cocos2d::Sprite* sprite = SpriteTextureController::getInstance()->createGameSpriteWithPath(BIG_COMBO_EFFECT_POINT_PATH);
                cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(cocos2d::ScaleTo::create(BIG_COMBO_EFFECT_POINT_TIEM, BIG_COMBO_EFFECT_POINT_SCALETO),
                    cocos2d::MoveBy::create(BIG_COMBO_EFFECT_POINT_TIEM, cocos2d::Vec2(0, BIG_COMBO_EFFECT_POINT_MOVEBY_Y)));
                cocos2d::Sequence* sp_seq = cocos2d::Sequence::createWithTwoActions(spawn, cocos2d::CallFunc::create([=]() {
                    sprite->removeFromParent();
                }));
                int x = cocos2d::random(BIG_COMBO_EFFECT_POINT_POS_X_MIN, BIG_COMBO_EFFECT_POINT_POS_X_MAX);
                int y = cocos2d::random(BIG_COMBO_EFFECT_POINT_POS_Y_MIN, BIG_COMBO_EFFECT_POINT_POS_Y_MAX);
                sprite->setPosition(x, y);
                node->addChild(sprite);
                sprite->runAction(sp_seq);
            }));
            node->runAction(cocos2d::RepeatForever::create(seq));
        }
        {//�׻�
            cocostudio::Armature* armature = cocostudio::Armature::create(BIG_COMBO_EFFECT_UNDER_FIRE_NAME);
            armature->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, true);
            armature->setPosition(BIG_COMBO_EFFECT_UNDER_FIRE_POSITION);
            csb_node_->addChild(armature, UI_ZORDER_ANIMATION_BIG_ELIMINATE_EFFECT_REPEAT);
        }
        {//Ͱ�ζ�
            this->startShakeBarrel();
            BigBackgroundEffect* blue_effect = BigBackgroundEffect::create();
            this->addChild(blue_effect, -3);
        }
        //{//������Ч
        //    this->getGameCharacter()->playLegendaryAnimation();
        //}
        {//��ǩ˫��
            barrel_score_node_->doubleBarrelScoreLabel();
        }
    }

    void GameScene::stopBigEliminateEffect(cocos2d::EventCustom*)
    {
        auto stop_func = [=](std::string name) {
            cocostudio::Armature* armature = dynamic_cast<cocostudio::Armature*>(csb_node_->getChildByName(name));
            if (armature)
            {
                armature->removeFromParent();
            }
        };
        stop_func(BIG_COMBO_EFFECT_FIRE_REPEAT_NAME);
        stop_func(BIG_COMBO_EFFECT_UNDER_FIRE_NAME);

        cocos2d::Node* node = csb_node_->getChildByName(BIG_COMBO_EFFECT_POINT_NAME);
        if (node)
        {
            node->removeFromParent();
        }
        this->stopShakeBarrel();
        barrel_score_node_->SingleBarrelScoreLabel();
    }

    void GameScene::startShakeBarrel()
    {

        auto shake_func = [=](std::string name) {
            float x = BARREL_SHAKE_MOVEBY_DISTANCE_X;
            float y = BARREL_SHAKE_MOVEBY_DISTANCE_Y;
            float time = BARREL_SHAKE_MOVEBY_DISTANCE_TIME;
            cocos2d::MoveBy* move_1 = cocos2d::MoveBy::create(time, cocos2d::Vec2(x, 0));
            cocos2d::MoveBy* move_2 = cocos2d::MoveBy::create(time, cocos2d::Vec2(-x, 0));
            cocos2d::MoveBy* move_3 = cocos2d::MoveBy::create(time, cocos2d::Vec2(-x, 0));
            cocos2d::MoveBy* move_4 = cocos2d::MoveBy::create(time, cocos2d::Vec2(x, 0));

            cocos2d::MoveBy* move_5 = cocos2d::MoveBy::create(time, cocos2d::Vec2(0, y));
            cocos2d::MoveBy* move_6 = cocos2d::MoveBy::create(time, cocos2d::Vec2(0, -y));
            cocos2d::MoveBy* move_7 = cocos2d::MoveBy::create(time, cocos2d::Vec2(0, -y));
            cocos2d::MoveBy* move_8 = cocos2d::MoveBy::create(time, cocos2d::Vec2(0, y));

            cocos2d::Sequence* seq_1 = cocos2d::Sequence::create(move_1, move_2, move_3, move_4, nullptr);
            cocos2d::Sequence* seq_2 = cocos2d::Sequence::create(move_5, move_6, move_7, move_8, nullptr);
            //cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(cocos2d::RepeatForever::create(seq_1), cocos2d::RepeatForever::create(seq_2));
            csb_node_->getChildByName(name)->runAction(cocos2d::RepeatForever::create(seq_1));
            csb_node_->getChildByName(name)->runAction(cocos2d::RepeatForever::create(seq_2));
        };
        shake_func(UI_NAME_BARRELHEAD_NODE);
        shake_func(UI_NAME_BARRELHEAD_BORDER_FIRST);
        shake_func(UI_NAME_BARRELHEAD_BORDER_SECOND);
        shake_func(UI_NAME_BARRELHEAD_BORDER_THIRD);
        shake_func(UI_NAME_BARRELHEAD_BORDER_FOURTH);
        shake_func(UI_NAME_BARRELHEAD_BORDER_FIFTH);
        shake_func(UI_NAME_BARRELHEAD_BORDER_SIXTH);
        shake_func(UI_NAME_BARREL_BOTTOM_FIRST);
        shake_func(UI_NAME_BARREL_BOTTOM_SECOND);
        shake_func(UI_NAME_BARREL_BOTTOM_THIRD);
        shake_func(UI_NAME_BARREL_BOTTOM_FOURTH);
        shake_func(UI_NAME_BARREL_BOTTOM_FIFTH);
        shake_func(UI_NAME_BARREL_NODE);
        //this->handleBarrelScoreLabel(shake_func);
        shake_func(BARREL_SCORE_LABEL_NODE_NAME);
    }

    void GameScene::stopShakeBarrel()
    {
        auto stop_func = [=](std::string name) {csb_node_->getChildByName(name)->stopAllActions(); };
        stop_func(UI_NAME_BARRELHEAD_NODE);
        //stop_func(UI_NAME_BARRELHEAD_FIRST);
        //stop_func(UI_NAME_BARRELHEAD_SECOND);
        //stop_func(UI_NAME_BARRELHEAD_THIRD);
        //stop_func(UI_NAME_BARRELHEAD_FOURTH);
        //stop_func(UI_NAME_BARRELHEAD_FIFTH);
        stop_func(UI_NAME_BARRELHEAD_BORDER_FIRST);
        stop_func(UI_NAME_BARRELHEAD_BORDER_SECOND);
        stop_func(UI_NAME_BARRELHEAD_BORDER_THIRD);
        stop_func(UI_NAME_BARRELHEAD_BORDER_FOURTH);
        stop_func(UI_NAME_BARRELHEAD_BORDER_FIFTH);
        stop_func(UI_NAME_BARRELHEAD_BORDER_SIXTH);
        stop_func(UI_NAME_BARREL_BOTTOM_FIRST);
        stop_func(UI_NAME_BARREL_BOTTOM_SECOND);
        stop_func(UI_NAME_BARREL_BOTTOM_THIRD);
        stop_func(UI_NAME_BARREL_BOTTOM_FOURTH);
        stop_func(UI_NAME_BARREL_BOTTOM_FIFTH);
        stop_func(UI_NAME_BARREL_NODE);
        //stop_func(UI_NAME_BARREL_FIRST);
        //stop_func(UI_NAME_BARREL_SECOND);
        //stop_func(UI_NAME_BARREL_THIIRD);
        //stop_func(UI_NAME_BARREL_FOURTH);
        //stop_func(UI_NAME_BARREL_FIFTH);
        //stop_func(UI_NAME_BARREL_NUMBLE_FIRST);
        //stop_func(UI_NAME_BARREL_NUMBLE_SECOND);
        //stop_func(UI_NAME_BARREL_NUMBLE_THIRD);
        //stop_func(UI_NAME_BARREL_NUMBLE_FOURTH);
        //stop_func(UI_NAME_BARREL_NUMBLE_FIFTH);

        stop_func(BARREL_SCORE_LABEL_NODE_NAME);
    }

    //void GameScene::doubleBarrelScoreLabel()
    //{
    //}

    //void GameScene::SingleBarrelScoreLabel()
    //{
    //}

    void GameScene::updateCompletedTaskLabel(cocos2d::EventCustom*)
    {
        int numble = GameScoreController::getInstance()->getCompletedTaskNumble();
        char str[5];
        sprintf(str, "%d", numble);
        this->getCompletedTaskLabel()->setString(str);
        this->estimateVictory();
    }

    void GameScene::estimateVictory()
    {
        if (GameScoreController::getInstance()->gameVictory())
        {
            this->victory();
        }
    }

    void GameScene::victory()
    {
        //this->getGameCharacter()->playVictoryAnimation();
        //this->setSecondPrepareBubble(nullptr);
        //GamePlayController::getInstance()->setPrepareBubble(nullptr);
        //cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_UPDATE_COMPLETED_TASK_LABEL);
        //cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_ESTIMATE_VICTORY);
        if (!first_victory_flag_)
        {
            return;
        }
        first_victory_flag_ = false;
		this->setPropertyTouchEnabled(false);
        GamePlayController::getInstance()->disposeVictory();
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(AFTER_VICTORY_SHOOT_BUBBLE_DELAYTIME*2), cocos2d::CallFunc::create([=]() {
            this->shootBubblesAfterVictory();
        })));
        bubble_map_node_->stopAllActions();
        //bubble_map_node_->removeFromParent();
    }

    void GameScene::shootBubblesAfterVictory()
    {
        BaseBubble* prepare_bubble = this->getPrepareBubble();
        if (!prepare_bubble)
        {
            if (!barrel_score_node_->isBarrelScoreLabelDisplay())
            {
                this->popVictoryAlert();
            }
            return;
        }
        this->getGameCharacter()->playVictoryAnimation();

        BaseBubble* prepare_bubble_copy = BubbleFactory::getInstance()->createBubbleWithType(prepare_bubble->getBubbleType());
        prepare_bubble_copy->setPosition(prepare_bubble->getPosition());
        prepare_bubble->removeFromParent();
        GamePlayController::getInstance()->clearPrepareBubble();
        csb_node_->addChild(prepare_bubble_copy);
        dynamic_cast<ColorBubble*>(prepare_bubble_copy)->shootAfterVictory();
        cocos2d::CallFunc* call_func = cocos2d::CallFunc::create([=]() {
            if (BaseBubble* bubble = this->getSecondPrepareBubble())
            {
                bubble->setVisible(true);
                cocos2d::MoveTo* move = cocos2d::MoveTo::create(AFTER_VECTORY_PREPARE_RELOAD_MOVE_TIME, this->getGunsightPosition());
                cocos2d::CallFunc* func = cocos2d::CallFunc::create([=]() {
                    dynamic_cast<ColorBubble*>(bubble)->shootAfterVictory(); 
                });
                this->addSecondPrepareBubble();
                cocos2d::Sequence* seq = cocos2d::Sequence::create(move, func, NULL);
                bubble->runAction(seq);
            }
        });
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(call_func, cocos2d::DelayTime::create(AFTER_VECTORY_PREPARE_REPEAT_DELAY_TIME));
        int count = GameScoreController::getInstance()->getBubbleUseCount();
		this->runAction(cocos2d::Repeat::create(seq, count));
        //������ʱ��Ԥ����һ������ʤ�����
        //cocos2d::Director::getInstance()->getScheduler()->pauseTarget
        this->schedule([=](float) {
            this->popVictoryAlert();
            this->unschedule(GAME_SCENE_SHOOT_BUBBLES_AFTER_VICTORY_SCHEDULE_KEY);
        }, 15.0f, GAME_SCENE_SHOOT_BUBBLES_AFTER_VICTORY_SCHEDULE_KEY);
    }

    void GameScene::replayGame()
    {
        cocos2d::Director::getInstance()->replaceScene(GameScene::createScene(this->getPresentStageCellNumble(), this->getPresentStageNumble()));
    }

    void GameScene::usedEnterProps()
    {
        EnterPropsViewManager* props_manager = EnterPropsViewManager::getInstance();
        GamePlayController* play_controller = GamePlayController::getInstance();
        if (props_manager->getPropsSwitchEnable(ADD_SPECIAL_COMMODITY_NAME))
        {
            play_controller->usedAddSpecialBubbleProps();
        }
        if (props_manager->getPropsSwitchEnable(ADD_BUBBLE_NUMBLE_COMMODITY_NAME))
        {
            this->usedAddBubbleNumbleProps();
        }
    }

    void GameScene::addKeyboardEventListener()
    {
#if (CC_TARGET_PLATFORM  ==  CC_PLATFORM_WIN32)
        auto listener = cocos2d::EventListenerKeyboard::create();
        listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event*) {
            if (code == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE)
            {
                if (!this->getChildByName(GAME_BASE_ALERT_NAME))
                {
                    this->popPauseAlert();
                }
            }
            if (code == cocos2d::EventKeyboard::KeyCode::KEY_F5)
            {
                this->replayGame();
            }
        };
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
#endif
    }

    //void GameScene::physicsRayCast(cocos2d::PhysicsRayCastCallbackFunc func, const cocos2d::Vec2 & point1, const cocos2d::Vec2 & point2)
    //{
    //    this->getScenePhysicsWorld()->rayCast(func, point1, point2, nullptr);
    //}

    void GameScene::defeat()
    {
        bubble_map_node_->stopAllActions();
        this->setPropertyTouchEnabled(false);
        GamePlayController::getInstance()->disposeDefeat();
        this->getGameCharacter()->playDefeatAnimation();
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(2.0f), cocos2d::CallFunc::create([=]() {
            this->popDefeatBuyAlert();
        })));
    }

    void GameScene::popDefeatBuyAlert()
    {
		if (this->getChildByName(GAME_DEFEAT_BUY_PROPS_ALERT_NAME))
		{
			return;
		}
        GameDefeatBuyPropsAlert* buy_alert = GameDefeatBuyPropsAlert::create();
        buy_alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        buy_alert->setPosition(visible_size.width / 2, visible_size.height / 2);
        this->addChild(buy_alert, 2);
        buy_alert->setCancelCallback([=](cocos2d::Ref*) {
            this->popDefeatAlert();
            buy_alert->removeFromParent();
        });
    }

    void GameScene::popDefeatAlert()
    {
        GameDefeatAlert* alert = GameDefeatAlert::createWithLevelNumble(this->getPresentStageNumble());
        alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visible_size.width / 2, visible_size.height / 2);
        alert->setReplayCallback([=](cocos2d::Ref*) {
            this->replayGame();
        });
        alert->setCancelCallback([=](cocos2d::Ref*) {
            cocos2d::Director::getInstance()->replaceScene(GameStageSelectionScene::createScene());
        });
        this->runAction(cocos2d::CallFunc::create([=]() {
            this->addChild(alert, 2);
        }));
    }

    void GameScene::popVictoryAlert()
    {
        if (this->getChildByName(UI_NAME_GAME_VICTORY_ALERT) != nullptr || GameScoreController::getInstance()->getBubbleUseCount() > 0)
        {
            return;
        }
        bubble_map_node_->stopAllActions();
        int start_numble = this->getScoreProgressMenu()->getStartOnNumble();
        int present_stage_numble = this->getPresentStageNumble();
        UserDataManager::getInstance()->updateStageData(present_stage_numble, start_numble);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(POP_VICTORY_ALERT_DELAYTIME), cocos2d::CallFunc::create([=]() {
            GameVictoryAlert* alert = GameVictoryAlert::create(present_stage_numble, GameScoreController::getInstance()->getTotalScore(), start_numble);
            alert->setName(UI_NAME_GAME_VICTORY_ALERT);
            alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
            cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
            alert->setPosition(visible_size.width / 2, visible_size.height / 2);
            this->addChild(alert, 2);
            alert->setReplayCallback([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
                {
                    this->replayGame();
                }
            });
            alert->setNextCallback([=](Ref* target, cocos2d::ui::Widget::TouchEventType type) {
                if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
                {
                    cocos2d::Director::getInstance()->replaceScene(GameStageSelectionScene::createSceneWithStageData(this->getPresentStageData()));
                }
                });
        })));
    }

    void GameScene::popPauseAlert()
    {
        GamePauseAlert* alert = GamePauseAlert::create();
        alert->setScale(SmartScaleController::getInstance()->getPlayAreaZoom());
        cocos2d::Size visible_size = cocos2d::Director::getInstance()->getVisibleSize();
        alert->setPosition(visible_size.width / 2, visible_size.height / 2);
        this->addChild(alert, 2);
        alert->setReturnCallback([=](cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                cocos2d::Director::getInstance()->replaceScene(GameStageSelectionScene::createScene());
                this->gameResume();
            }
        });
        alert->setReplayCallback([=](cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType type) {
            if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
            {
                this->replayGame();
                this->gameResume();
            }
        });
        alert->setContinueCallback([=](cocos2d::Ref*) {
                this->gameResume();
                alert->removeFromParent();
        });
        bubble_map_node_->pause();
        this->gamePause();
    }

    void GameScene::gamePause()
    {
        bubble_map_node_->pause();
        csb_node_->pause();
        pause_nodes_ = cocos2d::Director::getInstance()->getActionManager()->pauseAllRunningActions();
        this->getScenePhysicsWorld()->setSpeed(0);
        this->pause();
    }

    void GameScene::gameResume()
    {
        bubble_map_node_->resume();
        csb_node_->resume();
        cocos2d::Director::getInstance()->getActionManager()->resumeTargets(pause_nodes_);
        this->getScenePhysicsWorld()->setSpeed(1);
        this->resume();
    }

    void GameScene::updateBubbleUseCountLabel(cocos2d::EventCustom*)
    {
        int numble = GameScoreController::getInstance()->getBubbleUseCount();
        char str[5];
        sprintf(str, "%d", numble);
        this->getBubbleUseCountLabel()->setString(str);
    }

    void GameScene::displayBarrelScoreLabel()
    {
        if (!barrel_score_node_->isBarrelScoreLabelDisplay())
        {
            //auto func = [=](const std::string& name) {
            //    cocos2d::Node* node = csb_node_->getChildByName(name);
            //    if (node->getActionByTag(BARREL_SCORE_LABEL_ACTION_TAG) == nullptr)
            //    {
            //        cocos2d::MoveBy* move1 = cocos2d::MoveBy::create(BARREL_SCORE_LABEL_MOVEBY_1_DURATION, cocos2d::Vec2(0.0f, BARREL_SCORE_LABEL_MOVEBY_Y));
            //        cocos2d::DelayTime* delay = cocos2d::DelayTime::create(BARREL_SCORE_LABEL_DELAYTIME_DURATION);
            //        cocos2d::MoveBy* move2 = cocos2d::MoveBy::create(BARREL_SCORE_LABEL_MOVEBY_2_DURATION, cocos2d::Vec2(0.0f, -BARREL_SCORE_LABEL_MOVEBY_OFFS_Y));
            //        cocos2d::Sequence* seq = cocos2d::Sequence::create(move1, delay, move2, nullptr);
            //        seq->setTag(BARREL_SCORE_LABEL_ACTION_TAG);
            //        node->runAction(seq);
            //        this->setBarrelScoreLabelDisplay(true);
            //    }
            //};
            //this->handleBarrelScoreLabel(func);
            barrel_score_node_->displayBarrelScoreLabel();
        }
    }

    void GameScene::notDisplayedBarrelScoreLabel()
    {
        if (barrel_score_node_->isBarrelScoreLabelDisplay())
        {
            //auto func = [=](const std::string& name) {
            //    cocos2d::Node* node = csb_node_->getChildByName(name);
            //    if (node->getActionByTag(BARREL_SCORE_LABEL_ACTION_TAG) == nullptr)
            //    {
            //        cocos2d::Vector<cocos2d::FiniteTimeAction*> vector;
            //        cocos2d::MoveBy* move2 = cocos2d::MoveBy::create(BARREL_SCORE_LABEL_MOVEBY_1_DURATION, cocos2d::Vec2(0.0f, -BARREL_SCORE_LABEL_MOVEBY_Y));
            //        vector.pushBack(move2);
            //        cocos2d::DelayTime* delay = cocos2d::DelayTime::create(BARREL_SCORE_LABEL_DELAYTIME_DURATION);
            //        vector.pushBack(delay);
            //        cocos2d::MoveBy* move1 = cocos2d::MoveBy::create(BARREL_SCORE_LABEL_MOVEBY_2_DURATION, cocos2d::Vec2(0.0f, BARREL_SCORE_LABEL_MOVEBY_OFFS_Y));
            //        vector.pushBack(move1);
            //        cocos2d::Sequence* seq = cocos2d::Sequence::create(vector);
            //        seq->setTag(BARREL_SCORE_LABEL_ACTION_TAG);
            //        node->runAction(seq);
            //        this->setBarrelScoreLabelDisplay(false);
            //    }
            //};
            //this->handleBarrelScoreLabel(func);
            barrel_score_node_->notDisplayedBarrelScoreLabel();
            if (GameScoreController::getInstance()->gameVictory())
            {
                this->popVictoryAlert();
            }
        }
    }

    void  GameScene::updateGameTaskLabel()
    {
        int numble = GameScoreController::getInstance()->getGameTaskNumble();
        char str[3];
        sprintf(str, "%d", numble);
        this->getGameTaskLabel()->setString(str);
    }

    void GameScene::doSomethingAfterFirstAdjustMap()
    {
        if (this->isFirstHandle())
        {
            RainbowSealManager::getInstance()->beginSealingCharactor();
            this->addTouchEventListener();
            this->usedEnterProps();
            this->setFirstHandleFlag(false);
            this->setPropertyTouchEnabled(true);
        }
        if (this->isFallStage())
        {
            this->mapFallingBegin();
        }
    }

    bool GameScene::isOnlyBubbleUseCount()
    {
        return GameScoreController::getInstance()->getBubbleUseCount() <= 1;
    }

    //bool GameScene::isBarrelScoreLabelDisplay()
    //{
    //    return barrel_score_display_flag_;
    //}

    //void GameScene::setBarrelScoreLabelDisplay(bool flag)
    //{
    //    barrel_score_display_flag_ = flag;
    //}

    //void GameScene::handleBarrelScoreLabel(std::function<void(const std::string&name)> func)
    //{
    //    for (auto var : UI_NAME_BARREL_NUMBLES)
    //    {
    //        func(var);
    //    }
    //}
    void GameScene::addOneAirBubblesNumble(cocos2d::EventCustom*)
    {
        ++total_air_bubbles_numble_;
        //static int numble = 0;
        //++numble;
		//CCLOG("total: %d", numble);
		//CCLOG("++%d", total_air_bubbles_numble_);
        this->displayBarrelScoreLabel();
    }

    void GameScene::cutOneAirBubblesNumble(cocos2d::EventCustom*)
    {
        --total_air_bubbles_numble_;
		//CCLOG("--%d", total_air_bubbles_numble_);
        if (this->isNeedNotDisplayedBarrelScoreLabel())
        {
            this->notDisplayedBarrelScoreLabel();
            GamePlayController::getInstance()->disposeGameDefeat();
        }
    }

    void GameScene::findThreeBubble(cocos2d::EventCustom * event)
    {
        BubbleVector vector = *static_cast<BubbleVector*>(event->getUserData());
        //std::vector<BubbleType> color_vector;
        //color_vector.push_back(kBubbleBombBomb);
        //color_vector.push_back(kBubbleAddNumbleBubble);
        //if (StageDataManager::getInstance()->getStageTypeWithNumble(this->getPresentStageNumble()) != kWindmill)
        //{
        //    color_vector.push_back(kBubbleLightning);
        //}
        for (auto var : vector)
        {
            dynamic_cast<ColorBubble*>(var)->changeRandomSpecialBubble(this->convertCsbToMapSpace(this->getGunsightPosition()), 
                StageDataManager::getInstance()->getStageTypeWithNumble(this->getPresentStageNumble()));
        }
    }

    int GameScene::getTotalAirBubblesNumble()
    {
        return total_air_bubbles_numble_;
    }

    bool GameScene::isNeedNotDisplayedBarrelScoreLabel()
    {
        return this->getTotalAirBubblesNumble() == 0;
        //return AirBubbleManager::getInstance()->isNoneAirBubble();
    }

    //void GameScene::add3DCharactor()
    //{
    //    using cocos2d::Sprite3D;
    //    using cocos2d::Animate3D;
    //    using cocos2d::Animation3D;
    //    using cocos2d::Vec3;
    //    using cocos2d::Director;
    //    using cocos2d::MoveTo;
    //    using cocos2d::Sequence;
    //    using cocos2d::CallFunc;
    //    using cocos2d::RepeatForever;
    //    std::string fileName = "tortoise.c3b";
    //    auto sprite = Sprite3D::create(fileName);
    //    sprite->setScale(0.2f);
    //    auto s = Director::getInstance()->getVisibleSize();
    //    sprite->setPosition(cocos2d::Vec2(s.width / 2, s.height / 2));
    //    sprite->setGlobalZOrder(10.0f);
    //    addChild(sprite);
    //    auto animation = Animation3D::create(fileName);
    //    if (animation)
    //    {
    //        auto animate = Animate3D::create(animation, 0.f, 1.933f);
    //        auto _swim = RepeatForever::create(animate);
    //        sprite->runAction(_swim);
    //    }
    //}
}
