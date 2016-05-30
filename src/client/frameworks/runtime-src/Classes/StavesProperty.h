//*******************************************************************************
//������   : StavesProperty
//����     : <���ȵ���>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _STAVES_PROPERTY_H_
#define _STAVES_PROPERTY_H_
#include "BaseProperty.h"
namespace bubble_second {
    class StavesProperty : public BaseProperty
    {
    public:
        ~StavesProperty();
        CREATE_FUNC(StavesProperty);
    protected:
        void useItem() override;
        void cancelUseItem() override;
    private:
        StavesProperty();
        bool init();
    };
}
#endif //_STAVES_PROPERTY_H_