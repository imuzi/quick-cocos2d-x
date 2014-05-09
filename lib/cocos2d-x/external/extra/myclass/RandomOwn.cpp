//
//  RandomOwn.cpp
//  quickcocos2dx
//
//  Created by leeyo on 4/8/14.
//  Copyright (c) 2014 qeeplay.com. All rights reserved.
//

#include "RandomOwn.h"

//#define multiplier 0x5DEECE66DL
//#define addend 0xBL
//#define mask (1L << 48) - 1
//#define _seedUniquifier 8682522807148012L

static RandomOwn* m_pInstance;
RandomOwn* RandomOwn::getInstance(long long seed)
{
    if ( m_pInstance == NULL ){
        m_pInstance = new RandomOwn(seed);
    }
    else{
        m_pInstance->setSeed(seed);
    }
    return m_pInstance;
}

RandomOwn::RandomOwn(long long seed)
{
    this->seed = initialScramble(seed);

}

RandomOwn::~RandomOwn()
{
}
 
long long RandomOwn::seedUniquifier()
{
    long long current = _seedUniquifier;
    long long next = current * 181783497276652981L;
    
    return next;
}
long long RandomOwn::initialScramble(long long seed)
{
//    printf("%lld-------%lld----%lld---%lld---%lld \n",seed,(seed ^ multiplier) & mask,multiplier,mask,addend);
    return (seed ^ multiplier) & mask;

}
void RandomOwn::setSeed(long long seed)
{
    this->seed = initialScramble(seed);
    haveNextNextGaussian = false;

}
int RandomOwn::next(int bits)
{
    long long oldseed, nextseed;
    
    oldseed = this->seed;
    nextseed = (oldseed * multiplier + addend) & mask;
    
    this->seed = nextseed;
    
//    printf("(int)(nextseed >> (48 - bits)) ---%d \n",(int)(nextseed >> (48 - bits)));
    return (int)(nextseed >> (48 - bits));

}

int RandomOwn::nextInt(int n)
{
    if ((n & -n) == n)  // i.e., n is a power of 2
        return (int)((n * (long long)next(31)) >> 31);
    
    int bits, val;
    do {
        bits = next(31);
        val = bits % n;
    } while (bits - val + (n-1) < 0);
    return val;

}

void RandomOwn::nextBytes(unsigned char *bytes/*byte[] bytes*/)
{
    
    
    //    for (int i = 0, len = bytes.length; i < len; )
    //    for (int rnd = nextInt(),
    //         n = Math.min(len - i, Integer.SIZE/Byte.SIZE);
    //         n-- > 0; rnd >>= Byte.SIZE)
    //        bytes[i++] = (byte)rnd;
}
int RandomOwn::nextInt()
{
    return next(32);
}
//long long RandomOwn::nextLong()
//{
//}
//bool RandomOwn::nextBoolean()
//{
//}
//float RandomOwn::nextFloat()
//{
//}
//double RandomOwn::nextDouble()
//{
//}
//double RandomOwn::nextGaussian()
//{
//}