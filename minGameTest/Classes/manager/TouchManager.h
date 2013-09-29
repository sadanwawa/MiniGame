//
//  TouchManager.h
//  minGameTest
//
//  Created by 马 英臣 on 13-9-3.
//
//

#ifndef minGameTest_TouchManager_h
#define minGameTest_TouchManager_h

#include "cocos2d.h"
#include "../core/Singleton.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TouchManager : public Singleton<TouchManager>, public Object
{
public:
    TouchManager();
    ~TouchManager();
    
    virtual bool initialize();
    

};

#endif
