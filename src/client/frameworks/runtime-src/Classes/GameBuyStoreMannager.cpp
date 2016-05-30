#include "GameBuyStoreMannager.h"
#include "GameJNIHelper.h"

namespace bubble_second {
    GameBuyStoreMannager::GameBuyStoreMannager()
    {
    }


    GameBuyStoreMannager::~GameBuyStoreMannager()
    {
    }

    void bubble_second::GameBuyStoreMannager::setCurrentPropsTarget(int target)
    {
        props_target_ = target;
    }
    void GameBuyStoreMannager::buyProps(int target)
    {
        GameJNIHelper::getInstance()->payWithTargetID(target);
        this->setCurrentPropsTarget(target);
    }
    bool GameBuyStoreMannager::isBuyPuzzleNewbiwGift()
    {
        return props_target_ == PUZZLE_NEWBIE_GIFT_TARGET_ID;
    }
}