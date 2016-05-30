//*******************************************************************************
//������   : BombBombProperty
//����     : <����ը������, һըը��Ȧ>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BOMB_BOMB_PROPERTY_H_
#define _BOMB_BOMB_PROPERTY_H_
#include "BaseProperty.h"
namespace bubble_second {
    class BombBombProperty : public BaseProperty
    {
    public:
        CREATE_FUNC(BombBombProperty);
        ~BombBombProperty();
    protected:
        void useItem() override;
        void cancelUseItem() override;
    private:
        BombBombProperty();
        bool init();
    };
}
#endif //_BOMB_BOMB_PROPERTY_H_