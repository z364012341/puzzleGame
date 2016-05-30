//*******************************************************************************
//������   : BubbleColorPicker
//����     : <�������ݵ�ȡɫ��>
//-------------------------------------------------------------------------------
//��ע     : <������ŵ�ǰ��ͼ��ʣ�����ݵ���ɫ>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BUBBLE_COLOR_PICKER_H_
#define _BUBBLE_COLOR_PICKER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleColorPicker
    {
    public:
        BubbleColorPicker();
        ~BubbleColorPicker();
        void init();
    public:
        void addColorWithBubbleColor(BubbleType color);
        void subtractColorWithBubbleColor(BubbleType color);
        BubbleType getBubbleColorFromPicker();
        //�ж������ɫ�ǲ���û����
        bool needChangeBubbleType(BubbleType color);
        //������һ�ѵ���ɫ��Χ
        void setColorPickerRange();
        BubbleType getBubbleColorInRange();
    private:
        //�ж��ǲ���һ����ͨС�������
        bool isColorBubbleType(BubbleType color);
        std::vector<BubbleType> getColorPickerVector();
        //����¼�����
        //void addEventListenerCustom();
        //void addColorWithEvent(cocos2d::EventCustom* event);
        //void subtractColorWithEvent(cocos2d::EventCustom* event);
    private:
        std::map<BubbleType, int> color_picker_;
        std::vector<BubbleType> color_range_;
        int color_total_;
    };
}
#endif //_BUBBLE_COLOR_PICKER_H_