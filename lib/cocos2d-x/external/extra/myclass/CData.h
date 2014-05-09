//
//  CData.h
//  coinflip
//
//  Created by WenyongLi on 7/22/13.
//
//

#ifndef __coinflip__CData__
#define __coinflip__CData__

#include <iostream>
class CData {
public :
    CData();
    ~CData();
    std::string dir;
    static CData* getAmInstance();
    bool line1End;
    bool line2End;
    bool line3End;
    bool line4End;
    bool line5End;
	int *value;
    int spinlines ;
    float slottableh;
    float slotenmh;
    
    void enterLua();
};




#endif /* defined(__coinflip__CData__) */
