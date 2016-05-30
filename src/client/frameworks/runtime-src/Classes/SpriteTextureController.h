//*******************************************************************************
//������   : SpriteTextureController
//����     : <���뾫������������߼�>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _SPRITE_TEXTURE_CONTROLLER_H_
#define _SPRITE_TEXTURE_CONTROLLER_H_
#include "BubbleSecondConstant.h"
#include "CenteredMenuItemSprite.h"
const std::string GAME_COIN_PATH = "jinbi.PNG"; //���
namespace bubble_second {
    class CenteredMenuItemSprite;
    class SpriteTextureController
    {
    public:
        GETINSTANCE_FUNC(SpriteTextureController);
        ~SpriteTextureController();
        void setSpriteTexture(const std::string& path, cocos2d::Sprite* sprite);
        cocos2d::Sprite* createGameSpriteWithPath(const std::string& path);
        CenteredMenuItemSprite* createMenuItemSprite(const std::string& path, const cocos2d::ccMenuCallback& callback = nullptr);
        cocos2d::Sprite* createStageTypeSprite(const StageType& type);
        cocos2d::Sprite* createMenuStageTypeSprite(const StageType& type);
        //cocos2d::Sprite* createStageTypeSprite(const StageType& type);
        cocos2d::Sprite* createGameBackgroundSprite(int cell_numble);
        //��������
        void addResourcesTexture();
        //���
        void setGrayShader(cocos2d::Sprite* sprite);
        //void addGameBackgroundTexture(int cell_numble);
        //cocos2d::Sprite* createGameBlurBackground();
        //����
        //cocos2d::Sprite* getScreenShot();
    private:
        SpriteTextureController();
        void readGameSceneBackgroundFile();
        void addArmatureFile();
        void removeArmatureFile();
        //ģ��
        //cocos2d::RenderTexture* SpriteBlurer(cocos2d::Sprite* pSprite, const float fRadius = 8.0f, const float fSampleNum = 8.0f);
    private:
        std::map<StageType, std::string> stagetype_to_path_;
        std::map<StageType, std::string> stage_menu_stagetype_to_path_;
        cocos2d::ValueMap cell_to_path_;
        std::vector<std::string> armature_path_;
    };
}
#endif //_SPRITE_TEXTURE_CONTROLLER_H_