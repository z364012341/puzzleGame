#include "GameStandbyTimer.h"
#include "BubbleSecondConstant.h"

namespace bubble_second {
    GameStandbyTimer::GameStandbyTimer()
    {
    }


    GameStandbyTimer::~GameStandbyTimer()
    {
    }

    bool bubble_second::GameStandbyTimer::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->addTouchEventListener();
        this->timerBegin();
        return true;
    }

    void GameStandbyTimer::addTouchEventListener()
    {
        auto listener = cocos2d::EventListenerTouchOneByOne::create();
        listener->setSwallowTouches(false);
        listener->onTouchBegan = [=](cocos2d::Touch *touch, cocos2d::Event *event) {
            this->clearClockNumble();
            return false;
        };
        cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    }

    void GameStandbyTimer::timerBegin()
    {
        this->stopAllActions();
        cocos2d::Sequence* seq = cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(10.0f), 
            cocos2d::CallFunc::create(CC_CALLBACK_0(GameStandbyTimer::clockGoing, this)));
        this->runAction(cocos2d::RepeatForever::create(seq));
    }
    //void GameStandbyTimer::addClockNumble()
    //{
    //    ++clock_numble_;
    //}
    void GameStandbyTimer::clearClockNumble()
    {
        //clock_numble_ = 0;
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CLOCK_CLEAR);
        this->timerBegin();
    }
    void GameStandbyTimer::clockGoing()
    {
        //this->addClockNumble();
        //if (this->isClockRang())
        //{
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_CLOCK_RANG);
        //    this->clearClockNumble();
        //}
    }
    //bool GameStandbyTimer::isClockRang()
    //{
    //    return clock_numble_ == 10;
    //}
}