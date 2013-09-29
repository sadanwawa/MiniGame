//
//  ParticaleEffectLayerLoader.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//
#ifndef minGameTest_ParticaleEffectLayerLoader_h
#define minGameTest_ParticaleEffectLayerLoader_h
#include "ParticaleEffectLayer.h"

/* Forward declaration. */
class CCBReader;
class ParticaleEffectLayerLoader : public cocos2d::extension::NodeLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ParticaleEffectLayerLoader, loader);    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ParticaleEffectLayer);
};
#endif
