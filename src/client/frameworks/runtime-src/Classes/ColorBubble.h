//*******************************************************************************
//������   : ColorBubble
//����     : <��ͨ�Ĳ�ɫ������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _COLOR_BUBBLE_H_
#define _COLOR_BUBBLE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
namespace bubble_second {
    class DarkCloudBubble;
    class BubbleReflectionPointComponent;
    class ColorBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(ColorBubble);
        static ColorBubble* createWithType(int type, int cloud)
        {
            ColorBubble *pRet = new(std::nothrow) ColorBubble();
            if (pRet && pRet->initWithTypeAndCloud(type, cloud))
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
        void onEnter() override;
        void onExit() override;
    public:
        //����ײ������
        //void runBubbleEffect(const std::string& name, const cocos2d::Vec2& point);
        ////����ײ����Ч�ķ���
        //cocos2d::Vec2 getEffectDistance(const cocos2d::Vec2& point, float distance);
        //�����Ϊ����С��ĸ���
        virtual void addBubblePrepareBody();
        void addBubbleStaticBody() override;
        //����С��
        void shoot();
        //����С������Զ����¼�
        virtual void dispatchEventAfterShooted();
        void bubbleEliminate(int combo) override;
        bool isDarkCloudBubble();
        void destroyDarkCloud();
        //��������������Ч
        void playEliminateEffect();
        //ʤ��������
        void shootAfterVictory();
        //�ӳٲ���ײ
        void delayNotCollision();
        //��������������
        void changeRandomSpecialBubble(const cocos2d::Vec2& point, StageType stage_type);
		//��������
		void playStanbyAnimation();
		void stopStanbyAnimation();
		//���÷������
		void setShootPoints(const cocos2d::Vec2& touch_location);
        //����Ͱ�ײ�
        void contactBarrelBottom();
        //��������
        void bubbleFlash();
        void removeBubbleFlash();
        //��ȡ�ٶ�����
        cocos2d::Vec2 getSpeedNormalized();
        cocos2d::Vec2 getBubbleSpeed();
        BubbleType getBubbleType() override;
    protected:
        ColorBubble();
        bool initWithTypeAndCloud(int type, int cloud = kBubbleNoCloud);
        virtual ~ColorBubble();
        //�ӿ��е���
		void dispatchCustomAddAirBubbleNumbleEvent();
        void downFromAir() override;
    private:
        bool init();
        bool initWithType(int type);
        void initHandleEffect();
        void runPreBubbleContactEffect(const cocos2d::Vec2& contact_point);
        //��Ӷ�̬����, Ϊ��ʹС��ӿ��е���
        virtual void addBubbleDynamicBody() override;
        //���ݵ����λ�û�ȡ����ĳ���
        cocos2d::Vec2 getImpulseByTouchlocation(cocos2d::Vec2 touch_location);
    private:
        DarkCloudBubble* cloud_bubble_;
        cocos2d::Vec2 speed_normalized_;
		//cocos2d::Vec2 shoot_impulse_;
        //cocos2d::Vec2 initial_position_;
        cocos2d::EventListenerCustom* listener_ = nullptr;
        cocos2d::Sprite* bubble_flash_ = nullptr;
        BubbleReflectionPointComponent* reflection_point_component_ = nullptr;
        //std::vector<cocos2d::Vec2> points_;
    };
}
#endif //_COLOR_BUBBLE_H_