//*******************************************************************************
//������   : GameScene
//����     : <��Ϸ��ս������>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BASE_PROPERTY_H_
#define _BASE_PROPERTY_H_
#include "cocos2d.h"
#include "SpriteTextureController.h"
#include "ui\UITextAtlas.h"
namespace bubble_second {
    enum PropsState
    {//���ߵ�ʹ��״̬
        notUseForError = 0, //��Ϊ��״̬�й�, ���Բ�����0��ö��
        kUsing,
        kNotUsed
    };
    typedef bool TouchEnabled;
    typedef bool isUsing;
    class BaseProperty  : public cocos2d::Sprite
    {
    public:
        //static BaseProperty* createWithName(const std::string& name)
        //{
        //    BaseProperty *pRet = new(std::nothrow) BaseProperty();
        //    if (pRet && pRet->initWithName(name))
        //    {
        //        pRet->autorelease();
        //        return pRet;
        //    }
        //    else
        //    {
        //        delete pRet;
        //        pRet = NULL;
        //        return NULL;
        //    }
        //}
        CREATE_FUNC(BaseProperty);
        virtual ~BaseProperty();
        void onExit() override;
    public:
        virtual void touchItem();
        void actionBegan();
        virtual void cancelUseItem();
        void actionEnded();
        isUsing itemIsUsing();
        void setPropertyEnabled(bool flag);
        bool isPropertyEnabled();
    protected:
        BaseProperty();
        bool init();
        virtual void useItem();
        //����ͼ���״̬, �Ƿ񱻵��ʹ��֮���
        void setPropsState(PropsState state);
        PropsState getPropsState();
        //��ʼ�����ߵ�ͼ��
        void initIconWithPath(const std::string& path);
        //����֮��
        void haveUsedProperty(cocos2d::EventCustom*);
    private:
        void addNumbleButton();
        void addNumbleLabel(cocos2d::Sprite* bgSprite);
        void initHandle();
        void addTouchEventListener();
        void removeTouchEventListener();
    private:
        cocos2d::MenuItem* button_;
        std::map<PropsState, std::function<void()>> state_to_handle_;
        PropsState use_state_;
        TouchEnabled touch_flag_;
        cocos2d::Menu* menu_;
        bool touch_enable_ = true;
        cocos2d::ui::TextAtlas* props_numble_label_ = nullptr;
    };
}
#endif //_BASE_PROPERTY_H_