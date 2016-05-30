#include "RainbowSealBubble.h"
#include "BubbleComponent.h"
#include "GamePlayController.h"
#include "RainbowSealManager.h"
#include "BubbleFactory.h"
#include "RainbowCharactor.h"
#include "SpriteTextureController.h"
const std::string RAINBOW_SEAL_BUBBLE_COVER_CSB = "RainbowSealBubbleCover.csb";
const std::string BUBBLE_COVER_NAME = "kuangliubianxing_1";
namespace bubble_second {
    RainbowSealBubble::RainbowSealBubble()
    {
        first_flag_ = true;
        sealed_charactor_ = nullptr;
    }

    RainbowSealBubble::~RainbowSealBubble()
    {
    }

    bool RainbowSealBubble::init()
    {
        if (!BaseComponentBubble::init())
        {
            return false;
        }
        
        this->setBubbleType(kBubbleRainbowSeal);
        //this->addStandbyAnimation();
        this->setRainbowColor(kBubbleTransparent);
        this->setSupensionPoint(true);
        this->setBubbleComponentNumble(BUBBLE_REABOW_SEAL_COMPONENT_NUMBLE);
        this->addGameTaskNumble();
        this->runAction(cocos2d::CallFunc::create([=]() {       
            RainbowSealManager::getInstance()->addRainbowSealBubble(this);
        }));
        return true;
    }

    void RainbowSealBubble::addTouchEventListener()
    {
        if (this->isCharactorExist())
        {
            BaseComponentBubble::addTouchEventListener();
        }
    }

    void RainbowSealBubble::addBackground()
    {
        rainbow_swirl_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(RAINBOW_CHARACTOR_SWIRL_PATH);
        rainbow_swirl_->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
        this->addChild(rainbow_swirl_, -1);
        rainbow_swirl_->setOpacity(200);
        cocos2d::BlendFunc blend = { GL_SRC_ALPHA, GL_ONE };
        rainbow_swirl_->setBlendFunc(blend);
        cocos2d::RotateBy* rotate = cocos2d::RotateBy::create(8.0f, 360);
        rainbow_swirl_->runAction(cocos2d::RepeatForever::create(rotate));

        rainbow_background_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(RAINBOW_CHARACTOR_BG_PATH);
        //rainbow_background_->setScale(0.9f);
        rainbow_background_->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
        this->addChild(rainbow_background_, -2);
    }

    void RainbowSealBubble::addBubbleCover()
    {
        cover_csb_ = cocos2d::CSLoader::createNode(RAINBOW_SEAL_BUBBLE_COVER_CSB);
        this->setContentSize(cover_csb_->getChildByName(BUBBLE_COVER_NAME)->getContentSize());
        //auto action = cocos2d::CSLoader::createTimeline(RAINBOW_SEAL_BUBBLE_COVER_CSB);
        //cover->runAction(action);
        //action->gotoFrameAndPlay(0, true);

        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(RAINBOW_CHARACTOR_BG_PATH);
        sp->setScale(0.95f);
        cocos2d::ClippingNode* clipping = cocos2d::ClippingNode::create(sp);
        clipping->addChild(cover_csb_);
        clipping->setAlphaThreshold(0);
        clipping->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
        this->addChild(clipping, 1);

        //this->setContentSize(sp->getContentSize());
    }

    void RainbowSealBubble::setBubbleTexture(BubbleType type)
    {
        if (type >= 0)
        {
            //this->setSpriteFrame(BubbleFactory::getInstance()->getPathWithType(type));

            //cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(BubbleFactory::getInstance()->getPathWithType(type));
            //this->addChild(sp, 1);
            //sp->setPosition(sp->getContentSize().width / 2, sp->getContentSize().height / 2);
            this->addBubbleCover();
        }
    }

    bool RainbowSealBubble::isEqualRainbowColor(BubbleType color)
    {
        return color == this->getRainbowColor();
    }

    BubbleVector RainbowSealBubble::disposeRainbowSeal(BubbleType color)
    {
        //BubbleVector vector(0);
        if (this->isEqualRainbowColor(color))
        {   
            return this->getTotalBubbles();
        }
        else
        {
            this->changeRainbowColor();
        }
        return BubbleVector(0);
    }

    BubbleType RainbowSealBubble::getRainbowColor()
    {
        return rainbow_color_;
    }

    void RainbowSealBubble::changeRainbowColor()
    {
        if (this->isCharactorExist())
        {
            BubbleType color = this->getRainbowColor();
            do
            {
                color = GamePlayController::getInstance()->getBubbleColorFromPicker();
            } while (color == this->getRainbowColor());
            this->setRainbowColor(color);
        }
    }

    void RainbowSealBubble::setRainbowColor(BubbleType color)
    {
        GamePlayController::getInstance()->addPrepareColor(color);
        GamePlayController::getInstance()->subtractPrepareColor(this->getRainbowColor());
        rainbow_color_ = color;
        if (this->isCharactorExist())
        {
            this->setBackgroundColor(this->getRainbowColor());
        }
    }

    //void RainbowSealBubble::setSealedCharactor(RainbowCharactor* charactor)
    //{
    //    sealed_charactor_ = charactor;
    //}

    //RainbowCharactor * RainbowSealBubble::getSealedCharactor()
    //{
    //    return sealed_charactor_;
    //}

    void RainbowSealBubble::bubbleEliminate(int combo)
    {
        this->addCompletedTaskNumble();

        using cocostudio::ArmatureDataManager;
        using cocostudio::Armature;
        cocostudio::Armature* armature = Armature::create(RAINBOW_BUBBLE_ARMATURE_NAME);
        armature->setScale(0.87f);
        armature->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
        this->addChild(armature, 1);
        armature->getAnimation()->play(RAINBOW_BUBBLE_ARMATURE_BOMB_NAME, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementType == cocostudio::COMPLETE)
            {
                RainbowSealManager::getInstance()->moveSealedCharactor(this);
                this->removeFromParent();
            }
        });
        this->playCharactorDefeatAnimation();
    }

    bool RainbowSealBubble::isCharactorExist()
    {
        return sealed_charactor_ != nullptr;
    }
    void RainbowSealBubble::playCharactorDefeatAnimation()
    {
        if (this->isCharactorExist())
        {
            sealed_charactor_->playDefeatAnimation();
        }
    }

    void RainbowSealBubble::playCharactorStandbyAnimation()
    {
        if (this->isCharactorExist())
        {
            sealed_charactor_->playStandbyAnimation();
        }
    }

    void RainbowSealBubble::downFromAir()
    {
        //this->bubbleEliminate();
    }

    void RainbowSealBubble::addStandbyAnimation()
    {
        auto action = cocos2d::CSLoader::createTimeline(RAINBOW_SEAL_BUBBLE_COVER_CSB);
        cover_csb_->runAction(action);
        action->gotoFrameAndPlay(0, true);
        this->playCharactorStandbyAnimation();
    }

    void RainbowSealBubble::addRainbowCharactor()
    {
        sealed_charactor_ = RainbowCharactor::createWithFile(RAINBOW_CHARACTOR_ARMATURE_NAME);
        sealed_charactor_->setPosition(this->getContentSize().width/2, this->getContentSize().height / 2);
        this->addChild(sealed_charactor_);
    }

    void RainbowSealBubble::runBubbleEffect(const std::string& name, const cocos2d::Vec2& point)
    {
        BaseComponentBubble::runBubbleEffect(name, point);
        if (sealed_charactor_)
        {
            sealed_charactor_->playContactAnimation();
        }
    }

    void RainbowSealBubble::beginSealingCharactor()
    {
        this->addBackground();
        this->addRainbowCharactor();
        sealed_charactor_->beginSealingCharactor();
        this->addStandbyAnimation();
        this->changeRainbowColor();
    }

    void RainbowSealBubble::setBackgroundColor(BubbleType color)
    {
        //this->getSealedBubble()->setBubbleType(color);
        rainbow_background_->setColor(RainbowSealManager::getInstance()->getColor3BWithBubbleColor(color));
    }

    bool RainbowSealBubble::isEliminateByProperty()
    {
        return this->isCharactorExist();
    }
}