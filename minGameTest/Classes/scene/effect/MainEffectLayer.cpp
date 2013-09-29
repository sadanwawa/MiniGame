//
//  MainEffectLayer.cpp
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//

#include "MainEffectLayer.h"

MainEffectLayer::MainEffectLayer()
:spriteA(NULL),
spriteB(NULL),
touch_test_btn(NULL)
{
  
}
MainEffectLayer::~MainEffectLayer(){//析构函数没有调用？？？
    CCLOG("MainEffectLayer删除。");   
}

void MainEffectLayer::onEnter(){
    BaseLayer::onEnter();
}
void MainEffectLayer::onExit(){
    BaseLayer::onExit();    
    UIManager::Instance()->removeLayersByType(CCBI::att_progress.c_str());
    UIManager::Instance()->removeLayersByType(CCBI::att_bing_behit.c_str());
}

bool MainEffectLayer::init(){    
    if(!BaseLayer::init()){
        return false;
    }    
    return true;
}


SEL_MenuHandler MainEffectLayer::onResolveCCBCCMenuItemSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //菜单事件
    
    return NULL;
}
Control::Handler MainEffectLayer::onResolveCCBCCControlSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //按钮事件
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickClose", MainEffectLayer::onClickClose);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickAttack", MainEffectLayer::onClickAttack);
    
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickAddEffect", MainEffectLayer::onClickAddEffect);
    CCB_SELECTORRESOLVER_CCCONTROL_GLUE(this, "onClickRemoveEffect", MainEffectLayer::onClickRemoveEffect);
    return NULL;
}
bool MainEffectLayer::onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode){
    //显示对象
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "spriteA", Sprite*, spriteA);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "spriteB", Sprite*, spriteB);
    CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "touch_test_btn", Sprite*, touch_test_btn);
    return false;
}

void MainEffectLayer::onNodeLoaded(cocos2d::Node * node, cocos2d::extension::NodeLoader * nodeLoader){


}


////bool MainEffectLayer::onAssignCCBCustomProperty(Object* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue){
////    
////    return false;
////}

void MainEffectLayer::onClickAttack(cocos2d::Object * sender, Control::EventType pControlEvent){        
    UIManager::Instance()->addPopLayer(CCBI::att_progress.c_str(),this,0,spriteA->getPosition());
    UIManager::Instance()->openPopLayers();
     
    
    FiniteTimeAction*  actionA = Sequence::create(
                                                  MoveTo::create(0.5, spriteB->getPosition()),
                                                  //ScaleTo::create(0.8,1),
                                                  CallFunc::create( CC_CALLBACK_0(MainEffectLayer::moveToTarget,this)),
                                                  CallFunc::create( CC_CALLBACK_0(MainEffectLayer::beHitEffect,this)),                                                  
                                                  NULL);
    
    Node* node=UIManager::Instance()->getLayerByType(CCBI::att_progress.c_str());
    node->runAction(actionA);        
}

void MainEffectLayer::moveToTarget(){
    ParticleSystemQuad* system=dynamic_cast<ParticleSystemQuad*>(UIManager::Instance()->getLayerByType(CCBI::att_progress.c_str()));
    if(system){
        system->stopSystem();
    }
}

void MainEffectLayer::beHitEffect(){
    
    UIManager::Instance()->addPopLayer(CCBI::att_bing_behit.c_str(),this,0);
    UIManager::Instance()->openPopLayers();
    Node* node=UIManager::Instance()->getLayerByType(CCBI::att_bing_behit.c_str());    
    node->setPosition(spriteB->getPosition());

    node->setScale(0.8);
    FiniteTimeAction*  actionA = Sequence::create(
                                                  DelayTime::create(1),                                                  
                                                  CallFunc::create( CC_CALLBACK_0(MainEffectLayer::removeOnceAttEffect,this)),
                                                  NULL);
    node->runAction(actionA);    
}

void MainEffectLayer::removeOnceAttEffect(){
    UIManager::Instance()->removeLayerByType(CCBI::att_progress.c_str());
    UIManager::Instance()->removeLayerByType(CCBI::att_bing_behit.c_str());
}

void MainEffectLayer::onClickClose(cocos2d::Object * sender, Control::EventType pControlEvent){
    UIManager::Instance()->removeLayerByNode(this);
}

void MainEffectLayer::onClickAddEffect(cocos2d::Object * sender, Control::EventType pControlEvent){
//    UIManager::Instance()->addPopLayer(CCBI::att_bing.c_str(),this,0,ccp(100,100));
//    UIManager::Instance()->openPopLayers();
    
    UIManager::Instance()->addPopLayer(CCBI::att_bing.c_str(),this,0,spriteB->getPosition());
    UIManager::Instance()->openPopLayers();
}
void MainEffectLayer::onClickRemoveEffect(cocos2d::Object * sender, Control::EventType pControlEvent){
//    UIManager::Instance()->removeLayersByType(CCBI::att_bing.c_str());    
    UIManager::Instance()->removeLayersByType(CCBI::att_bing.c_str()); 
}

//bool MainEffectLayer::ccTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
//    //判断自定义触摸逻辑  如果找到目标并不再继续响应 return true;
//    if(Layer::ccTouchBegan(pTouch, pEvent)){
//        //表示点击到当前对象
//    }
//    //return true;
//    
//    //没有找到目标 调用BaseLayer::ccTouchBegan(pTouch, pEvent) 继续响应;
//    return false;
//}
