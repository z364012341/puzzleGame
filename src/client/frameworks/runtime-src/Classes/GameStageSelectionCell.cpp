#include "GameStageSelectionCell.h"
#include "StageSelectionMenu.h"
#include "StageDataManager.h"
#include "StageNumble.h"
#include "StageCellRabbit.h"
const std::string STAGE_CELL_BACKGROUND = "stageBackground";
const std::string SINGLE_COW_NAME = "singleCowArmature";
const std::string COUPLES_COW_NAME = "CouplesCowArmature";
const std::string SINGLE_COW_ANIMATION_NAME_1 = "danshenniu1";
const std::string SINGLE_COW_ANIMATION_NAME_2 = "danshenniu2";
const std::string SINGLE_COW_ANIMATION_NAME_3 = "danshenniu3-xunhuan";
namespace bubble_second {
    GameStageSelectionCell::GameStageSelectionCell()
    {
    }

    GameStageSelectionCell::~GameStageSelectionCell()
    {
    }

    bool GameStageSelectionCell::isInCell(int level)
    {
        return level < this->getLevelMax();
    }

    float GameStageSelectionCell::getBackgroundHeight()
    {
        return background_node_->getChildByName(STAGE_CELL_BACKGROUND)->getContentSize().height;
    }

    GameStageSelectionCell * bubble_second::GameStageSelectionCell::create()
    {
        GameStageSelectionCell *pRet = new(std::nothrow) GameStageSelectionCell();
        if (pRet && pRet->init())
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

    bool GameStageSelectionCell::init()
    {
        static int cellNumble = GAME_STAGE_SELECTION_CELL_NUMBLE_BEGIN;
        if (!(this->addBackground(cellNumble) && this->addSelectionMenu(cellNumble)))
        {
            StageNumble::getInstance()->clear();
            cellNumble = GAME_STAGE_SELECTION_CELL_NUMBLE_BEGIN;
            return false;
        }
        ++cellNumble;
        return true;
    }
    void GameStageSelectionCell::playAnimationAndLastLoop(cocostudio::Armature* armature)
    {
        auto names = armature->getAnimation()->getAnimationData()->movementNames;
        std::string last_name = names.back();
        armature->getAnimation()->playWithNames(names, SPECIAL_BUBBLE_EFFECT_DURATION, false);
        armature->getAnimation()->setMovementEventCallFunc([=](cocostudio::Armature *armature, cocostudio::MovementEventType movementType, const std::string& movementID) {
            if (movementID == last_name && movementType == cocostudio::COMPLETE)
            {
                armature->getAnimation()->play(last_name, SPECIAL_BUBBLE_EFFECT_DURATION, true);
            }
        });

    }
    bool GameStageSelectionCell::addBackground(int cell_numble)
    {
        char path[20];
        sprintf(path, GAME_STAGE_NODE_CSB_FORMAT, cell_numble);
        if (!cocos2d::FileUtils::getInstance()->isFileExist(path))
        {
            return false;
        }
        background_node_ = cocos2d::CSLoader::createNode(path);
        //background_node_->setScale(GAME_STAGE_SELECTION_CELL_SCALE);
        this->addChild(background_node_);
        auto action = cocos2d::CSLoader::createTimeline(path);
        background_node_->runAction(action);
        action->gotoFrameAndPlay(0, true);

        if (cell_numble == 0)
        {//第一关特殊处理
            this->disposedBackgroundAnimation();
        }

        return true;
    }

    void GameStageSelectionCell::disposedBackgroundAnimation()
    {
        this->playAnimationAndLastLoop(dynamic_cast<cocostudio::Armature*>(background_node_->getChildByName(SINGLE_COW_NAME)));
        this->playAnimationAndLastLoop(dynamic_cast<cocostudio::Armature*>(background_node_->getChildByName(COUPLES_COW_NAME)));
        background_node_->getChildByName("rabbit_1")->addChild(StageCellRabbit::create());
        background_node_->getChildByName("rabbit_2")->addChild(StageCellRabbit::create());
    }

    bool GameStageSelectionCell::addSelectionMenu(int cell_numble)
    {
        int tag = GAME_STAGE_SELECTION_CELL_MENU_POSITION_NODE_TAG_BEGIN;
        cocos2d::Node* node = nullptr;
        StageSelectionMenu* menu = nullptr;
        bool result = false;
        while (true)
        {
            int stage_numble = StageNumble::getInstance()->getStageNumble();
            node = background_node_->getChildByTag(tag);
            if (node && !StageNumble::getInstance()->moreThanStageTotal())
            {
                menu = StageSelectionMenu::create(cell_numble, stage_numble, StageDataManager::getInstance()->getStageTypeWithNumble(stage_numble));
                menu->setScale(0.9f);
                node->addChild(menu);
                StageNumble::getInstance()->nextStageNumble();
                ++tag;
                result = true;
            }
            else
            {
                this->setLevelMax(stage_numble);
                break;
            }
        }
        return result;
    }
    void GameStageSelectionCell::setLevelMax(int level)
    {
        level_max_ = level;
    }
    int GameStageSelectionCell::getLevelMax()
    {
        return level_max_;
    }
}