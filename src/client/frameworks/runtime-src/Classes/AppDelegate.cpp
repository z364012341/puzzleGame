#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "lua_module_register.h"
//#include "lua_LoadingScene_auto.hpp"
//#include "lua_GameStageSelectionScene_auto.hpp"
#include "lua_GameStartButton_auto.hpp"
#include "lua_SmartScaleController_auto.hpp"
#include "lua_ButtonEffectController_auto.hpp"
#include "lua_GameAlertMask_auto.hpp"
#include "lua_ControlButtonController_auto.hpp"
#include "lua_UserDataManager_auto.hpp"
#include "lua_SpriteTextureController_auto.hpp"
#include "lua_GameShareButton_auto.hpp"
#include "lua_PuzzleStageDataManager_auto.hpp"
#include "lua_PropsNumbleShow_auto.hpp"
#include "lua_PuzzleStoreItemFactory_auto.hpp"
#include "lua_PuzzleLoadingScene_auto.hpp"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_LINUX)
#include "ide-support/CodeIDESupport.h"
#endif

#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
#include "runtime/Runtime.h"
#include "ide-support/RuntimeLuaImpl.h"
#endif

using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();

#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
    RuntimeEngine::getInstance()->end();
#endif

}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages,
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // set default FPS
    Director::getInstance()->setAnimationInterval(1.0f / 60.0f);
    //获取系统时间
    //struct timeval now;
    //gettimeofday(&now, NULL);

    ////初始化随机种子
    ////timeval是个结构体，里边有俩个变量，一个是以秒为单位的，一个是以微妙为单位的 
    //unsigned rand_seed = (unsigned)(now.tv_sec * 1000 + now.tv_usec / 1000);    //都转化为毫秒 
    //srand(rand_seed);
    // register lua module
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);

    register_all_packages();

    LuaStack* stack = engine->getLuaStack();
    stack->setXXTEAKeyAndSign("2dxLua", strlen("2dxLua"), "XXTEA", strlen("XXTEA"));

    //register custom function
    //LuaStack* stack = engine->getLuaStack();
    //register_custom_function(stack->getLuaState());
	//register_all_LoadingScene(engine->getLuaStack()->getLuaState());
	//register_all_GameStageSelectionScene(engine->getLuaStack()->getLuaState());
    register_all_GameStartButton(engine->getLuaStack()->getLuaState());
    register_all_SmartScaleController(engine->getLuaStack()->getLuaState());
    register_all_ButtonEffectController(engine->getLuaStack()->getLuaState());
    register_all_GameAlertMask(engine->getLuaStack()->getLuaState());
    register_all_ControlButtonController(engine->getLuaStack()->getLuaState());
    register_all_UserDataManager(engine->getLuaStack()->getLuaState());
    register_all_SpriteTextureController(engine->getLuaStack()->getLuaState());
    register_all_PuzzleStageDataManager(engine->getLuaStack()->getLuaState());   
    register_all_GameShareButton(engine->getLuaStack()->getLuaState());
    register_all_PropsNumbleShow(engine->getLuaStack()->getLuaState());
    register_all_PuzzleStoreItemFactory(engine->getLuaStack()->getLuaState());
    register_all_PuzzleLoadingScene(engine->getLuaStack()->getLuaState());
#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
    auto runtimeEngine = RuntimeEngine::getInstance();
    runtimeEngine->addRuntime(RuntimeLuaImpl::create(), kRuntimeEngineLua);
    runtimeEngine->start();
#else
    if (engine->executeScriptFile("src/main.lua"))
    {
        return false;
    }
#endif

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
