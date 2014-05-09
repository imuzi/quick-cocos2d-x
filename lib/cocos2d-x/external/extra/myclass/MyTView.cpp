/****************************************************************************
 Copyright (c) 2012 cocos2d-x.org
 Copyright (c) 2010 Sangwoo Im
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "cocos2d.h"
#include "MyTView.h"
#include "MyStCell.h"
#include "menu_nodes/CCMenu.h"
#include "support/CCPointExtension.h"
#include "MySting.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"

NS_CC_EXT_BEGIN

MyTView* MyTView::create(MyTViewDataSource* dataSource, CCSize size)
{
    return MyTView::create(dataSource, size, NULL);
}

MyTView* MyTView::create(MyTViewDataSource* dataSource, CCSize size, CCNode *container)
{
    MyTView *table = new MyTView();
    table->initWithViewSize(size, container);
    table->autorelease();
    table->setDataSource(dataSource);
    table->_updateContentSize();

    return table;
}

bool MyTView::initWithViewSize(CCSize size, CCNode* container/* = NULL*/)
{
    if (MySView::initWithViewSize(size,container))
    {
        m_pCellsUsed      = new MyCCArrayForObjectSorting();
        m_pCellsFreed     = new MyCCArrayForObjectSorting();
        m_pIndices        = new std::set<unsigned int>();
        m_pTableViewDelegate = NULL;
        m_eVordering      = kMyTViewFillBottomUp;
        this->setDirection(kMySViewDirectionVertical);
        
        MySView::setDelegate(this);
        return true;
    }
    return false;
}

MyTView::MyTView()
: m_pIndices(NULL)
, m_pCellsUsed(NULL)
, m_pCellsFreed(NULL)
, m_pDataSource(NULL)
, m_pTableViewDelegate(NULL)
, m_eOldDirection(kMySViewDirectionNone)
{

}

MyTView::~MyTView()
{
    CC_SAFE_DELETE(m_pIndices);
    CC_SAFE_RELEASE(m_pCellsUsed);
    CC_SAFE_RELEASE(m_pCellsFreed);
}

void MyTView::setVerticalFillOrder(MyTViewVerticalFillOrder fillOrder)
{
    if (m_eVordering != fillOrder) {
        m_eVordering = fillOrder;
        if (m_pCellsUsed->count() > 0) {
            this->reloadData();
        }
    }
}

MyTViewVerticalFillOrder MyTView::getVerticalFillOrder()
{
    return m_eVordering;
}

void MyTView::reloadData()
{
    CCObject* pObj = NULL;
    CCARRAY_FOREACH(m_pCellsUsed, pObj)
    {
        MyStCell* cell = (MyStCell*)pObj;
        m_pCellsFreed->addObject(cell);
        cell->reset();
        if (cell->getParent() == this->getContainer())
        {
            this->getContainer()->removeChild(cell, true);
        }
    }

    m_pIndices->clear();
    m_pCellsUsed->release();
    m_pCellsUsed = new MyCCArrayForObjectSorting();
    
    this->_updateContentSize();
    if (m_pDataSource->numberOfCellsInTableView(this) > 0)
    {
        this->scrollViewDidScroll(this);
    }
}

MyStCell *MyTView::cellAtIndex(unsigned int idx)
{
    return this->_cellWithIndex(idx);
}

void MyTView::updateCellAtIndex(unsigned int idx)
{
    if (idx == CC_INVALID_INDEX)
    {
        return;
    }
    unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
    if (0 == uCountOfItems || idx > uCountOfItems-1)
    {
        return;
    }

    MyStCell* cell = this->_cellWithIndex(idx);
    if (cell)
    {
        this->_moveCellOutOfSight(cell);
    } 
    cell = m_pDataSource->tableCellAtIndex(this, idx);
    this->_setIndexForCell(idx, cell);
    this->_addCellIfNecessary(cell);
}

void MyTView::insertCellAtIndex(unsigned  int idx)
{
    if (idx == CC_INVALID_INDEX)
    {
        return;
    }

    unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
    if (0 == uCountOfItems || idx > uCountOfItems-1)
    {
        return;
    }

    MyStCell* cell = NULL;
    int newIdx = 0;
    
    cell = (MyStCell*)m_pCellsUsed->objectWithObjectID(idx);
    if (cell) 
    {
        newIdx = m_pCellsUsed->indexOfSortedObject(cell);
        for (unsigned int i=newIdx; i<m_pCellsUsed->count(); i++)
        {
            cell = (MyStCell*)m_pCellsUsed->objectAtIndex(i);
            this->_setIndexForCell(cell->getIdx()+1, cell);
        }
    }
    
 //   [m_pIndices shiftIndexesStartingAtIndex:idx by:1];
    
    //insert a new cell
    cell = m_pDataSource->tableCellAtIndex(this, idx);
    this->_setIndexForCell(idx, cell);
    this->_addCellIfNecessary(cell);
    
    this->_updateContentSize();
}

void MyTView::removeCellAtIndex(unsigned int idx)
{
    if (idx == CC_INVALID_INDEX)
    {
        return;
    }
    
    unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
    if (0 == uCountOfItems || idx > uCountOfItems-1)
    {
        return;
    }

    MyStCell* cell = NULL;
    unsigned int newIdx = 0;
    
    cell = this->_cellWithIndex(idx);
    if (!cell) {
        return;
    }
    
    newIdx = m_pCellsUsed->indexOfSortedObject(cell);
    
    //remove first
    this->_moveCellOutOfSight(cell);
    
    m_pIndices->erase(idx);
//    [m_pIndices shiftIndexesStartingAtIndex:idx+1 by:-1];
    for (unsigned int i=m_pCellsUsed->count()-1; i > newIdx; i--) {
        cell = (MyStCell*)m_pCellsUsed->objectAtIndex(i);
        this->_setIndexForCell(cell->getIdx()-1, cell);
    }
}

MyStCell *MyTView::dequeueCell()
{
    MyStCell *cell;
    
    if (m_pCellsFreed->count() == 0)
    {
        cell = NULL;
    } else {
        cell = (MyStCell*)m_pCellsFreed->objectAtIndex(0);
        cell->retain();
        m_pCellsFreed->removeObjectAtIndex(0);
        cell->autorelease();
    }
    return cell;
}

void MyTView::_addCellIfNecessary(MyStCell * cell)
{
    if (cell->getParent() != this->getContainer())
    {
        this->getContainer()->addChild(cell);
    }
    m_pCellsUsed->insertSortedObject(cell);
    m_pIndices->insert(cell->getIdx());
    // [m_pIndices addIndex:cell.idx];
}

void MyTView::_updateContentSize()
{
    CCSize     size, cellSize;
    unsigned int cellCount;

    cellSize  = m_pDataSource->cellSizeForTable(this);
    cellCount = m_pDataSource->numberOfCellsInTableView(this);
    
    switch (this->getDirection())
    {
        case kMySViewDirectionHorizontal:
            size = CCSizeMake(cellCount * cellSize.width, cellSize.height);
            break;
        default:
            size = CCSizeMake(cellSize.width, cellCount * cellSize.height);
            break;
    }
    this->setContentSize(size);

	if (m_eOldDirection != m_eDirection)
	{
		if (m_eDirection == kMySViewDirectionHorizontal)
		{
			this->setContentOffset(ccp(0,0));
		}
		else
		{
			this->setContentOffset(ccp(0,this->minContainerOffset().y));
		}
		m_eOldDirection = m_eDirection;
	}

}

CCPoint MyTView::_offsetFromIndex(unsigned int index)
{
    CCPoint offset = this->__offsetFromIndex(index);
    
    const CCSize cellSize = m_pDataSource->cellSizeForTable(this);
    if (m_eVordering == kMyTViewFillTopDown) {
        offset.y = this->getContainer()->getContentSize().height - offset.y - cellSize.height;
    }
    return offset;
}

CCPoint MyTView::__offsetFromIndex(unsigned int index)
{
    CCPoint offset;
    CCSize  cellSize;
    
    cellSize = m_pDataSource->cellSizeForTable(this);
    switch (this->getDirection()) {
        case kMySViewDirectionHorizontal:
            offset = ccp(cellSize.width * index, 0.0f);
            break;
        default:
            offset = ccp(0.0f, cellSize.height * index);
            break;
    }
    
    return offset;
}

unsigned int MyTView::_indexFromOffset(CCPoint offset)
{
    int index = 0;
    const int maxIdx = m_pDataSource->numberOfCellsInTableView(this)-1;

    const CCSize cellSize = m_pDataSource->cellSizeForTable(this);
    if (m_eVordering == kMyTViewFillTopDown) {
        offset.y = this->getContainer()->getContentSize().height - offset.y - cellSize.height;
    }
    index = MAX(0, this->__indexFromOffset(offset));
    index = MIN(index, maxIdx);

    return index;
}

int MyTView::__indexFromOffset(CCPoint offset)
{
    int  index = 0;
    CCSize     cellSize;
    
    cellSize = m_pDataSource->cellSizeForTable(this);
    
    switch (this->getDirection()) {
        case kMySViewDirectionHorizontal:
            index = offset.x/cellSize.width;
            break;
        default:
            index = offset.y/cellSize.height;
            break;
    }
    
    return index;
}

MyStCell* MyTView::_cellWithIndex(unsigned int cellIndex)
{
    MyStCell *found;
    
    found = NULL;
    
//     if ([m_pIndices containsIndex:cellIndex])
    if (m_pIndices->find(cellIndex) != m_pIndices->end())
    {
        found = (MyStCell *)m_pCellsUsed->objectWithObjectID(cellIndex);
    }
    
    return found;
}

void MyTView::_moveCellOutOfSight(MyStCell *cell)
{
    m_pCellsFreed->addObject(cell);
    m_pCellsUsed->removeSortedObject(cell);
    m_pIndices->erase(cell->getIdx());
    // [m_pIndices removeIndex:cell.idx];
    cell->reset();
    if (cell->getParent() == this->getContainer()) {
        this->getContainer()->removeChild(cell, true);;
    }
}

void MyTView::_setIndexForCell(unsigned int index, MyStCell *cell)
{
    cell->setAnchorPoint(ccp(0.0f, 0.0f));
    cell->setPosition(this->_offsetFromIndex(index));
    cell->setIdx(index);
}

void MyTView::scrollViewDidScroll(MySView* view)
{
    unsigned int uCountOfItems = m_pDataSource->numberOfCellsInTableView(this);
    if (0 == uCountOfItems)
    {
        return;
    }
    
    unsigned int startIdx = 0, endIdx = 0, idx = 0, maxIdx = 0;
    CCPoint offset = ccpMult(this->getContentOffset(), -1);
    maxIdx = MAX(uCountOfItems-1, 0);
    const CCSize cellSize = m_pDataSource->cellSizeForTable(this);
    
    if (m_eVordering == kMyTViewFillTopDown)
    {
        CCLog("~~~~!!!!!!tableview!");
        offset.y = offset.y + m_tViewSize.height/this->getContainer()->getScaleY() - cellSize.height;
    }
    startIdx = this->_indexFromOffset(offset);
    
    

    if (m_eVordering == kMyTViewFillTopDown)
    {
        offset.y -= m_tViewSize.height/this->getContainer()->getScaleY();
    }
    else 
    {
        offset.y += m_tViewSize.height/this->getContainer()->getScaleY();
    }
    offset.x += m_tViewSize.width/this->getContainer()->getScaleX();
    
    endIdx   = this->_indexFromOffset(offset);   
   
#if 0 // For Testing.
    CCObject* pObj;
    int i = 0;
    CCARRAY_FOREACH(m_pCellsUsed, pObj)
    {
        MyStCell* pCell = (MyStCell*)pObj;
        CCLog("cells Used index %d, value = %d", i, pCell->getIdx());
        i++;
    }
   // CCLog("---------------------------------------");
    i = 0;
    CCARRAY_FOREACH(m_pCellsFreed, pObj)
    {
        MyStCell* pCell = (MyStCell*)pObj;
        CCLog("cells freed index %d, value = %d", i, pCell->getIdx());
        i++;
    }
  //  CCLog("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
#endif
    
    if (m_pCellsUsed->count() > 0)
    {
        MyStCell* cell = (MyStCell*)m_pCellsUsed->objectAtIndex(0);

        idx = cell->getIdx();
        while(idx <startIdx)
        {
            this->_moveCellOutOfSight(cell);
            if (m_pCellsUsed->count() > 0)
            {
           
                cell = (MyStCell*)m_pCellsUsed->objectAtIndex(0);
                idx = cell->getIdx();    
            }
            else
            {
                break;
            }
        }
    }
    if (m_pCellsUsed->count() > 0)
    {
        MyStCell *cell = (MyStCell*)m_pCellsUsed->lastObject();
        idx = cell->getIdx();

        while(idx <= maxIdx && idx > endIdx)
        {
            this->_moveCellOutOfSight(cell);
            if (m_pCellsUsed->count() > 0)
            {
              
                cell = (MyStCell*)m_pCellsUsed->lastObject();
                idx = cell->getIdx();
                
            }
            else
            {
                break;
            }
        }
    }
    
    for (unsigned int i=startIdx; i <= endIdx; i++)
    {
        //if ([m_pIndices containsIndex:i])
        if (m_pIndices->find(i) != m_pIndices->end())
        {
          //  CCLog("~~~~~~~~~rrrrrrr~~~~~~~~~~~=%d",endIdx);
            continue;
        }
        this->updateCellAtIndex(i);
    }
}

void MyTView::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if (!this->isVisible()) {
        return;
    }
    if (m_pTouches->count() == 1 && !this->isTouchMoved()) {
        unsigned int        index;
        MyStCell   *cell;
        CCPoint           point;
        
        point = this->getContainer()->convertTouchToNodeSpace(pTouch);
        if (m_eVordering == kMyTViewFillTopDown) {
            CCSize cellSize = m_pDataSource->cellSizeForTable(this);
            point.y -= cellSize.height;
        }
        index = this->_indexFromOffset(point);
        cell  = this->_cellWithIndex(index);
        
        if (cell) {
            m_pTableViewDelegate->tableCellTouched(this, cell);
        }
    }
    MySView::ccTouchEnded(pTouch, pEvent);
}

NS_CC_EXT_END
