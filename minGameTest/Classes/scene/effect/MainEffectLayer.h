//
//  MainEffectLayer.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//

#ifndef minGameTest_MainEffectLayer_h
#define minGameTest_MainEffectLayer_h


#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../manager/UIManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MainEffectLayer:
public BaseLayer,
public cocos2d::extension::CCBSelectorResolver,
public cocos2d::extension::CCBMemberVariableAssigner,
public NodeLoaderListener
{   
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MainEffectLayer, create);     
    
//    static MainEffectLayer * create() { 
//        MainEffectLayer * ptr = new MainEffectLayer(); 
//        if(ptr != NULL && ptr->init()) { 
//            ptr->autorelease(); 
//            return ptr; 
//        } 
//        CC_SAFE_DELETE(ptr); 
//        return NULL; 
//    }    
    
    MainEffectLayer();    
    virtual ~MainEffectLayer();
        
    virtual void onEnter();
    virtual void onExit();    
    virtual bool init();
//
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char * pSelectorName);
    virtual Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(Object* pTarget, const char* pMemberVariableName, Node* pNode);
    virtual void onNodeLoaded(cocos2d::Node * node, NodeLoader * nodeLoader);
 
    void onClickAttack(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickClose(cocos2d::Object * sender, Control::EventType pControlEvent);
    
    void onClickAddEffect(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickRemoveEffect(cocos2d::Object * sender, Control::EventType pControlEvent);
    
    
////    virtual bool onAssignCCBCustomProperty(Object* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    
//                
//    virtual bool ccTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);   
    
//    virtual void registerWithTouchDispatcher(void);
    
private:
    
    Sprite* spriteA;
    Sprite* spriteB;
    Sprite* touch_test_btn;

    
    
    void moveToTarget();
    void beHitEffect();
    void removeOnceAttEffect();
};

#endif
