//
//  TestSpin.cpp
//  quickcocos2dx
//
//  Created by lee on 7/30/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#include "TestSpin.h"
TestSpin* TestSpin::create()
{
    TestSpin *sprite = new TestSpin();
    if (sprite && sprite->init()) {
        //        sprite->setPosition(ccp(300,300));
        //        sprite->setName(pszFileName);
        sprite->autorelease();
        return sprite;
    }
    //    else if (sprite && sprite->initWithSpriteFrameName(pszFileName)) {
    //        sprite->setPosition(ccp(300,300));
    //        sprite->setName(pszFileName);
    //        sprite->autorelease();
    //        return sprite;
    //    }
    //    picpath = pszFileName;
    CC_SAFE_DELETE(sprite);
    sprite = NULL;
    return NULL;
}

bool TestSpin::init()
{
	bool bRet = false;
    
	do {
		CC_BREAK_IF(!CCLayer::init());
        CCSprite *sprite = CCSprite::create("coin-2.png");
        float child_h = sprite->getContentSize().height;
        float child_w = sprite->getContentSize().width;
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        
        tespin = SpinTable::create(CCSizeMake(child_w*9, child_h*19), CCSizeMake(child_w*1, child_h*1), 8, 1);
        tespin->setPosition(ccp(winSize.width/4,100));
        tespin->setDelegate(this);
       tespin->reload();

        this->addChild(tespin,1,1);
        this->schedule(schedule_selector(TestSpin::update),7);
//              tespin->spin();
        bRet = true;
	} while (0);
    
	return bRet;
	
}

void TestSpin::update(float dat){
    
   tespin->spin();
    
}

float TestSpin::cellsSpaceWidthWithSpinTable(SpinTable * table){

    return 0;
    CCLog("cellsSpaceWidthWithSpinTable!");

};
float TestSpin::cellsSpaceHeightWithSpinTable(SpinTable * table){
        CCLog("cellsSpaceHeightWithSpinTable!");
return 0;
};
SpinTableCell * TestSpin::getCell(SpinTable * table, int row, int column){
    
     SpinTableCell * cell = SpinTableCell::create();
    CCSprite *sprite = CCSprite::create("coin-2.png");
    //        child_h = sprite->getContentSize().height;
    //        child_w = sprite->getContentSize().width;
    sprite->setAnchorPoint(ccp(0,0));
    sprite->setPosition(ccp(0, 0));
    
    CCString * stf = CCString::createWithFormat("row=%d",row);
    
    CCLabelTTF* rownum = CCLabelTTF::create(stf->getCString(), "", 40);
    sprite->addChild(rownum);
    
    
    cell->addChild(sprite,0,456);

    
    CCLog("getCell!");
    CCLog("row=%d",row);
    CCLog("column=%d",column);
    

return  cell;

};
float TestSpin::spinVelocity(int column){
    
    CCLog("spinVelocity!");
     CCLog("column=%d",column);

    return 4;
};
float TestSpin::spinVelocityShowResult(int column){
    CCLog("spinVelocityShowResult!");


    return 2;

};
float TestSpin::spinDuration(int column){
    CCLog("spinDuration!");

    return 2;
    

};
void TestSpin::cellWillSpinInTable(SpinTable * table, SpinTableCell * cell){
    CCLog("cellWillSpinInTable!");
        

    };
void TestSpin::cellWillSpinInTableAndShowResult(SpinTable * table, SpinTableCell * cell, int rowIndex, int columnIndex){
 CCLog("cellWillSpinInTableAndShowResult!");
    CCLog("rowidex =%d~~~~~~~~~~~~~~~~~~~~~~~~",rowIndex);
    CCLog("columnIndex =%d",columnIndex);
//    if (rowIndex==5) {
//        table->
//    }
    
};

