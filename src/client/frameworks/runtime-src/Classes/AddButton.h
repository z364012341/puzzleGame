//*******************************************************************************
//������   : EnterGameAlert
//����     : <������Ϸ����ǰ�����>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _ADD_BUTTON_H_
#define _ADD_BUTTON_H_
#include "BubbleSecondConstant.h"
#include "ui\UIButton.h"
namespace bubble_second {
	class AddButton : public cocos2d::Node
	{
	public:
		CREATE_FUNC(AddButton);
		~AddButton();
	private:
		AddButton();
		bool init();
		void playButtonAction();
	private:
		cocos2d::ui::Button* button_ = nullptr;
		cocos2d::Node* csb_node_ = nullptr;
	};
}
#endif //_ADD_BUTTON_H_