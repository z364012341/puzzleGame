#include "UserDataManager.h"
//#include "StageDataManager.h"
#include "md5.h"
#include "XMLTool.h"
#include "GameBuyStoreMannager.h"
const std::string GAME_STAGE_DATA_PATH = "stageData.plist";
const std::string GAME_USER_DATA_PATH = "userData.plist";
const std::string GAME_PUZZLE_STAGE_DATA_PATH = "puzzleStageBestScore.plist";
const std::string USER_DATA_NICKNAME_KEY = "user_nickname";
const std::string USER_DATA_MUSIC_KEY = "GAME_MUSIC";
const std::string USER_DATA_SOUND_EFFECT_KEY = "SOUND_EFFECT";
const std::string HAVED_BUY_NEWBIE_GIFT_KEY = "buyNewbieGift";
const std::string PROP_MD5_KEY = "md5";
const std::string PROP_MD5_SECRET_KEY = "*miaopass*";
namespace bubble_second {
    UserDataManager::UserDataManager()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_BUY_PROPS_PAY_SUCCESS, [=](cocos2d::EventCustom* event) {
            if (GameBuyStoreMannager::getInstance()->isBuyPuzzleNewbiwGift())
            {
                this->buyNewbieGift();
            }
            for (auto var : buy_props_save_)
            {
                this->addPropsNumbleWithKey(var.first, var.second.asInt());
            }

        });
        cocos2d::Director::getInstance()->getEventDispatcher()->addCustomEventListener(EVENT_BUY_PROPS_PAY_FAIL, [=](cocos2d::EventCustom* event) {
            buy_props_save_.clear();
        });
    }

    UserDataManager::~UserDataManager()
    {
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_BUY_PROPS_PAY_SUCCESS);
        cocos2d::Director::getInstance()->getEventDispatcher()->removeCustomEventListeners(EVENT_BUY_PROPS_PAY_FAIL);
    }
    void UserDataManager::readStageFile()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getStageDataPath();
        if (file_utils->isFileExist(path))
        {
            stage_data_ = file_utils->getValueMapFromFile(path);
        }
    }
    void UserDataManager::readUserDataFile()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getUserDataPath();
        if (file_utils->isFileExist(path))
        {
            user_data_ = file_utils->getValueMapFromFile(path);
            if (user_data_[PROP_MD5_KEY].asString() != this->encryptionPropsNumble())
            {
                exit(-1);
            }
        }
    }
    std::string UserDataManager::getMD5Str(const std::string & input_str)
    {
        return MD5(input_str).hexdigest();
    }
    std::string UserDataManager::encryptionPropsNumble()
    {
        std::string str = XMLTool::convertIntToString(this->getPropsNumbleWithKey(PUZZLE_SEARCH_PROP_KEY)) +
            XMLTool::convertIntToString(this->getPropsNumbleWithKey(PUZZLE_BIG_EYES_PROP_KEY)) +
            XMLTool::convertIntToString(this->getPropsNumbleWithKey(PUZZLE_ADD_TIME_PROP_KEY));
        return this->getMD5Str(PROP_MD5_SECRET_KEY+ str);
    }
    int UserDataManager::getPropsNumbleWithKey(const std::string & key)
    {
        if (user_data_.find(key) != user_data_.end())
        {
            return user_data_.at(key).asInt();
        }
        return 0;
    }
    void UserDataManager::setPropsNumbleWithKey(const std::string & key, int numble)
    {
        user_data_[key] = numble;
        this->saveUserData();
    }
    void UserDataManager::addPropsNumbleWithKey(const std::string & key, int numble)
    {
        this->setPropsNumbleWithKey(key, this->getPropsNumbleWithKey(key) + numble);
    }
    void UserDataManager::cutPropsNumbleWithKey(const std::string& key)
    {
        this->setPropsNumbleWithKey(key, this->getPropsNumbleWithKey(key)-1);
    }
    void UserDataManager::setBuyPropsKeyAndNumble(cocos2d::ValueMap data)
    {
        buy_props_save_ = data;
    }
    void UserDataManager::buyNewbieGift()
    {
        cocos2d::UserDefault::getInstance()->setBoolForKey(HAVED_BUY_NEWBIE_GIFT_KEY.c_str(), true);
        cocos2d::UserDefault::getInstance()->flush();
    }
    bool UserDataManager::canBuyNewbieGift()
    {
        return !cocos2d::UserDefault::getInstance()->getBoolForKey(HAVED_BUY_NEWBIE_GIFT_KEY.c_str());
    }
    int UserDataManager::getStartNumbleWithLevel(int level)
    {
        char levelStr[10];
        sprintf(levelStr, "%d", level);
        if (stage_data_.find(levelStr) != stage_data_.end())
        {
            return stage_data_.at(levelStr).asInt();
        }
        return 0;
    }
    void UserDataManager::setPresentCell(int cell_numble)
    {
        present_cell_ = cell_numble;
    }
    int UserDataManager::getPresentCell()
    {
        return present_cell_;
    }
    void UserDataManager::setUserNickname(const std::string & name)
    {
        user_data_[USER_DATA_NICKNAME_KEY] = name;
    }
    std::string UserDataManager::getUserNickname() const
    {
        if (user_data_.find(USER_DATA_NICKNAME_KEY) != user_data_.end())
        {
            return user_data_.at(USER_DATA_NICKNAME_KEY).asString();
        }
        return "";
    }
    void UserDataManager::setGameMusicEnable(bool flag)
    {
        user_data_[USER_DATA_MUSIC_KEY] = flag;
    }
    bool UserDataManager::isGameMusicEnable()
    {
        if (user_data_.find(USER_DATA_MUSIC_KEY) != user_data_.end())
        {
            return user_data_.at(USER_DATA_MUSIC_KEY).asBool();
        }
        return false;
    }
    void UserDataManager::setSoundEffect(bool flag)
    {
        user_data_[USER_DATA_SOUND_EFFECT_KEY] = flag;
    }
    bool UserDataManager::isSoundEffectEnable()
    {
        if (user_data_.find(USER_DATA_SOUND_EFFECT_KEY) != user_data_.end())
        {
            return user_data_.at(USER_DATA_SOUND_EFFECT_KEY).asBool();
        }
        return false;
    }
    void UserDataManager::saveUserData()
    {
        std::string path = getUserDataPath();
        user_data_[PROP_MD5_KEY] = this->encryptionPropsNumble();
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(user_data_, path);

    }
    //bool UserDataManager::isCompletedGame()
    //{
    //    return this->getStagePassCount() == StageDataManager::getInstance()->getStageTotalNumble();
    //}
    void UserDataManager::writeStageDataToFile()
    {
        std::string path = getStageDataPath();
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(stage_data_, path);
    }
    void UserDataManager::updateStageData(int level, int start_numble)
    {
        char levelStr[10];
        sprintf(levelStr, "%d", level);
        if (stage_data_.find(levelStr) != stage_data_.end() && stage_data_[levelStr].asInt() >= start_numble)
        {
            return;
        }
        if (level-1 == stage_data_.size())
        {
            stage_data_[levelStr] = cocos2d::Value(start_numble);
            this->writeStageDataToFile();
        }
    }
    void UserDataManager::readDataFile()
    {
        this->readStageFile();
        this->readUserDataFile();
        this->readPuzzleStageBestScore();
        unlock_stage_numble_ = this->getStagePassCount();
    }
    std::string UserDataManager::getStageDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_STAGE_DATA_PATH;
    }
    std::string UserDataManager::getUserDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_USER_DATA_PATH;
    }
    std::string UserDataManager::getPuzzleStageDataPath() const
    {
        return cocos2d::FileUtils::getInstance()->getWritablePath() + GAME_PUZZLE_STAGE_DATA_PATH;
    }
    int UserDataManager::getStagePassCount()
    {
        return stage_data_.size();
    }
    void UserDataManager::addUnlockStageNumble()
    {
        unlock_stage_numble_++;
    }
    bool UserDataManager::isUnlockWithStageNumble(int stage_numble)
    {
        return stage_numble <= unlock_stage_numble_;
    }
    void UserDataManager::insertPuzzleStageData(const std::string & key, int consumingTime)
    {
        if (puzzle_stage_data_.find(key) == puzzle_stage_data_.end() || puzzle_stage_data_[key].asInt()>consumingTime)
        {
            puzzle_stage_data_[key] = cocos2d::Value(consumingTime);
            this->savePuzzleStageData();
        }
    }
    void UserDataManager::savePuzzleStageData()
    {
        std::string path = getPuzzleStageDataPath();
        cocos2d::FileUtils::getInstance()->writeValueMapToFile(puzzle_stage_data_, path);
    }
    void UserDataManager::readPuzzleStageBestScore()
    {
        auto file_utils = cocos2d::FileUtils::getInstance();
        std::string path = this->getPuzzleStageDataPath();
        if (file_utils->isFileExist(path))
        {
            puzzle_stage_data_ = file_utils->getValueMapFromFile(path);
        }
    }
    int UserDataManager::getPuzzleStageBestScoreWithKey(const std::string & key)
    {
        //if (puzzle_stage_data_.find(key) != puzzle_stage_data_.end())
        //{
            return puzzle_stage_data_.at(key).asInt();
        //}
        //return 99999;

    }
    const std::string UserDataManager::getPuzzleSearchPropKey()
    {
        return PUZZLE_SEARCH_PROP_KEY;
    }
    const std::string UserDataManager::getPuzzleBigEyesPropKey()
    {
        return PUZZLE_BIG_EYES_PROP_KEY;
    }
    const std::string UserDataManager::getPuzzleAddTimePropKey()
    {
        return PUZZLE_ADD_TIME_PROP_KEY;
    }
    
}