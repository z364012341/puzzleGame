#include "GameSamsung.h"
#include "ScoreProgressStar.h"
const float GAME_SAMSUNG_TWO_SIDES_POSITION_X = 150.8f;
const float GAME_SAMSUNG_MIDDLE_POSITION_Y = 55.0f;
const cocos2d::Vec2 SAMSUNG_DOUBLE_POSITION(100.0f, 0.0f);
namespace bubble_second {
    GameSamsung::GameSamsung()
    {
        numble_to_handle_[1] = CC_CALLBACK_0(GameSamsung::addStartMiddle, this);
        numble_to_handle_[2] = CC_CALLBACK_0(GameSamsung::addStartDouble, this);
        numble_to_handle_[3] = CC_CALLBACK_0(GameSamsung::addStartTriple, this);
    }

    GameSamsung::~GameSamsung()
    {
    }

    GameSamsung * bubble_second::GameSamsung::createWithNumble(int numble)
    {
        GameSamsung *pRet = new(std::nothrow) GameSamsung();
        if (pRet && pRet->initWithNumble(numble))
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

    bool GameSamsung::initWithNumble(int numble)
    {
        this->addStart(numble);
        //this->controlStartLight(numble);
        return true;
    }
    void GameSamsung::addStart(int numble)
    {
        if (auto handle = numble_to_handle_[numble])
        {
            handle();
        }
    }
    void GameSamsung::addStartLeft()
    {
        ScoreProgressStar* start = ScoreProgressStar::create();
        this->addChild(start);
        start->setPosition(-GAME_SAMSUNG_TWO_SIDES_POSITION_X, 0.0f);
        start->setRotation(-GAME_SAMSUNG_TWO_SIDES_ROTATIOIN);
        start_vector_.pushBack(start);
    }
    void GameSamsung::addStartMiddle()
    {
        ScoreProgressStar* start = ScoreProgressStar::create();
        this->addChild(start);
        start->setPosition(0.0f, GAME_SAMSUNG_MIDDLE_POSITION_Y);
        start_vector_.pushBack(start);
    }
    void GameSamsung::addStartRight()
    {
        ScoreProgressStar* start = ScoreProgressStar::create();
        this->addChild(start);
        start->setPosition(GAME_SAMSUNG_TWO_SIDES_POSITION_X, 0.0f);
        start->setRotation(GAME_SAMSUNG_TWO_SIDES_ROTATIOIN);
        start_vector_.pushBack(start);
    }

    void bubble_second::GameSamsung::addStartDouble()
    {
        ScoreProgressStar* left_start = ScoreProgressStar::create();
        this->addChild(left_start);
        left_start->setPosition(SAMSUNG_DOUBLE_POSITION*-1);
        left_start->setRotation(-GAME_SAMSUNG_TWO_SIDES_ROTATIOIN);
        start_vector_.pushBack(left_start);

        ScoreProgressStar* right_start = ScoreProgressStar::create();
        this->addChild(right_start);
        right_start->setPosition(SAMSUNG_DOUBLE_POSITION);
        right_start->setRotation(GAME_SAMSUNG_TWO_SIDES_ROTATIOIN);
        start_vector_.pushBack(right_start);
    }

    void bubble_second::GameSamsung::addStartTriple()
    {
        this->addStartLeft();
        this->addStartMiddle();
        this->addStartRight();
    }

    //void GameSamsung::controlStartLight(int numble)
    //{
    //    for (int i = 0; i < start_vector_.size(); i++)
    //    {
    //        start_vector_.at(i)->controlLightWithFlag(i<numble);
    //    }
    //}
}