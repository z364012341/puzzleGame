//*******************************************************************************
//类名称   : PuzzleStoreItemFactory
//功能     : <拼图购买界面listview的item工厂>
//-------------------------------------------------------------------------------
//备注     : <负责生成item>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _PUZZLE_STORE_ITEM_FACTORY_H_
#define _PUZZLE_STORE_ITEM_FACTORY_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class PuzzleStoreItemFactory
    {
    public:
        GETINSTANCE_FUNC(PuzzleStoreItemFactory);
        cocos2d::Node* createItemWithIndex(int index);
        cocos2d::Node* createGiftsItemWithIndex(int index);
        cocos2d::Node* createNewbieAlert();
        ~PuzzleStoreItemFactory();
        void loadItemData();
        int getItemTotal();
        int getGiftsItemTotal();
    private:
        PuzzleStoreItemFactory();
        void loadGiftData();
    private:
        cocos2d::ValueMap item_data_;
        cocos2d::ValueMap gifts_item_data_;

    };
}
#endif //PuzzleStoreItemFactory