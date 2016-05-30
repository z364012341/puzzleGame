//*******************************************************************************
//������   : GameScene
//����     : <��Ϸ��ս������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "ui\UITextAtlas.h"
#include "ui\UITextBMFont.h"
#include "ui\UIButton.h"
#include "StageData.h"
namespace bubble_second {
    class BaseProperty;
    class BaseWeapon;
    class BubbleMainSightingDevice;
    class GameCharacter;
    class ScoreProgressMenu;
    class BarrelScoreLabelNode;
    //struct StageData
    //{
    //    int cell_numble = 0;
    //    int level_numble = 0;
    //};
    class GameScene : public cocos2d::Layer
    {
    public:
        static cocos2d::Scene* createScene(int cell_numble, int numble);
        static GameScene* createWithStageNumble(StageData stage_data);
        bool initWithStageNumble(StageData stage_data);
        GameScene();
        ~GameScene();
    public:
		void updateStart(float delta);
		void update(float delta) override;
        void onEnter() override;
        void onExit() override;
    public:
        //map�е�С������ת����cabnode�е�����
        cocos2d::Vec2 convertMapToCsbSpace(const cocos2d::Vec2& point);
        //��csb������ת��map��
        cocos2d::Vec2 convertCsbToMapSpace(const cocos2d::Vec2& point);
        //��ȡ����̨
        cocos2d::Node* getGunsight();
        //��ȡС��
        cocos2d::Node* getSecondBubbleStoreNode();
        int getPresentStageNumble();
        void setPresentStageData(StageData numble);
        int getPresentStageCellNumble();
        StageData getPresentStageData();
        //��Ϸ��ͣ��ʼ
        void gamePause();
        void gameResume();
		//��ȡ׼��С��ķ���λ��
		cocos2d::Vec2 getPrepareBubbleOrigin();
        //��ȡmap��ߵ�
        float getMapMaxPositionY();
        //���߼��
        //void physicsRayCast(cocos2d::PhysicsRayCastCallbackFunc func, const cocos2d::Vec2& point1, const cocos2d::Vec2& point2);
    private:
        //��ȡ����̨��λ��
        cocos2d::Vec2 getGunsightPosition();
        //��ʼ����ͼ����,�����ǹؿ�
        void initBubbleMap(int stage_numble);
        //��ʼ���ؼ��㼶
        void initUIZOrder();
        //cocos2d::Node* getBarrelHeadNode();
        //��ʼ��ˮͰ
        void initBarrels();
        //�Կؼ�������Ļ�������
        void initChildren();
        //��ʼ�������ĵ÷ֹҼ�
        void initScoreWidget();
        //��ȡ������Ϣnode
        //cocos2d::Node* getTopInfoUI();
        //��ӽ�ɫ
        void initCharacter();
        //��ӱ�����
        void initHandle();
        //��ʼ��Ͱ���������ǩ��
        void initBarrelScoreLabel();
        //�������Ӷ�ʱ��
        void addStandbyTimer();
        //��ӻ���ļ���
        //void addExchangeBubbleListener();
        //�Ƴ�����ļ���
        //void removeExchangeBubbleListener();
        //������Ч�ļ�
        //void addArmatureFile();
        //void removeArmatureFile();
        //������׼��
        void addBubbleSightingDevice();
        //������ƺ͹�����
        void clearController();
        //ʤ��֮������ʣ�����
        void shootBubblesAfterVictory();
        //���汾��
        void replayGame();
        //�������ǰʹ�õĵ���
        void usedEnterProps();
        //��Ӽ����¼�
        void addKeyboardEventListener();
    private:
        //��ȡ�����ӿؼ�
        cocos2d::ui::TextBMFont* getScoreUI();
        //��ȡ����λ�õ�С���y����
        float getBubbleMinPositionY();
        //�����ͼ��������λ��
        float getAdjustMapDistance(float map_min_pos);
        //��ȡС���ͼ���µ����ľ���
        float getAdjustMapDownwardDistance(float distance);
        //��ȡС���ͼ���ϵ����ľ���
        float getAdjustMapUpwardDistance(float distance);
        //��ȡ��ͼ���ԭʼλ��
        cocos2d::Vec2 getBubbleMapOrigin();
        //��ȡ����С��
        void setPrepareColorBubble(BaseBubble* bubble);
        BaseBubble* getPrepareBubble();
        //��ȡ�ڶ�����С��
		void setSecondPrepareBubble(BaseBubble* bubble);
        BaseBubble* getSecondPrepareBubble();
        //���׼������С��
        void addPrepareBubble();
        //��ȡ�÷ֹҼ���λ��
        //cocos2d::Vec2 getScoreWidgetPosition();
        //��ȡ�ڶ�����̨λ��
        cocos2d::Vec2 getSecondBubbleStoreNodePosition();
        //ͨ�����ֻ�ȡ�����λ��
        cocos2d::Vec2 getNodePositionWithName(const std::string& child_name);
        //��ȡ��׼�豸
        BubbleMainSightingDevice* getBubbleSightingDevice();
        //��ȡ����������label
        cocos2d::ui::TextBMFont* getCompletedTaskLabel();
        //��ȡʤ��������
        cocos2d::ui::TextBMFont* getGameTaskLabel();
        //��ȡС������
        cocos2d::ui::TextBMFont* getBubbleUseCountLabel();
        //��ȡ����
        GameCharacter* getGameCharacter();
        //��ȡ����������
        ScoreProgressMenu* getScoreProgressMenu();
        //�ؿ�����
        void setStageType(StageType type);
        StageType getStageType();
    private:
        //��ӱ���
        void addGameBackground(int cell_numble);
        //���ȫ��Ͱ�Ǳ�Ե����
        void addBarrelheadsPhysicsBody();
        //��ӵ���Ͱ�Ǳ�Ե����
        void addBarrelheadPhysicsBodyWithName(const std::string& child_name);
        //���ȫ��Ͱ�ײ�
        void addBarrelBottoms();
        //��ӵ���Ͱ�ײ�
        void addBarrelBottomWithName(const std::string& child_name);
        //��ʼ����������
        void addTouchEventListener();
        //void addBubbleWithPoint(BaseBubble* bubble, cocos2d::Vec2 point);
        void addBubblePhysicsBodyToMap(BaseBubble* bubble);
        //������
        //void addClippingNode();
        //���ÿؼ��Ĳ㼶
        void setUIZOrderWithNameAndNumber(const std::string& child_name, int localZOrder);
        //��ӵڶ�����С��
        BaseBubble* addSecondPrepareBubble();
        //����׼��С��, û��λ�ú�������Ϣ��
        BaseBubble* createPrepareBubble();
        //�������ֻ�ȡ����UI�Ŀؼ�
        //cocos2d::Node* getTopUIChildWithName(const std::string& child_name);
        //����������ķ���С�����ɫ, ��С����ɫ��ʣ���С����ɫһ��
        void disposedPrepareBubbleType();
        //�����Ƿ���Ե������С��
        void addExchangeBubbleListener();
        void removeExchangeBubbleListener();
        //�����˵���С��֮���¼���Ӧ
        void haveShootPropsBubble(BaseProperty* property);
        //���õ���ͼ���Ƿ��ܵ��
        void setPropertyTouchEnabled(bool flag);
        //���ð����˵������ܵ�
        void setMenuTouchEnabled(bool flag);
        //���������
        void  recentbubbleCast();
        //�ı��������ɫ
        //void changeSwirlColor();
		//׼��С���������
		void playPrepareBubbleStanbyAction();
        //�������ݵĶ������ض������ʱ��
        float playBubblesEffects(BubbleVector bubbles);
        //����������λ��
        void setPropsWeaponPosition(const cocos2d::Vec2& point);
        //���һ���÷ֹҼ�
        void addScoreWidget(const cocos2d::Vec2& point);
        //��������Ĺ�
        void startShakeBarrel();
        void stopShakeBarrel();
        //�ı���׼����ɫ
        void changeSightingDeviceColor();
        //�����ܵ�Ŀ��������
        void updateGameTaskLabel();
        //��ͼ�ƶ���֮���func
        void doSomethingAfterFirstAdjustMap();
        //�Ƿ�ֻʣ��һ������С��
        bool isOnlyBubbleUseCount();
        //�Ƿ�����ʾͰ����ķ���
        //bool isBarrelScoreLabelDisplay();
        //void setBarrelScoreLabelDisplay(bool flag);
        //��Ͱ����ķ������в���
        //void handleBarrelScoreLabel(std::function<void(const std::string& name)> func);
        int getTotalAirBubblesNumble();
        //�Ƿ���Ҫ��ʾ
        bool isNeedNotDisplayedBarrelScoreLabel();
        //��ʾͰ�������label
        void displayBarrelScoreLabel();
        //����ʾ
        void notDisplayedBarrelScoreLabel();
        //ʤ��
        void victory();
        //ʧ��
        void defeat();
        void popDefeatBuyAlert();
        void popDefeatAlert();
        void popVictoryAlert();
        void popPauseAlert();
        //ʹ��+10��������
        void usedAddBubbleNumbleProps();
        //�Ƿ��ǵ�һ��
        bool isFirstHandle();
        void setFirstHandleFlag(bool flag);
        //��ͼ��������ģʽ
        void mapFallingBegin();
        //��ȡ����moveby
        //cocos2d::MoveBy* getMapFallingAction();
        //�ƶ���ͼ
        void moveMapWithDistance(float moveby_distance);
        //�����ƶ�����
    private:
        //����Զ����¼�����
        void addEventListenerCustom();
        void removeEventListenerCustom();
        //����С��
        void eliminateSprites(cocos2d::EventCustom* event);
        //����С��
        void spritesDownFromAir(cocos2d::EventCustom* event);
        //С��runײ����Ч
        void runBubbleContactEffect(cocos2d::EventCustom* event);
        //���С���ͼ
        void addBubbleMapUI(cocos2d::EventCustom* event);
        //��Ӷ����������ݵ���������ı�־
        void addTopEliminateBubbleLogo(cocos2d::EventCustom * event);
        //��ӷ糵��ͼ
        void addWindmillBorder(cocos2d::EventCustom*);
        void addWindmillBorderFunc(cocos2d::Size size, cocos2d::Vec2 point, int test_bitmask = BITMASK_WINDMILL_BORDER_CONTACTTEST);
        //����С��
        void clingBubble(cocos2d::EventCustom* event);
        //�糵�淨��ת
        void windmillBubbleRotation(cocos2d::EventCustom* event);
        //������������
        void addEliminateCombo(cocos2d::EventCustom*);
        //û������ʹ�ùҼ�����
        void removeTwoScoreWidget(cocos2d::EventCustom*);
        //���·�����ǩ
        void scoreTextUpdate(cocos2d::EventCustom* event);
        //��С��ҩװ�����̨
        void reloadPrepareBubble(cocos2d::EventCustom*);
        //����׼��С��
        void exchangePrepareBubble(cocos2d::EventCustom*);
        //�����Ʋ�
        void destroyBubbleDarkCloud(cocos2d::EventCustom* event);
        //������ͼ������λ��
        void adjustMapPosition(cocos2d::EventCustom* event);
        //����ĵ�����ͼ���
        void fallAdjustMapPosition(cocos2d::EventCustom* event);
        //ʹ���˲������
        void useBubbleBombProps(cocos2d::EventCustom* event);
        //ȡ��ʹ�ò��������ը������
        void cancelUsedBubbleBombProps(cocos2d::EventCustom* event);
        //ʹ�������֮��ص�
        void haveUsedProps(cocos2d::EventCustom* event);
        //��ӵ���ѡ�����
        void addPropsSelectAlert(cocos2d::EventCustom* event);
        //�Ƴ�����ѡ�����
        void removePropsSelectAlert(cocos2d::EventCustom*);
        //ѡ��С��
        void selectBubble(cocos2d::EventCustom* event);
        //����Ļ�е�С��Ӵ����¼�
        void addListenerForBubblesInVisibleSize(cocos2d::EventCustom* event);
        //ɾ��С��Ĵ����¼�
        void removeListenerForBubblesInVisibleSize();
        //ȷ��ʹ��ѡ��ϵ����
        void useSelectProperties(cocos2d::EventCustom*);
        //�жϼ���С���Ƿ���ȷ
        void recentlyBubbleCast(cocos2d::EventCustom* event);
        //��ת��̨����׼��
        void rotateSightingDevice(cocos2d::EventCustom* event);
        //������������Ч
        void playBigEliminateEffect(cocos2d::EventCustom*);
        //ֹͣ6��������Ч
        void stopBigEliminateEffect(cocos2d::EventCustom*);
        //��������ɵ�Ŀ��label                                 
        void updateCompletedTaskLabel(cocos2d::EventCustom*);
        //�ж��Ƿ�ʤ��
        void estimateVictory();
        //����С������label
        void updateBubbleUseCountLabel(cocos2d::EventCustom*);
        //����1��׹��������
        void addOneAirBubblesNumble(cocos2d::EventCustom*);
        //��һ
        void cutOneAirBubblesNumble(cocos2d::EventCustom*);
        //�ҵ�3����ͨС���������������
        void findThreeBubble(cocos2d::EventCustom* event);
        //�������书��
        void addFallBorder(cocos2d::EventCustom*);
        //����fallģʽ�Ķ���
        void fallStageHandle();
        void setFallStageFlag(bool flag);
        bool isFallStage();
        //��������÷�label
        void addEliminateScoreLabel(cocos2d::EventCustom* event);
        //
        //void mutipleSealBubbleFly(cocos2d::EventCustom* event);
    private:
        //��ֹ���崩͸
        //void updateStart(float delta);
        //void update(float delta);
        cocos2d::PhysicsWorld* getScenePhysicsWorld();
        //������������
        void setPhysicsWorldBody();
        //void addWindmillPhysicsJoints(BaseBubble* bubble);
    private:
        cocos2d::Node* edge_shape_node_;
        cocos2d::Node* csb_node_;
        cocos2d::Node* bubble_map_node_;
        BaseBubble* property_bubble_;
        std::map<std::string, std::function<void(BaseProperty* property)>> props_name_to_handle_;
        std::map<std::string, BubbleType> props_name_to_color_;
        BaseProperty* color_bomb_property_;
        BaseProperty* bomb_bomb_property_;
        BaseProperty* wooden_hammer_property_;
        BaseProperty* staves_property_;
        //std::map<BubbleType, std::string> bubblecolor_to_swirl_;
        BaseWeapon* props_weapon_ = nullptr;
        bool first_flag_;
        //bool barrel_score_display_flag_;
        GameCharacter* game_character_;
        //int present_stage_numble_ = 0;
        StageData stage_data_;
        int total_air_bubbles_numble_ = 0;
        StageType stage_type_;
        bool is_fall_stage_ = false;
        bool add_props_flag = true;
        bool first_victory_flag_ = true;
		cocos2d::ui::Button* pause_menu_ = nullptr;
        BaseBubble* prepare_bubble_ = nullptr;
		BaseBubble* second_bubble_ = nullptr;
		ScoreProgressMenu* score_progress_ = nullptr;
        BarrelScoreLabelNode* barrel_score_node_ = nullptr;
        cocos2d::Vector<cocos2d::Node*> pause_nodes_;
        BubbleMainSightingDevice* main_sighting_device_ = nullptr;
    };
}
#endif //_GAME_SCENE_H_
