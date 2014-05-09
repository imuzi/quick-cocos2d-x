//
//  MySprite.h
//  quickcocos2dx
//
//  Created by WenyongLi on 7/23/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#ifndef __quickcocos2dx__MySprite__
#define __quickcocos2dx__MySprite__


#include "cocos2d.h"
using namespace cocos2d;

class MySprite : public CCSprite{
public:
    static MySprite* createMS(const char* fileName);
};


#endif /* defined(__quickcocos2dx__MySprite__) */
