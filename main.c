#include "main.h"
#include "common.h"


int cgiMain(){
  #ifdef DEBUG
  #endif

  showHeader();

  printf("%s\n",getGameName() );
  // fprintf(stdout, "%s", name);

  showFooter();

  return 0;
}
