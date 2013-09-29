//
//  TouchTestLayer.cpp
//  minGameTest
//
//  Created by 马 英臣 on 13-9-13.
//
//

#include "TouchTestLayer.h"
#include "../../utils/TouchUtil.h"

TouchTestLayer::TouchTestLayer()
:mpcolorLayer(NULL)
{
    
}
TouchTestLayer::~TouchTestLayer(){
    CCLOG("TouchTestLayer删除。");
    CC_SAFE_RELEASE(mpcolorLayer);
}

void TouchTestLayer::onEnter(){
    BaseLayer::onEnter();
    
}
void TouchTestLayer::onExit(){
    BaseLayer::onExit();   
}

bool TouchTestLayer::init(){
    if(!BaseLayer::init()){
        return false;
    }      
    return true;
}

SEL_MenuHandler TouchTestLayer::onResolveCCBCCMenuItemSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //菜单事件
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onClickClose1", TouchTestLayer::onClickClose1);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onClickClose2", TouchTestLayer::onClickClose2);
    return NULL;
}
Control::Handler TouchTestLayer::onResolveCCBCCControlSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //按钮事件
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickClose", TouchTestLayer::onClickClose);
    return NULL;
}
bool TouchTestLayer::onAssignCCBMemberVariable(cocos2d::Object * pTarget, const char * pMemberVariableName, cocos2d::Node * pNode){
    //显示对象
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "mpcolorLayer", LayerColor*, mpcolorLayer);
    return false;
}
bool TouchTestLayer::onAssignCCBCustomProperty(Object* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue){    
    return false;
}
void TouchTestLayer::onNodeLoaded(cocos2d::Node * node, cocos2d::extension::NodeLoader * nodeLoader){
      
//    Size ss=this->getContentSize();
//    std::cout<<ss.width<<","<<ss.height<<std::endl;    
}

void TouchTestLayer::registerWithTouchDispatcher(void){
        
}

bool TouchTestLayer::ccTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    bool touch=BaseLayer::ccTouchBegan(pTouch, pEvent);    
    //碰到某一区域
    
    //碰到某一不规则区域
    if(touch){
        UIManager::Instance()->removeLayerByNode(this);
    }    
    return touch;
}

void TouchTestLayer::onClickClose(cocos2d::Object * sender, Control::EventType pControlEvent){
    CCLOG("onClickAddClose");   
    UIManager::Instance()->removeLayerByNode(this);
}
void TouchTestLayer::onClickClose1(cocos2d::Object * sender){
    CCLOG("onClickAddClose1");   
    
}
void TouchTestLayer::onClickClose2(cocos2d::Object * sender){
    CCLOG("onClickAddClose2");   
    
}

