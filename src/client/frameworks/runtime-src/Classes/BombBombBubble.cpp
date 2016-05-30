#include "BombBombBubble.h"
#include "cocostudio/CocoStudio.h"
#include "GameScoreController.h"
#include "cocostudio\CocoStudio.h"
const std::string BOMB_BOMB_BUBBLE_CENTER_FIRE_NAME = "huoqiuTX";
const std::string BOMB_BOMB_BUBBLE_PARTICLE_PATH = "particle/huoqiulizi.plist";
namespace bubble_second {
    BombBombBubble::BombBombBubble()
    {
    }


    BombBombBubble::~BombBombBubble()
    {
    }

    bool BombBombBubble::init()
    {
        if (!BaseBubble::init())
        {
            return false;
        }
        this->setBubbleType(kBubbleBombBomb);
        this->addCenterFire();
        return true;
    }

    void BombBombBubble::addCenterFire()
    {
        cocostudio::Armature* fire = cocostudio::Armature::create(BOMB_BOMB_BUBBLE_CENTER_FIRE_NAME);
        fire->getAnimation()->playWithIndex(0);
        fire->setPosition(this->getContentSize().width/2, this->getContentSize().height/2);
        this->addChild(fire);
    }

    void BombBombBubble::downFromAir()
    {
        this->playEliminateEffect();
    }

    void BombBombBubble::bubbleEliminate(int combo)
    {
        this->playEliminateEffect();
    }

    void BombBombBubble::playEliminateEffect()
    {
        cocos2d::ParticleSystemQuad* particle = cocos2d::ParticleSystemQuad::create(BOMB_BOMB_BUBBLE_PARTICLE_PATH);
        particle->setPosition(this->getPosition());
        this->getParent()->addChild(particle);
        BaseBubble::bubbleEliminate();
        particle->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(0.5f), cocos2d::CallFunc::create([=]() {
            particle->removeFromParent();
        })));
    }
}