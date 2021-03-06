#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MainScene.h"
//#include "UIManager.h"
#include "manager/ResourceManager.h"
#include "manager/UIManager.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    Director* director = Director::getInstance();
    EGLView* eglView = EGLView::getInstance();
    
    //eglView->setDesignResolutionSize(480,320,ResolutionPolicy::SHOW_ALL);
    director->setOpenGLView(eglView);
	
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    
    
    UIManager::Instance()->initialize(); 
    ResourceManager::Instance()->initialize();
        
    // create a scene. it's an autorelease object
    Scene *scene = HelloWorld::scene();
    // run
    director->runWithScene(scene);    
    
//    scene = MainScene::scene();
//    // run
//    director->runWithScene(scene);    

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
