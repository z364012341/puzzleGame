//*******************************************************************************
//������   : WoodenHammerProperty
//����     : <Сľ������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _WOODEN_HAMMER_PROPERTY_H_
#define _WOODEN_HAMMER_PROPERTY_H_
#include "BaseProperty.h"
namespace bubble_second {
    class WoodenHammerProperty : public BaseProperty
    {
    public:
        CREATE_FUNC(WoodenHammerProperty);
        ~WoodenHammerProperty();
    protected:
        void useItem() override;
        void cancelUseItem() override;
    private:
        WoodenHammerProperty();
        bool init();
    };
}
#endif //_WOODEN_HAMMER_PROPERTY_H_