//*******************************************************************************
//������   : BubbleColorRender
//����     : <������ɫ���>
//-------------------------------------------------------------------------------
//��ע     : <����������,������ײ�ʹ����Ļص�>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BUBBLE_COLOR_RENDER_H_
#define _BUBBLE_COLOR_RENDER_H_
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleColorRender
    {
    public:
        BubbleColorRender(const std::vector<BubbleType>& color_vector);
        ~BubbleColorRender();
        BubbleType getRandomColorWithColor(BubbleType color);
    private:
        void initWithColorVector(const std::vector<BubbleType>& color_vector);
        void mixBubbleColor(const std::vector<BubbleType>& color_vector);
		//void printColorRender(const std::vector<BubbleType>& color_vector);
    private:
        std::map<BubbleType, BubbleType> color_to_color_;
		std::vector<BubbleType> origin_color_vector;
    };
}
#endif //_BUBBLE_COLOR_RENDER_H_