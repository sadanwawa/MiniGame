//
//  ParticaleEffectLayer.cpp
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
// 播放Layer中的粒子特效
//

#include "ParticaleEffectLayer.h"

ParticaleEffectLayer::ParticaleEffectLayer()
{
  
}
ParticaleEffectLayer::~ParticaleEffectLayer(){
    CCLOG("ParticaleEffectLayer删除。");
    
}

void ParticaleEffectLayer::onNodeLoaded(cocos2d::Node * node, cocos2d::extension::NodeLoader * nodeLoader){
        
}

void ParticaleEffectLayer::onEnter(){
    BaseLayer::onEnter();    
}
void ParticaleEffectLayer::onExit(){
    BaseLayer::onExit();    
}

SEL_MenuHandler ParticaleEffectLayer::onResolveCCBCCMenuItemSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //菜单事件
    
    return NULL;
}
Control::Handler ParticaleEffectLayer::onResolveCCBCCControlSelector(cocos2d::Object * pTarget, const char * pSelectorName){
    //按钮事件    
    return NULL;
}
bool ParticaleEffectLayer::onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode){
    //显示对象   
    return false;
}
