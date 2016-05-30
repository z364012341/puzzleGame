#include "GameBubbleMapImple.h"
#include "XMLTool.h"
#include "ColorBubble.h"
#include "BubbleFactory.h"
#include "GameScene.h"
#include "BaseComponentBubble.h"
#include "BubbleComponent.h"
#include "GameScoreController.h"
#include "StageDataManager.h"
#include "BubbleColorRender.h"
const float WINDMILL_BUBBLE_ROTATION_FACTOR = 4000.0f; //风车转转转的速度系数
const int RECENTLY_BUBBLE_FIND_HIGH_PRIORITY_SEQUENCE[] = { 5, 4, 6, 3, 7};
const int RECENTLY_BUBBLE_FIND_LOW_PRIORITY_SEQUENCE[] = { 2, 8, 1, 9, 0, 10 };
const int RECENTLY_BUBBLE_FIND_INDEX_OFFSET = 4;
namespace bubble_second{
    GameBubbleMapImple::GameBubbleMapImple():special_bubble_(nullptr)
    {
        auto top_suspension_func = [=]() {
            cocos2d::Map<int, BaseBubble*> sprite_map;
            for (int i = -1; i != MAP_EVEN_ROW_MAX; i++)
            {
                BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(
                    kBubbleTransparent,
                    cocos2d::Vec2(i, MAP_TOP_ROW_INDEX),
                    this->convertIndexToPoint(cocos2d::Vec2(i, MAP_TOP_ROW_INDEX)));
                sprite_map.insert(i, bubble);
                this->addSuspensionPointToVector(bubble);
            }
            bubble_sprite_map_[MAP_TOP_ROW_INDEX] = sprite_map;
        };
        stagetype_to_handle_[kTopEliminate] = [=]() {
            top_suspension_func();
            GameScoreController::getInstance()->setGameTaskNumble(TOP_ELIMINATE_GAME_TASK_NUMBLE);
        };
        stagetype_to_handle_[kRescueAnimal] = [=]() {
            top_suspension_func();
        };
        stagetype_to_handle_[kDestroyRainbowSeal] = [=]() {
            top_suspension_func();
        };
        stagetype_to_handle_[kWindmill] = [=]() {
            this->setSpecialBubble();
        };
    }

    GameBubbleMapImple::~GameBubbleMapImple()
    {
    }

    BubbleSpriteMap GameBubbleMapImple::initBubbleSpriteVetctor(BubbleColorRender* render, const BubblesData& stage_info, const StageType& stage_type)
    {
        BaseBubble* bubble = nullptr;
        BubbleVector componentBubbles;
        for (auto var: stage_info)
        {
            bubble = this->convertBubbleDataToBubble(render, var);
            if (bubble)
            {
                this->addBubbleToBubbleMap(bubble);
                if (bubble->getBubbleComponentNumble() != 0)
                {
                    //this->addBubbleComponentByBubble(bubble);
                    componentBubbles.pushBack(bubble);
                }
                this->disposeAddSuspensionPoint(bubble);
            }
        }
        for (auto var : componentBubbles)
        {
            this->addBubbleComponentByBubble(var);
        }
        this->stageTypeFunc(stage_type);
        return bubble_sprite_map_;        
    }

    void GameBubbleMapImple::stageTypeFunc(const StageType& stage_type)
    {
        //auto handle = stagetype_to_handle_[stage_type];
        if (auto handle = stagetype_to_handle_[stage_type])
        {
            handle();
        }
    }

    BaseBubble* GameBubbleMapImple::convertBubbleDataToBubble(BubbleColorRender* render, const BubbleInfo& info)
    {
        XMLTool* tool= new XMLTool;
        int type = tool->convertStringToInt(info.at(STAGE_XML_FIELDS_BUBBLETYPE));
        type = render->getRandomColorWithColor((BubbleType)type);
        int row = tool->convertStringToInt(info.at(STAGE_XML_FIELDS_ROW));
        int col = tool->convertStringToInt(info.at(STAGE_XML_FIELDS_COL));
        int cloud = tool->convertStringToInt(info.at(STAGE_XML_FIELDS_CLOUD));
        BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(type, cocos2d::Vec2(col, row),
            this->convertIndexToPoint(cocos2d::Vec2(col, row)), cloud);
        CC_SAFE_DELETE(tool);
        return bubble;
    }

    void GameBubbleMapImple::disposeAddSuspensionPoint(BaseBubble* bubble)
    {
        if (bubble->isSuspensionPoint())
        {
            this->addSuspensionPointToVector(bubble);
        }
    }

    void GameBubbleMapImple::disposeRemoveSuspensionPoint(BaseBubble* bubble)
    {
        if (bubble->isSuspensionPoint())
        {
            this->removeSuspensionPointFromVector(bubble);
        }
    }

    void GameBubbleMapImple::addSuspensionPointToVector(BaseBubble* bubble)
    {
        suspension_points_.pushBack(bubble);
    }

    void GameBubbleMapImple::removeSuspensionPointFromVector(BaseBubble* bubble)
    {
        suspension_points_.eraseObject(bubble);
    }

    cocos2d::Vec2 GameBubbleMapImple::convertIndexToPoint(const cocos2d::Vec2& index)
    {
        int row = index.y;
        int col = index.x;
        float posX = (abs(row) % 2 + 1) * (MAP_BUBBLE_RADIUS)+col * MAP_BUBBLE_RADIUS * 2;
        float posY = 0 - MAP_BUBBLE_RADIUS - row * (MAP_BUBBLE_RADIUS  * SQRT3);
        return cocos2d::Vec2(posX, posY);
    }

    int bubble_second::GameBubbleMapImple::getColFactorWithIndex(const cocos2d::Vec2 & index)
    {
        return abs((int)index.y % 2);
    }

    cocos2d::Vec2 GameBubbleMapImple::getUpLeftIndex(const cocos2d::Vec2& index)
    {
        return cocos2d::Vec2(index.x + getColFactorWithIndex(index) - 1, index.y - 1);
    }

    cocos2d::Vec2 bubble_second::GameBubbleMapImple::getLeftIndex(const cocos2d::Vec2 & index)
    {
        return cocos2d::Vec2(index.x - 1, index.y);
    }

    cocos2d::Vec2 bubble_second::GameBubbleMapImple::getBottomLeftIndex(const cocos2d::Vec2 & index)
    {
        return cocos2d::Vec2(index.x + getColFactorWithIndex(index) - 1, index.y + 1);
    }

    cocos2d::Vec2 bubble_second::GameBubbleMapImple::getBottomRightIndex(const cocos2d::Vec2 & index)
    {
        return cocos2d::Vec2(index.x + getColFactorWithIndex(index), index.y + 1);
    }

    cocos2d::Vec2 bubble_second::GameBubbleMapImple::getRightIndex(const cocos2d::Vec2 & index)
    {
        return cocos2d::Vec2(index.x + 1, index.y);
    }

    cocos2d::Vec2 bubble_second::GameBubbleMapImple::getUpRightIndex(const cocos2d::Vec2 & index)
    {
        return cocos2d::Vec2(index.x + getColFactorWithIndex(index), index.y - 1);
    }

    BubbleIndexVector GameBubbleMapImple::getAroundIndexWithIndex(const cocos2d::Vec2& index)
    {
        if (isWindmillStage())
        {
            return getAroundIndexWithIndexWithoutCondition(index);
        }
        using cocos2d::Vec2;
        BubbleIndexVector index_vector;
        int special = getColFactorWithIndex(index);
        if (special != 0 || index.x != 0.0f)
        {
            index_vector.push_back(getUpLeftIndex(index));//左上
            if (special != 1 || index.x != 0.0f)
            {
                index_vector.push_back(getLeftIndex(index));//左
            }
            index_vector.push_back(getBottomLeftIndex(index));//左下
        }

        if (special != 0 || index.x != MAP_EVEN_ROW_MAX - 1)
        {
            index_vector.push_back(getBottomRightIndex(index));//右下
            if (special != 1 || index.x != MAP_ODD_ROW_MAX - 1)
            {
                index_vector.push_back(getRightIndex(index));//右
            }
            index_vector.push_back(getUpRightIndex(index));//右上
        }
        return index_vector;
    }

    BubbleIndexVector GameBubbleMapImple::getAroundIndexWithIndexWithoutCondition(const cocos2d::Vec2 & index)
    {
        using cocos2d::Vec2;
        BubbleIndexVector index_vector;
        //int special = getColFactorWithIndex(index);
        index_vector.push_back(getUpLeftIndex(index));//左上
        index_vector.push_back(getLeftIndex(index));//左
        index_vector.push_back(getBottomLeftIndex(index));//左下
        index_vector.push_back(getBottomRightIndex(index));//右下
        index_vector.push_back(getRightIndex(index));//右
        index_vector.push_back(getUpRightIndex(index));//右上
        return index_vector;
    }

    BubbleIndexVector GameBubbleMapImple::getSecondAroundIndexWithIndex(const cocos2d::Vec2& index)
    {
        using cocos2d::Vec2;
        //int special = getColFactorWithIndex(index);
        BubbleIndexVector index_vector;
        index_vector.push_back(getUpLeftIndex(getUpLeftIndex(index))); //左上左上
        index_vector.push_back(getLeftIndex(getUpLeftIndex(index))); //左上左
        index_vector.push_back(getLeftIndex(getLeftIndex(index))); //左左
        index_vector.push_back(getBottomLeftIndex(getLeftIndex(index))); //左左下
        index_vector.push_back(getBottomLeftIndex(getBottomLeftIndex(index))); //左下左下
        index_vector.push_back(getBottomLeftIndex(getBottomRightIndex(index))); //下下
        index_vector.push_back(getBottomRightIndex(getBottomRightIndex(index))); //右下右下
        index_vector.push_back(getRightIndex(getBottomRightIndex(index))); //右下右
        index_vector.push_back(getRightIndex(getRightIndex(index))); //右右
        index_vector.push_back(getRightIndex(getUpRightIndex(index))); //右上右
        index_vector.push_back(getUpRightIndex(getUpRightIndex(index))); //右上右上
        index_vector.push_back(getUpRightIndex(getUpLeftIndex(index))); //上上
        return index_vector;
    }

    BubbleIndexVector GameBubbleMapImple::getUnderTwoIndexByIndex(const cocos2d::Vec2& index)
    {
        using cocos2d::Vec2;
        BubbleIndexVector index_vector;
        int special = getColFactorWithIndex(index);
        if (special != 0 || index.x != 0.0)
        {
            index_vector.push_back(getBottomLeftIndex(index));//左下
        }
        if (special != 0 || index.x != MAP_EVEN_ROW_MAX - 1)
        {
            index_vector.push_back(getBottomRightIndex(index));//右下
        }
        return index_vector;
    }

    cocos2d::Vec2 GameBubbleMapImple::convertGameSceneCsbToMapSpaceWithBubble(cocos2d::Node* bubble)
    {
        GameScene* gamescene = nullptr;
        cocos2d::Node* parent = bubble->getParent();
        while (1)
        {
            if (gamescene = dynamic_cast<GameScene*>(parent))
            {
                break;
            }
            else
            {
                parent = parent->getParent();
            }
        }
        //GameScene* gamescene = dynamic_cast<GameScene*>(bubble->getParent()->getParent());
        return gamescene->convertCsbToMapSpace(bubble->getPosition());
    }

    cocos2d::Vec2 GameBubbleMapImple::convertGameSceneMapToCsbSpaceWithBubble(cocos2d::Node* bubble)
    {
        GameScene* gamescene = dynamic_cast<GameScene*>(bubble->getParent()->getParent()->getParent());
        return gamescene->convertMapToCsbSpace(bubble->getPosition());
    }

    BubbleIndexVector GameBubbleMapImple::getComponentIndexByIndexAndNumble(const cocos2d::Vec2& index, int numble)
    {
        BubbleIndexVector index_vector(0);
        switch (numble)
        {
        case 2:
            index_vector = this->getUnderTwoIndexByIndex(index);
            break;
        case 6:
            index_vector = this->getAroundIndexWithIndex(index);
            break;
        default:
            assert(false);
            break;
        }
        return index_vector;
    }

    BubbleIndexVector GameBubbleMapImple::getTwoAroundIndexWithIndex(const cocos2d::Vec2& index)
    {
        using cocos2d::Vec2;
        BubbleIndexVector first_vector = this->getAroundIndexWithIndex(index);
        //std::vector<Vec2> second_vector = this->getSecondAroundIndexWithIndex(index);
        for (auto var : this->getSecondAroundIndexWithIndex(index))
        {
            first_vector.push_back(var);
        }
        return first_vector;
    }

    BubbleVector GameBubbleMapImple::getAroundBubbleWithIndex(const cocos2d::Vec2& index)
    {
        return this->getBubbleVectorWithIndexVector(this->getAroundIndexWithIndex(index));
    }

    BubbleVector GameBubbleMapImple::getAroundBubbleExceptComponentWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector vector = this->getAroundBubbleWithIndex(index);
        for (auto iter = vector.begin(); iter < vector.end();)
        {
            if ((*iter)->isComponentBubbleType())
            {
                iter = vector.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
        return vector;
    }

    BubbleVector GameBubbleMapImple::getAroundComponentBubbleWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector vector = this->getAroundBubbleWithIndex(index);
        for (auto iter = vector.begin(); iter < vector.end();)
        {
            if (!(*iter)->isComponentBubbleType())
            {
                iter = vector.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
        return vector;
    }

    BubbleVector GameBubbleMapImple::getTwoAroundBubbleWithIndex(const cocos2d::Vec2 & index)
    {
        return this->getBubbleVectorWithIndexVector(this->getTwoAroundIndexWithIndex(index));
    }

    BubbleVector GameBubbleMapImple::getAroundColorBubblesWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector around_color_bubble;
        for (auto var : this->getAroundBubbleWithIndex(index))
        {
            if (var->isColorBubbleType() || var->isEqualType(kBubbleBlackHole))
            {
                around_color_bubble.pushBack(var);
            }
        }
        return around_color_bubble;
    }

    BubbleVector GameBubbleMapImple::getAroundSametypeBubbleWithIndexAndType(const cocos2d::Vec2& index)
    {
        BubbleVector same_bubble_vector;
        BaseBubble* bubble = this->getSpriteWithIndex(index);
        for (auto iter : this->getAroundBubbleWithIndex(index))
        {
            if (bubble->isEqualType(iter->getBubbleType()))
            {
                same_bubble_vector.pushBack(iter);
            }
        }
        return same_bubble_vector;
    }

    BubbleVector GameBubbleMapImple::getSametypeBubbleWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector same_vector;
        same_vector.pushBack(this->getSpriteWithIndex(index));
        this->traverseBubbles(&same_vector, CC_CALLBACK_1(GameBubbleMapImple::getAroundSametypeBubbleWithIndexAndType, this));
        return same_vector;
    }

    BaseBubble* GameBubbleMapImple::getSpriteWithIndex(const cocos2d::Vec2& index)
    {
        return bubble_sprite_map_[index.y].at(index.x);
    }

    BaseBubble* GameBubbleMapImple::clingBubble(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index)
    {
        //cocos2d::Vec2 bubble_should_index = this->getTheNearestEmptyIndex(this->convertGameSceneCsbToMapSpaceWithBubble(prepare_bubble),
        //    contact_index);
        //assert(bubble_sprite_map_[bubble_should_index.y].at(bubble_should_index.x) == nullptr);
        //BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(prepare_bubble->getBubbleType(),
        //    bubble_should_index, this->convertIndexToPoint(bubble_should_index));
        //bubble_sprite_map_;
        BaseBubble* bubble = this->preclingBubble(prepare_bubble, contact_index);
        this->addBubbleToBubbleMap(bubble);
        return bubble;
    }

    BaseBubble* GameBubbleMapImple::preclingBubble(BaseBubble * prepare_bubble, const cocos2d::Vec2 & contact_index)
    {
        cocos2d::Vec2 bubble_pos = prepare_bubble->getParent()->getName() == UI_NAME_GAME_PLAY_AREA_NODE ? this->convertGameSceneCsbToMapSpaceWithBubble(prepare_bubble) : prepare_bubble->getPosition();
        cocos2d::Vec2 bubble_should_index = this->getTheNearestEmptyIndex(bubble_pos, contact_index);
        assert(bubble_sprite_map_[bubble_should_index.y].at(bubble_should_index.x) == nullptr);
        BaseBubble* bubble = BubbleFactory::getInstance()->createBubbleWithType(prepare_bubble->getBubbleType(),
            bubble_should_index, this->convertIndexToPoint(bubble_should_index));
        prepare_bubble->setBubbleIndex(bubble_should_index);
        return bubble;
    }

    void GameBubbleMapImple::removeSpriteFromeMap(const BubbleVector& vector)
    {
        for (auto var : vector)
        {
            this->removeSpriteFromeMapWithIndex(var->getBubbleIndex());
        }
    }

    void GameBubbleMapImple::removeSpriteFromeMapWithIndex(const cocos2d::Vec2& index)
    {
        bubble_sprite_map_[index.y].erase(index.x);
    }

    std::vector<cocos2d::Vec2> GameBubbleMapImple::getAroundEmptyIndexWithIndex(const cocos2d::Vec2& index)
    {
        std::vector<cocos2d::Vec2> index_vector = this->getAroundIndexWithIndex(index);
        for (auto iter = index_vector.begin(); iter != index_vector.end();)
        {
            if (bubble_sprite_map_[iter->y].at(iter->x))
            {
                iter = index_vector.erase(iter);
                continue;
            }
            ++iter;
        }
#if (COCOS2D_DEBUG > 0)
        for (auto var : index_vector)
        {
            assert(bubble_sprite_map_[var.y].at(var.x) == nullptr);
        }
#endif
        return index_vector;
    }

    BubbleVector GameBubbleMapImple::getBubbleVectorWithIndexVector(const BubbleIndexVector& index_vector)
    {
        cocos2d::Vector<BaseBubble*> vector;
        BaseBubble* basebubble = nullptr;
        for (auto iter : index_vector)
        {
            basebubble = this->getSpriteWithIndex(iter);
            if (basebubble)
            {
                vector.pushBack(basebubble);
            }
        }
        return vector;
    }

    cocos2d::Vec2 GameBubbleMapImple::getTheNearestEmptyIndex(const cocos2d::Vec2& point, const cocos2d::Vec2& index)
    {
        std::vector<cocos2d::Vec2> index_vector = this->getAroundEmptyIndexWithIndex(index);
        return this->getIndexMindistanceWithVector(point, index_vector);
    }

    cocos2d::Vec2 GameBubbleMapImple::getIndexMindistanceWithVector(const cocos2d::Vec2& point, 
        const std::vector<cocos2d::Vec2>& index_vector)
    {
        cocos2d::Vec2 nearest_index = index_vector.at(0);
        float distance = point.distance(index_vector.at(0));
        float compare_distance = 0;
        for (auto iter : index_vector)
        {
            compare_distance = point.distance(this->convertIndexToPoint(iter));
            if (compare_distance < distance)
            {
                nearest_index = iter;
                distance = compare_distance;
            }
        }
        //assert(bubble_sprite_map_[nearest_index.y].at(nearest_index.x) == nullptr);
        return nearest_index;
    }

    void GameBubbleMapImple::addBubbleToBubbleMap(BaseBubble* bubble)
    {
        cocos2d::Vec2 index = bubble->getBubbleIndex();
        bubble_sprite_map_[index.y].insert(index.x, bubble);
		//bubble_sprite_map_[index.x][index.y] = bubble;
    }

    void GameBubbleMapImple::addBubbleComponentByBubble(BaseBubble* bubble)
    {
        int component_numble = bubble->getBubbleComponentNumble();
        if (component_numble == 0)
        {
            return;
        }
        BaseComponentBubble* component_bubble = dynamic_cast<BaseComponentBubble*>(bubble);
        BubbleIndexVector index_vector = this->getComponentIndexByIndexAndNumble(bubble->getBubbleIndex(), component_numble);
        for (int i = 0; i < component_numble; i++)
        {
            BubbleComponent* component = BubbleComponent::createWithCore(bubble);
            auto index = index_vector.at(i);
            component->setBubbleIndex(index);
            component->setPosition(this->convertIndexToPoint(index));
            component_bubble->addBubbleComponent(component);
            this->addBubbleToBubbleMap(component);
        }
    }

    BubbleVector GameBubbleMapImple::disposeAirBubbleAfterEliminate()
    {
        BubbleVector vector = this->getInTheAirBubbles();
        this->removeSpriteFromeMap(vector);
        return vector;
    }

    BubbleVector GameBubbleMapImple::getNotInTheAirBubbles()
    {
        BubbleVector vector;
        cocos2d::Vec2 vec2;
        for (auto var : suspension_points_)
        {
            vec2 = var->getBubbleIndex();
            vector.pushBack(var);
        }
        this->traverseBubbles(&vector, CC_CALLBACK_1(GameBubbleMapImple::getAroundBubbleWithIndex, this));
        return vector;
    }

    BubbleVector GameBubbleMapImple::getInTheAirBubbles()
    {
        BubbleVector not_air_vector = this->getNotInTheAirBubbles();
        BubbleVector air_vector;
        for (auto var_1 : bubble_sprite_map_)
        {
            for (auto var_2 : var_1.second)
            {
                if (this->isExistInVector(not_air_vector, var_2.second))
                {
                    continue;
                }
                air_vector.pushBack(var_2.second);
            }
        }
        return air_vector;
    }

    void GameBubbleMapImple::traverseBubbles(BubbleVector* seed,
        std::function<BubbleVector(const cocos2d::Vec2& index)> func)
    {
        int map_size = 0;
        do
        {//有配套流程图
            map_size = seed->size();
            BubbleVector map_clone = *seed;
            for (auto iter_1 : map_clone)
            {
                this->mergeTwoBubbleVector(seed, func(iter_1->getBubbleIndex()));
            } //for (auto iter_1 : map_clone)
        } while (map_size != seed->size());
    }

    bool GameBubbleMapImple::isExistInVector(const BubbleVector& vector, BaseBubble* bubble)
    {
        auto iter = std::find(vector.begin(), vector.end(), bubble);
        return iter != vector.end();
    }

    BubbleVector GameBubbleMapImple::getAllBubblesFromMap()
    {
        BubbleVector vector(0);
        for (auto row_var : bubble_sprite_map_)
        {
            for (auto col_var : row_var.second)
            {
                if (col_var.second->getBubbleType() != kBubbleTransparent)
                {
                    vector.pushBack(col_var.second);
                }
            }
        }
        return vector;
    }

    BubbleVector GameBubbleMapImple::separateWindmillBubble()
    {
        BubbleVector vector(0);
        BaseBubble* bubble = nullptr;
        for (auto row_var : bubble_sprite_map_)
        {
            for (auto col_var : row_var.second)
            {
                if (col_var.second->getBubbleType() != kBubbleWindmill)
                {
                    vector.pushBack(col_var.second);
                }
                else
                {
                    bubble = col_var.second;
                }
            }
        }
        vector.insert(0, bubble);
        return vector;
    }

    float GameBubbleMapImple::getWindmillRotationAngle(BaseBubble* prepare_bubble)
    {
        float angle = getWindmillContactVelocity(prepare_bubble)/ WINDMILL_BUBBLE_ROTATION_FACTOR; //切线的速度
        return angle;
    }

    int GameBubbleMapImple::getWindmillRotationDirection(const cocos2d::Vec2 & bubble_speed, const cocos2d::Vec2& to_center_speed)
    {
        int direction = 0;
        if ((to_center_speed.x < 0 && to_center_speed.y>0) && (bubble_speed.x > 0 && bubble_speed.y>0) ||
            (to_center_speed.x > 0 && to_center_speed.y>0) && (bubble_speed.x > 0 && bubble_speed.y<0) || 
            (to_center_speed.x > 0 && to_center_speed.y<0) && (bubble_speed.x < 0 && bubble_speed.y<0) || 
            (to_center_speed.x < 0 && to_center_speed.y<0) && (bubble_speed.x < 0 && bubble_speed.y>0))
        {
            direction = 1;
        }
        else
        {
            direction = -1;
        }
        return direction;
    }

    float GameBubbleMapImple::getWindmillContactVelocity(BaseBubble * prepare_bubble)
    {
        cocos2d::Vec2 windmill_pos = this->convertGameSceneMapToCsbSpaceWithBubble(this->getSpecialBubble());
        cocos2d::Vec2 bubble_pos = this->convertGameSceneMapToCsbSpaceWithBubble(prepare_bubble);

        cocos2d::Vec2 contact_vector = bubble_pos - windmill_pos;    //指向圆心的向量
        cocos2d::Vec2 bubble_speed = dynamic_cast<ColorBubble*>(prepare_bubble)->getBubbleSpeed();  //小球速度向量
        cocos2d::Vec2 circle_line_speed = contact_vector.rotateByAngle(cocos2d::Vec2::ZERO, CC_DEGREES_TO_RADIANS(90.0f)).getNormalized(); //切线向量
        float r = bubble_pos.getDistance(windmill_pos); //半径
        cocos2d::Vec2 line_vector_project = bubble_speed.project(circle_line_speed); //切线速度分量
        float line_speed = line_vector_project.length(); //求模
        return  line_speed * getWindmillRotationDirection(line_vector_project, contact_vector)*r;
    }

    void GameBubbleMapImple::mergeTwoBubbleVector(BubbleVector* first_vector, 
        const BubbleVector& second_vector)
    {
        first_vector->pushBack(this->getDifferentInTwoBubbleVector(*first_vector, second_vector));
    }

    BubbleVector GameBubbleMapImple::getDifferentInTwoBubbleVector(const BubbleVector& first_vector,
        const BubbleVector& second_vector)
    {
        BubbleVector different_vector;
        for (auto iter_2 : second_vector)
        {
            if (this->isExistInVector(first_vector, iter_2))
            {
                continue;
            }
            different_vector.pushBack(iter_2);
        }
        return different_vector;
    }

    BubbleVectorMap GameBubbleMapImple::getEffectBubbles(BaseBubble* prepare_bubble, const cocos2d::Vec2& contact_index)
    {
        BaseBubble* bubble = getSpriteWithIndex(contact_index);
        if (!bubble)
        {
            return BubbleVectorMap();
        }
        assert(bubble);
        //cocos2d::Vec2 pre_convert_pos = this->convertGameSceneCsbToMapSpaceWithBubble(prepare_bubble);
        cocos2d::Vec2 pre_convert_pos = prepare_bubble->getPosition();;
        cocos2d::Vec2 nearest_index = this->getIndexNearestContactBubble(pre_convert_pos, contact_index);
        BubbleVector contact_around = this->getAroundBubbleWithIndex(contact_index);
        BubbleVector nearest_around = this->getAroundBubbleWithIndex(nearest_index);
        BubbleVector long_bubbles;
        long_bubbles.pushBack(this->getSpriteWithIndex(contact_index));
        BaseBubble* nearest_bubble = this->getSpriteWithIndex(nearest_index);
        if (nearest_bubble != nullptr)
        {
            long_bubbles.pushBack(nearest_bubble);
        }
        BubbleVectorMap effect_bubbles;
        effect_bubbles[LONG_EFFECT_BUBBLE_KEY] = long_bubbles;
        BubbleVector short_bubbles;
        short_bubbles.pushBack(this->getDifferentInTwoBubbleVector(long_bubbles, contact_around));
        short_bubbles.pushBack(this->getDifferentInTwoBubbleVector(long_bubbles, nearest_around));
        effect_bubbles[SHORT_EFFECT_BUBBLE_KEY] = short_bubbles;
        BubbleVector prepare_vector;
        prepare_vector.pushBack(prepare_bubble);
        effect_bubbles[PREPARE_EFFECT_BUBBLE_KEY] = prepare_vector;
        return effect_bubbles;
    }

    cocos2d::Vec2 GameBubbleMapImple::getIndexNearestContactBubble(const cocos2d::Vec2& prepare_point,
        const cocos2d::Vec2& contact_index)
    {
        std::vector<cocos2d::Vec2> around_index = this->getAroundIndexWithIndex(contact_index);
        return this->getIndexMindistanceWithVector(prepare_point, around_index);
    }

    BubbleVector GameBubbleMapImple::getSameYBubblesWithIndex(const cocos2d::Vec2& index)
    {
        cocos2d::Map<int, BaseBubble*> row_map = bubble_sprite_map_[index.y];
        BubbleVector same_row_bubbles;
        for (auto iter = row_map.begin(); iter != row_map.end(); ++iter)
        {                              
            same_row_bubbles.pushBack(iter->second);
        }
        return same_row_bubbles;
    }

    cocos2d::Vector<ColorBubble*> GameBubbleMapImple::getAroundDarkCloudBubbleWithIndex(const cocos2d::Vec2& index)
    {
        BubbleVector around_bubbles = this->getAroundBubbleWithIndex(index);
        cocos2d::Vector<ColorBubble*> cloud_bubbles;
        for (auto var : around_bubbles)
        {
            ColorBubble* colorbubble = dynamic_cast<ColorBubble*>(var);
            if (colorbubble && colorbubble->isDarkCloudBubble())
            {
                cloud_bubbles.pushBack(colorbubble);
            }
        }
        return cloud_bubbles;
    }

    float GameBubbleMapImple::getBubblesMinPosition()
    {
        return this->convertIndexToPoint(cocos2d::Vec2(0, this->getBubblesMinIndexY())).y;
    }

    int GameBubbleMapImple::getBubblesMinIndexY()
    {
        for (int i = bubble_sprite_map_.size() + MAP_TOP_ROW_INDEX - 1; i != MAP_TOP_ROW_INDEX; i--)
        {
            if (bubble_sprite_map_[i].size() != 0)
            {
                return i;
            }
        }
        return MAP_TOP_ROW_INDEX;
    }

    BaseBubble * GameBubbleMapImple::getBubbleMinCenter()
    {
        int min_index_y = this->getBubblesMinIndexY();
        for (int i = 0; i < RECENTLY_BUBBLE_FIND_INDEX_OFFSET; i++)
        {
            for (auto index_x : RECENTLY_BUBBLE_FIND_HIGH_PRIORITY_SEQUENCE)
            {
                if (bubble_sprite_map_[min_index_y - i].at(index_x) != nullptr && bubble_sprite_map_[min_index_y - i].at(index_x)->getBubbleType() != kBubbleTransparent)
                {
                    return bubble_sprite_map_[min_index_y - i].at(index_x);
                }
            }
        }
        for (int i = 0; i < RECENTLY_BUBBLE_FIND_INDEX_OFFSET; i++)
        {
            for (auto index_x : RECENTLY_BUBBLE_FIND_LOW_PRIORITY_SEQUENCE)
            {
                if (bubble_sprite_map_[min_index_y - i].at(index_x) != nullptr && bubble_sprite_map_[min_index_y - i].at(index_x)->getBubbleType() != kBubbleTransparent)
                {
                    return bubble_sprite_map_[min_index_y - i].at(index_x);
                }
            }
        }
        return nullptr;
    }

    //BaseBubble * GameBubbleMapImple::getBubbleMinCenterWithIndexs(const int* indexs)
    //{
    //    int min_index_y = this->getBubblesMinIndexY();

    //    for (int i = 0; i < RECENTLY_BUBBLE_FIND_INDEX_OFFSET; i++)
    //    {
    //        for (size_t i = 0; i < sizeof(indexs)/sizeof(int); i++)
    //        {
    //            if (bubble_sprite_map_[min_index_y - i].at(indexs[i]) != nullptr && bubble_sprite_map_[min_index_y - i].at(indexs[i])->getBubbleType() != kBubbleTransparent)
    //            {
    //                return bubble_sprite_map_[min_index_y - i].at(indexs[i]);
    //            }
    //        }
    //    }
    //    return nullptr;
    //}

    BubbleVector GameBubbleMapImple::getBubblesInVisibleSize()
    {
        BubbleVector bubbles(0);
        int line_numble = 0;
        for (int i = bubble_sprite_map_.size(); i != MAP_TOP_ROW_INDEX && line_numble<MAP_MAX_ROW_IN_SCREEN; i--)
        {
            cocos2d::Map<int, BaseBubble*> map = bubble_sprite_map_[i];
            if (map.size() != 0)
            {
                for (auto iter : map)
                {
                    bubbles.pushBack(iter.second);
                }
                line_numble++;
            }
        }
        return bubbles;
    }

    BubbleVector bubble_second::GameBubbleMapImple::getSameBubblesInVisibleSize(BubbleType color)
    {
        BubbleVector bubbles = this->getBubblesInVisibleSize();
        for (auto iter = bubbles.begin(); iter < bubbles.end(); )
        {
            if (color != (*iter)->getBubbleType())
            {
                iter = bubbles.erase(iter);
                continue;
            }
            ++iter;
        }
        return bubbles;
    }

    int GameBubbleMapImple::getTopRowNullBubbleNumble()
    {
        return MAP_EVEN_ROW_MAX - bubble_sprite_map_[0].size();
    }

    void GameBubbleMapImple::setSpecialBubble()
    {
        for (auto var_row : bubble_sprite_map_)
        {
            for (auto var_col : var_row.second)
            {
                if (var_col.second->isWindmillBubble())
                {
                    special_bubble_ = var_col.second;
                    break;
                }
            }
        }
    }

    BaseBubble* GameBubbleMapImple::getSpecialBubble()
    {
        return special_bubble_;
    }

    void GameBubbleMapImple::setStageType(const StageType & type)
    {
        stage_type_ = type;
    }

    StageType GameBubbleMapImple::getStageType()
    {
        return stage_type_;
    }

    bool GameBubbleMapImple::isWindmillStage()
    {
        return this->getStageType() == kWindmill;
    }

    void GameBubbleMapImple::setFallFlag(bool flag)
    {
        is_fall_type_ = flag;
    }

    bool GameBubbleMapImple::isFallStage()
    {
        return is_fall_type_;
    }
    std::vector<cocos2d::Vec2> GameBubbleMapImple::getFirstRowPositions()
    {
        std::vector<cocos2d::Vec2> points;
        for (size_t i = 0; i < MAP_EVEN_ROW_MAX; i++)
        {
            points.push_back(this->convertIndexToPoint(cocos2d::Vec2(i, 0)));
        }
        return points;
    }
}