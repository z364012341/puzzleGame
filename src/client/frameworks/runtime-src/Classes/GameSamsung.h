//*******************************************************************************
//类名称   : GameSamsung
//功能     : <游戏里面三星显示>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _GAME_SAMSUNG_H_
#define _GAME_SAMSUNG_H_
#include "cocos2d.h"
namespace bubble_second {
    class ScoreProgressStar;
    class GameSamsung : public cocos2d::Node
    {
    public:
        static GameSamsung* createWithNumble(int numble);
        ~GameSamsung();
    private:
        GameSamsung();
        bool initWithNumble(int numble);
        void addStart(int numble);
        void addStartLeft();
        void addStartMiddle();
        void addStartRight();
        void addStartDouble();
        void addStartTriple();
        //void controlStartLight(int numble);
    private:
        //ScoreProgressStart* start_left_ = nullptr;
        //ScoreProgressStart* start_middle_ = nullptr;
        //ScoreProgressStart* start_right_ = nullptr;
        std::map<int, std::function<void()>> numble_to_handle_;
        cocos2d::Vector<ScoreProgressStar*> start_vector_;
    };
}
#endif //_GAME_SAMSUNG_H_