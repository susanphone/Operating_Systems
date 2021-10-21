
#include <stdio.h>
#include <sys/types.h>

int N=10;

int produce1(){
  while (1) {
	if (N>20) {
		  printf("Overflow!\n");
		  return 0;
		  };
    	N=N+2;
	printf("Produce1: Current N=%d.\n", N);
        }
}

int produce2(){
  while (1) {
	if (N>20) {
		  printf("Overflow!\n");
		  return 0;
		  };
    	N=N+5;
	printf("Produce2: Current N=%d.\n", N);
        }
}

int consumer() {
  while (1) {
	if (N<=0) {
		  printf("Underflow!\n");
		  return 0;
		  };
    	N=N-1;
	printf("Consumer: Current N=%d.\n", N);
        }
}

main() {
int pid, pid1;
	pid = fork();
	if (pid < 0 )
		printf("Fork failure.\n");
	else if (pid > 0)
	{
		printf("Parent PID=%d.\n",pid);
		consumer();
	} else
	{
   		pid1 = fork();
	        if (pid1 < 0 )
		       { printf("Fork failure.\n");}
		  else if (pid1 > 0)
			{
		          printf("Child PID=%d.\n",pid1);
			  produce1();
			} else {
			  printf("Child's child PID=%d.\n",pid1);
			  produce2();
			}
	}
}