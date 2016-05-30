//*******************************************************************************
//类名称   : GameStageSelectionScene
//功能     : <游戏的关卡选择场景>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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
        //增加关卡单元
        void addStageCell();
        //增加自定义事件
        void addEventListenerCustom();
        void removeEventListenerCustom();
        //增加鼠标事件
        void addMouseEventListener();
        //键盘事件
        void addKeyboardEventListener();
        //弹出进入alert
        void popEnterGameAlert(StageData data);
        //过关后进入下一关的接口
        void enterNextStage(StageData data);
        //设置按钮
        //void addSettingMenu();
        //拼图按钮
        void gotoPuzzleGame();
        void popSettingAlert();
        cocos2d::Node* getAlertRenderNode();
        //进入场景调整滚动视图位置
        void adjustingScrollviewPosition();
        //创建滚动内容
        //cocos2d::Layer* createScrollViewContentLayer();
		void scrollViewMoveCallback(cocos2d::Ref *pSender, cocos2d::ui::ScrollView::EventType eventType);
		//添加载具
		void addStageVehicle();
        //设置按钮回调
        void settingButtonFunc(cocos2d::Ref* target, cocos2d::ui::Widget::TouchEventType type);
        void setSettingButtonEnabled(bool enabled);
    private:
        float scrollview_bottom_height_ = 0.0f;
        cocos2d::Vector<GameStageSelectionCell*> cell_vector_;
        std::vector<cocos2d::Vec2> cell_position_vector_;
        //记录滚动条的位置
        static cocos2d::Vec2 scrollview_offset_;
        //float scale_zoom_;
        ScrollView* scrollview_ = nullptr;
        cocos2d::Node* csb_node_ = nullptr;
		GameStageVehicle* stage_vehicle_ = nullptr;
        cocostudio::Armature* setting_armature_ = nullptr;
    };
}
#endif //_GAME_STAGE_SELECTION_SCENE_H_