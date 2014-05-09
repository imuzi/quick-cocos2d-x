//
//  CData.cpp
//  coinflip
//
//  Created by WenyongLi on 7/22/13.
//
//

#include "CData.h"
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include <string>
 
#include "myclass/CData.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
#include <dirent.h>
#include <sys/stat.h>
#endif
 
USING_NS_CC;

CData::CData()
: value(NULL)
,line1End(true)
,line2End(true)
,line3End(true)
,line4End(true)
,line5End(true)
,dir("")
{
    

}
CData::~CData(){}

static CData * m_amInstance;
CData * CData::getAmInstance()
{
    if ( m_amInstance == NULL )
    {
        m_amInstance = new CData();
    }
    return m_amInstance;
}

void CData::enterLua()
{
    string pathToSave = CCFileUtils::sharedFileUtils()->getWritablePath();
    //    if (isUpdateItemClicked)
    //    {
    string envvx = "";
    envvx.append(pathToSave);
    envvx.append("res/");
    
    string envvxx = "";
    envvxx.append(pathToSave);
    envvxx.append("");
    vector<string> searchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();
    CCLog("searchPaths00= %s",searchPaths[0].c_str());
    //        searchPaths.insert(searchPaths.begin(), envvx);
    
    //vector 最前面的路径将优先找！所以解决方案是优先那个路劲下载 删除优先级1的文件如果优先级2的文件在 就依然可以执行
    searchPaths.insert(searchPaths.begin(), envvxx);
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
    CCLog("searchPaths00= %s",searchPaths[0].c_str());
    CCLog("searchPaths01= %s",searchPaths[1].c_str());
    //    }
    //    CCFileUtils::sharedFileUtils()->addSearchPath(envvxx.c_str());
    CCLog("searchPaths =%s",pathToSave.c_str());
    
    
    CCScriptEngineManager::sharedManager()->purgeSharedManager();
    CCLuaEngine *pEngine = CCLuaEngine::defaultEngine();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);     CCLuaStack *pStack = pEngine->getLuaStack();
    lua_State* L = pStack->getLuaState();
    // load lua extensions
     
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    //    string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("res/AllSprites.png");
    pStack->loadChunksFromZIP("res/framework_precompiled.zip");
    string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("scripts/main.lua");
    CCLog("path = %s",path.c_str());
    CCLog("runLua = %s",path.c_str());
#else
    string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(getStartupScriptFilename().c_str());
#endif
    
    int pos;
    while ((pos = path.find_first_of("\\")) != std::string::npos)
    {
        path.replace(pos, 1, "/");
    }
    size_t p = path.find_last_of("/\\");
    if (p != path.npos)
    {
        const string _dir = path.substr(0, p);
        pStack->addSearchPath(_dir.c_str());
        
        p = _dir.find_last_of("/\\");
        if (p != _dir.npos)
        {
            pStack->addSearchPath(_dir.substr(0, p).c_str());
        }
        CCLog("~~~directory =%s",_dir.substr(0, p).c_str());
        CCLog("~~~pathToSave =%s",pathToSave.c_str());
        
        dir = _dir.substr(0, p).c_str();
        CCUserDefault::sharedUserDefault()->setStringForKey("directory", _dir.substr(0, p));
        CCUserDefault::sharedUserDefault()->flush();
    }
    
    pEngine->addSearchPath(pathToSave.c_str());
    pStack->addSearchPath(pathToSave.c_str());
    
    string envv = "";
    envv.append(pathToSave);
    envv.append("scripts/");
    pStack->addSearchPath(envv.c_str());
    //string env = "__LUA_STARTUP_FILE__=\"";
//    string env = "";
//    
//    env.append(pathToSave);
//    env.append("");
//    env.append("scripts/main.lua");
//    CCLog("------------path is = %s",path.c_str());
//    CCLog("------------env is = %s",env.c_str());
//    
//    pEngine->executeString(env.c_str());
    
    CCLog("------------------------------------------------");
//    CCLog("LOAD LUA FILE: %s", env.c_str());
    CCLog("------------------------------------------------");
    
//    string lnetdir = "";
//    lnetdir.append(dir);
//    lnetdir.append("/scripts/LNetManager.lua");
//    pEngine->executeScriptFile(lnetdir.c_str());
//    
//    pEngine->executeScriptFile(path.c_str());
    
    
    //----
        
    /* 如果设置了 -e 和 -ek 要加上下面这句
    
    // pStack->setXXTEAKeyAndSign("aaa", 3);
     
    // 如果设置了 -e 和 -ek -es 则要加上下面这句
     
//    pStack->setXXTEAKeyAndSign("aaa", 3, "XT", 2);
    
     load framework */     
    pStack->loadChunksFromZIP("res/game.zip");
    pStack->executeString("require 'main'");
    
    
}
