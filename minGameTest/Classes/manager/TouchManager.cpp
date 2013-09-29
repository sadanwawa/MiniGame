//
//  TouchManager.cpp
//  minGameTest
//
//  Created by 马 英臣 on 13-9-3.
//
//

#include "TouchManager.h"

// singleton instance pointer
template<> TouchManager* Singleton<TouchManager>::msSingleton	= NULL;
TouchManager::TouchManager(){
    
};
TouchManager::~TouchManager(){
    
};

bool TouchManager::initialize(){
    
    return true;
};

