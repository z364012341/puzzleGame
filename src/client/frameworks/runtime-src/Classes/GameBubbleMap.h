//*******************************************************************************
//������   : GameBubbleMap
//����     : <��Ϸ�����еĵ�ͼ����>
//-------------------------------------------------------------------------------
//��ע     :
//          
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_BUBBLE_MAP_H_
#define _GAME_BUBBLE_MAP_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "GameBubbleMapImple.h"
namespace bubble_second {
    typedef bool Empty;
    class GameBubbleMap : public cocos2d::Ref
    {
    public:
        CREATE_FUNC(GameBubbleMap);
        ~GameBubbleMap();
        //void initWithStage(const std::string& stage_str);
    public:
        //��������С��
        void disposeContactBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        //������������
        BubbleVector disposeContactLightningBubble(const cocos2d::Vec2& contact_index);
        //���������ڶ�
        //void disposeContactBlackHoleBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        void disposeContactBlackHoleBubble(BaseBubble* flying_bubble, BaseBubble* blackhole_bubble);
        //��������c4С��
        BubbleVector disposeContactBombBombBubble(const cocos2d::Vec2& contact_index);
        //����buff���ݵ���
        void disposeBuffBubbleDown(BaseBubble* bubble);
        //����������
        void disposeDarkCloudBubble(const cocos2d::Vec2& contact_index);
        //����ʹ�ò���ը��
        BubbleVector disposeColorBombBubble(const cocos2d::Vec2& colorbomb_index);
        //����ʹ�õ�����
        void disposeUsedPropertyBubble(BaseBubble* property_bubble, const cocos2d::Vec2& contact_index);
        //����ը��Ȧը��
        BubbleVector disposeBombPropertyBubble(const cocos2d::Vec2& bomb_index);
        //�������ݵ�����
        void checkAirBubbles();
        //��������map��λ�õ���
        void adjustGameScenePosition();
        //������Ļ�ڵ�С��
        void findBubblesInVisibleSize();
        //����ʹ��Сľ��
        void disposeUseWoodenHammer(BaseBubble* bubble);
        //����ʹ�÷���
        void disposeUseStaves(BaseBubble* bubble);
        void disposeStavesSelectBubble(BaseBubble* bubble);
        //�����������淨��ʤ������
        void disposeCompletedTaskNumble();
        //���عؿ���Ϣ
        void loadStageDataWithNumble(int numble);
        //ʤ��
        void disposeGameVictory();
        //������Ϸ���
        void disposeGameDefeat();
        //����糵תתС�������߽�
        void disposeWindmillBubbleContactBorder(BaseBubble* bubble);
        //����+3�������ݵĵ���
        void disposeUsedAddSpecialBubbleProps();
        //������������С��
        void disposePhysicsCaseMinYCenterBubble(BaseBubble* contact_bubble);
        void disposeMinYCenterBubble();
    private:
        GameBubbleMap();
        bool init();
        void runBubbleEffect(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        void eliminateBubbles(BubbleVector vector, BaseBubble* prepare_bubble = nullptr, float delay_time = 0.0f);
        //�������ݵ�ʱ������remove�Ĳ���
        void disposeEliminateHandle(BubbleVector* same_bubbles, float delay_time);
        //ȥ�������ﲻ�ܱ���������������
        void eraseBubbleCanntEliminateByProperty(BubbleVector* same_bubbles);
        //�ַ��Զ����¼�
        void dispatchCustomEvent(const std::string& eventName, void* userData = nullptr);
        //����buff���С��
        Empty disposeAroundBuffBubble(const cocos2d::Vec2& cling_index);
        BubbleVector disposeBuffBubble(BubbleVector vector);
        //����ʺ�����
        Empty disposeRainbowSealBubble(BaseBubble* prepare_bubble);
        //�ɷ������������¼�
        void dispatchAddEliminateComboEvent(cocos2d::Vec2 prepare_point);
        //�жϹ�������������
        bool canEliminate(const BubbleVector& vector);
        //void setStageType(const StageType& type);
        //StageType getStageType();
        //bool isWindmillStage();
        void disposePreclingBubble(BaseBubble* prepare_bubble, BaseBubble* precling_bubble);
        void disposeClingBubble(BaseBubble* prepare_bubble, BaseBubble* cling_bubble);
        //�����糵תתת
        void disposeWindmillRotation(BaseBubble* prepare_bubble);
        //����ճ����ȥ֮����û�вʺ��ӡ����buff����֮���
        void disposeAfterClinging(BaseBubble* prepare_after_cling_bubble);
        //������Ļ��С��
        BubbleVector getBubbleInVisibleSize();
    private:
        GameBubbleMapImple* game_bubble_map_impl_;
        std::map<BubbleType, std::function<BubbleVector(cocos2d::Vec2)>> type_to_disposed_;
        std::map<StageType, std::function<bool()>> type_to_complete_handle_;
    };
}
#endif //_GAME_BUBBLE_MAP_H_