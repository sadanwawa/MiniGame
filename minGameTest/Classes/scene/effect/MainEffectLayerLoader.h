//
//  MainEffectLayerLoader.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//
#ifndef minGameTest_MainEffectLayerLoader_h
#define minGameTest_MainEffectLayerLoader_h
#include "MainEffectLayer.h"

/* Forward declaration. */
class CCBReader;
class MainEffectLayerLoader : public cocos2d::extension::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainEffectLayerLoader, loader);    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainEffectLayer);
};
#endif
