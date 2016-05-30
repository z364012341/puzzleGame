//*******************************************************************************
//�ļ���         : <BarrelBottom.h>
//�ļ�ʵ�ֹ���  : <�·�ˮͰui��Ͱ��node>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//�޸ļ�¼ :
//�� ��        �汾     �޸���              �޸�����
//2015/09/15   1.0     <�����>            <�����>
//*******************************************************************************
#ifndef _BARREL_BOTTOM_H_
#define _BARREL_BOTTOM_H_
#include "cocostudio\CocoStudio.h"
//#include "ui\UITextBMFont.h"
namespace bubble_second {
    class PopScoreLabelComponent;
    typedef bool EffectEnabled;
    class BarrelBottom : public cocos2d::Node
    {
    public:      
        static BarrelBottom* createWithName(const std::string& name)
        {
            BarrelBottom *pRet = new(std::nothrow) BarrelBottom();
            if (pRet && pRet->initScoreWithName(name))
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
    public:
        void contactOnce();
    private:
        void onEnter() override;
        //void onExit() override;
        BarrelBottom();
        virtual ~BarrelBottom();
        bool initScoreWithName(const std::string& name);
        void initPhysicsBody();
        void initScore(const std::string& name);
        void initPopLabelComponent();
        //void initScoreLabel();
        //����С��ײ������Ч
        void playEffect();
        //���Ŵ�����Ч
        //void playStandbyEffect();
        //��ʼ����Ч���ʱ��
        void initialStacdbyEffectTime();
        void setStacdbyEffectTime(int time);
    private:
        int score_ = 0.0f;
        int double_score_ = 0.0f;
        int initial_score_ = 0.0f;
        EffectEnabled effect_flag_;
        int standby_effect_delaytime_max_;
       //cocos2d::ui::TextBMFont* score_label_ = nullptr;
        PopScoreLabelComponent* label_component_ = nullptr;
        std::string pop_score_particle_path_ = "";
    };
}
#endif //_BARREL_BOTTOM_H_