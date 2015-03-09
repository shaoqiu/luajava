package com.shaoqiu.luajava;

public class LuaState {
    private final static String LUAJAVA_LIB = "luajava";
    static
    {
        System.loadLibrary(LUAJAVA_LIB);
    }
    private long mLuaStatePtr;

    private native int _lua_absindex(long L, int idx);
    private native void _lua_arith(long L, int op);
    private native void _lua_call(long L, int nargs, int nresults);
    private native int _lua_checkstack(long L, int n);
    private native void _lua_close(long L);
    private native int _lua_compare(long L, int index1, int index2, int op);
    private native void _lua_concat(long L, int n);
    private native void _lua_copy(long L, int fromidx, int toidx);
    private native void _lua_createtable(long L, int narr, int nrec);
    private native int _lua_error(long L);
    private native int _lua_gc(long L, int what, int data);
    private native int _lua_getfield(long L, int index, String key);
    private native int _lua_getglobal(long L, String name);
    private native int _lua_getmetatable(long L, int index);
    private native int _lua_gettable(long L, int index);
    private native int _lua_gettop(long L);
    private native String _lua_getupvalue(long L, int funcindex, int n);
    private native int _lua_getuservalue(long L, int index);
    private native void _lua_insert(long L, int index);
    private native int _lua_isboolean(long L, int index);
    private native int _lua_iscfunction(long L, int index);
    private native int _lua_isfunction(long L, int index);
    private native int _lua_isinteger(long L, int index);
    private native int _lua_islightuserdata(long L, int index);
    private native int _lua_isnil(long L, int index);
    private native int _lua_isnone(long L, int index);
    private native int _lua_isnoneornil(long L, int index);
    private native int _lua_isnumber(long L, int index);
    private native int _lua_isstring(long L, int index);
    private native int _lua_istable(long L, int index);
    private native int _lua_isthread(long L, int index);
    private native int _lua_isuserdata(long L, int index);
    private native int _lua_isyieldable(long L);
    private native void _lua_len(long L, int index);
    private native void _lua_newtable(long L);
    private native int _lua_next(long L, int index);
    private native int _lua_pcall(long L, int nargs, int nresults, int msgh);
    private native void _lua_pop(long L, int n);
    private native void _lua_pushboolean(long L, int b);
    private native String _lua_pushstring(long L, String str);
    private native void _lua_pushglobaltable(long L);
    private native void _lua_pushinteger(long L, long n);
    private native String _lua_pushliteral(long L, String str);
    private native String _lua_pushlstring(long L, String str, long len);
    private native void _lua_pushnil(long L);
    private native void _lua_pushfloat(long L, float f);
    private native int _lua_pushthread(long L);
    private native void _lua_pushvalue(long L, int index);
    private native int _lua_rawequal(long L, int index1, int index2);
    private native int _lua_rawget(long L, int index);
    private native long _lua_rawlen(long L, int index);
    private native void _lua_rawset(long L, int index);
    private native void _lua_remove(long L, int index);
    private native void _lua_replace(long L, int index);
    private native int _lua_resume(long L, long from, int nargs);
    private native void _lua_rotate(long L, int idx, int n);
    private native void _lua_setfield(long L, int index, String key);
    private native void _lua_setglobal(long L, String name);
    private native void _lua_setmetatable(long L, int index);
    private native void _lua_settable(long L, int index);
    private native void _lua_settop(long L, int index);
    private native void _lua_setuservalue(long L, int index);
    private native int _lua_staus(long L);
    private native long _lua_stringtonumber(long L, String str);
    private native int _lua_toboolean(long L, int index);
    private native long _lua_tointeger(long L, int index);
    private native double _lua_todouble(long L, int index);
    private native long _lua_topointer(long L, int index);
    private native String _lua_tostring(long L, int index);
    private native int _lua_type(long L, int index);
    private native String _lua_typename(long L, int tp);
    private native void _lua_xmove(long L, long to, int n);
    private native int _lua_yield(long L, int nresults);

    private native void _luaL_argcheck(long L, int cond, int arg, String extramsg);
    private native int _luaL_argerror(long L, int arg, String extramsg);
    private native int _luaL_callmeta(long L, int obj, String e);
    private native void _luaL_checkany(long L, int arg);
    private native long _luaL_checkinteger(long L, int arg);
    private native double _luaL_checknumber(long L, int arg);
    private native void _luaL_checkstack(long L, int sz, String msg);
    private native String _luaL_checkstring(long L, int arg);
    private native void _luaL_checktype(long L, int arg, int t);
    private native void _luaL_checkversion(long L);
    private native int _luaL_dofile(long L, String filename);
    private native int _luaL_dostring(long L, String str);
    private native int _luaL_error(long L, String msg);
    private native int _luaL_execresult(long L, int stat);
    private native int _luaL_fileresult(long L, int stat, String fname);
    private native int _luaL_getmetafield(long L, int obj, String e);
    private native int _luaL_getmetatable(long L, String tname);
    private native int _luaL_getsubtable(long L, int idx, String fname);
    private native String _luaL_gsub(long L, String s, String p, String r);
    private native long _luaL_len(long L, int index);
    private native int _luaL_loadbuffer(long L, String buff, long sz, String name);
    private native int _luaL_loadbufferx(long L, String buff, long sz, String name, String mode);
    private native int _luaL_loadfile(long L, String filename);
    private native int _luaL_loadfilex(long L, String filename, String mode);
    private native int _luaL_loadstring(long L, String s);
    private native int _luaL_newmetatable(long L, String tname);
    private native long _luaL_newstate();
    private native void _luaL_openlibs(long L);
    private native void _luaL_setmetatable(long L, String tname);
    private native String _luaL_typename(long L, int index);



    public int lua_absindex(int idx) {
        return _lua_absindex(mLuaStatePtr, idx);
    }
    public void lua_arith(int op) {
        _lua_arith(mLuaStatePtr, op);
    }
    public void lua_call(int nargs, int nresults) {
        _lua_call(mLuaStatePtr, nargs, nresults);
    }
    public int lua_checkstack(int n) {
        return _lua_checkstack(mLuaStatePtr, n);
    }
    public void lua_close() {
        _lua_close(mLuaStatePtr);
    }
    public int lua_compare(int index1, int index2, int op) {
        return _lua_compare(mLuaStatePtr, index1, index2, op);
    }
    public void lua_concat(int n) {
        _lua_concat(mLuaStatePtr, n);
    }
    public void lua_copy(int fromidx, int toidx) {
        _lua_copy(mLuaStatePtr, fromidx, toidx);
    }
    public void lua_createtable(int narr, int nrec) {
        _lua_createtable(mLuaStatePtr, narr, nrec);
    }
    public int lua_error() {
        return _lua_error(mLuaStatePtr);
    }
    public int lua_gc(int what, int data) {
        return _lua_gc(mLuaStatePtr, what, data);
    }
    public int lua_getfield(int index, String key) {
       return _lua_getfield(mLuaStatePtr, index, key); 
    }
    public int lua_getglobal(String name) {
        return _lua_getglobal(mLuaStatePtr, name);
    }
    public int lua_getmetatable(int index) {
       return _lua_getmetatable(mLuaStatePtr, index); 
    }
    public int lua_gettable(int index) {
        return _lua_gettable(mLuaStatePtr, index);
    }
    public int lua_gettop(long L) {
        return _lua_gettop(mLuaStatePtr);
    }
    public String lua_getupvalue(int funcindex, int n) {
        return _lua_getupvalue(mLuaStatePtr, funcindex, n);
    }
    public int lua_getuservalue(int index) {
        return _lua_getuservalue(mLuaStatePtr, index);

    }
    public void lua_insert(int index) {
       _lua_insert(mLuaStatePtr, index); 
    }
    public int lua_isboolean(int index) {
        return _lua_isboolean(mLuaStatePtr, index);
    }
    public int lua_iscfunction(int index) {
       return _lua_iscfunction(mLuaStatePtr, index); 
    }
    public int lua_isfunction(int index) {
        return _lua_isfunction(mLuaStatePtr, index);
    }
    public int lua_isinteger(int index) {
        return _lua_isinteger(mLuaStatePtr, index); 
    }
    public int lua_islightuserdata(int index) {
        return _lua_islightuserdata(mLuaStatePtr, index);
    }
    public int lua_isnil(int index) {
       return _lua_isnil(mLuaStatePtr, index); 
    }
    public int lua_isnone(int index) {
        return _lua_isnone(mLuaStatePtr, index);
    }
    public int lua_isnoneornil(int index) {
       return _lua_isnoneornil(mLuaStatePtr, index); 
    }
    public int lua_isnumber(int index) {
        return _lua_isnumber(mLuaStatePtr, index);
    }
    public int lua_isstring(int index) {
       return _lua_isstring(mLuaStatePtr, index); 
    }
    public int lua_istable(int index) {
        return _lua_istable(mLuaStatePtr, index);
    }
    public int lua_isthread(int index) {
       return _lua_isthread(mLuaStatePtr, index); 
    }
    public int lua_isuserdata(int index) {
        return _lua_isuserdata(mLuaStatePtr, index);
    }
    public int lua_isyieldable() {
        return _lua_isyieldable(mLuaStatePtr);
    }
    public void lua_len(int index) {
        _lua_len(mLuaStatePtr, index);
    }
    public void lua_newtable() {
        _lua_newtable(mLuaStatePtr);
    } 
    public int lua_next(int index) {
        return _lua_next(mLuaStatePtr, index);
    }
    public int lua_pcall(int nargs, int nresults, int msgh) {
       return _lua_pcall(mLuaStatePtr, nargs, nresults, msgh); 
    }
    public void lua_pop(int n) {
        _lua_pop(mLuaStatePtr, n);
    }
    public void lua_pushboolean(int b) {
       _lua_pushboolean(mLuaStatePtr, b); 
    }
    public String lua_pushstring(String str) {
        return _lua_pushstring(mLuaStatePtr, str);
    }
    public void lua_pushglobaltable() {
        _lua_pushglobaltable(mLuaStatePtr);
    }
    public void lua_pushinteger(long n) {
        _lua_pushinteger(mLuaStatePtr, n);
    }
    public String lua_pushliteral(String str) {
        return _lua_pushliteral(mLuaStatePtr, str);
    }
    public String lua_pushlstring(String str, long len) {
        return _lua_pushlstring(mLuaStatePtr, str, len);
    }
    public void lua_pushnil() {
        _lua_pushnil(mLuaStatePtr);
    }
    public void lua_pushfloat(float f) {
        _lua_pushfloat(mLuaStatePtr, f);
    }
    public int lua_pushthread() {
        return _lua_pushthread(mLuaStatePtr);
    }
    public void lua_pushvalue(int index) {
        _lua_pushvalue(mLuaStatePtr, index);
    }
    public int lua_rawequal(int index1, int index2) {
        return _lua_rawequal(mLuaStatePtr, index1, index2);
    }
    public int lua_rawget(int index) {
        return _lua_rawget(mLuaStatePtr, index);
    }
    public long lua_rawlen(int index) {
        return _lua_rawlen(mLuaStatePtr, index);
    }
    public void lua_rawset(int index) {
        _lua_rawset(mLuaStatePtr, index);
    }
    public void lua_remove(int index) {
        _lua_remove(mLuaStatePtr, index);
    }
    public void lua_replace(int index) {
       _lua_replace(mLuaStatePtr, index); 
    }
    public int lua_resume(long from, int nargs) {
        return _lua_resume(mLuaStatePtr, from, nargs);
    }
    public void lua_rotate(int idx, int n) {
       _lua_rotate(mLuaStatePtr, idx, n); 
    }
    public void lua_setfield(int index, String key) {
        _lua_setfield(mLuaStatePtr, index, key);
    }
    public void lua_setglobal(String name) {
        _lua_setglobal(mLuaStatePtr, name);
    }
    public void lua_setmetatable(int index) {
        _lua_setmetatable(mLuaStatePtr, index);
    }
    public void lua_settable(int index) {
        _lua_settable(mLuaStatePtr, index);
    }
    public void lua_settop(int index) {
        _lua_settop(mLuaStatePtr, index);
    }
    public void lua_setuservalue(int index) {
       _lua_setuservalue(mLuaStatePtr, index);
    }
    public int lua_staus() {
        return _lua_staus(mLuaStatePtr);
    }
    public long lua_stringtonumber(String str) {
        return _lua_stringtonumber(mLuaStatePtr, str);
    }
    public int lua_toboolean(int index) {
        return _lua_toboolean(mLuaStatePtr, index);
    }
    public long lua_tointeger(int index) {
        return _lua_tointeger(mLuaStatePtr, index);
    }
    public double lua_todouble(int index) {
        return _lua_todouble(mLuaStatePtr, index);
    }
    public long lua_topointer(int index) {
        return _lua_topointer(mLuaStatePtr, index);
    }
    public String lua_tostring(int index) {
        return _lua_tostring(mLuaStatePtr, index);
    }
    public int lua_type(int index) {
        return _lua_type(mLuaStatePtr, index);
    }
    public String lua_typename(int tp) {
       return _lua_typename(mLuaStatePtr, tp); 
    }
    public void lua_xmove(long to, int n) {
        _lua_xmove(mLuaStatePtr, to, n);
    }
    public int lua_yield(int nresults) {
       return _lua_yield(mLuaStatePtr, nresults); 
    }

    public void luaL_argcheck(int cond, int arg, String extramsg) {
        _luaL_argcheck(mLuaStatePtr, cond, arg, extramsg);
    }
    public int luaL_argerror(int arg, String extramsg) {
       return _luaL_argerror(mLuaStatePtr, arg, extramsg); 
    }
    public int luaL_callmeta(int obj, String e) {
        return _luaL_callmeta(mLuaStatePtr, obj, e);
    }
    public void luaL_checkany(int arg) {
       _luaL_checkany(mLuaStatePtr, arg); 
    }
    public long luaL_checkinteger(int arg) {
        return _luaL_checkinteger(mLuaStatePtr, arg);
    }
    public double luaL_checknumber(int arg) {
       return _luaL_checknumber(mLuaStatePtr, arg); 
    }
    public void luaL_checkstack(int sz, String msg) {
        _luaL_checkstack(mLuaStatePtr, sz, msg);
    }
    public String luaL_checkstring(int arg) {
       return _luaL_checkstring(mLuaStatePtr, arg); 
    }
    public void luaL_checktype(int arg, int t) {
        _luaL_checktype(mLuaStatePtr, arg, t);
    }
    public void luaL_checkversion() {
        _luaL_checkversion(mLuaStatePtr);
    }
    public int luaL_dofile(String filename) {
       return _luaL_dofile(mLuaStatePtr, filename); 
    }
    public int luaL_dostring(String str) {
        return _luaL_dostring(mLuaStatePtr, str);
    }
    public int luaL_error(String msg) {
       return _luaL_error(mLuaStatePtr, msg);
    }
    public int luaL_execresult(int stat) {
        return _luaL_execresult(mLuaStatePtr, stat);
    }
    public int luaL_fileresult(int stat, String fname) {
       return _luaL_fileresult(mLuaStatePtr, stat, fname); 
    }
    public int luaL_getmetafield(int obj, String e) {
        return _luaL_getmetafield(mLuaStatePtr, obj, e);
    }
    public int luaL_getmetatable(String tname) {
       return _luaL_getmetatable(mLuaStatePtr, tname); 
    }
    public int luaL_getsubtable(int idx, String fname) {
        return _luaL_getsubtable(mLuaStatePtr, idx, fname);
    }
    public String luaL_gsub(String s, String p, String r) {
        return _luaL_gsub(mLuaStatePtr, s, p, r);
    }
    public long luaL_len(int index) {
        return _luaL_len(mLuaStatePtr, index);
    }
    public int luaL_loadbuffer(String buff, long sz, String name) {
        return _luaL_loadbuffer(mLuaStatePtr, buff, sz, name);
    }
    public int luaL_loadbufferx(String buff, long sz, String name, String mode) {
        return _luaL_loadbufferx(mLuaStatePtr, buff, sz, name, mode);
    }
    public int luaL_loadfile(String filename) {
        return _luaL_loadfile(mLuaStatePtr, filename);
    }
    public int luaL_loadfilex(String filename, String mode) {
        return _luaL_loadfilex(mLuaStatePtr, filename, mode);
    }
    public int luaL_loadstring(String s) {
       return _luaL_loadstring(mLuaStatePtr, s); 
    }
    public int luaL_newmetatable(String tname) {
        return _luaL_newmetatable(mLuaStatePtr, tname);
    }
    public long luaL_newstate() {
        return _luaL_newstate();
    }
    public void luaL_openlibs() {
        _luaL_openlibs(mLuaStatePtr);
    }
    public void luaL_setmetatable(String tname) {
       _luaL_setmetatable(mLuaStatePtr, tname);
    }
    public String luaL_typename(int index) {
        return _luaL_typename(mLuaStatePtr, index);
    }


    public LuaState() {
        createLuaState();
    }
    private void createLuaState() {
        mLuaStatePtr = _luaL_newstate();
        _luaL_openlibs(mLuaStatePtr);
    }
}
