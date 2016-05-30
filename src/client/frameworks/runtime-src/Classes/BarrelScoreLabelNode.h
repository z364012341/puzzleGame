//*******************************************************************************
//������   : BarrelScoreLabelNode
//����     : <Ͱ�ϵķ�����ǩnode>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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
        //�Ƿ�����ʾͰ����ķ���
        bool isBarrelScoreLabelDisplay();
        //Ͱ�ķ�������
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