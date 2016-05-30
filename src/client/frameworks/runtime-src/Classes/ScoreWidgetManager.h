//*******************************************************************************
//������   : ScoreWidgetManager
//����     : <��Ϸ�е÷ֹҼ�(֩��.*.)����>
//-------------------------------------------------------------------------------
//��ע     :
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _SCORE_WIDGET_MANAGER_H_
#define _SCORE_WIDGET_MANAGER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    typedef cocos2d::Vector<cocos2d::Node*> WidgetPointsSeed;
    //typedef std::map<std::string, std::map<ScoreWidgetType, std::string>> WidgetBonePathMap;
    class ScoreWidget;
    class ScoreWidgetManager
    {
    public: 
        ~ScoreWidgetManager();
        GETINSTANCE_FUNC(ScoreWidgetManager);
    public:
        ScoreWidget* getNewScoreWidget(); 
        //cocos2d::Vec2 getScoreWidgetPositionWithVector(const cocos2d::Vector<cocos2d::Node*>& vector);
        cocos2d::Vec2 getScoreWidgetPosition();
        int getScoreWidgetTotal();
        int getScoreWidgetTotalWithType(const ScoreWidgetType& type);
        //��˳���Ƴ��Ƴ�2���Ҽ�
        void removeTwoScoreWidget();
        void clear();
        //λ������
        void setWidgetPointsSeed(WidgetPointsSeed seed);
        WidgetPointsSeed getWidgetPointsSeed();
        //const WidgetBonePathMap& getWidgetBonePathMap();
        cocos2d::Color3B getWidgetColorWithType(const ScoreWidgetType type);
        //�л���������Ƥ��
        void changeScoreWidgetArmatureDisplay(cocostudio::Armature* armature, const ScoreWidgetType& type);
        //��ȡ������Ƥ����
        void readBoneDateFromFile();
        //��ȡ������
        cocostudio::Armature* getWidgetUpdateArmature(const ScoreWidgetType type);
    private:
        ScoreWidgetManager();
        //���ʱ�����
        //void addEventListenerCustom();
        //�ж�������Ƿ������ϳ��ĹҼ�����
        bool isNearbyExistence(const cocos2d::Vec2& point);
        bool isNearByBorder(const cocos2d::Vec2& point);

        void addWidgetTotal();
        void cutWidgetTotal();
    private:
        std::map<ScoreWidgetType, cocos2d::Vector<ScoreWidget*>> score_widget_map_;
        std::vector<ScoreWidgetType> widget_update_sequence_;
        std::vector<ScoreWidgetType> widget_remove_sequence_;
        int widget_total_;
        //���������ӵ�ʲô�����֩��
        //ScoreWidgetType ComboToScoreWidgetType[6] =
        //{
        //    kScoreWidgetBlue,
        //    kScoreWidgetBlue,
        //    kScoreWidgetBlue,
        //    kScoreWidgetPink,
        //    kScoreWidgetPink,
        //    kScoreWidgetGreen
        //};
        std::map<int, ScoreWidgetType> combo_to_type_;
        std::map<ScoreWidgetType, std::string> type_to_key_;
        //λ������
        WidgetPointsSeed widget_points_seed_;

        //cocos2d::ValueMap bee_bone_data_;
        cocos2d::ValueMap score_widget_bone_data_;
        //WidgetBonePathMap bonename_to_map_;
        //std::map<ScoreWidgetType, cocos2d::Color3B> type_to_color_;
    };
}
#endif //_SCORE_WIDGET_MANAGER_H_