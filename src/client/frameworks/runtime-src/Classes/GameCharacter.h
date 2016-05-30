//*******************************************************************************
//类名称   : GameCharecter
//功能     : <游戏场景中的人物>
//-------------------------------------------------------------------------------
//备注     : <>
//           
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_CHARACTOR_H_
#define _GAME_CHARACTOR_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class GameCharacter : public cocos2d::Node
    {
    public:
        //static GameCharacter* createWithName(const std::string& name)
        //{ 
        //    GameCharacter *pRet = new(std::nothrow) GameCharacter();
        //    if (pRet && pRet->initWithName(name))
        //    {
        //        pRet->autorelease();
        //        return pRet;
        //    }
        //    else
        //    {
        //        delete pRet;
        //        pRet = NULL;
        //        return NULL;
        //    }
        //}
        CREATE_FUNC(GameCharacter);
        GameCharacter();
        ~GameCharacter();
    public:
        //void playLegendaryAnimation();
        void playVictoryAnimation();
        void playDefeatAnimation();
	protected:
		void onEnter() override;
		void onExit() override;
    private:
        bool init();
		void addEventListenerCustom();
		void removeEventListenerCustom();
        void addCharacterArmature();
		void addCharacterArmatureInvisibleWithName(const std::string& name);
        void playStandbyAnimation(cocostudio::Armature* armature, const std::string& name);
        cocostudio::Armature* getCharactorArmature1();
		cocostudio::Armature* getCharactorArmature2();
        cocostudio::Armature* getCharactorArmature3();
        void playNotLoopAnimationWithName(const std::string& name);
        void setDefeatFlag(bool flag);
        bool isDefeat();
		//根据角度播放发射动画
        void playShootAnimationWithBackName(const std::string & name, const std::string& backName);
        void playShootAnimationAloneWithNameAndDelaytime(const std::string& name, float delaytime);
        void playAnimationWithNameAndCallfunc(const std::string& name, const std::function<void()>& callfunc);
        void playAnimationWithNamesAndCallfunc(const std::vector<std::string>& names, const std::function<void()>& callfunc);
		void playShootAnimation1();
		void playShootAnimation2();
		void playShootAnimation3();
        void playShootAnimation4();
        void playStandbyAnimation1();
		//void playStandbyAnimation1To2(float angle);
		void playStandbyAnimation2();
        void playStandbyAnimation3();
        void playStandbyAnimation4();
		void charactorVictorChange();
        void playExchangeBubbleAnimation();
		void playCharactorVictorChangeAnimation();
        void playShootBubbleAnimation(cocos2d::EventCustom* event);
        void changeCharacterAngle(cocos2d::EventCustom* event);
		//设置其他动画不可见
		void setOtherArmatureInvisible(cocostudio::Armature* armature);
    private:
		cocos2d::Map<std::string, cocostudio::Armature*> armature_vector_;
        bool defeat_flag_ = false;
    };
}
#endif //_GAME_CHARACTOR_H_