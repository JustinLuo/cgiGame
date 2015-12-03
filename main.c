#include "main.h"
#include "common.h"
#include <mysql.h>


int cgiMain(){
  #ifdef DEBUG
  #endif

  showHeader();

  printf("%s\n",getGameName() );



  showFooter();

  return 0;
}
