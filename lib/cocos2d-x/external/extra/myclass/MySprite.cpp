//
//  MySprite.cpp
//  quickcocos2dx
//
//  Created by WenyongLi on 7/23/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#include "MySprite.h"
MySprite* MySprite::createMS(const char* fileName){
    MySprite* sp = new MySprite();
    if(sp && sp->initWithFile(fileName)){
        sp->setPosition(ccp(100,100));
        sp->autorelease();
        return sp;
    }
    CC_SAFE_DELETE(sp);
    return NULL;
}