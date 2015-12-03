#include "main.h"
#include "common.h"

//
// void error(lua_State* L, const char* fmt, ...)
// {
//     va_list argp;
//     va_start(argp, fmt);
//     vfprintf(cgiOut, fmt, argp);
//     va_end(argp);
//     lua_close(L);
//     exit(EXIT_FAILURE);
// }

char *getGameName(){
  char *name = NULL;
  lua_State *L = lua_open();
  luaL_openlibs(L);
  luaL_dofile(L, "conf.lua");
  lua_getglobal(L, "name");
  name = (char *)lua_tostring(L, -1);
  lua_close(L);
  return name;
}

// 显示游戏公告

void showGameNotice(){

}

// 显示游戏入口
void showGameEnter(){
  fprintf(cgiOut, "%s\n", );
}

// 显示html头
void showHeader(){
  cgiHeaderContentType("text/html");
  fprintf(cgiOut, "<!DOCTYPE html>\n<html lang='en'>\n<head>\n");
  fprintf(cgiOut, "<meta charset='utf-8'>\n" );
  fprintf(cgiOut, "<title>%s</title>\n",getGameName() );
  fprintf(cgiOut, "</head>\n<body>\n" );
}

//结束html
void showFooter(){
  fprintf(cgiOut, "</body>\n</html>" );
}
