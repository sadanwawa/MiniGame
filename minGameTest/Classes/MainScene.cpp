//
//  MainScene.cpp
//  minGameTest
//
//  Created by 马 英臣 on 13-8-15.
//
//

#include "MainScene.h"
#include "common/StaticConstant.h"
#include "scene/login/MainUILayerLoader.h"


MainScene::MainScene(){
    
}
MainScene::~MainScene(){
    
}

 bool MainScene::init(){
     if(!BaseScene::init()){
         return false;
     }
          
     Size visibleSize = Director::getInstance()->getVisibleSize();
     Point origin = Director::getInstance()->getVisibleOrigin();
     //背景图
     Sprite* sprite = Sprite::create(STC::IMAGE_HELLOWORLD.c_str());
     sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));     
     baseNode->addChild(sprite, 0);

     //标题
     LabelTTF* label = LabelTTF::create("MainScene", "Arial", 24);     
     label->setPosition(Point(origin.x + visibleSize.width/2,
                              origin.y + visibleSize.height - label->getContentSize().height));     
     
     baseNode->addChild(label, 1);     
     //菜单列表
     //关闭
     MenuItemImage *closeItem = MenuItemImage::create(
                                                      STC::IMAGE_CLOSENORMAL.c_str(),
                                                      STC::IMAGE_CLOSESELECT.c_str(),
                                                      CC_CALLBACK_1(MainScene::menuCloseCallback, this));
     
     closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                  origin.y + closeItem->getContentSize().height/2));
     
     
     sprite = Sprite::createWithSpriteFrameName(STC::FRAME_BTN1_NORMAL.c_str());
     Sprite*sprite2 = Sprite::createWithSpriteFrameName(STC::FRAME_BTN1_SELECT.c_str());
     MenuItemSprite *startItem =MenuItemSprite::create(sprite, sprite2,CC_CALLBACK_1(MainScene::menuCloseCallback, this));
     
        
     startItem->setPosition(Point(origin.x + visibleSize.width - startItem->getContentSize().width/2 ,
                                  origin.y + 2*startItem->getContentSize().height/2));
          
     // create menu, it's an autorelease object
     Menu* menu = Menu::create(closeItem, startItem,NULL);
     menu->setPosition(Point::ZERO);
     baseNode->addChild(menu, 1);////////////////////
          
     sprite = Sprite::createWithSpriteFrameName(STC::FRAME_BTN1_NORMAL.c_str());
     sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
     baseNode->addChild(sprite);
     
     
     //用代码创建按钮
          
     // Add the button
     Scale9Sprite *backgroundButton = Scale9Sprite::createWithSpriteFrameName(STC::FRAME_BTN1_NORMAL.c_str());     
     Scale9Sprite *backgroundHighlightedButton = Scale9Sprite::createWithSpriteFrameName(STC::FRAME_BTN1_SELECT.c_str());
     
     backgroundButton->setContentSize(Size(128, 128));
     backgroundHighlightedButton->setContentSize(Size(128, 128));
     
     LabelTTF *titleButton = LabelTTF::create("Touch Me!", "Marker Felt", 30);
     titleButton->setColor(Color3B(159, 168, 176));
     
     ControlButton *controlButton = ControlButton::create(titleButton, backgroundButton);
     controlButton->setBackgroundSpriteForState(backgroundHighlightedButton, Control::State::HIGH_LIGHTED);
     controlButton->setTitleColorForState(Color3B::WHITE, Control::State::HIGH_LIGHTED);
     
     controlButton->setAnchorPoint(Point(0.5f, 1));
     controlButton->setPosition(Point(origin.x + visibleSize.width -100- controlButton->getContentSize().width/2, visibleSize.height / 2.0f));
               
     baseNode->addChild(controlButton, 3);////////////////////
     
     // Add the black background
     Scale9Sprite *background = Scale9Sprite::createWithSpriteFrameName(STC::FRAME_BTN1_SELECT.c_str());
     background->setContentSize(Size(128, 128));
     background->setPosition(Point(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
     baseNode->addChild(background);
     
     // Sets up event handlers
     controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::touchDownAction), Control::EventType::TOUCH_DOWN);
     controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::touchDragInsideAction), Control::EventType::DRAG_INSIDE);
     controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::touchDragOutsideAction), Control::EventType::DRAG_OUTSIDE);
     controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::touchDragEnterAction), Control::EventType::DRAG_ENTER);
     controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::touchDragExitAction), Control::EventType::DRAG_EXIT);
     controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::touchUpInsideAction), Control::EventType::TOUCH_UP_INSIDE);
     controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::touchUpOutsideAction), Control::EventType::TOUCH_UP_OUTSIDE);
     controlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(MainScene::touchCancelAction), Control::EventType::TOUCH_CANCEL);
     
    /*由此看出 在代码中创建UI布局是多么的麻烦，所以Ui编辑器就显得非常必要了。  我们后面开始尝试用cocosBuilder编辑器制做UI并在项目中应用，
     
     工作一：cocosBuilder编辑器的使用；代码与UI的绑定；UIManager管理ccbi文件的加载 显示 卸载等。
     
     通过上边Menu 和 ControlButton的例子我们还可以看出：触摸层级和显示层级是不一致的。例子代码中Menu对象显示在下层  ControlButton对象显示在上层，按照正常逻辑应该响应ControlButton按钮的事件才对。但实际情况出乎我们的意料，不管显示层级如何改变Menu对象先于ControlButton响应了事件。  后边我们会研究触摸事件的响应机制并做定制化管理。
     
     工作二：触摸事件管理
     
     项目中事件机制是最常用的基础模块之一，通过事件方便数据传输和面向对象设计。
     工作三：自定义事件机制
     
     
     //工具：
     //1.自定义美术字工具及使用
     //2.导出字典表工具 
     
     
          
     */
     return true;
 }

cocos2d::Scene* MainScene::scene(){
    
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();    
    // 'layer' is an autorelease object
    MainScene *layer = MainScene::create();    
    // add layer as a child to scene
    scene->addChild(layer);    
    // return the scene
    return scene;

}

void MainScene::menuCloseCallback(Object* pSender){
    
    Director* direct=Director::getInstance();    
    Scene* scene = MainScene::scene();        
    Scene* dscene= TransitionZoomFlipAngular::create(1.2f, scene,TransitionScene::Orientation::DOWN_OVER);//带缩放效果且有角度转的下翻   
    direct->replaceScene(dscene);
    return;
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif    
//    if(CC_TARGET_PLATFORM==CC_PLATFORM_IOS){
//        exit(0);
//    }    
}

void MainScene::touchDownAction(Object *senderz, Control::EventType controlEvent)
{
    //_displayValueLabel->setString(String::createWithFormat("Touch Down")->getCString());        
}

void MainScene::touchDragInsideAction(Object *sender, Control::EventType controlEvent)
{
    //_displayValueLabel->setString(String::createWithFormat("Drag Inside")->getCString());
}

void MainScene::touchDragOutsideAction(Object *sender, Control::EventType controlEvent)
{
    //_displayValueLabel->setString(String::createWithFormat("Drag Outside")->getCString());
}

void MainScene::touchDragEnterAction(Object *sender, Control::EventType controlEvent)
{
    //_displayValueLabel->setString(String::createWithFormat("Drag Enter")->getCString());
}

void MainScene::touchDragExitAction(Object *sender, Control::EventType controlEvent)
{
    //_displayValueLabel->setString(String::createWithFormat("Drag Exit")->getCString());
}

void MainScene::touchUpInsideAction(Object *sender, Control::EventType controlEvent)
{              
    UIManager::Instance()->addPopLayer(CCBI::main_menu.c_str(),NULL,1);
    UIManager::Instance()->openPopLayers();    
    //添加粒子效果
    /*
    1.跟随鼠标移动粒子效果
     
    2.粒子效果控制
    */
    
    //逐侦特效播放
    /*
     控制添加删除AnimationManager
     
     */
    
    //视频 声音播放
    
}

void MainScene::touchUpOutsideAction(Object *sender, Control::EventType controlEvent)
{
    //_displayValueLabel->setString(String::createWithFormat("Touch Up Outside.")->getCString());
}

void MainScene::touchCancelAction(Object *sender, Control::EventType controlEvent)
{
    //_displayValueLabel->setString(String::createWithFormat("Touch Cancel")->getCString());
}

void MainScene::onEnter(){
    BaseScene::onEnter();
    UIManager::Instance()->addPopLayer(CCBI::main_menu.c_str(),NULL,0);
    UIManager::Instance()->openPopLayers();
}
