//*******************************************************************************
//������   : PropsNumbleShow
//����     : <��Ϸ��ս������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _PROPS_NUMBLE_SHOW_H_
#define _PROPS_NUMBLE_SHOW_H_
#include "cocos2d.h"
#include "ui\UITextAtlas.h"
namespace bubble_second {
    class PropsNumbleShow : public cocos2d::Node
    {
    public:
        //CREATE_FUNC(PropsNumbleShow);
        static PropsNumbleShow* create(const std::string& prop_key);
        ~PropsNumbleShow();
        //void addPropNumble(int numble = 1);
        bool cutPropNumble();
        void setPropNumble(int numble);
        void onEnter() override;
        void onExit() override;
    private:
        PropsNumbleShow();
        bool init(const std::string& prop_key);
        void updateLabel();
        bool isNoneProp();
    private:
        cocos2d::ui::TextAtlas* props_numble_label_ = nullptr;
        cocos2d::Sprite* plus_sprite_ = nullptr;
        std::string prop_key_ = "";
        cocos2d::EventListenerCustom* listener_ = nullptr;
        
    };
}
#endif //_PROPS_NUMBLE_SHOW_H_
