//
//  MainUILayer.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//

#ifndef minGameTest_MainUILayer_h
#define minGameTest_MainUILayer_h


#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../manager/UIManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MainUILayer:
public BaseLayer,
public cocos2d::extension::CCBSelectorResolver,
public cocos2d::extension::CCBMemberVariableAssigner,
public NodeLoaderListener

{   
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(MainUILayer, create);     
      
    MainUILayer();    
    virtual ~MainUILayer();
        
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool init();
    
    virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(Object * pTarget, const char * pSelectorName);
    virtual Control::Handler onResolveCCBCCControlSelector(Object * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(Object * pTarget, const char * pMemberVariableName, cocos2d::Node * node);
    virtual bool onAssignCCBCustomProperty(Object* pTarget, const char* pMemberVariableName, cocos2d::extension::CCBValue* pCCBValue);
    virtual void onNodeLoaded(cocos2d::Node * node, NodeLoader * nodeLoader);
                   
    void onClickMulPopUp(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickAnimation(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickScrollList(cocos2d::Object * sender, Control::EventType pControlEvent);    
    void onClickClose(cocos2d::Object * sender, Control::EventType pControlEvent);
    
    void onClickEffect(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickTestMulCCBI(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickMovie(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickSound(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickTouchTest(cocos2d::Object * sender, Control::EventType pControlEvent);
    void onClickTestEvent(cocos2d::Object * sender, Control::EventType pControlEvent);
    
    
    virtual bool ccTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);   
    
//    virtual void registerWithTouchDispatcher(void);
    
private:    
    void helloCommandTest(INotification const& notification);
    
};







#endif
