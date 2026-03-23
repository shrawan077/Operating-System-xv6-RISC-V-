#include "kernel/types.h"
#include "user/user.h"

int 
main(void){
    printf("My PID      %d\n", getpid());
    printf("Parent PID  %d\n", getppid());
    exit(0);
}