//
//  MainItemLayer.cpp
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//

#include "MainItemLayer.h"
#include "../../utils/TouchUtil.h"

MainItemLayer::MainItemLayer(){
    
}
MainItemLayer::~MainItemLayer(){
    CCLOG("MainItemLayer删除。");    
}

void MainItemLayer::onEnter(){
    BaseLayer::onEnter();
    
}
void MainItemLayer::onExit(){
    BaseLayer::onExit();   
}

bool MainItemLayer::init(){
    if(!BaseLayer::init()){
        return false;
    }      
    return true;
}

SEL_MenuHandler MainItemLayer::onResolveCCBCCMenuItemSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //菜单事件
    
    return NULL;
}
Control::Handler MainItemLayer::onResolveCCBCCControlSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //按钮事件
       
    return NULL;
}
bool MainItemLayer::onAssignCCBMemberVariable(cocos2d::Object * pTarget, const char * pMemberVariableName, cocos2d::Node * node){
    //显示对象
    return false;
}
bool MainItemLayer::onAssignCCBCustomProperty(Object* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue){    
    return false;
}
void MainItemLayer::onNodeLoaded(cocos2d::Node * node, cocos2d::extension::NodeLoader * nodeLoader){
      
//    Size ss=this->getContentSize();
//    std::cout<<ss.width<<","<<ss.height<<std::endl;    
}

bool MainItemLayer::ccTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    bool touch=BaseLayer::ccTouchBegan(pTouch, pEvent);    
    //碰到某一区域
    
    //碰到某一不规则区域
    if(touch){
        UIManager::Instance()->removeLayerByNode(this);
    }    
    return touch;
}



