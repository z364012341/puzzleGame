#include "UserDiamondInfoBoard.h"
#include "AddButton.h"
#include "BubbleSecondConstant.h"
const std::string CSB_PATH = "UserDiamondInfo.csb";
const std::string DIAMOND_NODE_NAME = "diamondNode";
namespace bubble_second {
    UserDiamondInfoBoard::UserDiamondInfoBoard()
    {
    }


    UserDiamondInfoBoard::~UserDiamondInfoBoard()
    {
    }

    bool UserDiamondInfoBoard::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Node* csb = cocos2d::CSLoader::createNode(CSB_PATH);
        csb->getChildByName(ADD_BUTTON_NODE_NAME)->addChild(AddButton::create());
        this->addChild(csb);

        armature_ = dynamic_cast<cocostudio::Armature*>(csb->getChildByName(DIAMOND_NODE_NAME));
        this->playRandomTimeAnimation();
        return true;
    }

    void UserDiamondInfoBoard::playRandomTimeAnimation()
    {
        int randomTime = cocos2d::random(5, 15);
        this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(randomTime), cocos2d::CallFunc::create([=]() {
            armature_->getAnimation()->playWithIndex(0, SPECIAL_BUBBLE_EFFECT_DURATION, false);
            armature_->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
                if (movementType == cocostudio::COMPLETE)
                {
                    this->playRandomTimeAnimation();
                }
            });
        })));
    }
}