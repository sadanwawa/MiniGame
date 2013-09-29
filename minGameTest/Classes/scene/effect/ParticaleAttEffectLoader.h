//
//  ParticaleAttEffectLoader.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//
#ifndef minGameTest_ParticaleAttEffectLoader_h
#define minGameTest_ParticaleAttEffectLoader_h
#include "ParticaleAttEffect.h"

/* Forward declaration. */
class CCBReader;
class ParticaleAttEffectLoader : public cocos2d::extension::NodeLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ParticaleAttEffectLoader, loader);    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ParticaleAttEffect);
};
#endif
