//*******************************************************************************
//������   : ScoreWidget
//����     : <�÷ֹҼ�.,. ��������Ů�������֩����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _SCORE_WIDGET_H_
#define _SCORE_WIDGET_H_
//#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class PopScoreLabelComponent;
    class GameNoneBubbleDownAnimationComponent;
    class ScoreWidget : public cocos2d::Node
    {
    public:
        static ScoreWidget* createWithType(const ScoreWidgetType& type)
        {
            ScoreWidget *pRet = new(std::nothrow) ScoreWidget();
            if (pRet && pRet->initWithType(type))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
        ~ScoreWidget();
    public:
        void contactOnce();
    public:
        void addPhysicsBody();
        void removeScoreWidget();
        //�����Ҽ�
        void updateScoreWidgetType();
        ScoreWidgetType getType();
        void addOneCombo();
        void comboClear();
        //��������
        void runEnterAction();
        //��һ�εĽ�������
        void runFirstEnterActioin();
        //���ù���ַ����Լ���λ��
        void setSelfPosition(const cocos2d::Vec2& point);
        cocos2d::Vec2 getSelfPosition();
    private:
        ScoreWidget();
        bool initWithType(const ScoreWidgetType& type);
        //�������
        void addAnimationComponent();
        void initPopScoreLabel();
        void setType(const ScoreWidgetType& type);
        //��ȡײ�����ӵķ���
        int getContactScore();
        void turnOffCombo(float);
        //������ǩ
        //cocos2d::LabelAtlas* getPopScoreLabel();
        //void setPopScoreLabel(cocos2d::LabelAtlas* label);
        //ײ����Ч
        void playContactAnimation(int score);
        //��������
        void playStandbyAnimation();
        //��Ӷ���
        void addArmature();
        //���ŷ��ж���
        void playFlyingAnimation(float duration);
        //���·�����ǩ
        //void updatePopScoreLabel(int score);
        //�Ƿ��ڲ���ײ������
        bool canPlayingContactAnimation();
        void setPlayContactAnimationEnabled(bool flag);
    private:
        ScoreWidgetType type_;
        bool action_flag_ = true;
        //std::map<ScoreWidgetType, std::string> type_to_path_;
        //std::map<ScoreWidgetType, std::string> type_to_armature_name_;
        std::map<ScoreWidgetType, ScoreWidgetType> type_update_to_type_;
        std::map<ScoreWidgetType, int> type_to_score_;
        int widget_combo_;
        bool combo_flag_;
        //cocos2d::LabelAtlas* pop_score_label_;
        cocos2d::Vec2 self_position_;
        cocostudio::Armature* armature_;
        PopScoreLabelComponent* label_component_ = nullptr;
        GameNoneBubbleDownAnimationComponent* none_bubble_component_ = nullptr;
    };
}
#endif //_SCORE_WIDGET_H_