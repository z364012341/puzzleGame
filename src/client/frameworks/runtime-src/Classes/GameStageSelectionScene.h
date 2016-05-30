//*******************************************************************************
//������   : GameStageSelectionScene
//����     : <��Ϸ�Ĺؿ�ѡ�񳡾�>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_STAGE_SELECTION_SCENE_H_
#define _GAME_STAGE_SELECTION_SCENE_H_
#include "BubbleSecondConstant.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UIScrollView.h"
#include "ui\UIButton.h"
namespace bubble_second {
	using cocos2d::ui::ScrollView;
    class GameStageSelectionCell;
	class GameStageVehicle;
	class GameStageSelectionScene : public cocos2d::Layer
    {
    public:
        static cocos2d::Scene* createScene();
        static cocos2d::Scene* createSceneWithStageData(StageData data);
        CREATE_FUNC(GameStageSelectionScene);
        ~GameStageSelectionScene();
        //void scrollViewDidScroll(ScrollView* view);
        cocos2d::Vec2 getScorllViewOffset(int cell_numble);
        void onEnter() override;
        void onExit() override;
        //void screenShot(bool bIsSave);
    private:
        GameStageSelectionScene();
        bool init();
        void loadView();
        void layout();
        cocos2d::ui::Button* getSettingButton();
        //���ӹؿ���Ԫ
        void addStageCell();
        //�����Զ����¼�
        void addEventListenerCustom();
        void removeEventListenerCustom();
        //��������¼�
        void addMouseEventListener();
        //�����¼�
        void addKeyboardEventListener();
        //��������alert
        void popEnterGameAlert(StageData data);
        //���غ������һ�صĽӿ�
        void enterNextStage(StageData data);
        //���ð�ť
        //void addSettingMenu();
        //ƴͼ��ť
        void gotoPuzzleGame();
        void popSettingAlert();
        cocos2d::Node* getAlertRenderNode();
        //���볡������������ͼλ��
        void adjustingScrollviewPosition();
        //������������
        //cocos2d::Layer* createScrollViewContentLayer();
		void scrollViewMoveCallback(cocos2d::Ref *pSender, cocos2d::ui::ScrollView::EventType eventType);
		//����ؾ�
		void addStageVehicle();
        //���ð�ť�ص�
        void settingButtonFunc(cocos2d::Ref* target, cocos2d::ui::Widget::TouchEventType type);
        void setSettingButtonEnabled(bool enabled);
    private:
        float scrollview_bottom_height_ = 0.0f;
        cocos2d::Vector<GameStageSelectionCell*> cell_vector_;
        std::vector<cocos2d::Vec2> cell_position_vector_;
        //��¼��������λ��
        static cocos2d::Vec2 scrollview_offset_;
        //float scale_zoom_;
        ScrollView* scrollview_ = nullptr;
        cocos2d::Node* csb_node_ = nullptr;
		GameStageVehicle* stage_vehicle_ = nullptr;
        cocostudio::Armature* setting_armature_ = nullptr;
    };
}
#endif //_GAME_STAGE_SELECTION_SCENE_H_