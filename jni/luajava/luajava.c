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

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _get_global_integer
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1get_1global_1integer
  (JNIEnv *env, jobject object, jlong ptr, jstring config)
{
    const char *name = (*env)->GetStringUTFChars(env, config, NULL);
    lua_getglobal((lua_State*)ptr, name);
    int ret = lua_tointeger((lua_State*)ptr, -1);
    (*env)->ReleaseStringUTFChars(env, config, name);
    return (jint)ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _get_global_string
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1get_1global_1string
  (JNIEnv *env, jobject object, jlong ptr, jstring config)
{
    const char *name = (*env)->GetStringUTFChars(env, config, NULL);
    lua_getglobal((lua_State*)ptr, name);
    const char *ret = lua_tostring((lua_State*)ptr, -1);
    (*env)->ReleaseStringUTFChars(env, config, name);
    return (*env)->NewStringUTF(env, ret);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_absindex
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1absindex
  (JNIEnv *env, jobject obj, jlong ptr, jint idx)
{
    return lua_absindex((lua_State*)ptr, idx);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_arith
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1arith
  (JNIEnv *env, jobject obj, jlong ptr, jint op)
{
    lua_arith((lua_State*)ptr, op);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_call
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1call
  (JNIEnv *env, jobject obj, jlong ptr, jint nargs, jint nresults)
{
    lua_call((lua_State*)ptr, nargs, nresults);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_checkstack
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1checkstack
  (JNIEnv *env, jobject obj, jlong ptr, jint n)
{
    return lua_checkstack((lua_State*)ptr, n);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_close
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1close
  (JNIEnv *env, jobject obj, jlong ptr)
{
    lua_close((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_compare
 * Signature: (JIII)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1compare
  (JNIEnv *env, jobject obj, jlong ptr, jint index1, jint index2, jint op)
{
    return lua_compare((lua_State*)ptr, index1, index2, op);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_concat
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1concat
  (JNIEnv *env, jobject obj, jlong ptr, jint n)
{
    lua_concat((lua_State*)ptr, n);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_copy
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1copy
  (JNIEnv *env, jobject obj, jlong ptr, jint fromidx, jint toidx)
{
    lua_copy((lua_State*)ptr, fromidx, toidx);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_createtable
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1createtable
  (JNIEnv *env, jobject obj, jlong ptr, jint narr, jint nrec)
{
    lua_createtable((lua_State*)ptr, narr, nrec);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_error
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1error
  (JNIEnv *env, jobject obj, jlong ptr)
{
    lua_error((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_gc
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1gc
  (JNIEnv *env, jobject obj, jlong ptr, jint what, jint data)
{
    return lua_gc((lua_State*)ptr, what, data);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_getfield
 * Signature: (JILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1getfield
  (JNIEnv *env, jobject obj, jlong ptr, jint index, jstring key)
{
    const char *name = (*env)->GetStringUTFChars(env, key, NULL);
    int ret = lua_getfield((lua_State*)ptr, index, name);
    (*env)->ReleaseStringUTFChars(env, key, name);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_getglobal
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1getglobal
  (JNIEnv *env, jobject obj, jlong ptr, jstring key)
{
    const char *name = (*env)->GetStringUTFChars(env, key, NULL);
    int ret = lua_getglobal((lua_State*)ptr, name);
    (*env)->ReleaseStringUTFChars(env, key, name);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_getmetatable
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1getmetatable
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_getmetatable((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_gettable
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1gettable
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_gettable((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_gettop
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1gettop
  (JNIEnv *env, jobject obj, jlong ptr)
{
    return lua_gettop((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_getupvalue
 * Signature: (JII)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1getupvalue
  (JNIEnv *env, jobject obj, jlong ptr, jint, jint);

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_getuservalue
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1getuservalue
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_getuservalue((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_insert
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1insert
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_insert((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isboolean
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isboolean
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isboolean((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_iscfunction
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1iscfunction
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_iscfunction((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isfunction
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isfunction
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isfunction((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isinteger
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isinteger
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isinteger((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_islightuserdata
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1islightuserdata
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_islightuserdata((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isnil
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isnil
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isnil((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isnone
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isnone
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isnone((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isnoneornil
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isnoneornil
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isnoneornil((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isnumber
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isnumber
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isnumber((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isstring
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isstring
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isstring((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_istable
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1istable
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_istable((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isthread
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isthread
  (JNIEnv *evn, jobject obj, jlong ptr, jint index)
{
    return lua_isthread((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isuserdata
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isuserdata
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_isuserdata((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_isyieldable
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1isyieldable
  (JNIEnv *env, jobject obj, jlong ptr)
{
    return lua_isyieldable((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_len
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1len
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_len((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_newtable
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1newtable
  (JNIEnv *env, jobject obj, jlong ptr)
{
    lua_newtable((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_next
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1next
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_next((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pcall
 * Signature: (JIII)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pcall
  (JNIEnv *env, jobject obj, jlong ptr, jint nargs, jint nresults, jint msgh)
{
    return lua_pcall((lua_State*)ptr, nargs, nresults, msgh);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pop
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pop
  (JNIEnv *env, jobject obj, jlong ptr, jint n)
{
    lua_pop((lua_State*)ptr, n);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushboolean
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushboolean
  (JNIEnv *env, jobject obj, jlong ptr, jint b)
{
    lua_pushboolean((lua_State*)ptr, b);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushstring
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushstring
  (JNIEnv *env, jobject obj, jlong ptr, jstring str)
{
    const char *cstr = (*env)->GetStringUTFChars(env, str, NULL);
    const char *ret = lua_pushstring((lua_State*)ptr, cstr);
    (*env)->ReleaseStringUTFChars(env, str, cstr);
    return (*env)->NewStringUTF(env, ret);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushglobaltable
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushglobaltable
  (JNIEnv *env, jobject obj, jlong ptr)
{
    lua_pushglobaltable((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushinteger
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushinteger
  (JNIEnv *env, jobject obj, jlong ptr, jlong n)
{
    lua_pushinteger((lua_State*)ptr, n);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushliteral
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushliteral
  (JNIEnv *env, jobject obj, jlong ptr, jstring str)
{
    const char *cstr = (*env)->GetStringUTFChars(env, str, NULL);
    const char *ret = lua_pushliteral((lua_State*)ptr, cstr);
    (*env)->ReleaseStringUTFChars(env, str, cstr);
    return (*env)->NewStringUTF(env, ret);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushlstring
 * Signature: (JLjava/lang/String;J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushlstring
  (JNIEnv *env, jobject obj, jlong ptr, jstring str, jlong sz)
{
    const char *cstr = (*env)->GetStringUTFChars(env, str, NULL);
    const char *ret = lua_pushlstring((lua_State*)ptr, cstr, sz);
    (*env)->ReleaseStringUTFChars(env, str, cstr);
    return (*env)->NewStringUTF(env, ret);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushnil
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushnil
  (JNIEnv *env, jobject obj, jlong ptr)
{
    lua_pushnil((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushfloat
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushfloat
  (JNIEnv *env, jobject obj, jlong ptr, jfloat f)
{
    lua_pushnumber((lua_State*)ptr, f);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushthread
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushthread
  (JNIEnv *env, jobject obj, jlong ptr)
{
    return lua_pushthread((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_pushvalue
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1pushvalue
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_pushvalue((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_rawequal
 * Signature: (JII)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1rawequal
  (JNIEnv *env, jobject obj, jlong ptr, jint index1, jint index2)
{
    return lua_rawequal((lua_State*)ptr, index1, index2);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_rawget
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1rawget
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_rawget((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_rawlen
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1rawlen
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_rawlen((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_rawset
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1rawset
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_rawset((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_remove
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1remove
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_remove((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_replace
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1replace
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_replace((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_resume
 * Signature: (JJI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1resume
  (JNIEnv *env, jobject obj, jlong ptr, jlong from, jint nargs)
{
    return lua_resume((lua_State*)ptr, from, nargs);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_rotate
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1rotate
  (JNIEnv *env, jobject obj, jlong ptr, jint index, jint n)
{
    lua_rotate((lua_State*)ptr, index, n);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_setfield
 * Signature: (JILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1setfield
  (JNIEnv *env, jobject obj, jlong ptr, jint index, jstring key)
{
    const char *name = (*env)->GetStringUTFChars(env, key, NULL);
    lua_setfield((lua_State*)ptr, index, name);
    (*env)->ReleaseStringUTFChars(env, key, name);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_setglobal
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1setglobal
  (JNIEnv *env, jobject obj, jlong ptr, jstring key)
{
    const char *name = (*env)->GetStringUTFChars(env, key, NULL);
    lua_setglobal((lua_State*)ptr, name);
    (*env)->ReleaseStringUTFChars(env, key, name);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_setmetatable
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1setmetatable
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_setmetatable((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_settable
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1settable
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_settable((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_settop
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1settop
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_settop((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_setuservalue
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1setuservalue
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    lua_setuservalue((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_staus
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1staus
  (JNIEnv *env, jobject obj, jlong ptr)
{
    return lua_status((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_stringtonumber
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1stringtonumber
  (JNIEnv *env, jobject obj, jlong ptr, jstring str)
{
    const char *cstr = (*env)->GetStringUTFChars(env, str, NULL);
    long ret = lua_stringtonumber((lua_State*)ptr, cstr);
    (*env)->ReleaseStringUTFChars(env, str, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_toboolean
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1toboolean
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_toboolean((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_tointeger
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1tointeger
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_tointeger((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_todouble
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1todouble
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_tonumber((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_topointer
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1topointer
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_topointer((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_tostring
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1tostring
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    const char *ret = lua_tostring((lua_State*)ptr, index);
    return (*env)->NewStringUTF(env, ret);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_type
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1type
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return lua_type((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_typename
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1typename
  (JNIEnv *env, jobject obj, jlong ptr, jint type)
{
    const char *ret = lua_typename((lua_State*)ptr, type);
    return (*env)->NewStringUTF(env, ret);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_xmove
 * Signature: (JJI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1xmove
  (JNIEnv *env, jobject obj, jlong ptr, jlong toptr, jint n)
{
    lua_xmove((lua_State*)ptr, (lua_State*)toptr, n);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _lua_yield
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1lua_1yield
  (JNIEnv *env, jobject obj, jlong ptr, jint nresults)
{
    return lua_yield((lua_State*)ptr, nresults);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_argcheck
 * Signature: (JIILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1argcheck
  (JNIEnv *env, jobject obj, jlong ptr, jint cond, jint arg, jstring extramsg)
{
    const char *cmsg = (*env)->GetStringUTFChars(env, extramsg, NULL);
    luaL_argcheck((lua_State*)ptr, cond, arg, cmsg);
    (*env)->ReleaseStringUTFChars(env, extramsg, cmsg);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_argerror
 * Signature: (JILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1argerror
  (JNIEnv *env, jobject obj, jlong ptr, jint arg, jstring extramsg)
{
    const char *cmsg = (*env)->GetStringUTFChars(env, extramsg, NULL);
    int ret = luaL_argerror((lua_State*)ptr, arg, cmsg);
    (*env)->ReleaseStringUTFChars(env, extramsg, cmsg);
    return ret; 
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_callmeta
 * Signature: (JILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1callmeta
  (JNIEnv *env, jobject obj, jlong ptr, jint obj, jstring e)
{
    const char * element = (*env)->GetStringUTFChars(env, e, NULL);
    int ret = luaL_callmeta((lua_State*)ptr, obj, element);
    (*env)->ReleaseStringUTFChars(env, e, element);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_checkany
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1checkany
  (JNIEnv *env, jobject obj, jlong ptr, jint arg)
{
    luaL_checkany((lua_State*)ptr, arg);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_checkinteger
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1checkinteger
  (JNIEnv *env, jobject obj, jlong ptr, jint arg)
{
    return luaL_checkinteger((lua_State*)ptr, arg);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_checknumber
 * Signature: (JI)D
 */
JNIEXPORT jdouble JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1checknumber
  (JNIEnv *env, jobject obj, jlong ptr, jint arg)
{
    return luaL_checknumber((lua_State*)ptr, arg);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_checkstack
 * Signature: (JILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1checkstack
  (JNIEnv *env, jobject obj, jlong ptr, jint sz, jstring msg)
{
    const char *cmsg = (*env)->GetStringUTFChars(env, msg, NULL);
    luaL_checkstack((lua_State*)ptr, sz, cmsg);
    (*env)->ReleaseStringUTFChars(env, msg, cmsg);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_checkstring
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1checkstring
  (JNIEnv *env, jobject obj, jlong ptr, jint arg)
{
    const char *ret = luaL_checkstring((lua_State*)ptr, arg);
    return (*env)->NewStringUTF(env, ret);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_checktype
 * Signature: (JII)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1checktype
  (JNIEnv *env, jobject obj, jlong ptr, jint arg, jint type)
{
    luaL_checktype((lua_State*)ptr, arg, type);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_checkversion
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1checkversion
  (JNIEnv *env, jobject obj, jlong ptr)
{
    luaL_checkversion((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_dofile
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1dofile
  (JNIEnv *env, jobject obj, jlong ptr, jstring filename)
{
    const char *cstr = (*env)->GetStringUTFChars(env, filename, NULL);
    int ret = luaL_dofile((lua_State*)ptr, cstr);
    (*env)->ReleaseStringUTFChars(env, filename, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_dostring
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1dostring
  (JNIEnv *env, jobject obj, jlong ptr, jstring str)
{
    const char *cstr = (*env)->GetStringUTFChars(env, str, NULL);
    int ret = luaL_dostring((lua_State*)ptr, cstr);
    (*env)->ReleaseStringUTFChars(env, str, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_error
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1error
  (JNIEnv *env, jobject obj, jlong ptr, jstring str)
{
    const char *cstr = (*env)->GetStringUTFChars(env, str, NULL);
    int ret = luaL_error((lua_State*)ptr, cstr);
    (*env)->ReleaseStringUTFChars(env, str, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_execresult
 * Signature: (JI)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1execresult
  (JNIEnv *env, jobject obj, jlong ptr, jint stat)
{
    return luaL_execresult((lua_State*)ptr, stat);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_fileresult
 * Signature: (JILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1fileresult
  (JNIEnv *env, jobject obj, jlong ptr, jint stat, jstring fname)
{
    const char *cstr = (*env)->GetStringUTFChars(env, fname, NULL);
    int ret = luaL_fileresult((lua_State*)ptr, stat, cstr);
    (*env)->ReleaseStringUTFChars(env, fname, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_getmetafield
 * Signature: (JILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1getmetafield
  (JNIEnv *env, jobject obj, jlong ptr, jint obj, jstring e)
{
    const char *cstr = (*env)->GetStringUTFChars(env, e, NULL);
    int ret = luaL_getmetafield((lua_State*)ptr, obj, cstr);
    (*env)->ReleaseStringUTFChars(env, e, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_getmetatable
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1getmetatable
  (JNIEnv *env, jobject obj, jlong ptr, jstring tname)
{
    const char *cstr = (*env)->GetStringUTFChars(env, tname, NULL);
    int ret = luaL_getmetatable((lua_State*)ptr, cstr);
    (*env)->ReleaseStringUTFChars(env, tname, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_getsubtable
 * Signature: (JILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1getsubtable
  (JNIEnv *env, jobject obj, jlong ptr, jint index, jstring fname)
{
    const char *cstr = (*env)->GetStringUTFChars(env, fname, NULL);
    int ret = luaL_getsubtable((lua_State*)ptr, index, cstr);
    (*env)->ReleaseStringUTFChars(env, fname, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_gsub
 * Signature: (JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1gsub
  (JNIEnv *env, jobject obj, jlong ptr, jstring s, jstring p, jstring r)
{
    const char *cs = (*env)->GetStringUTFChars(env, s, NULL);
    const char *cp = (*env)->GetStringUTFChars(env, p, NULL);
    const char *cr = (*env)->GetStringUTFChars(env, r, NULL);
    const char *ret = luaL_gsub((lua_State*)ptr, cs, cp, cr);
    (*env)->ReleaseStringUTFChars(env, s, cs);
    (*env)->ReleaseStringUTFChars(env, p, cp);
    (*env)->ReleaseStringUTFChars(env, r, cr);
    return (*env)->NewStringUTF(env, ret);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_len
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1len
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    return luaL_len((lua_State*)ptr, index);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_loadbuffer
 * Signature: (JLjava/lang/String;JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1loadbuffer
  (JNIEnv *env, jobject obj, jlong ptr, jstring buff, jlong sz, jstring name)
{
    const char *cbuff = (*env)->GetStringUTFChars(env, buff, NULL);
    const char *cname = (*env)->GetStringUTFChars(env, name, NULL);
    int ret = luaL_loadbuffer((lua_State*)ptr, cbuff, sz, cname);
    (*env)->ReleaseStringUTFChars(env, buff, cbuff);
    (*env)->ReleaseStringUTFChars(env, name, cname);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_loadbufferx
 * Signature: (JLjava/lang/String;JLjava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1loadbufferx
  (JNIEnv *env, jobject obj, jlong ptr, jstring buff, jlong sz, jstring name, jstring mode)
{
    const char *cbuff = (*env)->GetStringUTFChars(env, buff, NULL);
    const char *cname = (*env)->GetStringUTFChars(env, name, NULL);
    const char *cmode = (*env)->GetStringUTFChars(env, mode, NULL);
    int ret = luaL_loadbufferx((lua_State*)ptr, cbuff, sz, cname, cmode);
    (*env)->ReleaseStringUTFChars(env, buff, cbuff);
    (*env)->ReleaseStringUTFChars(env, name, cname);
    (*env)->ReleaseStringUTFChars(env, mode, cmode);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_loadfile
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1loadfile
  (JNIEnv *env, jobject obj, jlong ptr, jstring filename)
{
    const char *cfilename = (*env)->GetStringUTFChars(env, filename, NULL);
    int ret = luaL_loadfile((lua_State*)ptr, cfilename);
    (*env)->ReleaseStringUTFChars(env, filename, cfilename);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_loadfilex
 * Signature: (JLjava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1loadfilex
  (JNIEnv *env, jobject obj, jlong ptr, jstring filename, jstring mode)
{
    const char *cfilename = (*env)->GetStringUTFChars(env, filename, NULL);
    const char *cmode = (*env)->GetStringUTFChars(env, mode, NULL);
    int ret = luaL_loadfilex((lua_State*)ptr, cfilename, cmode);
    (*env)->ReleaseStringUTFChars(env, filename, cfilename);
    (*env)->ReleaseStringUTFChars(env, mode, cmode);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_loadstring
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1loadstring
  (JNIEnv *env, jobject obj, jlong ptr, jstring str)
{
    const char *cstr = (*env)->GetStringUTFChars(env, str, NULL);
    int ret = luaL_loadstring((lua_State*)ptr, cstr);
    (*env)->ReleaseStringUTFChars(env, str, cstr);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_newmetatable
 * Signature: (JLjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1newmetatable
  (JNIEnv *env, jobject obj, jlong ptr, jstring tname)
{
    const char *ctname = (*env)->GetStringUTFChars(env, tname, NULL);
    int ret = luaL_newmetatable((lua_State*)ptr, ctname);
    (*env)->ReleaseStringUTFChars(env, tname, ctname);
    return ret;
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_newstate
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1newstate
  (JNIEnv *env, jobject obj)
{
    return luaL_newstate();
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_openlibs
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1openlibs
  (JNIEnv *env, jobject obj, jlong ptr)
{
    luaL_openlibs((lua_State*)ptr);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_setmetatable
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1setmetatable
  (JNIEnv *env, jobject obj, jlong ptr, jstring tname)
{
    const char *ctname = (*env)->GetStringUTFChars(env, tname, NULL);
    luaL_setmetatable((lua_State*)ptr, ctname);
    (*env)->ReleaseStringUTFChars(env, tname, ctname);
}

/*
 * Class:     com_shaoqiu_luajava_LuaState
 * Method:    _luaL_typename
 * Signature: (JI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_shaoqiu_luajava_LuaState__1luaL_1typename
  (JNIEnv *env, jobject obj, jlong ptr, jint index)
{
    const char *ret = luaL_typename((lua_State*)ptr, index);
    return (*env)->NewStringUTF(env, ret);
}
