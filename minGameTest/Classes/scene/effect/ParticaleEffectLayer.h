//
//  ParticaleEffectLayer.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//

#ifndef minGameTest_ParticaleEffectLayer_h
#define minGameTest_ParticaleEffectLayer_h


#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../manager/UIManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ParticaleEffectLayer:
public BaseLayer,
public cocos2d::extension::CCBSelectorResolver,
public cocos2d::extension::CCBMemberVariableAssigner,
public NodeLoaderListener
{   
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ParticaleEffectLayer, create);     
      
    ParticaleEffectLayer();    
    virtual ~ParticaleEffectLayer();          
       
    virtual void onEnter();
    virtual void onExit();
    //
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char * pSelectorName);
    virtual Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode);
        
    virtual void onNodeLoaded(cocos2d::Node * node, NodeLoader * nodeLoader);
    
private:   
    
};







#endif
