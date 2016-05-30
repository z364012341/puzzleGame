//*******************************************************************************
//������   : StageTypeLogo
//����     : <�ؿ�����logo>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAGE_TYPE_LOGO_H_
#define _STAGE_TYPE_LOGO_H_
//#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class StageTypeLogo : public cocos2d::Node
    {
    public:
        static StageTypeLogo* create(const StageType& type);
        ~StageTypeLogo();
        void onEnter() override;
        void onExit() override;
    private:
        StageTypeLogo();
        bool initWithType(const StageType& type);
        void completeTaskBubbleFly(cocos2d::EventCustom* event);
        void bubbleNodeFlyFlyFly(cocos2d::Node* node, bool update_immediately);
        void playLogoFlash();
    private:
        cocos2d::Sprite* type_sprite_ = nullptr;
        StageType stage_type_;
    };
}
#endif //_STAGE_TYPE_LOGO_H_