#include "main.h"
#include "common.h"
#include <mysql/mysql.h>

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

// 初始化lua函数，每次都写好麻烦的 >_<!!
void luaInit(lua_State *L, const char *fname){
  luaL_openlibs(L);
  luaL_dofile(L, fname);
}

// 初始化mysql
MYSQL *mysqlInit(){
  lua_State *L = lua_open();
  const char *username, *password, *database;
  luaInit(L, "database.lua");
  // lua_getglobal(L, "host");
  lua_getglobal(L, "username");
  lua_getglobal(L, "password");
  lua_getglobal(L, "database");
  // host = lua_tostring(L, -4);
  username = lua_tostring(L, -3);
  password = lua_tostring(L, -2);
  database = lua_tostring(L, -1);

  lua_close(L);

  // #define HOST host

  MYSQL *conn_ptr;
  conn_ptr = mysql_init(NULL);
  if (!conn_ptr){
    fprintf(cgiOut, "conn_ptr Error!" );
    // return;
  }
  // fprintf(cgiOut, "Helln" );
  conn_ptr = mysql_real_connect(conn_ptr, "localhost", username, password, database, 0, NULL, 0);
  if (conn_ptr)
    fprintf(cgiOut, "OK" );
  else
    fprintf(cgiOut, "Failed:%s\n",mysql_error(conn_ptr) );

    return conn_ptr;
}

// 获取游戏名
char *getGameName(){
  char *name = NULL;
  lua_State *L = lua_open();
  luaInit(L, "conf.lua");
  lua_getglobal(L, "name");
  name = (char *)lua_tostring(L, -1);
  lua_close(L);
  return name;
}

// 获取游戏公告
char *getGameNotice(){
  lua_State *L = lua_open();
  char *notice = NULL;
  luaInit(L, "conf.lua");
  lua_getglobal(L, "notice");
  notice = (char *)lua_tostring(L, -1);
  lua_close(L);

  return notice;
}

// 显示游戏入口
void showGameEnter(){
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
