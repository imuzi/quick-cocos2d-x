//
//  SliderLayer.cpp
//  quickcocos2dx
//
//  Created by lee on 8/21/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#include "SliderLayer.h"

#define SCROLL_DEACCEL_RATE  0.95f
#define SCROLL_DEACCEL_DIST  1.0f
#define BOUNCE_DURATION      0.15f
#define INSET_RATIO          0.2f
#define MOVE_INCH            7.0f/160.0f


SliderLayer::SliderLayer()
: m_fZoomScale(0.0f)
, m_fMinZoomScale(0.0f)
, m_fMaxZoomScale(0.0f)
, m_bDragging(false)
, m_bTouchMoved(false)
, m_bBounceable(false)
, m_bClippingToBounds(false)
, m_fTouchLength(0.0f)
, m_pTouches(NULL)
, m_fMinScale(0.0f)
, m_fMaxScale(0.0f)
{
    m_pTouches = new CCArray();
}

SliderLayer::~SliderLayer()
{
    m_pTouches->release();
}


SliderLayer* SliderLayer::create()
{
    SliderLayer* pRet = new SliderLayer();
    
    if (pRet && pRet->init())
    {
        
        pRet->setTouchEnabled(true);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}


void SliderLayer::setContentOffset(CCPoint offset, bool animated){

    this->setPosition(offset);

};

void SliderLayer::deaccelerateScrolling(float dt)
{
    if (m_bDragging)
    {
        this->unschedule(schedule_selector(SliderLayer::deaccelerateScrolling));
        return;
    }
    
    float newX, newY;
    CCPoint maxInset, minInset;
    
    this->setPosition(ccpAdd(this->getPosition(), m_tScrollDistance));
    
    if (m_bBounceable)
    {
        maxInset = m_fMaxInset;
        minInset = m_fMinInset;
    }
    else
    {
        maxInset = ccp(0,1800);
        minInset = ccp(0,0);;
    }
    
    //check to see if offset lies within the inset bounds
    newX     = MIN(this->getPosition().x, maxInset.x);
    newX     = MAX(newX, minInset.x);
    newY     = MIN(this->getPosition().y, maxInset.y);
    newY     = MAX(newY, minInset.y);
    
    newX = this->getPosition().x;
    newY = this->getPosition().y;
    
    m_tScrollDistance     = ccpSub(m_tScrollDistance, ccp(newX - this->getPosition().x, newY - this->getPosition().y));
    m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE);
    this->setContentOffset(ccp(newX,newY));
    
    if ((fabsf(m_tScrollDistance.x) <= SCROLL_DEACCEL_DIST &&
         fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST) ||
        newY > maxInset.y || newY < minInset.y ||
        newX > maxInset.x || newX < minInset.x ||
        newX == maxInset.x || newX == minInset.x ||
        newY == maxInset.y || newY == minInset.y)
    {
        this->unschedule(schedule_selector(SliderLayer::deaccelerateScrolling));
       
    }
}


void SliderLayer::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, CCLayer::getTouchPriority(), false);
}

int SliderLayer::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if (!this->isVisible())
    {
        return false;
    }
   
//    CCRect frame = getViewRect();
    
    //dispatcher does not know about clipping. reject touches outside visible bounds.
//    if (m_pTouches->count() > 2 ||
//        m_bTouchMoved          ||
//        !frame.containsPoint(this->convertToWorldSpace(this->convertTouchToNodeSpace(touch))))
//    {
//        return false;
//    }
    
    if (!m_pTouches->containsObject(touch))
    {
        m_pTouches->addObject(touch);
    }
    
    if (m_pTouches->count() == 1)
    { // scrolling
        m_tTouchPoint     = this->convertTouchToNodeSpace(touch);
        m_bTouchMoved     = false;
        m_bDragging     = true; //dragging started
        m_tScrollDistance = ccp(0.0f, 0.0f);
        m_fTouchLength    = 0.0f;
    }
    else if (m_pTouches->count() == 2)
    {
        m_tTouchPoint  = ccpMidpoint(this->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(0)),
                                     this->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(1)));
        m_fTouchLength = ccpDistance(this->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(0)),
                                     this->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(1)));
        m_bDragging  = false;
    }
    return true;
}

int SliderLayer::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    if (!this->isVisible())
    {
        return 0 ;
    }
    if (m_pTouches->containsObject(touch))
    {
        if (m_pTouches->count() == 1 && m_bDragging)
        { // scrolling
            CCPoint moveDistance, newPoint, maxInset, minInset;
            CCRect  frame;
            float newX, newY;
            
            m_bTouchMoved  = true;
//            CCPoint frameOriginal = this->getParent()->convertToWorldSpace(this->getPosition());
//            frame = CCRectMake(frameOriginal.x, frameOriginal.y, m_tViewSize.width, m_tViewSize.height);
            
//            newPoint     = this->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(0));
            newPoint = this->convertTouchToNodeSpace(touch);

            moveDistance = ccpSub(newPoint, m_tTouchPoint);
            m_tTouchPoint  = newPoint;
            
           
            moveDistance = ccp(0.0f, moveDistance.y);
                  
//                        moveDistance = ccp(moveDistance.x, 0.0f);
            printf("\nmoveDistance=%f\n",moveDistance.y);
                this->setPosition(ccpAdd(this->getPosition(), moveDistance));
//            this->setPosition(ccp(this->getPositionX(),touch->getLocation().y));
                maxInset = ccp(0,1800);
                minInset = ccp(0,0);
            
                
                //check to see if offset lies within the inset bounds
                newX     = MIN(this->getPosition().x, maxInset.x);
                newX     = MAX(newX, minInset.x);
                newY     = MIN(this->getPosition().y, maxInset.y);
                newY     = MAX(newY, minInset.y);
                
                m_tScrollDistance     = ccpSub(moveDistance, ccp(newX - this->getPosition().x, newY - this->getPosition().y));
//                this->setContentOffset(ccp(newX, newY));
                           }
        }
    
    
    printf("m_tScrollDistance.y=%f",m_tScrollDistance.y);
}

void SliderLayer::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    if (!this->isVisible())
    {
        return;
    }
    if (m_pTouches->containsObject(touch))
    {
        if (m_pTouches->count() == 1 && m_bTouchMoved)
        {
            this->schedule(schedule_selector(SliderLayer::deaccelerateScrolling));
        }
        m_pTouches->removeObject(touch);
    }
    
    if (m_pTouches->count() == 0)
    {
        m_bDragging = false;
        m_bTouchMoved = false;
    }
}

void SliderLayer::ccTouchCancelled(CCTouch* touch, CCEvent* event)
{
    if (!this->isVisible())
    {
        return;
    }
    m_pTouches->removeObject(touch);
    if (m_pTouches->count() == 0)
    {
        m_bDragging = false;    
        m_bTouchMoved = false;
    }
}

