#include "BarrelScoreLabelNode.h"
#include "cocostudio\CocoStudio.h"
#include "XMLTool.h"   
#include "BubbleSecondConstant.h"
const std::string BARREL_SCORE_LABEL_NODE_CSB_PATH = "BarrelScoreLabelNode.csb";
const int BARREL_SCORE_LABEL_ACTION_TAG = 101; //动作的tag人直
const float BARREL_SCORE_LABEL_OFFS_Y = 75.0f;//酒桶分数的y偏移
const float BARREL_SCORE_LABEL_MOVEBY_OFFS_Y = 5.0f;
const float BARREL_SCORE_LABEL_MOVEBY_Y = BARREL_SCORE_LABEL_OFFS_Y + BARREL_SCORE_LABEL_MOVEBY_OFFS_Y; //酒桶分数的移动时候的y偏移
const float BARREL_SCORE_LABEL_MOVEBY_1_DURATION = 1.0f;
const float BARREL_SCORE_LABEL_MOVEBY_2_DURATION = 0.1f;
const float BARREL_SCORE_LABEL_DELAYTIME_DURATION = 0.3f;
const std::string UI_NAME_BARREL_NUMBLE_FIRST = "barrel_label_1"; //左数第一的桶上的数字
const std::string UI_NAME_BARREL_NUMBLE_SECOND = "barrel_label_2"; //左数第2的桶数字
const std::string UI_NAME_BARREL_NUMBLE_THIRD = "barrel_label_3"; //左数第3的桶数字
const std::string UI_NAME_BARREL_NUMBLE_FOURTH = "barrel_label_4"; //左数第4的桶数字
const std::string UI_NAME_BARREL_NUMBLE_FIFTH = "barrel_label_5"; //左数第5的桶数字
const std::string UI_NAME_BARREL_NUMBLES[5] = { UI_NAME_BARREL_NUMBLE_FIRST , UI_NAME_BARREL_NUMBLE_SECOND,
UI_NAME_BARREL_NUMBLE_THIRD,UI_NAME_BARREL_NUMBLE_FOURTH,UI_NAME_BARREL_NUMBLE_FIFTH };
namespace bubble_second {
    BarrelScoreLabelNode::BarrelScoreLabelNode()
    {
    }


    BarrelScoreLabelNode::~BarrelScoreLabelNode()
    {
    }

    void BarrelScoreLabelNode::displayBarrelScoreLabel()
    {
        if (this->getActionByTag(BARREL_SCORE_LABEL_ACTION_TAG) == nullptr)
        {
            cocos2d::MoveBy* move1 = cocos2d::MoveBy::create(BARREL_SCORE_LABEL_MOVEBY_1_DURATION, cocos2d::Vec2(0.0f, BARREL_SCORE_LABEL_MOVEBY_Y));
            cocos2d::DelayTime* delay = cocos2d::DelayTime::create(BARREL_SCORE_LABEL_DELAYTIME_DURATION);
            cocos2d::MoveBy* move2 = cocos2d::MoveBy::create(BARREL_SCORE_LABEL_MOVEBY_2_DURATION, cocos2d::Vec2(0.0f, -BARREL_SCORE_LABEL_MOVEBY_OFFS_Y));
            cocos2d::Sequence* seq = cocos2d::Sequence::create(move1, delay, move2, nullptr);
            seq->setTag(BARREL_SCORE_LABEL_ACTION_TAG);
            this->runAction(seq);
            this->setBarrelScoreLabelDisplay(true);
        }
    }

    void BarrelScoreLabelNode::notDisplayedBarrelScoreLabel()
    {
        if (this->getActionByTag(BARREL_SCORE_LABEL_ACTION_TAG) == nullptr)
        {
            cocos2d::Vector<cocos2d::FiniteTimeAction*> vector;
            cocos2d::MoveBy* move2 = cocos2d::MoveBy::create(BARREL_SCORE_LABEL_MOVEBY_1_DURATION, cocos2d::Vec2(0.0f, -BARREL_SCORE_LABEL_MOVEBY_Y));
            vector.pushBack(move2);
            cocos2d::DelayTime* delay = cocos2d::DelayTime::create(BARREL_SCORE_LABEL_DELAYTIME_DURATION);
            vector.pushBack(delay);
            cocos2d::MoveBy* move1 = cocos2d::MoveBy::create(BARREL_SCORE_LABEL_MOVEBY_2_DURATION, cocos2d::Vec2(0.0f, BARREL_SCORE_LABEL_MOVEBY_OFFS_Y));
            vector.pushBack(move1);
            cocos2d::Sequence* seq = cocos2d::Sequence::create(vector);
            seq->setTag(BARREL_SCORE_LABEL_ACTION_TAG);
            this->runAction(seq);
            this->setBarrelScoreLabelDisplay(false);
        }
    }

    bool BarrelScoreLabelNode::isBarrelScoreLabelDisplay()
    {
        return barrel_score_display_flag_;
    }

    void BarrelScoreLabelNode::doubleBarrelScoreLabel()
    {
        for (auto var : labels_)
        {
            var->setString(XMLTool::convertIntToString(XMLTool::convertStringToInt(var->getString())*2));
        }
    }

    void BarrelScoreLabelNode::SingleBarrelScoreLabel()
    {
        labels_.at(0)->setString(XMLTool::convertIntToString(BARREL_BOTTOM_SCORE_FIRST));
        labels_.at(1)->setString(XMLTool::convertIntToString(BARREL_BOTTOM_SCORE_SECOND));
        labels_.at(2)->setString(XMLTool::convertIntToString(BARREL_BOTTOM_SCORE_THIRD));
        labels_.at(3)->setString(XMLTool::convertIntToString(BARREL_BOTTOM_SCORE_FOURTH));
        labels_.at(4)->setString(XMLTool::convertIntToString(BARREL_BOTTOM_SCORE_FIFTH));
    }

    bool bubble_second::BarrelScoreLabelNode::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        this->loadView();
        return true;
    }
    void BarrelScoreLabelNode::loadView()
    {
        csb_node_ = cocos2d::CSLoader::createNode(BARREL_SCORE_LABEL_NODE_CSB_PATH);
        this->addChild(csb_node_);
        for (auto var : UI_NAME_BARREL_NUMBLES)
        {
            this->pushLabelWithName(var);
        }
    }
    void BarrelScoreLabelNode::setBarrelScoreLabelDisplay(bool flag)
    {
        barrel_score_display_flag_ = flag;
    }

    void BarrelScoreLabelNode::pushLabelWithName(const std::string & name)
    {
        labels_.pushBack(dynamic_cast<cocos2d::ui::TextBMFont*>(csb_node_->getChildByName(name)));
    }
}