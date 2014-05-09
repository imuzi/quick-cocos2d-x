//
//  ScrollLayer.cpp
//  quickcocos2dx
//
//  Created by lee on 8/28/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#include "ScrollLayer.h"
#include "TestSpin.h"
#include "CData.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define EMLEMNUM 1

#define LEFT1
#define LEFT2
#define MID
#define RIGHT1
#define RIGHT2

ScrollLayer::ScrollLayer(void)
{
    delayper = 0.0f;
    data = NULL ;
    elepic = NULL;
    
    
}

ScrollLayer::~ScrollLayer(void)
{
}
ScrollLayer* ScrollLayer::create()
{
    ScrollLayer *sprite = new ScrollLayer();
    if (sprite && sprite->init()) {
        sprite->autorelease();
        
        return sprite;
    }
    
    CC_SAFE_DELETE(sprite);
    sprite = NULL;
    return NULL;
}

bool ScrollLayer::init()
{
	bool bRet = false;
    
	do {
		CC_BREAK_IF(!CCLayer::init());
        data = CData::getAmInstance();
        
        
        elepic = "AllSprites.png";
            
        CCSprite *sprite = CCSprite::create(elepic);
        child_h = sprite->getContentSize().height;
        child_w = sprite->getContentSize().width;
        CCLog("tablelayer==%f",child_h);
        
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
//        data->slottableh = child_h*4 ;
//        data->slotenmh = child_h ;
        
        
        
        
		CCTableView*tableView1 = CCTableView::create(this, CCSizeMake(child_w, 480));
		tableView1->setDirection(kCCScrollViewDirectionVertical);
		tableView1->setPosition(ccp(0,240));
        
		tableView1->setDelegate(this);
		this->addChild(tableView1); 
		tableView1->reloadData();
        
//       -- tableView1->m_pContainer=sprite;
        CCLog("1024/228=%d",(int)(1024/228+1));
        
       
//        tableView1->m_pContainer->setPosition(ccp(tableView1->m_pContainer->getPositionX(),
//                                                  tableView1->m_pContainer->getPositionY()-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2));
        
		bRet = true;
	} while (0);
    
	return bRet;
	
}

void ScrollLayer::onScrollBegin(cocos2d::CCObject *psender){
    //   CCEaseBackOut
    
}

void ScrollLayer::onScrollEnd(cocos2d::CCObject *psender){
    
      //    CCOrbitCamera::create(2, 1, 0, 0, 360, 0, 0), 5)
}
void ScrollLayer::StarSpin(int linenum)
{
  }

void ScrollLayer::tableCellTouched(CCTableView* table,CCTableViewCell* cell)
{
    
    CCLOG("cell touched at index: %i", 28-cell->getIdx());
    
    //    cell->get
}


CCSize ScrollLayer::cellSizeForTable(CCTableView *table)
{
    //    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    //    CCSprite *sprite = CCSprite::create("StartButton.png");
    return CCSizeMake(child_w, child_h);
}

CCTableViewCell* ScrollLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    //  CCTableView  printf ("@@@@@@@@@@@@@@table->getPositionX()%f",table->getPositionX());
    
    //    switch (table->getPositionX()) {
    //        case <#constant#>:
    //            <#statements#>
    //            break;
    //
    //        default:
    //            break;
    //    }
    
    CCString *string = CCString::createWithFormat("AllSprites.png",idx );
    CCString *string2 = CCString::createWithFormat("%d",idx );
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
		cell = new CCTableViewCell();
		cell->autorelease();
        //  cell->removeChildByTag(456,true);
        cell->removeAllChildrenWithCleanup(true);
		CCSprite *sprite = CCSprite::create(string->getCString());
        
		sprite->setAnchorPoint(CCPointZero);
		sprite->setPosition(ccp(0, 0));
        
		cell->addChild(sprite,0);
        
        
        CCLog("!!!!!cell");
        //        CCLabelTTF *label = CCLabelTTF::create(string2->getCString(), "Helvetica", 35.0);
        //        label->setPosition(ccp(child_w/2, 15));
        //		label->setAnchorPoint(CCPointZero);
        //        label->setTag(123);
        //        label->setColor(ccWHITE);
        //        cell->addChild(label);
    }
    else
    {
        cell->removeAllChildrenWithCleanup(true);
		CCSprite *sprite = CCSprite::create(string->getCString());
        
		sprite->setAnchorPoint(CCPointZero);
		sprite->setPosition(ccp(0, 0));
        
		cell->addChild(sprite,0);
        
        
        //        CCLog("!!!!!cell");
        //        CCLabelTTF *label = CCLabelTTF::create(string2->getCString(), "Helvetica", 35.0);
        //        label->setPosition(ccp(child_w/2, 15));
        //		label->setAnchorPoint(CCPointZero);
        //        label->setTag(123);
        //        label->setColor(ccWHITE);
        //        cell->addChild(label);
        //        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
        //        label->setString(string2->getCString());
    }
    

    
    return cell;
}

unsigned int ScrollLayer::numberOfCellsInTableView(CCTableView *table)
{
    return EMLEMNUM;
}


