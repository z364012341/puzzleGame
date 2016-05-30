#include "ScoreProgressStar.h"
#include "SpriteTextureController.h"
const float STAR_PERCENT_ZOOM_SCALE = 0.90f;
const float STAR_TEXTURE_SCALE = 0.35f;
const std::string SCORE_PROGRESS_START_PATH = "xingxing.png"; //ÁÁÐÇÐÇ
//const std::string SCORE_PROGRESS_START_DARK_PATH = "xingxinghui.png"; //ÁÁÐÇÐÇ
namespace bubble_second {
    ScoreProgressStar::ScoreProgressStar()
    {
    }


    ScoreProgressStar::~ScoreProgressStar()
    {
    }

    ScoreProgressStar* bubble_second::ScoreProgressStar::createWithPercent(float percent)
    {
        ScoreProgressStar *pRet = new(std::nothrow) ScoreProgressStar();
        if (pRet && pRet->initWithPercent(percent))
        {
            pRet->autorelease();
            return pRet;
        }
        else
        {
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }

    bool ScoreProgressStar::initWithPercent(float percent)
    {
        if (!cocos2d::Sprite::init())
        {
            return false;
        }
        SpriteTextureController::getInstance()->setSpriteTexture(SCORE_PROGRESS_START_PATH, this);
        this->setScale(STAR_TEXTURE_SCALE);
        this->setStartPercent(percent);
        this->startTurnOff();
        return true;
    }

    bool ScoreProgressStar::init()
    {
        if (!cocos2d::Sprite::init())
        {
            return false;
        }
        SpriteTextureController::getInstance()->setSpriteTexture(SCORE_PROGRESS_START_PATH, this);
        return true;
    }

    void ScoreProgressStar::setStartPercent(float percent)
    {
		start_percent_ = percent*STAR_PERCENT_ZOOM_SCALE;
    }
    float ScoreProgressStar::getStartPercent()
    {
        return start_percent_;
    }

    void ScoreProgressStar::setStartSpriteShader(const std::string & shader_path)
    {
        //auto fileUtiles = cocos2d::FileUtils::getInstance();
        //std::string fragmentFullPath = fileUtiles->fullPathForFilename(shader_path.c_str());
        //std::string fragSource = fileUtiles->getStringFromFile(fragmentFullPath);
        //cocos2d::GLProgram* shader_program = cocos2d::GLProgram::createWithByteArrays(cocos2d::ccPositionTextureColor_noMVP_vert, fragSource.c_str());
        //cocos2d::GLProgramState* program_state = cocos2d::GLProgramState::getOrCreateWithGLProgram(shader_program);
        //this->setGLProgramState(program_state);
        SpriteTextureController::getInstance()->setGrayShader(this);
    }

    void ScoreProgressStar::startTurnOn()
    {
        if (this->startIsOn())
        {
            return;
        }
        this->setStartSpriteShader(NORMAL_FSH_PATH);
        //SpriteTextureController::getInstance()->setSpriteTexture(SCORE_PROGRESS_START_PATH, this);
        start_on_flag_ = true;
        this->playTurnOnAnimation();
    }

    void ScoreProgressStar::startTurnOff()
    {
        if (!this->startIsOn())
        {
            return;
        }
        this->setStartSpriteShader(GREY_SCALE_FSH_PATH);
        //SpriteTextureController::getInstance()->setSpriteTexture(SCORE_PROGRESS_START_DARK_PATH, this);
        start_on_flag_ = false;
    }

    void ScoreProgressStar::playTurnOnAnimation()
    {
        cocos2d::Sprite* sp = SpriteTextureController::getInstance()->createGameSpriteWithPath(SCORE_PROGRESS_START_PATH);
        //sp->setAnchorPoint(cocos2d::Vec2::ANCHOR_BOTTOM_LEFT);
        sp->setPosition(this->getContentSize().width/2, this->getContentSize().height / 2);
        this->addChild(sp);
        cocos2d::ScaleTo* move1 = cocos2d::ScaleTo::create(0.25f, 1.3f);
        cocos2d::ScaleTo* move2 = cocos2d::ScaleTo::create(0.25f, 1.0f);
        cocos2d::CallFunc* callfunc = cocos2d::CallFunc::create(CC_CALLBACK_0(cocos2d::Sprite::removeFromParent, sp));
        sp->runAction(cocos2d::Sequence::create(move1, move2, callfunc, nullptr));
    }

    void ScoreProgressStar::controlLightWithPercent(float percent)
    {
        if (this->isNeedTurnOn(percent))
        {
            this->startTurnOn();
        }
    }

    void ScoreProgressStar::controlLightWithFlag(bool flag)
    {
        if (flag)
        {
            this->startTurnOn();
        }
        else
        {
            this->startTurnOff();
        }
    }

    bool ScoreProgressStar::startIsOn()
    {
        return start_on_flag_;
    }

    bool ScoreProgressStar::isNeedTurnOn(float percent)
    {
        return percent >= this->getStartPercent();
    }
}