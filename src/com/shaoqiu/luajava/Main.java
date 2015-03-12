package com.shaoqiu.luajava;

public class Main {

    public static void main(String[] args) {
        System.out.println("LuaState test");
        LuaState lua = new LuaState();
        lua.luaL_dofile("hello.lua");
        lua.lua_getglobal("shaoqiu");
        String shaoqiu = lua.lua_tostring(-1);
        System.out.println(shaoqiu);
    }
}
