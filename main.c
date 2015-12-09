#include "main.h"
#include "common.h"
#include <mysql/mysql.h>


int cgiMain(){
  #ifdef DEBUG
  #endif

  showHeader();

  // printf("%s<br />",getGameName() );

  // printf("%s\n",getGameNotice() );

  MYSQL *conn_ptr;
  conn_ptr =  mysqlInit();
  //
  // // fprintf(cgiOut, "%s\n", getGameName(conn_ptr));
  // sprintf(qbuf, "select `value` from `game_system` where `name` = 'title'");
  // fprintf(cgiOut, "%s<br />", qbuf);
  //
  // if (mysql_query(conn_ptr, qbuf)){
  //   fprintf(cgiOut, "%s\n", mysql_error(conn_ptr));
  // }
  //
  // res = mysql_use_result(conn_ptr);
  //
  // fprintf(cgiOut, "Mysql Tables in mysql databases:<br />" );
  // while ((row = mysql_fetch_row(res)) != NULL)
  //   printf("%s<br />", row[0]);
  //
  // mysql_free_result(res);
  //
  //
  // mysql_close(conn_ptr);
  // printf("%s",getGameName(conn_ptr));

  printf("%s\n",getGameNotice(conn_ptr) );
  // getGameName();
  // getGameNotice();
  mysql_close(conn_ptr);


  showFooter();

  return 0;
}
