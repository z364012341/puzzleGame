//*******************************************************************************
//������   : LoadingScene
//����     : <loading����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _LOADING_SCENE_H_
#define _LOADING_SCENE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class LoadingScene : public cocos2d::Layer
    {
    public:
        static cocos2d::Scene* createScene();
        CREATE_FUNC(LoadingScene);
        LoadingScene();
        ~LoadingScene();
        bool init();
        void beginLoading();
        void addBackground();
    };
}
#endif //_LOADING_SCENE_H_