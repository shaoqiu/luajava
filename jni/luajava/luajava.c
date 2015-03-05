#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_newstate
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1newstate
  (JNIEnv *env, jobject object)
{
    return (long)luaL_newstate();
}
/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_openlibs
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1openlibs
  (JNIEnv *env, jobject object, jlong ptr)
{
   luaL_openlibs((lua_State*)ptr);
}
/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_dofile
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1dofile
  (JNIEnv *env, jobject object, jlong ptr, jstring fname)
{
    const char *name = (*env)->GetStringUTFChars(env, fname, NULL);
    int ret = luaL_dofile((lua_State*)ptr, name);
    (*env)->ReleaseStringUTFChars(env, fname, name);
    return (jint)ret;
}
