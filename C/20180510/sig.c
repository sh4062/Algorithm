#include <unistd.h>

#include <stdio.h>

#include <sys/wait.h>

#include <sys/types.h>

#include <signal.h>

void SignHandler(int iSignNo)

{

  printf("Capture sign no:%d\n",iSignNo);

} int

main()

{

  signal(SIGINT,SignHandler);

  while(1);

  return 0;

}
