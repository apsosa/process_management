#include <unistd.h>
 
int main(void)
{
  char *binaryPath = "/bin/ls";
  char *arg1 = "-lh";
  
 
  execl(binaryPath, binaryPath, arg1, NULL);
 
  return 0;
 }
