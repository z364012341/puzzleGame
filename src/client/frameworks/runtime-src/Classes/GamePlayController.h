//*******************************************************************************
//������   : GamePlayController
//����     : <��Ϸ������������, ������ײ�ʹ�������>
//-------------------------------------------------------------------------------
//��ע     : <����������,������ײ�ʹ����Ļص�>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_PLAY_CONTROLLER_H_
#define _GAME_PLAY_CONTROLLER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameBubbleMap;
    class BubbleColorPicker;
    class BaseBubble;
    class GameScene;
    typedef BaseBubble WeaponBox;  
    typedef int TouchDirection;
    class GamePlayController //: public cocos2d::Layer
    {
    public:
        ~GamePlayController();
        GETINSTANCE_FUNC(GamePlayController);
    public:
        //gamescene�ĵ����Ӧ
        bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);// final;
        void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);// final;
        void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);// final;
        //��ײ
        bool onContactBegin(cocos2d::PhysicsContact& contact);
        void onContactSeparate(cocos2d::PhysicsContact& contact);
        //���ڽ�������С��ĵ����Ӧ
        bool exchangePrepareBubbleOnTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
        void exchangePrepareBubbleOnTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
        void exchangePrepareBubbleOnTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
        ////���������ɫ�ͳ����ͼƬ
        //bool touchToChangeTexture(cocos2d::Touch *touch, cocos2d::Event *event);
        //void touchToMoveCharecter(cocos2d::Touch *touch, cocos2d::Event *event);
        //������ߵ���Ӧ
        bool touchPropertyBegan(cocos2d::Touch *touch, cocos2d::Event *event);
        void touchPropertyMoved(cocos2d::Touch *touch, cocos2d::Event *event);
        void touchPropertyEnded(cocos2d::Touch *touch, cocos2d::Event *event);
        //���ѡ��С��
        bool touchSelectBubble(cocos2d::Touch *touch, cocos2d::Event *event);
    public://��ʼ����صĳ�Ա����
        //����׼�������С��
        void setPrepareBubble(BaseBubble* color_bubble);
        void clearPrepareBubble();
        BaseBubble* getPrepareBubble();
        //���عؿ���ͼ����
        void loadStageMap(int numble);
        //�����Ƿ��ܵ������С��
        void setBubbleShootEnabled(bool flag);
        //��ȡ�Ƿ��ܵ������С��
        bool getBubbleShootEnabled();
        //���ȡɫ
        void addPrepareColor(BubbleType color);
        //����һ��ȡɫ
        void subtractPrepareColor(BubbleType color);
        //ȡɫ
        BubbleType getBubbleColorFromPicker();
        //BubbleType getBubbleColorInRange();
        //������ɫ��Χ
        void setBubbleColorRange();
        //����С�����������ɫ
        void prepareBubbleChangeType(BaseBubble* pre_second_bubble);
        //�����������ݵĵ���
        void disposeBuffBubbleDown(BaseBubble* bubble);
        //������Χ��������
        void disposeDarkCloudBubble(const cocos2d::Vec2& contact_index);
        //�Կ������ݽ��м��
        void checkAirBubbles();
        //������ͼ���
        void adjustGameScenePosition();
        //�����Ļ�ڵ�����
        void findBubblesInVisibleSize();
        //������ѡ�е�ͬɫС��
        void disposeSelectSameBubbles();
        //����ʹ�õ��ִ�����
        void disposeUseWoodenHammer();
        //��������ѡ���С��
        void setSelectBubble(WeaponBox* bubble);
        //����ʹ��ħ����
        void disposeUseStaves();
        //��ת��׼��
        void disposeSightingDevice(const cocos2d::Vec2& touch_location, bool touch_began = false);
        //����ʤ��
        void disposeVictory(); 
        //����ʧ��
        void disposeDefeat();
        //ʹ�ü��������ݵĵ���
        void usedAddSpecialBubbleProps();
        //��Ҫ��׼����
        bool needExchangePrepareBubble(bool exchange_flag);

        void setTouchDirection(TouchDirection direction);
        TouchDirection getTouchDirection();
		//���ô���
        void setGameSceneDelegate(GameScene* scene_delegate);
		//����С��
		void shootPrepareBubble();
        //��ȡ��������λ��
        float getPlayAreaMaxY();
        //��ȡ�����׼ȷλ��
        cocos2d::Vec2 getShootingInitialPosition();
        //���߼��
        //void gamePhysicsRayCast(cocos2d::PhysicsRayCastCallbackFunc func, const cocos2d::Vec2 & point1, const cocos2d::Vec2 & point2);
        //��������С��
        void disposeMinYCenterBubble();
        //�ж�ʧ��
        void disposeGameDefeat();
    private:
        //��׼����С�����ȥ
		void dispatchShootEvent(const cocos2d::Vec2& touch_location);
        //���ݷ����ȡ���������λ��
        cocos2d::Vec2 getRealTouchPoint(const cocos2d::Vec2& touch_location);
        //��������Ĳ�������������node
        cocos2d::Vector<cocos2d::Node*> separateContactNodeWithName(const std::string& name, 
            cocos2d::Node* node_a, cocos2d::Node* node_b);
        cocos2d::Vector<cocos2d::Node*> separateContactNodeWithTag(int tag,
            cocos2d::Node* node_a, cocos2d::Node* node_b);
        //�ж��Ƿ��ý���С���ҿ��Է���С��
        bool canShootingBubble(const cocos2d::Vec2& touch_location);
        //�ж����Ƿ���Է���
        bool isShootBubbleEnable(const cocos2d::Vec2& touch_location);
        //�ж��Ƿ��ڷ�������
        bool isInShootArea(const cocos2d::Vec2& touch_location);
        //ת��touch������
        cocos2d::Vec2 convertGLToNodeSpace(const cocos2d::Vec2& touch_location, cocos2d::Node* node);
        //�ж��Ƿ��������target
        bool touchOnIt(const cocos2d::Vec2& point, cocos2d::Node* sprite);
        //��ȡ������ĽǶ�
        //float getAngleWithVectors(const cocos2d::Vec2& point_1, const cocos2d::Vec2& point_2);
        //��ȡһ���������С��ĽǶ�
        float getPrepareBubbleAngle(const cocos2d::Vec2& point);
        //��ȡ��׼������ת�Ƕ�
        float getTouchAngleForPrepareBubble(const cocos2d::Vec2& touch_location);
        bool isTouchUnderside();
        //���÷���
        void setTouchDirection(const cocos2d::Vec2& touch_point);

        //������׼����
        void turnOnSightingDevice(cocos2d::Vec2 point);
        void turnOffSightingDevice();
    private://��ײ��صĳ�Ա����
        GamePlayController();
        void initHandleMap();
        typedef void(GamePlayController::*contactHandle)(cocos2d::Node*, cocos2d::Node*);
        void addContactHandleWithTwoNames(contactHandle handle, const std::string& name_1, const std::string& name_2);
        //������ɫ����ͨС��
        void disposeContactWithColorBubble(BaseBubble* flying_bubble, BaseBubble* contacted_bubble);
        //������ײ��С����¼�
        void disposeContactWithBubble(cocos2d::Node* flying_node, cocos2d::Node* contact_node);
        //������ײ��Ͱ�׵��¼�
        void disposeContactWithBarrelBottom(cocos2d::Node* barrel_node, cocos2d::Node* bubble_node);
        //���������÷ֹҼ�
        void disposeContactWithScoreWidget(cocos2d::Node* widget_node, cocos2d::Node* bubble_node);
        //������������С��
        //void disposeContactWithLightningBubble(BaseBubble* flying_node, BaseBubble* lightning_node);
        //���������ڶ�С��
        void disposeContactWithBlackHoleBubble(BaseBubble* flying_node, BaseBubble* lightning_node);
        //����ʹ�ò�ɫ��ըС��
        void disposeUsingPropertyBubble(BaseBubble* flying_node, BaseBubble* contact_node);
        //��������������
        void disposeBubbleCast(cocos2d::Node* cast_node, cocos2d::Node* bubble_node);
        //�Ƿ���Խ���С��
        bool exchangePrepareEnabled(const cocos2d::Vec2& touch_point/*, cocos2d::Node* event_node*/);
        bool touchInGunsight(const cocos2d::Vec2& touch_point);
        bool touchInGrass(const cocos2d::Vec2& touch_point);
        //������ײ��׼��
        void disposeSightingPointContactBubble(cocos2d::Node* sight_node, cocos2d::Node* other_node);
        //void disposeSightingPointContactBorder(cocos2d::Node* sight_node, cocos2d::Node* other_node);
        //����糵תתС�������߽�
        void disposeWindmillBubbleBorder(cocos2d::Node* border_node, cocos2d::Node* other_node);
        void disposeContactWindmillBorder(cocos2d::Node* node_1, cocos2d::Node* node_2);
        //��������ģʽ�����߽�
        void disposeFallBubbleBorder(cocos2d::Node* border_node, cocos2d::Node* other_node);
    private:
        enum Direction
        {
            kUnderside = -1,
            kUpside = 1
        };
        GameBubbleMap* bubble_map_ = nullptr;
        BaseBubble* prepare_bubble_;
        BubbleColorPicker* color_picker_ = nullptr;
        typedef void(GamePlayController::*pHandle)(BaseBubble*, BaseBubble*);
        std::map<BubbleType, pHandle> key_to_handle_map_;
        bool shoot_bubble_enabled_;
        //std::map<std::string, float> name_to_exchange_distance_;
        std::map<BubbleType, pHandle> props_to_handle_;
        WeaponBox* select_bubble_;
        TouchDirection direction_;
        std::map<std::string, std::map<std::string, std::function<void(cocos2d::Node*, cocos2d::Node*)>>> name_to_contact_handle_;
        GameScene* game_scene_delegate_ = nullptr;
    };
}
#endif //_GAME_PLAY_CONTROLLER_H_