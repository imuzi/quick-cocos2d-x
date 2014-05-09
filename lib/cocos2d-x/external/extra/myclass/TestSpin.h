//
//  TestSpin.h
//  quickcocos2dx
//
//  Created by lee on 7/30/13.
//  Copyright (c) 2013 qeeplay.com. All rights reserved.
//

#ifndef __quickcocos2dx__TestSpin__
#define __quickcocos2dx__TestSpin__
#include "cocos2d.h"
#include "SpinTable.h"


USING_NS_CC;


#include <iostream>
class TestSpin : public cocos2d::CCLayer, public SpinTableDelegate
{
public:
    virtual bool init();
    static TestSpin* create();
    void update(float dat);
    SpinTable *tespin;
    
public:
    virtual float cellsSpaceWidthWithSpinTable(SpinTable * table);
    virtual float cellsSpaceHeightWithSpinTable(SpinTable * table);
    virtual SpinTableCell * getCell(SpinTable * table, int row, int column);
    virtual float spinVelocity(int column);
    virtual float spinVelocityShowResult(int column);
    virtual float spinDuration(int column);
    virtual void cellWillSpinInTable(SpinTable * table, SpinTableCell * cell);
    virtual void cellWillSpinInTableAndShowResult(SpinTable * table, SpinTableCell * cell, int rowIndex, int columnIndex);

};
#endif /* defined(__quickcocos2dx__TestSpin__) */
