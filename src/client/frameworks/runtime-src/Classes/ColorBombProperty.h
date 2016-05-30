//*******************************************************************************
//������   : ColorBombProperty
//����     : <���������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _COLOR_BOMB_PROPERTY_H_
#define _COLOR_BOMB_PROPERTY_H_
#include "cocos2d.h"
#include "BaseProperty.h"
namespace bubble_second {
    class ColorBombProperty : public BaseProperty
    {
    public:
        CREATE_FUNC(ColorBombProperty);
        ~ColorBombProperty();
    protected:
        void useItem() override;
        void cancelUseItem() override;
        bool init();
        //void haveUsedProperty(cocos2d::EventCustom*) override; 
    private:
        //void haveUsedColorBombBubble(cocos2d::EventCustom*);
    private:
        ColorBombProperty();

    };
}
#endif //_COLOR_BOMB_PROPERTY_H_