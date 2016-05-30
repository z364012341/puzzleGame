#include "GameCharactorNameManager.h"

const std::string GAME_CHARACTER_ARMATURE_LAOHU_NAME = "laohu";
const std::string GAME_CHARACTER_ARMATURE_LAOHU2_NAME = "laohu2";
const std::string GAME_CHARACTER_ARMATURE_LAOHU3_NAME = "laohu3";
const std::string GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_NAME = "laohu-shengli";

const std::string GAME_CHARACTER_ARMATURE_MIAO_1_NAME = "xiaomao1";
const std::string GAME_CHARACTER_ARMATURE_MIAO_2_NAME = "xiaomao2";
const std::string GAME_CHARACTER_ARMATURE_MIAO_3_NAME = "xiaomao3";
const std::string GAME_CHARACTER_ARMATURE_MIAO_VICTORY_NAME = "shenglimao";

const std::string CHARCTOR_ARMATURE_KEY_1 = "armature_1";
const std::string CHARCTOR_ARMATURE_KEY_2 = "armature_2";
const std::string CHARCTOR_ARMATURE_KEY_3 = "armature_3";
const std::string CHARCTOR_ARMATURE_KEY_VICTORY = "armature_victory";
const std::string CHARCTOR_LAOHU_ARMATURE_KEY = "laohu";
const std::string CHARCTOR_MIAO_ARMATURE_KEY = "miaopass";
namespace bubble_second {
    GameCharactorNameManager::GameCharactorNameManager()
    {
        current_name_ = CHARCTOR_MIAO_ARMATURE_KEY;
        {
            cocos2d::ValueMap names_map;
            names_map[CHARCTOR_ARMATURE_KEY_1] = GAME_CHARACTER_ARMATURE_LAOHU_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_2] = GAME_CHARACTER_ARMATURE_LAOHU2_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_3] = GAME_CHARACTER_ARMATURE_LAOHU3_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_VICTORY] = GAME_CHARACTER_ARMATURE_LAOHU_VICTORY_NAME;
            charactor_armature_names_[CHARCTOR_LAOHU_ARMATURE_KEY] = names_map;
        }
        {               
            cocos2d::ValueMap names_map;
            names_map[CHARCTOR_ARMATURE_KEY_1] = GAME_CHARACTER_ARMATURE_MIAO_1_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_2] = GAME_CHARACTER_ARMATURE_MIAO_2_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_3] = GAME_CHARACTER_ARMATURE_MIAO_3_NAME;
            names_map[CHARCTOR_ARMATURE_KEY_VICTORY] = GAME_CHARACTER_ARMATURE_MIAO_VICTORY_NAME;
            charactor_armature_names_[CHARCTOR_MIAO_ARMATURE_KEY] = names_map;
        }
    }


    GameCharactorNameManager::~GameCharactorNameManager()
    {
    }
    std::string GameCharactorNameManager::getCurrentArmatureName()
    {
        return current_name_;
    }
    std::string GameCharactorNameManager::getCurrentArmatureName1()
    {
        return charactor_armature_names_[this->getCurrentArmatureName()].asValueMap()[CHARCTOR_ARMATURE_KEY_1].asString();
    }
    std::string GameCharactorNameManager::getCurrentArmatureName2()
    {
        return charactor_armature_names_[this->getCurrentArmatureName()].asValueMap()[CHARCTOR_ARMATURE_KEY_2].asString();
    }
    std::string GameCharactorNameManager::getCurrentArmatureName3()
    {
        return charactor_armature_names_[this->getCurrentArmatureName()].asValueMap()[CHARCTOR_ARMATURE_KEY_3].asString();
    }
    std::string GameCharactorNameManager::getCurrentArmatureNameVictory()
    {
        return charactor_armature_names_[this->getCurrentArmatureName()].asValueMap()[CHARCTOR_ARMATURE_KEY_VICTORY].asString();
    }
}