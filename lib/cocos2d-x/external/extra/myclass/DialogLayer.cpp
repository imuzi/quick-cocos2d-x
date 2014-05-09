#include "DialogLayer.h"


DialogLayer::DialogLayer()
{
     mTouchHandler=0;
     m_pMenu=NULL;
    m_pMenu2=NULL;
     m_pLayer=NULL;
     m_pEditBox1=NULL;
     m_pEditBox2=NULL;
    m_pEditBox3=NULL;
    m_pEditBox4=NULL;
    m_pEditBox5=NULL;
     m_pTextField = NULL ;
    m_tableview = NULL;
    m_tableview1 = NULL;
    m_isCanTouch = true;
   
}

DialogLayer::~DialogLayer()
{
    
}
DialogLayer* DialogLayer::create(const ccColor4B& color)
{
    return DialogLayer::create(color,1);

}
DialogLayer* DialogLayer::create(int priorityRate)
{
    return DialogLayer::create(ccc4(0, 0, 0, 80),priorityRate);
    
}


DialogLayer* DialogLayer::create(const ccColor4B& color,int priorityRate)
{
    DialogLayer* dl = new DialogLayer();
    if (dl){
        dl->initWithColor(color);
//        dl->color.r=color.r;
//        dl->color.g=color.g;
//        dl->color.b=color.b;
//        dl->color.a=color.a;
        dl->xinit(priorityRate);
        dl->autorelease();
        return dl;
    }
    
    CC_SAFE_DELETE(dl);
    
    return NULL;
    
}




DialogLayer* DialogLayer::create()
{
    return DialogLayer::create(ccc4(0, 0, 0, 180));
}

void DialogLayer::enableTouch(CCNode* child)
{
    ((CCLayer*)child)->setTouchPriority(((CCLayer*)child)->getTouchPriority()+curPriority-1);
}


//DialogLayer* DialogLayer::create(const char* bgShow1 ,const char* labelTTF1,const char* okImgNormal1,const char* okImgSelect1,SEL_MenuHandler callFUN)
//{
//    
//    DialogLayer* dl=new DialogLayer(1);
//    
//    dl->bgShow = bgShow1;
//    dl->labelTTF = labelTTF1;
//    dl->okImgNormal = okImgNormal1 ;
//    dl->okImgSelect = okImgSelect1;
//    dl->callFUN = callFUN;
//    dl->init();
//    dl->autorelease();
//    return dl;
//}
//
//DialogLayer* DialogLayer::create(const char* bgShow1 ,const char* labelTTF1,const char* okImgNormal1,const char* okImgSelect1,const char* cancelImgNormal1,const char* cancelImgSelect1)
//{
//    DialogLayer* dl=new DialogLayer(2);
//    
//    dl->bgShow = bgShow1;
//    dl->labelTTF = labelTTF1;
//    dl->okImgNormal = okImgNormal1 ;
//    dl->okImgSelect = okImgSelect1;
//    dl->cancelImgNormal = cancelImgNormal1;
//    dl->cancelImgSelect = cancelImgSelect1;
//    dl->init();
//    dl->autorelease();
//    return dl;
//}

bool DialogLayer::xinit(int priorityRate)
{
    bool bRet = false;
    
    do {
//        CC_BREAK_IF(!CCLayerColor::initWithColor(color));
        
//        if (TAG ==1)
//        {
//            initDialog1();
//        }
//        else
//        {
//            initDialog2();
//        }
       
       
        //CCSize size = CCDirector::sharedDirector()->getWinSize();
        m_pMenu=CCMenu::create();

        m_pMenu->setPosition(ccp(0,0));
        this->addChild(m_pMenu);
        
        
        curPriority = LAYER_PRIORITY*priorityRate;
        
        unRegisterScriptTouchHandler();

        
        bRet = true;
    } while (0);
    
    return bRet;
}



void DialogLayer::onEnter()
{
    CCLayerColor::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,curPriority, true);
}

void DialogLayer::onExit()
{
    CCLayerColor::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

void DialogLayer::disableTouch()
{
    m_isCanTouch = false;
}

void DialogLayer::eanbleTouch()
{
    m_isCanTouch = true;
}

int DialogLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (m_isCanTouch)
    {
   
    if (m_pMenu)
    {
        m_bTouchedMenu = m_pMenu->ccTouchBegan(pTouch, pEvent);
     }
    
    if (m_pMenu2)
    {
        m_bTouchedMenu2 = m_pMenu2->ccTouchBegan(pTouch, pEvent);
    }
    
    if(m_pLayer)
    {
        m_bTouchedLayer = m_pLayer->ccTouchBegan(pTouch, pEvent);
    }
    
    if(m_pEditBox1)
    {
        m_bTouchedEditBox1 = m_pEditBox1->ccTouchBegan(pTouch, pEvent);
    }
    if(m_pEditBox2)
    {
        m_bTouchedEditBox2 = m_pEditBox2->ccTouchBegan(pTouch, pEvent);
    }
    if(m_pEditBox3)
    {
        m_bTouchedEditBox3 = m_pEditBox3->ccTouchBegan(pTouch, pEvent);
    }
    if(m_pEditBox4)
    {
        m_bTouchedEditBox4 = m_pEditBox4->ccTouchBegan(pTouch, pEvent);
    }
    if(m_pEditBox5)
    {
        m_bTouchedEditBox5 = m_pEditBox5->ccTouchBegan(pTouch, pEvent);
    }
    
    if(m_tableview)
    {
        
        m_bTouchedtableview = m_tableview->ccTouchBegan(pTouch, pEvent);

    }
    
    if(m_tableview1)
    {
        
        m_bTouchedtableview1 = m_tableview1->ccTouchBegan(pTouch, pEvent);

    }
    if(m_pTextField)
    {
        
        m_bTouchedTextField = m_pTextField->ccTouchBegan(pTouch, pEvent);
        
    }
        if (mTouchHandler != 0)
        {
            cocos2d::CCScriptEngineManager::sharedManager()->getScriptEngine()->executeMyTouchEvent(mTouchHandler,"began",pTouch);
        }
        
    }
    return true;
}

int DialogLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
     if (m_pMenu)
     {
         if (m_bTouchedMenu)
         {
             m_pMenu->ccTouchMoved(pTouch, pEvent);
         }
     }
    
    if (m_pMenu2)
    {
        if (m_bTouchedMenu2)
        {
            m_pMenu2->ccTouchMoved(pTouch, pEvent);
        }
    }

    
    
    if (m_pLayer)
    {
        if (m_bTouchedLayer)
        {
            m_pLayer->ccTouchMoved(pTouch, pEvent);
        }
    }
    if(m_pEditBox1)
    {
        if(m_bTouchedEditBox1)
        {
            m_pEditBox1->ccTouchMoved(pTouch, pEvent);

        }
    }
    if(m_pEditBox2)
    {
        if(m_bTouchedEditBox2)
        {
            m_pEditBox2->ccTouchMoved(pTouch, pEvent);
            
        }
    }
    
    if(m_pEditBox3)
    {
        if(m_bTouchedEditBox3)
        {
            m_pEditBox3->ccTouchMoved(pTouch, pEvent);
            
        }
    }
    if(m_pEditBox4)
    {
        if(m_bTouchedEditBox4)
        {
            m_pEditBox4->ccTouchMoved(pTouch, pEvent);
            
        }
    }
    if(m_pEditBox5)
    {
        if(m_bTouchedEditBox5)
        {
            m_pEditBox5->ccTouchMoved(pTouch, pEvent);
            
        }
    }
    
    if(m_tableview)
    {
        if (m_bTouchedtableview) {
            m_tableview->ccTouchMoved(pTouch, pEvent);
        }
    }
    
    if(m_tableview1)
    {
        if (m_bTouchedtableview1) {
            m_tableview1->ccTouchMoved(pTouch, pEvent);
        }
    }
    if(m_pTextField)
    {
        if (m_bTouchedTextField) {
            m_pTextField->ccTouchMoved(pTouch, pEvent);
        }
    }
    
    if (mTouchHandler != 0)
    {
        cocos2d::CCScriptEngineManager::sharedManager()->getScriptEngine()->executeMyTouchEvent(mTouchHandler,"moved",pTouch);
    }
    
    
}

void DialogLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if (m_pMenu)
    {
       if (m_bTouchedMenu)
       {
          m_pMenu->ccTouchEnded(pTouch, pEvent);
          m_bTouchedMenu = false;
       }
    }
    
    if (m_pMenu2)
    {
        if (m_bTouchedMenu2)
        {
            m_pMenu2->ccTouchEnded(pTouch, pEvent);
            m_bTouchedMenu2 = false;
        }
    }
    
    
        
    if (m_pLayer)
    {
            if (m_bTouchedLayer)
            {
                m_pLayer->ccTouchEnded(pTouch, pEvent);
                m_bTouchedLayer = false;
            }
    }
    if(m_pEditBox1)
    {
        if(m_bTouchedEditBox1)
        {
            m_pEditBox1->ccTouchEnded(pTouch, pEvent);
            m_bTouchedEditBox1= false ;
            
        }
    }
    
    if(m_pEditBox2)
    {
        if(m_bTouchedEditBox2)
        {
            m_pEditBox2->ccTouchEnded(pTouch, pEvent);
            m_bTouchedEditBox2= false ;
            
        }
    }
    
    if(m_pEditBox3)
    {
        if(m_bTouchedEditBox3)
        {
            m_pEditBox3->ccTouchEnded(pTouch, pEvent);
            m_bTouchedEditBox3= false ;
            
        }
    }
    
    if(m_pEditBox4)
    {
        if(m_bTouchedEditBox4)
        {
            m_pEditBox4->ccTouchEnded(pTouch, pEvent);
            m_bTouchedEditBox4= false ;
            
        }
    }
    
    if(m_pEditBox5)
    {
        if(m_bTouchedEditBox5)
        {
            m_pEditBox5->ccTouchEnded(pTouch, pEvent);
            m_bTouchedEditBox5= false ;
            
        }
    }
    
    if(m_tableview)
    {
        if(m_bTouchedtableview)
        {
            m_tableview->ccTouchEnded(pTouch, pEvent);
            m_bTouchedtableview= false ;
            
        }
    }
    
    if(m_tableview1)
    {
        if(m_bTouchedtableview1)
        {
            m_tableview1->ccTouchEnded(pTouch, pEvent);
            m_bTouchedtableview1= false ;
            
        }
    }
    
    if(m_pTextField)
    {
        if (m_bTouchedTextField) {
            m_pTextField->ccTouchEnded(pTouch, pEvent);
            m_bTouchedTextField = false;
        }
    }
    
    if (mTouchHandler != 0)
    {
        cocos2d::CCScriptEngineManager::sharedManager()->getScriptEngine()->executeMyTouchEvent(mTouchHandler,"ended",pTouch);
    }
    
}

void DialogLayer::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
     if (m_pMenu)
     {
         if (m_bTouchedMenu)
         {
             m_pMenu->ccTouchCancelled(pTouch, pEvent);
             m_bTouchedMenu = false;
         }
     }
    
    if (m_pMenu2)
    {
        if (m_bTouchedMenu2)
        {
            m_pMenu2->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedMenu2 = false;
        }
    }

    
    
    
    if (m_pLayer)
    {
        if (m_bTouchedLayer)
        {
            m_pLayer->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedLayer = false;
        }
    }
    if(m_pEditBox1)
    {
        if(m_bTouchedEditBox1)
        {
            m_pEditBox1->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedEditBox1= false ;
            
        }
    }
    
    if(m_pEditBox2)
    {
        if(m_bTouchedEditBox2)
        {
            m_pEditBox2->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedEditBox2= false ;
            
        }
    }
    
    if(m_pEditBox3)
    {
        if(m_bTouchedEditBox3)
        {
            m_pEditBox3->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedEditBox3= false ;
            
        }
    }
    
    if(m_pEditBox4)
    {
        if(m_bTouchedEditBox4)
        {
            m_pEditBox4->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedEditBox4= false ;
            
        }
    }
    if(m_pEditBox5)
    {
        if(m_bTouchedEditBox5)
        {
            m_pEditBox5->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedEditBox5= false ;
            
        }
    }
    
    
    if(m_tableview)
    {
        if(m_bTouchedtableview)
        {
            m_tableview->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedtableview= false ;
            
        }
    }
    
    if(m_tableview1)
    {
        if(m_bTouchedtableview1)
        {
            m_tableview1->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedtableview1= false ;
            
        }
    }
    if(m_pTextField)
    {
        if (m_bTouchedTextField) {
            m_pTextField->ccTouchCancelled(pTouch, pEvent);
            m_bTouchedTextField = false;
        }
    }
    
    
}

GLubyte DialogLayer::getOpacity(void){
    return m_nOpacity;
}
void DialogLayer::setOpacity(GLubyte opacity)
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
    CCLayerColor::setOpacity(opacity);
}


void DialogLayer::registerScriptTouchHandler(int handler)
{
    if (mTouchHandler!=0)
    {
        unRegisterScriptTouchHandler();
    }
    mTouchHandler=handler;

}

void DialogLayer::unRegisterScriptTouchHandler()
{
    mTouchHandler=0;
}



