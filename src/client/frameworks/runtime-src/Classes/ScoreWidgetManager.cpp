#include "ScoreWidgetManager.h"
#include "ScoreWidget.h"
#include "GameScoreController.h"
#include "XMLTool.h"
const float WIDGET_POSITION_RANGE_RIGHT_MAX = GAME_DESIGN_RESOLUTION_WIDTH / 2 - BUBBLE_RADIUS - SCORE_WIDGET_BODY_RADIUS + 5.0f;
const float WIDGET_POSITION_RANGE_RIGHT_MIN = GAME_DESIGN_RESOLUTION_WIDTH / 2 - BUBBLE_RADIUS * 2 - SCORE_WIDGET_BODY_RADIUS - 5.0f;
const float WIDGET_POSITION_RANGE_LEFT_MAX = -WIDGET_POSITION_RANGE_RIGHT_MIN;
const float WIDGET_POSITION_RANGE_LEFT_MIN = -WIDGET_POSITION_RANGE_RIGHT_MAX;
const std::string SCORE_WIDGET_UPDATE_ANIMATION_NAME = "yun3";
const std::string SCORE_WIDGET_BONE_DATA_PLIST_PATH = "res/scoreWidgetBoneData.plist";
namespace bubble_second {
    ScoreWidgetManager::ScoreWidgetManager():widget_total_(0)
    {
        //this->addEventListenerCustom();
        combo_to_type_[0] = kScoreWidgetLow;
        combo_to_type_[1] = kScoreWidgetLow;
        combo_to_type_[2] = kScoreWidgetMiddle;
        combo_to_type_[3] = kScoreWidgetMiddle;
        combo_to_type_[4] = kScoreWidgetMiddle;
        combo_to_type_[5] = kScoreWidgetMiddle;
        combo_to_type_[6] = kScoreWidgetHigh;
        widget_update_sequence_.push_back(kScoreWidgetLow);
        widget_update_sequence_.push_back(kScoreWidgetMiddle);
        widget_remove_sequence_.push_back(kScoreWidgetHigh);
        widget_remove_sequence_.push_back(kScoreWidgetMiddle);
        widget_remove_sequence_.push_back(kScoreWidgetLow);

        type_to_key_[kScoreWidgetLow] = "low";
        type_to_key_[kScoreWidgetMiddle] = "middle";
        type_to_key_[kScoreWidgetHigh] = "high";
        /*cocos2d::ValueMap bee_bone_data;
        {
            cocos2d::ValueMap bee_low_data;
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "mifengguai_0001_MiFeng-yanpi2.png";
                bee_low_data["Layer48"] = bone_data; }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "mifengguai_0000_MiFeng-yanpi1.png";
                bee_low_data["Layer46"] = bone_data;
            }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "新建文件夹 (12)/mifengguai_0003_MiFeng-tou4.png";
                bone_data[XMLTool::convertIntToString(1)] = "新建文件夹 (12)/mifengguai_0009_MiFeng-tou1.png";
                bone_data[XMLTool::convertIntToString(2)] = "新建文件夹 (12)/mifengguai_0004_MiFeng-tou3.png";
                bone_data[XMLTool::convertIntToString(3)] = "新建文件夹 (12)/mifengguai_0006_MiFeng-tou2.png";
                bee_low_data["Layer17"] = bone_data;
            }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "新建文件夹 (12)/mifengguai_0013_MiFeng-body.png";
                bee_low_data["Layer16"] = bone_data;
            }
            bee_bone_data["low"] = bee_low_data;
        }
        {
            cocos2d::ValueMap bee_low_data;
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "middle/mifengguai_0001_MiFeng-yanpi2.png";
                bee_low_data["Layer48"] = bone_data; }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "middle/mifengguai_0000_MiFeng-yanpi1.png";
                bee_low_data["Layer46"] = bone_data;
            }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "middle/mifengguai_0003_MiFeng-tou4.png";
                bone_data[XMLTool::convertIntToString(1)] = "middle/mifengguai_0009_MiFeng-tou1.png";
                bone_data[XMLTool::convertIntToString(2)] = "middle/mifengguai_0004_MiFeng-tou3.png";
                bone_data[XMLTool::convertIntToString(3)] = "middle/mifengguai_0006_MiFeng-tou2.png";
                bee_low_data["Layer17"] = bone_data;
            }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "middle/mifengguai_0013_MiFeng-body.png";
                bee_low_data["Layer16"] = bone_data;
            }
            bee_bone_data["middle"] = bee_low_data;
        }
        {
            cocos2d::ValueMap bee_high_data;
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "high/mifengguai_0001_MiFeng-yanpi2.png";
                bee_high_data["Layer48"] = bone_data; }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "high/mifengguai_0000_MiFeng-yanpi1.png";
                bee_high_data["Layer46"] = bone_data;
            }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "high/mifengguai_0003_MiFeng-tou4.png";
                bone_data[XMLTool::convertIntToString(1)] = "high/mifengguai_0009_MiFeng-tou1.png";
                bone_data[XMLTool::convertIntToString(2)] = "high/mifengguai_0004_MiFeng-tou3.png";
                bone_data[XMLTool::convertIntToString(3)] = "high/mifengguai_0006_MiFeng-tou2.png";
                bee_high_data["Layer17"] = bone_data;
            }
            {
                cocos2d::ValueMap bone_data;
                bone_data[XMLTool::convertIntToString(0)] = "high/mifengguai_0013_MiFeng-body.png";
                bee_high_data["Layer16"] = bone_data;
            }

            bee_bone_data["high"] = bee_high_data;
            score_widget_bone_data_["mifeng"] = bee_bone_data;
            cocos2d::FileUtils::getInstance()->writeValueMapToFile(score_widget_bone_data_, cocos2d::FileUtils::getInstance()->getWritablePath() + "scoreWidgetBoneData.plist");
        }*/

    }

    ScoreWidgetManager::~ScoreWidgetManager()
    {

    }

    void ScoreWidgetManager::clear()
    {
        for (auto iter_1 = score_widget_map_.begin(); iter_1 != score_widget_map_.end(); ++iter_1)
        {
            iter_1->second.clear();
        }
        widget_total_ = 0;
    }

    void ScoreWidgetManager::changeScoreWidgetArmatureDisplay(cocostudio::Armature* armature, const ScoreWidgetType& type)
    {
        for (auto var1: score_widget_bone_data_.at(armature->getName()).asValueMap().at(type_to_key_[type]).asValueMap())
        {
            for (auto var2 : var1.second.asValueMap())
            {
                armature->getBone(var1.first)->addDisplay(cocostudio::Skin::createWithSpriteFrameName(var2.second.asString()), XMLTool::convertStringToInt(var2.first));      
            }
        }
    }

    void ScoreWidgetManager::readBoneDateFromFile()
    {
        score_widget_bone_data_ = cocos2d::FileUtils::getInstance()->getValueMapFromFile(SCORE_WIDGET_BONE_DATA_PLIST_PATH);
    }

    cocostudio::Armature * ScoreWidgetManager::getWidgetUpdateArmature(const ScoreWidgetType type)
    {
        cocostudio::Armature* armature = cocostudio::Armature::create(SCORE_WIDGET_UPDATE_ANIMATION_NAME);
        if (type == kScoreWidgetHigh)
        {
            armature->getBone("Layer1")->addDisplay(cocostudio::Skin::createWithSpriteFrameName("mifengTX2_0011_fen-1.png"), 0);
            armature->getBone("Layer1")->addDisplay(cocostudio::Skin::createWithSpriteFrameName("mifengTX2_0010_fen-2.png"), 1);
            armature->getBone("Layer1")->addDisplay(cocostudio::Skin::createWithSpriteFrameName("mifengTX2_0009_fen-3.png"), 2);
            armature->getBone("Layer1")->addDisplay(cocostudio::Skin::createWithSpriteFrameName("mifengTX2_0008_fen-4.png"), 3);
        }
        return armature;
    }

    void ScoreWidgetManager::removeTwoScoreWidget()
    {
        //关闭用以测试
        int time = 0;
        //for (auto iter_1 = score_widget_vector_.begin(); iter_1 != score_widget_vector_.end(); ++iter_1)
        //{
        //    for (auto iter = iter_1->begin(); iter != iter_1->end(); )
        //    {
        //        if (time != SCORE_WIDGET_NOT_COMBO_NUMBLE)
        //        {
        //            (*iter)->removeScoreWidget();
        //            iter = iter_1->erase(iter);
        //            --widget_total_;
        //            ++time;
        //            continue;
        //        }
        //        return;   
        //    }
        //}
        for (auto var : widget_remove_sequence_)
        {
            for (auto iter = score_widget_map_[var].begin(); iter != score_widget_map_[var].end(); )
            {
                if (time != SCORE_WIDGET_NOT_COMBO_NUMBLE)
                {
                    (*iter)->removeScoreWidget();
                    iter = score_widget_map_[var].erase(iter);
                    this->cutWidgetTotal();
                    ++time;
                    continue;
                }
                return;
            }
        }
    }

    //void ScoreWidgetManager::addEventListenerCustom()
    //{
    //    cocos2d::EventDispatcher* dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();
    //    auto listener = cocos2d::EventListenerCustom::create(EVENT_MAP_LOADED, CC_CALLBACK_1(ScoreWidgetManager::clear, this));
    //    dispatcher->addEventListenerWithFixedPriority(listener, 1);
    //}

    ScoreWidget* ScoreWidgetManager::getNewScoreWidget()
    {
        if (widget_total_ < 6)
        {
            //++widget_total_;
            this->addWidgetTotal();
            const ScoreWidgetType& type = combo_to_type_[GameScoreController::getInstance()->getEliminateCombo()];
            ScoreWidget* widget = ScoreWidget::createWithType(type);
            widget->setSelfPosition(this->getScoreWidgetPosition());
            score_widget_map_[type].pushBack(widget);
            return widget;
        }
        else
        {
            //for (auto iter_1 = score_widget_vector_.begin(); iter_1 != --score_widget_vector_.end(); ++iter_1)
            //{//最高级的不用升级
            //    for (auto iter_2 = iter_1->begin(); iter_2 != iter_1->end(); ++iter_2)
            //    {
            //        ScoreWidget* widget = *iter_2;
            //        iter_1->erase(iter_2);              
            //        score_widget_vector_[widget->getType()].pushBack(widget);
            //        //先移动vector里面的元素在升级, 因为升级会初始化连击次数
            //        widget->updateScoreWidgetType();
            //        return nullptr;
            //    }
            //}
            ScoreWidget* widget = nullptr;
            for (auto var : widget_update_sequence_)
            {
                for (auto iter = score_widget_map_[var].begin(); iter != score_widget_map_[var].end(); ++iter)
                {
                    widget = *iter;
                    score_widget_map_.at(var).erase(iter);
                    widget->updateScoreWidgetType();
                    score_widget_map_.at(widget->getType()).pushBack(widget);
                    widget = nullptr;
                    return nullptr;
                }
            }
        }
        return nullptr;
    }

    //cocos2d::Vec2 ScoreWidgetManager::getScoreWidgetPositionWithVector(const cocos2d::Vector<cocos2d::Node*>& vector)
    //{
    //    int vector_size = vector.size();
    //    cocos2d::Vec2 point;
    //    int numble = 0;
    //    do
    //    {
    //        point = vector.at(cocos2d::random(0, vector_size - 1))->getPosition()
    //            + cocos2d::Vec2(cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS),
    //                cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS));
    //        ++numble;
    //    } while (this->isNearbyExistence(point)/* && numble < 999*/);
    //    return point;
    //}

    cocos2d::Vec2 ScoreWidgetManager::getScoreWidgetPosition()
    {
        int vector_size = this->getWidgetPointsSeed().size();
        cocos2d::Vec2 point;
        int numble = 0;
        do
        {
            point = this->getWidgetPointsSeed().at(cocos2d::random(0, vector_size - 1))->getPosition()
                + cocos2d::Vec2(cocos2d::random(-1 * SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS),
                    cocos2d::random(SCORE_WIDGET_POSITION_OFFS, SCORE_WIDGET_POSITION_OFFS*2));
            ++numble;
        } while (this->isNearbyExistence(point)/* && numble < 999*/);
        return point;
    }

    bool ScoreWidgetManager::isNearbyExistence(const cocos2d::Vec2& point)
    {
        bool borderFlag = this->isNearByBorder(point);
        if (borderFlag)
        {
            return true;
        }
        for (auto var_1 : score_widget_map_)
        {
            for (auto var_2 : var_1.second)
            {
                if (var_2->getSelfPosition().distance(point) < TWO_SCORE_WIDGET_DISTANCE)
                {    
                    return true;
                }
            }
        }
        return false;
    }

    bool ScoreWidgetManager::isNearByBorder(const cocos2d::Vec2 & point)
    {
        return (WIDGET_POSITION_RANGE_LEFT_MIN<point.x && point.x<WIDGET_POSITION_RANGE_LEFT_MAX) || (WIDGET_POSITION_RANGE_RIGHT_MIN<point.x && point.x<WIDGET_POSITION_RANGE_RIGHT_MAX);
    }

    void ScoreWidgetManager::addWidgetTotal()
    {
        ++widget_total_;
        //CCLOG("++widget: %d", widget_total_);
    }

    void ScoreWidgetManager::cutWidgetTotal()
    {
        --widget_total_;
        //CCLOG("--widget: %d", widget_total_);
    }

    int ScoreWidgetManager::getScoreWidgetTotal()
    {
        return widget_total_;
    }

    int ScoreWidgetManager::getScoreWidgetTotalWithType(const ScoreWidgetType& type)
    {
        return score_widget_map_[type].size();
    }

    void ScoreWidgetManager::setWidgetPointsSeed(WidgetPointsSeed seed)
    {
        widget_points_seed_ = seed;
    }

    WidgetPointsSeed ScoreWidgetManager::getWidgetPointsSeed()
    {
        return widget_points_seed_;
    }

    //const WidgetBonePathMap & ScoreWidgetManager::getWidgetBonePathMap()
    //{
    //    return bonename_to_map_;
    //}

}