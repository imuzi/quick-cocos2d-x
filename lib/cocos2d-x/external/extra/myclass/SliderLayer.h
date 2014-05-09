//
//  SliderLayer.h
//  quickcocos2dx
//
//  Created by lee on 8/21/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#ifndef __quickcocos2dx__SliderLayer__
#define __quickcocos2dx__SliderLayer__

#include "cocos2d.h"
#include <iostream>

USING_NS_CC;


class SliderLayer : public CCLayer
{
public:
    SliderLayer();
    virtual ~SliderLayer();
    
    static SliderLayer *create(void);
    
    
    
    void registerWithTouchDispatcher();
    
    
    void setContentOffset(CCPoint offset, bool animated = false);
    
//    CCPoint minContainerOffset();
//    CCPoint maxContainerOffset();
    
    
    virtual int ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual int ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
   


private:

//    void relocateContainer(bool animated);
 
    void deaccelerateScrolling(float dt);

    
protected:
//    CCRect getViewRect();
    
    /**
     * current zoom scale
     */
    float m_fZoomScale;
    /**
     * min zoom scale
     */
    float m_fMinZoomScale;
    /**
     * max zoom scale
     */
    float m_fMaxZoomScale;
    bool m_bDragging;
    
    /**
     * Content offset. Note that left-bottom point is the origin
     */
    CCPoint m_tContentOffset;
    
    /**
     * Container holds scroll view contents, Sets the scrollable container object of the scroll view
     */
    CCNode* m_pContainer;
    /**
     * Determiens whether user touch is moved after begin phase.
     */
    bool m_bTouchMoved;
    /**
     * max inset point to limit scrolling by touch
     */
    CCPoint m_fMaxInset;
    /**
     * min inset point to limit scrolling by touch
     */
    CCPoint m_fMinInset;
    /**
     * Determines whether the scroll view is allowed to bounce or not.
     */
    bool m_bBounceable;
    
    bool m_bClippingToBounds;
    
    /**
     * scroll speed
     */
    CCPoint m_tScrollDistance;
    /**
     * Touch point
     */
    CCPoint m_tTouchPoint;
    /**
     * length between two fingers
     */
    float m_fTouchLength;
    /**
     * UITouch objects to detect multitouch
     */
    CCArray* m_pTouches;
    /**
     * size to clip. CCNode boundingBox uses contentSize directly.
     * It's semantically different what it actually means to common scroll views.
     * Hence, this scroll view will use a separate size property.
     */
    CCSize m_tViewSize;
    /**
     * max and min scale
     */
    float m_fMinScale, m_fMaxScale;
    /**
     * scissor rect for parent, just for restoring GL_SCISSOR_BOX
     */
    CCRect m_tParentScissorRect;
    bool m_bScissorRestored;
};



#endif /* defined(__quickcocos2dx__SliderLayer__) */
