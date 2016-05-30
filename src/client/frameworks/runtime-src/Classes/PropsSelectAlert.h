//*******************************************************************************
//������   : NullBubble
//����     : <��Ϊ�յĲ��ɼ�Ҳ��������������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _PROPS_SELECT_ALERT_H_
#define _PROPS_SELECT_ALERT_H_
#include "cocos2d.h"
namespace bubble_second {
    class PropsSelectAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(PropsSelectAlert);
        ~PropsSelectAlert();
    private:
        PropsSelectAlert();
        bool init();
        void initPannel();
    };
}
#endif //_PROPS_SELECT_ALERT_H_