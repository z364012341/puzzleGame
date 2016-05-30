//*******************************************************************************
//类名称   : PuzzleLoadingScene
//功能     : <拼图loading界面>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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