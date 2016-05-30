//*******************************************************************************
//类名称   : BubbleMainSightingDevice
//功能     : <游戏泡泡的主喵准器>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_MAIN_SIGHTING_DEVICE_H_
#define _BUBBLE_MAIN_SIGHTING_DEVICE_H_
#include "BubbleSightingDevice.h"
namespace bubble_second {
    class BubbleReflectionPointComponent;
    class BubbleMainSightingDevice : public BubbleSightingDevice
    {
    public:
        CREATE_FUNC(BubbleMainSightingDevice);
        ~BubbleMainSightingDevice();
        void setParent(cocos2d::Node* parent) override;
        void onEnter() override;
        void onExit() override;
        //void changePointsColor(BubbleType color) override;
        void turnOnMainSightingDevice(const cocos2d::Vec2 & touch_point);
        //void turnOnSightingDevice()override;
        void turnOffSightingDevice()override;
    private:
        BubbleMainSightingDevice();
        bool init();
        //void turnOnDeviceOnce(int device_numble = 0) override;
        void initRemainDevice();
        void rotateDevice(const cocos2d::Vec2& touch_point);
    private:
        BubbleReflectionPointComponent* reflection_point_component_ = nullptr;
        //cocos2d::Vector<BubbleSightingDevice*> remaind_device_;
    };
}
#endif //_BUBBLE_MAIN_SIGHTING_DEVICE_H_