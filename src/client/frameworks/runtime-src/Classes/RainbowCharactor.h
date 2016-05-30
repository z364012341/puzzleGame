//*******************************************************************************
//������   : RainbowCharactor
//����     : <�ʺ��ӡ���������>
//-------------------------------------------------------------------------------
//��ע     :
//          
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _RAINBOW_CHARACTOR_H_
#define _RAINBOW_CHARACTOR_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
#include "cocostudio/CocoStudio.h"
const std::string RAINBOW_CHARACTOR_ARMATURE_NAME = "langda";
namespace bubble_second {
    class RainbowSealBubble;
    class BaseBubble;
    class RainbowCharactor : public cocos2d::Node
    {
    public:
        //CREATE_FUNC(RainbowCharactor);
        static RainbowCharactor* createWithFile(const std::string& path);
        ~RainbowCharactor();
        //��ʼ��ӡ
        void beginSealingCharactor();
        //��ӡת��
        void moveSealintCharactor(RainbowSealBubble* bubble, const cocos2d::Vec2& from_point);
        //���ö�����·��
        void setArmaturePath(const std::string& path);
        std::string getArmaturePath();
        void playContactAnimation();
        void playStandbyAnimation();
        void playDefeatAnimation();
    private:
        RainbowCharactor();
        //bool init();
        bool initWithFile(const std::string& path);
        void initTexture();
        //void setSealedBubble(BaseBubble* bubble);
        //BaseBubble* getSealedBubble();
        void addCharactorArmature();
        //void runFlyingAnimation(RainbowSealBubble* bubble, const cocos2d::Vec2& armature_point, bool armature_point_need_convert = true);
    private:
        //�������������е���
        //BaseBubble* sealed_bubble_;

        std::string armature_path_;
        cocostudio::Armature *armature_ = nullptr;
    };
}
#endif //_RAINBOW_CHARACTOR_H_