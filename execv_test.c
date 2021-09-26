#include <unistd.h>
#include <stdio.h>

int main(void) {
  char *binaryPath = "/bin/ls";
  char *args[] = {binaryPath, "-lh", NULL};
 
  printf("I am the parent.Process ID:%d\n",getpid());
  pid_t hijo1 = fork();
  if (hijo1 == 0)
  {
    /* code */
    printf("I am the first child.Process ID:%d\n",getpid());
    execv(binaryPath, args);
    pid_t hijo2 = fork();
    if (hijo2 == 0)
    {
      /* code */
      printf("I am the second child.Process ID:%d\n",getpid());
    }
    
  }
  printf("Ending the Main function\n");
  return 0;
}

