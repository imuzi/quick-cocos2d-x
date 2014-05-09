#ifndef __MyStCell_H__
#define __MyStCell_H__

#include "cocos2d.h"
#include "MySting.h"

NS_CC_EXT_BEGIN

/**
 * Abstract class for SWTableView cell node
 */
class MyStCell: public CCNode, public MyCCSortableObject
{
public:
    MyStCell() {}
    /**
     * The index used internally by SWTableView and its subclasses
     */
//     static MyStCell *getInstance(){
//         static MyStCell* m_datapush=NULL;
//         if (m_datapush==NULL)
//         {
//             m_datapush = new MyStCell();
//         }
//         return m_datapush;
//    

    unsigned int getIdx();
    void setIdx(unsigned int uIdx);
    /**
     * Cleans up any resources linked to this cell and resets <code>idx</code> property.
     */
    void reset();

    void setObjectID(unsigned int uIdx);
    unsigned int getObjectID();
private:
    unsigned int m_uIdx;
};

NS_CC_EXT_END

#endif /* __MyStCell_H__ */
