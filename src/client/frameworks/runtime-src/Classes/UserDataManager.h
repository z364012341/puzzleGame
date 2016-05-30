//*******************************************************************************
//������   : UserDataManager
//����     : <�������ݳ־û�>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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
        //��ȡ��ͨ���ؿ�������
        int getStagePassCount();
        void updateStageData(int level, int start_numble);
        void readDataFile();
        int getStartNumbleWithLevel(int level);
        void setPresentCell(int cell_numble);
        int getPresentCell();
        void setUserNickname(const std::string& name);
        std::string getUserNickname() const;
        void setGameMusicEnable(bool flag);
        //�Ƿ񲥷�����
        bool isGameMusicEnable();
        void setSoundEffect(bool flag);
        //�Ƿ񲥷���Ч����
        bool isSoundEffectEnable();
        //�����������
        void saveUserData();
        //��Ϸ�Ƿ�ͨ��
        bool isCompletedGame();
        //+1�����ؿ�
        void addUnlockStageNumble();
        bool isUnlockWithStageNumble(int stage_numble);
        //ƴͼ�ؿ�����
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
        //������Ʒtarget
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