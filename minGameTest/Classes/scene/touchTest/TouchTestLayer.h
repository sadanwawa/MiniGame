//
//  TouchTestLayer.h
//  minGameTest
//
//  Created by 马 英臣 on 13-9-13.
//
//

#ifndef minGameTest_TouchTestLayer_h
#define minGameTest_TouchTestLayer_h


#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../manager/UIManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TouchTestLayer:
public BaseLayer,
public cocos2d::extension::CCBSelectorResolver,
public cocos2d::extension::CCBMemberVariableAssigner,
public NodeLoaderListener
{   
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(TouchTestLayer, create);     
      
    TouchTestLayer();    
    virtual ~TouchTestLayer();
        
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool init();
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char * pSelectorName);
    virtual Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(Object * pTarget, const char * pMemberVariableName, cocos2d::Node * node);
    virtual bool onAssignCCBCustomProperty(Object* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::Node * node, NodeLoader * nodeLoader);
    virtual bool ccTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    
    virtual void registerWithTouchDispatcher(void);
    
private:
    
    void onClickClose(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickClose1(cocos2d::Object * sender);
    void onClickClose2(cocos2d::Object * sender);
    
    LayerColor* mpcolorLayer;
    
    
};







#endif
