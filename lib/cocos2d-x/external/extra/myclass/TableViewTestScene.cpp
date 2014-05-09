#include "TableViewTestScene.h"
#include "TestSpin.h"
#include "CData.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define EMLEMNUM 13

#define LEFT1 
#define LEFT2
#define MID
#define RIGHT1
#define RIGHT2

TableViewTestLayer::TableViewTestLayer(void)  
{  
    delayper = 0.0f;
    tableView1 = NULL;
    tableView2 = NULL;  
    tableView3 = NULL;
    tableView4 = NULL;
    tableView5 = NULL;
    data = NULL ;
    elepic = NULL;
    
    
}  

TableViewTestLayer::~TableViewTestLayer(void)  
{  
}  
TableViewTestLayer* TableViewTestLayer::create()
{
    TableViewTestLayer *sprite = new TableViewTestLayer();
    if (sprite && sprite->init()) {
        sprite->autorelease();
        
        return sprite;
    }

    CC_SAFE_DELETE(sprite);
    sprite = NULL;
    return NULL;
}

bool TableViewTestLayer::init()
{
	bool bRet = false;

	do {
		CC_BREAK_IF(!CCLayer::init());
        data = CData::getAmInstance();
               
        
        elepic = "fightscene/icon_3.png";
        CCNotificationCenter::sharedNotificationCenter()->addObserver(
                                                                      this,
                                                                      callfuncO_selector(
                                                                                         TableViewTestLayer::onScrollBegin),
                                                                      "onScrollBegin",
                                                                      NULL);
        
        CCNotificationCenter::sharedNotificationCenter()->addObserver(
                                                                      this, 
                                                                      callfuncO_selector(
                                                                                         TableViewTestLayer::onScrollEnd), 
                                                                      "onScrollEnd", 
                                                                      NULL);
        
//        CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, "onScrollEnd");
//        CCNotificationCenter::sharedNotificationCenter()->removeObserver(this, "onScrollBegin");
        
              
        CCSprite *sprite = CCSprite::create(elepic);
        child_h = sprite->getContentSize().height;
        child_w = sprite->getContentSize().width;
        CCLog("tablelayer==%f",child_h);
        
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        data->slottableh = child_h*4 ;
        data->slotenmh = child_h ;
        
        
        
        
		tableView1 = MyTView::create(this, CCSizeMake(child_w, data->slottableh));
		tableView1->setDirection(kMySViewDirectionVertical);
		tableView1->setPosition(ccp(winSize.width*.80,0));
		tableView1->setDelegate(this);
		this->addChild(tableView1);
		tableView1->reloadData();
        
        tableView2 = MyTView::create(this, CCSizeMake(child_w, data->slottableh));
		tableView2->setDirection(kMySViewDirectionVertical);
		tableView2->setPosition(ccp(winSize.width*.60,0));
		tableView2->setDelegate(this);
		this->addChild(tableView2);
		tableView2->reloadData();
        
        tableView3 = MyTView::create(this, CCSizeMake(child_w, data->slottableh));
		tableView3->setDirection(kMySViewDirectionVertical);
		tableView3->setPosition(ccp(winSize.width*.4,0));
		tableView3->setDelegate(this);
		this->addChild(tableView3);
		tableView3->reloadData();
       
        
        tableView4 = MyTView::create(this, CCSizeMake(child_w, data->slottableh));
		tableView4->setDirection(kMySViewDirectionVertical);
		tableView4->setPosition(ccp(winSize.width*.2,0));
		tableView4->setDelegate(this);
		this->addChild(tableView4);
		tableView4->reloadData();
        
        tableView5 = MyTView::create(this, CCSizeMake(child_w, data->slottableh));
		tableView5->setDirection(kMySViewDirectionVertical);
		tableView5->setPosition(ccp(winSize.width*.0,0));
		tableView5->setDelegate(this);
		this->addChild(tableView5);
		tableView5->reloadData();
               
//        toExtensionsMainLayer(0);
//      this->schedule(schedule_selector(TableViewTestLayer::toExtensionsMainLayer),11.0f);
//        }
        CCLog("1024/228=%d",(int)(1024/228+1));
     
        tableView5->m_pContainer->setPosition(ccp(tableView5->m_pContainer->getPositionX(),
                                                  tableView5->m_pContainer->getPositionY()-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2));
        tableView4->m_pContainer->setPosition(ccp(tableView4->m_pContainer->getPositionX(),
                                                  tableView4->m_pContainer->getPositionY()-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2));
        tableView3->m_pContainer->setPosition(ccp(tableView3->m_pContainer->getPositionX(),
                                                  tableView3->m_pContainer->getPositionY()-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2));
        tableView2->m_pContainer->setPosition(ccp(tableView2->m_pContainer->getPositionX(),
                                                  tableView2->m_pContainer->getPositionY()-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2));
        tableView1->m_pContainer->setPosition(ccp(tableView1->m_pContainer->getPositionX(),
                                                  tableView1->m_pContainer->getPositionY()-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2));
//        tableView5->m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(0, ccp(0,-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))));
//        tableView4->m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(0, ccp(0,-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))));
//        tableView3->m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(0, ccp(0,-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))));
//        tableView2->m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(0, ccp(0,-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))));
//        tableView1->m_pContainer->runAction(CCEaseBackIn::create(CCMoveBy::create(0, ccp(0,-(child_h*((int)(data->slottableh/child_h+1))-data->slottableh)/2))));
//        
        
		bRet = true;
	} while (0);

	return bRet;
	
}

void TableViewTestLayer::onScrollBegin(cocos2d::CCObject *psender){
//   CCEaseBackOut
    
}

void TableViewTestLayer::onScrollEnd(cocos2d::CCObject *psender){
    
    if (data->spinlines ==5) {
        
        _tag++;
        if (_tag>1) {
            tableView1->cellAtIndex(data->value[0])->runAction(CCBlink::create(1.5, 75));
            tableView2->cellAtIndex(data->value[1])->runAction(CCBlink::create(1.5, 75));
            tableView3->cellAtIndex(data->value[2])->runAction(CCBlink::create(1.5, 75));
            tableView4->cellAtIndex(data->value[3])->runAction(CCBlink::create(1.5, 75));
            tableView5->cellAtIndex(data->value[4])->runAction(CCBlink::create(1.5, 75));
        }
        
        
        
    }
    else {
        tableView2->cellAtIndex(data->value[1])->runAction(CCBlink::create(1.5, 75));
        tableView3->cellAtIndex(data->value[2])->runAction(CCBlink::create(1.5, 75));
        tableView4->cellAtIndex(data->value[3])->runAction(CCBlink::create(1.5, 75));
        
         CCNotificationCenter::sharedNotificationCenter()->postNotification("fight",NULL);
    }
   
//    CCRepeat::create(CCEaseSineInOut::create(CCSequence::create(CCScaleTo::create(.3,1.1),CCScaleTo::create(.3,.91),CCScaleTo::create(.22,.1),NULL)), 5)
    CCLog("onScrollend!");
//    CCOrbitCamera::create(2, 1, 0, 0, 360, 0, 0), 5)
}
void TableViewTestLayer::StarSpin(int linenum)
{
    _tag = 0;
    delete []data->value;
    int a[5]={(int)(CCRANDOM_0_1()*6+3),(int)(CCRANDOM_0_1()*6+3),(int)(CCRANDOM_0_1()*6+3),(int)(CCRANDOM_0_1()*6+3),(int)(CCRANDOM_0_1()*6+3)};
    data->value = new int[5];
    for (int i=0; i<5; i++) {
        data->value[i] = a[i];
//        data->value[i] = i+3;
        
        CCLog("data->getvalue[i]=%d",data->value[i]);
    }
    data->spinlines = linenum;
    if (data->spinlines ==5) {
        tableView5->autoScroll5(ccp(0.00,360*.751));
        tableView4->autoScroll4(ccp(0.00,300*.751));
        tableView3->autoScroll3(ccp(0.00,230*.751));
        tableView2->autoScroll2(ccp(0.00,170*.751));
        tableView1->autoScroll1(ccp(0.00,130*.751));
    }
    else {
        tableView4->autoScroll4(ccp(0.00,360*.751));
        tableView3->autoScroll3(ccp(0.00,230*.751));
        tableView2->autoScroll2(ccp(0.00,130*.751));
 
    }
    
    
    
    
}

void TableViewTestLayer::tableCellTouched(MyTView* table, MyStCell* cell)
{

    CCLOG("cell touched at index: %i", 28-cell->getIdx());

//    cell->get
}

void TableViewTestLayer::updatecell1( MyStCell *cell)
{
    CCLog("updatecell!");
}
void TableViewTestLayer::updatecell2( MyStCell *cell)
{
    CCLog("updatecell!");
}
void TableViewTestLayer::updatecell3( MyStCell *cell)
{
    CCLog("updatecell!");
}
void TableViewTestLayer::updatecell4( MyStCell *cell)
{
    CCLog("updatecell!");
}
void TableViewTestLayer::updatecell5( MyStCell *cell)
{
    CCLog("updatecell!");
}

CCSize TableViewTestLayer::cellSizeForTable(MyTView *table)
{
//    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
//    CCSprite *sprite = CCSprite::create("StartButton.png");
    return CCSizeMake(child_w, child_h);
}

MyStCell* TableViewTestLayer::tableCellAtIndex(MyTView *table, unsigned int idx)
{
//    printf ("@@@@@@@@@@@@@@table->getPositionX()%f",table->getPositionX());
    
//    switch (table->getPositionX()) {
//        case <#constant#>:
//            <#statements#>
//            break;
//            
//        default:
//            break;
//    }
    
    CCString *string = CCString::createWithFormat("fightscene/icon_%d.png",idx );
    CCString *string2 = CCString::createWithFormat("%d",idx );
    MyStCell *cell = table->dequeueCell();
    if (!cell) {
		cell = new MyStCell();
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

//        cell->removeAllChildrenWithCleanup(true);
//        
//        CCSprite *sprite2 = CCSprite::create(elepic);
//       
//		sprite2->setAnchorPoint(CCPointZero);
//		sprite2->setPosition(ccp(0, 0));
//        
//		cell->addChild(sprite2,0);
    
//   
//        CCLog("cell~~~=%d",cell->getChildrenCount());
    
//    }


    return cell;
}

unsigned int TableViewTestLayer::numberOfCellsInTableView(MyTView *table)
{
    return EMLEMNUM;
}


