//
//  MyLayer.cpp
//  quickcocos2dx
//
//  Created by lee on 7/26/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#include "MyLayer.h"

using namespace cocos2d;

MyLayer::MyLayer()
{
}
MyLayer::~MyLayer()
{
}


MyLayer *MyLayer::create()
{
    MyLayer *pRet = new MyLayer();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        pRet->m_nOpacity = 0;
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
GLubyte MyLayer::getOpacity(void){
    return m_nOpacity;
}
void MyLayer::setOpacity(GLubyte opacity)
{
//    --CCLog("setpoppocdi~~~~~~~~~~~~~~~~~~~~~~~~~");
    m_nOpacity = opacity;
    CCObject* child;
    CCARRAY_FOREACH(m_pChildren, child)
    {
        CCNode* pNode = (CCNode*)child;
//        cocos2d::CCRGBAProtocol *pRGBAProtocol = dynamic_cast<cocos2d::CCRGBAProtocol*>(pNode);
        if (pNode)
        {
            pNode->setOpacity(opacity);
        }
    }
    CCLayer::setOpacity(opacity);
}


float MyLayer::getHeight(){
//    CCObject* child =NULL;
    CCNode* child = dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(0));
    float minpos=0;
    
    float maxheight = 0;
//    CCARRAY_FOREACH(m_pChildren, child)
    for (int aa=0;aa<(m_pChildren->count());aa++)
    {
        CCNode* pNode = dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa));
//        if (dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getPositionY()<0){
//            
//        }
        if (dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getPositionY()!=0) {
            
            printf("dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getPositionY()==%f",dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getPositionY()) ;
            
            
            
            
            (dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getPositionY()
             -dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getContentSize().height/2)<minpos?
            minpos=(dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getPositionY()-dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getContentSize().height/2),child=dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa)):0;
            
            printf("minheight=%f \n",dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getPositionY()-dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getContentSize().height/2);
            printf("childminpos=%f\n",child->getPositionY());
            
            maxheight = dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getPositionY()-dynamic_cast<CCNode*>(m_pChildren->objectAtIndex(aa))->getContentSize().height/2;
            
            printf("----------------++maxheight=%f\n",maxheight);
            printf("++++++++++++++++minheight=%f\n",minpos);
            
            

        }
        else {
      
        
        }
        
//        printf("aa=%d",aa);   
    }
    printf("$getContentSize= %f,%f",child->getContentSize().width,child->getContentSize().height);
    printf("$minposminposminposminposminposminpos= %f",minpos);
//    if (minpos<0) {
//        return child->getContentSize().height/2 - minpos+CCDirector::sharedDirector()->getWinSize().height;
//    }
    
    return CCDirector::sharedDirector()->getWinSize().height - minpos;
}

    
    
    
    
