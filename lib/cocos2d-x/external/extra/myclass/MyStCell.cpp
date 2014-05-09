#include "MyStCell.h"

NS_CC_EXT_BEGIN

void MyStCell::reset()
{
    m_uIdx = CC_INVALID_INDEX;
}

void MyStCell::setObjectID(unsigned int uIdx)
{
    m_uIdx = uIdx;
}

unsigned int MyStCell::getObjectID()
{
    return m_uIdx;
}

unsigned int MyStCell::getIdx()
{
    return m_uIdx;
}

void MyStCell::setIdx(unsigned int uIdx)
{
    m_uIdx = uIdx;
}

NS_CC_EXT_END
