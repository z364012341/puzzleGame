#include "BubbleReflectionPointComponent.h"
#include "BubbleSecondConstant.h"
#include "GamePlayController.h"
const float REFLECTION_POINT_MIN_X = BUBBLE_RADIUS;
const float REFLECTION_POINT_MAX_X = GAME_DESIGN_RESOLUTION_WIDTH - BUBBLE_RADIUS;
namespace bubble_second {
    BubbleReflectionPointComponent::BubbleReflectionPointComponent()
    {
        key_to_x_[true] = REFLECTION_POINT_MIN_X;
        key_to_x_[false] = REFLECTION_POINT_MAX_X;
    }

    bool BubbleReflectionPointComponent::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        return true;
    }

    BubbleReflectionPointComponent::~BubbleReflectionPointComponent()
    {
    }

    void BubbleReflectionPointComponent::calculateReflectionPoints(const cocos2d::Vec2 & touch_point)
    {
        reflection_points_.clear();
        reflection_angles_.clear();
        id_to_hidden_.clear();
        cocos2d::Vec2 shooting_position = GamePlayController::getInstance()->getShootingInitialPosition();
        float max_y = GamePlayController::getInstance()->getPlayAreaMaxY();
        if (shooting_position.x == touch_point.x)
        {
            reflection_points_.push_back(cocos2d::Vec2(shooting_position.x, max_y));
            reflection_points_.push_back(cocos2d::Vec2(shooting_position.x, 0.0f));
            return;
        }
        float k = (touch_point.y - shooting_position.y) / (touch_point.x - shooting_position.x);
        float b = shooting_position.y - shooting_position.x *k;

        bool direction = touch_point.x < shooting_position.x;
        float x = key_to_x_[direction];
        float y = k*x + b;
        delta_y_ = (y - shooting_position.y) * 2;
        this->pushBackRelectionPoint(shooting_position, cocos2d::Vec2(x, y));

        while (reflection_points_.back().y > 0.0f)
        {
            direction = !direction;
            cocos2d::Vec2 point = cocos2d::Vec2(key_to_x_[direction], reflection_points_.back().y + delta_y_);
            this->pushBackRelectionPoint(reflection_points_.back(), point);
        }
        id_to_hidden_.pop_back();
        id_to_hidden_.push_back(true);
        this->pushBackReflectionOffset();
        //reflection_points_.pop_back();
        //reflection_angles_.pop_back();
      }

    void BubbleReflectionPointComponent::pushBackRelectionPoint(const cocos2d::Vec2 pre_point, const cocos2d::Vec2 current_point)
    {
        float max_y = GamePlayController::getInstance()->getPlayAreaMaxY();
        if (current_point.y < max_y)
        {
            reflection_points_.push_back(current_point);
            this->pushBackAngle(pre_point, current_point);
            this->pushBackDontBeHidden();
        }
        else
        {

            reflection_points_.push_back(cocos2d::Vec2::getIntersectPoint(pre_point, current_point, cocos2d::Vec2(REFLECTION_POINT_MIN_X, max_y), cocos2d::Vec2(REFLECTION_POINT_MAX_X, max_y)));
            this->pushBackAngle(pre_point, reflection_points_.back());
            this->pushBackHidden();
            reflection_points_.push_back(cocos2d::Vec2(current_point.x, max_y) - current_point + cocos2d::Vec2(current_point.x, max_y));
            this->pushBackAngle(reflection_points_.at(reflection_points_.size()-2), reflection_points_.back());
            delta_y_ *= -1;
        }
    }

    void BubbleReflectionPointComponent::pushBackAngle(const cocos2d::Vec2 & pre_point, const cocos2d::Vec2 & current_point)
    {
        auto a = -CC_RADIANS_TO_DEGREES(cocos2d::Vec2(0.0f, 1.0f).getAngle(current_point - pre_point));
        reflection_angles_.push_back(-CC_RADIANS_TO_DEGREES(cocos2d::Vec2(0.0f, 1.0f).getAngle(current_point - pre_point)));
    }

    void BubbleReflectionPointComponent::pushBackHidden()
    {
        id_to_hidden_.push_back(true);
    }

    void BubbleReflectionPointComponent::pushBackDontBeHidden()
    {
        id_to_hidden_.push_back(false);
    }

    void BubbleReflectionPointComponent::pushBackReflectionOffset()
    {
        reflection_offset_.clear();
        cocos2d::Vec2 pre_point = GamePlayController::getInstance()->getShootingInitialPosition();
        cocos2d::Vec2 current_point;
        int offset = 0;
        for (auto var : reflection_points_)
        {
            offset = this->calculateReflectionOffset(pre_point, var, offset);
            reflection_offset_.push_back(offset);
            pre_point = var;
        }
    }

    int BubbleReflectionPointComponent::calculateReflectionOffset(const cocos2d::Vec2 & pre_point, const cocos2d::Vec2 & current_point, int pre_offset)
    {
        return (int)(pre_point.getDistance(current_point)+ pre_offset) % (int)MAP_BUBBLE_DIAMETER;
    }

    std::vector<cocos2d::Vec2> BubbleReflectionPointComponent::getReflectionPoints()
    {
        return reflection_points_;
    }

    std::vector<float> BubbleReflectionPointComponent::getReflectionAngles()
    {
        return reflection_angles_;
    }

    std::vector<bool> BubbleReflectionPointComponent::getHiddenFlags()
    {
        return id_to_hidden_;
    }
    std::vector<float> BubbleReflectionPointComponent::getReflectionoffset()
    {
        return reflection_offset_;
    }
}