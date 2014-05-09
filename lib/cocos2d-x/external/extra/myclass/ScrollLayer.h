//
//  ScrollLayer.h
//  quickcocos2dx
//
//  Created by lee on 8/28/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#ifndef __quickcocos2dx__ScrollLayer__
#define __quickcocos2dx__ScrollLayer__


#include "cocos2d.h"
#include "cocos-ext.h"
#include "MyTView.h"
#include "CData.h"

USING_NS_CC;
USING_NS_CC_EXT;



class ScrollLayer : public cocos2d::CCLayer, public CCTableViewDataSource, public CCTableViewDelegate
{
    
public:
	ScrollLayer(void);
	~ScrollLayer(void);
public:
    
    static ScrollLayer* create();
    virtual bool init();
    
	void StarSpin(int linenum);
    
    int _tag;
    
    
    float child_w,child_h;

    
    void onScrollEnd(CCObject*psender);
    void onScrollBegin(CCObject*psender);
    
	    
    const char *elepic;
    
    
    CData *data;
    
    float delayper;
    virtual void scrollViewDidScroll(CCScrollView* view) {};
    virtual void scrollViewDidZoom(CCScrollView* view) {};
    virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);
    virtual cocos2d::CCSize cellSizeForTable(CCTableView *table);
    virtual CCTableViewCell* tableCellAtIndex(CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(CCTableView *table);
};

#endif /* defined(__quickcocos2dx__ScrollLayer__) */
