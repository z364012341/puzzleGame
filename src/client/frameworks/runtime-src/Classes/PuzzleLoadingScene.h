//*******************************************************************************
//������   : PuzzleLoadingScene
//����     : <ƴͼloading����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _PUZZLE_LOADING_SCENE_H_
#define _PUZZLE_LOADING_SCENE_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class PuzzleLoadingScene : public cocos2d::Layer
    {
    public:
        static cocos2d::Scene* createScene();
        CREATE_FUNC(PuzzleLoadingScene);
        PuzzleLoadingScene();
        ~PuzzleLoadingScene();
        bool init();
        void beginLoading();
    };
}
#endif //_PUZZLE_LOADING_SCENE_H_