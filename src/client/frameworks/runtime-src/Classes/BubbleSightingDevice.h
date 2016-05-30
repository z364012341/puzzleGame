//*******************************************************************************
//������   : BubbleSightingDevice
//����     : <��Ϸ���ݵ���׼��>
//-------------------------------------------------------------------------------
//��ע     : <>
//�����÷� : <>
//-------------------------------------------------------------------------------
//����     : <�����>, [yyy], [zzz] ...�����ߺͶ��ŷָ���޸����б�
//*******************************************************************************
#ifndef _BUBBLE_SIGHTING_DEVICE_H_
#define _BUBBLE_SIGHTING_DEVICE_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class BubbleSightingPoint;
    typedef cocos2d::Vector<BubbleSightingPoint*> SightPointVector;
    class BubbleSightingDevice : public cocos2d::Node
    {
    public:
        CREATE_FUNC(BubbleSightingDevice);
        virtual ~BubbleSightingDevice();
        void onEnter() override;
        void onExit() override;
        //void rotateSightingDevice(const float angle, const float& max_pos_y);
        //void contactWorldBorder();
        void contactBubble();
        //���豸
        //virtual void turnOnDeviceOnce(int device_numble = 0);
        //�ı���ɫ
        void changePointsColor(BubbleType color);
        //�Ƿ����������߽�
        //bool isContactTopBorder(const float& max_pos_y);
        //�Ƿ��ǵ�һ̨�豸
        //bool isFirstDevice();
        //�����һ̨�豸�ĽǶ��������㶥��������λ��
        //void setFirstDeviceAngle(const float& angle);
        //float getFirstDeviceAngle() const;
        //����������������ʣ�µ���Զ��
        void deviceGoAway();
        //ֹͣ���˶�
        void stopDevicePoint();
        //������׼��
        void  performSightingDevice();
        //������ȥ
        void sightingPointMove();

        void setVisible(bool visible) override;
        virtual void turnOnSightingDevice();
        virtual void turnOffSightingDevice();
        bool isDeviceOnStage();
        //������һ���豸
        void setNextSightingDevice(BubbleSightingDevice * device);
        BubbleSightingDevice * getNextSightingDevice();
        //���ýǶ�
        void setDeviceRotation(const std::vector<float>& angles);
        //����λ��
        void setDevicePosition(const std::vector<cocos2d::Vec2>& points);
        //������������
        void setDevicePointHidden(const std::vector<bool>& flags);
        //targetID  {set get}
        void setTargetID(int numble);
        int getTargetID() const;
        //���λ�ñ���
        void setReflectionPointOffset(const std::vector<float>& offset_vector);
    protected:
        BubbleSightingDevice();
        virtual bool init();
        //����point����ʾ
        void setSightingPointsVisibled();
        //��ȡ�����ĸ���λ��
        //void setContactMinPosition(const std::vector<cocos2d::Vec2>& points);
        //cocos2d::Vec2 calculateContactMinPosition(const cocos2d::Vec2 & point1, const cocos2d::Vec2 & point2);
        //bool devicePhysicsRayCastCallbackFunc(cocos2d::PhysicsWorld& world, const cocos2d::PhysicsRayCastInfo& info, void* data);
    private:
        //��������������Ƿ�����С��֮��ʹʣ������ʧ���ж�, �����߽�ʣ����ʾ
        //void addPhysicsBody();
        //��ȡ��һ����׼�ߵ�λ��
        //cocos2d::Vec2 getReflectionPoint();
        //������׼�����Сλ��y
        float getSightingPointsMinPositionY();
        //�ж��Ƿ��鵽
        bool isContactBubble();
        //�ж���׼���Ƿ���Ҫ����
        bool isSightingPointsNeedHidden(const cocos2d::Vec2& point/*, float min_y, float max_y*/);
        //��תʣ����豸
        //void rotateRemainDevice(const float angle, const cocos2d::Vec2& point, const float& max_pos_y);
        //void setDeviceRotationAndPosition(float angle, const cocos2d::Vec2& point);
        //���㶥��������λ��
        //�Ȱ���ͨ���㷨���λ��, ���λ�ó�������, �����¼���λ��
        //��һ������: ��ûƫ�ƹ��ĵ��λ��
        //�ڶ�������: ����λ��
        //cocos2d::Vec2 calculateReflectTopPosition(const cocos2d::Vec2& point, const float& max_pos_y);
        //void setTopReflectRotationAndPosition(float angle, const cocos2d::Vec2& point, const float& max_pos_y);
        cocos2d::Vec2 convertLocalToCsbSpace(const cocos2d::Vec2& local_point);
        //�����Ƿ�Ҫ���ص��
        void setHidePointEnable(bool flag);
        bool isHidePoint();

        //hypotenuse_offset_ set get
        //void setHypotenuseOffset(float offset);
        float getHypotenuseOffset();
        //max_top_y_ set get
        //void setMaxTopY(float numble);
        float getMaxTopY();
    private:
        //static float max_top_y_; //�������������y   �����csb������
        //size_t points_index_ = 0;
        bool switch_flag_ = false;
        BubbleSightingDevice* sight_device_ = nullptr;
        SightPointVector sighting_points_;
        int target_id_ = 0;
        //static float first_device_angle_;
        bool is_hide_point_ = false;
        float hypotenuse_offset_ = 0.0f; //б��ƫ��, ����׼�ߵĵ��з���Ч��
        cocos2d::Node* points_node_ = nullptr;
        //float relection_offset_ = 0.0f;
        //cocos2d::Vec2* min_position_ = &cocos2d::Vec2(0.0, 0.0);
        //cocos2d::DrawNode* node_ = nullptr;
    };
}
#endif //_BUBBLE_SIGHTING_DEVICE_H_