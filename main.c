#include "main.h"
#include "common.h"
#include <mysql/mysql.h>


int cgiMain(){
  #ifdef DEBUG
  #endif

  showHeader();

  printf("%s<br />",getGameName() );
  printf("%s\n",getGameNotice() );

  // MYSQL *conn_ptr;
  // conn_ptr = mysql_init(NULL);
  //
  // if (!conn_ptr){
  //   fprintf(cgiOut, "ERROR");
  // }
  // conn_ptr = mysql_real_connect(conn_ptr, "localhost", "root", "123456", "game", 0, NULL, 0);
  // if (conn_ptr)
  //   fprintf(cgiOut, "Conn OK!" );
  // else
  //   fprintf(cgiOut, "Conn error!" );
  MYSQL *Conn = mysqlInit();
  mysql_close(Conn);



  showFooter();

  return 0;
}
