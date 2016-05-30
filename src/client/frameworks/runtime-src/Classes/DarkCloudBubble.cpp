#include "DarkCloudBubble.h"
#include "SpriteTextureController.h"
#include "BubbleFactory.h"
const std::string DARK_CLOUD_PATH = "yinyunshang.png";
const float DARK_CLOUD_MOVE_X = -120.0f;
const float DARK_CLOUD_MOVE_X_FIRST = DARK_CLOUD_MOVE_X/-2;
const float DARK_CLOUD_MOVE_DURATION = 2.0f;
const float DARK_CLOUD_SCALE_MIN = 0.4f;
const float DARK_CLOUD_SCALE_MAX = 1.8f;
const float DARK_CLOUD_SCALE_DELTA = DARK_CLOUD_SCALE_MAX - DARK_CLOUD_SCALE_MIN;
const std::string DARK_CLOUD_BUBBLE_ELIMINATE_PARTICLE_PATH = "particle/yun1.plist";
namespace bubble_second {
    DarkCloudBubble::DarkCloudBubble()
    {
    }

    DarkCloudBubble::~DarkCloudBubble()
    {
    }

    bool DarkCloudBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleDarkCloud);
        this->addStandbyAction();
        return true;
    }

    void DarkCloudBubble::addStandbyAction()
    {
        cocos2d::ClippingNode* clip = cocos2d::ClippingNode::create(
            SpriteTextureController::getInstance()->createGameSpriteWithPath(BubbleFactory::getInstance()->getPathWithType(kBubbleYellow)));
        Sprite* sp = this->getCenterDarkCloud();
        clip->addChild(sp);
        clip->setAlphaThreshold(0);
        //cocos2d::MoveBy* move1 = cocos2d::MoveBy::create(DARK_CLOUD_MOVE_DURATION/2, cocos2d::Vec2(DARK_CLOUD_MOVE_X_FIRST, 0.0f));
        //sp->runAction(cocos2d::Sequence::createWithTwoActions(move1, cocos2d::CallFunc::create([=]() {
        //    cocos2d::MoveBy* move2 = cocos2d::MoveBy::create(DARK_CLOUD_MOVE_DURATION, cocos2d::Vec2(DARK_CLOUD_MOVE_X, 0.0f));
        //    sp->runAction(cocos2d::RepeatForever::create(cocos2d::Sequence::createWithTwoActions(move2, move2->reverse())));
        //})));
        clip->setPosition(this->getContentSize().width /2, this->getContentSize().height / 2);
        this->addChild(clip);
    }

    cocos2d::Sprite * DarkCloudBubble::getCenterDarkCloud()
    {
        Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(DARK_CLOUD_PATH);
        //float scale_percent = cocos2d::rand_0_1();
        //sp->setScale(DARK_CLOUD_SCALE_DELTA * scale_percent + DARK_CLOUD_SCALE_MIN);
        //sp->setOpacity(255* (1-scale_percent));
        return sp;
    }

    void DarkCloudBubble::playEliminateEffect()
    {
        cocos2d::ParticleSystemQuad* particle = cocos2d::ParticleSystemQuad::create(DARK_CLOUD_BUBBLE_ELIMINATE_PARTICLE_PATH);
        particle->setPosition(this->getPosition());
        this->getParent()->addChild(particle);
        this->removeFromParent();
        particle->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.5f), cocos2d::CallFunc::create([=]() {
            particle->removeFromParent();
        })));
    }

    void DarkCloudBubble::downFromAir()
    {
        this->playEliminateEffect();
    }

    void DarkCloudBubble::bubbleEliminate(int)
    {
        this->playEliminateEffect();
    }
}