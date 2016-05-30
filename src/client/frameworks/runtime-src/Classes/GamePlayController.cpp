#include<math.h>
#include "GamePlayController.h"
#include "GameScoreController.h"
#include "GameBubbleMap.h"
#include "ScoreWidget.h"
#include "BarrelBottom.h"
#include "BubbleColorPicker.h"
#include "SmartScaleController.h"
#include "BaseBubble.h"
#include "BlackHoleBubble.h"
#include "GameCharacter.h"
#include "BaseProperty.h"
#include "ColorBubble.h"
#include "GameScene.h"
#include "BubbleSightingDevice.h"
#include "BubbleSightingPoint.h"
namespace bubble_second {
    GamePlayController::GamePlayController()
    {
        this->initHandleMap();
        prepare_bubble_ = nullptr;
        select_bubble_ = nullptr;
        direction_ = 0;
    }

    GamePlayController::~GamePlayController()
    {
        if (bubble_map_)
        {
            bubble_map_->release();
        }
        if (color_picker_)
        {
            delete color_picker_;
            color_picker_ = nullptr;
        }
    }

    void GamePlayController::initHandleMap()
    {
        key_to_handle_map_[kBubbleTransparent] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleYellow] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubblePurple] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleBlue] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleRed] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleGreen] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleOrange] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubblePink] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleLightning] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleDarkCloud] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleAddNumbleBubble] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleBlackHole] = &GamePlayController::disposeContactWithBlackHoleBubble;
        key_to_handle_map_[kBubbleBombBomb] = &GamePlayController::disposeContactWithColorBubble;
        props_to_handle_[kBubbleColorBomb] = &GamePlayController::disposeUsingPropertyBubble;
        props_to_handle_[kBubbleBombBombProperty] = &GamePlayController::disposeUsingPropertyBubble;
        key_to_handle_map_[kBubbleComponent] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleRainbowSeal] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleMutipleSeal] = &GamePlayController::disposeContactWithColorBubble;
        key_to_handle_map_[kBubbleWindmill] = &GamePlayController::disposeContactWithColorBubble;

        this->addContactHandleWithTwoNames(&GamePlayController::disposeContactWithBubble, PREPARE_BUBBLE_NAME, MAP_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeContactWithBarrelBottom, BARREL_BOTTOM_NAME, MAP_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeContactWithScoreWidget, SCORE_WIDGET_NAME, MAP_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeContactWithBubble, COLOR_BOMB_BUBBLE_NAME, MAP_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeContactWithBubble, PROPS_BOMB_BOMB_NAME, MAP_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeBubbleCast, WOODEN_HAMMER_CAST_NODE_NAME, MAP_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeSightingPointContactBubble, NAME_BUBBLE_SIGHTING_POINT, MAP_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeWindmillBubbleBorder, UI_NAME_WINDMILL_BORDER, PREPARE_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeWindmillBubbleBorder, UI_NAME_WINDMILL_BORDER, MAP_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeContactWindmillBorder, UI_NAME_WINDMILL_BORDER, PROPS_BOMB_BOMB_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeContactWindmillBorder, UI_NAME_WINDMILL_BORDER, COLOR_BOMB_BUBBLE_NAME);
        this->addContactHandleWithTwoNames(&GamePlayController::disposeFallBubbleBorder, UI_NAME_FALL_BOTTOM_BORDER, MAP_BUBBLE_NAME);
    }

    void bubble_second::GamePlayController::addContactHandleWithTwoNames(contactHandle handle, const std::string& name_1, const std::string& name_2)
    {
		assert(!name_to_contact_handle_[name_1][name_2]);
        name_to_contact_handle_[name_1][name_2] = std::bind(handle, this, std::placeholders::_1, std::placeholders::_2);
        name_to_contact_handle_[name_2][name_1] = std::bind(handle, this, std::placeholders::_2, std::placeholders::_1);
    }

    bool GamePlayController::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
    {   
        if (!this->getBubbleShootEnabled())
        {
            return false;
        }
        auto touch_point = touch->getLocation();
        this->setTouchDirection(touch_point);
        this->disposeSightingDevice(touch_point, true);
        return true;
    }
    void GamePlayController::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)
    {
        this->disposeSightingDevice(touch->getLocation());
    }
    void GamePlayController::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        if (nullptr == prepare_bubble_)
        {
            return;
        }
        const cocos2d::Vec2 touch_location = this->convertGLToNodeSpace(touch->getLocation(), event->getCurrentTarget()->getChildByName(UI_NAME_GAME_PLAY_AREA_NODE));
        if (this->canShootingBubble(touch_location))
        { 
            this->dispatchShootEvent(touch_location);
        }
        this->turnOffSightingDevice();
    }

    bool GamePlayController::canShootingBubble(const cocos2d::Vec2& touch_location)
    {
        bool isCanShoot = this->isShootBubbleEnable(touch_location) && !this->exchangePrepareEnabled(touch_location);
        return isCanShoot;
    }

    void GamePlayController::setGameSceneDelegate(GameScene * scene_delegate)
    {
        game_scene_delegate_ = scene_delegate;
    }

    bool GamePlayController::onContactBegin(cocos2d::PhysicsContact& contact)
    {
        auto sprite_1 = dynamic_cast<cocos2d::Node*>(contact.getShapeA()->getBody()->getNode());
        auto sprite_2 = dynamic_cast<cocos2d::Node*>(contact.getShapeB()->getBody()->getNode());
        if (sprite_1 && sprite_2 && sprite_1->getPhysicsBody() && sprite_2->getPhysicsBody())
        {
            assert(name_to_contact_handle_[sprite_1->getName()][sprite_2->getName()]);
			name_to_contact_handle_[sprite_1->getName()][sprite_2->getName()](sprite_1, sprite_2);
        }
        return true;
    }

    void GamePlayController::onContactSeparate(cocos2d::PhysicsContact& contact)
    {
        auto sprite_1 = dynamic_cast<cocos2d::Node*>(contact.getShapeA()->getBody()->getNode());
        auto sprite_2 = dynamic_cast<cocos2d::Node*>(contact.getShapeB()->getBody()->getNode());
        if (!sprite_1 || !sprite_2)
        {
            return;
        }
        if (sprite_1->getName() != NAME_BUBBLE_SIGHTING_POINT && sprite_2->getName() != NAME_BUBBLE_SIGHTING_POINT)
        {
            return;
        }
        if (!dynamic_cast<BaseBubble*>(sprite_1) && !dynamic_cast<BaseBubble*>(sprite_2))
        {
            return;
        }
        auto vector = this->separateContactNodeWithName(MAP_BUBBLE_NAME, sprite_1, sprite_2);
        BubbleSightingPoint* point = dynamic_cast<BubbleSightingPoint*>(vector.back());
        if (point && vector.front()->getName() == MAP_BUBBLE_NAME)
        {
            point->cutContactCount();
        }
    }

    bool GamePlayController::isShootBubbleEnable(const cocos2d::Vec2& touch_location)
    {
        return this->getBubbleShootEnabled() &&this->isInShootArea(touch_location);
    }

    bool GamePlayController::isInShootArea(const cocos2d::Vec2& touch_location)
    {
        float angle = this->getPrepareBubbleAngle(touch_location);
        //CCLOG("ssssss%f", angle);
        //分别看方向是在上面还是在下面
        if (this->getTouchDirection() == kUpside)
        {
            return angle > SHOOT_BUBBLE_ENABLED_DEGREE && angle < (180.0f - SHOOT_BUBBLE_ENABLED_DEGREE);
        }
        else
        {
            return  (angle < -SHOOT_BUBBLE_ENABLED_DEGREE&&angle > -90.0f) || angle<270.0f&&angle >(SHOOT_BUBBLE_ENABLED_DEGREE + 180.0f);
        }
    }

    //float GamePlayController::getAngleWithVectors(const cocos2d::Vec2& point_1, const cocos2d::Vec2& point_2)
    //{
    //    return CC_RADIANS_TO_DEGREES(asin((point_2.y - point_1.y) / point_1.distance(point_2)));
    //}

    float GamePlayController::getPrepareBubbleAngle(const cocos2d::Vec2& point)
    {
        //auto a = this->getAngleWithVectors(game_scene_delegate_->getPrepareBubbleOrigin(), point);
        //auto aa = 90.0f + CC_RADIANS_TO_DEGREES(cocos2d::Vec2(0.0f, 1.0f).getAngle(point - game_scene_delegate_->getPrepareBubbleOrigin()));
		return 90.0f + CC_RADIANS_TO_DEGREES(cocos2d::Vec2(0.0f, 1.0f).getAngle(point - game_scene_delegate_->getPrepareBubbleOrigin()));
    }

    void GamePlayController::disposeContactWithBubble(cocos2d::Node* flying_node, cocos2d::Node * contact_node)
    {
        BaseBubble* flying_bubble = dynamic_cast<BaseBubble*>(flying_node);
        if (flying_bubble->isHadContacted())
        {
            return;
        }
        flying_bubble->hadContacted();
        flying_bubble->stopAllActions();
        BaseBubble* contact_bubble = dynamic_cast<BaseBubble*>(contact_node);
        if (auto props_handle = props_to_handle_[flying_bubble->getBubbleType()])
        {//优先处理道具的球
            (this->*props_handle)(flying_bubble, contact_bubble);
        }
        else if (auto bubble_handle = key_to_handle_map_[contact_bubble->getBubbleType()])
        {
            (this->*bubble_handle)(flying_bubble, contact_bubble);
        }
    }

    void GamePlayController::disposeContactWithBarrelBottom(cocos2d::Node* barrel_node, cocos2d::Node* bubble_node)
    {
        if (bubble_node->getParent())
        {
			//static int numble = 0;
			//++numble;
			//CCLOG("event_total: %d", numble);
            //bubble_node->removeFromParent();
			//cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CUT_AIR_BUBBLE_NUMBLE);
            dynamic_cast<ColorBubble*>(bubble_node)->contactBarrelBottom();
			dynamic_cast<BarrelBottom*>(barrel_node)->contactOnce();
        }
    }

    void GamePlayController::disposeContactWithScoreWidget(cocos2d::Node * widget_node, cocos2d::Node * bubble_node)
    {  
        ScoreWidget* contact_widget = dynamic_cast<ScoreWidget*>(widget_node);
        contact_widget->contactOnce();
    }

    void GamePlayController::setPrepareBubble(BaseBubble* color_bubble)
    {
        prepare_bubble_ = color_bubble;
		if (prepare_bubble_ && prepare_bubble_->getName() == "")
		{
			prepare_bubble_->setName(PREPARE_BUBBLE_NAME);
		}
    }

    void GamePlayController::clearPrepareBubble()
    {
        prepare_bubble_ = nullptr;
    }

    BaseBubble* GamePlayController::getPrepareBubble()
    {
        return prepare_bubble_;
    }

	void GamePlayController::dispatchShootEvent(const cocos2d::Vec2& touch_location)
	{
        cocos2d::Vec2 touch_point = this->getRealTouchPoint(touch_location);
        dynamic_cast<ColorBubble*>(prepare_bubble_)->setShootPoints(touch_point);
        float angle = this->getTouchAngleForPrepareBubble(touch_point);
		cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SHOOT_PREPARE_BUBBLE, &angle);
		this->setBubbleShootEnabled(false);
	}

    cocos2d::Vec2 bubble_second::GamePlayController::getRealTouchPoint(const cocos2d::Vec2 & touch_location)
    {
        cocos2d::Vec2 touch_point = touch_location;
        if (this->isTouchUnderside())
        {

            touch_point.rotate(this->getShootingInitialPosition(), CC_DEGREES_TO_RADIANS(180.0f));
        }
        return touch_point;
    }

    void GamePlayController::shootPrepareBubble()
    {
		//float angle = this->getTouchAngleForPrepareBubble(touch_location);
		//cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SHOOT_PREPARE_BUBBLE, &angle);
		dynamic_cast<ColorBubble*>(prepare_bubble_)->shoot();
    }

    float GamePlayController::getPlayAreaMaxY()
    {
        if (game_scene_delegate_ != nullptr)
        {
            return game_scene_delegate_->getMapMaxPositionY();
        }
        return 0.0f;
    }

    cocos2d::Vec2 GamePlayController::getShootingInitialPosition()
    {
        return game_scene_delegate_->getPrepareBubbleOrigin();
    }

    //void GamePlayController::gamePhysicsRayCast(cocos2d::PhysicsRayCastCallbackFunc func, const cocos2d::Vec2 & point1, const cocos2d::Vec2 & point2)
    //{
    //    game_scene_delegate_->physicsRayCast(func, point1, point2);
    //}

    void GamePlayController::loadStageMap(int numble)
    {
        prepare_bubble_ = nullptr;
        select_bubble_ = nullptr;
        if (color_picker_)
        {
            delete color_picker_;
        }
        color_picker_ = new BubbleColorPicker();
        if (bubble_map_)
        {
            bubble_map_->release();
        }
        bubble_map_ = GameBubbleMap::create();
        bubble_map_->retain();
        bubble_map_->loadStageDataWithNumble(numble);
    }

    void GamePlayController::disposeContactWithColorBubble(BaseBubble* flying_bubble, BaseBubble* contacted_bubble)
    {
        bubble_map_->disposeContactBubble(flying_bubble, contacted_bubble->getBubbleIndex());      
    }

    void GamePlayController::setBubbleShootEnabled(bool flag)
    {
        shoot_bubble_enabled_ = flag;
    }

    bool GamePlayController::getBubbleShootEnabled()
    {
        return shoot_bubble_enabled_;
    }

    cocos2d::Vector<cocos2d::Node*> GamePlayController::separateContactNodeWithName(const std::string & name, 
        cocos2d::Node* node_a, cocos2d::Node* node_b)
    {//0索引的是跟参数名字一样的小球
        cocos2d::Vector<cocos2d::Node*> node_vector;
        node_vector.pushBack(node_a->getName() == name ? node_a : node_b);
        node_vector.pushBack(node_a->getName() != name ? node_a : node_b);
        return node_vector;
    }

    cocos2d::Vector<cocos2d::Node*> GamePlayController::separateContactNodeWithTag(int tag, cocos2d::Node * node_a, cocos2d::Node * node_b)
    {
        cocos2d::Vector<cocos2d::Node*> node_vector;
        node_vector.pushBack(node_a->getTag() == tag ? node_a : node_b);
        node_vector.pushBack(node_a->getTag() != tag ? node_a : node_b);
        return node_vector;
    }

    void GamePlayController::addPrepareColor(BubbleType color)
    {
        color_picker_->addColorWithBubbleColor(color);
    }

    void GamePlayController::subtractPrepareColor(BubbleType color)
    {
        color_picker_->subtractColorWithBubbleColor(color);
    }

    BubbleType GamePlayController::getBubbleColorFromPicker()
    {
        return color_picker_->getBubbleColorFromPicker();
    }

    void GamePlayController::setBubbleColorRange()
    {
        color_picker_->setColorPickerRange();
    }

    bool GamePlayController::exchangePrepareBubbleOnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        return true;
    }

    void GamePlayController::exchangePrepareBubbleOnTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {

    }

    void GamePlayController::exchangePrepareBubbleOnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        const cocos2d::Vec2& touch_location = this->convertGLToNodeSpace(touch->getLocation(), event->getCurrentTarget()->getParent());
        bool exchange_flag = this->exchangePrepareEnabled(touch_location);
        if (needExchangePrepareBubble(exchange_flag))
        {
            this->setBubbleShootEnabled(!exchange_flag);
            cocos2d::EventCustom event(EVENT_EXCHANGE_BUBBLE);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
        }
    }

    bool bubble_second::GamePlayController::needExchangePrepareBubble(bool exchange_flag)
    {
        return this->getBubbleShootEnabled() && this->getBubbleShootEnabled() == exchange_flag;
    }

    bool GamePlayController::exchangePrepareEnabled(const cocos2d::Vec2& touch_point)
    {
        return this->touchInGunsight(touch_point) || this->touchInGrass(touch_point);
    }

    bool bubble_second::GamePlayController::touchInGunsight(const cocos2d::Vec2 & touch_point)
    {
        float distance = touch_point.distance(game_scene_delegate_->getGunsight()->getPosition());
        return  distance <= GUNSIGHT_EXCHANGE_DISTANCE;
    }

    bool bubble_second::GamePlayController::touchInGrass(const cocos2d::Vec2 & touch_point)
    {
        float distance = touch_point.distance(game_scene_delegate_->getSecondBubbleStoreNode()->getPosition());
        return  distance <= GRASS_EXCHANGE_DISTANCE;
    }

    void GamePlayController::disposeSightingPointContactBubble(cocos2d::Node* sight_node, cocos2d::Node* other_node)
    {
        auto sight_point = dynamic_cast<BubbleSightingPoint*>(sight_node);
        sight_point->addContactCount();
        BubbleSightingDevice* device = dynamic_cast<BubbleSightingDevice*>(sight_node->getParent()->getParent());
        assert(device);
        device->contactBubble();
    }


    void GamePlayController::disposeWindmillBubbleBorder(cocos2d::Node * border_node, cocos2d::Node * other_node)
    {
        cocos2d::Node* bubble_node = this->separateContactNodeWithTag(COLOR_BUBBLE_TAG, border_node, other_node).front();
        bubble_map_->disposeWindmillBubbleContactBorder(dynamic_cast<BaseBubble*>(bubble_node));
    }

    void bubble_second::GamePlayController::disposeContactWindmillBorder(cocos2d::Node * border_node, cocos2d::Node * other_node)
    {
        dynamic_cast<BaseBubble*>(other_node)->bubbleEliminate();
    }

    void GamePlayController::disposeFallBubbleBorder(cocos2d::Node * border_node, cocos2d::Node * other_node)
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_GAME_DEFEAT);
    }

    cocos2d::Vec2 GamePlayController::convertGLToNodeSpace(const cocos2d::Vec2& touch_location, cocos2d::Node* node)
    {
		return node->convertToNodeSpace(touch_location);
    }

    void GamePlayController::disposeContactWithBlackHoleBubble(BaseBubble* flying_node, BaseBubble* blackhole_node)
    {
        bubble_map_->disposeContactBlackHoleBubble(flying_node, blackhole_node);
    }

    void GamePlayController::disposeUsingPropertyBubble(BaseBubble* flying_node, BaseBubble* contacted_bubble)
    {
        if (contacted_bubble->isEqualType(kBubbleBlackHole))
        {
            this->disposeContactWithBlackHoleBubble(flying_node, contacted_bubble);
            return;
        }
        bubble_map_->disposeUsedPropertyBubble(flying_node, contacted_bubble->getBubbleIndex());
    }

    void GamePlayController::prepareBubbleChangeType(BaseBubble* pre_second_bubble)
    {
        if (pre_second_bubble&&color_picker_->needChangeBubbleType(pre_second_bubble->getBubbleType()))
        {
            pre_second_bubble->setBubbleType(color_picker_->getBubbleColorFromPicker());
        }
        if (this->getPrepareBubble()&&color_picker_->needChangeBubbleType(this->getPrepareBubble()->getBubbleType()))
        {
            this->getPrepareBubble()->setBubbleType(color_picker_->getBubbleColorFromPicker());
        }
    }

    void GamePlayController::disposeBuffBubbleDown(BaseBubble* bubble)
    {
        bubble_map_->disposeBuffBubbleDown(bubble);
    }

    void GamePlayController::disposeDarkCloudBubble(const cocos2d::Vec2& contact_index)
    {
        bubble_map_->disposeDarkCloudBubble(contact_index);
    }

    void GamePlayController::checkAirBubbles()
    {
        bubble_map_->checkAirBubbles();
    }

    void GamePlayController::adjustGameScenePosition()
    {
        bubble_map_->adjustGameScenePosition();
    }

    bool GamePlayController::touchPropertyBegan(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto sprite = dynamic_cast<BaseProperty*>(event->getCurrentTarget());
        return this->touchOnIt(touch->getLocation(), sprite);
    }

    void GamePlayController::touchPropertyMoved(cocos2d::Touch *touch, cocos2d::Event *event)
    {
    }

    void GamePlayController::touchPropertyEnded(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto sprite = dynamic_cast<BaseProperty*>(event->getCurrentTarget());
        if (this->touchOnIt(touch->getLocation(), sprite) && sprite->isPropertyEnabled() && prepare_bubble_!=nullptr)
        {
            sprite->touchItem();
        }
    }

    bool GamePlayController::touchSelectBubble(cocos2d::Touch *touch, cocos2d::Event *event)
    {
        auto node = dynamic_cast<cocos2d::Node*>(event->getCurrentTarget());
        if (this->touchOnIt(touch->getLocation(), node))
        {
            auto bubble = dynamic_cast<BaseBubble*>(node);
            if (!bubble)
            {
                bubble = dynamic_cast<BaseBubble*>(node->getParent());
            }
            this->setSelectBubble(bubble);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_SELECT_BUBBLE, bubble);
            return true;
        }
        return false;
    }

    bool GamePlayController::touchOnIt(const cocos2d::Vec2& point, cocos2d::Node* sprite)
    {
        const cocos2d::Vec2 touch_location = this->convertGLToNodeSpace(point, sprite->getParent());
        if (sprite->getBoundingBox().containsPoint(touch_location))
        {
            return true;
        }
        return false;
    }

    void GamePlayController::disposeBubbleCast(cocos2d::Node* cast_node, cocos2d::Node* bubble_node)
    {
        auto weapon_box = dynamic_cast<WeaponBox*>(bubble_node);
        if (weapon_box && !(weapon_box->isEqualType(kBubbleTransparent) || weapon_box->isEqualType(kBubbleWindmill)))
        {
            //bubble_map_->disposePhysicsCaseMinYCenterBubble(dynamic_cast<BaseBubble*>(bubble_node));
            this->setSelectBubble(weapon_box);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_RECENT_BUBBLE_CAST, weapon_box);
        }
    }

    void bubble_second::GamePlayController::disposeMinYCenterBubble()
    {
        bubble_map_->disposeMinYCenterBubble();
    }

    void GamePlayController::disposeGameDefeat()
    {
        bubble_map_->disposeGameDefeat();
    }

    void GamePlayController::findBubblesInVisibleSize()
    {
        bubble_map_->findBubblesInVisibleSize();
    }

    void bubble_second::GamePlayController::disposeSelectSameBubbles()
    {
        assert(select_bubble_);
        bubble_map_->disposeStavesSelectBubble(select_bubble_);
    }

    void GamePlayController::disposeUseWoodenHammer()
    {
        bubble_map_->disposeUseWoodenHammer(select_bubble_);
        this->setSelectBubble(nullptr);
    }
    void GamePlayController::setSelectBubble(WeaponBox* bubble)
    {
        select_bubble_ = bubble;
    }

    void GamePlayController::disposeUseStaves()
    {
        bubble_map_->disposeUseStaves(select_bubble_);
        this->setSelectBubble(nullptr);
    }

    void GamePlayController::disposeSightingDevice(const cocos2d::Vec2& touch_point, bool touch_began)
    {
        //static int numble = 0;
        //if (numble >= 1)
        //{//减少触发次数以提高性能
        //    ++numble;
        //    return;
        //}
        //numble = 0;
		if (!prepare_bubble_)
		{
			return;
		}
        cocos2d::Vec2 touch_location = this->convertGLToNodeSpace(touch_point, prepare_bubble_->getParent());
        if (this->canShootingBubble(touch_location))
        {
            float angle = this->getTouchAngleForPrepareBubble(this->convertGLToNodeSpace(touch_point, prepare_bubble_->getParent()));
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_ROTATE_SIGHTING_DEVICE, &angle);
            cocos2d::Vec2 touch_point = this->getRealTouchPoint(touch_location);
            if (touch_began)
            {
                this->turnOnSightingDevice(touch_point);
            }
            else
            {
                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_MAIN_ROTATE_SIGHTING_DEVICE, &touch_point);
            }

            //this->turnOnSightingDevice();
        }
        else
        {
            this->turnOffSightingDevice();
        }
    }

    void GamePlayController::disposeVictory()
    {
        this->setBubbleShootEnabled(false);
        bubble_map_->disposeGameVictory();
    }

    void GamePlayController::disposeDefeat()
    {
        this->setBubbleShootEnabled(false);
    }

    void GamePlayController::usedAddSpecialBubbleProps()
    {
        bubble_map_->disposeUsedAddSpecialBubbleProps();
    }

    float GamePlayController::getTouchAngleForPrepareBubble(const cocos2d::Vec2& touch_location)
    {
        float angle = this->getPrepareBubbleAngle(touch_location);
		cocos2d::Vec2 pre_point = game_scene_delegate_->getPrepareBubbleOrigin();
        //int direction = touch_location.x > pre_point.x? 1: -1;
        float device_angle = (90.0f - angle);// *direction;
        return device_angle;
    }

    bool bubble_second::GamePlayController::isTouchUnderside()
    {
        return this->getTouchDirection() == kUnderside;
    }

    void GamePlayController::setTouchDirection(const cocos2d::Vec2& touch_point)
    {
        if (this->getBubbleShootEnabled())
        {
            cocos2d::Vec2 bubble_point = prepare_bubble_->getPosition();
            cocos2d::Vec2 sub_numble = this->convertGLToNodeSpace(touch_point, prepare_bubble_->getParent()) - bubble_point;
            this->setTouchDirection(sub_numble.y < 0 ? kUnderside : kUpside);//方向系数
        }
    }

    void GamePlayController::setTouchDirection(TouchDirection direction)
    {
        direction_ = direction;
    }

    TouchDirection GamePlayController::getTouchDirection()
    {
        return direction_;
    }

    void GamePlayController::turnOnSightingDevice(cocos2d::Vec2 point)
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_TURN_ON_SIGHTING_DEVICE, &point);
    }

    void GamePlayController::turnOffSightingDevice()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_TURN_OFF_SIGHTING_DEVICE);
    }

}                                                              