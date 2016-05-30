//*******************************************************************************
//������   : StageSelectionMenu
//����     : <�ؿ���ѡ��ť>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAGE_SELECTION_MENU_H_
#define _STAGE_SELECTION_MENU_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameSamsung;
    enum HalfMoonSlashDirection
    {
      kLeft = -1,
      kRight = 1
    };
    class StageSelectionMenu : public cocos2d::Node
    {
    public:
        static StageSelectionMenu* create(int cell_numble, int level, const StageType& type);
        ~StageSelectionMenu();
        void turnOnBlink();
        //����ѡ��ť�ܲ��ܵ�
        void setSelectionMenuEnable(bool flag);
		bool isCurrentStage();
        //��ťԤ����
        void preUnlockStage();
        void unlockStage();
        void playUnlockStageAnimation();
    private:
        StageSelectionMenu();
        bool init(int cell_numble, int level, const StageType& type);
        void addButton(const StageType& type);
        StageData getStageData();
        //����״̬
        void setMenuState();
        void setButtonEnable(bool flag);
        void addSamsung(int start_numble);
        void addStageLabel();
        bool isButtonEnable();
        void addStageTypeTexture(const StageType& type);
        //���ߵİ���ն
        //void halfMoonSlash(const HalfMoonSlashDirection& direction);
        //���㸸��layer
        cocos2d::Node* getSelectionLayer();
        //����
        void addStandbyParticle();
        void addStandbyHaloAnimation();
    private:
        GameSamsung* samsung_ = nullptr;
        cocos2d::Sprite* button_sp_ = nullptr;
        cocos2d::Sprite* stage_type_sprite_ = nullptr;
        cocos2d::Vec2 touch_begin_position_;
        bool touch_enable_ = true;
        bool menu_enable_ = true;
        StageData stageData_;
        cocos2d::ParticleSystemQuad* pre_unlock_particle_ = nullptr;
        //int cell_numble_ = 0;
        //int level_numble_ = 0;
		//bool is_current_stage_flag_ = false;
    };
}
#endif //_STAGE_SELECTION_MENU_H_