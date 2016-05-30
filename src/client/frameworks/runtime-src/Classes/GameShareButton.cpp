#include "GameShareButton.h"
#include "cocostudio\CocoStudio.h"
const std::string SHARE_BUTTON_CSB_PATH = "GameShareButton.csb";
const std::string SHARE_BUTTON_ANIMATION_0_NAME = "animation0";
const std::string SHARE_BUTTON_ANIMATION_1_NAME = "animation1";

namespace bubble_second {
    GameShareButton::GameShareButton()
    {
    }

    bool GameShareButton::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        cocos2d::Node* csb_node = cocos2d::CSLoader::createNode(SHARE_BUTTON_CSB_PATH);
        auto action = cocos2d::CSLoader::createTimeline(SHARE_BUTTON_CSB_PATH);
        csb_node->runAction(action);
        action->play(SHARE_BUTTON_ANIMATION_0_NAME, false);
        action->setAnimationEndCallFunc(SHARE_BUTTON_ANIMATION_0_NAME, [=]() {
            action->play(SHARE_BUTTON_ANIMATION_1_NAME, true);
        });
        this->addChild(csb_node);
        return true;
    }


    GameShareButton::~GameShareButton()
    {
    }
}