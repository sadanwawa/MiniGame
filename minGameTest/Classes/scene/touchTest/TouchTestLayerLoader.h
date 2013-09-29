//
//  TouchTestLayerLoader.h
//  minGameTest
//
//  Created by 马 英臣 on 13-9-13.
//
//
#ifndef minGameTest_TouchTestLayerLoader_h
#define minGameTest_TouchTestLayerLoader_h
#include "TouchTestLayer.h"

/* Forward declaration. */
class CCBReader;
class TouchTestLayerLoader : public cocos2d::extension::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TouchTestLayerLoader, loader);    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(TouchTestLayer);
};
#endif
