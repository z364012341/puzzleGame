#include "GameCharacter.h"
#include "GameScoreController.h"
//#include "SpriteTextureController.h"
#include "GamePlayController.h"
#include "GameCharactorNameManager.h"
const std::string GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_NAME = "TX-yanwu";


const std::string CHARACTER_ANIMATION_STANDBY_NAME_1 = "daiji-01-1";
const std::string CHARACTER_ANIMATION_STANDBY_NAME_2 = "daiji-02";
const std::string CHARACTER_ANIMATION_STANDBY_NAME_4 = "rengqiu-04-daiji";
const std::string CHARACTER_ANIMATION_STANDBY_NAME_3 = "rengqiu-03-daiji";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_1 = "rengqiu01";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_1TO2 = "01-rengqiuqiehuan-02";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_2TO1 = "02-rengqiuqiehuan-01";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_2 = "rengqiu-02";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_3 = "rengqiu-03";
const std::string CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_4 = "rengqiu-04";
const std::string CHARACTER_LAOHU_RELOAD_BUBBLE_ANIMATION_NAME = "jieqiu-01";
const float CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_1 = 40.0f;
const float CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_2 = -10.0f;
const float CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_3 = -40.0f;
const float CHARACTER_ARMATURE_SCALE = 0.37f;
const float CHARACTER_SHOOT_BUBBLE_DELAYTIME_1 = 0.02f;
const float CHARACTER_SHOOT_BUBBLE_DELAYTIME_2 = 0.05f;
const std::string CHARACTER_DEFEAT_ANIMATION_NAME_1 = "shibai-01";
const std::string CHARACTER_DEFEAT_ANIMATION_NAME_3 = "shibai-03ku-xunhuan";
const std::string CHARACTER_VICTORY_SMOKE_ANIMATION_NAME = "Animation1";
const std::string CHARACTER_VICTORY_STANDBY_ANIMATION_1_NAME = "shengli";
const std::string CHARACTER_VICTORY_STANDBY_ANIMATION_2_NAME = "shengli-xunhuan";

namespace bubble_second {
	GameCharacter::GameCharacter()
	{
    }


	GameCharacter::~GameCharacter()
	{
	}

	bool GameCharacter::init()
	{
		if (!cocos2d::Node::init())
		{
			return false;
		}
		this->addCharacterArmature();
		this->playStandbyAnimation1();
		return true;
	}

	void GameCharacter::onEnter()
	{
		cocos2d::Node::onEnter();
		this->addEventListenerCustom();
	}

	void GameCharacter::onExit()
	{
		this->removeEventListenerCustom();
        cocos2d::Node::onExit();
	}

	void GameCharacter::addEventListenerCustom()
	{
		auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
		dispatcher->addCustomEventListener(EVENT_SHOOT_PREPARE_BUBBLE, CC_CALLBACK_1(GameCharacter::playShootBubbleAnimation, this));
        dispatcher->addCustomEventListener(EVENT_ROTATE_SIGHTING_DEVICE, CC_CALLBACK_1(GameCharacter::changeCharacterAngle, this));
        dispatcher->addCustomEventListener(EVENT_EXCHANGE_BUBBLE, [=](cocos2d::EventCustom* event) {this->playExchangeBubbleAnimation(); });
	}

	void GameCharacter::removeEventListenerCustom()
	{
		auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
		dispatcher->removeCustomEventListeners(EVENT_SHOOT_PREPARE_BUBBLE);
        dispatcher->removeCustomEventListeners(EVENT_ROTATE_SIGHTING_DEVICE);
	}

	void GameCharacter::addCharacterArmature()
	{
		{
			cocostudio::Armature* charactor = cocostudio::Armature::create(GameCharactorNameManager::getInstance()->getCurrentArmatureName1());
			charactor->setScale(CHARACTER_ARMATURE_SCALE);
			this->addChild(charactor);
			armature_vector_.insert(GameCharactorNameManager::getInstance()->getCurrentArmatureName1(), charactor);
		}
		this->addCharacterArmatureInvisibleWithName(GameCharactorNameManager::getInstance()->getCurrentArmatureName2());
        this->addCharacterArmatureInvisibleWithName(GameCharactorNameManager::getInstance()->getCurrentArmatureName3());
	}

	void GameCharacter::addCharacterArmatureInvisibleWithName(const std::string& name)
	{
		cocostudio::Armature* charactor = cocostudio::Armature::create(name);
		charactor->setScale(CHARACTER_ARMATURE_SCALE);
		charactor->setVisible(false);
		this->addChild(charactor);
		armature_vector_.insert(name, charactor);
	}

	void GameCharacter::playShootBubbleAnimation(cocos2d::EventCustom* event)
	{
        float angle = *static_cast<float*>(event->getUserData());
		if (angle >= CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_1)
        {
            this->playShootAnimation1();
        }
        else if (angle >= CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_2)
        {
            this->playShootAnimation2();
        }
        else if (angle >= CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_3)
        {
            this->playShootAnimation3();
        }
        else
        {
            this->playShootAnimation4();
        }
	}

    void bubble_second::GameCharacter::changeCharacterAngle(cocos2d::EventCustom * event)
    {
        float angle = *static_cast<float*>(event->getUserData());
        if (angle >= CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_1)
        {
            this->playStandbyAnimation1();
			//this->playStandbyAnimation1To2(angle);
        }
        else if (angle >= CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_2)
        {
            this->playStandbyAnimation2();
        }
        else if (angle >= CHARACTER_SHOOT_BUBBLE_ANIMATION_ANGLE_3)
        {
            this->playStandbyAnimation3();
        }
        else
        {
            this->playStandbyAnimation4();
        }
    }

    void bubble_second::GameCharacter::playShootAnimationAloneWithNameAndDelaytime(const std::string& name, float delaytime = 0.0f)
    {
        GamePlayController::getInstance()->shootPrepareBubble();
        cocos2d::CallFunc* func = cocos2d::CallFunc::create([=]() {
                this->playNotLoopAnimationWithName(name);
            });
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(delaytime), func);
        this->runAction(seq);
    }

    void bubble_second::GameCharacter::playAnimationWithNameAndCallfunc(const std::string & name, const std::function<void()>& callfunc)
    {
        auto armature = this->getCharactorArmature1();
        this->setOtherArmatureInvisible(armature);
        armature->getAnimation()->stop();
        armature->getAnimation()->play(name, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE && !isDefeat())
            {
                callfunc();
            }
        });
    }

    void bubble_second::GameCharacter::playAnimationWithNamesAndCallfunc(const std::vector<std::string>& names, const std::function<void()>& callfunc)
    {
        auto armature = this->getCharactorArmature1();
        armature->getAnimation()->stop();
        armature->getAnimation()->playWithNames(names, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE && movementID == names.back())
            {
                callfunc();
            }
        });
    }

    void bubble_second::GameCharacter::playShootAnimationWithBackName(const std::string & name, const std::string& backName)
    {
        auto armature = this->getCharactorArmature1();
        armature->getAnimation()->play(name, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE && !isDefeat())
            {
                this->playAnimationWithNameAndCallfunc(backName, CC_CALLBACK_0(GameCharacter::playStandbyAnimation1, this));
            }
        });
    }

	void GameCharacter::playShootAnimation1()
	{
        this->playShootAnimationAloneWithNameAndDelaytime(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_1, CHARACTER_SHOOT_BUBBLE_DELAYTIME_1);
	}

	void GameCharacter::playShootAnimation2()
	{
		//this->playAnimationWithNameAndCallfunc(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_1TO2, [=]() {
            GamePlayController::getInstance()->shootPrepareBubble();
            cocos2d::CallFunc* func = cocos2d::CallFunc::create([=]() {
                std::vector<std::string> names;
                names.push_back(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_2);
                names.push_back(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_2TO1);
				this->playAnimationWithNamesAndCallfunc(names, CC_CALLBACK_0(GameCharacter::playStandbyAnimation1, this));
            });
            cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(CHARACTER_SHOOT_BUBBLE_DELAYTIME_2), func);
            this->runAction(seq);
        //});
	}

	void GameCharacter::playShootAnimation3()
	{
		cocostudio::Armature* armature = this->getCharactorArmature2();
		this->setOtherArmatureInvisible(armature);
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(CHARACTER_SHOOT_BUBBLE_DELAYTIME_2),
            cocos2d::CallFunc::create([=]() {
            GamePlayController::getInstance()->shootPrepareBubble();
                armature->getAnimation()->play(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_3, SPECIAL_BUBBLE_EFFECT_DURATION, false);
                armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                    if (movementType == cocostudio::COMPLETE && !isDefeat())
                    {
                        this->playStandbyAnimation4();
                    }
                });
            }), 
            nullptr));
	}

    void GameCharacter::playShootAnimation4()
    {
        cocostudio::Armature* armature = this->getCharactorArmature3();
        this->setOtherArmatureInvisible(armature);
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(CHARACTER_SHOOT_BUBBLE_DELAYTIME_2),
            cocos2d::CallFunc::create([=]() {GamePlayController::getInstance()->shootPrepareBubble(); }),
            cocos2d::DelayTime::create(CHARACTER_SHOOT_BUBBLE_DELAYTIME_2),
            cocos2d::CallFunc::create([=]() {
                armature->getAnimation()->play(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_4, SPECIAL_BUBBLE_EFFECT_DURATION, false);
                armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                    if (movementType == cocostudio::COMPLETE && !isDefeat())
                    {
                        this->playStandbyAnimation4();
                    }
                });
            }), 
            nullptr)
        );
    }

    void GameCharacter::playStandbyAnimation(cocostudio::Armature* armature, const std::string& name)
    {
        if (armature->getAnimation()->getCurrentMovementID() == name && armature->isVisible())
        {
            return;
        }
        this->setOtherArmatureInvisible(armature);
        armature->getAnimation()->play(name, SPECIAL_BUBBLE_EFFECT_DURATION, true);
    }

    void GameCharacter::playStandbyAnimation1()
    {
        this->playStandbyAnimation(this->getCharactorArmature1(), CHARACTER_ANIMATION_STANDBY_NAME_1);
    }

	//void GameCharacter::playStandbyAnimation1To2(float angle)
	//{
	//	this->getCharactorArmature1()->getAnimation()->gotoAndPause(angle/40);
	//}

	void GameCharacter::playStandbyAnimation2()
	{
		this->playStandbyAnimation(this->getCharactorArmature1(), CHARACTER_ANIMATION_STANDBY_NAME_2);
	}

    void GameCharacter::playStandbyAnimation3()
    {
        this->playStandbyAnimation(this->getCharactorArmature2(), CHARACTER_ANIMATION_STANDBY_NAME_3);
    }

    void GameCharacter::playStandbyAnimation4()
    {
        this->playStandbyAnimation(this->getCharactorArmature3(), CHARACTER_ANIMATION_STANDBY_NAME_4);
    }

    //void GameCharacter::playLegendaryAnimation()
    //{
    //    //this->playNotLoopAnimationWithName(GAME_CHARACTER_ANIMATION_LEGENDARY_NAME);
    //}

	void  GameCharacter::charactorVictorChange()
	{
		this->playCharactorVictorChangeAnimation();
		cocostudio::Armature* armature = cocostudio::Armature::create(GAME_CHARACTER_ARMATURE_VICTORY_SMOKE_NAME);
		armature->setScale(3);
		this->addChild(armature);
		this->setOtherArmatureInvisible(armature);
		armature->getAnimation()->play(CHARACTER_VICTORY_SMOKE_ANIMATION_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
		armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
			if (movementType == cocostudio::COMPLETE)
			{
				armature->removeFromParent();
			}
		});
	}

    void GameCharacter::playExchangeBubbleAnimation()
    {
        if (GameScoreController::getInstance()->getBubbleUseCount()<=1)
        {
            return;
        }
        this->playAnimationWithNameAndCallfunc(CHARACTER_LAOHU_RELOAD_BUBBLE_ANIMATION_NAME, CC_CALLBACK_0(GameCharacter::playStandbyAnimation1, this));
    }

    void GameCharacter::playVictoryAnimation()
    {
		auto armature = this->getCharactorArmature1();
		armature->getAnimation()->stop();
		armature->getAnimation()->play(CHARACTER_LAOHU_SHOOT_BUBBLE_ANIMATION_NAME_2, SPECIAL_BUBBLE_EFFECT_DURATION, false);
		armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
			if (movementType == cocostudio::COMPLETE)
			{
				this->charactorVictorChange();
			}
		});
    }

	void GameCharacter::playCharactorVictorChangeAnimation()
	{
		cocostudio::Armature* charactor = cocostudio::Armature::create(GameCharactorNameManager::getInstance()->getCurrentArmatureNameVictory());
		charactor->setScale(CHARACTER_ARMATURE_SCALE);
		charactor->setOpacity(0);
		this->addChild(charactor);
		cocos2d::FadeIn* fadeIn = cocos2d::FadeIn::create(0.5);
		cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(fadeIn, cocos2d::CallFunc::create([=](){
			charactor->getAnimation()->play(CHARACTER_VICTORY_STANDBY_ANIMATION_1_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
			charactor->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
				if (movementType == cocostudio::COMPLETE)
				{
					charactor->getAnimation()->play(CHARACTER_VICTORY_STANDBY_ANIMATION_2_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
				}
			});
		}));
		charactor->runAction(seq);
	}

    void GameCharacter::playDefeatAnimation()
    {
		if (this->isDefeat())
		{
			return;
		}
        auto armature = this->getCharactorArmature1();
		armature->getAnimation()->stop();
        this->setOtherArmatureInvisible(armature);
		//armature->setVisible(true);
        this->setDefeatFlag(true);
		armature->getAnimation()->play(CHARACTER_DEFEAT_ANIMATION_NAME_1, SPECIAL_BUBBLE_EFFECT_DURATION, false);
		armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
			if (movementType == cocostudio::COMPLETE)
			{
				armature->getAnimation()->play(CHARACTER_DEFEAT_ANIMATION_NAME_3, SPECIAL_BUBBLE_EFFECT_DURATION, true);
			}
		});
    }

    cocostudio::Armature * GameCharacter::getCharactorArmature1()
    {
		return armature_vector_.at(GameCharactorNameManager::getInstance()->getCurrentArmatureName1());
    }

	cocostudio::Armature * GameCharacter::getCharactorArmature2()
	{
		return armature_vector_.at(GameCharactorNameManager::getInstance()->getCurrentArmatureName2());
	}

    cocostudio::Armature * GameCharacter::getCharactorArmature3()
    {
        return armature_vector_.at(GameCharactorNameManager::getInstance()->getCurrentArmatureName3());
    }

    void GameCharacter::playNotLoopAnimationWithName(const std::string& name)
    {
        this->playAnimationWithNameAndCallfunc(name, CC_CALLBACK_0(GameCharacter::playStandbyAnimation1, this));
    }

	void GameCharacter::setOtherArmatureInvisible(cocostudio::Armature* armature)
	{
		for (auto var : armature_vector_)
		{
			var.second->setVisible(var.second == armature);
		}
	}

    void GameCharacter::setDefeatFlag(bool flag)
    {
        defeat_flag_ = flag;
    }

    bool GameCharacter::isDefeat()
    {
        return defeat_flag_;
    }
}