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

#ifndef __MyTView_H__
#define __MyTView_H__

#include "MySView.h"
#include "MyStCell.h"

#include <set>

NS_CC_EXT_BEGIN

class MyTView;
class MyCCArrayForObjectSorting;

typedef enum {
    kMyTViewFillTopDown,
    kMyTViewFillBottomUp
} MyTViewVerticalFillOrder;

/**
 * Sole purpose of this delegate is to single touch event in this version.
 */
class MyTViewDelegate : public MySViewDelegate
{
public:
    /**
     * Delegate to respond touch event
     *
     * @param table table contains the given cell
     * @param cell  cell that is touched
     */
    virtual void tableCellTouched(MyTView* table, MyStCell* cell) = 0;
};


/**
 * Data source that governs table backend data.
 */
class MyTViewDataSource
{
public:
    /**
     * cell height for a given table.
     *
     * @param table table to hold the instances of Class
     * @return cell size
     */
    virtual CCSize cellSizeForTable(MyTView *table) = 0;
    /**
     * a cell instance at a given index
     *
     * @param idx index to search for a cell
     * @return cell found at idx
     */
    virtual MyStCell* tableCellAtIndex(MyTView *table, unsigned int idx) = 0;
    /**
     * Returns number of cells in a given table view.
     * 
     * @return number of cells
     */
    virtual unsigned int numberOfCellsInTableView(MyTView *table) = 0;

};


/**
 * UITableView counterpart for cocos2d for iphone.
 *
 * this is a very basic, minimal implementation to bring UITableView-like component into cocos2d world.
 * 
 */
class MyTView : public MySView, public MySViewDelegate
{
public:
    MyTView();
    virtual ~MyTView();

    /**
     * An intialized table view object
     *
     * @param dataSource data source
     * @param size view size
     * @return table view
     */
    static MyTView* create(MyTViewDataSource* dataSource, CCSize size);
    /**
     * An initialized table view object
     *
     * @param dataSource data source;
     * @param size view size
     * @param container parent object for cells
     * @return table view
     */
    static MyTView* create(MyTViewDataSource* dataSource, CCSize size, CCNode *container);
    
    /**
     * data source
     */
    MyTViewDataSource* getDataSource() { return m_pDataSource; }
    void setDataSource(MyTViewDataSource* source) { m_pDataSource = source; }
    /**
     * delegate
     */
    MyTViewDelegate* getDelegate() { return m_pTableViewDelegate; } 
    void setDelegate(MyTViewDelegate* pDelegate) { m_pTableViewDelegate = pDelegate; }

    /**
     * determines how cell is ordered and filled in the view.
     */
    void setVerticalFillOrder(MyTViewVerticalFillOrder order);
    MyTViewVerticalFillOrder getVerticalFillOrder();


    bool initWithViewSize(CCSize size, CCNode* container = NULL);
    /**
     * Updates the content of the cell at a given index.
     *
     * @param idx index to find a cell
     */
    void updateCellAtIndex(unsigned int idx);
    /**
     * Inserts a new cell at a given index
     *
     * @param idx location to insert
     */
    void insertCellAtIndex(unsigned int idx);
    /**
     * Removes a cell at a given index
     *
     * @param idx index to find a cell
     */
    void removeCellAtIndex(unsigned int idx);
    /**
     * reloads data from data source.  the view will be refreshed.
     */
    void reloadData();
    /**
     * Dequeues a free cell if available. nil if not.
     *
     * @return free cell
     */
    MyStCell *dequeueCell();

    /**
     * Returns an existing cell at a given index. Returns nil if a cell is nonexistent at the moment of query.
     *
     * @param idx index
     * @return a cell at a given index
     */
    MyStCell *cellAtIndex(unsigned int idx);


    virtual void scrollViewDidScroll(MySView* view);
    virtual void scrollViewDidZoom(MySView* view) {}
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

protected:
    
    /**
     * vertical direction of cell filling
     */
    MyTViewVerticalFillOrder m_eVordering;
    
    /**
     * index set to query the indexes of the cells used.
     */
    std::set<unsigned int>* m_pIndices;
    //NSMutableIndexSet *indices_;
    /**
     * cells that are currently in the table
     */
    MyCCArrayForObjectSorting* m_pCellsUsed;
    /**
     * free list of cells
     */
    MyCCArrayForObjectSorting* m_pCellsFreed;
    /**
     * weak link to the data source object
     */
    MyTViewDataSource* m_pDataSource;
    /**
     * weak link to the delegate object
     */
    MyTViewDelegate* m_pTableViewDelegate;

	MySViewDirection m_eOldDirection;

    int __indexFromOffset(CCPoint offset);
    unsigned int _indexFromOffset(CCPoint offset);
    CCPoint __offsetFromIndex(unsigned int index);
    CCPoint _offsetFromIndex(unsigned int index);
    void _updateContentSize();

    MyStCell* _cellWithIndex(unsigned int cellIndex);
    void _moveCellOutOfSight(MyStCell *cell);
    void _setIndexForCell(unsigned int index, MyStCell *cell);
    void _addCellIfNecessary(MyStCell * cell);

};


NS_CC_EXT_END

#endif /* __MyTView_H__ */

