//*******************************************************************************
//������   : PuzzleStoreItemFactory
//����     : <ƴͼ�������listview��item����>
//-------------------------------------------------------------------------------
//��ע     : <��������item>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
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