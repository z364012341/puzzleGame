#ifndef _GAME_BUY_STORE_MANNAGER_H_
#define _GAME_BUY_STORE_MANNAGER_H_
#include "BubbleSecondConstant.h"
const int PUZZLE_NEWBIE_GIFT_TARGET_ID = 113;
namespace bubble_second {
    class GameBuyStoreMannager
    {
    public:
        GETINSTANCE_FUNC(GameBuyStoreMannager);
        ~GameBuyStoreMannager(); 
        void buyProps(int target);
        bool isBuyPuzzleNewbiwGift();
    private:
        GameBuyStoreMannager();
        void setCurrentPropsTarget(int target);
    private:
        int props_target_ = 0;
    };
}
#endif //
