#ifndef MAIN_H
#define MAIN_H

#include <cgic.h>
#include <stdlib.h>
#include "./lua/install/include/lua.h"
#include "./lua/install/include/lauxlib.h"
#include "./lua/install/include/lualib.h"
#include "./lua/install/include/luaconf.h"

#define lua_open() luaL_newstate()
#define false 0
#define true 1

#endif
