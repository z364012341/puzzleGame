//*******************************************************************************
//类名称   : BarrelScoreLabelNode
//功能     : <桶上的分数标签node>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BARREL_SCORE_LABEL_NODE_H_
#define _BARREL_SCORE_LABEL_NODE_H_
#include "cocos2d.h"
#include "ui/UITextBMFont.h"
namespace bubble_second {
    class BarrelScoreLabelNode : public cocos2d::Node
    {
    public:
        CREATE_FUNC(BarrelScoreLabelNode);
        ~BarrelScoreLabelNode();
        void displayBarrelScoreLabel();
        void notDisplayedBarrelScoreLabel();
        //是否在显示桶上面的分数
        bool isBarrelScoreLabelDisplay();
        //桶的分数翻倍
        void doubleBarrelScoreLabel();
        void SingleBarrelScoreLabel();
    private:
        BarrelScoreLabelNode();
        bool init();
        void loadView();
        void setBarrelScoreLabelDisplay(bool flag);
        void pushLabelWithName(const std::string& name);
    private:
        cocos2d::Node* csb_node_ = nullptr;
        bool barrel_score_display_flag_ = false;
        cocos2d::Vector<cocos2d::ui::TextBMFont*> labels_;
    };
}
#endif //_BARREL_SCORE_LABEL_NODE_H_