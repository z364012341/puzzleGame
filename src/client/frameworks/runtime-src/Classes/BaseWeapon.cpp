#include "BaseWeapon.h"
//#include "BaseBubble.h"
const std::string& WEAPON_STANDBY_ANIMATION_NAME = "daiji";
namespace bubble_second {
    BaseWeapon::BaseWeapon()
    {
    }


    BaseWeapon::~BaseWeapon()
    {
    }

    bool BaseWeapon::inAttackRange(BubbleType color)
    {
        return true;
    }

    void BaseWeapon::attackBubble()
    {
        this->removeFromParent();
    }

    void BaseWeapon::selectBubble(const cocos2d::Vec2 & point)
    {
        this->setPosition(point);
        this->setVisible(true);
    }

    bool BaseWeapon::init(const std::string& armature_name)
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        //select_bubble_ = nullptr;
        armature_ = cocostudio::Armature::create(armature_name);
        armature_->getAnimation()->play(WEAPON_STANDBY_ANIMATION_NAME);
        this->addChild(armature_);
        return true;
    }

    cocostudio::Armature * BaseWeapon::getWeaponArmature()
    {
        return armature_;
    }

    //void BaseWeapon::setSelectBubble(BaseBubble* bubble)
    //{
    //    select_bubble_ = bubble;
    //    this->setPosition(select_bubble_->getPosition());
    //    select_bubble_->getParent()->addChild(this);
    //}
}