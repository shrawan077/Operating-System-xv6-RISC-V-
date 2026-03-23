#include "kernel/types.h"
#include "user/user.h"

int
main(void){
    printf("Current limit : %d\n", getlimit());

  // set a very small limit — only 8KB
  setlimit(8 * 1024);
  printf("Limit set to  : %d bytes\n", getlimit());

  // try to allocate 1MB — this should FAIL because of our limit
  char *mem = sbrk(1024 * 1024);

  if(mem == (char*)-1)
    printf("sbrk FAILED — limit enforced correctly!\n");
  else
    printf("sbrk succeeded — limit NOT enforced\n");

  // now remove the limit
  setlimit(0);
  printf("Limit removed.\n");

  // try again — this should SUCCEED now
  mem = sbrk(1024 * 1024);
  if(mem == (char*)-1)
    printf("sbrk FAILED — something is wrong\n");
  else
    printf("sbrk succeeded — no limit, works fine!\n");

  exit(0);
}