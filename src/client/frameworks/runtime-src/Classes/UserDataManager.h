//*******************************************************************************
//类名称   : UserDataManager
//功能     : <用于数据持久化>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _USER_DATA_MANAGER_H_
#define _USER_DATA_MANAGER_H_
#include "BubbleSecondConstant.h"
const std::string PUZZLE_SEARCH_PROP_KEY = "search";
const std::string PUZZLE_BIG_EYES_PROP_KEY = "bigEyes";
const std::string PUZZLE_ADD_TIME_PROP_KEY = "addTime";

namespace bubble_second {
    class UserDataManager
    {
    public:
        GETINSTANCE_FUNC(UserDataManager);
        static const std::string getPuzzleSearchPropKey();
        static const std::string getPuzzleBigEyesPropKey();
        static const std::string getPuzzleAddTimePropKey();
        UserDataManager();
        //获取已通过关卡的数量
        int getStagePassCount();
        void updateStageData(int level, int start_numble);
        void readDataFile();
        int getStartNumbleWithLevel(int level);
        void setPresentCell(int cell_numble);
        int getPresentCell();
        void setUserNickname(const std::string& name);
        std::string getUserNickname() const;
        void setGameMusicEnable(bool flag);
        //是否播放音乐
        bool isGameMusicEnable();
        void setSoundEffect(bool flag);
        //是否播放特效声音
        bool isSoundEffectEnable();
        //保存玩家数据
        void saveUserData();
        //游戏是否通关
        bool isCompletedGame();
        //+1解锁关卡
        void addUnlockStageNumble();
        bool isUnlockWithStageNumble(int stage_numble);
        //拼图关卡数据
        void insertPuzzleStageData(const std::string& key, int consumingTime);
        void savePuzzleStageData();
        void readPuzzleStageBestScore();
        int getPuzzleStageBestScoreWithKey(const std::string& key);

        int getPropsNumbleWithKey(const std::string& key);
        void setPropsNumbleWithKey(const std::string& key, int numble);
        void addPropsNumbleWithKey(const std::string& key, int numble);
        void cutPropsNumbleWithKey(const std::string& key);

        void setBuyPropsKeyAndNumble(cocos2d::ValueMap data);

        void buyNewbieGift();
        bool canBuyNewbieGift();
        //设置商品target
        //void setStoreOneTimeFlag(bool flag);
    private:
        ~UserDataManager();
        void writeStageDataToFile();
        std::string getStageDataPath() const;
        std::string getUserDataPath() const;
        std::string getPuzzleStageDataPath() const;
        void readStageFile();
        void readUserDataFile();
        std::string getMD5Str(const std::string& input_str);
        std::string encryptionPropsNumble();
        
    private:
        cocos2d::ValueMap stage_data_;
        int present_cell_ = 0;
        cocos2d::ValueMap user_data_;
        int unlock_stage_numble_ = 0;
        cocos2d::ValueMap puzzle_stage_data_;
        cocos2d::ValueMap buy_props_save_;
        
    };
}
#endif //_USER_DATA_MANAGER_H_