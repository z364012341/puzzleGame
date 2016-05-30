//*******************************************************************************
//�ļ���       : <MutipleSealBubble.h>
//�ļ�ʵ�ֹ���  : <�������Դ����ط�ӡ, ��������ʧȥ�ҵ�����ӡ>
//����         : <�����.,.>
//�汾         : <1.0>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _MUTIPLE_SEAL_BUBBLE_H_
#define _MUTIPLE_SEAL_BUBBLE_H_
#include "BaseComponentBubble.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class MutipleSealBubble : public BaseComponentBubble
    {
    public:
        static MutipleSealBubble* createWithComponentNumble(int numble)
        {
            MutipleSealBubble *pRet = new(std::nothrow) MutipleSealBubble();
            if (pRet && pRet->initWithComponentNumble(numble))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
        ~MutipleSealBubble();
        void onEnter() override;
        void onExit() override;
        void bubbleEliminate(int combo = 0) override;
        //cocostudio::Armature * getBubbleEliminateArmature();
        void bubbleEliminateFlyCallfunc();
        void downFromAir() override;
        void addBubbleStaticBody() override;
        cocos2d::Vec2 getBubblePropsWeaponPosition() override;
    private:
        MutipleSealBubble();
        void setBubbleTexture(BubbleType type) override;
        bool initWithComponentNumble(int numble);
		void playStandbyAnimation();
        void playDefeatAnimation(cocos2d::EventCustom* event);
		void runBubbleEffect(const std::string& name, const cocos2d::Vec2& point) override;
        void addNoopComponent();
	private:
        cocostudio::Armature *armature_;
        cocos2d::EventListenerCustom* listener_ = nullptr;
    };
}
#endif //_MUTIPLE_SEAL_BUBBLE_H_