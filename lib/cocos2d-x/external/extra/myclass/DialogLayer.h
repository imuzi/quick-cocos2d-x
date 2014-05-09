//
//  DialogLayer.h
//  ModalDialogDemo
//
//  Created by Tom on 12-5-28.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef ModalDialogDemo_DialogLayer_h
#define ModalDialogDemo_DialogLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "LuaTableView.hpp"
#include "LuaEventHandler.hpp"
#include "CCEditBox.h"
#include "CursorTextField.h"
USING_NS_CC;

using namespace extension ;


class DialogLayer: public CCLayerColor
{
    // 模态对话框菜单

public:
    DialogLayer();
    ~DialogLayer();
    bool xinit(int priorityRate);
    
    CCMenu *m_pMenu ;
    
    CCMenu *m_pMenu2 ;
    CCLayer *m_pLayer ;
    CCEditBox *m_pEditBox1 ;
    CCEditBox *m_pEditBox2 ;
    CCEditBox *m_pEditBox3 ;
    CCEditBox *m_pEditBox4 ;
    CCEditBox *m_pEditBox5 ;
    
    CursorTextField *m_pTextField;
    LuaTableView* m_tableview;
    LuaTableView* m_tableview1;
    ccColor4B color;
    
    const int LAYER_PRIORITY=-1129;
    int curPriority;
    
    int mTouchHandler;
    void registerScriptTouchHandler(int handler);
    void unRegisterScriptTouchHandler();
    
    
//    LuaTableView
    // 记录菜单点击
    bool m_bTouchedMenu ;
    bool m_bTouchedMenu2 ;
    bool m_bTouchedLayer ;
    bool m_bTouchedEditBox1 ;
    bool m_bTouchedEditBox2 ;
    bool m_bTouchedEditBox3 ;
    bool m_bTouchedEditBox4 ;
    bool m_bTouchedEditBox5 ;
    
    bool m_bTouchedTextField ;
    bool m_bTouchedtableview ;
    bool m_bTouchedtableview1;
    
    bool m_isCanTouch;
    void disableTouch();
    void eanbleTouch();
    
    static DialogLayer* create();
    static DialogLayer* create(const ccColor4B& color);
    static DialogLayer* create(int priorityRate);
    static DialogLayer* create(const ccColor4B& color,int priorityRate);


    void onEnter();
    void onExit();
    
    
    void enableTouch(CCNode* child);
    
    virtual int ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual int ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    CC_PROPERTY(GLubyte, m_nOpacity, Opacity)
};

#endif
