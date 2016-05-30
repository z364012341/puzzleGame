//*******************************************************************************
//������   : SimpleControlSwitch
//����     : <�򵥿���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _SIMPLE_CONTROL_SWITCH_H_
#define _SIMPLE_CONTROL_SWITCH_H_
#include "cocos2d.h"
namespace bubble_second {
    class SimpleControlSwitch : public cocos2d::Node
    {
    public:
        static SimpleControlSwitch* create(cocos2d::Sprite* backgroundSprite, cocos2d::Sprite* switchSprite, cocos2d::Label* onLabel, cocos2d::Label* offLabel);
        ~SimpleControlSwitch();
        void setSwitchState(bool flag);
        bool getSwitchState();
        void setMenuCallback(const cocos2d::ccMenuCallback& callback);
    private:
        SimpleControlSwitch();
        bool init(cocos2d::Sprite* backgroundSprite, cocos2d::Sprite* switchSprite, cocos2d::Label* onLabel, cocos2d::Label* offLabel); 
        void needsLayout();
        void moveSwitch();
    private:
        cocos2d::Sprite* backgroundSprite_ = nullptr;
        cocos2d::Sprite* switchSprite_ = nullptr;
        cocos2d::Menu* switchMenu_ = nullptr;
        cocos2d::Label* onLabel_ = nullptr;
        cocos2d::Label* offLabel_ = nullptr;
        cocos2d::Vec2 left_point;
        cocos2d::Vec2 right_point;
        bool move_flag_ = false;
        float move_speed_ = 300.0f;
        bool switch_state_ = true;
        cocos2d::ccMenuCallback menu_callback_ = nullptr;
    };
}
#endif //_SIMPLE_CONTROL_SWITCH_H_