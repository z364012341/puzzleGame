//*******************************************************************************
//������   : BubbleFactory
//����     : <���ݹ�����..���𴴽��������ݵ�ʵ��������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BUBBLE_FACTORY_H_
#define _BUBBLE_FACTORY_H_
#include "BaseBubble.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class ColorBubble;
    class BubbleFactory
    {
    public:
        GETINSTANCE_FUNC(BubbleFactory);
        //�����������������������������
        BaseBubble* createBubbleWithType(int type, int cloud=-1);
        BaseBubble* createBubbleWithType(int type, cocos2d::Vec2 index, cocos2d::Vec2 point, int cloud = kBubbleNoCloud);
    public:
        std::string getPathWithType(int type);
    private:
        BubbleFactory();
        ~BubbleFactory();
        //������������ʼ��
        void initHandleMap();
        void initBubblePath();
    private:
        //����������
        //typedef ColorBubble*(*pHandle)(int);
        std::map<int, std::function<BaseBubble*(int, int)>> key_to_handle_map_;
        std::map<int, std::string> key_to_path;
    };
}
#endif //_BUBBLE_FACTORY_H_