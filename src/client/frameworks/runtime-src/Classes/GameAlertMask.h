//*******************************************************************************
//������   : EnterGameAlert
//����     : <������Ϸ����ǰ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_ALERT_MASK_H_
#define _GAME_ALERT_MASK_H_
#include "BubbleSecondConstant.h"
#include "ui\UIButton.h"
namespace bubble_second {
    class GameAlertMask : public cocos2d::Node
    {
    public:
        CREATE_FUNC(GameAlertMask);
        static GameAlertMask* createTransparentMask();
        ~GameAlertMask();
        //cocos2d::LayerColor* getBackgroundLayer();
        void backgroundFadeOut(float duration, cocos2d::CallFunc* func = nullptr);
    private:
        GameAlertMask();
        bool init();
        bool initTransparentMask();
        void addMaskMenu();
        void addColorLayer();
    private:
        cocos2d::LayerColor* layer_ = nullptr;
    };
}
#endif //_GAME_ALERT_MASK_H_
