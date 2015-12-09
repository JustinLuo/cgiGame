#include "main.h"
#include "common.h"
#include <mysql/mysql.h>


int cgiMain(){
  #ifdef DEBUG
  #endif

  // printf("%s<br />",getGameName() );

  // printf("%s\n",getGameNotice() );

  MYSQL *conn_ptr;
  conn_ptr =  mysqlInit();

  showHeader(conn_ptr);

  // printf("%s\n", getGameConfig(conn_ptr, "money"));
  // getGameConfig(conn_ptr, "money");
  fprintf(cgiOut, "<h2>%s</h2><hr />", getGameConfig(conn_ptr, "title"));

  printf("%s\n",getGameConfig(conn_ptr, "notice") );
  // getGameName();
  // getGameNotice();
  mysql_close(conn_ptr);


  showFooter();

  return 0;
}
