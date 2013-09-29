//
//  ParticaleAttEffect.h
//  minGameTest
//
//  Created by 马 英臣 on 13-8-20.
//
//

#ifndef minGameTest_ParticaleAttEffect_h
#define minGameTest_ParticaleAttEffect_h


#include "cocos2d.h"
#include "cocos-ext.h"
#include "../../manager/UIManager.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ParticaleAttEffect:
public Node,
public NodeLoaderListener

{   
public:
    
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ParticaleAttEffect, create);     
      
    ParticaleAttEffect();    
    virtual ~ParticaleAttEffect();        
       
    virtual void onNodeLoaded(cocos2d::Node * node, NodeLoader * nodeLoader);
       
    
private:   
    
};







#endif
