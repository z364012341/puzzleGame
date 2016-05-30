#include "ControlButtonController.h"
#include "ui\UIButton.h"
namespace bubble_second {

    ControlButtonController::ControlButtonController()
    {
        name_to_event_["pauseButton"] = "event_pause";
        name_to_event_["continueButton"] = "event_continue";
        name_to_event_["replayButton"] = "event_replay";
        name_to_event_["returnButton"] = "event_return";
    }

    bool ControlButtonController::addButtonTouchEventListener(cocos2d::ui::Widget * root)
    {
        if (name_to_event_.find(root->getName()) != name_to_event_.end())
        {
            dynamic_cast<cocos2d::ui::Button*>(root)->addClickEventListener([=](cocos2d::Ref*) {
                cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(name_to_event_[root->getName()]);
            });
            return true;
        }
        return false;
    }


    ControlButtonController::~ControlButtonController()
    {
    }

    void bubble_second::ControlButtonController::initControlButton(cocos2d::ui::Widget* root)
    {
        if (!root)
        {
            return;
        }
        if (this->addButtonTouchEventListener(root))
        {
            return;
        }
        const auto& arrayRootChildren = root->getChildren();
        for (auto& subWidget : arrayRootChildren)
        {
            cocos2d::ui::Widget* child = dynamic_cast<cocos2d::ui::Widget*>(subWidget);
            if (child)
            {
                this->initControlButton(child);
            }
        }
    }
}