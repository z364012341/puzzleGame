//*******************************************************************************
//������   : GameTextInfo
//����     : <��Ϸ������Ϣ��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _GAME_TEXT_INFO_H_
#define _GAME_TEXT_INFO_H_
#include "BubbleSecondConstant.h"
const std::string GAME_TEXT_LEVEL_NUMBLE_1_KEY = "alert_level_1";
const std::string GAME_TEXT_LEVEL_NUMBLE_2_KEY = "alert_level_2";
const std::string COMMODITY_ADD_10_BUBBLE_KEY = "add_10_bubble";   //��10����
const std::string COMMODITY_AIMING_LINE_KEY = "aiming_line"; //��׼�ߵ���
const std::string COMMODITY_ADD_SPECIAL_KEY = "add_special_bubble"; //��3����������
namespace bubble_second {
    class GameTextInfo
    {
    public:
        GETINSTANCE_FUNC(GameTextInfo);
        ~GameTextInfo();
        std::string getTextInfoWithKey(const std::string& key) const;
        std::string getTextInfoWithStageType(const StageType& type);
        std::string getCommodityCoinNumbleWithKey(const std::string& key) const;
        std::string getCommodityDiamondNumbleWithKey(const std::string& key) const;
        cocos2d::Value getCommodityCoinValueWithKey(const std::string& key) const;
        void plistToMap();
    private:
        GameTextInfo();
    private:
        cocos2d::ValueMap plist_map_;
        std::map<StageType, std::string> stagetype_to_key_;
        cocos2d::ValueMap commodity_map_;
    };
}
#endif //_GAME_TEXT_INFO_H_