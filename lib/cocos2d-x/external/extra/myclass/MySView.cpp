
#include "MySView.h"
#include "cocos2d.h"
#include "actions/CCActionInterval.h"
#include "actions/CCActionTween.h"
#include "actions/CCActionInstant.h"
#include "support/CCPointExtension.h"
#include "touch_dispatcher/CCTouchDispatcher.h"
#include "effects/CCGrid.h"
#include "CCDirector.h"
#include "kazmath/GL/matrix.h"
#include "touch_dispatcher/CCTouch.h"
#include "CCEGLView.h"

#include "cocos-ext.h"


USING_NS_CC_EXT;


USING_NS_CC;
NS_CC_EXT_BEGIN

//速度下降的比例

#define SCROLL_DEACCEL_RATE  0.991f

#define SCROLL_DEACCEL_DIST  0.35f

#define INDEX_NUM  13
#define STOP_AREA 24
#define STOP_AREATO  0
//停止的元素0为测试 1到5行的
#define ELEM0  5
#define ELEM1  5
#define ELEM2  3
#define ELEM3  5
#define ELEM4  9
#define ELEM5  8

//多久开始判断停止位置 越少婷的越晚 也越容易听不到位置
#define SCROLL_STOP  23.0f
#define SCROLL_STOP5 20
#define SCROLL_STOP4  126
#define SCROLL_STOP3  134
#define SCROLL_STOP2  40
#define SCROLL_STOP1  50.0f

#define BOUNCE_DURATION      0.15f
#define INSET_RATIO          0.000000000000001f
    #define MAX_SCROLL          400
    #define MAX_SCROLLS          300


MySView::MySView()
: m_fZoomScale(0.0f)
, m_fMinZoomScale(0.0f)
, m_fMaxZoomScale(0.0f)
, m_pDelegate(NULL)
, m_bDragging(false)
, m_bBounceable(false)
, m_eDirection(kMySViewDirectionBoth)
, m_bClippingToBounds(false)
, m_pContainer(NULL)
, m_bTouchMoved(false)
,m_isautoScroll(false)
, m_fTouchLength(0.0f)
, m_pTouches(NULL)
, m_fMinScale(0.0f)
, m_fMaxScale(0.0f)
, touched_(false)
, data(NULL)
{
    
    data = CData::getAmInstance();
    CCLog("mysview_newwwwww+++++++++++++++++++");
}

MySView::~MySView()
{
    m_pTouches->release();
}

MySView* MySView::viewWithViewSize(CCSize size, CCNode* container/* = NULL*/)
{
    return MySView::create(size, container);
}

MySView* MySView::create(CCSize size, CCNode* container/* = NULL*/)
{
    MySView* pRet = new MySView();
    if (pRet && pRet->initWithViewSize(size, container))
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}

MySView* MySView::node()
{
    return MySView::create();
}

MySView* MySView::create()
{
    MySView* pRet = new MySView();
    if (pRet && pRet->init())
    {
        pRet->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(pRet);
    }
    return pRet;
}


bool MySView::initWithViewSize(CCSize size, CCNode *container/* = NULL*/)
{
    if (CCLayer::init())
    {
        m_pContainer = container;
        
        if (!this->m_pContainer)
        {
            m_pContainer = CCLayer::create();
            this->m_pContainer->ignoreAnchorPointForPosition(false);
            this->m_pContainer->setAnchorPoint(ccp(0.0f, 0.0f));
        }

        this->setViewSize(size);

        setTouchEnabled(true);
        m_pTouches = new CCArray();
        m_pDelegate = NULL;
        m_bBounceable = true;
        m_bClippingToBounds = true;
        //m_pContainer->setContentSize(CCSizeZero);
        m_eDirection  = kMySViewDirectionBoth;
        m_pContainer->setPosition(ccp(0.0f, 0.0f));
        m_fTouchLength = 0.0f;
        
        this->addChild(m_pContainer);
        m_fMinScale = m_fMaxScale = 1.0f;
        return true;
    }
    return false;
}

bool MySView::init()
{
    return this->initWithViewSize(CCSizeMake(200, 200), NULL);
}

void MySView::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
}

bool MySView::isNodeVisible(CCNode* node)
{
    const CCPoint offset = this->getContentOffset();
    const CCSize  size   = this->getViewSize();
    const float   scale  = this->getZoomScale();
    
    CCRect viewRect;
    
    viewRect = CCRectMake(-offset.x/scale, -offset.y/scale, size.width/scale, size.height/scale); 
    
    return viewRect.intersectsRect(node->boundingBox());
}

void MySView::pause(CCObject* sender)
{
    m_pContainer->pauseSchedulerAndActions();

    CCObject* pObj = NULL;
    CCArray* pChildren = m_pContainer->getChildren();

    CCARRAY_FOREACH(pChildren, pObj)
    {
        CCNode* pChild = (CCNode*)pObj;
        pChild->pauseSchedulerAndActions();
    }
}

void MySView::resume(CCObject* sender)
{
    CCObject* pObj = NULL;
    CCArray* pChildren = m_pContainer->getChildren();

    CCARRAY_FOREACH(pChildren, pObj)
    {
        CCNode* pChild = (CCNode*)pObj;
        pChild->resumeSchedulerAndActions();
    }

    m_pContainer->resumeSchedulerAndActions();
}

void MySView::setTouchEnabled(bool e)
{
    CCLayer::setTouchEnabled(e);
    if (!e)
    {
        m_bDragging = false;
        m_bTouchMoved = false;
        m_pTouches->removeAllObjects();
    }
}

void MySView::setContentOffset(CCPoint offset, bool animated/* = false*/)
{
    if (animated)
    { //animate scrolling
        this->setContentOffsetInDuration(offset, BOUNCE_DURATION);
    } 
    else
    { //set the container position directly
        if (!m_bBounceable)
        {

            CCLOG("~~~~~~~~~~~~~~~~~~~m_bonnde");
            const CCPoint minOffset = this->minContainerOffset();
            const CCPoint maxOffset = this->maxContainerOffset();
            
            offset.x = MAX(minOffset.x, MIN(maxOffset.x, offset.x));
            offset.y = MAX(minOffset.y, MIN(maxOffset.y, offset.y));
        }
    
        m_pContainer->setPosition(offset);

        if (m_pDelegate != NULL)
        {
         //   CCLOG("scrooview didslcos!");
            m_pDelegate->scrollViewDidScroll(this);   
        }
    }
}

void MySView::setContentOffsetInDuration(CCPoint offset, float dt)
{
    CCFiniteTimeAction *scroll, *expire;
    
    scroll = CCMoveTo::create(dt, offset);
    expire = CCCallFuncN::create(this, callfuncN_selector(MySView::stoppedAnimatedScroll));
    m_pContainer->runAction(CCSequence::create(scroll, expire, NULL));
    this->schedule(schedule_selector(MySView::performedAnimatedScroll));
}

CCPoint MySView::getContentOffset()
{
    return m_pContainer->getPosition();
}

void MySView::setZoomScale(float s)
{
    if (m_pContainer->getScale() != s)
    {
        CCPoint oldCenter, newCenter;
        CCPoint center;
        
        if (m_fTouchLength == 0.0f) 
        {
            center = ccp(m_tViewSize.width*0.5f, m_tViewSize.height*0.5f);
            center = this->convertToWorldSpace(center);
        }
        else
        {
            center = m_tTouchPoint;
        }
        
        oldCenter = m_pContainer->convertToNodeSpace(center);
        m_pContainer->setScale(MAX(m_fMinScale, MIN(m_fMaxScale, s)));
        newCenter = m_pContainer->convertToWorldSpace(oldCenter);
        
        const CCPoint offset = ccpSub(center, newCenter);
        if (m_pDelegate != NULL)
        {
            m_pDelegate->scrollViewDidZoom(this);
        }
        this->setContentOffset(ccpAdd(m_pContainer->getPosition(),offset));
    }
}

float MySView::getZoomScale()
{
    return m_pContainer->getScale();
}

void MySView::setZoomScale(float s, bool animated)
{
    if (animated)
    {
        this->setZoomScaleInDuration(s, BOUNCE_DURATION);
    }
    else
    {
        this->setZoomScale(s);
    }
}

void MySView::setZoomScaleInDuration(float s, float dt)
{
    if (dt > 0)
    {
        if (m_pContainer->getScale() != s)
        {
            CCActionTween *scaleAction;
            scaleAction = CCActionTween::create(dt, "zoomScale", m_pContainer->getScale(), s);
            this->runAction(scaleAction);
        }
    }
    else
    {
        this->setZoomScale(s);
    }
}

void MySView::setViewSize(CCSize size)
{
    m_tViewSize = size;
    CCLayer::setContentSize(size);
}

CCNode * MySView::getContainer()
{
    return this->m_pContainer;
}

void MySView::setContainer(CCNode * pContainer)
{
    this->removeAllChildrenWithCleanup(true);

    if (!pContainer) return;

    this->m_pContainer = pContainer;

    this->m_pContainer->ignoreAnchorPointForPosition(false);
    this->m_pContainer->setAnchorPoint(ccp(0.0f, 0.0f));

    this->addChild(this->m_pContainer);

    this->setViewSize(this->m_tViewSize);
}

void MySView::relocateContainer(bool animated)
{
    CCPoint oldPoint, min, max;
    float newX, newY;
    
    min = this->minContainerOffset();
    max = this->maxContainerOffset();
    
    oldPoint = m_pContainer->getPosition();

    newX     = oldPoint.x;
    newY     = oldPoint.y;
    if (m_eDirection == kMySViewDirectionBoth || m_eDirection == kMySViewDirectionHorizontal)
    {
        newX     = MIN(newX, max.x);
        newX     = MAX(newX, min.x);
    }

    if (m_eDirection == kMySViewDirectionBoth || m_eDirection == kMySViewDirectionVertical)
    {
        newY     = MIN(newY, max.y);
        newY     = MAX(newY, min.y);
    }

    if (newY != oldPoint.y || newX != oldPoint.x)
    {
        this->setContentOffset(ccp(newX, newY), animated);
    }
}

CCPoint MySView::maxContainerOffset()
{
    return ccp(0.0f, 0.0f);
}

CCPoint MySView::minContainerOffset()
{
    return ccp(m_tViewSize.width - m_pContainer->getContentSize().width*m_pContainer->getScaleX(), 
               m_tViewSize.height - m_pContainer->getContentSize().height*m_pContainer->getScaleY());
}

void MySView::autoScroll(CCPoint offset, bool animated /* = false */){
    m_bDragging=false;
    m_isautoScroll=true;
    //    if (CCRANDOM_0_1()*100>50)
    //    {
    //         m_tScrollDistance=-offset;
    //    }
    //    else{
    m_tScrollDistance.y=-offset.y;
    //    }
    child_h =  data->slotenmh;
    
    //m_tScrollDistance=offset;
    
    _mtscdistancex=offset.x;
    _mtscdistancey=offset.y;
    m_pContainer->stopAllActions();
    this->schedule(schedule_selector(MySView::deaccelerateScrolling));
    ////CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollBegin");
    
}


void MySView::deaccelerateScrolling(float dt)
{
    //CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    //    this->setTouchEnabled(false);
    
    
      
    
    float newX, newY;
    CCPoint maxInset, minInset;
    
    
    m_pContainer->setPosition(ccpAdd(m_pContainer->getPosition(), m_tScrollDistance));
    
    if (m_bBounceable)
    {
        maxInset = m_fMaxInset;
        minInset = m_fMinInset;
    }
    else
    {
        maxInset = this->maxContainerOffset();
        minInset = this->minContainerOffset();
    }
    
    //check to see if offset lies within the inset bounds
    newX     = MIN(m_pContainer->getPosition().x, maxInset.x);
    newX     = MAX(newX, minInset.x);
    newY     = MIN(m_pContainer->getPosition().y, maxInset.y);
    newY     = MAX(newY, minInset.y);
    
    //     CCLOG("newX,x=%f  newY.y=%f",newX,newY);
    //      CCLOG("minInset,x=%f  minInset.y=%f",minInset.x,minInset.y);
    
    //     m_tScrollDistance     = ccpSub(m_tScrollDistance, ccp(newX - m_pContainer->getPosition().x, newY - m_pContainer->getPosition().y));
    //
    //     m_tScrollDistance     = ccpSub(m_tScrollDistance, ccp(0, newY - m_pContainer->getPosition().y));
    
    //     if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST+2.0f)
    //         {
    //             if ((((int)fabsf(newY+138))%348)==0)
    //             {
    //                  m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE-0.09f);
    //             }
    //     }
    //    else{
    m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE);
    //  }
    //  }
    CCLOG("!@@@@@@mtscdistan.x=%f",m_tScrollDistance.y);
    //    CCLog("newY=%f",newY);
    
    this->setContentOffset(ccp(newX,newY));
    
    
    if ((newY==maxInset.y)&&m_tScrollDistance.y>0)
    {
        
        //        CCLog("++++++++mtscdistan.y=%f",m_tScrollDistance.y);
        this->setContentOffset(ccp(newX,minInset.y+child_h*((int)(data->slottableh/child_h+1))-data->slottableh));
        //        this->setContentOffset(ccp(newX,minInset.y+child_h-(960-(child_h*8/2))/2));
        
//        m_bDragging=false;
        //  this->relocateContainer(false);
        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
    }
    if ((newY==minInset.y)&&m_tScrollDistance.y<0)
    {
        CCLog("~~~~~~~~mtscdistan.y=%f",m_tScrollDistance.y);
        CCLog("maxInset.y==%f",maxInset.y);
        
        this->setContentOffset(ccp(newX,maxInset.y-child_h*((int)(data->slottableh/child_h+1))+data->slottableh));
        //this->relocateContainer(false);
        
        CCLog("child_h==%f;data->slottableh=%f",child_h,data->slottableh);
        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
//        m_bDragging=false;
    }
    
    if (m_bDragging)
    {
        for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
        {

        if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
        {
            
            if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== ELEM0) {
                this->unschedule(schedule_selector(MySView::deaccelerateScrolling));
                m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))))  ;
                this->relocateContainer(true);
                CCLog("++++++++++++++++++++++++++++++++++++");
            }
        }
        }
//        return;
    }

    
    if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST+SCROLL_STOP)
        //||fabsf(
        //         newX == maxInset.x || newX == minInset.x ||
        //         newY == maxInset.y || newY == minInset.y)
    {
        //         CCLog("!!!!!!!!FiNSL minInset.y==%f~~~~",minInset.y);
        //         CCLog("!!!!!!!!FiNSL m_tViewSize.height==%f~~~~",m_tViewSize.height );
        //         CCLog("!!!!!!!!FiNSL m_pContainer->getContentSize().height==%f~~~~",m_pContainer->getContentSize().height);
        //           CCLog("!!!!!!!!FiNSL m_pContainer.y==%f~~~~",m_pContainer->getPositionY());
        //    newY--;
        //         if ((((int)fabsf(newY+138))%348)==0)
        //         {
        //             CCLog("348~%d~~~",(int)m_pContainer->getPositionY());
        //             this->unschedule(schedule_selector(MySView::deaccelerateScrolling));
        //             this->relocateContainer(true);
        //             registerWithTouchDispatcher();
        //             //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)((int)(m_pContainer->getPositionY()-36)/348));
        //         }
        //         else{
        for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
        {
            
            
            if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
            {
                
                if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== ELEM0) {
                    this->unschedule(schedule_selector(MySView::deaccelerateScrolling));
                    m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))))  ;
                    this->relocateContainer(true);
                    CCLog("++++++++++++++++++++++++++++++++++++");
                }
//                this->unschedule(schedule_selector(MySView::deaccelerateScrolling));
//                m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))))  ;
//                
                
//                tstnum_++;
//                CCLog("testnum~~~~=%d",tstnum_);
                this->setTouchEnabled(true);
                
                CCLog("m_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
                CCLog("idxxx=%d",(int)fabs((m_pContainer->getPositionY()-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1));
                //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)abs((int)(m_pContainer->getPositionY()-36)/348-1));
                //  m_pContainer->runAction(CCMoveBy::create(3.0f*(abs(i))/174,ccp(0,5+i)));
            }
        }
        if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST){
            this->unschedule(schedule_selector(MySView::deaccelerateScrolling));
            this->relocateContainer(true);
            
            this->setTouchEnabled(true);
            
            CCLog("xxxxxxm_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
            //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)(abs((int)(m_pContainer->getPositionY()-36)/348-1)));
        }
        
        //  CCLog("letteris%d",(int)(m_pContainer->getPositionY()-36)/348);  
        //         CCLog("348~%d~~~",(int)m_pContainer->getContentSize().height);
    }
}

void MySView::readyToSpin1(){
    m_pContainer->stopAllActions();
    m_pContainer->runAction(CCSequence::create(CCEaseBackOut::create(CCMoveBy::create(1.5,ccp(0,25))),
                                               CCEaseSineIn::create(CCMoveBy::create(.5,ccp(0,-55))),
                                               CCCallFunc::create(this,callfunc_selector(MySView::setReadyBool1)),NULL));
    line1ready =false;
    data->line1End =false;
    
}
void MySView::setReadyBool1(){
    CCLog("REadyBoll========");
    line1ready = true;
    
}

void MySView::readyToSpin2(){
    m_pContainer->stopAllActions();
    m_pContainer->runAction(CCSequence::create(CCDelayTime::create(.1), CCEaseBackOut::create(CCMoveBy::create(1.5,ccp(0,25))),
                                               CCEaseSineIn::create(CCMoveBy::create(.5,ccp(0,-55))),
                                               CCCallFunc::create(this,callfunc_selector(MySView::setReadyBool2)),NULL));
    line2ready =false;
    data->line2End = false;
    
}
void MySView::setReadyBool2(){
    CCLog("REadyBoll========");
    line2ready = true;
    
}

void MySView::readyToSpin3(){
    m_pContainer->stopAllActions();
    m_pContainer->runAction(CCSequence::create(CCDelayTime::create(.2),CCEaseBackOut::create(CCMoveBy::create(1.5,ccp(0,25))),
                                               CCEaseSineIn::create(CCMoveBy::create(.5,ccp(0,-55))),
                                               CCCallFunc::create(this,callfunc_selector(MySView::setReadyBool3)),NULL));
    line3ready =false;
    data->line3End = false;
    
}
void MySView::setReadyBool3(){
    CCLog("REadyBoll========");
    line3ready = true;
    
}

void MySView::readyToSpin4(){
    m_pContainer->stopAllActions();
    m_pContainer->runAction(CCSequence::create(CCDelayTime::create(.3),CCEaseBackOut::create(CCMoveBy::create(1.5,ccp(0,25))),
                                               CCEaseSineIn::create(CCMoveBy::create(.5,ccp(0,-55))),
                                               CCCallFunc::create(this,callfunc_selector(MySView::setReadyBool4)),NULL));
    line4ready =false;
    data->line4End = false;
    
}
void MySView::setReadyBool4(){
    CCLog("REadyBoll========");
    line4ready = true;
    
}

void MySView::readyToSpin5(){
    m_pContainer->stopAllActions();
    m_pContainer->runAction(CCSequence::create(CCDelayTime::create(.4),CCEaseBackOut::create(CCMoveBy::create(1.5,ccp(0,25))),
                                               CCEaseSineIn::create(CCMoveBy::create(.5,ccp(0,-55))),
                                               CCCallFunc::create(this,callfunc_selector(MySView::setReadyBool5)),NULL));
    line5ready =false;
    data->line5End = false;
    
}
void MySView::setReadyBool5(){
    CCLog("REadyBoll========");
    line5ready = true;
    
}

///slotsusing
void MySView::autoScroll1(CCPoint offset, bool animated /* = false */){
    m_bDragging=false;
    m_isautoScroll=true;
    touched_ = false;
    
    //    if (CCRANDOM_0_1()*100>50)
    //    {
    //         m_tScrollDistance=-offset;
    //    }
    //    else{
   
    m_tScrollDistance.y=-offset.y;
    //    }
    child_h =  data->slotenmh;
    
    //m_tScrollDistance=offset;
    
    _mtscdistancex=offset.x;
    _mtscdistancey=offset.y;
   m_pContainer->stopAllActions();
    readyToSpin1();
    this->schedule(schedule_selector(MySView::deaccelerateScrolling1));
    ////CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollBegin");
    
}

void MySView::autoScroll2(CCPoint offset, bool animated /* = false */){
    m_bDragging=false;
    m_isautoScroll=true;
    touched_ = false;
    //    if (CCRANDOM_0_1()*100>50)
    //    {
    //         m_tScrollDistance=-offset;
    //    }
    //    else{
    m_tScrollDistance.y=-offset.y;
    //    }
    child_h =  data->slotenmh;
    
    //m_tScrollDistance=offset;
    
    _mtscdistancex=offset.x;
    _mtscdistancey=offset.y;
   m_pContainer->stopAllActions();
    
     readyToSpin2();
    this->schedule(schedule_selector(MySView::deaccelerateScrolling2));
    ////CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollBegin");
    
}

void MySView::autoScroll3(CCPoint offset, bool animated /* = false */){
    m_bDragging=false;
    m_isautoScroll=true;
    touched_ = false;
    //    if (CCRANDOM_0_1()*100>50)
    //    {
    //         m_tScrollDistance=-offset;
    //    }
    //    else{
    m_tScrollDistance.y=-offset.y;
    //    }
    child_h =  data->slotenmh;
    
    //m_tScrollDistance=offset;
    
    _mtscdistancex=offset.x;
    _mtscdistancey=offset.y;
    m_pContainer->stopAllActions();
    readyToSpin3();
    this->schedule(schedule_selector(MySView::deaccelerateScrolling3));
    ////CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollBegin");
    
}

void MySView::autoScroll4(CCPoint offset, bool animated /* = false */){
    m_bDragging=false;
    m_isautoScroll=true;
    touched_ = false;
    //    if (CCRANDOM_0_1()*100>50)
    //    {
    //         m_tScrollDistance=-offset;
    //    }
    //    else{
    m_tScrollDistance.y=-offset.y;
    //    }
    child_h =  data->slotenmh;
    
    //m_tScrollDistance=offset;
    
    _mtscdistancex=offset.x;
    _mtscdistancey=offset.y;
    m_pContainer->stopAllActions();
    readyToSpin4();
    this->schedule(schedule_selector(MySView::deaccelerateScrolling4));
    ////CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollBegin");
    
}

void MySView::autoScroll5(CCPoint offset, bool animated /* = false */){
    m_bDragging=false;
    m_isautoScroll=true;
    touched_ = false;
    //    if (CCRANDOM_0_1()*100>50)
    //    {
    //         m_tScrollDistance=-offset;
    //    }
    //    else{
    m_tScrollDistance.y=-offset.y;
    //    }
    child_h =  data->slotenmh;
    
    //m_tScrollDistance=offset;
    
    _mtscdistancex=offset.x;
    _mtscdistancey=offset.y;
    //m_pContainer->stopAllActions();
     readyToSpin5();
    this->schedule(schedule_selector(MySView::deaccelerateScrolling5));
    ////CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollBegin");
    
}


void MySView::deaccelerateScrolling1(float dt)
{
    //CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
//    this->setTouchEnabled(false);
    
//    m_pContainer->setPosition(ccp(0,0));
//    if (m_bDragging)
//    {
//        this->unschedule(schedule_selector(MySView::deaccelerateScrolling1));
//        return;
//    }
    if (!line1ready) {
        return;
    }
    
    float newX, newY;
    CCPoint maxInset, minInset;
    
   
    m_pContainer->setPosition(ccpAdd(m_pContainer->getPosition(), m_tScrollDistance));
    
    if (m_bBounceable)
    {
        maxInset = m_fMaxInset;
        minInset = m_fMinInset;
    }
    else
    {
        maxInset = this->maxContainerOffset();
        minInset = this->minContainerOffset();
    }
    
    //check to see if offset lies within the inset bounds
    newX     = MIN(m_pContainer->getPosition().x, maxInset.x);
    newX     = MAX(newX, minInset.x);
    newY     = MIN(m_pContainer->getPosition().y, maxInset.y);
    newY     = MAX(newY, minInset.y);
    
//     CCLOG("newX,x=%f  newY.y=%f",newX,newY);
//      CCLOG("minInset,x=%f  minInset.y=%f",minInset.x,minInset.y);

//     m_tScrollDistance     = ccpSub(m_tScrollDistance, ccp(newX - m_pContainer->getPosition().x, newY - m_pContainer->getPosition().y));
// 
//     m_tScrollDistance     = ccpSub(m_tScrollDistance, ccp(0, newY - m_pContainer->getPosition().y));
    
//     if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST+2.0f)
//         {
//             if ((((int)fabsf(newY+138))%348)==0)
//             {
//                  m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE-0.09f);
//             }
   //     }
    //    else{
    m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE);
  //  }
  //  }
//       CCLOG("!@@@@@@mtscdistan.x=%f",m_tScrollDistance.y);
//    CCLog("newY=%f",newY);

    this->setContentOffset(ccp(newX,newY));


    if ((newY==maxInset.y)&&m_tScrollDistance.y>0)
    {
       
//        CCLog("++++++++mtscdistan.y=%f",m_tScrollDistance.y);
        this->setContentOffset(ccp(newX,minInset.y+child_h*((int)(data->slottableh/child_h+1))-data->slottableh));
//        this->setContentOffset(ccp(newX,minInset.y+child_h-(960-(child_h*8/2))/2));
    
//        m_bDragging=false;
        //  this->relocateContainer(false);
//         CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
    }
     if ((newY==minInset.y)&&m_tScrollDistance.y<0)
    {
       
        
        
//         CCLog("~~~~~~~~mtscdistan.y=%f",m_tScrollDistance.y);
//        CCLog("maxInset.y==%f",maxInset.y);
        
        this->setContentOffset(ccp(newX,maxInset.y-child_h*((int)(data->slottableh/child_h+1))+data->slottableh));
                 //this->relocateContainer(false);
//        CCLog("maxInset.y==%f",maxInset.y);
//        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
//        m_bDragging=false;
    }
      
//    if (touched_)
//    {
//        CCLog("______________________________________");
//        for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
//        {
//            if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
//            {
//                if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== data->value[0]) {
//                    this->unschedule(schedule_selector(MySView::deaccelerateScrolling1));
//                    m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))))  ;
//                    this->relocateContainer(true);
//                    CCLog("++++++++++++++++++++++++++++++++++++1111");
//                    CCLog("11111m_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
//                }
//                
//                //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)abs((int)(m_pContainer->getPositionY()-36)/348-1));
//                //  m_pContainer->runAction(CCMoveBy::create(3.0f*(abs(i))/174,ccp(0,5+i)));
//            }
//        }
//        //        return;
//    }
    

    if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST+SCROLL_STOP1)
        
    {

            for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
            {
                if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
                {
                    if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== data->value[0]) {
                        
                        data->line1End = true;
                        this->unschedule(schedule_selector(MySView::deaccelerateScrolling1));
                        m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))))  ;
                        this->relocateContainer(true);
                        
                        CCLog("4444newy=%f,child_h=%f",newY,child_h);
                            CCLog("++++++++++++++++++++++++++++++++++++1111");
                            CCLog("11111m_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
                       
                        
                    }

                //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)abs((int)(m_pContainer->getPositionY()-36)/348-1));
                  //  m_pContainer->runAction(CCMoveBy::create(3.0f*(abs(i))/174,ccp(0,5+i)));
                }
            }
    if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST){
        this->unschedule(schedule_selector(MySView::deaccelerateScrolling1));
        this->relocateContainer(true);

        this->setTouchEnabled(true);

        CCLog("xxxxxxm_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
        //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)(abs((int)(m_pContainer->getPositionY()-36)/348-1)));
    }
    
          //  CCLog("letteris%d",(int)(m_pContainer->getPositionY()-36)/348);  
//         CCLog("348~%d~~~",(int)m_pContainer->getContentSize().height);
    }
}

void MySView::deaccelerateScrolling2(float dt)
{
   
    
//    if (touched_)
//    {
//        this->unschedule(schedule_selector(MySView::deaccelerateScrolling2));
//        return;
//    }
    if (!line2ready) {
        return;
    }
    
    float newX, newY;
    CCPoint maxInset, minInset;
    
    
    m_pContainer->setPosition(ccpAdd(m_pContainer->getPosition(), m_tScrollDistance));
    
    if (m_bBounceable)
    {
        maxInset = m_fMaxInset;
        minInset = m_fMinInset;
    }
    else
    {
        maxInset = this->maxContainerOffset();
        minInset = this->minContainerOffset();
    }
    
    //check to see if offset lies within the inset bounds
    newX     = MIN(m_pContainer->getPosition().x, maxInset.x);
    newX     = MAX(newX, minInset.x);
    newY     = MIN(m_pContainer->getPosition().y, maxInset.y);
    newY     = MAX(newY, minInset.y);
 
    m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE);
    CCLOG("!@@@@@@mtscdistan.x=%f",m_tScrollDistance.y);
    //    CCLog("newY=%f",newY);
    
    this->setContentOffset(ccp(newX,newY));
    
    
    if ((newY==maxInset.y)&&m_tScrollDistance.y>0)
    {
        
        //        CCLog("++++++++mtscdistan.y=%f",m_tScrollDistance.y);
        this->setContentOffset(ccp(newX,minInset.y+child_h*((int)(data->slottableh/child_h+1))-data->slottableh));
        //        this->setContentOffset(ccp(newX,minInset.y+child_h-(960-(child_h*8/2))/2));
        
//        touched_=false;
        //  this->relocateContainer(false);
//        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
    }
    if ((newY==minInset.y)&&m_tScrollDistance.y<0)
    {
        
        
        
//        CCLog("~~~~~~~~mtscdistan.y=%f",m_tScrollDistance.y);
//        CCLog("maxInset.y==%f",maxInset.y);
        
        this->setContentOffset(ccp(newX,maxInset.y-child_h*((int)(data->slottableh/child_h+1))+data->slottableh));
        //this->relocateContainer(false);
        //        CCLog("maxInset.y==%f",maxInset.y);
//        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
//        touched_=false;
    }
    

    
    if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST+SCROLL_STOP2)
            {
                
        if (data->line1End) {
            for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
        {
            if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
            {
                if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== data->value[1]) {
                    this->unschedule(schedule_selector(MySView::deaccelerateScrolling2));
                    m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))))  ;
                    this->relocateContainer(true);
                    CCLog("++++++++++++++++++++++++++++++++++++222");
                    CCLog("4444newy=%f,child_h=%f",newY,child_h);
                    CCLog("22222m_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
                    
                    data->line2End = true;
                    
                    if (data->line1End&&data->line2End&&data->line3End&&data->line4End&&data->line5End) {
                        CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",NULL);
                    }
                }

                               //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)abs((int)(m_pContainer->getPositionY()-36)/348-1));
               
            }
        }
        }
        if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST){
            this->unschedule(schedule_selector(MySView::deaccelerateScrolling2));
            this->relocateContainer(true);
            
            this->setTouchEnabled(true);
            
            CCLog("xxxxxxm_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
            //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)(abs((int)(m_pContainer->getPositionY()-36)/348-1)));
        }
        
        //  CCLog("letteris%d",(int)(m_pContainer->getPositionY()-36)/348);  
        //         CCLog("348~%d~~~",(int)m_pContainer->getContentSize().height);
    }
}
void MySView::deaccelerateScrolling3(float dt)
{
    //CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    //    this->setTouchEnabled(false);
    
    
//    if (m_bDragging)
//    {
//        this->unschedule(schedule_selector(MySView::deaccelerateScrolling3));
//        return;
//    }
    if (!line3ready) {
        return;
    }
    
    float newX, newY;
    CCPoint maxInset, minInset;
    
    
    m_pContainer->setPosition(ccpAdd(m_pContainer->getPosition(), m_tScrollDistance));
    
    if (m_bBounceable)
    {
        maxInset = m_fMaxInset;
        minInset = m_fMinInset;
    }
    else
    {
        maxInset = this->maxContainerOffset();
        minInset = this->minContainerOffset();
    }
    
    //check to see if offset lies within the inset bounds
    newX     = MIN(m_pContainer->getPosition().x, maxInset.x);
    newX     = MAX(newX, minInset.x);
    newY     = MIN(m_pContainer->getPosition().y, maxInset.y);
    newY     = MAX(newY, minInset.y);
    
      m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE);
    //  }
    //  }
    CCLOG("!@@@@@@mtscdistan.x=%f",m_tScrollDistance.y);
    //    CCLog("newY=%f",newY);
    
    this->setContentOffset(ccp(newX,newY));
    
    
    if ((newY==maxInset.y)&&m_tScrollDistance.y>0)
    {
        
        //        CCLog("++++++++mtscdistan.y=%f",m_tScrollDistance.y);
        this->setContentOffset(ccp(newX,minInset.y+child_h*((int)(data->slottableh/child_h+1))-data->slottableh));
        //        this->setContentOffset(ccp(newX,minInset.y+child_h-(960-(child_h*8/2))/2));
        
//        m_bDragging=false;
        //  this->relocateContainer(false);
//        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
    }
    if ((newY==minInset.y)&&m_tScrollDistance.y<0)
    {
        
        
        
//        CCLog("~~~~~~~~mtscdistan.y=%f",m_tScrollDistance.y);
//        CCLog("maxInset.y==%f",maxInset.y);
        
        this->setContentOffset(ccp(newX,maxInset.y-child_h*((int)(data->slottableh/child_h+1))+data->slottableh-5));
        //this->relocateContainer(false);
        //        CCLog("maxInset.y==%f",maxInset.y);
//        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
//        m_bDragging=false;
    }

//    if (touched_)
//    {
//        CCLog("______________________________________2");
//        for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
//        {
//            if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
//            {
//                if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== data->value[2]) {
//                    this->unschedule(schedule_selector(MySView::deaccelerateScrolling3));
//                    m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))))  ;
//                    this->relocateContainer(true);
//                    CCLog("++++++++++++++++++++++++++++++++++++333333");
//                    CCLog("3333m_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
//                }
//                
//                //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)abs((int)(m_pContainer->getPositionY()-36)/348-1));
//                //  m_pContainer->runAction(CCMoveBy::create(3.0f*(abs(i))/174,ccp(0,5+i)));
//            }
//        }        //        return;
//    }
    
    if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST+SCROLL_STOP3)
        //||fabsf(
        //         newX == maxInset.x || newX == minInset.x ||
        //         newY == maxInset.y || newY == minInset.y)
    {
        if (data->line2End) {
            
       
        for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
        {
            if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
            {
                if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== data->value[2]) {
                    this->unschedule(schedule_selector(MySView::deaccelerateScrolling3));
                    m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))))  ;
                    this->relocateContainer(true);
                    CCLog("++++++++++++++++++++++++++++++++++++333333");
                    CCLog("4444newy=%f,child_h=%f",newY,child_h);
                     CCLog("3333m_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
                    data->line3End = true;

                }

                               //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)abs((int)(m_pContainer->getPositionY()-36)/348-1));
                //  m_pContainer->runAction(CCMoveBy::create(3.0f*(abs(i))/174,ccp(0,5+i)));
            }
        }
        }
        if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST){
            this->unschedule(schedule_selector(MySView::deaccelerateScrolling3));
            this->relocateContainer(true);
            
            this->setTouchEnabled(true);
            
            CCLog("xxxxxxm_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
            //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)(abs((int)(m_pContainer->getPositionY()-36)/348-1)));
        }
         }
}
void MySView::deaccelerateScrolling4(float dt)
{
       
//    if (m_bDragging)
//    {
//        this->unschedule(schedule_selector(MySView::deaccelerateScrolling4));
//        return;
//    }
    if (!line4ready) {
        return;
    }
    
    float newX, newY;
    CCPoint maxInset, minInset;
    
    
    m_pContainer->setPosition(ccpAdd(m_pContainer->getPosition(), m_tScrollDistance));
    
    if (m_bBounceable)
    {
        maxInset = m_fMaxInset;
        minInset = m_fMinInset;
    }
    else
    {
        maxInset = this->maxContainerOffset();
        minInset = this->minContainerOffset();
    }
    
    //check to see if offset lies within the inset bounds
    newX     = MIN(m_pContainer->getPosition().x, maxInset.x);
    newX     = MAX(newX, minInset.x);
    newY     = MIN(m_pContainer->getPosition().y, maxInset.y);
    newY     = MAX(newY, minInset.y);
     m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE);
    //  }
    //  }
    CCLOG("!@@@@@@mtscdistan.x=%f",m_tScrollDistance.y);
    //    CCLog("newY=%f",newY);
    
    this->setContentOffset(ccp(newX,newY));
    
    
    if ((newY==maxInset.y)&&m_tScrollDistance.y>0)
    {
        
        //        CCLog("++++++++mtscdistan.y=%f",m_tScrollDistance.y);
        this->setContentOffset(ccp(newX,minInset.y+child_h*((int)(data->slottableh/child_h+1))-data->slottableh));
        //        this->setContentOffset(ccp(newX,minInset.y+child_h-(960-(child_h*8/2))/2));
        
//        m_bDragging=false;
        //  this->relocateContainer(false);
//        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
    }
    if ((newY==minInset.y)&&m_tScrollDistance.y<0)
    {
  
//        CCLog("~~~~~~~~mtscdistan.y=%f",m_tScrollDistance.y);
//        CCLog("maxInset.y==%f",maxInset.y);
        
        this->setContentOffset(ccp(newX,maxInset.y-child_h*((int)(data->slottableh/child_h+1))+data->slottableh));

    }
    

    
    if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST+SCROLL_STOP4)
          {
              
              if (data->line3End) {
             
        for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
            {
            if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
            {
                if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== data->value[3]) {
                    this->unschedule(schedule_selector(MySView::deaccelerateScrolling4));
                   
                    m_pContainer->runAction(CCSequence::createWithTwoActions(
                                                                             CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))), CCCallFuncN::create(m_pContainer,
                                                                                                                                        callfuncN_selector(MySView::delayForShowResults)))
                                            
                                            
                                            )  ;
                    this->relocateContainer(true);
                    CCLog("+++++++++++++++data->value[3]=%d+++++fabs=%d+++++++4444",data->value[3],(int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1));
                     CCLog("4444m_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
                    CCLog("4444newy=%f,child_h=%f",newY,child_h);

                    data->line4End = true;
                    
                                }

            //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)abs((int)(m_pContainer->getPositionY()-36)/348-1));
                //  m_pContainer->runAction(CCMoveBy::create(3.0f*(abs(i))/174,ccp(0,5+i)));
            }
        }
              }
        if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST){
            this->unschedule(schedule_selector(MySView::deaccelerateScrolling4));
            this->relocateContainer(true);
            
            this->setTouchEnabled(true);
            
            CCLog("xxxxxxm_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
            //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)(abs((int)(m_pContainer->getPositionY()-36)/348-1)));
        }
         }
}


void MySView::deaccelerateScrolling5(float dt)
{
       
//    if (m_bDragging)
//    {
//        this->unschedule(schedule_selector(MySView::deaccelerateScrolling5));
//        return;
//    }
    if (!line5ready) {
        return;
    }
    
    float newX, newY;
    CCPoint maxInset, minInset;
    
    
    m_pContainer->setPosition(ccpAdd(m_pContainer->getPosition(), m_tScrollDistance));
    
    if (m_bBounceable)
    {
        maxInset = m_fMaxInset;
        minInset = m_fMinInset;
    }
    else
    {
        maxInset = this->maxContainerOffset();
        minInset = this->minContainerOffset();
    }
    
    //check to see if offset lies within the inset bounds
    newX     = MIN(m_pContainer->getPosition().x, maxInset.x);
    newX     = MAX(newX, minInset.x);
    newY     = MIN(m_pContainer->getPosition().y, maxInset.y);
    newY     = MAX(newY, minInset.y);
    
      m_tScrollDistance     = ccpMult(m_tScrollDistance, SCROLL_DEACCEL_RATE);
    //  }
    //  }
    CCLOG("!@@@@@@mtscdistan.x=%f",m_tScrollDistance.y);
    //    CCLog("newY=%f",newY);
    
    this->setContentOffset(ccp(newX,newY));
    
    
    if ((newY==maxInset.y)&&m_tScrollDistance.y>0)
    {
        
        //        CCLog("++++++++mtscdistan.y=%f",m_tScrollDistance.y);
        this->setContentOffset(ccp(newX,minInset.y+child_h*((int)(data->slottableh/child_h+1))-data->slottableh));
        //        this->setContentOffset(ccp(newX,minInset.y+child_h-(960-(child_h*8/2))/2));
        
//        m_bDragging=false;
        //  this->relocateContainer(false);
//        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
    }
    if ((newY==minInset.y)&&m_tScrollDistance.y<0)
    {
        
        
        
//        CCLog("~~~~~~~~mtscdistan.y=%f",m_tScrollDistance.y);
//        CCLog("maxInset.y==%f",maxInset.y);
        
        this->setContentOffset(ccp(newX,maxInset.y-child_h*((int)(data->slottableh/child_h+1))+data->slottableh));
        //this->relocateContainer(false);
        //        CCLog("maxInset.y==%f",maxInset.y);
//        CCLog("m_pContainer.y==%f",m_pContainer->getPositionY());
//        m_bDragging=false;
    }
    

    
    if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST+SCROLL_STOP5)
      
    {
        if (data->line4End) {
            
       
        
               for (int i=STOP_AREA;i>STOP_AREATO*-1;i--)
        {
            if ((((int)fabsf(m_pContainer->getPositionY()+i+(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))%(int)child_h)==0)
            {
                if ((int)fabs((m_pContainer->getPositionY()+i-(child_h-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))/child_h-1)== data->value[4]) {
                    this->unschedule(schedule_selector(MySView::deaccelerateScrolling5));
                    m_pContainer->runAction(CCSequence::createWithTwoActions(
                                                                             CCEaseBackIn::create(CCMoveBy::create(.2, ccp(0,5+i))), CCCallFuncN::create(m_pContainer,
                                                                                                                                                         callfuncN_selector(MySView::delayForShowResults)))
                                            
                                            
                                            )  ;
                    this->relocateContainer(true);
                    CCLog("++++++++++++++++++++++++++++++++++++55555");
                     CCLog("55555m_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
                    CCLog("4444newy=%f,child_h=%f",newY,child_h);
                    data->line5End =true;
                    
                   
                   
                }

              
               
                //  m_pContainer->runAction(CCMoveBy::create(3.0f*(abs(i))/174,ccp(0,5+i)));
            }
        }
             }
        if (fabsf(m_tScrollDistance.y) <= SCROLL_DEACCEL_DIST){
            this->unschedule(schedule_selector(MySView::deaccelerateScrolling5));
            this->relocateContainer(true);
            
            this->setTouchEnabled(true);
            
            CCLog("xxxxxxm_pContainer->getPositionY()=%f",m_pContainer->getPositionY());
            //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",(CCObject*)(abs((int)(m_pContainer->getPositionY()-36)/348-1)));
        }
        
        }
}

void MySView::delayForShowResults(cocos2d::CCNode *ccpro){
    
    CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollEnd",NULL);
    

}

void MySView::stoppedAnimatedScroll(CCNode * node)
{
    this->unschedule(schedule_selector(MySView::performedAnimatedScroll));
}

void MySView::performedAnimatedScroll(float dt)
{
    if (m_bDragging)
    {
        CCLog("perfomeainlmladsd^^^^^^^^^^^^^^^^^^");
        this->unschedule(schedule_selector(MySView::performedAnimatedScroll));
        return;
    }

    if (m_pDelegate != NULL)
    {
        m_pDelegate->scrollViewDidScroll(this);
    }
}


const CCSize & MySView::getContentSize()
{
	return m_pContainer->getContentSize();
}

void MySView::setContentSize(const CCSize & size)
{
    if (this->getContainer() != NULL)
    {
        this->getContainer()->setContentSize(size);
		this->updateInset();
    }
}

void MySView::updateInset()
{
	if (this->getContainer() != NULL)
	{
		m_fMaxInset = this->maxContainerOffset();
		m_fMaxInset = ccp(m_fMaxInset.x + m_tViewSize.width * INSET_RATIO,
			m_fMaxInset.y + m_tViewSize.height * INSET_RATIO);
		m_fMinInset = this->minContainerOffset();
		m_fMinInset = ccp(m_fMinInset.x - m_tViewSize.width * INSET_RATIO,
			m_fMinInset.y - m_tViewSize.height * INSET_RATIO);
	}
}

/**
 * make sure all children go to the container
 */
void MySView::addChild(CCNode * child, int zOrder, int tag)
{
    child->ignoreAnchorPointForPosition(false);
    child->setAnchorPoint(ccp(0.0f, 0.0f));
    if (m_pContainer != child) {
        m_pContainer->addChild(child, zOrder, tag);
    } else {
        CCLayer::addChild(child, zOrder, tag);
    }
}

void MySView::addChild(CCNode * child, int zOrder)
{
    this->addChild(child, zOrder, child->getTag());
}

void MySView::addChild(CCNode * child)
{
    this->addChild(child, child->getZOrder(), child->getTag());
}

/**
 * clip this view so that outside of the visible bounds can be hidden.
 */
void MySView::beforeDraw()
{
    if (m_bClippingToBounds)
    {
		// TODO: This scrollview should respect parents' positions
		CCPoint screenPos = this->getParent()->convertToWorldSpace(this->getPosition());

        glEnable(GL_SCISSOR_TEST);
        float s = this->getScale();

//        CCDirector *director = CCDirector::sharedDirector();
//        s *= director->getContentScaleFactor();
        CCEGLView::sharedOpenGLView()->setScissorInPoints(screenPos.x*s, screenPos.y*s, m_tViewSize.width*s, m_tViewSize.height*s);
        //glScissor((GLint)screenPos.x, (GLint)screenPos.y, (GLsizei)(m_tViewSize.width*s), (GLsizei)(m_tViewSize.height*s));
		
    }
}

/**
 * retract what's done in beforeDraw so that there's no side effect to
 * other nodes.
 */
void MySView::afterDraw()
{
    if (m_bClippingToBounds)
    {
        glDisable(GL_SCISSOR_TEST);
    }
}

void MySView::visit()
{
	// quick return if not visible
	if (!isVisible())
    {
		return;
    }

	kmGLPushMatrix();
	
    if (m_pGrid && m_pGrid->isActive())
    {
        m_pGrid->beforeDraw();
        this->transformAncestors();
    }

	this->transform();
    this->beforeDraw();

	if(m_pChildren)
    {
		ccArray *arrayData = m_pChildren->data;
		unsigned int i=0;
		
		// draw children zOrder < 0
		for( ; i < arrayData->num; i++ )
        {
			CCNode *child =  (CCNode*)arrayData->arr[i];
			if ( child->getZOrder() < 0 )
            {
				child->visit();
			}
            else
            {
				break;
            }
		}
		
		// this draw
		this->draw();
		
		// draw children zOrder >= 0
		for( ; i < arrayData->num; i++ )
        {
			CCNode* child = (CCNode*)arrayData->arr[i];
			child->visit();
		}
        
	}
    else
    {
		this->draw();
    }

    this->afterDraw();
	if ( m_pGrid && m_pGrid->isActive())
    {
		m_pGrid->afterDraw(this);
    }

	kmGLPopMatrix();
}

int MySView::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
//    touched_ = true;
//// m_bDragging   = true;
////    return true;
////    m_pContainer->stopAllActions();
//child_h =  data->slotenmh;
////    if (ReadIntegerDataFile("playmodel")==3)
////    {
//  
////    autoScroll(ccp(0.00,40+CCRANDOM_0_1()*180));
////          return true;
////    }
//    
////    CCLog("mysview = %f",data->slottableh);
//    if (!this->isVisible())
//    {
//        return false;
//    }
//
//    CCRect frame;
//    CCPoint frameOriginal = this->getParent()->convertToWorldSpace(this->getPosition());
//    frame = CCRectMake(frameOriginal.x, frameOriginal.y, m_tViewSize.width, m_tViewSize.height);
//    
//    //dispatcher does not know about clipping. reject touches outside visible bounds.
//    if (m_pTouches->count() > 2 ||
//        m_bTouchMoved          ||
//        !frame.containsPoint(m_pContainer->convertToWorldSpace(m_pContainer->convertTouchToNodeSpace(touch))))
//    {
//        return false;
//    }
//
//    if (!m_pTouches->containsObject(touch))
//    {
//        m_pTouches->addObject(touch);
//    }
//
//    if (m_pTouches->count() == 1)
//    { // scrolling
//        m_tTouchPoint     = this->convertTouchToNodeSpace(touch);
//        m_bTouchMoved     = false;
//        m_bDragging     = true; //dragging started
//        CCLog("m)bdaoo=true");
//        m_tScrollDistance = ccp(0.0f, 0.0f);
//        m_fTouchLength    = 0.0f;
//    }
//    else if (m_pTouches->count() == 2)
//    {
//        m_tTouchPoint  = ccpMidpoint(this->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(0)),
//                                   this->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(1)));
//        m_fTouchLength = ccpDistance(m_pContainer->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(0)),
//                                   m_pContainer->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(1)));
//        m_bDragging  = false;
//    } 
    return false;
}

int MySView::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
//    if (!this->isVisible())
//    {
//        return;
//    }
//
//    if (m_pTouches->containsObject(touch))
//    {
//        if (m_pTouches->count() == 1 && m_bDragging)
//        { // scrolling
//            CCPoint moveDistance, newPoint, maxInset, minInset;
//            CCRect  frame;
//            float newX, newY;
//            
//            m_bTouchMoved  = true;
//            CCPoint frameOriginal = this->getParent()->convertToWorldSpace(this->getPosition());
//            frame = CCRectMake(frameOriginal.x, frameOriginal.y, m_tViewSize.width, m_tViewSize.height);
//
//            newPoint     = this->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(0));
//            moveDistance = ccpSub(newPoint, m_tTouchPoint);
//            m_tTouchPoint  = newPoint;
//
//            if (frame.containsPoint(this->convertToWorldSpace(newPoint)))
//            {
//                switch (m_eDirection)
//                {
//                    case kMySViewDirectionVertical:
//                        moveDistance = ccp(0.0f, moveDistance.y);
//                        break;
//                    case kMySViewDirectionHorizontal:
//                        moveDistance = ccp(moveDistance.x, 0.0f);
//                        break;
//                    default:
//                        break;
//                }
//
//                m_pContainer->setPosition(ccpAdd(m_pContainer->getPosition(), moveDistance));
//                
//                maxInset = m_fMaxInset;
//                minInset = m_fMinInset;
//                
//                
//                //check to see if offset lies within the inset bounds
//                newX     = MIN(m_pContainer->getPosition().x, maxInset.x);
//                newX     = MAX(newX, minInset.x);
//                newY     = MIN(m_pContainer->getPosition().y, maxInset.y);
//                newY     = MAX(newY, minInset.y);
//           
//                m_tScrollDistance     = ccpSub(moveDistance, ccp(newX - m_pContainer->getPosition().x, newY - m_pContainer->getPosition().y));
//                this->setContentOffset(ccp(newX, newY));
//                if (newY==maxInset.y)
//                {
//                    //DOWN
//                    this->setContentOffset(ccp(newX,minInset.y+child_h*((int)(data->slottableh/child_h+1))-data->slottableh));
//                   // m_bDragging=false;
//                CCLog("~~~up minInset=%f",minInset.y);
//                CCLog(" movedistance.y=%f",moveDistance.y);
//                CCLog(" m_tScrollDistance.y=%f",m_tScrollDistance.y);
//                CCLog("!uppm_pContainer.y==%f~~~~",m_pContainer->getPositionY());
//                }
//                if (newY==minInset.y)
//                {
//                  
//                    this->setContentOffset(ccp(newX,maxInset.y-child_h*((int)(data->slottableh/child_h+1))+data->slottableh));
//                  //  m_bDragging=false;
//                    CCLog("~~~down maxInset=%f~~~~~",maxInset.y);
//                    CCLog(" movedistance.y=%f",moveDistance.y);
//                    CCLog(" m_tScrollDistance.y=%f",m_tScrollDistance.y);
//                     CCLog("!downm_pContainer.y==%f~~~~",m_pContainer->getPositionY());
//                    //return;
//                }
//
//            
//                CCLog("!uppm_pContainer.y=%f~~",m_pContainer->getPositionY());  
//            }
//        }
//        else if (m_pTouches->count() == 2 && !m_bDragging)
//        {
//            const float len = ccpDistance(m_pContainer->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(0)),
//                                            m_pContainer->convertTouchToNodeSpace((CCTouch*)m_pTouches->objectAtIndex(1)));
//            this->setZoomScale(this->getZoomScale()*len/m_fTouchLength);
//
//        }
//    }

}

void MySView::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    if (!this->isVisible())
    {
        return;
    }
//    if (m_pTouches->containsObject(touch))
//    {
//        if (m_pTouches->count() == 1 && m_bTouchMoved)
//        {
////            if (m_bDragging)
////            {
////
////                if (fabs(m_tScrollDistance.y)<10)
////                {
////                    if (m_tScrollDistance.y>0)
////                    {
////                        m_tScrollDistance.y=10;
////                    }
////                    if (m_tScrollDistance.y<0)
////                    {
////                        m_tScrollDistance.y=-10;
////                    }
////                }
////                m_pContainer->stopAllActions();
////                    //CCNotificationCenter::sharedNotificationCenter()->postNotification("onScrollBegin",NULL);
////                this->schedule(schedule_selector(MySView::deaccelerateScrolling));
////        }
////           }
//            
//           
//        }
//        m_pTouches->removeObject(touch);
//    } 
//
//    if (m_pTouches->count() == 0)
//    {
//        m_bDragging = false;    
//        m_bTouchMoved = false;
//    }
}

void MySView::ccTouchCancelled(CCTouch* touch, CCEvent* event)
{
//    if (!this->isVisible())
//    {
//        return;
//    }
//    m_pTouches->removeObject(touch); 
//    if (m_pTouches->count() == 0)
//    {
//        m_bDragging = false;    
//        m_bTouchMoved = false;
//    }
}

NS_CC_EXT_END
