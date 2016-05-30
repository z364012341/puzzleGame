#include "MutipleSealBubble.h"
#include "SpriteTextureController.h"
#include "BubbleFactory.h"
#include "GameNoopAnimationComponent.h"
//#include "GameScoreController.h"
const std::string MUTIPLE_SEAL_3_BUBBLE_ARMATURE_NAME = "wa";
const std::string MUTIPLE_SEAL_7_BUBBLE_ARMATURE_NAME = "xiongda";
const std::string MUTIPLE_SEAL_1_BUBBLE_ARMATURE_NAME = "1gebianfu";
//const std::string ANIMATION_STANDBY_NAME_1 = "daiji-zhayan";
//const std::string ANIMATION_STANDBY_NAME_2 = "chuancha";
//const std::string ANIMATION_CONTACT_NAME = "aida";
//const std::string ANIMATION_VICTORY_NAME = "siwang";
//const std::string ANIMATION_DEFEAT_NAME = "shibai";
//const std::string ANIMATION_NOOP_NAME = "wucaozuo";
namespace bubble_second {
    MutipleSealBubble::MutipleSealBubble()
    {
        armature_ = nullptr;
    }

    MutipleSealBubble::~MutipleSealBubble()
    {
    }

    bool MutipleSealBubble::initWithComponentNumble(int numble)
    {
        if (!BaseComponentBubble::init())
        {
            return false;
        }
        this->setBubbleComponentNumble(numble);
        this->setBubbleType(kBubbleMutipleSeal);
        this->addGameTaskNumble();
        return true;
    }

    void MutipleSealBubble::onEnter()
    {
        cocos2d::Node::onEnter();
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        listener_ = cocos2d::EventListenerCustom::create(EVENT_GAME_DEFEAT, CC_CALLBACK_1(MutipleSealBubble::playDefeatAnimation, this));
        dispatcher->addEventListenerWithFixedPriority(listener_, 1);
        }

    void MutipleSealBubble::onExit()
    {
        cocos2d::Node::onExit();
        cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(listener_);
    }

    void MutipleSealBubble::bubbleEliminate(int combo)
    {
		//this->setLocalZOrder(1);
		//armature_->getAnimation()->play(BUBBLE_ANIMATION_VICTORY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
		//armature_->setLocalZOrder(1);
		//armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
		//	if (movementType == cocostudio::COMPLETE)
		//	{
		//		this->addCompletedTaskNumble();
		//		//armature->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::FadeOut::create(1.0f), cocos2d::CallFunc::create(CC_CALLBACK_0(MutipleSealBubble::removeFromParent, this))));
		//		this->removeFromParent();
		//	}
		//});
        //cocostudio::Armature* armature = cocostudio::Armature::create(armature_->getName());
        //armature->setPosition(this->getPosition());
        //armature->getAnimation()->play(BUBBLE_ANIMATION_VICTORY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        //armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
        //    if (movementType == cocostudio::COMPLETE)
        //    {
        //        GameScoreController::getInstance()->addCompletedTaskNumble();
        //        //armature->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::FadeOut::create(1.0f), cocos2d::CallFunc::create(CC_CALLBACK_0(MutipleSealBubble::removeFromParent, this))));
        //        armature->removeFromParent();
        //    }
        //});
        //this->setVisible(false);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.8f), cocos2d::CallFunc::create([=]() {
            SpriteTextureController::getInstance()->setSpriteTexture("", this);
            armature_->setPosition(cocos2d::Vec2::ZERO);
            armature_->getAnimation()->play(BUBBLE_ANIMATION_VICTORY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    armature_->retain();
                    armature_->setPosition(armature_->getParent()->convertToWorldSpace(armature_->getPosition()));
                    armature_->removeFromParent();

                    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_MUTIPLE_SEAL_BUBBLE_FLY, armature_);
                    armature_->release();
                    BaseBubble::bubbleEliminate();
                }
            });
        })));
    }

    //cocostudio::Armature * MutipleSealBubble::getBubbleEliminateArmature()
    //{
    //    //cocostudio::Armature* armature = cocostudio::Armature::create(armature_->getName());

    //    //armature->getAnimation()->play(BUBBLE_ANIMATION_VICTORY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
    //    return armature_;
    //}

    void MutipleSealBubble::bubbleEliminateFlyCallfunc()
    {
        this->addCompletedTaskNumble();
        this->removeFromParent();
    }

	void MutipleSealBubble::runBubbleEffect(const std::string& name, const cocos2d::Vec2& point)
	{
		BaseComponentBubble::runBubbleEffect(name, point);
		armature_->getAnimation()->play(BUBBLE_ANIMATION_CONTACT_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
		armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
			if (movementType == cocostudio::COMPLETE)
			{
				this->playStandbyAnimation();
			}
		});
	}

    void MutipleSealBubble::downFromAir()
    {
        this->bubbleEliminate();
    }

    void MutipleSealBubble::setBubbleTexture(BubbleType)
    {
        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        BubbleType type = kBubbleMutipleSeal;
        //auto func = [=](const std::string& path) {            
        //    armature_ = Armature::create(path);
        //    armature_->getAnimation()->play(MUTIPLE_SEAL_CHARACTOR_ANIMATIOIN_STANDBY_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, true);
        //    auto rect = this->getBoundingBox();
        //    armature_->setPosition(rect.size.width / 2, rect.size.height / 2);
        //    this->addChild(armature_, -1);
        //};

		auto armatureFunc = [=](const std::string& name) {
			armature_ = Armature::create(name);
			this->playStandbyAnimation();
			auto rect = this->getBoundingBox();
			armature_->setPosition(rect.size.width / 2, rect.size.height / 2);
			this->addChild(armature_, -1);
		};
        switch (this->getBubbleComponentNumble())
        {
        case BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_1:
        {
            type = kBubbleMutipleSeal1;
            BaseComponentBubble::setBubbleTexture(type);
            armatureFunc(MUTIPLE_SEAL_1_BUBBLE_ARMATURE_NAME);
            break;
        }
        case BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3:
        {
            type = kBubbleMutipleSeal3;
            BaseComponentBubble::setBubbleTexture(type);
			armatureFunc(MUTIPLE_SEAL_3_BUBBLE_ARMATURE_NAME);
            this->setAnchorPoint(BUBBLE_MUTIPLE_SEAL_3_ANCHORPOINT);
            //armature_->setScale(0.95f);
            break;
        }
        case BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_7:
        {
            type = kBubbleMutipleSeal7;
            BaseComponentBubble::setBubbleTexture(type);
			armatureFunc(MUTIPLE_SEAL_7_BUBBLE_ARMATURE_NAME);
            armature_->setScale(0.9f);
            break;
        }
        default:
            assert(false);
            break;
        }
        this->addNoopComponent();
    }

    void MutipleSealBubble::addNoopComponent()
    {
        this->addChild(GameNoopAnimationComponent::create(armature_, BUBBLE_ANIMATION_NOOP_NAME, CC_CALLBACK_0(MutipleSealBubble::playStandbyAnimation, this)));
    }

	void MutipleSealBubble::playStandbyAnimation()
	{
		std::vector<std::string> names;
		names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
		names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
		names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
		names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
		names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_2);
		names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
		names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_1);
		names.push_back(BUBBLE_ANIMATION_STANDBY_NAME_2);
		armature_->getAnimation()->playWithNames(names);
        armature_->getAnimation()->setMovementEventCallFunc(nullptr);
	}

    void MutipleSealBubble::playDefeatAnimation(cocos2d::EventCustom * event)
    {
        armature_->getAnimation()->play(BUBBLE_ANIMATION_DEFEAT_NAME);
    }

    void MutipleSealBubble::addBubbleStaticBody()
    {
        this->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(ADD_PHYSICASBODY_DELAYTIME), cocos2d::CallFunc::create([&]()
        {
            cocos2d::PhysicsBody* body = cocos2d::PhysicsBody::createCircle(BUBBLE_RADIUS,
                cocos2d::PhysicsMaterial(BUBBLE_BODY_DENSITY,
                    BUBBLE_STATIC_BODY_RESTITUTION, BUBBLE_BODY_FRICTION));
            body->setDynamic(false);
            body->setGravityEnable(false);
            body->setMass(BUBBLE_BODY_MASS);
            body->setCategoryBitmask(BITMASK_BUBBLE_STATIC_CATEGORY);
            body->setCollisionBitmask(BITMASK_BUBBLE_STATIC_COLLISION);
            body->setContactTestBitmask(BITMASK_BUBBLE_STATIC_CONTACTTEST);
            if (this->getBubbleComponentNumble() == BUBBLE_MUTIPLE_SEAL_COMPONENT_NUMBLE_3)
            {
                body->setPositionOffset(cocos2d::Vec2(0.0f, 15.0f));
            }
            this->setPhysicsBody(body);
        }), NULL));
    }
    cocos2d::Vec2 MutipleSealBubble::getBubblePropsWeaponPosition()
    {
        cocos2d::Vec2 point(this->getContentSize().width/2, this->getContentSize().height / 2);
        //this->getParent()->convertToNodeSpace(this->convertToWorldSpace(point));
        return this->getParent()->convertToNodeSpace(this->convertToWorldSpace(point));
    }
}
