#include "main.h"
#include "common.h"
#include <string.h>
#include <mysql/mysql.h>

// 初始化lua函数，每次都写好麻烦的 >_<!!
void luaInit(lua_State *L, const char *fname){
  luaL_openlibs(L);
  luaL_dofile(L, fname);
}

// 初始化mysql
MYSQL *mysqlInit(){
  lua_State *L = lua_open();

  DataServer db;
  // char *ServerIp, *Username, *Password, *Database;
  luaInit(L, "database.lua");
  lua_getglobal(L, "ServerIp");
  lua_getglobal(L, "Username");
  lua_getglobal(L, "Password");
  lua_getglobal(L, "Database");
  // struct DataServer *db;
  db.ServerIp = (char *)lua_tostring(L, -4);
  db.Username = (char *)lua_tostring(L, -3);
  db.Password = (char *)lua_tostring(L, -2);
  db.Database = (char *)lua_tostring(L, -1);

  lua_close(L);

  MYSQL *conn_ptr;

  conn_ptr = mysql_init(NULL);

  if (!conn_ptr){
    fprintf(cgiOut, "conn_ptr Error!" );
    // return;
  }

  conn_ptr = mysql_real_connect(conn_ptr, "localhost", db.Username, db.Password, db.Database, 0, NULL, 0);
  // conn_ptr = mysql_real_connect(conn_ptr, ServerIp, Username, Password, Database, 0, NULL, 0);

  if (!conn_ptr)
    fprintf(cgiOut, "Failed:%s\n",mysql_error(conn_ptr) );

    return conn_ptr;
}

GameSystem getGameSystem(){
  GameSystem game;

}


// 获取游戏名
// char * getGameName(){
//
//   #define SELECT_QUERY_NAME "select `value` from `game_system` where `name` = 'title'"
//   MYSQL_ROW row;
//   MYSQL_RES *res;
//   MYSQL *conn_ptr;
//   char *title = (char *)malloc(20 * sizeof(char));
//
//   conn_ptr = mysqlInit();
//
//   if (mysql_query(conn_ptr, SELECT_QUERY_NAME)){
//     fprintf(cgiOut, "Query Error%s\n", conn_ptr);
//   }
//
//   res = mysql_use_result(conn_ptr);
//   while ((row = mysql_fetch_row(res)) != NULL){
//     strncpy(title, row[0], strlen(row[0]));
//   }
//   printf("%s\n",title );
//   mysql_close(conn_ptr);
//   return title;
// }
//
char * getGameName(MYSQL *conn_ptr){

  #define SELECT_QUERY_NAME "select `value` from `game_system` where `name` = 'money'"
  MYSQL_ROW row;
  MYSQL_RES *res;
  // MYSQL *conn_ptr;
  char *title = (char *)malloc(200 * sizeof(char));

  // conn_ptr = mysqlInit();

  if (mysql_query(conn_ptr, SELECT_QUERY_NAME)){
    fprintf(cgiOut, "Query Error%s\n", conn_ptr);
  }

  res = mysql_use_result(conn_ptr);
  while ((row = mysql_fetch_row(res)) != NULL){
    strncpy(title, row[0], strlen(row[0]-1));
    // printf("%s\n",row[0] );
    // printf("%s\n", );
  }
  // printf("%s\n",title );
  mysql_free_result(res);
  // mysql_close(conn_ptr);
  return title;
}



// 获取游戏公告
char *getGameNotice(MYSQL *conn_ptr){
  // MYSQL *conn_ptr;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char *notice = (char *)malloc(200 * sizeof(char));
  #define SELECT_QUERY_NOTICE "select `value` from `game_system` where `name` = 'money'"

  // conn_ptr = mysqlInit();
  // // // if (!conn)fprintf(cgiOut, "Query Error:<br />");
  if (mysql_query(conn_ptr, SELECT_QUERY_NOTICE)){
    fprintf(cgiOut, "Query Error:<br />" );
  }
  res = mysql_use_result(conn_ptr);
  while ((row = mysql_fetch_row(res)) != NULL){
    strncpy(notice, row[0], strlen(row[0]-1));
  }
  printf("%s\n", notice);
  mysql_free_result(res);

  return notice;
}


// 显示游戏入口
void showGameEnter(){
}

// 显示html头
void showHeader(MYSQL *conn_ptr){
  cgiHeaderContentType("text/html");
  fprintf(cgiOut, "<!DOCTYPE html>\n<html lang='en'>\n<head>\n");
  fprintf(cgiOut, "<meta charset='utf-8'>\n" );
  // fprintf(cgiOut, "<title>%s</title>\n",getGameName(conn_ptr) );
  fprintf(cgiOut, "</head>\n<body>\n" );
}

//结束html
void showFooter(){
  fprintf(cgiOut, "</body>\n</html>" );
}
