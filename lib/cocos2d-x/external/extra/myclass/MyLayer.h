//
//  MyLayer.h
//  quickcocos2dx
//
//  Created by lee on 7/26/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#ifndef __quickcocos2dx__MyLayer__
#define __quickcocos2dx__MyLayer__

#include <iostream>
#include "cocos2d.h"

class MyLayer : public cocos2d::CCLayer//RGBA
{
public:
    MyLayer();
    ~MyLayer();
    float getHeight();
    CC_PROPERTY(GLubyte, m_nOpacity, Opacity)
public:
    static MyLayer *create(void);
};
#endif /* defined(__quickcocos2dx__MyLayer__) */
