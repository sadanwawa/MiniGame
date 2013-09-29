//
//  StaticConstant.h
//  
//  Created by yinghcen ma on 13-8-19.
//  Copyright (c) 2013年 RenRenGame. All rights reserved.
//

#ifndef minGameTest_StaticConstant_h
#define minGameTest_StaticConstant_h

#include "cocos2d.h"

USING_NS_CC;

namespace STC {
    
    //.plist
    static const std::string PLIST_UITEST     = "ui_test.plist";
    
    // image for single 单张的图片
    static const std::string IMAGE_HELLOWORLD     = "HelloWorld.png";
    static const std::string IMAGE_CLOSENORMAL     = "CloseNormal.png";
    static const std::string IMAGE_CLOSESELECT     = "CloseSelected.png";
    
    
    
    // FRAME  打包到plist中的图片
    static const std::string FRAME_BTN1_NORMAL = "2013010821593531.png";
    static const std::string FRAME_BTN1_SELECT = "2013010821593552.png";
        
    //xml    
        
    //sound   
}

//UserDefault 中的字段
namespace UserDefaultConst {       
    static const std::string USER_ID = "User_Id";
    static const std::string USER_TOKEN = "User_Token";
    static const std::string USER_THIRDID = "User_ThirdId";
}

#endif
