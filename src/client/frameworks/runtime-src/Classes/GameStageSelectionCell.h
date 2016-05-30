//*******************************************************************************
//类名称   : GameStageSelectionCell
//功能     : <单个关卡cell>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_STAGE_SELECTION_CELL_H_
#define _GAME_STAGE_SELECTION_CELL_H_
#include "cocos2d.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class GameStageSelectionCell : public cocos2d::Node
    {
    public:
        static GameStageSelectionCell* create();
        ~GameStageSelectionCell();
        //判断传进来的关卡是否是本cell的
        bool isInCell(int level);
        float getBackgroundHeight();
    private:
        GameStageSelectionCell();
        bool init();
        void playAnimationAndLastLoop(cocostudio::Armature* armature);
        bool addBackground(int cell_numble);
        void disposedBackgroundAnimation();
        bool addSelectionMenu(int cell_numble);
        void setLevelMax(int level);
        int getLevelMax();
    private:
        cocos2d::Node* background_node_ = nullptr;
        int level_max_ = 0;
    };
}
#endif //_GAME_STAGE_SELECTION_CELL_H_