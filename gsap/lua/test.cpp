extern "C" {
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h> 
}
#include <cstdio>

int PrintStringList(lua_State * L) {
    int iStringCount = lua_gettop(L);
    for (int i = 1; i <= iStringCount; i++) {
        if (!lua_isstring(L, i)) {
            luaL_error(L, "Invalid string!");
        } else {
            printf("\t%s\n", lua_tostring(L, i));
        }
    }
    return 0;
}

int luaM(lua_State* L, int n, int m) {
    lua_getglobal(L, "mul");   // top = 1
    lua_getglobal(L, "mul");   // top = 2
    lua_pushnumber(L, n);      // top = 3
    lua_call(L, 1, 1);         // top = 2
    int ansn = (int)lua_tonumber(L, lua_gettop(L));
    lua_pop(L, 1);             // top = 1
    lua_pushnumber(L, m);
    lua_call(L, 1, 1);
    int ansm = (int)lua_tonumber(L, lua_gettop(L));
    lua_pop(L, 1);
    return ansn / ansm;
}

int main() {
    lua_State * L = luaL_newstate();
    luaL_openlibs(L);
    lua_register(L, "PrintStringList", PrintStringList);
    int iErrorCode = luaL_dofile(L, "test.lus"); // can also be luac.out if compiled
    if (iErrorCode) {
        printf("Error when loading mul.lua\n");
    }
    printf("the result is %d\n", luaM(L, 6, 2));
    lua_getglobal(L, "Messages");
    lua_call(L, 0, 0);
    lua_close(L);
    return 0;
}