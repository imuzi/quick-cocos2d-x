#ifndef __TABLEVIEWTESTSCENE_H__
#define __TABLEVIEWTESTSCENE_H__

#include "cocos2d.h"
#include "MyTView.h"
#include "CData.h"

USING_NS_CC;
USING_NS_CC_EXT;



class TableViewTestLayer : public cocos2d::CCLayer, public MyTViewDataSource, public MyTViewDelegate
{

public:  
	TableViewTestLayer(void);  
	~TableViewTestLayer(void); 
public:
    
    static TableViewTestLayer* create();
    virtual bool init();  
   
	void StarSpin(int linenum);
    
    int _tag;
    

    float child_w,child_h;
//    CREATE_FUNC(TableViewTestLayer);
   
	void updatecell1( MyStCell *cell);
    void updatecell2( MyStCell *cell);
    void updatecell3( MyStCell *cell);
    void updatecell4( MyStCell *cell);
    void updatecell5( MyStCell *cell);

    void onScrollEnd(CCObject*psender);
    void onScrollBegin(CCObject*psender);
    
	MyTView* tableView1;
    MyTView* tableView2;
    MyTView* tableView3;
    MyTView* tableView4;
    MyTView* tableView5;
    
    const char *elepic;
    
    
    CData *data;
    
    float delayper;
    virtual void scrollViewDidScroll(MySView* view) {};
    virtual void scrollViewDidZoom(MySView* view) {};
    virtual void tableCellTouched(MyTView* table, MyStCell* cell);
    virtual cocos2d::CCSize cellSizeForTable(MyTView *table);
    virtual MyStCell* tableCellAtIndex(MyTView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(MyTView *table);
};
//class ViewCell2 : public MyTViewDataSource, public MyTViewDelegate
//{
//    virtual void scrollViewDidScroll(MySView* view) {};
//    virtual void scrollViewDidZoom(MySView* view) {};
//    virtual void tableCellTouched(MyTView* table, MyStCell* cell);
//    virtual cocos2d::CCSize cellSizeForTable(MyTView *table);
//    virtual MyStCell* tableCellAtIndex(MyTView *table, unsigned int idx);
//    virtual unsigned int numberOfCellsInTableView(MyTView *table);
//};
//class ViewCell3 : public MyTViewDataSource, public MyTViewDelegate
//{
//    virtual void scrollViewDidScroll(MySView* view) {};
//    virtual void scrollViewDidZoom(MySView* view) {};
//    virtual void tableCellTouched(MyTView* table, MyStCell* cell);
//    virtual cocos2d::CCSize cellSizeForTable(MyTView *table);
//    virtual MyStCell* tableCellAtIndex(MyTView *table, unsigned int idx);
//    virtual unsigned int numberOfCellsInTableView(MyTView *table);
//};
//class ViewCell4 : public MyTViewDataSource, public MyTViewDelegate
//{
//    virtual void scrollViewDidScroll(MySView* view) {};
//    virtual void scrollViewDidZoom(MySView* view) {};
//    virtual void tableCellTouched(MyTView* table, MyStCell* cell);
//    virtual cocos2d::CCSize cellSizeForTable(MyTView *table);
//    virtual MyStCell* tableCellAtIndex(MyTView *table, unsigned int idx);
//    virtual unsigned int numberOfCellsInTableView(MyTView *table);
//};
//class ViewCell5 : public MyTViewDataSource, public MyTViewDelegate
//{
//    virtual void scrollViewDidScroll(MySView* view) {};
//    virtual void scrollViewDidZoom(MySView* view) {};
//    virtual void tableCellTouched(MyTView* table, MyStCell* cell);
//    virtual cocos2d::CCSize cellSizeForTable(MyTView *table);
//    virtual MyStCell* tableCellAtIndex(MyTView *table, unsigned int idx);
//    virtual unsigned int numberOfCellsInTableView(MyTView *table);
//};
//class ViewCell1 : public MyTViewDataSource, public MyTViewDelegate
//{
//    virtual void scrollViewDidScroll(MySView* view) {};
//    virtual void scrollViewDidZoom(MySView* view) {};
//    virtual void tableCellTouched(MyTView* table, MyStCell* cell);
//    virtual cocos2d::CCSize cellSizeForTable(MyTView *table);
//    virtual MyStCell* tableCellAtIndex(MyTView *table, unsigned int idx);
//    virtual unsigned int numberOfCellsInTableView(MyTView *table);
//};

#endif // __TABLEVIEWTESTSCENE_H__
