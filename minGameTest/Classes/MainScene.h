//
//  MainScene.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-15.
//
//

#ifndef minGameTest_MainScene_h
#define minGameTest_MainScene_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "HelloWorldScene.h"
//#include "UIManager.h"
#include "core/BaseScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MainScene: public BaseScene{
    
public:
    
    MainScene();    
    virtual ~MainScene();
    
    virtual void onEnter();
    
    virtual bool init();//覆盖
    
    static cocos2d::Scene* scene();//覆盖
    
    CREATE_FUNC(MainScene);//覆盖

    void menuCloseCallback(Object* pSender);
    
        
protected:
    
    void touchDownAction(Object *senderz, Control::EventType controlEvent);       
    void touchDragInsideAction(Object *sender, Control::EventType controlEvent);
    void touchDragOutsideAction(Object *sender, Control::EventType controlEvent);        
    void touchDragEnterAction(Object *sender, Control::EventType controlEvent);    
    void touchDragExitAction(Object *sender, Control::EventType controlEvent);     
    void touchUpInsideAction(Object *sender, Control::EventType controlEvent);     
    void touchUpOutsideAction(Object *sender, Control::EventType controlEvent);       
    void touchCancelAction(Object *sender, Control::EventType controlEvent);
    
private:
    
    
    

};


#endif
