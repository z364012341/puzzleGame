#include "ScoreProgressMenu.h"
#include "cocostudio\CocoStudio.h"
//#include "ui\UIImageView.h"
#include "ScoreProgressStar.h"
#include "SpriteTextureController.h"
const std::string PROGRESS_TIMER_PATH = "jindutiao.png";//进度条
const std::string PROGRESS_TIMER_BACKGROUND_PATH = "jindutiaokuang.png";//进度条背景
const std::string PROGRESS_TIMER_HEAD_PARTICLE_PATH = "particle/jingyantiaotuowei.plist";//进度条头头的粒子
const std::string PROGRESS_TIMER_BUBBLE_PARTICLE_PATH = "particle/qipao6.plist";//泡泡
const std::string PROGRESS_TIMER_HEAD_PATH = "jinduyuan.png";
const float PROGRESS_TIMER_MIN = 31.8f;
const float PROGRESS_TIMER_MAX = 100.0f - PROGRESS_TIMER_MIN;
const float PROGRESS_TIMER_DISTANCE = PROGRESS_TIMER_MAX - PROGRESS_TIMER_MIN;

const float PROGRESS_TIMER_ANGLE_MIN = 360.0f * PROGRESS_TIMER_MIN / 100.0f - 90.0f;
const float PROGRESS_TIMER_ANGLE_MAX = 180.0f - PROGRESS_TIMER_ANGLE_MIN;
const float PROGRESS_TIMER_ANGLE_DISTANCE = PROGRESS_TIMER_ANGLE_MAX - PROGRESS_TIMER_ANGLE_MIN;
//float PROGRESS_TIMER_OVAL_A = 110.0f;
//float PROGRESS_TIMER_OVAL_POW2_A = 12321.0f;
//float PROGRESS_TIMER_OVAL_B = 77.0f;
//float PROGRESS_TIMER_OVAL_POW2_B = 5929.0f;
const float PROGRESS_TIMER_CIRCLE_RADIUS = 122.0f;
const int PROGRESS_TIMER_ZORDER = 1;
const int START_ZORDER = PROGRESS_TIMER_ZORDER + 1;
const cocos2d::Vec2 BACKGROUND_POS(0.0f, 52.0f);
namespace bubble_second {
    ScoreProgressMenu::ScoreProgressMenu() :global_percent_(PROGRESS_TIMER_MIN), current_percentage_(PROGRESS_TIMER_MIN)
    {
    }

    ScoreProgressMenu::~ScoreProgressMenu()
    {
    }

    bool ScoreProgressMenu::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->initScoreMenu();
        //this->setName(GAME_TOP_INFO_NAME);
        //score_progress_timer_->setPercentage(global_percent_);
        return true;
    }
    void ScoreProgressMenu::initScoreMenu()
    {
        cocos2d::Sprite* background = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROGRESS_TIMER_BACKGROUND_PATH);
        background->setPosition(BACKGROUND_POS);
        this->addChild(background, -1);

        score_progress_timer_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROGRESS_TIMER_PATH);
        score_progress_timer_->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE_BOTTOM);
        score_progress_timer_->setRotation(-PROGRESS_TIMER_ANGLE_MIN);
        this->addProgressTimerHead();

        cocos2d::ClippingNode* clipping = cocos2d::ClippingNode::create(score_progress_timer_);
        //clipping->visit(cocos2d::Director::getInstance()->getRenderer(), this->getTransf(), this->flags);
        clipping->setAlphaThreshold(0);
        clipping->setPosition(background->getPosition());
        clipping->addChild(score_progress_timer_, PROGRESS_TIMER_ZORDER);
        this->addChild(clipping);
        cocos2d::ParticleSystemQuad* bubble_particle = cocos2d::ParticleSystemQuad::create(PROGRESS_TIMER_BUBBLE_PARTICLE_PATH);
        bubble_particle->setPosition(0.0f, -150.0f);
        clipping->addChild(bubble_particle, PROGRESS_TIMER_ZORDER);
    }

    void ScoreProgressMenu::addProgressTimerHead()
    {
        cocos2d::ParticleSystemQuad* particle = cocos2d::ParticleSystemQuad::create(PROGRESS_TIMER_HEAD_PARTICLE_PATH);
        particle->setPosition(17.0f, 0.0f);
        score_progress_timer_->addChild(particle, PROGRESS_TIMER_ZORDER);
        //progress_timer_head_ = SpriteTextureController::getInstance()->createGameSpriteWithPath(PROGRESS_TIMER_HEAD_PATH);
        //this->addChild(progress_timer_head_);
        //progress_timer_head_->setVisible(false);
        //this->updateHeadPosition();
    }

    //void ScoreProgressMenu::updateHeadPosition()
    //{
    //    particle_->setPosition(this->getHeadPosition());
    //    //progress_timer_head_->setPosition(this->getHeadPosition());
    //}

   // cocos2d::Vec2 ScoreProgressMenu::getHeadPosition()
   // {
   //     return this->calculateOvalPositionWithPercent(this->getPercentage() /100.0f);
   // }

    void ScoreProgressMenu::initStartSprite()
    {
        for (auto var : this->getStartNumbleModule().getPercentModule())
        {
            ScoreProgressStar* start = ScoreProgressStar::createWithPercent(var.second);
			start->setPosition(this->getStartPositionWithPercent(start->getStartPercent()));
            this->addChild(start, START_ZORDER);
            start_sprite_map_.insert(var.first, start);
        }
    }

    cocos2d::Vec2 ScoreProgressMenu::getStartPositionWithPercent(float percent)
    {
        //cocos2d::Rect rect = this->getScoreProgressTimer()->getBoundingBox();
        //float x = PROGRESS_TIMER_OVAL_A*2 * percent - PROGRESS_TIMER_OVAL_A;
        //float y = sqrt((1 - pow(x, 2)/ PROGRESS_TIMER_OVAL_POW_A)*PROGRESS_TIMER_OVAL_POW2_B);
        //return cocos2d::Vec2(x, -y);
        return this->calculateCirclePositionWithPercent(percent);
    }

    cocos2d::Vec2 ScoreProgressMenu::calculateCirclePositionWithPercent(float percent)
    {
        //float x = PROGRESS_TIMER_OVAL_A * 2 * percent - PROGRESS_TIMER_OVAL_A;
        //float y = sqrt((1 - pow(x, 2) / PROGRESS_TIMER_OVAL_POW2_A)*PROGRESS_TIMER_OVAL_POW2_B);
        //return cocos2d::Vec2(x, -y);

        //float circle_x = PROGRESS_TIMER_OVAL_A * 2 * percent - PROGRESS_TIMER_OVAL_A;
        //float circle_y = sqrt(PROGRESS_TIMER_OVAL_POW2_A - circle_x*circle_x);
        //float line_k = circle_y / circle_x;
        //float line_pow2_k = line_k*line_k;
        //float pow2_x = 1 / (1 / PROGRESS_TIMER_OVAL_POW2_A + line_pow2_k / PROGRESS_TIMER_OVAL_POW2_B);
        //int d = circle_x < 0 ? -1 : 1;
        //float x = sqrt(pow2_x)*d;
        //float y = sqrt((1 - pow(x, 2) / PROGRESS_TIMER_OVAL_POW2_A)*PROGRESS_TIMER_OVAL_POW2_B);
        //return cocos2d::Vec2(x, -y);

        cocos2d::Vec2 origin = cocos2d::Vec2(-PROGRESS_TIMER_CIRCLE_RADIUS, BACKGROUND_POS.y);
        //origin.rotate(BACKGROUND_POS, CC_DEGREES_TO_RADIANS(PROGRESS_TIMER_ANGLE_MIN));
        float angle = PROGRESS_TIMER_ANGLE_DISTANCE * percent + PROGRESS_TIMER_ANGLE_MIN;
        origin.rotate(BACKGROUND_POS, CC_DEGREES_TO_RADIANS(angle));
        return origin;
    }

    void ScoreProgressMenu::initialStartNumble(StartNumbleModule start_numble)
    {
        start_numble_ = start_numble;
        this->initStartSprite();
    }

    //cocos2d::ProgressTimer* ScoreProgressMenu::getScoreProgressTimer()
    //{
    //    return score_progress_timer_;
    //}

    void ScoreProgressMenu::increaseProgressTimer()
    {
        //static float direction = 0.0f;
        if (this->isScheduled(GAME_SCORE_PROGRESS_SCHEDULE_KEY))
        {
            return;
        }
        float percent = this->getPercentage();
        this->schedule([=](float) {
            this->setPercentage(this->getPercentage() + GAME_SCORE_PROGRESS_TIMER_PER_INCREASE_PERCENT);
            this->controlStartLight(this->getPercentage());
            if (this->isCompletedGoalPercent(this->getPercentage()))
            {
                this->unschedule(GAME_SCORE_PROGRESS_SCHEDULE_KEY);
            }
            //this->updateHeadPosition();
        }, GAME_SCORE_PROGRESS_SCHEDULE_KEY);
    }

    void ScoreProgressMenu::setGoalPercent(float percent)
    {
        global_percent_ = percent;
    }

    float ScoreProgressMenu::getGoalPercent()
    {
        return global_percent_;
    }

    void ScoreProgressMenu::setLastScore(int last_score)
    {
        last_score_ = last_score;
    }

    int ScoreProgressMenu::getLastScore()
    {
        return last_score_;
    }

    bool ScoreProgressMenu::isEqualLastScore(int score)
    {
        return last_score_ == score;
    }

    bool ScoreProgressMenu::isCompletedGoalPercent(float percent)
    {
        return percent >= this->getGoalPercent() || percent>=100.0f;
    }

    //bool ScoreProgressMenu::isCompletedBack(float percent)
    //{
    //    //return getScoreProgressTimer()->getPercentage() <= percent || getScoreProgressTimer()->getPercentage() <= 0.0f;
    //    return this->getPercentage() <= percent || this->getPercentage() <= 0.0f;
    //}

    StartNumbleModule ScoreProgressMenu::getStartNumbleModule()
    {
        return start_numble_;
    }

    void ScoreProgressMenu::controlStartLight(float percent)
    {
        for (auto var : start_sprite_map_)
        {
            var.second->controlLightWithPercent(percent/100);
        }
    }

    void ScoreProgressMenu::setPercentage(float percentage)
    {
        float min_percent = MIN(percentage, 100);
        float new_percent = PROGRESS_TIMER_DISTANCE / 100 * min_percent + PROGRESS_TIMER_MIN;
        float delta = new_percent - current_percentage_;
        current_percentage_ = new_percent;
        this->rotateProgressTimerWithPercentDelta(delta);
        //this->getScoreProgressTimer()->setPercentage(PROGRESS_TIMER_DISTANCE / 100 * percentage + PROGRESS_TIMER_MIN);
    }

    float ScoreProgressMenu::getPercentage()
    {
        //return MAX(0.0f, (this->getScoreProgressTimer()->getPercentage() - PROGRESS_TIMER_MIN)/ PROGRESS_TIMER_DISTANCE * 100);
        return  MAX(0.0f, (current_percentage_ - PROGRESS_TIMER_MIN) / PROGRESS_TIMER_DISTANCE * 100);
    }

    void ScoreProgressMenu::rotateProgressTimerWithPercentDelta(float percent_delta)
    {
        score_progress_timer_->setRotation(score_progress_timer_->getRotation() + -360.0f * percent_delta/100);
    }

    void ScoreProgressMenu::setScoreProgressTimerPercent(float score)
    {
        if (!this->isEqualLastScore(score))
        {
            this->setLastScore(score);
            this->setGoalPercent(getStartNumbleModule().getPercentWithScore(score));
            this->increaseProgressTimer();
        }
    }

    int ScoreProgressMenu::getStartOnNumble()
    {
        int numble = 0;
        for (auto var : start_sprite_map_)
        {
            if (var.second->startIsOn())
            {
                ++numble;
            }
        }
        return numble;
    }
}