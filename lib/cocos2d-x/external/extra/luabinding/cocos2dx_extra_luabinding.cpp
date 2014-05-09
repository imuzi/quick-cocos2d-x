/*
** Lua binding: cocos2dx_extra_luabinding
** Generated automatically by tolua++-1.0.92 on Thu May  8 15:42:49 2014.
*/

#include "cocos2dx_extra_luabinding.h"
#include "CCLuaEngine.h"

using namespace cocos2d;




#include "crypto/CCCrypto.h"
#include "native/CCNative.h"
#include "network/CCNetwork.h"
#include "myclass/CData.h"
#include "myclass/MySprite.h"
#include "myclass/DialogLayer.h"
#include "myclass/MyLayer.h"
#include "myclass/FDPixelSprite.h"
#include "myclass/TableViewTestScene.h"
#include "myclass/NetManager.h"
#include "myclass/MsgManager.h"
#include "myclass/SliderLayer.h"
#include "myclass/MySocket.h"
#include "myclass/EXZoomController.h"
#include "myclass/CCLayerPanZoom.h"
#include "myclass/RandomOwn.h"
#include "spine/CCSkeletonAnimation.h"
#include "spine/CCSkeleton.h"
#include "spine/Animation.h"
#include "spine/AnimationState.h"
#include "spine/AnimationStateData.h"
#include "spine/Atlas.h"
#include "spine/AtlasAttachmentLoader.h"
#include "spine/Attachment.h"
#include "spine/AttachmentLoader.h"
#include "spine/Bone.h"
#include "spine/BoneData.h"
#include "spine/RegionAttachment.h"
#include "spine/Skeleton.h"
#include "spine/SkeletonData.h"
#include "spine/SkeletonJson.h"
#include "spine/Skin.h"
#include "spine/Slot.h"
#include "spine/SlotData.h"
using namespace std;
using namespace cocos2d;
using namespace cocos2d::extra;

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_cocos2d__CCRect (lua_State* tolua_S)
{
 cocos2d::CCRect* self = (cocos2d::CCRect*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCSkeleton (lua_State* tolua_S)
{
 CCSkeleton* self = (CCSkeleton*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_EXZoomController (lua_State* tolua_S)
{
 EXZoomController* self = (EXZoomController*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCLayerPanZoom (lua_State* tolua_S)
{
 CCLayerPanZoom* self = (CCLayerPanZoom*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCSkeletonAnimation (lua_State* tolua_S)
{
 CCSkeletonAnimation* self = (CCSkeletonAnimation*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCRect (lua_State* tolua_S)
{
 CCRect* self = (CCRect*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}


#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCPoint"); toluafix_add_type_mapping(typeid(CCPoint).hash_code(), "CCPoint");
 tolua_usertype(tolua_S,"MsgManager"); toluafix_add_type_mapping(typeid(MsgManager).hash_code(), "MsgManager");
 tolua_usertype(tolua_S,"FDPixelSprite"); toluafix_add_type_mapping(typeid(FDPixelSprite).hash_code(), "FDPixelSprite");
 tolua_usertype(tolua_S,"CCMenu"); toluafix_add_type_mapping(typeid(CCMenu).hash_code(), "CCMenu");
 tolua_usertype(tolua_S,"DialogLayer"); toluafix_add_type_mapping(typeid(DialogLayer).hash_code(), "DialogLayer");
 tolua_usertype(tolua_S,"MyLayer"); toluafix_add_type_mapping(typeid(MyLayer).hash_code(), "MyLayer");
 tolua_usertype(tolua_S,"CCNode"); toluafix_add_type_mapping(typeid(CCNode).hash_code(), "CCNode");
 tolua_usertype(tolua_S,"CCCrypto"); toluafix_add_type_mapping(typeid(CCCrypto).hash_code(), "CCCrypto");
 tolua_usertype(tolua_S,"CData"); toluafix_add_type_mapping(typeid(CData).hash_code(), "CData");
 tolua_usertype(tolua_S,"CCLayerColor"); toluafix_add_type_mapping(typeid(CCLayerColor).hash_code(), "CCLayerColor");
 tolua_usertype(tolua_S,"spTrackEntry"); toluafix_add_type_mapping(typeid(spTrackEntry).hash_code(), "spTrackEntry");
 tolua_usertype(tolua_S,"SEL_AnimationStateEvent"); toluafix_add_type_mapping(typeid(SEL_AnimationStateEvent).hash_code(), "SEL_AnimationStateEvent");
 tolua_usertype(tolua_S,"TableViewTestLayer"); toluafix_add_type_mapping(typeid(TableViewTestLayer).hash_code(), "TableViewTestLayer");
 tolua_usertype(tolua_S,"CCSkeletonAnimation"); toluafix_add_type_mapping(typeid(CCSkeletonAnimation).hash_code(), "CCSkeletonAnimation");
 tolua_usertype(tolua_S,"CCEditBox"); toluafix_add_type_mapping(typeid(CCEditBox).hash_code(), "CCEditBox");
 tolua_usertype(tolua_S,"LuaTableView"); toluafix_add_type_mapping(typeid(LuaTableView).hash_code(), "LuaTableView");
 tolua_usertype(tolua_S,"ccColor3B"); toluafix_add_type_mapping(typeid(ccColor3B).hash_code(), "ccColor3B");
 
 tolua_usertype(tolua_S,"CCObject"); toluafix_add_type_mapping(typeid(CCObject).hash_code(), "CCObject");
 tolua_usertype(tolua_S,"spEvent"); toluafix_add_type_mapping(typeid(spEvent).hash_code(), "spEvent");
 tolua_usertype(tolua_S,"SpineSkin"); toluafix_add_type_mapping(typeid(SpineSkin).hash_code(), "SpineSkin");
 tolua_usertype(tolua_S,"SliderLayer"); toluafix_add_type_mapping(typeid(SliderLayer).hash_code(), "SliderLayer");
 tolua_usertype(tolua_S,"spAtlas"); toluafix_add_type_mapping(typeid(spAtlas).hash_code(), "spAtlas");
 tolua_usertype(tolua_S,"MySocket"); toluafix_add_type_mapping(typeid(MySocket).hash_code(), "MySocket");
 tolua_usertype(tolua_S,"CCRect"); toluafix_add_type_mapping(typeid(CCRect).hash_code(), "CCRect");
 
 tolua_usertype(tolua_S,"EXZoomController"); toluafix_add_type_mapping(typeid(EXZoomController).hash_code(), "EXZoomController");
 tolua_usertype(tolua_S,"spAttachment"); toluafix_add_type_mapping(typeid(spAttachment).hash_code(), "spAttachment");
 tolua_usertype(tolua_S,"spAnimationStateData"); toluafix_add_type_mapping(typeid(spAnimationStateData).hash_code(), "spAnimationStateData");
 tolua_usertype(tolua_S,"spSlot"); toluafix_add_type_mapping(typeid(spSlot).hash_code(), "spSlot");
 tolua_usertype(tolua_S,"MySprite"); toluafix_add_type_mapping(typeid(MySprite).hash_code(), "MySprite");
 tolua_usertype(tolua_S,"CCSkeleton"); toluafix_add_type_mapping(typeid(CCSkeleton).hash_code(), "CCSkeleton");
 tolua_usertype(tolua_S,"ccColor4B"); toluafix_add_type_mapping(typeid(ccColor4B).hash_code(), "ccColor4B");
 tolua_usertype(tolua_S,"spBone"); toluafix_add_type_mapping(typeid(spBone).hash_code(), "spBone");
 tolua_usertype(tolua_S,"spSkeleton"); toluafix_add_type_mapping(typeid(spSkeleton).hash_code(), "spSkeleton");
 tolua_usertype(tolua_S,"CCBlendProtocol"); toluafix_add_type_mapping(typeid(CCBlendProtocol).hash_code(), "CCBlendProtocol");
 tolua_usertype(tolua_S,"cocos2d::CCRect");
 tolua_usertype(tolua_S,"RandomOwn"); toluafix_add_type_mapping(typeid(RandomOwn).hash_code(), "RandomOwn");
 tolua_usertype(tolua_S,"spEventType"); toluafix_add_type_mapping(typeid(spEventType).hash_code(), "spEventType");
 tolua_usertype(tolua_S,"CCLayerPanZoom"); toluafix_add_type_mapping(typeid(CCLayerPanZoom).hash_code(), "CCLayerPanZoom");
 tolua_usertype(tolua_S,"spSkeletonData"); toluafix_add_type_mapping(typeid(spSkeletonData).hash_code(), "spSkeletonData");
 tolua_usertype(tolua_S,"CCTargetedTouchDelegate"); toluafix_add_type_mapping(typeid(CCTargetedTouchDelegate).hash_code(), "CCTargetedTouchDelegate");
 tolua_usertype(tolua_S,"CCLayer"); toluafix_add_type_mapping(typeid(CCLayer).hash_code(), "CCLayer");
 tolua_usertype(tolua_S,"spAnimationState"); toluafix_add_type_mapping(typeid(spAnimationState).hash_code(), "spAnimationState");
 tolua_usertype(tolua_S,"NetManager"); toluafix_add_type_mapping(typeid(NetManager).hash_code(), "NetManager");
 tolua_usertype(tolua_S,"CCNetwork"); toluafix_add_type_mapping(typeid(CCNetwork).hash_code(), "CCNetwork");
 tolua_usertype(tolua_S,"MyTViewDelegate"); toluafix_add_type_mapping(typeid(MyTViewDelegate).hash_code(), "MyTViewDelegate");
 tolua_usertype(tolua_S,"CCSprite"); toluafix_add_type_mapping(typeid(CCSprite).hash_code(), "CCSprite");
 tolua_usertype(tolua_S,"CCNative"); toluafix_add_type_mapping(typeid(CCNative).hash_code(), "CCNative");
 tolua_usertype(tolua_S,"MyTViewDataSource"); toluafix_add_type_mapping(typeid(MyTViewDataSource).hash_code(), "MyTViewDataSource");
 tolua_usertype(tolua_S,"CCHTTPRequest"); toluafix_add_type_mapping(typeid(CCHTTPRequest).hash_code(), "CCHTTPRequest");
 tolua_usertype(tolua_S,"CursorTextField"); toluafix_add_type_mapping(typeid(CursorTextField).hash_code(), "CursorTextField");
}

/* method: getAES256KeyLength of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_getAES256KeyLength00
static int tolua_cocos2dx_extra_luabinding_CCCrypto_getAES256KeyLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  CCCrypto::getAES256KeyLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAES256KeyLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: encryptAES256Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_encryptAES25600
static int tolua_cocos2dx_extra_luabinding_CCCrypto_encryptAES25600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* plaintext = ((const char*)  tolua_tostring(tolua_S,2,0));
  int plaintextLength = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,4,0));
  int keyLength = ((int)  tolua_tonumber(tolua_S,5,0));
  {
     CCCrypto::encryptAES256Lua(plaintext,plaintextLength,key,keyLength);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'encryptAES256'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decryptAES256Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_decryptAES25600
static int tolua_cocos2dx_extra_luabinding_CCCrypto_decryptAES25600(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* ciphertext = ((const char*)  tolua_tostring(tolua_S,2,0));
  int ciphertextLength = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,4,0));
  int keyLength = ((int)  tolua_tonumber(tolua_S,5,0));
  {
     CCCrypto::decryptAES256Lua(ciphertext,ciphertextLength,key,keyLength);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decryptAES256'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: encryptXXTEALua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_encryptXXTEA00
static int tolua_cocos2dx_extra_luabinding_CCCrypto_encryptXXTEA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* plaintext = ((const char*)  tolua_tostring(tolua_S,2,0));
  int plaintextLength = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,4,0));
  int keyLength = ((int)  tolua_tonumber(tolua_S,5,0));
  {
     CCCrypto::encryptXXTEALua(plaintext,plaintextLength,key,keyLength);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'encryptXXTEA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decryptXXTEALua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_decryptXXTEA00
static int tolua_cocos2dx_extra_luabinding_CCCrypto_decryptXXTEA00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* ciphertext = ((const char*)  tolua_tostring(tolua_S,2,0));
  int ciphertextLength = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* key = ((const char*)  tolua_tostring(tolua_S,4,0));
  int keyLength = ((int)  tolua_tonumber(tolua_S,5,0));
  {
     CCCrypto::decryptXXTEALua(ciphertext,ciphertextLength,key,keyLength);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decryptXXTEA'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: encodeBase64Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_encodeBase6400
static int tolua_cocos2dx_extra_luabinding_CCCrypto_encodeBase6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* input = ((const char*)  tolua_tostring(tolua_S,2,0));
  int inputLength = ((int)  tolua_tonumber(tolua_S,3,0));
  {
     CCCrypto::encodeBase64Lua(input,inputLength);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'encodeBase64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: decodeBase64Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_decodeBase6400
static int tolua_cocos2dx_extra_luabinding_CCCrypto_decodeBase6400(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* input = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
     CCCrypto::decodeBase64Lua(input);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'decodeBase64'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MD5Lua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_MD500
static int tolua_cocos2dx_extra_luabinding_CCCrypto_MD500(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* input = ((char*)  tolua_tostring(tolua_S,2,0));
  bool isRawOutput = ((bool)  tolua_toboolean(tolua_S,3,0));
  {
     CCCrypto::MD5Lua(input,isRawOutput);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MD5FileLua of class  CCCrypto */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCCrypto_MD5File00
static int tolua_cocos2dx_extra_luabinding_CCCrypto_MD5File00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCCrypto",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
     CCCrypto::MD5FileLua(path);
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MD5File'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showActivityIndicator of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_showActivityIndicator00
static int tolua_cocos2dx_extra_luabinding_CCNative_showActivityIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCNative::showActivityIndicator();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showActivityIndicator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hideActivityIndicator of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_hideActivityIndicator00
static int tolua_cocos2dx_extra_luabinding_CCNative_hideActivityIndicator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCNative::hideActivityIndicator();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideActivityIndicator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createAlert of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_createAlert00
static int tolua_cocos2dx_extra_luabinding_CCNative_createAlert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* title = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* message = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* cancelButtonTitle = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   CCNative::createAlert(title,message,cancelButtonTitle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createAlert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAlertButton of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_addAlertButton00
static int tolua_cocos2dx_extra_luabinding_CCNative_addAlertButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* buttonTitle = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   int tolua_ret = (int)  CCNative::addAlertButton(buttonTitle);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAlertButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showAlertLua of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_showAlert00
static int tolua_cocos2dx_extra_luabinding_CCNative_showAlert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
  {
   CCNative::showAlertLua(listener);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showAlert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cancelAlert of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_cancelAlert00
static int tolua_cocos2dx_extra_luabinding_CCNative_cancelAlert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCNative::cancelAlert();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cancelAlert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOpenUDID of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_getOpenUDID00
static int tolua_cocos2dx_extra_luabinding_CCNative_getOpenUDID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   string tolua_ret = (string)  CCNative::getOpenUDID();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOpenUDID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: openURL of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_openURL00
static int tolua_cocos2dx_extra_luabinding_CCNative_openURL00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   CCNative::openURL(url);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'openURL'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInputText of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_getInputText00
static int tolua_cocos2dx_extra_luabinding_CCNative_getInputText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* title = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* message = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* defaultValue = ((const char*)  tolua_tostring(tolua_S,4,0));
  {
   string tolua_ret = (string)  CCNative::getInputText(title,message,defaultValue);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInputText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDeviceName of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_getDeviceName00
static int tolua_cocos2dx_extra_luabinding_CCNative_getDeviceName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const string tolua_ret = (const string)  CCNative::getDeviceName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDeviceName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: vibrate of class  CCNative */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNative_vibrate00
static int tolua_cocos2dx_extra_luabinding_CCNative_vibrate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNative",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCNative::vibrate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'vibrate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithUrlLua of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_createWithUrl00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_createWithUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
  const char* url = ((const char*)  tolua_tostring(tolua_S,3,0));
  int method = ((int)  tolua_tonumber(tolua_S,4,kCCHTTPRequestMethodGET));
  {
   CCHTTPRequest* tolua_ret = (CCHTTPRequest*)  CCHTTPRequest::createWithUrlLua(listener,url,method);
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCHTTPRequest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRequestUrl of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setRequestUrl00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setRequestUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* url = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRequestUrl'", NULL);
#endif
  {
   self->setRequestUrl(url);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRequestUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRequestUrl of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getRequestUrl00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getRequestUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRequestUrl'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getRequestUrl();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRequestUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addRequestHeader of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addRequestHeader00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addRequestHeader00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* header = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addRequestHeader'", NULL);
#endif
  {
   self->addRequestHeader(header);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addRequestHeader'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addPOSTValue of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addPOSTValue00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addPOSTValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* key = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addPOSTValue'", NULL);
#endif
  {
   self->addPOSTValue(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addPOSTValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPOSTData of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setPOSTData00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setPOSTData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* data = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPOSTData'", NULL);
#endif
  {
   self->setPOSTData(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPOSTData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addFormFile of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addFormFile00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addFormFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* filePath = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* fileType = ((const char*)  tolua_tostring(tolua_S,4,"application/octet-stream"));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFormFile'", NULL);
#endif
  {
   self->addFormFile(name,filePath,fileType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFormFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addFormContents of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addFormContents00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addFormContents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* value = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFormContents'", NULL);
#endif
  {
   self->addFormContents(name,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFormContents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCookieString of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setCookieString00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setCookieString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* cookie = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCookieString'", NULL);
#endif
  {
   self->setCookieString(cookie);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCookieString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCookieString of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getCookieString00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getCookieString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCookieString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getCookieString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCookieString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAcceptEncoding of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setAcceptEncoding00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setAcceptEncoding00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  int acceptEncoding = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAcceptEncoding'", NULL);
#endif
  {
   self->setAcceptEncoding(acceptEncoding);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAcceptEncoding'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTimeout of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setTimeout00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setTimeout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  int timeout = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTimeout'", NULL);
#endif
  {
   self->setTimeout(timeout);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTimeout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_start00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->start();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cancel of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_cancel00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_cancel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cancel'", NULL);
#endif
  {
   self->cancel();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cancel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getState of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getState00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getState'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getState();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseStatusCode of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseStatusCode00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseStatusCode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseStatusCode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getResponseStatusCode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseStatusCode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseHeadersString of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseHeadersString00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseHeadersString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseHeadersString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getResponseHeadersString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseHeadersString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseString of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseString00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseString'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getResponseString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseDataLua of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseData00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseDataLua'", NULL);
#endif
  {
     self->getResponseDataLua();
   
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResponseDataLength of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseDataLength00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseDataLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResponseDataLength'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getResponseDataLength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResponseDataLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: saveResponseData of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_saveResponseData00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_saveResponseData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'saveResponseData'", NULL);
#endif
  {
   int tolua_ret = (int)  self->saveResponseData(filename);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'saveResponseData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getErrorCode of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getErrorCode00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getErrorCode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getErrorCode'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getErrorCode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getErrorCode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getErrorMessage of class  CCHTTPRequest */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getErrorMessage00
static int tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getErrorMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCHTTPRequest",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCHTTPRequest* self = (CCHTTPRequest*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getErrorMessage'", NULL);
#endif
  {
   string tolua_ret = (string)  self->getErrorMessage();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getErrorMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isLocalWiFiAvailable of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNetwork_isLocalWiFiAvailable00
static int tolua_cocos2dx_extra_luabinding_CCNetwork_isLocalWiFiAvailable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  CCNetwork::isLocalWiFiAvailable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isLocalWiFiAvailable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isInternetConnectionAvailable of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNetwork_isInternetConnectionAvailable00
static int tolua_cocos2dx_extra_luabinding_CCNetwork_isInternetConnectionAvailable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  CCNetwork::isInternetConnectionAvailable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isInternetConnectionAvailable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isHostNameReachable of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNetwork_isHostNameReachable00
static int tolua_cocos2dx_extra_luabinding_CCNetwork_isHostNameReachable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* hostName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  CCNetwork::isHostNameReachable(hostName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isHostNameReachable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInternetConnectionStatus of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNetwork_getInternetConnectionStatus00
static int tolua_cocos2dx_extra_luabinding_CCNetwork_getInternetConnectionStatus00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  CCNetwork::getInternetConnectionStatus();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInternetConnectionStatus'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createHTTPRequestLua of class  CCNetwork */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCNetwork_createHTTPRequest00
static int tolua_cocos2dx_extra_luabinding_CCNetwork_createHTTPRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCNetwork",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION listener = (  toluafix_ref_function(tolua_S,2,0));
  const char* url = ((const char*)  tolua_tostring(tolua_S,3,0));
  int method = ((int)  tolua_tonumber(tolua_S,4,kCCHTTPRequestMethodGET));
  {
   CCHTTPRequest* tolua_ret = (CCHTTPRequest*)  CCNetwork::createHTTPRequestLua(listener,url,method);
    int nID = (tolua_ret) ? tolua_ret->m_uID : -1;
int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCHTTPRequest");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createHTTPRequest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  MySocket */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MySocket_getInstance00
static int tolua_cocos2dx_extra_luabinding_MySocket_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MySocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MySocket* tolua_ret = (MySocket*)  MySocket::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MySocket");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  MySocket */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MySocket_init00
static int tolua_cocos2dx_extra_luabinding_MySocket_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MySocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MySocket* self = (MySocket*)  tolua_tousertype(tolua_S,1,0);
  const char* ip = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(ip,port);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartRequest of class  MySocket */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MySocket_StartRequest00
static int tolua_cocos2dx_extra_luabinding_MySocket_StartRequest00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MySocket",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MySocket* self = (MySocket*)  tolua_tousertype(tolua_S,1,0);
  int cbMsgId = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartRequest'", NULL);
#endif
  {
   self->StartRequest(cbMsgId);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartRequest'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: closePThread of class  MySocket */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MySocket_closePThread00
static int tolua_cocos2dx_extra_luabinding_MySocket_closePThread00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MySocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MySocket* self = (MySocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'closePThread'", NULL);
#endif
  {
   self->closePThread();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'closePThread'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  MySocket */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MySocket_destroy00
static int tolua_cocos2dx_extra_luabinding_MySocket_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MySocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MySocket* self = (MySocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'destroy'", NULL);
#endif
  {
   self->destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dir of class  CData */
#ifndef TOLUA_DISABLE_tolua_get_CData_dir
static int tolua_get_CData_dir(lua_State* tolua_S)
{
  CData* self = (CData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dir'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->dir);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dir of class  CData */
#ifndef TOLUA_DISABLE_tolua_set_CData_dir
static int tolua_set_CData_dir(lua_State* tolua_S)
{
  CData* self = (CData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dir'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dir = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAmInstance of class  CData */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CData_getAmInstance00
static int tolua_cocos2dx_extra_luabinding_CData_getAmInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CData* tolua_ret = (CData*)  CData::getAmInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAmInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enterLua of class  CData */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CData_enterLua00
static int tolua_cocos2dx_extra_luabinding_CData_enterLua00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CData* self = (CData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enterLua'", NULL);
#endif
  {
   self->enterLua();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enterLua'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createMS of class  MySprite */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MySprite_createMS00
static int tolua_cocos2dx_extra_luabinding_MySprite_createMS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MySprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   MySprite* tolua_ret = (MySprite*)  MySprite::createMS(fileName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MySprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createMS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pMenu of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pMenu_ptr
static int tolua_get_DialogLayer_m_pMenu_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pMenu'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pMenu,"CCMenu");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pMenu of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pMenu_ptr
static int tolua_set_DialogLayer_m_pMenu_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pMenu'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCMenu",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pMenu = ((CCMenu*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pMenu2 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pMenu2_ptr
static int tolua_get_DialogLayer_m_pMenu2_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pMenu2'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pMenu2,"CCMenu");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pMenu2 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pMenu2_ptr
static int tolua_set_DialogLayer_m_pMenu2_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pMenu2'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCMenu",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pMenu2 = ((CCMenu*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pLayer of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pLayer_ptr
static int tolua_get_DialogLayer_m_pLayer_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLayer'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pLayer,"CCLayer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pLayer of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pLayer_ptr
static int tolua_set_DialogLayer_m_pLayer_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pLayer'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCLayer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pLayer = ((CCLayer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pEditBox1 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pEditBox1_ptr
static int tolua_get_DialogLayer_m_pEditBox1_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox1'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pEditBox1,"CCEditBox");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pEditBox1 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pEditBox1_ptr
static int tolua_set_DialogLayer_m_pEditBox1_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox1'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCEditBox",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pEditBox1 = ((CCEditBox*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pEditBox2 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pEditBox2_ptr
static int tolua_get_DialogLayer_m_pEditBox2_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox2'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pEditBox2,"CCEditBox");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pEditBox2 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pEditBox2_ptr
static int tolua_set_DialogLayer_m_pEditBox2_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox2'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCEditBox",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pEditBox2 = ((CCEditBox*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pEditBox3 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pEditBox3_ptr
static int tolua_get_DialogLayer_m_pEditBox3_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox3'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pEditBox3,"CCEditBox");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pEditBox3 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pEditBox3_ptr
static int tolua_set_DialogLayer_m_pEditBox3_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox3'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCEditBox",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pEditBox3 = ((CCEditBox*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pEditBox4 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pEditBox4_ptr
static int tolua_get_DialogLayer_m_pEditBox4_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox4'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pEditBox4,"CCEditBox");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pEditBox4 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pEditBox4_ptr
static int tolua_set_DialogLayer_m_pEditBox4_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox4'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCEditBox",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pEditBox4 = ((CCEditBox*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pEditBox5 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pEditBox5_ptr
static int tolua_get_DialogLayer_m_pEditBox5_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox5'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pEditBox5,"CCEditBox");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pEditBox5 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pEditBox5_ptr
static int tolua_set_DialogLayer_m_pEditBox5_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pEditBox5'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCEditBox",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pEditBox5 = ((CCEditBox*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_pTextField of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_pTextField_ptr
static int tolua_get_DialogLayer_m_pTextField_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pTextField'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_pTextField,"CursorTextField");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_pTextField of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_pTextField_ptr
static int tolua_set_DialogLayer_m_pTextField_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_pTextField'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CursorTextField",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_pTextField = ((CursorTextField*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tableview of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_tableview_ptr
static int tolua_get_DialogLayer_m_tableview_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tableview'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_tableview,"LuaTableView");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tableview of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_tableview_ptr
static int tolua_set_DialogLayer_m_tableview_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tableview'",NULL);
  if (!tolua_isusertype(tolua_S,2,"LuaTableView",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tableview = ((LuaTableView*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_tableview1 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_get_DialogLayer_m_tableview1_ptr
static int tolua_get_DialogLayer_m_tableview1_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tableview1'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->m_tableview1,"LuaTableView");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_tableview1 of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_set_DialogLayer_m_tableview1_ptr
static int tolua_set_DialogLayer_m_tableview1_ptr(lua_State* tolua_S)
{
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_tableview1'",NULL);
  if (!tolua_isusertype(tolua_S,2,"LuaTableView",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_tableview1 = ((LuaTableView*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: disableTouch of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_DialogLayer_disableTouch00
static int tolua_cocos2dx_extra_luabinding_DialogLayer_disableTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DialogLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disableTouch'", NULL);
#endif
  {
   self->disableTouch();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disableTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: eanbleTouch of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_DialogLayer_eanbleTouch00
static int tolua_cocos2dx_extra_luabinding_DialogLayer_eanbleTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DialogLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'eanbleTouch'", NULL);
#endif
  {
   self->eanbleTouch();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'eanbleTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerScriptTouchHandler of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_DialogLayer_registerScriptTouchHandler00
static int tolua_cocos2dx_extra_luabinding_DialogLayer_registerScriptTouchHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DialogLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerScriptTouchHandler'", NULL);
#endif
  {
   self->registerScriptTouchHandler(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerScriptTouchHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unRegisterScriptTouchHandler of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_DialogLayer_unRegisterScriptTouchHandler00
static int tolua_cocos2dx_extra_luabinding_DialogLayer_unRegisterScriptTouchHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DialogLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unRegisterScriptTouchHandler'", NULL);
#endif
  {
   self->unRegisterScriptTouchHandler();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unRegisterScriptTouchHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableTouch of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_DialogLayer_enableTouch00
static int tolua_cocos2dx_extra_luabinding_DialogLayer_enableTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"DialogLayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  DialogLayer* self = (DialogLayer*)  tolua_tousertype(tolua_S,1,0);
  CCNode* child = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableTouch'", NULL);
#endif
  {
   self->enableTouch(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_DialogLayer_create00
static int tolua_cocos2dx_extra_luabinding_DialogLayer_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DialogLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   DialogLayer* tolua_ret = (DialogLayer*)  DialogLayer::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DialogLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_DialogLayer_create01
static int tolua_cocos2dx_extra_luabinding_DialogLayer_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DialogLayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const ccColor4B* color = ((const ccColor4B*)  tolua_tousertype(tolua_S,2,0));
  {
   DialogLayer* tolua_ret = (DialogLayer*)  DialogLayer::create(*color);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DialogLayer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_DialogLayer_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  DialogLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_DialogLayer_create02
static int tolua_cocos2dx_extra_luabinding_DialogLayer_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"DialogLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int priorityRate = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   DialogLayer* tolua_ret = (DialogLayer*)  DialogLayer::create(priorityRate);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"DialogLayer");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_DialogLayer_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  MyLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MyLayer_create00
static int tolua_cocos2dx_extra_luabinding_MyLayer_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MyLayer* tolua_ret = (MyLayer*)  MyLayer::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHeight of class  MyLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MyLayer_getHeight00
static int tolua_cocos2dx_extra_luabinding_MyLayer_getHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyLayer* self = (MyLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  FDPixelSprite */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_FDPixelSprite_create00
static int tolua_cocos2dx_extra_luabinding_FDPixelSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FDPixelSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* pszFileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   FDPixelSprite* tolua_ret = (FDPixelSprite*)  FDPixelSprite::create(pszFileName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FDPixelSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __CCTargetedTouchDelegate__ of class  FDPixelSprite */
#ifndef TOLUA_DISABLE_tolua_get_FDPixelSprite___CCTargetedTouchDelegate__
static int tolua_get_FDPixelSprite___CCTargetedTouchDelegate__(lua_State* tolua_S)
{
  FDPixelSprite* self = (FDPixelSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__CCTargetedTouchDelegate__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<CCTargetedTouchDelegate*>(self), "CCTargetedTouchDelegate");
#else
   tolua_pushusertype(tolua_S,(void*)((CCTargetedTouchDelegate*)self), "CCTargetedTouchDelegate");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  TableViewTestLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_TableViewTestLayer_create00
static int tolua_cocos2dx_extra_luabinding_TableViewTestLayer_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TableViewTestLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TableViewTestLayer* tolua_ret = (TableViewTestLayer*)  TableViewTestLayer::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TableViewTestLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StarSpin of class  TableViewTestLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_TableViewTestLayer_StarSpin00
static int tolua_cocos2dx_extra_luabinding_TableViewTestLayer_StarSpin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TableViewTestLayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TableViewTestLayer* self = (TableViewTestLayer*)  tolua_tousertype(tolua_S,1,0);
  int linenum = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StarSpin'", NULL);
#endif
  {
   self->StarSpin(linenum);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StarSpin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __MyTViewDataSource__ of class  TableViewTestLayer */
#ifndef TOLUA_DISABLE_tolua_get_TableViewTestLayer___MyTViewDataSource__
static int tolua_get_TableViewTestLayer___MyTViewDataSource__(lua_State* tolua_S)
{
  TableViewTestLayer* self = (TableViewTestLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__MyTViewDataSource__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<MyTViewDataSource*>(self), "MyTViewDataSource");
#else
   tolua_pushusertype(tolua_S,(void*)((MyTViewDataSource*)self), "MyTViewDataSource");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __MyTViewDelegate__ of class  TableViewTestLayer */
#ifndef TOLUA_DISABLE_tolua_get_TableViewTestLayer___MyTViewDelegate__
static int tolua_get_TableViewTestLayer___MyTViewDelegate__(lua_State* tolua_S)
{
  TableViewTestLayer* self = (TableViewTestLayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__MyTViewDelegate__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<MyTViewDelegate*>(self), "MyTViewDelegate");
#else
   tolua_pushusertype(tolua_S,(void*)((MyTViewDelegate*)self), "MyTViewDelegate");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  NetManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_NetManager_getInstance00
static int tolua_cocos2dx_extra_luabinding_NetManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetManager* tolua_ret = (NetManager*)  NetManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ContectLong of class  NetManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_NetManager_ContectLong00
static int tolua_cocos2dx_extra_luabinding_NetManager_ContectLong00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetManager* self = (NetManager*)  tolua_tousertype(tolua_S,1,0);
  const char* ip = ((const char*)  tolua_tostring(tolua_S,2,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ContectLong'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ContectLong(ip,port);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ContectLong'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RecvData of class  NetManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_NetManager_RecvData00
static int tolua_cocos2dx_extra_luabinding_NetManager_RecvData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetManager* self = (NetManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RecvData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RecvData();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RecvData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendData of class  NetManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_NetManager_SendData00
static int tolua_cocos2dx_extra_luabinding_NetManager_SendData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetManager* self = (NetManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendData'", NULL);
#endif
  {
   int tolua_ret = (int)  self->SendData();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_getInstance00
static int tolua_cocos2dx_extra_luabinding_MsgManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MsgManager* tolua_ret = (MsgManager*)  MsgManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MsgManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: msgnum of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_get_MsgManager_msgnum
static int tolua_get_MsgManager_msgnum(lua_State* tolua_S)
{
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'msgnum'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->msgnum);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: msgnum of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_set_MsgManager_msgnum
static int tolua_set_MsgManager_msgnum(lua_State* tolua_S)
{
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'msgnum'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->msgnum = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: recvbuffer of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_get_MsgManager_unsigned_recvbuffer
static int tolua_get_MsgManager_unsigned_recvbuffer(lua_State* tolua_S)
{
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'recvbuffer'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->recvbuffer);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: recvbuffer of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_set_MsgManager_unsigned_recvbuffer
static int tolua_set_MsgManager_unsigned_recvbuffer(lua_State* tolua_S)
{
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'recvbuffer'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->recvbuffer,(const char*)tolua_tostring(tolua_S,2,0),4049-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sendbuffer of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_get_MsgManager_unsigned_sendbuffer
static int tolua_get_MsgManager_unsigned_sendbuffer(lua_State* tolua_S)
{
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sendbuffer'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->sendbuffer);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sendbuffer of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_set_MsgManager_unsigned_sendbuffer
static int tolua_set_MsgManager_unsigned_sendbuffer(lua_State* tolua_S)
{
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sendbuffer'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->sendbuffer,(const char*)tolua_tostring(tolua_S,2,0),4049-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: cleanBuffer of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_cleanBuffer00
static int tolua_cocos2dx_extra_luabinding_MsgManager_cleanBuffer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cleanBuffer'", NULL);
#endif
  {
   self->cleanBuffer();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cleanBuffer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHeadMsgId of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_setHeadMsgId00
static int tolua_cocos2dx_extra_luabinding_MsgManager_setHeadMsgId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
  int msgid = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHeadMsgId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->setHeadMsgId(msgid);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHeadMsgId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHeadMsgKind of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_setHeadMsgKind00
static int tolua_cocos2dx_extra_luabinding_MsgManager_setHeadMsgKind00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
  int msgkind = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHeadMsgKind'", NULL);
#endif
  {
   int tolua_ret = (int)  self->setHeadMsgKind(msgkind);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHeadMsgKind'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeBodyShort of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyShort00
static int tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
  short value = ((short)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeBodyShort'", NULL);
#endif
  {
   int tolua_ret = (int)  self->writeBodyShort(value);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeBodyShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeBodyByte of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyByte00
static int tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned char value = ((unsigned char)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeBodyByte'", NULL);
#endif
  {
   int tolua_ret = (int)  self->writeBodyByte(value);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeBodyByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeBodyInt of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyInt00
static int tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeBodyInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->writeBodyInt(value);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeBodyInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeBodyString of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyString00
static int tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
  char* value = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeBodyString'", NULL);
#endif
  {
   int tolua_ret = (int)  self->writeBodyString(value);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeBodyString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getsendMsg of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_getsendMsg00
static int tolua_cocos2dx_extra_luabinding_MsgManager_getsendMsg00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getsendMsg'", NULL);
#endif
  {
   unsigned char* tolua_ret = (unsigned char*)  self->getsendMsg();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getsendMsg'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: writeBodyLong of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyLong00
static int tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyLong00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
  long long value = ((long long)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'writeBodyLong'", NULL);
#endif
  {
   int tolua_ret = (int)  self->writeBodyLong(value);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'writeBodyLong'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readBodyLong of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_readBodyLong00
static int tolua_cocos2dx_extra_luabinding_MsgManager_readBodyLong00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readBodyLong'", NULL);
#endif
  {
   long long tolua_ret = (long long)  self->readBodyLong();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readBodyLong'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMsgId of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_getMsgId00
static int tolua_cocos2dx_extra_luabinding_MsgManager_getMsgId00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMsgId'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMsgId();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMsgId'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBodyLen of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_getBodyLen00
static int tolua_cocos2dx_extra_luabinding_MsgManager_getBodyLen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBodyLen'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getBodyLen();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBodyLen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getResult of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_getResult00
static int tolua_cocos2dx_extra_luabinding_MsgManager_getResult00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getResult'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getResult();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getResult'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readBodyShort of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_readBodyShort00
static int tolua_cocos2dx_extra_luabinding_MsgManager_readBodyShort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readBodyShort'", NULL);
#endif
  {
   short tolua_ret = (short)  self->readBodyShort();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readBodyShort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readBodyByte of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_readBodyByte00
static int tolua_cocos2dx_extra_luabinding_MsgManager_readBodyByte00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readBodyByte'", NULL);
#endif
  {
   unsigned char tolua_ret = (unsigned char)  self->readBodyByte();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readBodyByte'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readBodyInt of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_readBodyInt00
static int tolua_cocos2dx_extra_luabinding_MsgManager_readBodyInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readBodyInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->readBodyInt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readBodyInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: readBodyString of class  MsgManager */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_MsgManager_readBodyString00
static int tolua_cocos2dx_extra_luabinding_MsgManager_readBodyString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MsgManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MsgManager* self = (MsgManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'readBodyString'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->readBodyString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'readBodyString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  SliderLayer */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_SliderLayer_create00
static int tolua_cocos2dx_extra_luabinding_SliderLayer_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SliderLayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SliderLayer* tolua_ret = (SliderLayer*)  SliderLayer::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SliderLayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: state of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeletonAnimation_state_ptr
static int tolua_get_CCSkeletonAnimation_state_ptr(lua_State* tolua_S)
{
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->state,"spAnimationState");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: state of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeletonAnimation_state_ptr
static int tolua_set_CCSkeletonAnimation_state_ptr(lua_State* tolua_S)
{
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'state'",NULL);
  if (!tolua_isusertype(tolua_S,2,"spAnimationState",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->state = ((spAnimationState*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: createSpineSkin of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createSpineSkin00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createSpineSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   SpineSkin* tolua_ret = (SpineSkin*)  CCSkeletonAnimation::createSpineSkin(num);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpineSkin");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createSpineSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: releaseSpineSkin of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_releaseSpineSkin00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_releaseSpineSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SpineSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSkin* skin = ((SpineSkin*)  tolua_tousertype(tolua_S,2,0));
  {
   CCSkeletonAnimation::releaseSpineSkin(skin);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'releaseSpineSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addSpineSkin of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_addSpineSkin00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_addSpineSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SpineSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isstring(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SpineSkin* skin = ((SpineSkin*)  tolua_tousertype(tolua_S,2,0));
  int pos = ((int)  tolua_tonumber(tolua_S,3,0));
  const char* slotName = ((const char*)  tolua_tostring(tolua_S,4,0));
  const char* skinName = ((const char*)  tolua_tostring(tolua_S,5,0));
  {
   CCSkeletonAnimation::addSpineSkin(skin,pos,slotName,skinName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSpineSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"SpineSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  SpineSkin* skin = ((SpineSkin*)  tolua_tousertype(tolua_S,4,0));
  int num = ((int)  tolua_tonumber(tolua_S,5,0));
  float scale = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  CCSkeletonAnimation::createWithFile(skeletonDataFile,atlasFile,skin,num,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"SpineSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  SpineSkin* skin = ((SpineSkin*)  tolua_tousertype(tolua_S,4,0));
  int num = ((int)  tolua_tonumber(tolua_S,5,0));
  float scale = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  Mtolua_new((CCSkeletonAnimation)(skeletonDataFile,atlasFile,skin,num,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00_local
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"SpineSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  SpineSkin* skin = ((SpineSkin*)  tolua_tousertype(tolua_S,4,0));
  int num = ((int)  tolua_tonumber(tolua_S,5,0));
  float scale = ((float)  tolua_tonumber(tolua_S,6,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  Mtolua_new((CCSkeletonAnimation)(skeletonDataFile,atlasFile,skin,num,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m_nScriptAnimationHandler of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeletonAnimation_m_nScriptAnimationHandler
static int tolua_get_CCSkeletonAnimation_m_nScriptAnimationHandler(lua_State* tolua_S)
{
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nScriptAnimationHandler'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m_nScriptAnimationHandler);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m_nScriptAnimationHandler of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeletonAnimation_m_nScriptAnimationHandler
static int tolua_set_CCSkeletonAnimation_m_nScriptAnimationHandler(lua_State* tolua_S)
{
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm_nScriptAnimationHandler'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m_nScriptAnimationHandler = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: listenAnimName of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeletonAnimation_listenAnimName
static int tolua_get_CCSkeletonAnimation_listenAnimName(lua_State* tolua_S)
{
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'listenAnimName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->listenAnimName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: listenAnimName of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeletonAnimation_listenAnimName
static int tolua_set_CCSkeletonAnimation_listenAnimName(lua_State* tolua_S)
{
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'listenAnimName'",NULL);
  if (!tolua_istable(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
 strncpy((char*)
self->listenAnimName,(const char*)tolua_tostring(tolua_S,2,0),20-1);
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerAnimationStatusListener of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_registerAnimationStatusListener00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_registerAnimationStatusListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
  const char* animName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerAnimationStatusListener'", NULL);
#endif
  {
   self->registerAnimationStatusListener(handler,animName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerAnimationStatusListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unRegisterAnimationStatusListener of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_unRegisterAnimationStatusListener00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_unRegisterAnimationStatusListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unRegisterAnimationStatusListener'", NULL);
#endif
  {
   self->unRegisterAnimationStatusListener();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unRegisterAnimationStatusListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationDuration of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_getAnimationDuration00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_getAnimationDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  const char* animName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationDuration'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAnimationDuration(animName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationDuration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithData of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithData00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  CCSkeletonAnimation::createWithData(skeletonData);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile01
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  CCSkeletonAnimation::createWithFile(skeletonDataFile,atlas,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile02
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  CCSkeletonAnimation::createWithFile(skeletonDataFile,atlasFile,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  Mtolua_new((CCSkeletonAnimation)(skeletonData));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01_local
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  Mtolua_new((CCSkeletonAnimation)(skeletonData));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  Mtolua_new((CCSkeletonAnimation)(skeletonDataFile,atlas,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02_local
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  Mtolua_new((CCSkeletonAnimation)(skeletonDataFile,atlas,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new03
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  Mtolua_new((CCSkeletonAnimation)(skeletonDataFile,atlasFile,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new03_local
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeletonAnimation* tolua_ret = (CCSkeletonAnimation*)  Mtolua_new((CCSkeletonAnimation)(skeletonDataFile,atlasFile,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeletonAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_delete00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_update00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  float deltaTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(deltaTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimationStateData of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimationStateData00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimationStateData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spAnimationStateData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  spAnimationStateData* stateData = ((spAnimationStateData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationStateData'", NULL);
#endif
  {
   self->setAnimationStateData(stateData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationStateData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMix of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setMix00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setMix00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  const char* fromAnimation = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* toAnimation = ((const char*)  tolua_tostring(tolua_S,3,0));
  float duration = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMix'", NULL);
#endif
  {
   self->setMix(fromAnimation,toAnimation,duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMix'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimationListener of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimationListener00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimationListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"SEL_AnimationStateEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  CCObject* instance = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  SEL_AnimationStateEvent method = *((SEL_AnimationStateEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationListener'", NULL);
#endif
  {
   self->setAnimationListener(instance,method);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimation00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->setAnimation(trackIndex,name,loop);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAnimation of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_addAnimation00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_addAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* name = ((const char*)  tolua_tostring(tolua_S,3,0));
  bool loop = ((bool)  tolua_toboolean(tolua_S,4,0));
  float delay = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAnimation'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->addAnimation(trackIndex,name,loop,delay);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrent of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_getCurrent00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_getCurrent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrent'", NULL);
#endif
  {
   spTrackEntry* tolua_ret = (spTrackEntry*)  self->getCurrent(trackIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spTrackEntry");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearTracks of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_clearTracks00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_clearTracks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearTracks'", NULL);
#endif
  {
   self->clearTracks();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearTracks'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearTrack of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_clearTrack00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_clearTrack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clearTrack'", NULL);
#endif
  {
   self->clearTrack(trackIndex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearTrack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onAnimationStateEvent of class  CCSkeletonAnimation */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_onAnimationStateEvent00
static int tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_onAnimationStateEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeletonAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"spEventType",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"spEvent",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeletonAnimation* self = (CCSkeletonAnimation*)  tolua_tousertype(tolua_S,1,0);
  int trackIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  spEventType type = *((spEventType*)  tolua_tousertype(tolua_S,3,0));
  spEvent* event = ((spEvent*)  tolua_tousertype(tolua_S,4,0));
  int loopCount = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onAnimationStateEvent'", NULL);
#endif
  {
   self->onAnimationStateEvent(trackIndex,type,event,loopCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onAnimationStateEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skeleton of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton_skeleton_ptr
static int tolua_get_CCSkeleton_skeleton_ptr(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skeleton'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->skeleton,"spSkeleton");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skeleton of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeleton_skeleton_ptr
static int tolua_set_CCSkeleton_skeleton_ptr(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skeleton'",NULL);
  if (!tolua_isusertype(tolua_S,2,"spSkeleton",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skeleton = ((spSkeleton*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rootBone of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton_rootBone_ptr
static int tolua_get_CCSkeleton_rootBone_ptr(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rootBone'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->rootBone,"spBone");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rootBone of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeleton_rootBone_ptr
static int tolua_set_CCSkeleton_rootBone_ptr(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rootBone'",NULL);
  if (!tolua_isusertype(tolua_S,2,"spBone",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rootBone = ((spBone*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: timeScale of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton_timeScale
static int tolua_get_CCSkeleton_timeScale(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->timeScale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: timeScale of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeleton_timeScale
static int tolua_set_CCSkeleton_timeScale(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'timeScale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->timeScale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: debugSlots of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton_debugSlots
static int tolua_get_CCSkeleton_debugSlots(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'debugSlots'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->debugSlots);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: debugSlots of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeleton_debugSlots
static int tolua_set_CCSkeleton_debugSlots(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'debugSlots'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->debugSlots = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: debugBones of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton_debugBones
static int tolua_get_CCSkeleton_debugBones(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'debugBones'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->debugBones);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: debugBones of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeleton_debugBones
static int tolua_set_CCSkeleton_debugBones(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'debugBones'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->debugBones = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: premultipliedAlpha of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton_premultipliedAlpha
static int tolua_get_CCSkeleton_premultipliedAlpha(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'premultipliedAlpha'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->premultipliedAlpha);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: premultipliedAlpha of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeleton_premultipliedAlpha
static int tolua_set_CCSkeleton_premultipliedAlpha(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'premultipliedAlpha'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->premultipliedAlpha = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_new00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"SpineSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  SpineSkin* equips = ((SpineSkin*)  tolua_tousertype(tolua_S,4,0));
  int changeNum = ((int)  tolua_tonumber(tolua_S,5,0));
  float scale = ((float)  tolua_tonumber(tolua_S,6,1));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  Mtolua_new((CCSkeleton)(skeletonDataFile,atlasFile,equips,changeNum,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_new00_local
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"SpineSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  SpineSkin* equips = ((SpineSkin*)  tolua_tousertype(tolua_S,4,0));
  int changeNum = ((int)  tolua_tonumber(tolua_S,5,0));
  float scale = ((float)  tolua_tonumber(tolua_S,6,1));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  Mtolua_new((CCSkeleton)(skeletonDataFile,atlasFile,equips,changeNum,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: myColor of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton_myColor
static int tolua_get_CCSkeleton_myColor(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'myColor'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->myColor,"ccColor3B");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: myColor of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeleton_myColor
static int tolua_set_CCSkeleton_myColor(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'myColor'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccColor3B",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->myColor = *((ccColor3B*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isAdditive of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton_isAdditive
static int tolua_get_CCSkeleton_isAdditive(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isAdditive'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isAdditive);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isAdditive of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_set_CCSkeleton_isAdditive
static int tolua_set_CCSkeleton_isAdditive(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isAdditive'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isAdditive = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColorAndAdditive of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_setColorAndAdditive00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_setColorAndAdditive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
  const ccColor3B* color = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColorAndAdditive'", NULL);
#endif
  {
   self->setColorAndAdditive(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColorAndAdditive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: restoreColorAndAdditive of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_restoreColorAndAdditive00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_restoreColorAndAdditive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'restoreColorAndAdditive'", NULL);
#endif
  {
   self->restoreColorAndAdditive();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'restoreColorAndAdditive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttachmentHeight of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_getAttachmentHeight00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_getAttachmentHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
  const char* attachmentName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttachmentHeight'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getAttachmentHeight(attachmentName);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttachmentHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithData of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithData00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  bool ownsSkeletonData = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  CCSkeleton::createWithData(skeletonData,ownsSkeletonData);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithFile00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  CCSkeleton::createWithFile(skeletonDataFile,atlas,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithFile of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithFile01
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithFile01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  CCSkeleton::createWithFile(skeletonDataFile,atlasFile,scale);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithFile00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_new01
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  bool ownsSkeletonData = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  Mtolua_new((CCSkeleton)(skeletonData,ownsSkeletonData));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeleton_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_new01_local
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"spSkeletonData",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  spSkeletonData* skeletonData = ((spSkeletonData*)  tolua_tousertype(tolua_S,2,0));
  bool ownsSkeletonData = ((bool)  tolua_toboolean(tolua_S,3,false));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  Mtolua_new((CCSkeleton)(skeletonData,ownsSkeletonData));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeleton_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_new02
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  Mtolua_new((CCSkeleton)(skeletonDataFile,atlas,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeleton_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_new02_local
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"spAtlas",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  spAtlas* atlas = ((spAtlas*)  tolua_tousertype(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  Mtolua_new((CCSkeleton)(skeletonDataFile,atlas,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeleton_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_new03
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  Mtolua_new((CCSkeleton)(skeletonDataFile,atlasFile,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeleton_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_new03_local
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* skeletonDataFile = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* atlasFile = ((const char*)  tolua_tostring(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   CCSkeleton* tolua_ret = (CCSkeleton*)  Mtolua_new((CCSkeleton)(skeletonDataFile,atlasFile,scale));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCSkeleton");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_CCSkeleton_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_delete00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_update00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
  float deltaTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(deltaTime);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_draw00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boundingBox of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_boundingBox00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_boundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boundingBox'", NULL);
#endif
  {
   cocos2d::CCRect tolua_ret = (cocos2d::CCRect)  self->boundingBox();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((cocos2d::CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"cocos2d::CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(cocos2d::CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"cocos2d::CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateWorldTransform of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_updateWorldTransform00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_updateWorldTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateWorldTransform'", NULL);
#endif
  {
   self->updateWorldTransform();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateWorldTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setToSetupPose of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_setToSetupPose00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_setToSetupPose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setToSetupPose'", NULL);
#endif
  {
   self->setToSetupPose();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setToSetupPose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBonesToSetupPose of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_setBonesToSetupPose00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_setBonesToSetupPose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBonesToSetupPose'", NULL);
#endif
  {
   self->setBonesToSetupPose();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBonesToSetupPose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSlotsToSetupPose of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_setSlotsToSetupPose00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_setSlotsToSetupPose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSlotsToSetupPose'", NULL);
#endif
  {
   self->setSlotsToSetupPose();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSlotsToSetupPose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findBone of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_findBone00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_findBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCSkeleton* self = (const CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
  const char* boneName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findBone'", NULL);
#endif
  {
   spBone* tolua_ret = (spBone*)  self->findBone(boneName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spBone");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findSlot of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_findSlot00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_findSlot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCSkeleton* self = (const CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
  const char* slotName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findSlot'", NULL);
#endif
  {
   spSlot* tolua_ret = (spSlot*)  self->findSlot(slotName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spSlot");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findSlot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkin of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_setSkin00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_setSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
  const char* skinName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setSkin(skinName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttachment of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_getAttachment00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_getAttachment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCSkeleton* self = (const CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
  const char* slotName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* attachmentName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttachment'", NULL);
#endif
  {
   spAttachment* tolua_ret = (spAttachment*)  self->getAttachment(slotName,attachmentName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"spAttachment");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttachment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAttachment of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCSkeleton_setAttachment00
static int tolua_cocos2dx_extra_luabinding_CCSkeleton_setAttachment00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkeleton",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
  const char* slotName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* attachmentName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAttachment'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->setAttachment(slotName,attachmentName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAttachment'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __CCBlendProtocol__ of class  CCSkeleton */
#ifndef TOLUA_DISABLE_tolua_get_CCSkeleton___CCBlendProtocol__
static int tolua_get_CCSkeleton___CCBlendProtocol__(lua_State* tolua_S)
{
  CCSkeleton* self = (CCSkeleton*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__CCBlendProtocol__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<CCBlendProtocol*>(self), "CCBlendProtocol");
#else
   tolua_pushusertype(tolua_S,(void*)((CCBlendProtocol*)self), "CCBlendProtocol");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_new00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EXZoomController* tolua_ret = (EXZoomController*)  Mtolua_new((EXZoomController)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EXZoomController");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_new00_local
static int tolua_cocos2dx_extra_luabinding_EXZoomController_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EXZoomController* tolua_ret = (EXZoomController*)  Mtolua_new((EXZoomController)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EXZoomController");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_delete00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: controllerWithNode of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_controllerWithNode00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_controllerWithNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  {
   EXZoomController* tolua_ret = (EXZoomController*)  EXZoomController::controllerWithNode(node);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EXZoomController");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'controllerWithNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithNode of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_initWithNode00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_initWithNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithNode'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithNode(node);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: centerOnPinch of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_centerOnPinch
static int tolua_get_EXZoomController_centerOnPinch(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'centerOnPinch'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->centerOnPinch);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: centerOnPinch of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_centerOnPinch
static int tolua_set_EXZoomController_centerOnPinch(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'centerOnPinch'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->centerOnPinch = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: zoomOnDoubleTap of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_zoomOnDoubleTap
static int tolua_get_EXZoomController_zoomOnDoubleTap(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zoomOnDoubleTap'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->zoomOnDoubleTap);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: zoomOnDoubleTap of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_zoomOnDoubleTap
static int tolua_set_EXZoomController_zoomOnDoubleTap(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zoomOnDoubleTap'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->zoomOnDoubleTap = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: zoomRate of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_zoomRate
static int tolua_get_EXZoomController_zoomRate(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zoomRate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->zoomRate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: zoomRate of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_zoomRate
static int tolua_set_EXZoomController_zoomRate(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zoomRate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->zoomRate = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: zoomInLimit of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_zoomInLimit
static int tolua_get_EXZoomController_zoomInLimit(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zoomInLimit'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->zoomInLimit);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: zoomInLimit of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_zoomInLimit
static int tolua_set_EXZoomController_zoomInLimit(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zoomInLimit'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->zoomInLimit = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: zoomOutLimit of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_zoomOutLimit
static int tolua_get_EXZoomController_zoomOutLimit(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zoomOutLimit'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->zoomOutLimit);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: zoomOutLimit of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_zoomOutLimit
static int tolua_set_EXZoomController_zoomOutLimit(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zoomOutLimit'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->zoomOutLimit = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: swipeVelocityMultiplier of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_swipeVelocityMultiplier
static int tolua_get_EXZoomController_swipeVelocityMultiplier(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'swipeVelocityMultiplier'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->swipeVelocityMultiplier);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: swipeVelocityMultiplier of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_swipeVelocityMultiplier
static int tolua_set_EXZoomController_swipeVelocityMultiplier(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'swipeVelocityMultiplier'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->swipeVelocityMultiplier = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollDuration of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_scrollDuration
static int tolua_get_EXZoomController_scrollDuration(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollDuration'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scrollDuration);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollDuration of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_scrollDuration
static int tolua_set_EXZoomController_scrollDuration(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollDuration'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scrollDuration = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollDamping of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_scrollDamping
static int tolua_get_EXZoomController_scrollDamping(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollDamping'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scrollDamping);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollDamping of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_scrollDamping
static int tolua_set_EXZoomController_scrollDamping(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollDamping'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scrollDamping = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pinchDamping of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_pinchDamping
static int tolua_get_EXZoomController_pinchDamping(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pinchDamping'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pinchDamping);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pinchDamping of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_pinchDamping
static int tolua_set_EXZoomController_pinchDamping(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pinchDamping'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pinchDamping = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pinchDistanceThreshold of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_pinchDistanceThreshold
static int tolua_get_EXZoomController_pinchDistanceThreshold(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pinchDistanceThreshold'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pinchDistanceThreshold);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pinchDistanceThreshold of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_pinchDistanceThreshold
static int tolua_set_EXZoomController_pinchDistanceThreshold(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pinchDistanceThreshold'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pinchDistanceThreshold = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: doubleTapZoomDuration of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_doubleTapZoomDuration
static int tolua_get_EXZoomController_doubleTapZoomDuration(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'doubleTapZoomDuration'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->doubleTapZoomDuration);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: doubleTapZoomDuration of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_doubleTapZoomDuration
static int tolua_set_EXZoomController_doubleTapZoomDuration(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'doubleTapZoomDuration'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->doubleTapZoomDuration = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: multitouchnum of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_get_EXZoomController_multitouchnum
static int tolua_get_EXZoomController_multitouchnum(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'multitouchnum'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->multitouchnum);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: multitouchnum of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_set_EXZoomController_multitouchnum
static int tolua_set_EXZoomController_multitouchnum(lua_State* tolua_S)
{
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'multitouchnum'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->multitouchnum = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBoundingRect of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_setBoundingRect00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_setBoundingRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCRect rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBoundingRect'", NULL);
#endif
  {
   self->setBoundingRect(rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBoundingRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoundingRect of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_getBoundingRect00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_getBoundingRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoundingRect'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->getBoundingRect();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoundingRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setWindowRect of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_setWindowRect00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_setWindowRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCRect rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setWindowRect'", NULL);
#endif
  {
   self->setWindowRect(rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setWindowRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWindowRect of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_getWindowRect00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_getWindowRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWindowRect'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->getWindowRect();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindowRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getOptimalZoomOutLimit of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_getOptimalZoomOutLimit00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_getOptimalZoomOutLimit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getOptimalZoomOutLimit'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getOptimalZoomOutLimit();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getOptimalZoomOutLimit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updatePosition of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_updatePosition00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_updatePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCPoint pos = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updatePosition'", NULL);
#endif
  {
   self->updatePosition(pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updatePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: centerOnPoint of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_centerOnPoint00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_centerOnPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCPoint pt = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'centerOnPoint'", NULL);
#endif
  {
   self->centerOnPoint(pt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'centerOnPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: centerOnPoint of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_centerOnPoint01
static int tolua_cocos2dx_extra_luabinding_EXZoomController_centerOnPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCPoint pt = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
  float duration = ((float)  tolua_tonumber(tolua_S,3,0));
  float rate = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'centerOnPoint'", NULL);
#endif
  {
   self->centerOnPoint(pt,duration,rate);
  }
 }
 return 0;
tolua_lerror:
 return tolua_cocos2dx_extra_luabinding_EXZoomController_centerOnPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: zoomInOnPoint of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_zoomInOnPoint00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_zoomInOnPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCPoint pt = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
  float duration = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'zoomInOnPoint'", NULL);
#endif
  {
   self->zoomInOnPoint(pt,duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'zoomInOnPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: zoomOutOnPoint of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_zoomOutOnPoint00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_zoomOutOnPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCPoint pt = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
  float duration = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'zoomOutOnPoint'", NULL);
#endif
  {
   self->zoomOutOnPoint(pt,duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'zoomOutOnPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: zoomOnPoint of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_zoomOnPoint00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_zoomOnPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  CCPoint pt = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
  float duration = ((float)  tolua_tonumber(tolua_S,3,0));
  float scale = ((float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'zoomOnPoint'", NULL);
#endif
  {
   self->zoomOnPoint(pt,duration,scale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'zoomOnPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableWithTouchPriority of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_enableWithTouchPriority00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_enableWithTouchPriority00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
  int priority = ((int)  tolua_tonumber(tolua_S,2,0));
  bool swallowsTouches = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableWithTouchPriority'", NULL);
#endif
  {
   self->enableWithTouchPriority(priority,swallowsTouches);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableWithTouchPriority'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disable of class  EXZoomController */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_EXZoomController_disable00
static int tolua_cocos2dx_extra_luabinding_EXZoomController_disable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EXZoomController",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EXZoomController* self = (EXZoomController*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disable'", NULL);
#endif
  {
   self->disable();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: layer of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_layer00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_layer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCLayerPanZoom* tolua_ret = (CCLayerPanZoom*)  CCLayerPanZoom::layer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCLayerPanZoom");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'layer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_delete00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isPanLayerMoved of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_isPanLayerMoved00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_isPanLayerMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isPanLayerMoved'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isPanLayerMoved();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isPanLayerMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_init00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_update00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onEnter of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_onEnter00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_onEnter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onEnter'", NULL);
#endif
  {
   self->onEnter();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onEnter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: onExit of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_onExit00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_onExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'onExit'", NULL);
#endif
  {
   self->onExit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'onExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enablePanZoom of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_enablePanZoom00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_enablePanZoom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enablePanZoom'", NULL);
#endif
  {
   self->enablePanZoom();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enablePanZoom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: disablePanZoom of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_disablePanZoom00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_disablePanZoom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'disablePanZoom'", NULL);
#endif
  {
   self->disablePanZoom();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'disablePanZoom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMaxScale of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setMaxScale00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setMaxScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
  float maxScale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMaxScale'", NULL);
#endif
  {
   self->setMaxScale(maxScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMaxScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaxScale of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getMaxScale00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getMaxScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMaxScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMinScale of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setMinScale00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setMinScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
  float minScale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMinScale'", NULL);
#endif
  {
   self->setMinScale(minScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMinScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMinScale of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getMinScale00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getMinScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMinScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getMinScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMinScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPanBoundsRect of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setPanBoundsRect00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setPanBoundsRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
  const CCRect* rect = ((const CCRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPanBoundsRect'", NULL);
#endif
  {
   self->setPanBoundsRect(*rect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPanBoundsRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPanBoundRect of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getPanBoundRect00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getPanBoundRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPanBoundRect'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->getPanBoundRect();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPanBoundRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScale00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(scale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setPosition00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* position = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(*position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleX of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScaleX00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScaleX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
  float fScaleX = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleX'", NULL);
#endif
  {
   self->setScaleX(fScaleX);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScaleY of class  CCLayerPanZoom */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScaleY00
static int tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScaleY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCLayerPanZoom",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCLayerPanZoom* self = (CCLayerPanZoom*)  tolua_tousertype(tolua_S,1,0);
  float fScaleY = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScaleY'", NULL);
#endif
  {
   self->setScaleY(fScaleY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScaleY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  RandomOwn */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_RandomOwn_getInstance00
static int tolua_cocos2dx_extra_luabinding_RandomOwn_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RandomOwn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  long long seed = ((long long)  tolua_tonumber(tolua_S,2,0));
  {
   RandomOwn* tolua_ret = (RandomOwn*)  RandomOwn::getInstance(seed);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RandomOwn");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nextInt of class  RandomOwn */
#ifndef TOLUA_DISABLE_tolua_cocos2dx_extra_luabinding_RandomOwn_nextInt00
static int tolua_cocos2dx_extra_luabinding_RandomOwn_nextInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RandomOwn",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RandomOwn* self = (RandomOwn*)  tolua_tousertype(tolua_S,1,0);
  int n = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nextInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->nextInt(n);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nextInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_cocos2dx_extra_luabinding_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"CCCrypto","CCCrypto","",NULL);
  tolua_beginmodule(tolua_S,"CCCrypto");
   tolua_function(tolua_S,"getAES256KeyLength",tolua_cocos2dx_extra_luabinding_CCCrypto_getAES256KeyLength00);
   tolua_function(tolua_S,"encryptAES256",tolua_cocos2dx_extra_luabinding_CCCrypto_encryptAES25600);
   tolua_function(tolua_S,"decryptAES256",tolua_cocos2dx_extra_luabinding_CCCrypto_decryptAES25600);
   tolua_function(tolua_S,"encryptXXTEA",tolua_cocos2dx_extra_luabinding_CCCrypto_encryptXXTEA00);
   tolua_function(tolua_S,"decryptXXTEA",tolua_cocos2dx_extra_luabinding_CCCrypto_decryptXXTEA00);
   tolua_function(tolua_S,"encodeBase64",tolua_cocos2dx_extra_luabinding_CCCrypto_encodeBase6400);
   tolua_function(tolua_S,"decodeBase64",tolua_cocos2dx_extra_luabinding_CCCrypto_decodeBase6400);
   tolua_function(tolua_S,"MD5",tolua_cocos2dx_extra_luabinding_CCCrypto_MD500);
   tolua_function(tolua_S,"MD5File",tolua_cocos2dx_extra_luabinding_CCCrypto_MD5File00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCNative","CCNative","",NULL);
  tolua_beginmodule(tolua_S,"CCNative");
   tolua_function(tolua_S,"showActivityIndicator",tolua_cocos2dx_extra_luabinding_CCNative_showActivityIndicator00);
   tolua_function(tolua_S,"hideActivityIndicator",tolua_cocos2dx_extra_luabinding_CCNative_hideActivityIndicator00);
   tolua_function(tolua_S,"createAlert",tolua_cocos2dx_extra_luabinding_CCNative_createAlert00);
   tolua_function(tolua_S,"addAlertButton",tolua_cocos2dx_extra_luabinding_CCNative_addAlertButton00);
   tolua_function(tolua_S,"showAlert",tolua_cocos2dx_extra_luabinding_CCNative_showAlert00);
   tolua_function(tolua_S,"cancelAlert",tolua_cocos2dx_extra_luabinding_CCNative_cancelAlert00);
   tolua_function(tolua_S,"getOpenUDID",tolua_cocos2dx_extra_luabinding_CCNative_getOpenUDID00);
   tolua_function(tolua_S,"openURL",tolua_cocos2dx_extra_luabinding_CCNative_openURL00);
   tolua_function(tolua_S,"getInputText",tolua_cocos2dx_extra_luabinding_CCNative_getInputText00);
   tolua_function(tolua_S,"getDeviceName",tolua_cocos2dx_extra_luabinding_CCNative_getDeviceName00);
   tolua_function(tolua_S,"vibrate",tolua_cocos2dx_extra_luabinding_CCNative_vibrate00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"kCCHTTPRequestMethodGET",kCCHTTPRequestMethodGET);
  tolua_constant(tolua_S,"kCCHTTPRequestMethodPOST",kCCHTTPRequestMethodPOST);
  tolua_constant(tolua_S,"kCCHTTPRequestAcceptEncodingIdentity",kCCHTTPRequestAcceptEncodingIdentity);
  tolua_constant(tolua_S,"kCCHTTPRequestAcceptEncodingGzip",kCCHTTPRequestAcceptEncodingGzip);
  tolua_constant(tolua_S,"kCCHTTPRequestAcceptEncodingDeflate",kCCHTTPRequestAcceptEncodingDeflate);
  tolua_constant(tolua_S,"kCCHTTPRequestStateIdle",kCCHTTPRequestStateIdle);
  tolua_constant(tolua_S,"kCCHTTPRequestStateCleared",kCCHTTPRequestStateCleared);
  tolua_constant(tolua_S,"kCCHTTPRequestStateInProgress",kCCHTTPRequestStateInProgress);
  tolua_constant(tolua_S,"kCCHTTPRequestStateCompleted",kCCHTTPRequestStateCompleted);
  tolua_constant(tolua_S,"kCCHTTPRequestStateCancelled",kCCHTTPRequestStateCancelled);
  tolua_constant(tolua_S,"kCCHTTPRequestStateFailed",kCCHTTPRequestStateFailed);
  tolua_cclass(tolua_S,"CCHTTPRequest","CCHTTPRequest","CCObject",NULL);
  tolua_beginmodule(tolua_S,"CCHTTPRequest");
   tolua_function(tolua_S,"createWithUrl",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_createWithUrl00);
   tolua_function(tolua_S,"setRequestUrl",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setRequestUrl00);
   tolua_function(tolua_S,"getRequestUrl",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getRequestUrl00);
   tolua_function(tolua_S,"addRequestHeader",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addRequestHeader00);
   tolua_function(tolua_S,"addPOSTValue",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addPOSTValue00);
   tolua_function(tolua_S,"setPOSTData",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setPOSTData00);
   tolua_function(tolua_S,"addFormFile",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addFormFile00);
   tolua_function(tolua_S,"addFormContents",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_addFormContents00);
   tolua_function(tolua_S,"setCookieString",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setCookieString00);
   tolua_function(tolua_S,"getCookieString",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getCookieString00);
   tolua_function(tolua_S,"setAcceptEncoding",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setAcceptEncoding00);
   tolua_function(tolua_S,"setTimeout",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_setTimeout00);
   tolua_function(tolua_S,"start",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_start00);
   tolua_function(tolua_S,"cancel",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_cancel00);
   tolua_function(tolua_S,"getState",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getState00);
   tolua_function(tolua_S,"getResponseStatusCode",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseStatusCode00);
   tolua_function(tolua_S,"getResponseHeadersString",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseHeadersString00);
   tolua_function(tolua_S,"getResponseString",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseString00);
   tolua_function(tolua_S,"getResponseData",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseData00);
   tolua_function(tolua_S,"getResponseDataLength",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getResponseDataLength00);
   tolua_function(tolua_S,"saveResponseData",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_saveResponseData00);
   tolua_function(tolua_S,"getErrorCode",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getErrorCode00);
   tolua_function(tolua_S,"getErrorMessage",tolua_cocos2dx_extra_luabinding_CCHTTPRequest_getErrorMessage00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"kCCNetworkStatusNotReachable",kCCNetworkStatusNotReachable);
  tolua_constant(tolua_S,"kCCNetworkStatusReachableViaWiFi",kCCNetworkStatusReachableViaWiFi);
  tolua_constant(tolua_S,"kCCNetworkStatusReachableViaWWAN",kCCNetworkStatusReachableViaWWAN);
  tolua_cclass(tolua_S,"CCNetwork","CCNetwork","",NULL);
  tolua_beginmodule(tolua_S,"CCNetwork");
   tolua_function(tolua_S,"isLocalWiFiAvailable",tolua_cocos2dx_extra_luabinding_CCNetwork_isLocalWiFiAvailable00);
   tolua_function(tolua_S,"isInternetConnectionAvailable",tolua_cocos2dx_extra_luabinding_CCNetwork_isInternetConnectionAvailable00);
   tolua_function(tolua_S,"isHostNameReachable",tolua_cocos2dx_extra_luabinding_CCNetwork_isHostNameReachable00);
   tolua_function(tolua_S,"getInternetConnectionStatus",tolua_cocos2dx_extra_luabinding_CCNetwork_getInternetConnectionStatus00);
   tolua_function(tolua_S,"createHTTPRequest",tolua_cocos2dx_extra_luabinding_CCNetwork_createHTTPRequest00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MySocket","MySocket","",NULL);
  tolua_beginmodule(tolua_S,"MySocket");
   tolua_function(tolua_S,"getInstance",tolua_cocos2dx_extra_luabinding_MySocket_getInstance00);
   tolua_function(tolua_S,"init",tolua_cocos2dx_extra_luabinding_MySocket_init00);
   tolua_function(tolua_S,"StartRequest",tolua_cocos2dx_extra_luabinding_MySocket_StartRequest00);
   tolua_function(tolua_S,"closePThread",tolua_cocos2dx_extra_luabinding_MySocket_closePThread00);
   tolua_function(tolua_S,"destroy",tolua_cocos2dx_extra_luabinding_MySocket_destroy00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CData","CData","",NULL);
  tolua_beginmodule(tolua_S,"CData");
   tolua_variable(tolua_S,"dir",tolua_get_CData_dir,tolua_set_CData_dir);
   tolua_function(tolua_S,"getAmInstance",tolua_cocos2dx_extra_luabinding_CData_getAmInstance00);
   tolua_function(tolua_S,"enterLua",tolua_cocos2dx_extra_luabinding_CData_enterLua00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MySprite","MySprite","CCSprite",NULL);
  tolua_beginmodule(tolua_S,"MySprite");
   tolua_function(tolua_S,"createMS",tolua_cocos2dx_extra_luabinding_MySprite_createMS00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"DialogLayer","DialogLayer","CCLayerColor",NULL);
  tolua_beginmodule(tolua_S,"DialogLayer");
   tolua_variable(tolua_S,"m_pMenu",tolua_get_DialogLayer_m_pMenu_ptr,tolua_set_DialogLayer_m_pMenu_ptr);
   tolua_variable(tolua_S,"m_pMenu2",tolua_get_DialogLayer_m_pMenu2_ptr,tolua_set_DialogLayer_m_pMenu2_ptr);
   tolua_variable(tolua_S,"m_pLayer",tolua_get_DialogLayer_m_pLayer_ptr,tolua_set_DialogLayer_m_pLayer_ptr);
   tolua_variable(tolua_S,"m_pEditBox1",tolua_get_DialogLayer_m_pEditBox1_ptr,tolua_set_DialogLayer_m_pEditBox1_ptr);
   tolua_variable(tolua_S,"m_pEditBox2",tolua_get_DialogLayer_m_pEditBox2_ptr,tolua_set_DialogLayer_m_pEditBox2_ptr);
   tolua_variable(tolua_S,"m_pEditBox3",tolua_get_DialogLayer_m_pEditBox3_ptr,tolua_set_DialogLayer_m_pEditBox3_ptr);
   tolua_variable(tolua_S,"m_pEditBox4",tolua_get_DialogLayer_m_pEditBox4_ptr,tolua_set_DialogLayer_m_pEditBox4_ptr);
   tolua_variable(tolua_S,"m_pEditBox5",tolua_get_DialogLayer_m_pEditBox5_ptr,tolua_set_DialogLayer_m_pEditBox5_ptr);
   tolua_variable(tolua_S,"m_pTextField",tolua_get_DialogLayer_m_pTextField_ptr,tolua_set_DialogLayer_m_pTextField_ptr);
   tolua_variable(tolua_S,"m_tableview",tolua_get_DialogLayer_m_tableview_ptr,tolua_set_DialogLayer_m_tableview_ptr);
   tolua_variable(tolua_S,"m_tableview1",tolua_get_DialogLayer_m_tableview1_ptr,tolua_set_DialogLayer_m_tableview1_ptr);
   tolua_function(tolua_S,"disableTouch",tolua_cocos2dx_extra_luabinding_DialogLayer_disableTouch00);
   tolua_function(tolua_S,"eanbleTouch",tolua_cocos2dx_extra_luabinding_DialogLayer_eanbleTouch00);
   tolua_function(tolua_S,"registerScriptTouchHandler",tolua_cocos2dx_extra_luabinding_DialogLayer_registerScriptTouchHandler00);
   tolua_function(tolua_S,"unRegisterScriptTouchHandler",tolua_cocos2dx_extra_luabinding_DialogLayer_unRegisterScriptTouchHandler00);
   tolua_function(tolua_S,"enableTouch",tolua_cocos2dx_extra_luabinding_DialogLayer_enableTouch00);
   tolua_function(tolua_S,"create",tolua_cocos2dx_extra_luabinding_DialogLayer_create00);
   tolua_function(tolua_S,"create",tolua_cocos2dx_extra_luabinding_DialogLayer_create01);
   tolua_function(tolua_S,"create",tolua_cocos2dx_extra_luabinding_DialogLayer_create02);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MyLayer","MyLayer","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"MyLayer");
   tolua_function(tolua_S,"create",tolua_cocos2dx_extra_luabinding_MyLayer_create00);
   tolua_function(tolua_S,"getHeight",tolua_cocos2dx_extra_luabinding_MyLayer_getHeight00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FDPixelSprite","FDPixelSprite","CCSprite",NULL);
  tolua_beginmodule(tolua_S,"FDPixelSprite");
   tolua_function(tolua_S,"create",tolua_cocos2dx_extra_luabinding_FDPixelSprite_create00);
   tolua_variable(tolua_S,"__CCTargetedTouchDelegate__",tolua_get_FDPixelSprite___CCTargetedTouchDelegate__,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TableViewTestLayer","TableViewTestLayer","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"TableViewTestLayer");
   tolua_function(tolua_S,"create",tolua_cocos2dx_extra_luabinding_TableViewTestLayer_create00);
   tolua_function(tolua_S,"StarSpin",tolua_cocos2dx_extra_luabinding_TableViewTestLayer_StarSpin00);
   tolua_variable(tolua_S,"__MyTViewDataSource__",tolua_get_TableViewTestLayer___MyTViewDataSource__,NULL);
   tolua_variable(tolua_S,"__MyTViewDelegate__",tolua_get_TableViewTestLayer___MyTViewDelegate__,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"NetManager","NetManager","",NULL);
  tolua_beginmodule(tolua_S,"NetManager");
   tolua_function(tolua_S,"getInstance",tolua_cocos2dx_extra_luabinding_NetManager_getInstance00);
   tolua_function(tolua_S,"ContectLong",tolua_cocos2dx_extra_luabinding_NetManager_ContectLong00);
   tolua_function(tolua_S,"RecvData",tolua_cocos2dx_extra_luabinding_NetManager_RecvData00);
   tolua_function(tolua_S,"SendData",tolua_cocos2dx_extra_luabinding_NetManager_SendData00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MsgManager","MsgManager","",NULL);
  tolua_beginmodule(tolua_S,"MsgManager");
   tolua_function(tolua_S,"getInstance",tolua_cocos2dx_extra_luabinding_MsgManager_getInstance00);
   tolua_variable(tolua_S,"msgnum",tolua_get_MsgManager_msgnum,tolua_set_MsgManager_msgnum);
   tolua_variable(tolua_S,"recvbuffer",tolua_get_MsgManager_unsigned_recvbuffer,tolua_set_MsgManager_unsigned_recvbuffer);
   tolua_variable(tolua_S,"sendbuffer",tolua_get_MsgManager_unsigned_sendbuffer,tolua_set_MsgManager_unsigned_sendbuffer);
   tolua_function(tolua_S,"cleanBuffer",tolua_cocos2dx_extra_luabinding_MsgManager_cleanBuffer00);
   tolua_function(tolua_S,"setHeadMsgId",tolua_cocos2dx_extra_luabinding_MsgManager_setHeadMsgId00);
   tolua_function(tolua_S,"setHeadMsgKind",tolua_cocos2dx_extra_luabinding_MsgManager_setHeadMsgKind00);
   tolua_function(tolua_S,"writeBodyShort",tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyShort00);
   tolua_function(tolua_S,"writeBodyByte",tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyByte00);
   tolua_function(tolua_S,"writeBodyInt",tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyInt00);
   tolua_function(tolua_S,"writeBodyString",tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyString00);
   tolua_function(tolua_S,"getsendMsg",tolua_cocos2dx_extra_luabinding_MsgManager_getsendMsg00);
   tolua_function(tolua_S,"writeBodyLong",tolua_cocos2dx_extra_luabinding_MsgManager_writeBodyLong00);
   tolua_function(tolua_S,"readBodyLong",tolua_cocos2dx_extra_luabinding_MsgManager_readBodyLong00);
   tolua_function(tolua_S,"getMsgId",tolua_cocos2dx_extra_luabinding_MsgManager_getMsgId00);
   tolua_function(tolua_S,"getBodyLen",tolua_cocos2dx_extra_luabinding_MsgManager_getBodyLen00);
   tolua_function(tolua_S,"getResult",tolua_cocos2dx_extra_luabinding_MsgManager_getResult00);
   tolua_function(tolua_S,"readBodyShort",tolua_cocos2dx_extra_luabinding_MsgManager_readBodyShort00);
   tolua_function(tolua_S,"readBodyByte",tolua_cocos2dx_extra_luabinding_MsgManager_readBodyByte00);
   tolua_function(tolua_S,"readBodyInt",tolua_cocos2dx_extra_luabinding_MsgManager_readBodyInt00);
   tolua_function(tolua_S,"readBodyString",tolua_cocos2dx_extra_luabinding_MsgManager_readBodyString00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"SliderLayer","SliderLayer","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"SliderLayer");
   tolua_function(tolua_S,"create",tolua_cocos2dx_extra_luabinding_SliderLayer_create00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCSkeletonAnimation","CCSkeletonAnimation","CCSkeleton",tolua_collect_CCSkeletonAnimation);
  #else
  tolua_cclass(tolua_S,"CCSkeletonAnimation","CCSkeletonAnimation","CCSkeleton",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCSkeletonAnimation");
   tolua_variable(tolua_S,"state",tolua_get_CCSkeletonAnimation_state_ptr,tolua_set_CCSkeletonAnimation_state_ptr);
   tolua_function(tolua_S,"createSpineSkin",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createSpineSkin00);
   tolua_function(tolua_S,"releaseSpineSkin",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_releaseSpineSkin00);
   tolua_function(tolua_S,"addSpineSkin",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_addSpineSkin00);
   tolua_function(tolua_S,"createWithFile",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile00);
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new00_local);
   tolua_variable(tolua_S,"m_nScriptAnimationHandler",tolua_get_CCSkeletonAnimation_m_nScriptAnimationHandler,tolua_set_CCSkeletonAnimation_m_nScriptAnimationHandler);
   tolua_variable(tolua_S,"listenAnimName",tolua_get_CCSkeletonAnimation_listenAnimName,tolua_set_CCSkeletonAnimation_listenAnimName);
   tolua_function(tolua_S,"registerAnimationStatusListener",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_registerAnimationStatusListener00);
   tolua_function(tolua_S,"unRegisterAnimationStatusListener",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_unRegisterAnimationStatusListener00);
   tolua_function(tolua_S,"getAnimationDuration",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_getAnimationDuration00);
   tolua_function(tolua_S,"createWithData",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithData00);
   tolua_function(tolua_S,"createWithFile",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile01);
   tolua_function(tolua_S,"createWithFile",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_createWithFile02);
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new01_local);
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new02_local);
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new03);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new03_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_new03_local);
   tolua_function(tolua_S,"delete",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_delete00);
   tolua_function(tolua_S,"update",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_update00);
   tolua_function(tolua_S,"setAnimationStateData",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimationStateData00);
   tolua_function(tolua_S,"setMix",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setMix00);
   tolua_function(tolua_S,"setAnimationListener",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimationListener00);
   tolua_function(tolua_S,"setAnimation",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_setAnimation00);
   tolua_function(tolua_S,"addAnimation",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_addAnimation00);
   tolua_function(tolua_S,"getCurrent",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_getCurrent00);
   tolua_function(tolua_S,"clearTracks",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_clearTracks00);
   tolua_function(tolua_S,"clearTrack",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_clearTrack00);
   tolua_function(tolua_S,"onAnimationStateEvent",tolua_cocos2dx_extra_luabinding_CCSkeletonAnimation_onAnimationStateEvent00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCSkeleton","CCSkeleton","CCNode",tolua_collect_CCSkeleton);
  #else
  tolua_cclass(tolua_S,"CCSkeleton","CCSkeleton","CCNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCSkeleton");
   tolua_variable(tolua_S,"skeleton",tolua_get_CCSkeleton_skeleton_ptr,tolua_set_CCSkeleton_skeleton_ptr);
   tolua_variable(tolua_S,"rootBone",tolua_get_CCSkeleton_rootBone_ptr,tolua_set_CCSkeleton_rootBone_ptr);
   tolua_variable(tolua_S,"timeScale",tolua_get_CCSkeleton_timeScale,tolua_set_CCSkeleton_timeScale);
   tolua_variable(tolua_S,"debugSlots",tolua_get_CCSkeleton_debugSlots,tolua_set_CCSkeleton_debugSlots);
   tolua_variable(tolua_S,"debugBones",tolua_get_CCSkeleton_debugBones,tolua_set_CCSkeleton_debugBones);
   tolua_variable(tolua_S,"premultipliedAlpha",tolua_get_CCSkeleton_premultipliedAlpha,tolua_set_CCSkeleton_premultipliedAlpha);
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_CCSkeleton_new00);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_CCSkeleton_new00_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_CCSkeleton_new00_local);
   tolua_variable(tolua_S,"myColor",tolua_get_CCSkeleton_myColor,tolua_set_CCSkeleton_myColor);
   tolua_variable(tolua_S,"isAdditive",tolua_get_CCSkeleton_isAdditive,tolua_set_CCSkeleton_isAdditive);
   tolua_function(tolua_S,"setColorAndAdditive",tolua_cocos2dx_extra_luabinding_CCSkeleton_setColorAndAdditive00);
   tolua_function(tolua_S,"restoreColorAndAdditive",tolua_cocos2dx_extra_luabinding_CCSkeleton_restoreColorAndAdditive00);
   tolua_function(tolua_S,"getAttachmentHeight",tolua_cocos2dx_extra_luabinding_CCSkeleton_getAttachmentHeight00);
   tolua_function(tolua_S,"createWithData",tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithData00);
   tolua_function(tolua_S,"createWithFile",tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithFile00);
   tolua_function(tolua_S,"createWithFile",tolua_cocos2dx_extra_luabinding_CCSkeleton_createWithFile01);
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_CCSkeleton_new01);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_CCSkeleton_new01_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_CCSkeleton_new01_local);
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_CCSkeleton_new02);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_CCSkeleton_new02_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_CCSkeleton_new02_local);
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_CCSkeleton_new03);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_CCSkeleton_new03_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_CCSkeleton_new03_local);
   tolua_function(tolua_S,"delete",tolua_cocos2dx_extra_luabinding_CCSkeleton_delete00);
   tolua_function(tolua_S,"update",tolua_cocos2dx_extra_luabinding_CCSkeleton_update00);
   tolua_function(tolua_S,"draw",tolua_cocos2dx_extra_luabinding_CCSkeleton_draw00);
   tolua_function(tolua_S,"boundingBox",tolua_cocos2dx_extra_luabinding_CCSkeleton_boundingBox00);
   tolua_function(tolua_S,"updateWorldTransform",tolua_cocos2dx_extra_luabinding_CCSkeleton_updateWorldTransform00);
   tolua_function(tolua_S,"setToSetupPose",tolua_cocos2dx_extra_luabinding_CCSkeleton_setToSetupPose00);
   tolua_function(tolua_S,"setBonesToSetupPose",tolua_cocos2dx_extra_luabinding_CCSkeleton_setBonesToSetupPose00);
   tolua_function(tolua_S,"setSlotsToSetupPose",tolua_cocos2dx_extra_luabinding_CCSkeleton_setSlotsToSetupPose00);
   tolua_function(tolua_S,"findBone",tolua_cocos2dx_extra_luabinding_CCSkeleton_findBone00);
   tolua_function(tolua_S,"findSlot",tolua_cocos2dx_extra_luabinding_CCSkeleton_findSlot00);
   tolua_function(tolua_S,"setSkin",tolua_cocos2dx_extra_luabinding_CCSkeleton_setSkin00);
   tolua_function(tolua_S,"getAttachment",tolua_cocos2dx_extra_luabinding_CCSkeleton_getAttachment00);
   tolua_function(tolua_S,"setAttachment",tolua_cocos2dx_extra_luabinding_CCSkeleton_setAttachment00);
   tolua_variable(tolua_S,"__CCBlendProtocol__",tolua_get_CCSkeleton___CCBlendProtocol__,NULL);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"EXZoomController","EXZoomController","CCLayer",tolua_collect_EXZoomController);
  #else
  tolua_cclass(tolua_S,"EXZoomController","EXZoomController","CCLayer",NULL);
  #endif
  tolua_beginmodule(tolua_S,"EXZoomController");
   tolua_function(tolua_S,"new",tolua_cocos2dx_extra_luabinding_EXZoomController_new00);
   tolua_function(tolua_S,"new_local",tolua_cocos2dx_extra_luabinding_EXZoomController_new00_local);
   tolua_function(tolua_S,".call",tolua_cocos2dx_extra_luabinding_EXZoomController_new00_local);
   tolua_function(tolua_S,"delete",tolua_cocos2dx_extra_luabinding_EXZoomController_delete00);
   tolua_function(tolua_S,"controllerWithNode",tolua_cocos2dx_extra_luabinding_EXZoomController_controllerWithNode00);
   tolua_function(tolua_S,"initWithNode",tolua_cocos2dx_extra_luabinding_EXZoomController_initWithNode00);
   tolua_variable(tolua_S,"centerOnPinch",tolua_get_EXZoomController_centerOnPinch,tolua_set_EXZoomController_centerOnPinch);
   tolua_variable(tolua_S,"zoomOnDoubleTap",tolua_get_EXZoomController_zoomOnDoubleTap,tolua_set_EXZoomController_zoomOnDoubleTap);
   tolua_variable(tolua_S,"zoomRate",tolua_get_EXZoomController_zoomRate,tolua_set_EXZoomController_zoomRate);
   tolua_variable(tolua_S,"zoomInLimit",tolua_get_EXZoomController_zoomInLimit,tolua_set_EXZoomController_zoomInLimit);
   tolua_variable(tolua_S,"zoomOutLimit",tolua_get_EXZoomController_zoomOutLimit,tolua_set_EXZoomController_zoomOutLimit);
   tolua_variable(tolua_S,"swipeVelocityMultiplier",tolua_get_EXZoomController_swipeVelocityMultiplier,tolua_set_EXZoomController_swipeVelocityMultiplier);
   tolua_variable(tolua_S,"scrollDuration",tolua_get_EXZoomController_scrollDuration,tolua_set_EXZoomController_scrollDuration);
   tolua_variable(tolua_S,"scrollDamping",tolua_get_EXZoomController_scrollDamping,tolua_set_EXZoomController_scrollDamping);
   tolua_variable(tolua_S,"pinchDamping",tolua_get_EXZoomController_pinchDamping,tolua_set_EXZoomController_pinchDamping);
   tolua_variable(tolua_S,"pinchDistanceThreshold",tolua_get_EXZoomController_pinchDistanceThreshold,tolua_set_EXZoomController_pinchDistanceThreshold);
   tolua_variable(tolua_S,"doubleTapZoomDuration",tolua_get_EXZoomController_doubleTapZoomDuration,tolua_set_EXZoomController_doubleTapZoomDuration);
   tolua_variable(tolua_S,"multitouchnum",tolua_get_EXZoomController_multitouchnum,tolua_set_EXZoomController_multitouchnum);
   tolua_function(tolua_S,"setBoundingRect",tolua_cocos2dx_extra_luabinding_EXZoomController_setBoundingRect00);
   tolua_function(tolua_S,"getBoundingRect",tolua_cocos2dx_extra_luabinding_EXZoomController_getBoundingRect00);
   tolua_function(tolua_S,"setWindowRect",tolua_cocos2dx_extra_luabinding_EXZoomController_setWindowRect00);
   tolua_function(tolua_S,"getWindowRect",tolua_cocos2dx_extra_luabinding_EXZoomController_getWindowRect00);
   tolua_function(tolua_S,"getOptimalZoomOutLimit",tolua_cocos2dx_extra_luabinding_EXZoomController_getOptimalZoomOutLimit00);
   tolua_function(tolua_S,"updatePosition",tolua_cocos2dx_extra_luabinding_EXZoomController_updatePosition00);
   tolua_function(tolua_S,"centerOnPoint",tolua_cocos2dx_extra_luabinding_EXZoomController_centerOnPoint00);
   tolua_function(tolua_S,"centerOnPoint",tolua_cocos2dx_extra_luabinding_EXZoomController_centerOnPoint01);
   tolua_function(tolua_S,"zoomInOnPoint",tolua_cocos2dx_extra_luabinding_EXZoomController_zoomInOnPoint00);
   tolua_function(tolua_S,"zoomOutOnPoint",tolua_cocos2dx_extra_luabinding_EXZoomController_zoomOutOnPoint00);
   tolua_function(tolua_S,"zoomOnPoint",tolua_cocos2dx_extra_luabinding_EXZoomController_zoomOnPoint00);
   tolua_function(tolua_S,"enableWithTouchPriority",tolua_cocos2dx_extra_luabinding_EXZoomController_enableWithTouchPriority00);
   tolua_function(tolua_S,"disable",tolua_cocos2dx_extra_luabinding_EXZoomController_disable00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCLayerPanZoom","CCLayerPanZoom","CCNode",tolua_collect_CCLayerPanZoom);
  #else
  tolua_cclass(tolua_S,"CCLayerPanZoom","CCLayerPanZoom","CCNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCLayerPanZoom");
   tolua_function(tolua_S,"layer",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_layer00);
   tolua_function(tolua_S,"delete",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_delete00);
   tolua_function(tolua_S,"isPanLayerMoved",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_isPanLayerMoved00);
   tolua_function(tolua_S,"init",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_init00);
   tolua_function(tolua_S,"update",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_update00);
   tolua_function(tolua_S,"onEnter",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_onEnter00);
   tolua_function(tolua_S,"onExit",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_onExit00);
   tolua_function(tolua_S,"enablePanZoom",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_enablePanZoom00);
   tolua_function(tolua_S,"disablePanZoom",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_disablePanZoom00);
   tolua_function(tolua_S,"setMaxScale",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setMaxScale00);
   tolua_function(tolua_S,"getMaxScale",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getMaxScale00);
   tolua_function(tolua_S,"setMinScale",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setMinScale00);
   tolua_function(tolua_S,"getMinScale",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getMinScale00);
   tolua_function(tolua_S,"setPanBoundsRect",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setPanBoundsRect00);
   tolua_function(tolua_S,"getPanBoundRect",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_getPanBoundRect00);
   tolua_function(tolua_S,"setScale",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScale00);
   tolua_function(tolua_S,"setPosition",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setPosition00);
   tolua_function(tolua_S,"setScaleX",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScaleX00);
   tolua_function(tolua_S,"setScaleY",tolua_cocos2dx_extra_luabinding_CCLayerPanZoom_setScaleY00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"RandomOwn","RandomOwn","",NULL);
  tolua_beginmodule(tolua_S,"RandomOwn");
   tolua_function(tolua_S,"getInstance",tolua_cocos2dx_extra_luabinding_RandomOwn_getInstance00);
   tolua_function(tolua_S,"nextInt",tolua_cocos2dx_extra_luabinding_RandomOwn_nextInt00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_cocos2dx_extra_luabinding (lua_State* tolua_S) {
 return tolua_cocos2dx_extra_luabinding_open(tolua_S);
};
#endif

