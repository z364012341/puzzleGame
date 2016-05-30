//*******************************************************************************
//�ļ���       : <RainbowSealBubble.h>
//�ļ�ʵ�ֹ���  : <�������Դ��ʺ��ӡ, �ֻز���>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _RAINBOW_SEAL_BUBBLE_H_
#define _RAINBOW_SEAL_BUBBLE_H_
#include "BaseComponentBubble.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class RainbowCharactor;
    class BaseBubble;
    class RainbowSealBubble : public BaseComponentBubble
    {
    public:
        CREATE_FUNC(RainbowSealBubble);
        ~RainbowSealBubble();
        //int getBubbleComponentNumble() override;
        BubbleVector disposeRainbowSeal(BubbleType color);
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
        //�ı���ɫ
        void changeRainbowColor();
        void beginSealingCharactor();
        //void setSealedCharactor(RainbowCharactor* charactor);
        //RainbowCharactor* getSealedCharactor();
        //float playTheSpecialEffects();
        bool isEliminateByProperty() override;
    private:
        RainbowSealBubble();
        bool init();
        void addTouchEventListener() override;
        void addBackground();
        //���Ӵ�������
        void addStandbyAnimation();
        void addRainbowCharactor();
        void setBubbleTexture(BubbleType type) override;
        void addBubbleCover();
        //������ɫ
        void setRainbowColor(BubbleType color);
        BubbleType getRainbowColor();
        //�Ƿ����ӡ��ɫ���
        bool isEqualRainbowColor(BubbleType color);
        //�Ƿ��Ѿ���ӡ������
        bool isCharactorExist();
        void playCharactorDefeatAnimation();
        void playCharactorStandbyAnimation();
        void runBubbleEffect(const std::string& name, const cocos2d::Vec2& point) override;
        //�ı��ӡ����ɫ
        void setBackgroundColor(BubbleType color);
    private:
        cocos2d::Sprite* rainbow_swirl_ = nullptr;
        cocos2d::Sprite* rainbow_background_ = nullptr;
        //��ӡ��ɫ
        BubbleType rainbow_color_;
        bool first_flag_;
        //�����ӡ������
        RainbowCharactor* sealed_charactor_;
        cocos2d::Node* cover_csb_ = nullptr;
    };
}
#endif //_RAINBOW_SEAL_BUBBLE_H_