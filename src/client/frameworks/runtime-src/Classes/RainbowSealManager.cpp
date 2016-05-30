#include "RainbowSealManager.h"
#include "RainbowSealBubble.h"
#include "RainbowCharactor.h"
namespace bubble_second {
    RainbowSealManager::RainbowSealManager()
    {
        this->clear();
        bubblecolor_to_color3b_[kBubbleYellow] = cocos2d::Color3B(229, 167, 13);
        bubblecolor_to_color3b_[kBubblePurple] = cocos2d::Color3B(140, 10, 175);
        bubblecolor_to_color3b_[kBubbleBlue] = cocos2d::Color3B(27, 37, 194);
        bubblecolor_to_color3b_[kBubbleRed] = cocos2d::Color3B(167, 6, 3);
        bubblecolor_to_color3b_[kBubbleGreen] = cocos2d::Color3B(36, 131, 2);
        bubblecolor_to_color3b_[kBubbleOrange] = cocos2d::Color3B(222, 78, 0);
        bubblecolor_to_color3b_[kBubblePink] = cocos2d::Color3B(253, 123, 234);
        bubblecolor_to_color3b_[kBubbleTransparent] = cocos2d::Color3B::WHITE;

    }

    RainbowSealManager::~RainbowSealManager()
    {
    }

    void RainbowSealManager::clear()
    {   
        rainbow_seal_bubbles_.clear();
        //rainbow_charactor_ = nullptr;
    }

    void RainbowSealManager::addRainbowSealBubble(RainbowSealBubble* bubble)
    {
        for (int i = 0; i < rainbow_seal_bubbles_.size(); i++)
        {
            if (bubble->isIndexlargeThen(rainbow_seal_bubbles_.at(i)->getBubbleIndex()))
            {
                rainbow_seal_bubbles_.insert(i, bubble);
                return;
            }
        }
        rainbow_seal_bubbles_.pushBack(bubble);
    }

    void RainbowSealManager::beginSealingCharactor()
    {
        auto begin_bubble = getNextRainbowSealBubble();
        if (!begin_bubble)
        {
            return;
        }
        begin_bubble->beginSealingCharactor();


        //if (!this->haveBeganSealed())
        //{
        //    rainbow_charactor_ = RainbowCharactor::createWithFile(RAINBOW_CHARACTOR_ARMATURE_NAME);
        //}
        //rainbow_charactor_->beginSealingCharactor(begin_bubble);
        //(*begin_bubble)->addChild(rainbow_charactor_);
        //auto rect = (*begin_bubble)->getBoundingBox();
        //rainbow_charactor_->setPosition(rect.size.width/2, rect.size.height/2);
        //(*begin_bubble)->changeRainbowColor();
    }

    //void RainbowSealManager::setRainbowCharactor(RainbowCharactor* charactor)
    //{
    //    rainbow_charactor_ = charactor;
    //}

    //RainbowCharactor* RainbowSealManager::getRainbowCharactor()
    //{
    //    return rainbow_charactor_;
    //}

    //bool RainbowSealManager::haveBeganSealed()
    //{
    //    return this->getRainbowCharactor()!=nullptr;
    //}

    cocos2d::Color3B RainbowSealManager::getColor3BWithBubbleColor(BubbleType color)
    {
        return bubblecolor_to_color3b_[color];
    }

    void RainbowSealManager::moveSealedCharactor(RainbowSealBubble* bubble)
    {
        auto from_point = bubble->getPosition();
        rainbow_seal_bubbles_.eraseObject(bubble);
        if (RainbowSealBubble* bubble = this->getNextRainbowSealBubble())
        {
            bubble->beginSealingCharactor();
        }

        //rainbow_charactor_->moveSealintCharactor(this->getNextRainbowSealBubble(), from_point);
    }

    RainbowSealBubble * RainbowSealManager::getNextRainbowSealBubble()
    {
        auto begin_bubble = rainbow_seal_bubbles_.begin();
        if (begin_bubble != rainbow_seal_bubbles_.end())
        {
            return *begin_bubble;
        }
        else
        {
            return nullptr;
        }  
    }

}