#include "PopScoreLabelComponent.h"
#include "XMLTool.h"
#include "BubbleSecondConstant.h"

const float POP_SCORE_INITIAL_SCALE = 0.1f;  //弹出分数的初始缩放
const float POP_SCORE_SCALETO_1_TIME = 0.3f;  //第一次缩放的时间
const float POP_SCORE_SCALETO_1_NUMBLE = 0.5f;  //第一次缩放的比例
const float POP_SCORE_SCALETO_2_TIME = 0.1f;
const float POP_SCORE_SCALETO_2_NUMBLE = POP_SCORE_SCALETO_1_NUMBLE*0.8f;
const float POP_SCORE_SCALETO_3_TIME = 0.2f;
const float POP_SCORE_SCALETO_3_NUMBLE = POP_SCORE_SCALETO_1_NUMBLE*1.2f;
const float POP_SCORE_SCALETO_4_TIME = 0.2f;
const float POP_SCORE_SCALETO_4_NUMBLE = POP_SCORE_SCALETO_1_NUMBLE;
//const float POP_SCORE_SCALETO_5_TIME = 0.2f;
//const float POP_SCORE_SCALETO_5_NUMBLE = 1.2f;
const cocos2d::Vec2 POP_SCORE_ANCHORPOINT = cocos2d::Vec2(0.5f, 0.5f);
const float POP_SCORE_MOVEBY_TIME = POP_SCORE_SCALETO_1_TIME + POP_SCORE_SCALETO_2_TIME + POP_SCORE_SCALETO_3_TIME;      //移动的时间 
const float POP_LABEL_REMOVE_DURATION = 0.05f;    //标签最后一下消除的时间
const int LABEL_OPACITY = 200;
const cocos2d::Vec2 POP_SCORE_MOVEBY_VEC2 = cocos2d::Vec2(0.0f, 20.0f); //移动的距离
namespace bubble_second {
    PopScoreLabelComponent::PopScoreLabelComponent()
    {
    }


    PopScoreLabelComponent::~PopScoreLabelComponent()
    {
    }

    bool PopScoreLabelComponent::init()
    {
        if (!cocos2d::Node::init())
        {
            return false;
        }
        return true;
    }

    void PopScoreLabelComponent::popLabelWithScore(int score)
    {
        if (score_label_)
        {
            score_label_->setString(XMLTool::convertIntToString(XMLTool::convertStringToInt(score_label_->getString()) + score));
        }
        else
        {
            score_label_ = cocos2d::ui::TextBMFont::create(XMLTool::convertIntToString(score), GAME_NUMBLE_FONT_PATH);
            //score_label_->setScale(0.5f);
            score_label_->setOpacity(LABEL_OPACITY);
            this->addChild(score_label_);
            this->runPopAction();
        }
    }

    void PopScoreLabelComponent::popOnceLabelWithScore(int score)
    {
        this->popLabelWithScore(score);
        remove_flag_ = true;
    }

    void PopScoreLabelComponent::runPopAction()
    {
        score_label_->setAnchorPoint(POP_SCORE_ANCHORPOINT);
        score_label_->setScale(POP_SCORE_INITIAL_SCALE);
        cocos2d::ScaleTo* scaleto_1 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_1_TIME, POP_SCORE_SCALETO_1_NUMBLE);
        cocos2d::ScaleTo* scaleto_2 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_2_TIME, POP_SCORE_SCALETO_2_NUMBLE);
        cocos2d::ScaleTo* scaleto_3 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_3_TIME, POP_SCORE_SCALETO_3_NUMBLE);
        cocos2d::ScaleTo* scaleto_4 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_4_TIME, POP_SCORE_SCALETO_4_NUMBLE);
        //cocos2d::ScaleTo* scaleto_5 = cocos2d::ScaleTo::create(POP_SCORE_SCALETO_5_TIME, POP_SCORE_SCALETO_5_NUMBLE);
        cocos2d::MoveBy* move = cocos2d::MoveBy::create(POP_SCORE_MOVEBY_TIME, POP_SCOREWIDGET_SCORE_MOVE_VEC2);
        cocos2d::ScaleTo* scaleto_6 = cocos2d::ScaleTo::create(POP_LABEL_REMOVE_DURATION, 1.0f);
        cocos2d::FadeOut* fade = cocos2d::FadeOut::create(POP_LABEL_REMOVE_DURATION);
        cocos2d::Sequence* seq_1 = cocos2d::Sequence::create(move, cocos2d::Spawn::createWithTwoActions(scaleto_6, fade), cocos2d::CallFunc::create([=]() {
            score_label_->removeFromParent();
            score_label_ = nullptr;
            if (remove_flag_)
            {
                this->removeFromParent();
            }
        }), NULL);
        cocos2d::Sequence* seq_2 = cocos2d::Sequence::create(scaleto_1, scaleto_2, scaleto_3, scaleto_4, NULL);
        cocos2d::Spawn* spawn = cocos2d::Spawn::createWithTwoActions(seq_1, seq_2);
        score_label_->runAction(spawn);
    }
}