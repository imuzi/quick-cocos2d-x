//
//  RandomOwn.h
//  quickcocos2dx
//
//  Created by leeyo on 4/8/14.
//  Copyright (c) 2014 qeeplay.com. All rights reserved.
//

#ifndef __quickcocos2dx__RandomOwn__
#define __quickcocos2dx__RandomOwn__

#include <iostream>
class RandomOwn {
    
public:
    RandomOwn(long long seed);
    ~RandomOwn();
    static RandomOwn* getInstance(long long seed);
    
    int nextInt(int n);
private:
    long long seed;
    double nextNextGaussian;
    bool haveNextNextGaussian = false;
    
    long long seedUniquifier();
    long long initialScramble(long long seed);
    void setSeed(long long seed);
    int next(int bits);
    void nextBytes(unsigned char *bytes/*byte[] bytes*/);
    int nextInt();

    long long nextLong();
    bool nextBoolean();
    float nextFloat();
    double nextDouble();
    double nextGaussian();
    
    
    long long multiplier = 25214903917/*0x5DEECE66DL*/;
    long long addend = 11/*0xBL*/;
    long long mask = 281474976710655/*(1L << 48) - 1*/;
    long long _seedUniquifier = 8682522807148012L/*8682522807148012L*/;
};

#endif /* defined(__quickcocos2dx__RandomOwn__) */
