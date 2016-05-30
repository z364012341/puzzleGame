//*******************************************************************************
//类名称   : EnterGameAlert
//功能     : <进入游戏场景前的面板>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
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