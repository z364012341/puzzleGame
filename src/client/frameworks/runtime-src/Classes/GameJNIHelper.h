//*******************************************************************************
//类名称   : GameJNIHelper
//功能     : <>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_JNI_HELPER_H_
#define _GAME_JNI_HELPER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class GameJNIHelper
    {
    public:
        GETINSTANCE_FUNC(GameJNIHelper);
        ~GameJNIHelper();
        void payWithTargetID(int targetID);
    private:
        GameJNIHelper();

    };
}
#endif