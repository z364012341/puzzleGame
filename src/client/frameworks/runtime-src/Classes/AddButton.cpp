#include "AddButton.h"
#include "cocostudio\CocoStudio.h"
#include "ui\UIScale9Sprite.h"
#include "ButtonEffectController.h"
const std::string CSB_PATH = "AddButton.csb";
//const std::string ADD_BUTTON_NAME = "addButton";
const std::string ADD_BUTTON_PATH = "anniutianjia.PNG";

namespace bubble_second {
	AddButton::AddButton()
	{
	}


	AddButton::~AddButton()
	{
	}

	bool AddButton::init()
	{
		if (!cocos2d::Node::init())
		{
			return false;
		}
        button_ = cocos2d::ui::Button::create(ADD_BUTTON_PATH);
        ButtonEffectController::setButtonZoomScale(button_);
        this->addChild(button_);

		csb_node_ = cocos2d::CSLoader::createNode(CSB_PATH);
		this->playButtonAction();
		//button_ = dynamic_cast<cocos2d::ui::Button*>(csb_node_->getChildByName(ADD_BUTTON_NAME));
        cocos2d::Sprite* stencil = cocos2d::Sprite::createWithTexture(button_->getRendererNormal()->getSprite()->getTexture());
        stencil->setScale(0.8f);

		cocos2d::ClippingNode* clipping = cocos2d::ClippingNode::create(stencil);
        clipping->setAlphaThreshold(0);
		clipping->addChild(csb_node_);
        button_->getRendererNormal()->addChild(clipping);
        clipping->setPosition(button_->getContentSize().width/2, button_->getContentSize().height / 2);
		return true;
	}

	void AddButton::playButtonAction()
	{
		int randomTime = cocos2d::random(1, 10);
		this->runAction(cocos2d::Sequence::createWithTwoActions(cocos2d::DelayTime::create(randomTime), cocos2d::CallFunc::create([=](){
			auto action = cocos2d::CSLoader::createTimeline(CSB_PATH);
			csb_node_->runAction(action);
			action->gotoFrameAndPlay(0, false);
			this->playButtonAction();
		})));
	}
}