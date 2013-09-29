//
//  MainItemLayerLoader.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//
#ifndef minGameTest_MainItemLayerLoader_h
#define minGameTest_MainItemLayerLoader_h
#include "MainItemLayer.h"

/* Forward declaration. */
class CCBReader;
class MainItemLayerLoader : public cocos2d::extension::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(MainItemLayerLoader, loader);    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(MainItemLayer);
};
#endif
