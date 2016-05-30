#include "GameJNIHelper.h"
#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) 
#include "platform/android/jni/JniHelper.h" 
#endif

namespace bubble_second {
    GameJNIHelper::GameJNIHelper()
    {
    }


    GameJNIHelper::~GameJNIHelper()
    {
    }
    void GameJNIHelper::payWithTargetID(int targetID)
    {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        cocos2d::JniMethodInfo mInfo;
        if (cocos2d::JniHelper::getStaticMethodInfo(mInfo, "com/skt/sdk/main/CplusAndJavaInteraction", "pay", "(I)V"))
        {
            mInfo.env->CallStaticVoidMethod(mInfo.classID, mInfo.methodID, targetID);
        }
#endif 
    }
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    extern "C"
    {
        void Java_com_skt_sdk_main_CplusAndJavaInteraction_paySuccess(JNIEnv* env, jobject obj) {
            //std::string  orderIdStr = JniHelper::jstring2string(orderId);
            //GamePay::getInstance()->payCallBackSuccess(rmb, orderIdStr);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_BUY_PROPS_PAY_SUCCESS);

        }
        void Java_com_skt_sdk_main_CplusAndJavaInteraction_payFail(JNIEnv* env, jobject obj) {
            //std::string  contextStr = JniHelper::jstring2string(context);
            //GamePay::getInstance()->payCallFailSuccess(contextStr);
            cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(EVENT_BUY_PROPS_PAY_FAIL);
        }
    };
#endif
}