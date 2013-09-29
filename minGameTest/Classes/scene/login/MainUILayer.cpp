//
//  MainUILayer.cpp
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//

#include "MainUILayer.h"
#include "../../event/CommandIDS.h"

MainUILayer::MainUILayer(){
   CC_REGISTER_OBJ_COMMAND(CMDID::UI_HELLO_COMMAND,MainUILayer,this, helloCommandTest);
}
MainUILayer::~MainUILayer(){
    CCLOG("MainUILayer删除。");
    CC_REMOVE_COMMAND(this);  
}

bool MainUILayer::init(){
    if(!BaseLayer::init()){
        return false;
    }    
    return true;
}

void MainUILayer::onEnter(){
    BaseLayer::onEnter();
    
//    this->setTouchMode(Touch::DispatchMode::ALL_AT_ONCE);//ALL_AT_ONCE    
//    Director::getInstance()->getTouchDispatcher()->addTargetedDelegate(this,100,true);
}
void MainUILayer::onExit(){
    BaseLayer::onExit();    
    UIManager::Instance()->removeLayersByType(CCBI::main_item.c_str());
    UIManager::Instance()->removeLayersByType(CCBI::main_effect.c_str());
}

SEL_MenuHandler MainUILayer::onResolveCCBCCMenuItemSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //菜单事件
    
    return NULL;
}
Control::Handler MainUILayer::onResolveCCBCCControlSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //按钮事件
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickClose", MainUILayer::onClickClose);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickMulPopUp", MainUILayer::onClickMulPopUp);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickAnimation", MainUILayer::onClickAnimation);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickScrollList", MainUILayer::onClickScrollList);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickEffect", MainUILayer::onClickEffect);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickTestMulCCBI", MainUILayer::onClickTestMulCCBI);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickMovie", MainUILayer::onClickMovie);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickSound", MainUILayer::onClickSound);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickTouchTest", MainUILayer::onClickTouchTest);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickTestEvent", MainUILayer::onClickTestEvent);    
    
    return NULL;
}
bool MainUILayer::onAssignCCBMemberVariable(cocos2d::Object * pTarget, const char * pMemberVariableName, cocos2d::Node * node){
    //显示对象
    return false;
}
bool MainUILayer::onAssignCCBCustomProperty(Object* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue){
    
    return false;
}
void MainUILayer::onNodeLoaded(cocos2d::Node * node, cocos2d::extension::NodeLoader * nodeLoader){
    
    
}
void MainUILayer::onClickMulPopUp(cocos2d::Object * sender, Control::EventType pControlEvent){    
//    
//    UIManager::Instance()->addPopLayer(CCBI::main_item.c_str(),this,1);
//    UIManager::Instance()->openPopLayers();    
//
    for(int i=0;i<15;i++){
        UIManager::Instance()->addPopLayer(CCBI::main_item.c_str(),this,1,ccp((i%5)*80,80*(i/5)));
    }    
    UIManager::Instance()->openPopLayers();    
}
void MainUILayer::onClickAnimation(cocos2d::Object * sender, Control::EventType pControlEvent){
    
    
}
void MainUILayer::onClickScrollList(cocos2d::Object * sender, Control::EventType pControlEvent){
    
    
}
void MainUILayer::onClickEffect(cocos2d::Object * sender, Control::EventType pControlEvent){
    //粒子效果
    
    UIManager::Instance()->addPopLayer(CCBI::main_effect.c_str(),this,1);
    UIManager::Instance()->openPopLayers();
        
}
void MainUILayer::onClickTestMulCCBI(cocos2d::Object * sender, Control::EventType pControlEvent){
    
    
}
void MainUILayer::onClickMovie(cocos2d::Object * sender, Control::EventType pControlEvent){
    std::cout<<"视频播放："<<std::endl;
    
    
}
void MainUILayer::onClickSound(cocos2d::Object * sender, Control::EventType pControlEvent){
    std::cout<<"声音管理："<<std::endl;
//   Director::getInstance()->getTouchDispatcher()->addStandardDelegate(this, -10000);
//    Director::getInstance()->getTouchDispatcher()->addTargetedDelegate(this,1,false);
//    Director::getInstance()->getTouchDispatcher()->removeDelegate(this);    
}
void MainUILayer::onClickTestEvent(cocos2d::Object * sender, Control::EventType pControlEvent){
     std::cout<<"事件测试："<<std::endl;
    Notification notice(CMDID::UI_HELLO_COMMAND);
    int value=100;
    notice.setBody(&value);
    CC_EXECUTE_COMMAND(notice);
}

void MainUILayer::onClickClose(cocos2d::Object * sender, Control::EventType pControlEvent){
    UIManager::Instance()->removeLayerByNode(this);
}

bool MainUILayer::ccTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){   
    //判断自定义触摸逻辑  如果找到目标并不再继续响应 return true;
    if(BaseLayer::ccTouchBegan(pTouch, pEvent)){
        //表示点击到当前对象
        return true;
    }
    //return true;
    
    //没有找到目标 调用BaseLayer::ccTouchBegan(pTouch, pEvent) 继续响应;
    return false;
}

void MainUILayer::onClickTouchTest(cocos2d::Object * sender, Control::EventType pControlEvent){
       std::cout<<"touch test："<<std::endl;
    
    UIManager::Instance()->addPopLayer(CCBI::main_touch.c_str(),this,1);
    UIManager::Instance()->openPopLayers();
    
}

void MainUILayer::helloCommandTest(INotification const& notification){
    
    std::cout<<"接收到事件："<<std::endl;    
    int value=*(int*)notification.getBody();
    std::cout<<value<<std::endl;  
       
}


//void MainUILayer::registerWithTouchDispatcher()
//{
//    
//    
//    Director::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, -129, false);
//    //Director::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);//多点触摸
//       
//}
