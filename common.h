#ifndef COMMON_H
#define COMMON_H

// 错误处理
// void error(lua_State* L, const char* fmt, ...);

typedef struct DataServer{
   char *ServerIp;
   char *Username;
   char *Password;
   char *Database;
}DataServer;

//  游戏基本信息
typedef struct GameSystem{
  char *money;
  char *notice;
}GameSystem;

#define PRINT(i)        do{                \
    printf("%8s(): ", __FUNCTION__);       \
    printf("&%-5s =0x%-6x, ", #i, &(i));   \
    printf(" %-5s =0x%-6x"  , #i,  (i));   \
}while(0)

#define PRINT_INT(i)    do{                \
    PRINT(i);                              \
    printf("\n");                          \
}while(0)

#define PRINT_PTR(p)    do{                \
    PRINT(p);                              \
    printf(", *%-5s =0x%-6x\n", #p, *(p)); \
}while(0)


// 加载配置文件
// void loadConf(const char fname, int *width, int *height);
// char *getGameName();
// void getGameName(MYSQL *conn_ptr);
// char *getGameNotice();

void luaInit(lua_State *L, const char *fname);
// MYSQL *mysqlInit(const char *fname);

// void luaInit(lua_State, const char *fname);
// MYSQL *mysqlInit();/

void showGameEnter();
void showHeader();
void showFooter();

#endif
