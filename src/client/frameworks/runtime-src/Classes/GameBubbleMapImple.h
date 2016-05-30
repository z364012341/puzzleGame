//*******************************************************************************
//������   : GameBubbleMapImple
//����     : <��Ϸ�����еĵ�ͼ��������������>
//-------------------------------------------------------------------------------
//��ע     : <������������Լ���Ļ�е�λ��,����11��,˫��10����>
//           <���С���Ѱ��ͬɫС��������ͼ,>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_BUBBLE_MAP_IMPLEMENTATION_H_
#define _GAME_BUBBLE_MAP_IMPLEMENTATION_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "StageDataModule.h"
namespace bubble_second {
    //typedef std::map<int, cocos2d::Map<int, BaseBubble*>> BubbleSpriteMap;
    //typedef cocos2d::Vector<BaseBubble*> BubbleVector;
    //typedef std::map<std::string, BubbleVector> BubbleVectorMap;
    class ColorBubble;
    class BubbleColorRender;
    class GameBubbleMapImple
    {
    public:
        GameBubbleMapImple();
        ~GameBubbleMapImple();
    public:
        //��ȡ��Χ��������������
        static BubbleIndexVector getAroundIndexWithIndexWithoutCondition(const cocos2d::Vec2& index);
        //���ݹؿ�������ʼ����������,������Ҫ����string����
        BubbleSpriteMap initBubbleSpriteVetctor(BubbleColorRender* render, const BubblesData& stage_info, const StageType& stage_type);
        //��ײ���ȡ��ɫ��ͬ��С��, �����Ǹ��ź�ķ���С�������
        BubbleVector getSametypeBubbleWithIndex(const cocos2d::Vec2& index);
        //���ݴ����vector������bubble_sprite_map_�е�С��
        void removeSpriteFromeMap(const BubbleVector& vector);
        //����������ɾ��bubble_sprite_map_
        void removeSpriteFromeMapWithIndex(const cocos2d::Vec2& index);
        //��С��ճ����ȥ
        BaseBubble* clingBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        BaseBubble* preclingBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        //��ȡ��Ҫ����ײ����Ч��С��
        BubbleVectorMap getEffectBubbles(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index);
        //���������������С��
        BubbleVector disposeAirBubbleAfterEliminate();
        //��ȡ�����x���������ڵ���һ��С��, 
        BubbleVector getSameYBubblesWithIndex(const cocos2d::Vec2& index);
        //��ȡ�����������Χ����������
        cocos2d::Vector<ColorBubble*> getAroundDarkCloudBubbleWithIndex(const cocos2d::Vec2& index);
        //����������ȡ�������С��
        BaseBubble* getSpriteWithIndex(const cocos2d::Vec2& index);
        //��ȡ����6��С��
        BubbleVector getAroundBubbleWithIndex(const cocos2d::Vec2& index);
        //��ȡ��Χ���������С��
        BubbleVector getAroundBubbleExceptComponentWithIndex(const cocos2d::Vec2& index);
        //��ȡ��Χ�����С��
        BubbleVector getAroundComponentBubbleWithIndex(const cocos2d::Vec2& index);
        //��ȡ��Χ��Ȧ��18��λ�õ�С��
        BubbleVector getTwoAroundBubbleWithIndex(const cocos2d::Vec2& index);
        //��ȡ���ܵ���ͨС��
        BubbleVector getAroundColorBubblesWithIndex(const cocos2d::Vec2& index);
        //��ȡ����������ݵ�λ��
        float getBubblesMinPosition();
        //��������
        int getBubblesMinIndexY();
        //��ȡ�뷢��̨��������
        BaseBubble* getBubbleMinCenter();
        //BaseBubble* getBubbleMinCenterWithIndexs(const int* indexs);
        //��ȡ��Ļ�ڵ�С��
        BubbleVector getBubblesInVisibleSize();
        //��ȡ��Ļ�ڵ�ͬɫС��
        BubbleVector getSameBubblesInVisibleSize(BubbleType color);
        //������ݵ����
        void addBubbleComponentByBubble(BaseBubble* bubble);
        //���ӹҵ�
        void disposeAddSuspensionPoint(BaseBubble* bubble);
        void addSuspensionPointToVector(BaseBubble* bubble);
        //�Ƴ��ҵ�����
        void disposeRemoveSuspensionPoint(BaseBubble* bubble);
        void removeSuspensionPointFromVector(BaseBubble* bubble);
        //��鶥��0����������������
        int getTopRowNullBubbleNumble();
        //�ϲ�����BubbleVector, �ظ��Ĳ�Ҫ
        void mergeTwoBubbleVector(BubbleVector* first_vector, const BubbleVector& second_vector);
        //ȷ��������Ԫ���Ƿ����
        bool isExistInVector(const BubbleVector& vector, BaseBubble* bubble);
        //��ȡ�����ڵ�ʣ��Ԫ��
        BubbleVector getAllBubblesFromMap();
        //����糵����
        BubbleVector separateWindmillBubble();
        //��ȡ�糵��ת�ĽǶ� 
        float getWindmillRotationAngle(BaseBubble* prepare_bubble);
        int getWindmillRotationDirection(const cocos2d::Vec2& bubble_speed, const cocos2d::Vec2& to_center_speed);
        float getWindmillContactVelocity(BaseBubble* prepare_bubble);
        //�ؿ�����
        void setStageType(const StageType& type);
        StageType getStageType();
        //�Ƿ��Ƿ糵����
        bool isWindmillStage();
        //�Ƿ�����������
        void setFallFlag(bool flag);
        bool isFallStage();
        std::vector<cocos2d::Vec2> getFirstRowPositions();
    private:
        static int getColFactorWithIndex(const cocos2d::Vec2& index);
        static cocos2d::Vec2 getUpLeftIndex(const cocos2d::Vec2& index);
        static cocos2d::Vec2 getLeftIndex(const cocos2d::Vec2& index);
        static cocos2d::Vec2 getBottomLeftIndex(const cocos2d::Vec2& index);
        static cocos2d::Vec2 getBottomRightIndex(const cocos2d::Vec2& index);
        static cocos2d::Vec2 getRightIndex(const cocos2d::Vec2& index);
        static cocos2d::Vec2 getUpRightIndex(const cocos2d::Vec2& index);
        //��ȡһ����������������
        BubbleIndexVector getAroundIndexWithIndex(const cocos2d::Vec2& index);
        //��ȡһ��������ڶ�Ȧ������
        BubbleIndexVector getSecondAroundIndexWithIndex(const cocos2d::Vec2& index);
        //��ȡһ�������Ա���Ȧ����Ӱ
        BubbleIndexVector getTwoAroundIndexWithIndex(const cocos2d::Vec2& index);
        //�ѵ�������ת��������
        cocos2d::Vec2 convertIndexToPoint(const cocos2d::Vec2& index);
        //��ȡ���������������ͬ��С��
        BubbleVector getAroundSametypeBubbleWithIndexAndType(const cocos2d::Vec2& index);
        //��ȡ��������û��С�������������
        BubbleIndexVector getAroundEmptyIndexWithIndex(const cocos2d::Vec2& index);
        //�����꼯ת��ΪС�򼯺�
        BubbleVector getBubbleVectorWithIndexVector(const BubbleIndexVector& index_vector);
        //��ȡ���������
        BubbleIndexVector getComponentIndexByIndexAndNumble(const cocos2d::Vec2& index, int numble);
        //��ȡһ��������������������
        BubbleIndexVector getUnderTwoIndexByIndex(const cocos2d::Vec2& index);
        //ת��map��csb������
        cocos2d::Vec2 convertGameSceneCsbToMapSpaceWithBubble(cocos2d::Node* bubble);
        cocos2d::Vec2 convertGameSceneMapToCsbSpaceWithBubble(cocos2d::Node* bubble);
    private:
        //��ȡ�����λ�õ�����
        cocos2d::Vec2 getTheNearestEmptyIndex(const cocos2d::Vec2& point, const cocos2d::Vec2& index);
        //��С��ӵ���ͼ��ȥ
        void addBubbleToBubbleMap(BaseBubble* bubble);
        //Ѱ��δ����С��
        BubbleVector getNotInTheAirBubbles();
        //��ȡ���յ�С��
        BubbleVector getInTheAirBubbles();
        //�������Ӻ�function
        void traverseBubbles(BubbleVector* seed, std::function<BubbleVector(const cocos2d::Vec2& index)> func);
        //���Ժ���  ��ӡ����С�������
        //void printAllIndex();
        //���������̵�����
        cocos2d::Vec2 getIndexMindistanceWithVector(const cocos2d::Vec2& point, const std::vector<cocos2d::Vec2>& index_vector);
        //��ȡ��ײ���������һ������
        cocos2d::Vec2 getIndexNearestContactBubble(const cocos2d::Vec2& prepare_point,
            const cocos2d::Vec2& contact_index);
        //��������BubbleVector�в��ظ���
        BubbleVector getDifferentInTwoBubbleVector(const BubbleVector& first_vector,
            const BubbleVector& second_vector);
        //����string��Ϣ��������
        BaseBubble* convertBubbleDataToBubble(BubbleColorRender* render, const BubbleInfo& info);
        //�ؿ����ʹ���
        void stageTypeFunc(const StageType& stage_type);
    private:
        void setSpecialBubble();
        BaseBubble* getSpecialBubble();
    private:
        BubbleSpriteMap bubble_sprite_map_;
        BubbleVector suspension_points_;
        std::map<StageType, std::function<void()>> stagetype_to_handle_;
        //�洢�����������Ʒ糵��boss����
        BaseBubble* special_bubble_;
        StageType stage_type_;
        bool is_fall_type_ = false;
    };
}
#endif //_GAME_BUBBLE_MAP_IMPLEMENTATION_H_