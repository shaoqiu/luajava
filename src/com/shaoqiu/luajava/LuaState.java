package com.shaoqiu.luajava;

public class LuaState {
    private final static String LUAJAVA_LIB = "luajava";
    private long mLuaStatePtr;
    private native long _luaL_newstate();
    private native void _luaL_openlibs(long luaState);
    private native int _luaL_dofile(long luaState, String file);
    private native int _get_global_integer(long luaState, String config);
    private native String _get_global_string(long luaState, String config);
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
    public int getGlobalInteger(String config) {
        return _get_global_integer(mLuaStatePtr, config);
    }
    public String getGlobalString(String config) {
        return _get_global_string(mLuaStatePtr, config);
    }
    public static void main(String[] args) {
        System.out.println("luajava test");
        LuaState lua = new LuaState();
        lua.doFile("hello.lua");
        int width = lua.getGlobalInteger("width");
        System.out.println("width = " + width);
        String shaoqiu = lua.getGlobalString("shaoqiu");
        System.out.println("shaoqiu = " + shaoqiu);
    }
}
