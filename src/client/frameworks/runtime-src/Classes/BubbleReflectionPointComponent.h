//*******************************************************************************
//类名称   : BubbleReflectionPointComponent
//功能     : <小球反射路径计算组件>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_REFLECTION_POINT_COMPONENT_H_
#define _BUBBLE_REFLECTION_POINT_COMPONENT_H_
#include "cocos2d.h"
namespace bubble_second {
    class BubbleReflectionPointComponent  : public cocos2d::Node
    {
    public:
        CREATE_FUNC(BubbleReflectionPointComponent);
        ~BubbleReflectionPointComponent();
        //void setBubblePositionOfShooting(const cocos2d::Vec2& point);
        void calculateReflectionPoints(const cocos2d::Vec2& touch_point);
        std::vector<cocos2d::Vec2> getReflectionPoints();
        std::vector<float> getReflectionAngles();
        std::vector<bool> getHiddenFlags();
        std::vector<float> getReflectionoffset();
    private:
        BubbleReflectionPointComponent();
        bool init();
        void pushBackRelectionPoint(const cocos2d::Vec2 pre_point, const cocos2d::Vec2 current_point);
        void pushBackAngle(const cocos2d::Vec2& pre_point, const cocos2d::Vec2& current_point);
        void pushBackHidden();
        void pushBackDontBeHidden();
        void pushBackReflectionOffset();
        int calculateReflectionOffset(const cocos2d::Vec2& pre_point, const cocos2d::Vec2& current_point, int pre_offset);
    private:
        //cocos2d::Vec2 shooting_position_;
        std::vector<cocos2d::Vec2> reflection_points_;
        std::vector<float> reflection_angles_;
        std::vector<float> reflection_offset_;
        std::map<bool, float> key_to_x_;
        std::vector<bool> id_to_hidden_;
        float delta_y_ = 0.0f;
    };
}
#endif //_BUBBLE_REFLECTION_POINT_COMPONENT_H_