package com.shaoqiu.luajava;

public class LuaState {
    private final static String LUAJAVA_LIB = "luajava";

    private long mLuaStatePtr;

    public native long _luaL_newstate();
    public native void _luaL_openlibs(long luaState);
    public native int _luaL_dofile(long luaState, String file);

    static
    {
        System.loadLibrary(LUAJAVA_LIB);
    }

    public LuaState() {
        createLuaState();
    }

    public int doFile(String file) {
        return _luaL_dofile(mLuaStatePtr, file);
        
    }

    private void createLuaState() {
        mLuaStatePtr = _luaL_newstate();
        _luaL_openlibs(mLuaStatePtr);
    }
}
